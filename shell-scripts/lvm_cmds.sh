#!/bin/sh

NODE=`hostname`
NODE_LEN=`expr length $NODE`
BOUND="a b c d"
BOUND_CNT=-2

create(){
  for i in $BOUND; do
    pvcreate /dev/sd$i
    let BOUND_CNT+=2
  done
  echo "sd[${BOUND:0:1}-${BOUND:$BOUND_CNT:1}]"
  vgcreate disk-pool /dev/sd[${BOUND:0:1}-${BOUND:$BOUND_CNT:1}]
  LV_NAME=ssd${NODE:`expr $NODE_LEN - 1`:1}
  lvcreate -L 3.6T -i 4 -I 256k -n $LV_NAME disk-pool
}

remove(){
  LV_NAME=ssd${NODE:`expr $NODE_LEN - 1`:1}
  echo y|lvremove /dev/disk-pool/$LV_NAME
  for i in $BOUND; do echo y| pvremove /dev/sd$i --force --force ; done
}

#echo ${NODE:`expr $NODE_LEN - 1`:1}
#LV_NAME=ssd${NODE:`expr $NODE_LEN - 1`:1}
#echo $LV_NAME
#
#  for i in $BOUND; do
#    let BOUND_CNT+=2
#  done
#
#echo ${BOUND:$BOUND_CNT:1}
#
#exit

if [ $# -gt 0 ]; then
  case $1 in
  "re-create") remove; create;;
  "create") create;;
  "remove") remove;;
  *)
    echo "please input one of {create, remove, re-create}";;
  esac
fi


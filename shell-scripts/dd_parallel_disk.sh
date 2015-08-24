#!/bin/sh

BOUND="a b c d"

r_test(){
  echo "dd parallel read test"
  for i in $BOUND; do
    dd if=/dev/sd$i of=/dev/null bs=1024k count=10240 iflag=direct &
  done

  for i in $BOUND; do
    while [ `lsof /dev/sd$i | wc -l` -gt 0 ];do sleep 1; done;
  done
}

w_test(){
  echo "dd parallel write test"
  for i in $BOUND; do
    dd if=/dev/zero of=/dev/sd$i bs=1024k count=10240 oflag=direct &
  done

  for i in $BOUND; do
    while [ `lsof /dev/sd$i | wc -l` -gt 0 ];do sleep 1;  done;
  done
}

rw_test(){
  echo "dd parallel read test"
  for i in $BOUND; do
    dd if=/dev/sd$i of=/dev/null bs=1024k count=10240 iflag=direct &
  done

  for i in $BOUND; do
    while [ `lsof /dev/sd$i | wc -l` -gt 0 ];do sleep 1; done;
  done;

  echo "dd parallel write test"
  for i in $BOUND; do
    dd if=/dev/zero of=/dev/sd$i bs=1024k count=10240 oflag=direct &
  done

  for i in $BOUND; do
    while [ `lsof /dev/sd$i | wc -l` -gt 0 ];do sleep 1; done;
  done;
}

if [ $# -eq 0 ]; then
  r_test
else
  case $1 in
  "rw") rw_test;;
  "wr") rw_test;;
  "r") r_test;;
  "w") w_test;;
  *)
    echo "please input one of {r, w, wr, rw}";;
  esac
fi

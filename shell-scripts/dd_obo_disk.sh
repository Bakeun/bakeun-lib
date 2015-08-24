#!/bin/sh

BOUND="a b c d"

r_test(){
  for i in $BOUND; do
    echo "sd$i dd read test";
    dd if=/dev/sd$i of=/dev/null bs=1024k count=10240 iflag=direct;
  done;
}

w_test(){
  for i in $BOUND; do
    echo "sd$i dd write test";
    dd if=/dev/zero of=/dev/sd$i bs=1024k count=10240 oflag=direct;
  done;
}

rw_test(){
  for i in $BOUND; do
    echo "sd$i dd read test";
    dd if=/dev/sd$i of=/dev/null bs=1024k count=10240 iflag=direct;
    echo "sd$i dd write test";
    dd if=/dev/zero of=/dev/sd$i bs=1024k count=10240 oflag=direct;
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

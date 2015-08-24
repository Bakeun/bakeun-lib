#!/bin/sh

BOUND="a b c d"
TGT_PATH=${2:?"requires an target_path"}
TEST_FILE="fs_test"

r_test(){
  echo "$TGT_PATH dd read test";
  if [ `find $TGT_PATH -type f -name $TEST_FILE` ]; then
    dd if=$TGT_PATH/$TEST_FILE of=/dev/null bs=1024k count=10240 iflag=direct
  else
    echo "there are no file for test"
    echo "before this cmd, try dd_obo_fs.sh w {TGT_PATH}"
  fi
}

w_test(){
  if [ `find $TGT_PATH -type f -name $TEST_FILE` ]; then
    sudo rm $TGT_PATH/$TEST_FILE
  fi
  echo "$TGT_PATH dd write test";
  dd if=/dev/zero of=$TGT_PATH/$TEST_FILE bs=1024k count=10240 oflag=direct
}

rw_test(){
  if [ `find $TGT_PATH -type f -name $TEST_FILE` ]; then
    sudo rm $TGT_PATH/$TEST_FILE
  fi
  echo "$TGT_PATH dd write test"
  dd if=/dev/zero of=$TGT_PATH/$TEST_FILE bs=1024k count=10240 oflag=direct
  echo "$TGT_PATH dd read test"
  dd if=$TGT_PATH/$TEST_FILE of=/dev/null bs=1024k count=10240 iflag=direct
}

if [ $# -eq 0 ]; then
  r_test
else
  case $1 in
  "rw") TGT_PATH=${2:?"requires an target_path"}; rw_test;;
  "wr") TGT_PATH=${2:?"requires an target_path"}; rw_test;;
  "r") TGT_PATH=${2:?"requires an target_path"}; r_test;;
  "w") TGT_PATH=${2:?"requires an target_path"}; w_test;;
  *)
    echo "please input one of {r, w, wr, rw}";;
  esac
fi

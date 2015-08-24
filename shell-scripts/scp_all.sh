#!/bin/sh

NET_ID=192.168.2

for i in 24; do
  scp $1 $NET_ID.$i:$1;
done

#!/bin/bash

COUNT=10

for i in $(seq 1 $COUNT); do
  echo "[Test #$i]"
  ./Base
  echo " --- \n"
  sleep 1
done

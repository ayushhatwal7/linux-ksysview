#!/bin/sh

input=${1}
echo "input: ${input}"

if [ "${input}" = "1" ]; then
    insmod ksysview_core/ksysview_core.ko || { echo "[!] ksysview_core load failed"; exit 1; }
    insmod ksysview_proc/ksysview_proc.ko  || { echo "[!] ksysview_proc load failed";  exit 1; }
else
    rmmod ksysview_proc  || { echo "[!] ksysview_proc rmmod failed"; exit 1; }
    rmmod ksysview_core  || { echo "[!] ksysview_core rmmod failed"; exit 1; }
fi

lsmod | grep ksys
sleep 1

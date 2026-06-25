# ksysview

Unified Kernel Process & Thread Introspection Module — Stacked Architecture

## Overview
Two stacked loadable kernel modules exposing live process/thread introspection via /proc.

- `ksysview_core` — platform introspection, exports symbols via EXPORT_SYMBOL
- `ksysview_proc` — /proc interface, process/thread iteration, consumes core's exports

## Build
make
## Load
sudo insmod ksysview_core/ksysview_core.ko
sudo insmod ksysview_proc/ksysview_proc.ko

## Unload
sudo rmmod ksysview_proc
sudo rmmod ksysview_core

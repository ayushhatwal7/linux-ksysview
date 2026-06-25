KDIR ?= /lib/modules/$(shell uname -r)/build/
PWD := $(shell pwd)

ksysview_core:
	make -C ${KDIR} M=${PWD}/ksysview_core modules

ksysview_proc: ksysview_core 
	make -C ${KDIR} M=${PWD}/ksysview_proc \
		KBUILD_EXTRA_SYMBOLS=${PWD}/ksysview_core/Module.symvers modules

all: ksysview_proc

clean:
	make -C ${KDIR} M=${PWD}/ksysview_core clean
	make -C ${KDIR} M=${PWD}/ksysview_proc clean

.PHONY: ksysview_core ksysview_proc all clean

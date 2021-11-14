KERNEL_VERSION ?= $(shell uname -r)
KERNEL_PATH ?= /lib/modules/$(KERNEL_VERSION)/build

obj-m += sbiglpt.o

sbiglpt-y = \
	module.o \
	ioctl.o

all:
	make -C $(KERNEL_PATH) M=$(shell pwd) \
		KBUILD_EXTRA_SYMBOLS=$(KBUILD_EXTRA_SYMBOLS) modules

install:
	make -C $(KERNEL_PATH) M=$(shell pwd) modules_install
	depmod

clean:
	make -C $(KERNEL_PATH) M=$(shell pwd) clean

check:
	scripts/checkpatch.pl --no-tree -f --ignore=LINUX_VERSION_CODE \
		ioctl.c module.c sbiglpt.h sbiglpt_module.h

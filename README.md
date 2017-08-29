### sbig-parport

This is a port of the SBIG parallel port camera driver for Linux from
an older 2.4 kernel to a modern 4.9 kernel.

It is slightly different than the old one, in that it uses the "parport"
stack and thus doesn't directly access legacy x86 ports.  That allows it
to work with non-x86 parport hardware, such as
[pi-parport](https://github.com/garlick/pi-parport).

### SBIG Universal Driver

This driver provides a low-level interface, primarily `ioctl()` based, to the
SBIG Universal Driver, which provides the documented API for applications.
Fortunately, support for this interface has not been removed in modern
versions of the universal driver, at least up to version 4.84
(`LinuxDevKit-2014-10-27T12-58`).

### building

You'll need kernel headers or a kernel source tree.  To build against
headers packaged for your running kernel, run
```
$ cd driver
$ make
```
To build against another kernel, set `KERNEL_PATH` or `KERNEL_VERSION`
on the make command line.

### installing

```
$ cd ../udev
$ sudo cp 51-sbig-parport.rules /etc/udev/rules.d/
$ sudo udevadm control --reload-rules
$ sudo udevadm trigger
```

### running

```
$ modprobe parport parport_pc
$ insmod sbiglpt.ko
```

### testing

I have some old cameras I have tested with.  These include:
* ST-5C
* ST-7E
* ST-9E

I primarily test with [sbig-util](https://github.com/garlick/sbig-util).

Testing is pretty ad-hoc at this point.

### license

This kernel module is proprietary, although its source code was publicly
distributed by SBIG on its web site for many years.  It cannot be
re-distributed with the Linux kernel as this would violate the terms of
the kernel's GPL license.

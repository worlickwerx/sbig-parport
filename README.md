### sbig-parport

This is a Linux device driver for the older SBIG parallel port
astronomy cameras such as ST-237, ST-7, ST-8, ST-9.

This version includes changes to support modern kernels, and non-PC
parallel port devices such as
[pi-parport](https://github.com/worlickwerx/pi-parport).

The driver maintains the ABI expected by the SBIG Universal Driver SDK.
Versions up to 4.84 have been tested.  Parallel port cameras appear to
the SDK and applications as `LPT1`, `LPT2`, etc..

### Support

Issues and pull requests are welcome.
See also: [project wiki](https://github.com/worlickwerx/sbig-parport/wiki)

Note: this driver is no longer supported by SBIG/DL.

### License

SPDX-License-Identifier: GPL-2.0-only

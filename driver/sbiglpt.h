/* SPDX-License-Identifier: UNLICENSED */

/* This file defines the user-kernel interface.
 * It implements an ABI baked into the closed source
 * SBIG Universal Driver SDK, which is currently the only
 * viable method to access SBIG cameras, even for open
 * source software.  Do not change this ABI.
 */

#ifndef _SBIGLPT_H
#define _SBIGLPT_H

#define IOCTL_BASE 0xbb

/* N.B. some _IOWR macros should be _IOR, but changing breaks ABI.
 */
#define IOCTL_GET_JIFFIES		_IOWR(IOCTL_BASE, 1, void *)
#define IOCTL_GET_HZ			_IOWR(IOCTL_BASE, 2, void *)
#define IOCTL_GET_DRIVER_INFO		_IOWR(IOCTL_BASE, 3, void *)
#define IOCTL_SET_VDD			_IOWR(IOCTL_BASE, 4, void *)
#define IOCTL_GET_LAST_ERROR		_IOWR(IOCTL_BASE, 5, void *)

#define IOCTL_SEND_MICRO_BLOCK		_IOWR(IOCTL_BASE, 10, void *)
#define IOCTL_GET_MICRO_BLOCK		_IOWR(IOCTL_BASE, 11, void *)
#define IOCTL_SUBMIT_IN_URB		_IOWR(IOCTL_BASE, 12, void *)
#define IOCTL_GET_IN_URB		_IOWR(IOCTL_BASE, 13, void *)

#define IOCTL_INIT_PORT			_IO(IOCTL_BASE, 20)
#define IOCTL_CAMERA_OUT		_IOWR(IOCTL_BASE, 21, void *)
#define IOCTL_CLEAR_IMAG_CCD		_IOWR(IOCTL_BASE, 22, void *)
#define IOCTL_CLEAR_TRAC_CCD		_IOWR(IOCTL_BASE, 23, void *)
#define IOCTL_GET_PIXELS		_IOWR(IOCTL_BASE, 24, void *)
#define IOCTL_GET_AREA			_IOWR(IOCTL_BASE, 25, void *)
#define IOCTL_DUMP_ILINES		_IOWR(IOCTL_BASE, 26, void *)
#define IOCTL_DUMP_TLINES		_IOWR(IOCTL_BASE, 27, void *)
#define IOCTL_DUMP_5LINES		_IOWR(IOCTL_BASE, 28, void *)
#define IOCTL_CLOCK_AD			_IOWR(IOCTL_BASE, 29, void *)
#define IOCTL_REALLOCATE_PORTS		_IOWR(IOCTL_BASE, 30, void *)
#define IOCTL_SET_BUFFER_SIZE		_IOW(IOCTL_BASE, 31, __u16)
#define IOCTL_GET_BUFFER_SIZE		_IO(IOCTL_BASE, 32)
#define IOCTL_TEST_COMMAND		_IO(IOCTL_BASE, 33)

struct ioc_get_pixels_params {
	__s16 /* CAMERA_TYPE */ cameraID;
	__s16 /* CCD_REQUEST */ ccd;
	__s16 left;
	__s16 len;
	__s16 right;
	__s16 horzBin;
	__s16 vertBin;
	__s16 clearWidth;
	__s16 st237A;
	__s16 st253;
};

struct ioc_vclock_ccd_params {
	__s16 /* CAMERA_TYPE */ cameraID;
	__s16 onVertBin;
	__s16 clearWidth;
};

struct ioc_dump_lines_params {
	__s16 /* CAMERA_TYPE */ cameraID;
	__s16 width;
	__s16 len;
	__s16 vertBin;
	__s16 vToHRatio;
	__s16 st253;
};

struct ioc_clear_ccd_params {
	__s16 /* CAMERA_TYPE */ cameraID;
	__s16 height;
	__s16 times;
};

struct ioc_get_area_params {
	__s16 /* CAMERA_TYPE */ cameraID;
	__s16 /* CCD_REQUEST */ ccd;
	__s16 left;
	__s16 len;
	__s16 right;
	__s16 horzBin;
	__s16 vertBin;
	__s16 clearWidth;
	__s16 st237A;
	__s16 height;
};

struct linux_micro_block {
	__u8 *pBuffer;
	unsigned long length; // N.B. change to fixed size breaks ABI
};

struct linux_get_pixels_params {
	struct ioc_get_pixels_params gpp;
	__u16 *dest;
	unsigned long length; // N.B. change to fixed size breaks ABI
};

struct ioc_set_vdd {
	__u16 raiseIt;
	__u16 vddWasLow;
};

struct linux_camera_out_params {
	__u8 reg;
	__u8 value;
};

struct linux_get_area_params {
	struct ioc_get_area_params gap;
	__u16 *dest;
	unsigned long length; // N.B. change to fixed size breaks ABI
};

/* values must match PAR_ERROR in sbigudrv.h */
enum par_error {
	CE_NO_ERROR = 0,
	CE_BAD_PARAMETER = 6,
	CE_TX_TIMEOUT = 7,
	CE_RX_TIMEOUT = 8,
	CE_NAK_RECEIVED = 9,
	CE_CAN_RECEIVED = 10,
	CE_UNKNOWN_RESPONSE = 11,
	CE_BAD_LENGTH = 12,
	CE_AD_TIMEOUT = 13,
	// values not explicitly used in sbiglpt omitted
};

/* values must match CCD_REQUEST in sbigudrv.h */
enum ccd_request {
	CCD_IMAGING = 0,
	CCD_TRACKING = 1,
	CCD_EXT_TRACKING = 2,
};

/* values must match CAMERA_TYPE in sbigudrv.h */
enum camera_type {
	ST5C_CAMERA = 6,
	ST237_CAMERA = 8,
	ST10_CAMERA = 12,
	ST1K_CAMERA = 13,
	// values not explicitly used here omitted
};

/* layout must match must match GetDriverInfoResults0 in sbigudrv.h */
struct driver_info_results {
	__u16 version;
	__u8 name[64];
	__u16 maxRequest;
};


#endif /* !_SBIGLPT_H */

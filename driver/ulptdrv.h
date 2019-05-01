/* SPDX-License-Identifier: UNLICENSED */

/* This file defines the user-kernel interface.
 * It implements an ABI baked into the closed source
 * SBIG Universal Driver SDK, which is currently the only
 * viable method to access SBIG cameras, even for open
 * source software.  Do not change this ABI.
 */

#ifndef _ULPTDRV_
#define _ULPTDRV_

#define IOCTL_BASE 0xbb

#define IOCTL_GET_JIFFIES _IOWR(IOCTL_BASE, 1, char *)
#define IOCTL_GET_HZ _IOWR(IOCTL_BASE, 2, char *)
#define IOCTL_GET_DRIVER_INFO _IOWR(IOCTL_BASE, 3, char *)
#define IOCTL_SET_VDD _IOWR(IOCTL_BASE, 4, char *)
#define IOCTL_GET_LAST_ERROR _IOWR(IOCTL_BASE, 5, char *)

#define IOCTL_SEND_MICRO_BLOCK _IOWR(IOCTL_BASE, 10, char *)
#define IOCTL_GET_MICRO_BLOCK _IOWR(IOCTL_BASE, 11, char *)
#define IOCTL_SUBMIT_IN_URB _IOWR(IOCTL_BASE, 12, char *)
#define IOCTL_GET_IN_URB _IOWR(IOCTL_BASE, 13, char *)

#define IOCTL_INIT_PORT _IO(IOCTL_BASE, 20)
#define IOCTL_CAMERA_OUT _IOWR(IOCTL_BASE, 21, char *)
#define IOCTL_CLEAR_IMAG_CCD _IOWR(IOCTL_BASE, 22, char *)
#define IOCTL_CLEAR_TRAC_CCD _IOWR(IOCTL_BASE, 23, char *)
#define IOCTL_GET_PIXELS _IOWR(IOCTL_BASE, 24, char *)
#define IOCTL_GET_AREA _IOWR(IOCTL_BASE, 25, char *)
#define IOCTL_DUMP_ILINES _IOWR(IOCTL_BASE, 26, char *)
#define IOCTL_DUMP_TLINES _IOWR(IOCTL_BASE, 27, char *)
#define IOCTL_DUMP_5LINES _IOWR(IOCTL_BASE, 28, char *)
#define IOCTL_CLOCK_AD _IOWR(IOCTL_BASE, 29, char *)
#define IOCTL_REALLOCATE_PORTS _IOWR(IOCTL_BASE, 30, char *)
#define IOCTL_SET_BUFFER_SIZE _IOW(IOCTL_BASE, 31, unsigned short)
#define IOCTL_GET_BUFFER_SIZE _IO(IOCTL_BASE, 32)
#define IOCTL_TEST_COMMAND _IO(IOCTL_BASE, 33)

#define IOCTL_SUBMIT_PIXEL_IN_URB _IOWR(IOCTL_BASE, 34, char *)
#define IOCTL_GET_PIXEL_IN_URB _IOWR(IOCTL_BASE, 35, char *)
#define IOCTL_GET_PIXEL_BLOCK _IOWR(IOCTL_BASE, 36, char *)

struct ioc_camera_out_params {
	unsigned char reg;
	unsigned char value;
};

struct ioc_get_pixels_params {
	short /* CAMERA_TYPE */ cameraID;
	short /* CCD_REQUEST */ ccd;
	short left;
	short len;
	short right;
	short horzBin;
	short vertBin;
	short clearWidth;
	short st237A;
	short st253;
};

struct ioc_vclock_ccd_params {
	short /* CAMERA_TYPE */ cameraID;
	short onVertBin;
	short clearWidth;
};

struct ioc_dump_lines_params {
	short /* CAMERA_TYPE */ cameraID;
	short width;
	short len;
	short vertBin;
	short vToHRatio;
	short st253;
};

struct ioc_clear_ccd_params {
	short /* CAMERA_TYPE */ cameraID;
	short height;
	short times;
};

struct ioc_get_area_params {
	short /* CAMERA_TYPE */ cameraID;
	short /* CCD_REQUEST */ ccd;
	short left;
	short len;
	short right;
	short horzBin;
	short vertBin;
	short clearWidth;
	short st237A;
	short height;
};

struct linux_micro_block {
	unsigned char *pBuffer;
	unsigned long length;
};

struct linux_get_pixels_params {
	struct ioc_get_pixels_params gpp;
	unsigned short *dest;
	unsigned long length;
};

struct ioc_set_vdd {
	unsigned short raiseIt;
	unsigned short vddWasLow;
};

struct linux_camera_out_params {
	unsigned char reg;
	unsigned char value;
};

struct linux_get_area_params {
	struct ioc_get_area_params gap;
	unsigned short *dest;
	unsigned long length;
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
	unsigned short version;
	char name[64];
	unsigned short maxRequest;
};


#endif

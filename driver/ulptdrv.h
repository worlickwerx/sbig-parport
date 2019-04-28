/* SPDX-License-Identifier: UNLICENSED */

#ifndef _ULPTDRV_
#define _ULPTDRV_

#define IOCTL_BASE 0xbb

#define LIOCTL_GET_JIFFIES _IOWR(IOCTL_BASE, 1, char *)
#define LIOCTL_GET_HZ _IOWR(IOCTL_BASE, 2, char *)
#define LIOCTL_GET_DRIVER_INFO _IOWR(IOCTL_BASE, 3, char *)
#define LIOCTL_SET_VDD _IOWR(IOCTL_BASE, 4, char *)
#define LIOCTL_GET_LAST_ERROR _IOWR(IOCTL_BASE, 5, char *)

#define LIOCTL_SEND_MICRO_BLOCK _IOWR(IOCTL_BASE, 10, char *)
#define LIOCTL_GET_MICRO_BLOCK _IOWR(IOCTL_BASE, 11, char *)
#define LIOCTL_SUBMIT_IN_URB _IOWR(IOCTL_BASE, 12, char *)
#define LIOCTL_GET_IN_URB _IOWR(IOCTL_BASE, 13, char *)

#define LIOCTL_INIT_PORT _IO(IOCTL_BASE, 20)
#define LIOCTL_CAMERA_OUT _IOWR(IOCTL_BASE, 21, char *)
#define LIOCTL_CLEAR_IMAG_CCD _IOWR(IOCTL_BASE, 22, char *)
#define LIOCTL_CLEAR_TRAC_CCD _IOWR(IOCTL_BASE, 23, char *)
#define LIOCTL_GET_PIXELS _IOWR(IOCTL_BASE, 24, char *)
#define LIOCTL_GET_AREA _IOWR(IOCTL_BASE, 25, char *)
#define LIOCTL_DUMP_ILINES _IOWR(IOCTL_BASE, 26, char *)
#define LIOCTL_DUMP_TLINES _IOWR(IOCTL_BASE, 27, char *)
#define LIOCTL_DUMP_5LINES _IOWR(IOCTL_BASE, 28, char *)
#define LIOCTL_CLOCK_AD _IOWR(IOCTL_BASE, 29, char *)
#define LIOCTL_REALLOCATE_PORTS _IOWR(IOCTL_BASE, 30, char *)
#define LIOCTL_SET_BUFFER_SIZE _IOW(IOCTL_BASE, 31, unsigned short)
#define LIOCTL_GET_BUFFER_SIZE _IO(IOCTL_BASE, 32)
#define LIOCTL_TEST_COMMAND _IO(IOCTL_BASE, 33)

#define LIOCTL_SUBMIT_PIXEL_IN_URB _IOWR(IOCTL_BASE, 34, char *)
#define LIOCTL_GET_PIXEL_IN_URB _IOWR(IOCTL_BASE, 35, char *)
#define LIOCTL_GET_PIXEL_BLOCK _IOWR(IOCTL_BASE, 36, char *)

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

#endif

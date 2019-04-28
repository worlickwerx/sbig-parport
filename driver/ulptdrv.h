/* SPDX-License-Identifier: UNLICENSED */

/*

	ulptdrv.h - Contains the typedefs and prototypes for the
				low-level LPT drivers for the Universal Driver.

*/
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

/*

	Individual Command Struct Defines

	Note: Don't use enums as types because
		  Windows C compile makes them 4 bytes.

*/
typedef struct {
	unsigned char reg;
	unsigned char value;
} IOC_CAMERA_OUT_PARAMS;
typedef struct {
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
} IOC_GET_PIXELS_PARAMS;
typedef struct {
	short /* CAMERA_TYPE */ cameraID;
	short onVertBin;
	short clearWidth;
} IOC_VCLOCK_CCD_PARAMS;
typedef struct {
	short /* CAMERA_TYPE */ cameraID;
	short width;
	short len;
	short vertBin;
	short vToHRatio;
	short st253;
} IOC_DUMP_LINES_PARAMS;
typedef struct {
	short /* CAMERA_TYPE */ cameraID;
	short height;
	short times;
} IOC_CLEAR_CCD_PARAMS;
typedef struct {
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
} IOC_GET_AREA_PARAMS;

/*

	Linux Only Structs

*/
typedef struct {
	unsigned char *pBuffer;
	unsigned long length;
} LinuxMicroblock;
typedef struct {
	IOC_GET_PIXELS_PARAMS gpp;
	unsigned short *dest;
	unsigned long length;
} LinuxGetPixelsParams;
typedef struct {
	unsigned short raiseIt;
	unsigned short vddWasLow;
} IocSetVdd;

typedef struct {
	unsigned char reg;
	unsigned char value;
} LinuxCameraOutParams;

typedef struct {
	IOC_GET_AREA_PARAMS gap;
	unsigned short *dest;
	unsigned long length;
} LinuxGetAreaParams;

#endif

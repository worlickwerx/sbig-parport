/*

	PAROPTS.H - Lists the compile time options for the
    		    Parallel Driver

*/
#ifndef _PAROPTS_
#define _PAROPTS_

#ifndef _PARMICRO_
#include "parmicro.h"
#endif

#ifndef _PARLPT_
#include "parlpt.h"
#endif

#ifndef _UDRVSBIGONLY_
  #include "udrvsbigonly.h"
#endif

 typedef long HANDLE;
 typedef long USBDRIVER_HANDLE;

 #define enable()
 #define disable()
 #define closesocket(a) close(a)
 #define SOCKET_ERROR -1
 #define INVALID_SOCKET -1
 #define IP_ADDRESS_STR_LENGTH 16

#define DRIVER_VERSION		0x0435	// BCD version
#define DRIVER_STRING		"4.35"
    #define DRIVER_SUFFIX "-LINUX"
#define SIMULATE_CAMERA 		0					// set to 1 to simulate a camera/video
#define CAMERA_SIMULATED		STL_CAMERA			// set to the type of camera desired
#define STL_CAMERA_SIMULATED	STL_1001_CAMERA		// for ST-L camera this sub-type
#define NO_CLEARS 				4	// number of times to clear CCD at
									// start of exposure
#define FULL_CLEAR_TIME			6	// ticks before use full clear
#define DIDDLE_TE_FOR_READOUT	0	// set to 1 to cause TE cooler to change
									// +/- 3 % for readout for testing

#define IP_ADDRESS_STR_LENGTH		16

#define USB_GA_REV				5	/* default target Gate Array Rev */
#define INVALID_USB_DEVICE		0xFFFF

typedef enum {EXP_IDLE, EXP_IN_PROGRESS=2, EXP_COMPLETE } EXPOSURE_STATE;
// typedef enum {IMAGING_CCD, TRACKING_CCD } CCD;

typedef struct {
	/* must be first */
	MY_LOGICAL handleInUse;					/* = FALSE; */

	/* formerly global */
	short baseAddress;
	MY_LOGICAL imagingRIP, trackingRIP;
	MY_LOGICAL vddOverride;					/* = FALSE; */
	LINK_INFO linkInfo;						/* = { LINK_NONE, DEV_NONE, FALSE, 0, 0, 0}; */
	StartReadoutParams startReadoutParams;
	unsigned char control_out;				/* = 0; */
	unsigned char imaging_clocks_out;		/* = 0; */
	USHORT imagingBias;						/* = 0; */
	USHORT trackingBias;					/* = 0; */
	USHORT st5cBias;						/* = 0; */
	USHORT st237Bias;						/* = 0; */

	/* formerly static to sbigudrv.c */
	MY_LOGICAL driverOpen;					/* = FALSE; */
	short commandStatus[CC_LAST_COMMAND];
	EXPOSURE_STATE exposureState[2];
	MY_LOGICAL camLinkEstablished;			/* = FALSE; */
	CAMERA_TYPE cameraID;
	STL_CAMERA_TYPE stlCameraID;
	unsigned short firmwareVersion;
	struct {
		short width, height;
		short top, left, bottom, right;
		short full_width, full_height;
		short binning[10];
		USHORT gain;
		USHORT offset;
		USHORT bcd_pixel_width;
		USHORT bcd_pixel_height;
		USHORT dump_extra;
		USHORT storage_height;
	} ccd_info[2];
	struct {
		short hasTrackingCCD;
		short baseIsST7;
		short baseIsST5C;
		short trackerIs237;
		short featherCam;
		short st237A;
		CCD_REQUEST maxCCD;
	} cameraInfo;
	MiscellaneousControlParams lastControl;	/* = { TRUE, SC_LEAVE_SHUTTER, LED_ON }; */
	EEPROMContents eeprom;
	MY_LOGICAL shutterOpen;
	MY_LOGICAL waitForTrigger;
	CCD_REQUEST triggeredCCD;
	StartExposureParams triggerExpParams;
	unsigned long lastTrackingTime;
	MY_LOGICAL teFrozen;					/* = FALSE; */
	MY_LOGICAL teFrozenOff;
	USHORT lastTESetpoint;
	USHORT lastTEPower;
	MY_LOGICAL teAutoFreeze;				/* = FALSE; */
	MY_LOGICAL st253;
	MY_LOGICAL closeShutterOnEndExposure;
	unsigned long cfwT0, cfwTimeout;
	MY_LOGICAL cfwTimerSet;

	/* options from Application */
	UDRV_OPTIONS udrvOpt;

	unsigned short debugMsgOption;

	HANDLE lptHandle;					/* = INVALID_HANDLE_VALUE; */
	HANDLE ethHandle;					/* = INVALID_HANDLE_VALUE; */
	HANDLE usblHandle;
	FifoInfo fifoInfo;
	MY_LOGICAL m_bNeedCleanup;
	ENUM_USB_DRIVER usbDriver;
	unsigned short thisUSBDevice;

	int m_cliSocket;					/* = INVALID_SOCKET; */
} DLL_GLOBALS, *PDLL_GLOBALS;

/* Driver Control Parameters */
extern unsigned long driverControlParams[];

extern unsigned short GetNextUSBDevice(void);

#endif
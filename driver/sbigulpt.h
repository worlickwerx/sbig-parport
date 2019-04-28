/*

	sbigulpt.h - Contains the prototypes for the LPT code

*/
#ifndef _SBIGULPT_
#define _SBIGULPT_

#define DOS_VERSION_BCD			0x0400						/* DOS version in BCD */
#define DOS_VERSION_STRING  	"SBIGULPT Ver 4.0D" 		/* DOS version string */
#define VXD_VERSION_BCD			0x0407						/* VXD version in BCD */
#define VXD_VERSION_STRING  	"SBIGUDrv.VXD Ver 4.07"		/* VXD version string */
#define GENERIC_VERSION_BCD		0x0400						/* Generic version in BCD */
#define GENERIC_VERSION_STRING  "SBIGULPT.XXX Ver 4.0G"		/* Generic version string */

typedef struct _DEVICE_EXTENSION {
        //CCD local data are stored here:
        SetIRQLParams               NewIrql, OldIrql;
        PUCHAR                      BaseAddress;
        UCHAR                       control_out;
		ULONG						noBytesRd;
		ULONG						noBytesWr;
        UCHAR                       imaging_clocks_out;
        USHORT						state;
		USHORT						irqCount;
}DEVICE_EXTENSION, *PDEVICE_EXTENSION;

extern void ULPTInitPort(PDEVICE_EXTENSION pDevExt);
extern void ULPTCameraOut(PDEVICE_EXTENSION pDevExt, UCHAR reg, UCHAR val);
extern UCHAR ULPTCameraIn(PDEVICE_EXTENSION pDevExt, UCHAR reg);

extern PAR_ERROR ULPTGetUSTimer(PDEVICE_EXTENSION pDevExt,
                    GetUSTimerResults  *Results);
extern PAR_ERROR ULPTSendMicroBlock(PDEVICE_EXTENSION pDevExt,
                    UCHAR *pData, DWORD dataLen);
extern PAR_ERROR ULPTGetMicroBlock(PDEVICE_EXTENSION pDevExt,
					UCHAR *pData, DWORD dataLen);
extern PAR_ERROR ULPTGetPixels(PDEVICE_EXTENSION pDevExt,
						   IOC_GET_PIXELS_PARAMS *pParams,
						   unsigned short *dest, DWORD resultsSize);
extern PAR_ERROR ULPTGetArea(PDEVICE_EXTENSION pDevExt,
						   IOC_GET_AREA_PARAMS *pParams,
						   unsigned short *dest, DWORD resultsSize);
extern PAR_ERROR ULPTRVClockImagingCCD(PDEVICE_EXTENSION pDevExt,
							   IOC_VCLOCK_CCD_PARAMS *pParams);
extern PAR_ERROR ULPTRVClockTrackingCCD(PDEVICE_EXTENSION pDevExt,
							   IOC_VCLOCK_CCD_PARAMS *pParams);
extern PAR_ERROR ULPTRVClockST5CCCD(PDEVICE_EXTENSION pDevExt,
							   IOC_VCLOCK_CCD_PARAMS *pParams);
extern PAR_ERROR ULPTRVClockST253CCCD(PDEVICE_EXTENSION pDevExt,
							   IOC_VCLOCK_CCD_PARAMS *pParams);
extern PAR_ERROR ULPTDumpImagingLines(PDEVICE_EXTENSION pDevExt,
								  IOC_DUMP_LINES_PARAMS *pParams);
extern PAR_ERROR ULPTDumpTrackingLines(PDEVICE_EXTENSION pDevExt,
								  IOC_DUMP_LINES_PARAMS *pParams);
extern PAR_ERROR ULPTDumpST5CLines(PDEVICE_EXTENSION pDevExt,
								  IOC_DUMP_LINES_PARAMS *pParams);
extern PAR_ERROR ULPTDumpST253Lines(PDEVICE_EXTENSION pDevExt,
								  IOC_DUMP_LINES_PARAMS *pParams);
extern void ULPTSetVdd(PDEVICE_EXTENSION pDevExt, short raiseIt,
				   UCHAR *pVddWasLow);
extern PAR_ERROR ULPTClockAD(PDEVICE_EXTENSION pDevExt, short len);
extern PAR_ERROR ULPTClearImagingArray(PDEVICE_EXTENSION pDevExt,
								   IOC_CLEAR_CCD_PARAMS *pParams);
extern PAR_ERROR ULPTClearTrackingArray(PDEVICE_EXTENSION pDevExt,
								   IOC_CLEAR_CCD_PARAMS *pParams);
extern ULONG MyTickCount(void);
extern PAR_ERROR ULPTGetDriverInfo(GetDriverInfoParams *pParams,
							GetDriverInfoResults0 *pResults);

#endif

/*********************************************************
File:   ComStack_Types.h
Author: Hischi
Date:   25-05-2019
----------------------------------------------------------
Specification:              AUTOSAR_SWS_ComStackTypes.pdf
Part of AUTOSAR Standard:   Classic Platform
Part of Standard Release:   4.3.1
*********************************************************/

#include "Std_Types.h"      /* SWS_Comtype_00001 */
#include "ComStack_Cfg.h"   /* SWS_Comtype_00001 */

#ifndef COMSTACK_TYPES_H    /* SWS_Comtype_00016 */
#define COMSTACK_TYPES_H

typedef uint16 PduIdType;   /* SWS_COMTYPE_00005 */

typedef uint32 PduLengthType;   /* SWS_COMTYPE_00008 */

typedef struct {
    uint8*          SduDataPtr;
    uint8*          MetaDataPtr;
    PduLengthType   SduLength;
} PduInfoType;                  /* SWS_COMTYPE_00011 */

typedef uint8 PNCHandleType;    /* SWS_COMTYPE_00036 */

typedef uint8 TPParameterType;  /* SWS_COMTYPE_00031 */
#define TP_STMIN    0x00u          
#define TP_BS       0x01u
#define TP_BC       0x02u

typedef uint8 BufReq_ReturnType;    /* SWS_COMTYPE_00012 */
#define BUFREQ_OK       0x00u
#define BUFREQ_E_NOT_OK 0x01u
#define BUFREQ_E_BUSY   0x02u
#define BUFREQ_E_OVFL   0x03u

typedef uint8 TpDataStateType;  /* SWS_COMTYPE_00027 */
#define TP_DATACONF     0x00u
#define TP_DATARETRY    0x01u
#define TP_CONFPENDING  0x02u

typedef struct {
    TpDataStateType TpDataState;
    PduLengthType   TxTpDataCnt;
} RetryInfoType;        /* SWS_COMTYPE_00037 */

typedef uint8 NetworkHandleType;    /* SWS_COMTYPE_00038 */

typedef uint8 IcomConfigType;       /* SWS_COMTYPE_00039 */

typedef uint8 IcomSwitch_ErrorType; /* SWS_COMTYPE_00040 */
#define ICAOM_SWITCH_E_OK       0x00u
#define ICOM_SWITCH_E_FAILED    0x01u

#endif /* COMSTACK_TYPES_H */
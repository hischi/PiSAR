/*********************************************************
File:   Std_Types.h
Author: Hischi
Date:   25-05-2019
----------------------------------------------------------
Specification:              AUTOSAR_SWS_StandardTypes.pdf
Part of AUTOSAR Standard:   Classic Platform
Part of Standard Release:   4.3.1
*********************************************************/

#ifndef STD_TYPES_H             /* SWS_Std_00014 */
#define STD_TYPES_H

#include "Compiler.h"           /* SWS_Std_00019 */
#include "Platform_Types.h"     /* SWS_Std_00019 */


typedef uint8 Std_ReturnType;   /* SWS_Std_00005 */
#ifndef STATUSTYPEDEFINED       /* SWS_Std_00006 */
    #define STATUSTYPEDEFINED
    #define E_OK 0x00u
    typedef unsigned char StatusType; /* OSEK compliance */
#endif
#define E_NOT_OK    0x01u       /* SWS_Std_00006 */

typedef struct {
	uint16  vendorID;
	uint16  moduleID;
	uint8   sw_major_version;
	uint8   sw_minor_version;
	uint8   sw_patch_version;
} Std_VersionInfoType;          /* SWS_Std_00015 */

#define STD_HIGH    0x01u  /* Physical state 5V or 3.3V */  /* SWS_Std_00007 */
#define STD_LOW     0x00u  /* Physical state 0V */          /* SWS_Std_00007 */

#define STD_ACTIVE  0x01u /* Logical state active */        /* SWS_Std_00013 */
#define STD_IDLE    0x00u /* Logical state idle */          /* SWS_Std_00013 */

#define STD_ON      0x01u       /* SWS_Std_00010 */
#define STD_OFF     0x00u       /* SWS_Std_00010 */

#endif /* STD_TYPES_H */

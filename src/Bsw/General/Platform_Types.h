/*********************************************************
File:   Platform_Types.h
Author: Hischi
Date:   25-05-2019
----------------------------------------------------------
Specification:              AUTOSAR_SWS_PlatformTypes.pdf
Part of AUTOSAR Standard:   Classic Platform
Part of Standard Release:   4.3.1
*********************************************************/

#ifndef PLATFORM_TYPES_H             
#define PLATFORM_TYPES_H

typedef char boolean;       /* SWS_Platform_00026 */
#ifndef TRUE                /* SWS_Platform_00056 */
    #define TRUE 1
#endif
#ifndef FALSE
    #define FALSE 0         /* SWS_Platform_00056 */
#endif

typedef char uint8;                 /* SWS_Platform_00013 */

typedef unsigned short int uint16;  /* SWS_Platform_00014 */

typedef unsigned int uint32;        /* SWS_Platform_00015 */

typedef unsigned long uint64;       /* SWS_Platform_00066 */

typedef signed char sint8;          /* SWS_Platform_00016 */

typedef signed short int sint16;    /* SWS_Platform_00017 */

typedef signed int sint32;          /* SWS_Platform_00018 */

typedef signed long sint64;         /* SWS_Platform_00067 */

typedef uint8 uint8_least;          /* SWS_Platform_00020 */

typedef uint16 uint16_least;        /* SWS_Platform_00021 */

typedef uint32 uint32_least;        /* SWS_Platform_00022 */

typedef sint8 sint8_least;          /* SWS_Platform_00023 */

typedef sint16 sint16_least;        /* SWS_Platform_00024 */

typedef sint32 sint32_least;        /* SWS_Platform_00025 */

typedef float float32;              /* SWS_Platform_00041 */

typedef double float64;             /* SWS_Platform_00042 */

#define CPU_TYPE_8  8               /* SWS_Platform_00064 */
#define CPU_TPYE_16 16              /* SWS_Platform_00064 */
#define CPU_TYPE_32 32              /* SWS_Platform_00064 */
#define CPU_TYPE_64 64              /* SWS_Platform_00064 */
#define CPU_TYPE CPU_TYPE_32        /* SWS_Platform_00045 */

#define MSB_FIRST 0                 /* SWS_Platform_00038 */
#define LSB_FIRST 1                 /* SWS_Platform_00038 */
#define CPU_BIT_ORDER MSB_FIRST     /* SWS_Platform_00048 */

#define HIGH_BYTE_FIRST 0           /* SWS_Platform_00039 */
#define LOW_BYTE_FIRST  1           /* SWS_Platform_00039 */
#define CPU_BYTE_ORDER LOW_BYTE_FIRST   /* SWS_Platform_00051 */


#endif /* PLATFORM_TYPES_H */

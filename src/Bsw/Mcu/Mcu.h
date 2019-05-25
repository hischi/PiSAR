/*********************************************************
File:   Mcu.h
Author: Hischi
Date:   25-05-2019
----------------------------------------------------------
Specification:              AUTOSAR_SWS_MCUDriver.pdf
Part of AUTOSAR Standard:   Classic Platform
Part of Standard Release:   4.3.1
*********************************************************/

#ifndef MCU_H
#define MCU_H

#define MCU_MODULE_ID       101
#define MCU_VENDOR_ID       0x1234
#define MCU_MAJOR_VERSION   0
#define MCU_MINOR_VERSION   1
#define MCU_PATCH_VERSION   0

/*--------------------------------------------------------
  Includes
--------------------------------------------------------*/

#include "Mcu_Cfg.h"                /* SWS_Mcu_00211 */
#include "../General/Std_Types.h"   /* SWS_Mcu_00152 */

/*--------------------------------------------------------
  Type definitions
--------------------------------------------------------*/

typedef struct {
    uint8   dummy;
} Mcu_ConfigType;       /* SWS_Mcu_00249 */

typedef uint8 Mcu_PllStatusType;    /* SWS_Mcu_00250 */
#define MCU_PLL_STATUS_UNDEFINED    0x00u
#define MCU_PLL_UNLOCKED            0x01u
#define MCU_PLL_LOCKED              0x02u

typedef uint8 Mcu_ClockType;        /* SWS_Mcu_00251 */

typedef uint8 Mcu_ResetType;        /* SWS_Mcu_00252 */
#define MCU_RESET_UNDEFINED         0x00u
#define MCU_RESET_POWER_ON_RESET    0x01u
#define MCU_WATCHDOG_RESET          0x02u
#define MCU_SW_RESET                0x03u

typedef Mcu_ResetType Mcu_RawResetType; /* SWS_Mcu_00253 */

typedef uint8 Mcu_ModeType;         /* SWS_Mcu_00254 */

typedef uint32 Mcu_RamSectionType;  /* SWS_Mcu_00255 */

typedef uint8 Mcu_RamStateType;     /* SWS_Mcu_00256 */
#define MCU_RAMSTATE_INVALID    0x00u
#define MCU_RAMSTATE_VALID      0x01u

/*--------------------------------------------------------
  Function definitions
--------------------------------------------------------*/
void Mcu_Init(
    const Mcu_ConfigType* ConfigPtr
);  /* SWS_Mcu_00153 */

Std_ReturnType Mcu_InitRamSection(
    Mcu_RamSectionType RamSection
);  /* SWS_Mcu_00154 */

Std_ReturnType Mcu_InitClock(
    Mcu_ClockType ClockSetting
);  /* SWS_Mcu_00155 */

Std_ReturnType Mcu_DistributePllClock(
    void
);  /* SWS_Mcu_00156 */

Mcu_PllStatusType Mcu_GetPllStatus(
    void
);  /* SWS_Mcu_00157 */

Mcu_ResetType Mcu_GetResetReason(
    void
);  /* SWS_Mcu_00158 */

Mcu_RawResetType Mcu_GetResetRawValue(
    void
);  /* SWS_Mcu_00159 */

void Mcu_PerformReset(
    void
);  /* SWS_Mcu_00160 */

void Mcu_SetMode(
    Mcu_ModeType McuMode
);  /* SWS_Mcu_00161 */

void Mcu_GetVersionInfo(
    Std_VersionInfoType* versioninfo
);  /* SWS_Mcu_00162 */

Mcu_RamStateType Mcu_GetRamState(
    void
);  /* SWS_Mcu_00207 */

#endif /* MCU_H */




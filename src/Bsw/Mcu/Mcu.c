/*********************************************************
File:   Mcu.c
Author: Hischi
Date:   25-05-2019
----------------------------------------------------------
Specification:              AUTOSAR_SWS_MCUDriver.pdf
Part of AUTOSAR Standard:   Classic Platform
Part of Standard Release:   4.3.1
*********************************************************/

#include "Mcu.h"
#include "Mcu_MemMap.h"

#include <string.h>
#include <time.h>
#include <stdio.h>

#define MCU_RESET_PATH "/nvm/reset.txt" 

/*--------------------------------------------------------
  Locals
--------------------------------------------------------*/
Mcu_ConfigType mcu_config;  /* Holds the current Mcu configuration*/

clock_t clock_startvalue;
Mcu_PllStatusType pll_status = MCU_PLL_STATUS_UNDEFINED;    /* SWS_Mcu_00132 */



/*--------------------------------------------------------
  API implementation
--------------------------------------------------------*/

void Mcu_Init(const Mcu_ConfigType* ConfigPtr) {
    mcu_config = *ConfigPtr;    /* SWS_Mcu_00026 */

    pll_status = MCU_PLL_STATUS_UNDEFINED;
}

Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection) {

    if (RamSection < Mcu_RamSectionCount) {   /* Check if parameter is in range */
        
        memset(&Mcu_Ram[SECTIONADDR2ADDR(RamSection, 0)], McuRamDefaultValue, Mcu_RamSectionSize);  /* SWS_Mcu_00011 */
        return E_OK;

    } else {

        return E_NOT_OK;
    }
}


Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting) {
    clock_startvalue = clock();
    pll_status = MCU_PLL_LOCKED;    /* SWS_Mcu_00137 */

    return E_OK;
}

Std_ReturnType Mcu_DistributePllClock(void) {
    return E_OK;
}

Mcu_PllStatusType Mcu_GetPllStatus(void) {
    return pll_status;  /* SWS_Mcu_00008 */
}

Mcu_ResetType Mcu_GetResetReason(void) {
    FILE *fp;
    int c;
    Mcu_ResetType reset_type = MCU_RESET_UNDEFINED;

    fp = fopen(MCU_RESET_PATH, "r");
    if (fp) {
        c = fgetc(fp);
        if (c == 'p') {
            reset_type = MCU_RESET_POWER_ON_RESET;
        }
        else if (c == 'w') {
            reset_type = MCU_WATCHDOG_RESET;
        }
        else if (c == 's') {
            reset_type = MCU_SW_RESET;
        }

        fclose(fp);
    }
    
    return reset_type;
}

Mcu_RawResetType Mcu_GetResetRawValue(void) {
    return Mcu_GetResetReason();
}

void Mcu_PerformReset(void) {
    FILE *fp;
    fp = fopen(MCU_RESET_PATH, "w+");
    if (fp) {
        fputc('s', fp);
        fclose(fp);
    }

    pll_status = MCU_PLL_STATUS_UNDEFINED;
}

void Mcu_SetMode(Mcu_ModeType McuMode) {

}

void Mcu_GetVersionInfo(Std_VersionInfoType* versioninfo) {
    versioninfo->moduleID = MCU_MODULE_ID;
    versioninfo->vendorID = MCU_VENDOR_ID;
    versioninfo->sw_major_version = MCU_MAJOR_VERSION;
    versioninfo->sw_minor_version = MCU_MINOR_VERSION;
    versioninfo->sw_patch_version = MCU_PATCH_VERSION;
}

Mcu_RamStateType Mcu_GetRamState(void) {
    return MCU_RAMSTATE_VALID;
}
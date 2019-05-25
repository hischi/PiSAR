/*********************************************************
File:   Mcu_MemMap.h
Author: Hischi
Date:   25-05-2019
----------------------------------------------------------
Specification:              AUTOSAR_SWS_MCUDriver.pdf
Part of AUTOSAR Standard:   Classic Platform
Part of Standard Release:   4.3.1
*********************************************************/

#ifndef MCU_MEMMAP_H
#define MCU_MEMMAP_H

#define Mcu_RamSectionCount 8
#define Mcu_RamSectionSize 16777216  /* 16 MiB , 0x1000000*/

char Mcu_Ram[Mcu_RamSectionCount *  Mcu_RamSectionSize];

#define ADDR2SECTION(addr) (addr >> 27) 
#define ADDR2SECTIONADDR(addr) (addr & 0x00FFFFFF)
#define SECTIONADDR2ADDR(section, section_addr) ((section << 27) | section_addr)

#define Mcu_StackSection 0
#define Mcu_StackMaxSize Mcu_RamSectionSize
const char* Mcu_StackBottom = &Mcu_Ram[SECTIONADDR2ADDR(Mcu_StackSection, 0)];


#endif /* MCU_MEMMAP_H */
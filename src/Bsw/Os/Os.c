/*********************************************************
File:   Os.h
Author: Hischi
Date:   25-05-2019
----------------------------------------------------------
Specification:              AUTOSAR_SWS_OS.pdf
Part of AUTOSAR Standard:   Classic Platform
Part of Standard Release:   4.3.1
*********************************************************/

#include "Os.h"

/*--------------------------------------------------------
Locals
--------------------------------------------------------*/
TickType Os_Timer_LastValues[Os_Cfg_TimerCount];



/*--------------------------------------------------------
API Implementation
--------------------------------------------------------*/
ApplicationType GetApplicationID(void) {

}

ApplicationType GetCurrentApplicationID(void);    /* SWS_Os_00797 */

ISRType GetISRID(void);    /* SWS_Os_00511 */

StatusType CallTrustedFunction(
    TrustedFunctionIndexType        FunctionIndex,
    TrustedFunctionParameterRefType FunctionParams
);  /* SWS_Os_00097 */

AccessType CheckISRMemoryAccess(
    ISRType                 ISRID,
    MemoryStartAddressType  Address,
    MemorySizeType          Size
);  /* SWS_Os_00512 */

AccessType CheckTaskMemoryAccess(
    TaskType                TaskID,
    MemoryStartAddressType  Address,
    MemorySizeType          Size
);  /* SWS_Os_00513 */

ObjectAccessType CheckObjectAccess(
    ApplicationType     ApplID,
    ObjectTypeType      ObjectType,
    ...
);  /* SWS_Os_00256 */

ApplicationType CheckObjectOwnership(
    ObjectTypeType ObjectType,
    ...
);  /* SWS_Os_00017 */

StatusType StartScheduleTableRel(
    ScheduleTableType   ScheduleTableID,
    TickType            Offset
);  /* SWS_Os_00347 */

StatusType StartScheduleTableAbs(
    ScheduleTableType   ScheduleTableID,
    TickType            Start
);  /* SWS_Os_00358 */

StatusType StopScheduleTable(
    ScheduleTableType ScheduleTableID
);  /* SWS_Os_00006 */

StatusType NextScheduleTable(
    ScheduleTableType ScheduleTableID_From,
    ScheduleTableType ScheduleTableID_To
);  /* SWS_Os_00191 */

StatusType StartScheduleTableSynchron(
    ScheduleTableType ScheduleTableID
);  /* SWS_Os_00201 */

StatusType SyncScheduleTable(
    ScheduleTableType   ScheduleTableID,
    TickType            Value
);  /* SWS_Os_00199 */

StatusType SetScheduletableAsync(
    ScheduleTableType ScheduleTableID
);  /* SWS_Os_00422 */

StatusType GetScheduleTableStatus(
    ScheduleTableType           ScheduleTableID,
    ScheduleTableStatusRefType  ScheduleStatus
);  /* SWS_Os_00227 */

StatusType IncrementCounter(
    CounterType CounterID
);  /* SWS_Os_00399 */

StatusType GetCounterValue(
    CounterType CounterID,
    TickRefType Value
);  /* SWS_Os_00383 */

StatusType GetElapsedValue(
    CounterType CounterID,
    TickRefType Value,
    TickRefType ElapsedValue
);  /* SWS_Os_00392 */

StatusType TerminateApplication(
    ApplicationType Application,
    RestartType     RestartOption
);  /* SWS_Os_00258 */

StatusType AllowAccess(void);   /* SWS_Os_00501 */

StatusType GetApplicationState(
    ApplicationType         Application,
    ApplicationStateRefType Value
);  /* SWS_Os_00499 */

uint32 GetNumberOfActivatedCores(void);     /* SWS_Os_00672 */

CoreIdType GetCoreID(void);     /* SWS_Os_00674 */

void StartCore(
    CoreIdType  CoreID,
    StatusType* Status
);  /* SWS_Os_00676 */

void StartNonAutosarCore(
    CoreIdType  CoreID,
    StatusType* Status
);  /* SWS_Os_00682 */

StatusType GetSpinlock(
    SpinlockIdType SpinlockId
);  /* SWS_Os_00686 */

StatusType ReleaseSpinlock(
    SpinlockIdType SpinlockId
);  /* SWS_Os_00695 */

StatusType TryToGetSpinlock(
    SpinlockIdType          SpinlockId,
    TryToGetSpinlockType*   Success
);  /* SWS_Os_00703 */

void ShutdownAllCores(
    StatusType Error
);  /* SWS_Os_00713 */

StatusType ControlIdle(
    CoreIdType      CoreID,
    IdleModeType    IdleMode
);  /* SWS_Os_00769 */

StatusType ReadPeripheral8(
    AreaIdType      Area,
    const uint8*    Address,
    uint8*          ReadValue
);  /* SWS_Os_91013 */

StatusType ReadPeripheral16(
    AreaIdType      Area,
    const uint16*   Address,
    uint16*         ReadValue
);  /* SWS_Os_91015 */

StatusType ReadPeripheral32(
    AreaIdType      Area,
    const uint32*   Address,
    uint32*         ReadValue
);  /* SWS_Os_91014 */

StatusType WritePeripheral8(
    AreaIdType  Area,
    uint8*      Address,
    uint8       WriteValue
);  /* SWS_Os_91010 */

StatusType WritePeripheral16(
    AreaIdType  Area,
    uint16*     Address,
    uint16      WriteValue
);  /* SWS_Os_91012 */

StatusType WritePeripheral32(
    AreaIdType  Area,
    uint32*     Address,
    uint32      WriteValue
);  /* SWS_Os_91011 */

StatusType ModifyPeripheral8(
    AreaIdType  Area,
    uint8*      Address,
    uint8       Clearmask,
    uint8       Setmask
);  /* SWS_Os_91016 */

StatusType ModifyPeripheral16(
    AreaIdType  Area,
    uint16*     Address,
    uint16      Clearmask,
    uint16      Setmask
);  /* SWS_Os_91018 */

StatusType ModifyPeripheral32(
    AreaIdType  Area,
    uint32*     Address,
    uint32      Clearmask,
    uint32      Setmask
);  /* SWS_Os_91017 */

StatusType EnableInterruptSource(
    ISRType ISRID,
    boolean ClearPending
);  /* SWS_Os_91020 */

StatusType DisableInterruptSource(
    ISRType ISRID
);  /* SWS_Os_91019 */

StatusType ClearPendingInterrupt(
    ISRType ISRID
);  /* SWS_Os_91021 */
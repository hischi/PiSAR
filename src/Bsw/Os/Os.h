/*********************************************************
File:   Os.h
Author: Hischi
Date:   25-05-2019
----------------------------------------------------------
Specification:              AUTOSAR_SWS_OS.pdf
Part of AUTOSAR Standard:   Classic Platform
Part of Standard Release:   4.3.1
*********************************************************/

#ifndef OS_H
#define OS_H

#include "../General/Std_Types.h"
#include "../../Rte/Rte_Type.h"
#include "Os_Cfg.h"
#include "Os_MemMap.h"

#define OSMEMORY_IS_READABLE(ptr) ptr
#define OSMEMORY_IS_WRITEABLE(ptr) ptr
#define OSMEMORY_IS_EXECUTEABLE(ptr) ptr
#define OSMEMORY_IS_STACKSPACE(ptr) ptr

/*--------------------------------------------------------
Type definitions
--------------------------------------------------------*/

typedef uint32 ApplicationType;     /* SWS_Os_00772 */
#define INVALID_OSAPPLICATION 0u

typedef uint8 ApplicationStateType; /* SWS_Os_00773 */
#define APPLICATION_ACCESSIBLE  0x00u
#define APPLICATION_RESTARTING  0x01u
#define APPLICATION_TERMINATED  0x02u
typedef P2VAR(ApplicationStateType,AUTOMATIC,AUTOMATIC) ApplicationStateRefType;   /* SWS_Os_00774 */

typedef uint32 TrustedFunctionIndexType;    /* SWS_Os_00775 */
typedef P2VAR(TrustedFunctionIndexType, AUTOMATIC, AUTOMATIC) TrustedFunctionParameterRefType;   /* SWS_Os_00776 */

typedef uint8 AccessType;       /* SWS_Os_00777 */

typedef uint8 ObjectAccessType; /* SWS_Os_00778 */
#define NO_ACCESS   0x00u
#define ACCESS      0x01u

typedef uint8 ObjectTypeType;   /* SWS_Os_00779 */
#define OBJECT_TASK             0x00u
#define OBJECT_ISR              0x01u
#define OBJECT_ALARM            0x02u
#define OBJECT_RESOURCE         0x03u
#define OBJECT_COUNTER          0x04u
#define OBJECT_SCHEDULETABLE    0x05u

typedef void* MemoryStartAddressType;   /* SWS_Os_00780 */

typedef uint32 MemorySizeType;          /* SWS_Os_00781 */

typedef uint8 ISRType;                  /* SWS_Os_00782 */
#define INVALID_ISR 0x00u

typedef uint32 ScheduleTableType;       /* SWS_Os_00783 */

typedef uint8 ScheduleTableStatusType;  /* SWS_Os_00784 */
#define SCHEDULETABLE_STOPPED   0x00u
#define SCHEDULETABLE_NEXT      0x01u
#define SCHEDULETABLE_WAITING   0x02u
#define SCHEDULETABLE_RUNNING   0x03u
#define SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS 0x04u
typedef P2VAR(ScheduleTableStatusType,AUTOMATIC,AUTOMATIC) ScheduleTableStatusRefType;  /* SWS_Os_00785 */

typedef uint8 ProtectionReturnType;     /* SWS_Os_00787 */
#define PRO_IGNORE                  0x00u
#define PRO_TERMINATETASKISR        0x01u
#define PRO_TERMINATEAPPL           0x02u
#define PRO_TERMINATEAPPL_RESTART   0x03u
#define PRO_SHUTDOWN                0x04u

typedef uint8 RestartType;              /* SWS_Os_00788 */
#define NO_RESTART  0x00u
#define RESTART     0x01u

typedef uint64 PhysicalTimeType;        /* SWS_Os_00789 */

typedef uint32 CoreIdType;              /* SWS_Os_00790 */
#define OS_CORE_ID_MASTER   0u
#define OS_CORE_ID_0        0u

typedef uint16 SpinlockIdType;          /* SWS_Os_00791 */
#define INVALID_SPINLOCK    0u

typedef uint8 TryToGetSpinlockType;     /* SWS_Os_00792 */
#define TRYTOGETSPINLOCK_NOSUCCESS  0x00u
#define TRYTOGETSPINLOCK_SUCCESS    0x01u

typedef uint8 IdleModeType;             /* SWS_Os_00793 */
#define IDLE_NO_HALT    0x00u

typedef uint16 AreaIdType;              /* SWS_Os_91000 */

typedef uint32 TaskType;

typedef uint32 TickType;
typedef P2VAR(TickType, AUTOMATIC, AUTOMATIC) TickRefType;

typedef uint32 CounterType;             /* SWS_Os_00786 */

typedef uint64 TimeInMicrosecondsType;  /* SWS_Os_00794 */



/*--------------------------------------------------------
Function definitions
--------------------------------------------------------*/

ApplicationType GetApplicationID(void);    /* SWS_Os_00016 */

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

/*--------------------------------------------------------
IOC definitions
--------------------------------------------------------*/

#define IOC_E_OK        RTE_E_OK
#define IOC_E_NOK       RTE_E_NOK
#define IOC_E_LIMIT     RTE_E_LIMIT
#define IOC_E_LOST_DATA RTE_E_LOST_DATA
#define IOC_E_NO_DATA   RTE_E_NO_DATA

/*--------------------------------------------------------
Hook definitions
--------------------------------------------------------*/

ProtectionReturnType ProtectionHook(
    StatusType Fatalerror
);  /* SWS_Os_00538 */

#endif /* OS_H */



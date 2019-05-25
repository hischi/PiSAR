/*********************************************************
File:   Compiler_Cfg.h
Author: Hischi
Date:   25-05-2019
----------------------------------------------------------
Specification:              AUTOSAR_SWS_CompilerAbstraction.pdf
Part of AUTOSAR Standard:   Classic Platform
Part of Standard Release:   4.3.1
*********************************************************/

#ifndef COMPILER_CFG_H      
#define COMPILER_CFG_H

#define AUTOMATIC               /* SWS_COMPILER_00046 */

#define TYPEDEF                 /* SWS_COMPILER_00059 */

#define NULL_PTR ((void*) 0)    /* SWS_COMPILER_00051 */

#define INLINE                  /* SWS_COMPILER_00057 */

#define LOCAL_INLINE            /* SWS_COMPILER_00060 */


#define FUNC(type, memclass) type   /* SWS_COMPILER_00005 */

#define FUNC_P2CONST(rettype, ptrclass, memclass) const rettype *   /* SWS_COMPILER_00061 */

#define FUNC_P2VAR(rettype, ptrclass, memclass) rettype *           /* SWS_COMPILER_00063 */

#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *                /* SWS_COMPILER_00006 */

#define P2CONST(ptrtype, memclass, ptrclass) (const ptrtype) *      /* SWS_COMPILER_00013 */

#define CONSTP2VAR (ptrtype, memclass, ptrclass) const (ptrtype *)  /* SWS_COMPILER_00031 */

#define CONSTP2CONST(ptrtype, memclass, ptrclass) const (const ptrtype *)   /* SWS_COMPILER_00032 */

#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)       /* SWS_COMPILER_00039 */

#define CONSTP2FUNC(rettype, ptrclass, fctname) rettype (* const fctname)   /* SWS_COMPILER_00065 */

#define CONST(consttype, memclass) const consttype  /* SWS_COMPILER_00023 */

#define VAR(vartype, memclass) vartype              /* SWS_COMPILER_00026 */


#endif /* COMPILER_CFG_H */
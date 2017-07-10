/* $Id: udivmoddi4.c 67298 2017-06-08 13:26:34Z vboxsync $ */
/** @file
 * IPRT - __udivmoddi4 implementation
 */

/*
 * Copyright (C) 2006-2016 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 *
 * The contents of this file may alternatively be used under the terms
 * of the Common Development and Distribution License Version 1.0
 * (CDDL) only, as it comes in the "COPYING.CDDL" file of the
 * VirtualBox OSE distribution, in which case the provisions of the
 * CDDL are applicable instead of those of the GPL.
 *
 * You may elect to license modified versions of this file under the
 * terms and conditions of either the GPL or the CDDL or both.
 */

#include <iprt/stdint.h>
#include <iprt/uint64.h>

uint64_t __udivmoddi4(uint64_t u64A, uint64_t u64B, uint64_t *pu64R);

/**
 * __udivmoddi4() implementation to satisfy external references from 32-bit
 * code generated by gcc-7 or later.
 *
 * @param   u64A        The divident value.
 * @param   u64B        The divisor value.
 * @param   pu64R       A pointer to the reminder. May be NULL.
 * @returns u64A / u64B
 */
uint64_t __udivmoddi4(uint64_t u64A, uint64_t u64B, uint64_t *pu64R)
{
    RTUINT64U Divident;
    RTUINT64U Divisor;
    RTUINT64U Quotient;
    RTUINT64U Reminder;
    Divident.u = u64A;
    Divisor.u  = u64B;
    RTUInt64DivRem(&Quotient, &Reminder, &Divident, &Divisor);
    if (pu64R)
        *pu64R = Reminder.u;
    return Quotient.u;
}

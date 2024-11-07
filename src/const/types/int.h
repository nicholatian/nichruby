/*********************************************************************\
 *    __   _ _____ _______ _     _  ______ _     _ ______ __   __    *
 *    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      *
 *    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       *
 *                             nich ruby                             *
 *                                                                   *
 *             Copyright (C) 2020-2024 Alexander Nicholi             *
 *                    Released under BSD-2-Clause                    *
\*********************************************************************/

#ifndef INC__NICHRUBY_CONST_TYPES_INT_H
#define INC__NICHRUBY_CONST_TYPES_INT_H

#ifndef TYPELESS
/* Prevents the compiler from doing type analysis based optimisations
 * on the type, treating it as octet-addressable cast-friendly data. */
#define TYPELESS __attribute__( ( may_alias ) )
#endif

/* Signed 32-bit integer. */
typedef __INT32_TYPE__ s32 TYPELESS;
/* Signed 16-bit integer. */
typedef __INT16_TYPE__ s16 TYPELESS;
/* Signed 8-bit integer. */
typedef __INT8_TYPE__ s8 TYPELESS;
/* Unsigned 32-bit integer. */
typedef __UINT32_TYPE__ u32 TYPELESS;
/* Unsigned 16-bit integer. */
typedef __UINT16_TYPE__ u16 TYPELESS;
/* Unsigned 8-bit integer. */
typedef __UINT8_TYPE__ u8 TYPELESS;

#endif /* INC__NICHRUBY_CONST_TYPES_INT_H */

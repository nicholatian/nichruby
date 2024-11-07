/*********************************************************************\
 *    __   _ _____ _______ _     _  ______ _     _ ______ __   __    *
 *    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      *
 *    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       *
 *                             nich ruby                             *
 *                                                                   *
 *             Copyright (C) 2020-2024 Alexander Nicholi             *
 *                    Released under BSD-2-Clause                    *
\*********************************************************************/

#ifndef INC__NICHRUBY_CONST_TYPES_CHAR_H
#define INC__NICHRUBY_CONST_TYPES_CHAR_H

#ifndef PACKED
/* Force the structure to be tightly packed into as few octets as
 * possible. */
#define PACKED __attribute__( ( packed ) )
#endif

#ifndef TYPELESS
/* Prevents the compiler from doing type analysis based optimisations
 * on the type, treating it as octet-addressable cast-friendly data. */
#define TYPELESS __attribute__( ( may_alias ) )
#endif

/* A single ASCII character. */
typedef __UINT8_TYPE__ chr TYPELESS;

/* A single Unicode code point. */
struct uchr
{
	/* The lower 16 bits of the code point. */
	__UINT16_TYPE__ lo;
	/* The upper 5 bits of the code point. */
	__UINT16_TYPE__ hi;
} PACKED TYPELESS;

/* A single Unicode code point. */
typedef struct uchr uchr;

#endif /* INC__NICHRUBY_CONST_TYPES_CHAR_H */

/*********************************************************************\
 *    __   _ _____ _______ _     _  ______ _     _ ______ __   __    *
 *    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      *
 *    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       *
 *                             nich ruby                             *
 *                                                                   *
 *             Copyright (C) 2020-2024 Alexander Nicholi             *
 *                    Released under BSD-2-Clause                    *
\*********************************************************************/

#ifndef INC__NICHRUBY_CONST_TYPES_BASE_H
#define INC__NICHRUBY_CONST_TYPES_BASE_H

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

#ifndef NORETURN
#define NORETURN __attribute__( ( noreturn ) )
#endif

#ifndef PURE
#define PURE __attribute__( ( pure ) )
#endif

#ifndef ALIGN
#define ALIGN( _n ) __attribute__( ( aligned( _n ) ) )
#endif

#ifndef ASSUME
#define ASSUME( _e ) __builtin_assume( ( _e ) )
#endif

#ifndef UNREACHABLE
#define UNREACHABLE __builtin_unreachable( )
#endif

#ifndef NULL
#define NULL ( 0 )
#endif

#ifndef FALSE
#define FALSE ( 0 )
#endif

#ifndef TRUE
#define TRUE ( !( FALSE ) )
#endif

typedef __UINTPTR_TYPE__ ptri TYPELESS;
typedef __INTPTR_TYPE__ offs TYPELESS;
typedef _Bool bl TYPELESS;

#endif /* INC__NICHRUBY_CONST_TYPES_BASE_H */

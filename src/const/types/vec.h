/*********************************************************************\
 *    __   _ _____ _______ _     _  ______ _     _ ______ __   __    *
 *    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      *
 *    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       *
 *                             nich ruby                             *
 *                                                                   *
 *             Copyright (C) 2020-2024 Alexander Nicholi             *
 *                    Released under BSD-2-Clause                    *
\*********************************************************************/

#ifndef INC__NICHRUBY_CONST_TYPES_VEC_H
#define INC__NICHRUBY_CONST_TYPES_VEC_H

#ifndef VECSIZE
#define VECSIZE( _n ) __attribute__( ( vector_size( _n ) ) )
#endif

/* 2-wide vector of signed 32-bit integers. */
typedef __INT32_TYPE__ s32v2 VECSIZE( 8 );
/* 4-wide vector of signed 32-bit integers. */
typedef __INT32_TYPE__ s32v4 VECSIZE( 16 );
/* 8-wide vector of signed 32-bit integers. */
typedef __INT32_TYPE__ s32v8 VECSIZE( 32 );
/* 16-wide vector of signed 32-bit integers. */
typedef __INT32_TYPE__ s32v16 VECSIZE( 64 );

/* 2-wide vector of signed 16-bit integers. */
typedef __INT16_TYPE__ s16v2 VECSIZE( 4 );
/* 4-wide vector of signed 16-bit integers. */
typedef __INT16_TYPE__ s16v4 VECSIZE( 8 );
/* 8-wide vector of signed 16-bit integers. */
typedef __INT16_TYPE__ s16v8 VECSIZE( 16 );
/* 16-wide vector of signed 16-bit integers. */
typedef __INT16_TYPE__ s16v16 VECSIZE( 32 );
/* 32-wide vector of signed 16-bit integers. */
typedef __INT16_TYPE__ s16v32 VECSIZE( 64 );

/* 2-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ s8v2 VECSIZE( 2 );
/* 4-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ s8v4 VECSIZE( 4 );
/* 8-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ s8v8 VECSIZE( 8 );
/* 16-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ s8v16 VECSIZE( 16 );
/* 32-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ s8v32 VECSIZE( 32 );
/* 64-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ s8v64 VECSIZE( 64 );

/* 2-wide vector of unsigned 32-bit integers. */
typedef __UINT32_TYPE__ u32v2 VECSIZE( 8 );
/* 4-wide vector of unsigned 32-bit integers. */
typedef __UINT32_TYPE__ u32v4 VECSIZE( 16 );
/* 8-wide vector of unsigned 32-bit integers. */
typedef __UINT32_TYPE__ u32v8 VECSIZE( 32 );
/* 16-wide vector of unsigned 32-bit integers. */
typedef __UINT32_TYPE__ u32v16 VECSIZE( 64 );

/* 2-wide vector of unsigned 16-bit integers. */
typedef __UINT16_TYPE__ u16v2 VECSIZE( 4 );
/* 4-wide vector of unsigned 16-bit integers. */
typedef __UINT16_TYPE__ u16v4 VECSIZE( 8 );
/* 8-wide vector of unsigned 16-bit integers. */
typedef __UINT16_TYPE__ u16v8 VECSIZE( 16 );
/* 16-wide vector of unsigned 16-bit integers. */
typedef __UINT16_TYPE__ u16v16 VECSIZE( 32 );
/* 32-wide vector of unsigned 16-bit integers. */
typedef __UINT16_TYPE__ u16v32 VECSIZE( 64 );

/* 2-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ u8v2 VECSIZE( 2 );
/* 4-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ u8v4 VECSIZE( 4 );
/* 8-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ u8v8 VECSIZE( 8 );
/* 16-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ u8v16 VECSIZE( 16 );
/* 32-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ u8v32 VECSIZE( 32 );
/* 64-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ u8v64 VECSIZE( 64 );

#endif /* INC__NICHRUBY_CONST_TYPES_VEC_H */

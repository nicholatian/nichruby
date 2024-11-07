/*********************************************************************\
 *    __   _ _____ _______ _     _  ______ _     _ ______ __   __    *
 *    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      *
 *    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       *
 *                             nich ruby                             *
 *                                                                   *
 *             Copyright (C) 2020-2024 Alexander Nicholi             *
 *                    Released under BSD-2-Clause                    *
\*********************************************************************/

#ifndef INC__NICHRUBY_CCHELP_H
#define INC__NICHRUBY_CCHELP_H

#ifndef ALIGNED_ALLOCA
#define ALIGNED_ALLOCA(_n, _a) __builtin_alloca_with_align((_n), (_a))
#endif

#ifndef ALLOCA
#define ALLOCA(_n) __builtin_alloca( ( _n ) )
#endif

#ifndef POPCOUNT
#define POPCOUNT( _n ) __builtin_popcountg( ( _n ) )
#endif

#ifndef CLZ
#define CLZ( _n ) __builtin_clzg( ( _n ) )
#endif

#ifndef CTZ
#define CTZ( _n ) __builtin_ctzg( ( _n ) )
#endif

#ifndef CHECKED_ADD
#define CHECKED_ADD( _x, _y, _s ) \
	__builtin_add_overflow( ( _x ), ( _y ), ( _s ) )
#endif

#ifndef CHECKED_SUB
#define CHECKED_SUB( _x, _y, _d ) \
	__builtin_sub_overflow( ( _x ), ( _y ), ( _d ) )
#endif

#ifndef CHECKED_MUL
#define CHECKED_MUL( _x, _y, _p ) \
	__builtin_mul_overflow( ( _x ), ( _y ), ( _p ) )
#endif

#endif /* INC__NICHRUBY_CCHELP_H */

/* -*- coding: utf-8 -*- */
/****************************************************************************\
 *       __   _ _____ _______ _     _  ______ _     _ ______  __   __       *
 *       | \  |   |   |       |_____| |_____/ |     | |_____]   \_/         *
 *       |  \_| __|__ |_____  |     | |    \_ |_____| |_____]    |          *
 *                                 nichruby                                 *
 *                                                                          *
 *                    Copyright © 2020 Alexander Nicholi                    *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC__CONST_BATTLE_WEATHER_H
#define INC__CONST_BATTLE_WEATHER_H

enum /* weather */
{
	WEATHER_RAIN_TEMP = 1 << 0,
	/* NOTE: downpour is unused */
	WEATHER_RAIN_POUR  = 1 << 1,
	WEATHER_RAIN_PERM = 1 << 2,
	WEATHER_RAIN_ANY = WEATHER_RAIN_TEMP | WEATHER_RAIN_POUR |
	   WEATHER_RAIN_PERM,
	WEATHER_SANDSTORM_TEMP = 1 << 3,
	WEATHER_SANDSTORM_PERM = 1 << 4,
	WEATHER_SANDSTORM_ANY =
	   WEATHER_SANDSTORM_TEMP | WEATHER_SANDSTORM_PERM,
	WEATHER_SUN_TEMP = 1 << 5,
	WEATHER_SUN_PERM = 1 << 6,
	WEATHER_SUN_ANY       = WEATHER_SUN_TEMP | WEATHER_SUN_PERM,
	WEATHER_HAIL          = 1 << 7,
	WEATHER_HAIL_ANY      = WEATHER_HAIL,
	WEATHER_ANY           = WEATHER_RAIN_ANY | WEATHER_SANDSTORM_ANY |
	   WEATHER_SUN_ANY | WEATHER_HAIL_ANY
};

#endif /* INC__CONST_BATTLE_WEATHER_H */

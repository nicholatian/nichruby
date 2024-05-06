/*********************************************************************\
 *    __   _ _____ _______ _     _  ______ _     _ ______ __   __    *
 *    | \  |   |   |       |_____| |_____/ |     | |_____]  \_/      *
 *    |  \_| __|__ |_____  |     | |    \_ |_____| |_____]   |       *
 *                             nich ruby                             *
 *                                                                   *
 *             Copyright (C) 2020-2024 Alexander Nicholi             *
 *                    Released under BSD-2-Clause                    *
\*********************************************************************/

/* DEFINITION MODULE */

#ifndef INC__CONST_MON_MOVES_H
#define INC__CONST_MON_MOVES_H

enum /* moves */
{
	MOVE_NONE,
	MOVE_POUND,
	MOVE_KARATE_CHOP,
	MOVE_DOUBLE_SLAP,
	MOVE_COMET_PUNCH,
	MOVE_MEGA_PUNCH,
	MOVE_PAY_DAY,
	MOVE_FIRE_PUNCH,
	MOVE_ICE_PUNCH,
	MOVE_THUNDER_PUNCH,
	MOVE_SCRATCH,
	MOVE_VICE_GRIP,
	MOVE_GUILLOTINE,
	MOVE_RAZOR_WIND,
	MOVE_SWORDS_DANCE,
	MOVE_CUT,
	MOVE_GUST,
	MOVE_WING_ATTACK,
	MOVE_WHIRLWIND,
	MOVE_FLY,
	MOVE_BIND,
	MOVE_SLAM,
	MOVE_VINE_WHIP,
	MOVE_STOMP,
	MOVE_DOUBLE_KICK,
	MOVE_MEGA_KICK,
	MOVE_JUMP_KICK,
	MOVE_ROLLING_KICK,
	MOVE_SAND_ATTACK,
	MOVE_HEADBUTT,
	MOVE_HORN_ATTACK,
	MOVE_FURY_ATTACK,
	MOVE_HORN_DRILL,
	MOVE_TACKLE,
	MOVE_BODY_SLAM,
	MOVE_WRAP,
	MOVE_TAKE_DOWN,
	MOVE_THRASH,
	MOVE_DOUBLE_EDGE,
	MOVE_TAIL_WHIP,
	MOVE_POISON_STING,
	MOVE_TWINEEDLE,
	MOVE_PIN_MISSILE,
	MOVE_LEER,
	MOVE_BITE,
	MOVE_GROWL,
	MOVE_ROAR,
	MOVE_SING,
	MOVE_SUPERSONIC,
	MOVE_SONIC_BOOM,
	MOVE_DISABLE,
	MOVE_ACID,
	MOVE_EMBER,
	MOVE_FLAMETHROWER,
	MOVE_MIST,
	MOVE_WATER_GUN,
	MOVE_HYDRO_PUMP,
	MOVE_SURF,
	MOVE_ICE_BEAM,
	MOVE_BLIZZARD,
	MOVE_PSYBEAM,
	MOVE_BUBBLE_BEAM,
	MOVE_AURORA_BEAM,
	MOVE_HYPER_BEAM,
	MOVE_PECK,
	MOVE_DRILL_PECK,
	MOVE_SUBMISSION,
	MOVE_LOW_KICK,
	MOVE_COUNTER,
	MOVE_SEISMIC_TOSS,
	MOVE_STRENGTH,
	MOVE_ABSORB,
	MOVE_MEGA_DRAIN,
	MOVE_LEECH_SEED,
	MOVE_GROWTH,
	MOVE_RAZOR_LEAF,
	MOVE_SOLAR_BEAM,
	MOVE_POISON_POWDER,
	MOVE_STUN_SPORE,
	MOVE_SLEEP_POWDER,
	MOVE_PETAL_DANCE,
	MOVE_STRING_SHOT,
	MOVE_DRAGON_RAGE,
	MOVE_FIRE_SPIN,
	MOVE_THUNDER_SHOCK,
	MOVE_THUNDERBOLT,
	MOVE_THUNDER_WAVE,
	MOVE_THUNDER,
	MOVE_ROCK_THROW,
	MOVE_EARTHQUAKE,
	MOVE_FISSURE,
	MOVE_DIG,
	MOVE_TOXIC,
	MOVE_CONFUSION,
	MOVE_PSYCHIC,
	MOVE_HYPNOSIS,
	MOVE_MEDITATE,
	MOVE_AGILITY,
	MOVE_QUICK_ATTACK,
	MOVE_RAGE,
	MOVE_TELEPORT,
	MOVE_NIGHT_SHADE,
	MOVE_MIMIC,
	MOVE_SCREECH,
	MOVE_DOUBLE_TEAM,
	MOVE_RECOVER,
	MOVE_HARDEN,
	MOVE_MINIMIZE,
	MOVE_SMOKESCREEN,
	MOVE_CONFUSE_RAY,
	MOVE_WITHDRAW,
	MOVE_DEFENSE_CURL,
	MOVE_BARRIER,
	MOVE_LIGHT_SCREEN,
	MOVE_HAZE,
	MOVE_REFLECT,
	MOVE_FOCUS_ENERGY,
	MOVE_BIDE,
	MOVE_METRONOME,
	MOVE_MIRROR_MOVE,
	MOVE_SELF_DESTRUCT,
	MOVE_EGG_BOMB,
	MOVE_LICK,
	MOVE_SMOG,
	MOVE_SLUDGE,
	MOVE_BONE_CLUB,
	MOVE_FIRE_BLAST,
	MOVE_WATERFALL,
	MOVE_CLAMP,
	MOVE_SWIFT,
	MOVE_SKULL_BASH,
	MOVE_SPIKE_CANNON,
	MOVE_CONSTRICT,
	MOVE_AMNESIA,
	MOVE_KINESIS,
	MOVE_SOFT_BOILED,
	MOVE_HI_JUMP_KICK,
	MOVE_GLARE,
	MOVE_DREAM_EATER,
	MOVE_POISON_GAS,
	MOVE_BARRAGE,
	MOVE_LEECH_LIFE,
	MOVE_LOVELY_KISS,
	MOVE_SKY_ATTACK,
	MOVE_TRANSFORM,
	MOVE_BUBBLE,
	MOVE_DIZZY_PUNCH,
	MOVE_SPORE,
	MOVE_FLASH,
	MOVE_PSYWAVE,
	MOVE_SPLASH,
	MOVE_ACID_ARMOR,
	MOVE_CRABHAMMER,
	MOVE_EXPLOSION,
	MOVE_FURY_SWIPES,
	MOVE_BONEMERANG,
	MOVE_REST,
	MOVE_ROCK_SLIDE,
	MOVE_HYPER_FANG,
	MOVE_SHARPEN,
	MOVE_CONVERSION,
	MOVE_TRI_ATTACK,
	MOVE_SUPER_FANG,
	MOVE_SLASH,
	MOVE_SUBSTITUTE,
	MOVE_STRUGGLE,
	MOVE_SKETCH,
	MOVE_TRIPLE_KICK,
	MOVE_THIEF,
	MOVE_SPIDER_WEB,
	MOVE_MIND_READER,
	MOVE_NIGHTMARE,
	MOVE_FLAME_WHEEL,
	MOVE_SNORE,
	MOVE_CURSE,
	MOVE_FLAIL,
	MOVE_CONVERSION_2,
	MOVE_AEROBLAST,
	MOVE_COTTON_SPORE,
	MOVE_REVERSAL,
	MOVE_SPITE,
	MOVE_POWDER_SNOW,
	MOVE_PROTECT,
	MOVE_MACH_PUNCH,
	MOVE_SCARY_FACE,
	MOVE_FAINT_ATTACK,
	MOVE_SWEET_KISS,
	MOVE_BELLY_DRUM,
	MOVE_SLUDGE_BOMB,
	MOVE_MUD_SLAP,
	MOVE_OCTAZOOKA,
	MOVE_SPIKES,
	MOVE_ZAP_CANNON,
	MOVE_FORESIGHT,
	MOVE_DESTINY_BOND,
	MOVE_PERISH_SONG,
	MOVE_ICY_WIND,
	MOVE_DETECT,
	MOVE_BONE_RUSH,
	MOVE_LOCK_ON,
	MOVE_OUTRAGE,
	MOVE_SANDSTORM,
	MOVE_GIGA_DRAIN,
	MOVE_ENDURE,
	MOVE_CHARM,
	MOVE_ROLLOUT,
	MOVE_FALSE_SWIPE,
	MOVE_SWAGGER,
	MOVE_MILK_DRINK,
	MOVE_SPARK,
	MOVE_FURY_CUTTER,
	MOVE_STEEL_WING,
	MOVE_MEAN_LOOK,
	MOVE_ATTRACT,
	MOVE_SLEEP_TALK,
	MOVE_HEAL_BELL,
	MOVE_RETURN,
	MOVE_PRESENT,
	MOVE_FRUSTRATION,
	MOVE_SAFEGUARD,
	MOVE_PAIN_SPLIT,
	MOVE_SACRED_FIRE,
	MOVE_MAGNITUDE,
	MOVE_DYNAMIC_PUNCH,
	MOVE_MEGAHORN,
	MOVE_DRAGON_BREATH,
	MOVE_BATON_PASS,
	MOVE_ENCORE,
	MOVE_PURSUIT,
	MOVE_RAPID_SPIN,
	MOVE_SWEET_SCENT,
	MOVE_IRON_TAIL,
	MOVE_METAL_CLAW,
	MOVE_VITAL_THROW,
	MOVE_MORNING_SUN,
	MOVE_SYNTHESIS,
	MOVE_MOONLIGHT,
	MOVE_HIDDEN_POWER,
	MOVE_CROSS_CHOP,
	MOVE_TWISTER,
	MOVE_RAIN_DANCE,
	MOVE_SUNNY_DAY,
	MOVE_CRUNCH,
	MOVE_MIRROR_COAT,
	MOVE_PSYCH_UP,
	MOVE_EXTREME_SPEED,
	MOVE_ANCIENT_POWER,
	MOVE_SHADOW_BALL,
	MOVE_FUTURE_SIGHT,
	MOVE_ROCK_SMASH,
	MOVE_WHIRLPOOL,
	MOVE_BEAT_UP,
	MOVE_FAKE_OUT,
	MOVE_UPROAR,
	MOVE_STOCKPILE,
	MOVE_SPIT_UP,
	MOVE_SWALLOW,
	MOVE_HEAT_WAVE,
	MOVE_HAIL,
	MOVE_TORMENT,
	MOVE_FLATTER,
	MOVE_WILL_O_WISP,
	MOVE_MEMENTO,
	MOVE_FACADE,
	MOVE_FOCUS_PUNCH,
	MOVE_SMELLING_SALT,
	MOVE_FOLLOW_ME,
	MOVE_NATURE_POWER,
	MOVE_CHARGE,
	MOVE_TAUNT,
	MOVE_HELPING_HAND,
	MOVE_TRICK,
	MOVE_ROLE_PLAY,
	MOVE_WISH,
	MOVE_ASSIST,
	MOVE_INGRAIN,
	MOVE_SUPERPOWER,
	MOVE_MAGIC_COAT,
	MOVE_RECYCLE,
	MOVE_REVENGE,
	MOVE_BRICK_BREAK,
	MOVE_YAWN,
	MOVE_KNOCK_OFF,
	MOVE_ENDEAVOR,
	MOVE_ERUPTION,
	MOVE_SKILL_SWAP,
	MOVE_IMPRISON,
	MOVE_REFRESH,
	MOVE_GRUDGE,
	MOVE_SNATCH,
	MOVE_SECRET_POWER,
	MOVE_DIVE,
	MOVE_ARM_THRUST,
	MOVE_CAMOUFLAGE,
	MOVE_TAIL_GLOW,
	MOVE_LUSTER_PURGE,
	MOVE_MIST_BALL,
	MOVE_FEATHER_DANCE,
	MOVE_TEETER_DANCE,
	MOVE_BLAZE_KICK,
	MOVE_MUD_SPORT,
	MOVE_ICE_BALL,
	MOVE_NEEDLE_ARM,
	MOVE_SLACK_OFF,
	MOVE_HYPER_VOICE,
	MOVE_POISON_FANG,
	MOVE_CRUSH_CLAW,
	MOVE_BLAST_BURN,
	MOVE_HYDRO_CANNON,
	MOVE_METEOR_MASH,
	MOVE_ASTONISH,
	MOVE_WEATHER_BALL,
	MOVE_AROMATHERAPY,
	MOVE_FAKE_TEARS,
	MOVE_AIR_CUTTER,
	MOVE_OVERHEAT,
	MOVE_ODOR_SLEUTH,
	MOVE_ROCK_TOMB,
	MOVE_SILVER_WIND,
	MOVE_METAL_SOUND,
	MOVE_GRASS_WHISTLE,
	MOVE_TICKLE,
	MOVE_COSMIC_POWER,
	MOVE_WATER_SPOUT,
	MOVE_SIGNAL_BEAM,
	MOVE_SHADOW_PUNCH,
	MOVE_EXTRASENSORY,
	MOVE_SKY_UPPERCUT,
	MOVE_SAND_TOMB,
	MOVE_SHEER_COLD,
	MOVE_MUDDY_WATER,
	MOVE_BULLET_SEED,
	MOVE_AERIAL_ACE,
	MOVE_ICICLE_SPEAR,
	MOVE_IRON_DEFENSE,
	MOVE_BLOCK,
	MOVE_HOWL,
	MOVE_DRAGON_CLAW,
	MOVE_FRENZY_PLANT,
	MOVE_BULK_UP,
	MOVE_BOUNCE,
	MOVE_MUD_SHOT,
	MOVE_POISON_TAIL,
	MOVE_COVET,
	MOVE_VOLT_TACKLE,
	MOVE_MAGICAL_LEAF,
	MOVE_WATER_SPORT,
	MOVE_CALM_MIND,
	MOVE_LEAF_BLADE,
	MOVE_DRAGON_DANCE,
	MOVE_ROCK_BLAST,
	MOVE_SHOCK_WAVE,
	MOVE_WATER_PULSE,
	MOVE_DOOM_DESIRE,
	MOVE_PSYCHO_BOOST,
	MAX_MOVE
};

#endif /* INC__CONST_MON_MOVES_H */

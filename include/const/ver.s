@ -*- coding: utf-8 -*-
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@       __   _ _____ _______ _     _  ______ _     _ ______  __   __       @@
@@       | \  |   |   |       |_____| |_____/ |     | |_____]   \_/         @@
@@       |  \_| __|__ |_____  |     | |    \_ |_____| |_____]    |          @@
@@                                 nichruby                                 @@
@@                                                                          @@
@@                    Copyright © 2020 Alexander Nicholi                    @@
@@                       Released under BSD-2-Clause.                       @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.ifdef SAPPHIRE
.equ GAME_VERSION, 1
.else
.equ GAME_VERSION, 2
.endif

.ifdef SAPPHIRE
.set MUS_EVIL_TEAM, MUS_AQA_0
.set MUS_GOOD_TEAM, MUS_MGM0
.else
.set MUS_EVIL_TEAM, MUS_MGM0
.set MUS_GOOD_TEAM, MUS_AQA_0
.endc

.ifdef SAPPHIRE
.set ITEM_ORB, ITEM_BLUE_ORB
.else
.set ITEM_ORB, ITEM_RED_ORB
.endif

.ifdef SAPPHIRE
.set SPECIES_KYOGROUD, SPECIES_KYOGRE
.else
.set SPECIES_KYOGROUD, SPECIES_GROUDON
.endif

.ifdef SAPPHIRE
.set SPECIES_LATIAOS, SPECIES_LATIOS
.else
.set SPECIES_LATIAOS, SPECIES_LATIAS
.endif

.ifdef SAPPHIRE
.set TRAINER_PETALBURG_WOODS_GRUNT, TRAINER_GRUNT_9
.set TRAINER_RUSTURF_TUNNEL_GRUNT, TRAINER_GRUNT_15
.set TRAINER_MUSEUM_2F_GRUNT_1, TRAINER_GRUNT_19
.set TRAINER_MUSEUM_2F_GRUNT_2, TRAINER_GRUNT_20
.set TRAINER_514, TRAINER_HECTOR_1
.set TRAINER_MT_CHIMNEY_GRUNT_1, TRAINER_MATT_2
.set TRAINER_MT_CHIMNEY_GRUNT_2, TRAINER_GRUNT_13
.set TRAINER_HIDEOUT_1F_GRUNT, TRAINER_GRUNT_1
.set TRAINER_HIDEOUT_B1F_GRUNT_1, TRAINER_GRUNT_2
.set TRAINER_HIDEOUT_B1F_GRUNT_2, TRAINER_GRUNT_3
.set TRAINER_HIDEOUT_B1F_GRUNT_3, TRAINER_GRUNT_26
.set TRAINER_HIDEOUT_B2F_GRUNT_1, TRAINER_MATT_1
.set TRAINER_HIDEOUT_B2F_GRUNT_2, TRAINER_GRUNT_4
.set TRAINER_HIDEOUT_B2F_GRUNT_3, TRAINER_GRUNT_27
.set TRAINER_SEAFLOOR_CAVERN_GRUNT_1, TRAINER_GRUNT_5
.set TRAINER_SEAFLOOR_CAVERN_GRUNT_2, TRAINER_GRUNT_6
.set TRAINER_SEAFLOOR_CAVERN_GRUNT_3, TRAINER_SHELLY_2
.set TRAINER_SEAFLOOR_CAVERN_GRUNT_4, TRAINER_GRUNT_7
.set TRAINER_SEAFLOOR_CAVERN_GRUNT_5, TRAINER_ARCHIE_2
.set TRAINER_MT_CHIMNEY_GRUNT_3, TRAINER_ARCHIE_3
.set TRAINER_MT_PYRE_SUMMIT_GRUNT_1, TRAINER_GRUNT_22
.set TRAINER_MT_PYRE_SUMMIT_GRUNT_2, TRAINER_GRUNT_23
.set TRAINER_MT_PYRE_SUMMIT_GRUNT_3, TRAINER_GRUNT_24
.set TRAINER_WEATHER_INSTITUTE_GRUNT_1, TRAINER_GRUNT_16
.set TRAINER_WEATHER_INSTITUTE_GRUNT_2, TRAINER_GRUNT_25
.set TRAINER_WEATHER_INSTITUTE_GRUNT_3, TRAINER_GRUNT_17
.set TRAINER_WEATHER_INSTITUTE_GRUNT_4, TRAINER_GRUNT_18
.set TRAINER_WEATHER_INSTITUTE_GRUNT_5, TRAINER_SHELLY_1
.else
.set TRAINER_PETALBURG_WOODS_GRUNT, TRAINER_GRUNT_36
.set TRAINER_RUSTURF_TUNNEL_GRUNT, TRAINER_GRUNT_42
.set TRAINER_MUSEUM_2F_GRUNT_1, TRAINER_GRUNT_46
.set TRAINER_MUSEUM_2F_GRUNT_2, TRAINER_GRUNT_47
.set TRAINER_514, TRAINER_HECTOR_2
.set TRAINER_MT_CHIMNEY_GRUNT_1, TRAINER_TABITHA_2
.set TRAINER_MT_CHIMNEY_GRUNT_2, TRAINER_GRUNT_40
.set TRAINER_HIDEOUT_1F_GRUNT, TRAINER_GRUNT_28
.set TRAINER_HIDEOUT_B1F_GRUNT_1, TRAINER_GRUNT_29
.set TRAINER_HIDEOUT_B1F_GRUNT_2, TRAINER_GRUNT_30
.set TRAINER_HIDEOUT_B1F_GRUNT_3, TRAINER_GRUNT_53
.set TRAINER_HIDEOUT_B2F_GRUNT_1, TRAINER_TABITHA_1
.set TRAINER_HIDEOUT_B2F_GRUNT_2, TRAINER_GRUNT_31
.set TRAINER_HIDEOUT_B2F_GRUNT_3, TRAINER_GRUNT_54
.set TRAINER_SEAFLOOR_CAVERN_GRUNT_1, TRAINER_GRUNT_32
.set TRAINER_SEAFLOOR_CAVERN_GRUNT_2, TRAINER_GRUNT_33
.set TRAINER_SEAFLOOR_CAVERN_GRUNT_3, TRAINER_COURTNEY_2
.set TRAINER_SEAFLOOR_CAVERN_GRUNT_4, TRAINER_GRUNT_34
.set TRAINER_SEAFLOOR_CAVERN_GRUNT_5, TRAINER_MAXIE_2
.set TRAINER_MT_CHIMNEY_GRUNT_3, TRAINER_MAXIE_3
.set TRAINER_MT_PYRE_SUMMIT_GRUNT_1, TRAINER_GRUNT_49
.set TRAINER_MT_PYRE_SUMMIT_GRUNT_2, TRAINER_GRUNT_50
.set TRAINER_MT_PYRE_SUMMIT_GRUNT_3, TRAINER_GRUNT_51
.set TRAINER_WEATHER_INSTITUTE_GRUNT_1, TRAINER_GRUNT_43
.set TRAINER_WEATHER_INSTITUTE_GRUNT_2, TRAINER_GRUNT_52
.set TRAINER_WEATHER_INSTITUTE_GRUNT_3, TRAINER_GRUNT_44
.set TRAINER_WEATHER_INSTITUTE_GRUNT_4, TRAINER_GRUNT_45
.set TRAINER_WEATHER_INSTITUTE_GRUNT_5, TRAINER_COURTNEY_1
.endif

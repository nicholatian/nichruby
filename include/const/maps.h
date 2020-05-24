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

#ifndef INC__CONST_MAPS_H
#define INC__CONST_MAPS_H

enum /* map */
{
	MAP_PETALBRG,
	MAP_SLATPORT,
	MAP_MAUVILLE,
	MAP_RUSTBORO,
	MAP_FORTREE,
	MAP_LILYCOVE,
	MAP_SOOTOPLS,
	MAP_EVERGRAN,
	MAP_LITLROOT,
	MAP_OLDALE,
	MAP_DEWFORD,
	MAP_LAVARIDG,
	MAP_FALARBOR,
	MAP_VERDANTR,
	MAP_PACIFLOG,
	MAP_ROUTE101,
	MAP_ROUTE102,
	MAP_ROUTE103,
	MAP_ROUTE104,
	MAP_ROUTE105,
	MAP_ROUTE106,
	MAP_ROUTE107,
	MAP_ROUTE108,
	MAP_ROUTE109,
	MAP_ROUTE110,
	MAP_ROUTE111,
	MAP_ROUTE112,
	MAP_ROUTE113,
	MAP_ROUTE114,
	MAP_ROUTE115,
	MAP_ROUTE116,
	MAP_ROUTE117,
	MAP_ROUTE118,
	MAP_ROUTE119,
	MAP_ROUTE120,
	MAP_ROUTE121,
	MAP_ROUTE122,
	MAP_ROUTE123,
	MAP_ROUTE124,
	MAP_ROUTE125,
	MAP_ROUTE126,
	MAP_ROUTE127,
	MAP_ROUTE128,
	MAP_ROUTE129,
	MAP_ROUTE130,
	MAP_ROUTE131,
	MAP_ROUTE132,
	MAP_ROUTE133,
	MAP_ROUTE134,
	MAP_UNDWTR1,
	MAP_UNDWTR2,
	MAP_UNDWTR3,
	MAP_UNDWTR4,
	MAP_LR_MHS1F,
	MAP_LR_MHS2F,
	MAP_LR_FHS1F,
	MAP_LR_FHS2F,
	MAP_LR_LAB,
	MAP_OL_HOUS1,
	MAP_OL_HOUS2,
	MAP_OL_PC1F,
	MAP_OL_PC2F,
	MAP_OL_MART,
	MAP_DF_HOUS1,
	MAP_DF_PC1F,
	MAP_DF_PC2F,
	MAP_DF_GYM,
	MAP_DF_HALL,
	MAP_DF_HOUS2,
	MAP_LV_HERBS,
	MAP_LV_GYM1F,
	MAP_LV_GYM1B,
	MAP_LV_HOUS,
	MAP_LV_MART,
	MAP_LV_PC1F,
	MAP_LV_PC2F,
	MAP_FA_MART,
	MAP_FA_CONLB,
	MAP_FA_CONHL,
	MAP_FA_PC1F,
	MAP_FA_PC2F,
	MAP_FA_HOUS1,
	MAP_FA_HOUS2,
	MAP_VD_CONLB,
	MAP_VD_CONHL,
	MAP_VD_MART,
	MAP_VD_PC1F,
	MAP_VD_PC2F,
	MAP_VD_WANHS,
	MAP_VD_FSRHS,
	MAP_VD_HOUS,
	MAP_PL_PC1F,
	MAP_PL_PC2F,
	MAP_PL_HOUS1,
	MAP_PL_HOUS2,
	MAP_PL_HOUS3,
	MAP_PL_HOUS4,
	MAP_PL_HOUS5,
	MAP_PB_WLYHS,
	MAP_PB_GYM,
	MAP_PB_HOUS1,
	MAP_PB_HOUS2,
	MAP_PB_PC1F,
	MAP_PB_PC2F,
	MAP_PB_MART,
	MAP_SP_SHP1F,
	MAP_SP_SHP2F,
	MAP_SP_CONLB,
	MAP_SP_CONHL,
	MAP_SP_HOUS1,
	MAP_SP_FANCL,
	MAP_SP_OMU1F,
	MAP_SP_OMU2F,
	MAP_SP_HARBR,
	MAP_SP_HOUS2,
	MAP_SP_PC1F,
	MAP_SP_PC2F,
	MAP_SP_MART,
	MAP_MV_GYM,
	MAP_MV_BIKES,
	MAP_MV_HOUS1,
	MAP_MV_GAMEC,
	MAP_MV_HOUS2,
	MAP_MV_PC1F,
	MAP_MV_PC2F,
	MAP_MV_MART,
	MAP_RB_DEV1F,
	MAP_RB_DEV2F,
	MAP_RB_DEV3F,
	MAP_RB_GYM,
	MAP_RB_PKSCH,
	MAP_RB_PC1F,
	MAP_RB_PC2F,
	MAP_RB_MART,
	MAP_RB_FLAT1,
	MAP_RB_FLAT2,
	MAP_RB_HOUS1,
	MAP_RB_CUTTR,
	MAP_RB_HOUS2,
	MAP_RB_FLAT3,
	MAP_RB_FLAT4,
	MAP_RB_FLAT5,
	MAP_RB_HOUS3,
	MAP_FT_HOUS1,
	MAP_FT_GYM,
	MAP_FT_PC1F,
	MAP_FT_PC2F,
	MAP_FT_MART,
	MAP_FT_HOUS2,
	MAP_FT_HOUS3,
	MAP_FT_HOUS4,
	MAP_FT_HOUS5,
	MAP_FT_DSHOP,
	MAP_LC_COV1F,
	MAP_LC_COV2F,
	MAP_LC_AMU1F,
	MAP_LC_AMU2F,
	MAP_LC_CONLB,
	MAP_LC_CONHL,
	MAP_LC_PC1F,
	MAP_LC_PC2F,
	MAP_LC_MART,
	MAP_LC_PTFC,
	MAP_LC_HARBR,
	MAP_LC_EMPTY,
	MAP_LC_MVDEL,
	MAP_LC_HOUS1,
	MAP_LC_HOUS2,
	MAP_LC_HOUS3,
	MAP_LC_HOUS4,
	MAP_LC_DEP1F,
	MAP_LC_DEP2F,
	MAP_LC_DEP3F,
	MAP_LC_DEP4F,
	MAP_LC_DEP5F,
	MAP_LC_DEPRF,
	MAP_LC_DEPEL,
	MAP_MD_GYM,
	MAP_MD_HOUS1,
	MAP_MD_HOUS2,
	MAP_MD_PC1F,
	MAP_MD_PC2F,
	MAP_MD_MART,
	MAP_MD_HOUS3,
	MAP_MD_STEVN,
	MAP_MD_HOUS4,
	MAP_MD_SPC1F,
	MAP_MD_SPC2F,
	MAP_MD_GMC1F,
	MAP_MD_GMC1B,
	MAP_ST_GYM1F,
	MAP_ST_GYM1B,
	MAP_ST_PC1F,
	MAP_ST_PC2F,
	MAP_ST_MART,
	MAP_ST_HOUS1,
	MAP_ST_HOUS2,
	MAP_ST_HOUS3,
	MAP_ST_HOUS4,
	MAP_ST_HOUS5,
	MAP_ST_HOUS6,
	MAP_ST_HOUS7,
	MAP_ST_HOUS8,
	MAP_EG_SIDNY,
	MAP_EG_PHEEB,
	MAP_EG_GLACI,
	MAP_EG_DRAKE,
	MAP_EG_CHAMP,
	MAP_EG_CORR1,
	MAP_EG_CORR2,
	MAP_EG_CORR3,
	MAP_EG_CORR4,
	MAP_EG_CORR5,
	MAP_EG_LEAG,
	MAP_EG_HFAME,
	MAP_EG_PC1F,
	MAP_EG_PC2F,
	MAP_BRINYCOT,
	MAP_PPFLOWER,
	MAP_WINSTRAT,
	MAP_RESTSTOP,
	MAP_CBLCARLO,
	MAP_CBLCARHI,
	MAP_FOSLHOUS,
	MAP_FOSLTUNL,
	MAP_LANETTES,
	MAP_TUNNELRS,
	MAP_DAYCARE,
	MAP_SFRIGATE,
	MAP_METEOR1F,
	MAP_METEOR2F,
	MAP_METEOR1B,
	MAP_METEOR2B,
	MAP_RUSTURF,
	MAP_UNDRSOOT,
	MAP_DSRTRUIN,
	MAP_GRANCV1F,
	MAP_GRANCV1B,
	MAP_GRANCV2B,
	MAP_GRANCVSR,
	MAP_PBWOODS,
	MAX_MAP
};

#endif /* INC__CONST_MAPS_H */
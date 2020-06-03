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

/* DEFINITION MODULE */

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
	MAP_MTCHIM,
	MAP_JAGDPASS,
	MAP_FIERPATH,
	MAP_MTPYRE1F,
	MAP_MTPYRE2F,
	MAP_MTPYRE3F,
	MAP_MTPYRE4F,
	MAP_MTPYRE5F,
	MAP_MTPYRE6F,
	MAP_MTPYREXT,
	MAP_MTPYRESM,
	MAP_AQAHID1F,
	MAP_AQAHID1B,
	MAP_AQAHID2B,
	MAP_UNDWTRSF,
	MAP_SFC_ENTR,
	MAP_SFC_RM1,
	MAP_SFC_RM2,
	MAP_SFC_RM3,
	MAP_SFC_RM4,
	MAP_SFC_RM5,
	MAP_SFC_RM6,
	MAP_SFC_RM7,
	MAP_SFC_RM8,
	MAP_SFC_RM9,
	MAP_COO_ENTR,
	MAP_COO_1F,
	MAP_COO_1B,
	MAP_COO_2B,
	MAP_COO_3B,
	MAP_COO_4B,
	MAP_VICTRD1F,
	MAP_VICTRD1B,
	MAP_VICTRD2B,
	MAP_SHLLO_EN,
	MAP_SHLLO_IN,
	MAP_SHLLO_ST,
	MAP_SHLHI_EN,
	MAP_SHLHI_IN,
	MAP_NUMAU_EN,
	MAP_NUMAU_IN,
	MAP_CAC_DECK,
	MAP_CAC_C1F,
	MAP_CAC_R1F,
	MAP_CAC_C1B,
	MAP_CAC_R1B,
	MAP_CAC_2R1B,
	MAP_CAC_UNW1,
	MAP_CAC_RM1B,
	MAP_CAC_2R1F,
	MAP_CAC_CPOF,
	MAP_CAC_UNW2,
	MAP_CAC_HFCR,
	MAP_CAC_HFRM,
	MAP_ISLNCAVE,
	MAP_ANCIENTO,
	MAP_UNDWT134,
	MAP_UNDWT_SC,
	MAP_SC_OUTER,
	MAP_SC_INNER,
	MAP_SCORSLAB,
	MAP_MAGMAH1F,
	MAP_MAGMAH1B,
	MAP_MAGMAH2B,
	MAP_SKYENTR,
	MAP_SKYOUTS,
	MAP_SKYPIL1F,
	MAP_SKYPIL2F,
	MAP_SKYPIL3F,
	MAP_SKYPIL4F,
	MAP_SHLLO_IC,
	MAP_SKYPIL5F,
	MAP_SKYPLTOP,
	MAP_SB_RDCV1,
	MAP_SB_BRCV1,
	MAP_SB_BUCV1,
	MAP_SB_YLCV1,
	MAP_SB_TREE1,
	MAP_SB_SHRB1,
	MAP_SB_RDCV2,
	MAP_SB_BRCV2,
	MAP_SB_BUCV2,
	MAP_SB_YLCV2,
	MAP_SB_TREE2,
	MAP_SB_SHRB2,
	MAP_SB_RDCV3,
	MAP_SB_BRCV3,
	MAP_SB_BUCV3,
	MAP_SB_YLCV3,
	MAP_SB_TREE3,
	MAP_SB_SHRB3,
	MAP_SB_RDCV4,
	MAP_SB_BRCV4,
	MAP_SB_BUCV4,
	MAP_SB_YLCV4,
	MAP_SB_TREE4,
	MAP_SB_SHRB4,
	MAP_SBATLCOL,
	MAP_TRADECTR,
	MAP_RECORCTR,
	MAP_DBATLCOL,
	MAP_LNKCONR1,
	MAP_UNK25_29,
	MAP_UNK25_30,
	MAP_UNK25_31,
	MAP_UNK25_32,
	MAP_UNK25_33,
	MAP_UNK25_34,
	MAP_LNKCONR2,
	MAP_LNKCONR3,
	MAP_LNKCONR4,
	MAP_LNKCONR5,
	MAP_LNKCONR6,
	MAP_INSTRUCK,
	MAP_TIDAL_CR,
	MAP_TIDAL_LD,
	MAP_TIDAL_RM,
	MAP_SAFAR_NW,
	MAP_SAFAR_NE,
	MAP_SAFAR_SW,
	MAP_SAFAR_SE,
	MAP_BATOW_OU,
	MAP_BATOW_LB,
	MAP_BATOW_EL,
	MAP_BATOW_CR,
	MAP_BATOW_BR,
	MAP_SI_EXTER,
	MAP_SI_INTER,
	MAP_SAFAR_RH,
	MAP_ROUT104X,
	MAP_R104X_PP,
	MAP_R109_SSH,
	MAP_TRHS_ENT,
	MAP_TRHS_END,
	MAP_TRHS_COR,
	MAP_TRHS_PZ1,
	MAP_TRHS_PZ2,
	MAP_TRHS_PZ3,
	MAP_TRHS_PZ4,
	MAP_TRHS_PZ5,
	MAP_TRHS_PZ6,
	MAP_TRHS_PZ7,
	MAP_TRHS_PZ8,
	MAP_R110_CRS,
	MAP_R110_CRN,
	MAP_R113_GLS,
	MAP_R123_BER,
	MAP_R119_WI1,
	MAP_R119_WI2,
	MAP_R119_HOU,
	MAP_R124_THH,
	MAX_MAP
};

#endif /* INC__CONST_MAPS_H */

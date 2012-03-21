/*****************************************************************************
* Microchip Graphics Library
* Graphics Display Designer (GDD) Template
*****************************************************************************
* Dependencies:    See INCLUDES section below
* Processor:       PIC24F, PIC24H, dsPIC, PIC32
* Compiler:       	MPLAB C30 V3.22, MPLAB C32 V1.05b
* Linker:          MPLAB LINK30, MPLAB LINK32
* Company:         Microchip Technology Incorporated
*
* Software License Agreement
*
* Copyright (c) 2010 Microchip Technology Inc.  All rights reserved.
* Microchip licenses to you the right to use, modify, copy and distribute
* Software only when embedded on a Microchip microcontroller or digital
* signal controller, which is integrated into your product or third party
* product (pursuant to the sublicense terms in the accompanying license
* agreement).  
*
* You should refer to the license agreement accompanying this Software
* for additional information regarding your rights and obligations.
*
* SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
* KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
* OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
* PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
* OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
* BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
* DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
* INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
* COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
* CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
* OR OTHER SIMILAR COSTS.
*
* Author               Date        Comment
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
*****************************************************************************/
#ifndef	_GDD_SCREENS_H_
#define	 _GDD_SCREENS_H_
void GDDDemoCreateFirstScreen(void);
void GDDDemoGOLMsgCallback(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg);
void GDDDemoGOLDrawCallback(void);
void GDDDemoNextScreen(void);
extern const FONT_FLASH gentium_16_200_0_0_0_0;
void CreateBaseMain(void); //Main Screen to be created
void CreateScroll(void);//Creates Headers and background
void CreatePagerSelect(void); //Pager Call Screen is called
void CreatePager0(void);
void CreatePager1(void);
void CreatePager2(void);
void CreatePager3(void);
void CreatePager4(void);
void CreatePager5(void);
void CreatePager6(void);
void CreatePager7(void);
void CreatePager8(void);
void CreatePager9(void);
void CreatePager10(void);
void CreatePager11(void);
void CreatePager12(void);
void CreatePager13(void);
void CreatePager14(void);
void CreatePager15(void);
void CreatePager16(void);
void CreatePager17(void);
void CreatePager18(void);
void CreatePager19(void);
void CreatePager20(void);
void CreatePager21(void);
void CreatePager22(void);
void CreatePager23(void);
void CreatePager24(void);
void CreatePager25(void);
void CreatePager26(void);
void CreatePager27(void);
void CreatePager28(void);
void CreatePager29(void);
void CreatePager30(void);
void CreatePager31(void);
void CreatePager32(void);
void CreatePager33(void);
void CreatePager34(void);
void CreatePager35(void);
void CreatePager36(void);
void CreatePager37(void);
void CreatePager38(void);
void CreatePager39(void);
void CreatePager40(void);
void CreatePager41(void);
void CreatePager42(void);
void CreatePager43(void);
void CreatePager44(void);
void CreatePager45(void);
void CreatePager46(void);
void CreatePager47(void);
void CreatePager48(void);
void CreatePager49(void);
void CreatePager50(void);
void CreatePager51(void);
void CreatePager52(void);
void CreatePager53(void);
void CreatePager54(void);
void CreatePager55(void);
void CreatePager56(void);
void CreatePager57(void);
void CreatePager58(void);
void CreatePager59(void);
void CreatePager60(void);
void CreatePager61(void);
void CreatePager62(void);
void CreatePager63(void);
void CreatePager64(void);
void CreatePager65(void);
void CreatePager66(void);
void CreatePager67(void);
void CreatePager68(void);
void CreatePager69(void);
void CreatePager70(void);
void CreatePager71(void);
void CreatePager72(void);
void CreatePager73(void);
void CreatePager74(void);
void CreatePager75(void);
void CreatePager76(void);
void CreatePager77(void);
void CreatePager78(void);
void CreatePager79(void);
void CreatePager80(void);
void CreatePager81(void);
void CreatePager82(void);
void CreatePager83(void);
void CreatePager84(void);
void CreatePager85(void);
void CreatePager86(void);
void CreatePager87(void);
void CreatePager88(void);
void CreatePager89(void);
void CreatePager90(void);
void CreatePager91(void);
void CreatePager92(void);
void CreatePager93(void);
void CreatePager94(void);
void CreatePager95(void);
void CreatePager96(void);
void CreatePager97(void);
void CreatePager98(void);
void CreatePager99(void);



//Buttons on main Screen
#define BaseMain_Call   1
#define BaseMain_EditData   2
#define BaseMain_Clear 2000
#define BaseMain_Next 2001
#define BaseMain_Back 2002

//Header
#define BaseMain_OBJ_STATICTEXT_1_1   16
#define BaseMain_OBJ_STATICTEXT_2_1   17
#define BaseMain_OBJ_STATICTEXT_3_1   18
#define BaseMain_OBJ_STATICTEXT_4_1   19
#define BaseMain_OBJ_STATICTEXT_5_1   20
#define BaseMain_OBJ_STATICTEXT_6_1   21

//Pager 0
#define BaseMain_PAGERNUMBER_00   4
#define BaseMain_NUMBERGUEST_00   5
#define BaseMain_PAGERACTIVATED_00 6
#define BaseMain_PAGERCALLED_00   7
#define BaseMain_TABLENUMBER_00   8
#define BaseMain_ORDERFOOD_00   9
//Pager 1
#define BaseMain_PAGERNUMBER_01   10
#define BaseMain_NUMBERGUEST_01   11
#define BaseMain_PAGERACTIVATED_01  12
#define BaseMain_PAGERCALLED_01   13
#define BaseMain_TABLENUMBER_01   14
#define BaseMain_ORDERFOOD_01   15
//Pager 2
#define BaseMain_PAGERNUMBER_02   26
#define BaseMain_NUMBERGUEST_02   27
#define BaseMain_PAGERACTIVATED_02  28
#define BaseMain_PAGERCALLED_02   29
#define BaseMain_TABLENUMBER_02   30
#define BaseMain_ORDERFOOD_02   31
//Pager 3
#define BaseMain_PAGERNUMBER_03   32
#define BaseMain_NUMBERGUEST_03   33
#define BaseMain_PAGERACTIVATED_03  34
#define BaseMain_PAGERCALLED_03   35
#define BaseMain_TABLENUMBER_03   36
#define BaseMain_ORDERFOOD_03   37
//Pager 4
#define BaseMain_PAGERNUMBER_04   38
#define BaseMain_NUMBERGUEST_04   39
#define BaseMain_PAGERACTIVATED_04 40
#define BaseMain_PAGERCALLED_04   41
#define BaseMain_TABLENUMBER_04   42
#define BaseMain_ORDERFOOD_04   43
//Pager 5
#define BaseMain_PAGERNUMBER_05   44
#define BaseMain_NUMBERGUEST_05   45
#define BaseMain_PAGERACTIVATED_05  46
#define BaseMain_PAGERCALLED_05   47
#define BaseMain_TABLENUMBER_05   48
#define BaseMain_ORDERFOOD_05   49
//Pager 6
#define BaseMain_PAGERNUMBER_06   50
#define BaseMain_NUMBERGUEST_06   51
#define BaseMain_PAGERACTIVATED_06  52
#define BaseMain_PAGERCALLED_06   53
#define BaseMain_TABLENUMBER_06   54
#define BaseMain_ORDERFOOD_06   55
//Pager 7
#define BaseMain_PAGERNUMBER_07   56
#define BaseMain_NUMBERGUEST_07   57
#define BaseMain_PAGERACTIVATED_07  58
#define BaseMain_PAGERCALLED_07   59
#define BaseMain_TABLENUMBER_07   60
#define BaseMain_ORDERFOOD_07   61
//Pager 8
#define BaseMain_PAGERNUMBER_08   62
#define BaseMain_NUMBERGUEST_08   63
#define BaseMain_PAGERACTIVATED_08  64
#define BaseMain_PAGERCALLED_08   65
#define BaseMain_TABLENUMBER_08   66
#define BaseMain_ORDERFOOD_08   67
//Pager 9
#define BaseMain_PAGERNUMBER_09   68
#define BaseMain_NUMBERGUEST_09   69
#define BaseMain_PAGERACTIVATED_09  70
#define BaseMain_PAGERCALLED_09   71
#define BaseMain_TABLENUMBER_09   72
#define BaseMain_ORDERFOOD_09   73
//Pager 10
#define BaseMain_PAGERNUMBER_10   74
#define BaseMain_NUMBERGUEST_10   75
#define BaseMain_PAGERACTIVATED_10  76
#define BaseMain_PAGERCALLED_10   77
#define BaseMain_TABLENUMBER_10   78
#define BaseMain_ORDERFOOD_10  79
//Pager 11
#define BaseMain_PAGERNUMBER_11   80
#define BaseMain_NUMBERGUEST_11   81
#define BaseMain_PAGERACTIVATED_11  82
#define BaseMain_PAGERCALLED_11   83
#define BaseMain_TABLENUMBER_11   84
#define BaseMain_ORDERFOOD_11  85
//Pager 12
#define BaseMain_PAGERNUMBER_12   86
#define BaseMain_NUMBERGUEST_12   87
#define BaseMain_PAGERACTIVATED_12  88
#define BaseMain_PAGERCALLED_12   89
#define BaseMain_TABLENUMBER_12   90
#define BaseMain_ORDERFOOD_12  91
//Pager 13
#define BaseMain_PAGERNUMBER_13   92
#define BaseMain_NUMBERGUEST_13   93
#define BaseMain_PAGERACTIVATED_13  94
#define BaseMain_PAGERCALLED_13   95
#define BaseMain_TABLENUMBER_13   96
#define BaseMain_ORDERFOOD_13  97
//Pager 14
#define BaseMain_PAGERNUMBER_14   98
#define BaseMain_NUMBERGUEST_14   99
#define BaseMain_PAGERACTIVATED_14  100
#define BaseMain_PAGERCALLED_14   101
#define BaseMain_TABLENUMBER_14   102
#define BaseMain_ORDERFOOD_14  103
//Pager 15
#define BaseMain_PAGERNUMBER_15   104
#define BaseMain_NUMBERGUEST_15   105
#define BaseMain_PAGERACTIVATED_15  106
#define BaseMain_PAGERCALLED_15   107
#define BaseMain_TABLENUMBER_15   108
#define BaseMain_ORDERFOOD_15  109
//Pager 16
#define BaseMain_PAGERNUMBER_16   110
#define BaseMain_NUMBERGUEST_16   111
#define BaseMain_PAGERACTIVATED_16  112
#define BaseMain_PAGERCALLED_16   113
#define BaseMain_TABLENUMBER_16   114
#define BaseMain_ORDERFOOD_16  115
//Pager 17
#define BaseMain_PAGERNUMBER_17   116
#define BaseMain_NUMBERGUEST_17   117
#define BaseMain_PAGERACTIVATED_17  118
#define BaseMain_PAGERCALLED_17   119
#define BaseMain_TABLENUMBER_17   120
#define BaseMain_ORDERFOOD_17  121
//Pager 18
#define BaseMain_PAGERNUMBER_18   122
#define BaseMain_NUMBERGUEST_18   123
#define BaseMain_PAGERACTIVATED_18  124
#define BaseMain_PAGERCALLED_18   125
#define BaseMain_TABLENUMBER_18   126
#define BaseMain_ORDERFOOD_18  127
//Pager 19
#define BaseMain_PAGERNUMBER_19   128
#define BaseMain_NUMBERGUEST_19   129
#define BaseMain_PAGERACTIVATED_19  130
#define BaseMain_PAGERCALLED_19   131
#define BaseMain_TABLENUMBER_19   132
#define BaseMain_ORDERFOOD_19  133
//Pager 20
#define BaseMain_PAGERNUMBER_20   134
#define BaseMain_NUMBERGUEST_20   135
#define BaseMain_PAGERACTIVATED_20  136
#define BaseMain_PAGERCALLED_20   137
#define BaseMain_TABLENUMBER_20   138
#define BaseMain_ORDERFOOD_20  139
//Pager 21
#define BaseMain_PAGERNUMBER_21   140
#define BaseMain_NUMBERGUEST_21   141
#define BaseMain_PAGERACTIVATED_21  142
#define BaseMain_PAGERCALLED_21   143
#define BaseMain_TABLENUMBER_21   144
#define BaseMain_ORDERFOOD_21  145
//Pager 22
#define BaseMain_PAGERNUMBER_22   146
#define BaseMain_NUMBERGUEST_22   147
#define BaseMain_PAGERACTIVATED_22  148
#define BaseMain_PAGERCALLED_22   149
#define BaseMain_TABLENUMBER_22   150
#define BaseMain_ORDERFOOD_22  151
//Pager 23
#define BaseMain_PAGERNUMBER_23   152
#define BaseMain_NUMBERGUEST_23   153
#define BaseMain_PAGERACTIVATED_23  154
#define BaseMain_PAGERCALLED_23   155
#define BaseMain_TABLENUMBER_23   156
#define BaseMain_ORDERFOOD_23  157
//Pager 24
#define BaseMain_PAGERNUMBER_24   158
#define BaseMain_NUMBERGUEST_24   159
#define BaseMain_PAGERACTIVATED_24  160
#define BaseMain_PAGERCALLED_24   161
#define BaseMain_TABLENUMBER_24   162
#define BaseMain_ORDERFOOD_24  163
//Pager 25
#define BaseMain_PAGERNUMBER_25   164
#define BaseMain_NUMBERGUEST_25   165
#define BaseMain_PAGERACTIVATED_25  166
#define BaseMain_PAGERCALLED_25   167
#define BaseMain_TABLENUMBER_25   168
#define BaseMain_ORDERFOOD_25  169
//Pager 26
#define BaseMain_PAGERNUMBER_26   170
#define BaseMain_NUMBERGUEST_26   171
#define BaseMain_PAGERACTIVATED_26  172
#define BaseMain_PAGERCALLED_26   173
#define BaseMain_TABLENUMBER_26   174
#define BaseMain_ORDERFOOD_26  175
//Pager 27
#define BaseMain_PAGERNUMBER_27   176
#define BaseMain_NUMBERGUEST_27   177
#define BaseMain_PAGERACTIVATED_27  178
#define BaseMain_PAGERCALLED_27   179
#define BaseMain_TABLENUMBER_27   180
#define BaseMain_ORDERFOOD_27  181
//Pager 28
#define BaseMain_PAGERNUMBER_28   182
#define BaseMain_NUMBERGUEST_28   183
#define BaseMain_PAGERACTIVATED_28  184
#define BaseMain_PAGERCALLED_28   185
#define BaseMain_TABLENUMBER_28   186
#define BaseMain_ORDERFOOD_28  187
//Pager 29
#define BaseMain_PAGERNUMBER_29   188
#define BaseMain_NUMBERGUEST_29   189
#define BaseMain_PAGERACTIVATED_29  190
#define BaseMain_PAGERCALLED_29   191
#define BaseMain_TABLENUMBER_29   192
#define BaseMain_ORDERFOOD_29  193
//Pager 30
#define BaseMain_PAGERNUMBER_30   194
#define BaseMain_NUMBERGUEST_30   195
#define BaseMain_PAGERACTIVATED_30  196
#define BaseMain_PAGERCALLED_30   197
#define BaseMain_TABLENUMBER_30   198
#define BaseMain_ORDERFOOD_30  199
//Pager 31
#define BaseMain_PAGERNUMBER_31   200
#define BaseMain_NUMBERGUEST_31   201
#define BaseMain_PAGERACTIVATED_31  202
#define BaseMain_PAGERCALLED_31   203
#define BaseMain_TABLENUMBER_31   204
#define BaseMain_ORDERFOOD_31  205
//Pager 32
#define BaseMain_PAGERNUMBER_32   206
#define BaseMain_NUMBERGUEST_32   207
#define BaseMain_PAGERACTIVATED_32  208
#define BaseMain_PAGERCALLED_32   209
#define BaseMain_TABLENUMBER_32   210
#define BaseMain_ORDERFOOD_32  211
//Pager 33
#define BaseMain_PAGERNUMBER_33   212
#define BaseMain_NUMBERGUEST_33   213
#define BaseMain_PAGERACTIVATED_33  214
#define BaseMain_PAGERCALLED_33   215
#define BaseMain_TABLENUMBER_33   216
#define BaseMain_ORDERFOOD_33  217
//Pager 34
#define BaseMain_PAGERNUMBER_34   218
#define BaseMain_NUMBERGUEST_34   219
#define BaseMain_PAGERACTIVATED_34  220
#define BaseMain_PAGERCALLED_34   221
#define BaseMain_TABLENUMBER_34   222
#define BaseMain_ORDERFOOD_34  223
//Pager 35
#define BaseMain_PAGERNUMBER_35   224
#define BaseMain_NUMBERGUEST_35   225
#define BaseMain_PAGERACTIVATED_35  226
#define BaseMain_PAGERCALLED_35   227
#define BaseMain_TABLENUMBER_35   228
#define BaseMain_ORDERFOOD_35  229
//Pager 36
#define BaseMain_PAGERNUMBER_36	230
#define BaseMain_NUMBERGUEST_36	231
#define BaseMain_PAGERACTIVATED_36	232
#define BaseMain_PAGERCALLED_36	233
#define BaseMain_TABLENUMBER_36	234
#define BaseMain_ORDERFOOD_36	235
//Pager 37
#define BaseMain_PAGERNUMBER_37	236
#define BaseMain_NUMBERGUEST_37	237
#define BaseMain_PAGERACTIVATED_37	238
#define BaseMain_PAGERCALLED_37	239
#define BaseMain_TABLENUMBER_37	240
#define BaseMain_ORDERFOOD_37	241
//Pager 38
#define BaseMain_PAGERNUMBER_38	242
#define BaseMain_NUMBERGUEST_38	243
#define BaseMain_PAGERACTIVATED_38	244
#define BaseMain_PAGERCALLED_38	245
#define BaseMain_TABLENUMBER_38	246
#define BaseMain_ORDERFOOD_38	247
//Pager 39
#define BaseMain_PAGERNUMBER_39	248
#define BaseMain_NUMBERGUEST_39	249
#define BaseMain_PAGERACTIVATED_39	250
#define BaseMain_PAGERCALLED_39	251
#define BaseMain_TABLENUMBER_39	252
#define BaseMain_ORDERFOOD_39	253
//Pager 40
#define BaseMain_PAGERNUMBER_40	254
#define BaseMain_NUMBERGUEST_40	255
#define BaseMain_PAGERACTIVATED_40	256
#define BaseMain_PAGERCALLED_40	257
#define BaseMain_TABLENUMBER_40	258
#define BaseMain_ORDERFOOD_40	259
//Pager 41
#define BaseMain_PAGERNUMBER_41	260
#define BaseMain_NUMBERGUEST_41	261
#define BaseMain_PAGERACTIVATED_41	262
#define BaseMain_PAGERCALLED_41	263
#define BaseMain_TABLENUMBER_41	264
#define BaseMain_ORDERFOOD_41	265
//Pager 42
#define BaseMain_PAGERNUMBER_42	266
#define BaseMain_NUMBERGUEST_42	267
#define BaseMain_PAGERACTIVATED_42	268
#define BaseMain_PAGERCALLED_42	269
#define BaseMain_TABLENUMBER_42	270
#define BaseMain_ORDERFOOD_42	271
//Pager 43
#define BaseMain_PAGERNUMBER_43	272
#define BaseMain_NUMBERGUEST_43	273
#define BaseMain_PAGERACTIVATED_43	274
#define BaseMain_PAGERCALLED_43	275
#define BaseMain_TABLENUMBER_43	276
#define BaseMain_ORDERFOOD_43	277
//Pager 44
#define BaseMain_PAGERNUMBER_44	278
#define BaseMain_NUMBERGUEST_44	279
#define BaseMain_PAGERACTIVATED_44	280
#define BaseMain_PAGERCALLED_44	281
#define BaseMain_TABLENUMBER_44	282
#define BaseMain_ORDERFOOD_44	283
//Pager 45
#define BaseMain_PAGERNUMBER_45	284
#define BaseMain_NUMBERGUEST_45	285
#define BaseMain_PAGERACTIVATED_45	286
#define BaseMain_PAGERCALLED_45	287
#define BaseMain_TABLENUMBER_45	288
#define BaseMain_ORDERFOOD_45	289
//Pager 46
#define BaseMain_PAGERNUMBER_46	290
#define BaseMain_NUMBERGUEST_46	291
#define BaseMain_PAGERACTIVATED_46	292
#define BaseMain_PAGERCALLED_46	293
#define BaseMain_TABLENUMBER_46	294
#define BaseMain_ORDERFOOD_46	295
//Pager 47
#define BaseMain_PAGERNUMBER_47	296
#define BaseMain_NUMBERGUEST_47	297
#define BaseMain_PAGERACTIVATED_47	298
#define BaseMain_PAGERCALLED_47	299
#define BaseMain_TABLENUMBER_47	300
#define BaseMain_ORDERFOOD_47	301
//Pager 48
#define BaseMain_PAGERNUMBER_48	302
#define BaseMain_NUMBERGUEST_48	303
#define BaseMain_PAGERACTIVATED_48	304
#define BaseMain_PAGERCALLED_48	305
#define BaseMain_TABLENUMBER_48	306
#define BaseMain_ORDERFOOD_48	307
//Pager 49
#define BaseMain_PAGERNUMBER_49	308
#define BaseMain_NUMBERGUEST_49	309
#define BaseMain_PAGERACTIVATED_49	310
#define BaseMain_PAGERCALLED_49	311
#define BaseMain_TABLENUMBER_49	312
#define BaseMain_ORDERFOOD_49	313
//Pager 50
#define BaseMain_PAGERNUMBER_50	314
#define BaseMain_NUMBERGUEST_50	315
#define BaseMain_PAGERACTIVATED_50	316
#define BaseMain_PAGERCALLED_50	317
#define BaseMain_TABLENUMBER_50	318
#define BaseMain_ORDERFOOD_50	319
//Pager 51
#define BaseMain_PAGERNUMBER_51	320
#define BaseMain_NUMBERGUEST_51	321
#define BaseMain_PAGERACTIVATED_51	322
#define BaseMain_PAGERCALLED_51	323
#define BaseMain_TABLENUMBER_51	324
#define BaseMain_ORDERFOOD_51	325
//Pager 52
#define BaseMain_PAGERNUMBER_52	326
#define BaseMain_NUMBERGUEST_52	327
#define BaseMain_PAGERACTIVATED_52	328
#define BaseMain_PAGERCALLED_52	329
#define BaseMain_TABLENUMBER_52	330
#define BaseMain_ORDERFOOD_52	331
//Pager 53
#define BaseMain_PAGERNUMBER_53	332
#define BaseMain_NUMBERGUEST_53	333
#define BaseMain_PAGERACTIVATED_53	334
#define BaseMain_PAGERCALLED_53	335
#define BaseMain_TABLENUMBER_53	336
#define BaseMain_ORDERFOOD_53	337
//Pager 54
#define BaseMain_PAGERNUMBER_54	338
#define BaseMain_NUMBERGUEST_54	339
#define BaseMain_PAGERACTIVATED_54	340
#define BaseMain_PAGERCALLED_54	341
#define BaseMain_TABLENUMBER_54	342
#define BaseMain_ORDERFOOD_54	343
//Pager 55
#define BaseMain_PAGERNUMBER_55	344
#define BaseMain_NUMBERGUEST_55	345
#define BaseMain_PAGERACTIVATED_55	346
#define BaseMain_PAGERCALLED_55	347
#define BaseMain_TABLENUMBER_55	348
#define BaseMain_ORDERFOOD_55	349
//Pager 56
#define BaseMain_PAGERNUMBER_56	350
#define BaseMain_NUMBERGUEST_56	351
#define BaseMain_PAGERACTIVATED_56	352
#define BaseMain_PAGERCALLED_56	353
#define BaseMain_TABLENUMBER_56	354
#define BaseMain_ORDERFOOD_56	355
//Pager 57
#define BaseMain_PAGERNUMBER_57	356
#define BaseMain_NUMBERGUEST_57	357
#define BaseMain_PAGERACTIVATED_57	358
#define BaseMain_PAGERCALLED_57	359
#define BaseMain_TABLENUMBER_57	360
#define BaseMain_ORDERFOOD_57	361
//Pager 58
#define BaseMain_PAGERNUMBER_58	362
#define BaseMain_NUMBERGUEST_58	363
#define BaseMain_PAGERACTIVATED_58	364
#define BaseMain_PAGERCALLED_58	365
#define BaseMain_TABLENUMBER_58	366
#define BaseMain_ORDERFOOD_58	367
//Pager 59
#define BaseMain_PAGERNUMBER_59	368
#define BaseMain_NUMBERGUEST_59	369
#define BaseMain_PAGERACTIVATED_59	370
#define BaseMain_PAGERCALLED_59	371
#define BaseMain_TABLENUMBER_59	372
#define BaseMain_ORDERFOOD_59	373
//Pager 60
#define BaseMain_PAGERNUMBER_60	374
#define BaseMain_NUMBERGUEST_60	375
#define BaseMain_PAGERACTIVATED_60	376
#define BaseMain_PAGERCALLED_60	377
#define BaseMain_TABLENUMBER_60	378
#define BaseMain_ORDERFOOD_60	379
//Pager 61
#define BaseMain_PAGERNUMBER_61	380
#define BaseMain_NUMBERGUEST_61	381
#define BaseMain_PAGERACTIVATED_61	382
#define BaseMain_PAGERCALLED_61	383
#define BaseMain_TABLENUMBER_61	384
#define BaseMain_ORDERFOOD_61	385
//Pager 62
#define BaseMain_PAGERNUMBER_62	386
#define BaseMain_NUMBERGUEST_62	387
#define BaseMain_PAGERACTIVATED_62	388
#define BaseMain_PAGERCALLED_62	389
#define BaseMain_TABLENUMBER_62	390
#define BaseMain_ORDERFOOD_62	391
//Pager 63
#define BaseMain_PAGERNUMBER_63	392
#define BaseMain_NUMBERGUEST_63	393
#define BaseMain_PAGERACTIVATED_63	394
#define BaseMain_PAGERCALLED_63	395
#define BaseMain_TABLENUMBER_63	396
#define BaseMain_ORDERFOOD_63	397
//Pager 64
#define BaseMain_PAGERNUMBER_64	398
#define BaseMain_NUMBERGUEST_64	399
#define BaseMain_PAGERACTIVATED_64	400
#define BaseMain_PAGERCALLED_64	401
#define BaseMain_TABLENUMBER_64	402
#define BaseMain_ORDERFOOD_64	403
//Pager 65
#define BaseMain_PAGERNUMBER_65	404
#define BaseMain_NUMBERGUEST_65	405
#define BaseMain_PAGERACTIVATED_65	406
#define BaseMain_PAGERCALLED_65	407
#define BaseMain_TABLENUMBER_65	408
#define BaseMain_ORDERFOOD_65	409
//Pager 66
#define BaseMain_PAGERNUMBER_66	410
#define BaseMain_NUMBERGUEST_66	411
#define BaseMain_PAGERACTIVATED_66	412
#define BaseMain_PAGERCALLED_66	413
#define BaseMain_TABLENUMBER_66	414
#define BaseMain_ORDERFOOD_66	415
//Pager 67
#define BaseMain_PAGERNUMBER_67	416
#define BaseMain_NUMBERGUEST_67	417
#define BaseMain_PAGERACTIVATED_67	418
#define BaseMain_PAGERCALLED_67	419
#define BaseMain_TABLENUMBER_67	420
#define BaseMain_ORDERFOOD_67	421
//Pager 68
#define BaseMain_PAGERNUMBER_68	422
#define BaseMain_NUMBERGUEST_68	423
#define BaseMain_PAGERACTIVATED_68	424
#define BaseMain_PAGERCALLED_68	425
#define BaseMain_TABLENUMBER_68	426
#define BaseMain_ORDERFOOD_68	427
//Pager 69
#define BaseMain_PAGERNUMBER_69	428
#define BaseMain_NUMBERGUEST_69	429
#define BaseMain_PAGERACTIVATED_69	430
#define BaseMain_PAGERCALLED_69	431
#define BaseMain_TABLENUMBER_69	432
#define BaseMain_ORDERFOOD_69	433
//Pager 70
#define BaseMain_PAGERNUMBER_70	434
#define BaseMain_NUMBERGUEST_70	435
#define BaseMain_PAGERACTIVATED_70	436
#define BaseMain_PAGERCALLED_70	437
#define BaseMain_TABLENUMBER_70	438
#define BaseMain_ORDERFOOD_70	439
//Pager 71
#define BaseMain_PAGERNUMBER_71	440
#define BaseMain_NUMBERGUEST_71	441
#define BaseMain_PAGERACTIVATED_71	442
#define BaseMain_PAGERCALLED_71	443
#define BaseMain_TABLENUMBER_71	444
#define BaseMain_ORDERFOOD_71	445
//Pager 72
#define BaseMain_PAGERNUMBER_72	446
#define BaseMain_NUMBERGUEST_72	447
#define BaseMain_PAGERACTIVATED_72	448
#define BaseMain_PAGERCALLED_72	449
#define BaseMain_TABLENUMBER_72	450
#define BaseMain_ORDERFOOD_72	451
//Pager 73
#define BaseMain_PAGERNUMBER_73	452
#define BaseMain_NUMBERGUEST_73	453
#define BaseMain_PAGERACTIVATED_73	454
#define BaseMain_PAGERCALLED_73	455
#define BaseMain_TABLENUMBER_73	456
#define BaseMain_ORDERFOOD_73	457
//Pager 74
#define BaseMain_PAGERNUMBER_74	458
#define BaseMain_NUMBERGUEST_74	459
#define BaseMain_PAGERACTIVATED_74	460
#define BaseMain_PAGERCALLED_74	461
#define BaseMain_TABLENUMBER_74	462
#define BaseMain_ORDERFOOD_74	463
//Pager 75
#define BaseMain_PAGERNUMBER_75	464
#define BaseMain_NUMBERGUEST_75	465
#define BaseMain_PAGERACTIVATED_75	466
#define BaseMain_PAGERCALLED_75	467
#define BaseMain_TABLENUMBER_75	468
#define BaseMain_ORDERFOOD_75	469
//Pager 76
#define BaseMain_PAGERNUMBER_76	470
#define BaseMain_NUMBERGUEST_76	471
#define BaseMain_PAGERACTIVATED_76	472
#define BaseMain_PAGERCALLED_76	473
#define BaseMain_TABLENUMBER_76	474
#define BaseMain_ORDERFOOD_76	475
//Pager 77
#define BaseMain_PAGERNUMBER_77	476
#define BaseMain_NUMBERGUEST_77	477
#define BaseMain_PAGERACTIVATED_77	478
#define BaseMain_PAGERCALLED_77	479
#define BaseMain_TABLENUMBER_77	480
#define BaseMain_ORDERFOOD_77	481
//Pager 78
#define BaseMain_PAGERNUMBER_78	482
#define BaseMain_NUMBERGUEST_78	483
#define BaseMain_PAGERACTIVATED_78	484
#define BaseMain_PAGERCALLED_78	485
#define BaseMain_TABLENUMBER_78	486
#define BaseMain_ORDERFOOD_78	487
//Pager 79
#define BaseMain_PAGERNUMBER_79	488
#define BaseMain_NUMBERGUEST_79	489
#define BaseMain_PAGERACTIVATED_79	490
#define BaseMain_PAGERCALLED_79	491
#define BaseMain_TABLENUMBER_79	492
#define BaseMain_ORDERFOOD_79	493
//Pager 80
#define BaseMain_PAGERNUMBER_80	494
#define BaseMain_NUMBERGUEST_80	495
#define BaseMain_PAGERACTIVATED_80	496
#define BaseMain_PAGERCALLED_80	497
#define BaseMain_TABLENUMBER_80	498
#define BaseMain_ORDERFOOD_80	499
//Pager 81
#define BaseMain_PAGERNUMBER_81	500
#define BaseMain_NUMBERGUEST_81	501
#define BaseMain_PAGERACTIVATED_81	502
#define BaseMain_PAGERCALLED_81	503
#define BaseMain_TABLENUMBER_81	504
#define BaseMain_ORDERFOOD_81	505
//Pager 82
#define BaseMain_PAGERNUMBER_82	506
#define BaseMain_NUMBERGUEST_82	507
#define BaseMain_PAGERACTIVATED_82	508
#define BaseMain_PAGERCALLED_82	509
#define BaseMain_TABLENUMBER_82	510
#define BaseMain_ORDERFOOD_82	511
//Pager 83
#define BaseMain_PAGERNUMBER_83	512
#define BaseMain_NUMBERGUEST_83	513
#define BaseMain_PAGERACTIVATED_83	514
#define BaseMain_PAGERCALLED_83	515
#define BaseMain_TABLENUMBER_83	516
#define BaseMain_ORDERFOOD_83	517
//Pager 84
#define BaseMain_PAGERNUMBER_84	518
#define BaseMain_NUMBERGUEST_84	519
#define BaseMain_PAGERACTIVATED_84	520
#define BaseMain_PAGERCALLED_84	521
#define BaseMain_TABLENUMBER_84	522
#define BaseMain_ORDERFOOD_84	523
//Pager 85
#define BaseMain_PAGERNUMBER_85	524
#define BaseMain_NUMBERGUEST_85	525
#define BaseMain_PAGERACTIVATED_85	526
#define BaseMain_PAGERCALLED_85	527
#define BaseMain_TABLENUMBER_85	528
#define BaseMain_ORDERFOOD_85	529
//Pager 86
#define BaseMain_PAGERNUMBER_86	530
#define BaseMain_NUMBERGUEST_86	531
#define BaseMain_PAGERACTIVATED_86	532
#define BaseMain_PAGERCALLED_86	533
#define BaseMain_TABLENUMBER_86	534
#define BaseMain_ORDERFOOD_86	535
//Pager 87
#define BaseMain_PAGERNUMBER_87	536
#define BaseMain_NUMBERGUEST_87	537
#define BaseMain_PAGERACTIVATED_87	538
#define BaseMain_PAGERCALLED_87	539
#define BaseMain_TABLENUMBER_87	540
#define BaseMain_ORDERFOOD_87	541
//Pager 88
#define BaseMain_PAGERNUMBER_88	542
#define BaseMain_NUMBERGUEST_88	543
#define BaseMain_PAGERACTIVATED_88	544
#define BaseMain_PAGERCALLED_88	545
#define BaseMain_TABLENUMBER_88	546
#define BaseMain_ORDERFOOD_88	547
//Pager 89
#define BaseMain_PAGERNUMBER_89	548
#define BaseMain_NUMBERGUEST_89	549
#define BaseMain_PAGERACTIVATED_89	550
#define BaseMain_PAGERCALLED_89	551
#define BaseMain_TABLENUMBER_89	552
#define BaseMain_ORDERFOOD_89	553
//Pager 90
#define BaseMain_PAGERNUMBER_90	554
#define BaseMain_NUMBERGUEST_90	555
#define BaseMain_PAGERACTIVATED_90	556
#define BaseMain_PAGERCALLED_90	557
#define BaseMain_TABLENUMBER_90	558
#define BaseMain_ORDERFOOD_90	559
//Pager 91
#define BaseMain_PAGERNUMBER_91	560
#define BaseMain_NUMBERGUEST_91	561
#define BaseMain_PAGERACTIVATED_91	562
#define BaseMain_PAGERCALLED_91	563
#define BaseMain_TABLENUMBER_91	564
#define BaseMain_ORDERFOOD_91	565
//Pager 92
#define BaseMain_PAGERNUMBER_92	566
#define BaseMain_NUMBERGUEST_92	567
#define BaseMain_PAGERACTIVATED_92	568
#define BaseMain_PAGERCALLED_92	569
#define BaseMain_TABLENUMBER_92	570
#define BaseMain_ORDERFOOD_92	571
//Pager 93
#define BaseMain_PAGERNUMBER_93	572
#define BaseMain_NUMBERGUEST_93	573
#define BaseMain_PAGERACTIVATED_93	574
#define BaseMain_PAGERCALLED_93	575
#define BaseMain_TABLENUMBER_93	576
#define BaseMain_ORDERFOOD_93	577
//Pager 94
#define BaseMain_PAGERNUMBER_94	578
#define BaseMain_NUMBERGUEST_94	579
#define BaseMain_PAGERACTIVATED_94	580
#define BaseMain_PAGERCALLED_94	581
#define BaseMain_TABLENUMBER_94	582
#define BaseMain_ORDERFOOD_94	583
//Pager 95
#define BaseMain_PAGERNUMBER_95	584
#define BaseMain_NUMBERGUEST_95	585
#define BaseMain_PAGERACTIVATED_95	586
#define BaseMain_PAGERCALLED_95	587
#define BaseMain_TABLENUMBER_95	588
#define BaseMain_ORDERFOOD_95	589
//Pager 96
#define BaseMain_PAGERNUMBER_96	590
#define BaseMain_NUMBERGUEST_96	591
#define BaseMain_PAGERACTIVATED_96	592
#define BaseMain_PAGERCALLED_96	593
#define BaseMain_TABLENUMBER_96	594
#define BaseMain_ORDERFOOD_96	595
//Pager 97
#define BaseMain_PAGERNUMBER_97	596
#define BaseMain_NUMBERGUEST_97	597
#define BaseMain_PAGERACTIVATED_97	598
#define BaseMain_PAGERCALLED_97	599
#define BaseMain_TABLENUMBER_97	600
#define BaseMain_ORDERFOOD_97	601
//Pager 98
#define BaseMain_PAGERNUMBER_98	602
#define BaseMain_NUMBERGUEST_98	603
#define BaseMain_PAGERACTIVATED_98	604
#define BaseMain_PAGERCALLED_98	605
#define BaseMain_TABLENUMBER_98	606
#define BaseMain_ORDERFOOD_98	607
//Pager 99
#define BaseMain_PAGERNUMBER_99	608
#define BaseMain_NUMBERGUEST_99	609
#define BaseMain_PAGERACTIVATED_99	610
#define BaseMain_PAGERCALLED_99	611
#define BaseMain_TABLENUMBER_99	612
#define BaseMain_ORDERFOOD_99	613


//Pager Call Screen
#define PagerSelect_Main   22
#define PagerSelect_OBJ_EDITBOX_7_4   23
#define PagerSelect_OBJ_STATICTEXT_7_4   24
#define PagerSelect_OBJ_WINDOW_4   25

//Other
#define	NUM_GDD_SCREENS	2
#endif

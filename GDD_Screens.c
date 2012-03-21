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

* Author               Date        Comment
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
*****************************************************************************/
#include "Graphics\Graphics.h"
#include "GDD_Screens.h"

//Dimentions for drawing boxes
#define Left 0
#define Top 50
#define Right 70
#define Bottom 85
#define MAXCHARSIZE 16384
#define HorizontalShift 70
#define VerticleShift 35

// Buttons
const XCHAR BaseMain_Calltext[] = "Call";
const XCHAR BaseMain_EditDatatext[] = "Edit Data";
const XCHAR BaseMain_Cleartext[] = "Clear";
const XCHAR BaseMain_Nexttext[]="vv";
const XCHAR BaseMain_Backtext[]="^^";

//Pager 0
const XCHAR BaseMain_PAGERNUMBER_00text[] = "00";
XCHAR BaseMain_NUMBERGUEST_00text[]="5";
XCHAR BaseMain_PAGERACTIVATED_00text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_00text[] = "";
XCHAR BaseMain_TABLENUMBER_00text[] = "";
XCHAR BaseMain_ORDERFOOD_00text[] = "";
//Pager 1
const XCHAR BaseMain_PAGERNUMBER_01text[] = "01";
XCHAR BaseMain_NUMBERGUEST_01text[] = "2";
XCHAR BaseMain_PAGERACTIVATED_01text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_01text[] = "";
XCHAR BaseMain_TABLENUMBER_01text[] = "";
XCHAR BaseMain_ORDERFOOD_01text[] = "";
//Pager 2
const XCHAR BaseMain_PAGERNUMBER_02text[] = "02";
XCHAR BaseMain_NUMBERGUEST_02text[] = "3";
XCHAR BaseMain_PAGERACTIVATED_02text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_02text[] = "";
XCHAR BaseMain_TABLENUMBER_02text[] = "";
XCHAR BaseMain_ORDERFOOD_02text[] = "";
//Pager 3
const XCHAR BaseMain_PAGERNUMBER_03text[] = "03";
XCHAR BaseMain_NUMBERGUEST_03text[] = "6";
XCHAR BaseMain_PAGERACTIVATED_03text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_03text[] = "";
XCHAR BaseMain_TABLENUMBER_03text[] = "";
XCHAR BaseMain_ORDERFOOD_03text[] = "";
//Pager 4
const XCHAR BaseMain_PAGERNUMBER_04text[] = "04";
XCHAR BaseMain_NUMBERGUEST_04text[] = "10";
XCHAR BaseMain_PAGERACTIVATED_04text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_04text[] = "";
XCHAR BaseMain_TABLENUMBER_04text[] = "";
XCHAR BaseMain_ORDERFOOD_04text[] = "";
//Pager 5
const XCHAR BaseMain_PAGERNUMBER_05text[] = "05";
XCHAR BaseMain_NUMBERGUEST_05text[] = "99";
XCHAR BaseMain_PAGERACTIVATED_05text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_05text[] = "";
XCHAR BaseMain_TABLENUMBER_05text[] = "";
XCHAR BaseMain_ORDERFOOD_05text[] = "";
//Pager 6
const XCHAR BaseMain_PAGERNUMBER_06text[] = "06";
XCHAR BaseMain_NUMBERGUEST_06text[] = "";
XCHAR BaseMain_PAGERACTIVATED_06text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_06text[] = "";
XCHAR BaseMain_TABLENUMBER_06text[] = "";
XCHAR BaseMain_ORDERFOOD_06text[] = "";
//Pager 7
const XCHAR BaseMain_PAGERNUMBER_07text[] = "07";
XCHAR BaseMain_NUMBERGUEST_07text[] = "";
XCHAR BaseMain_PAGERACTIVATED_07text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_07text[] = "";
XCHAR BaseMain_TABLENUMBER_07text[] = "";
XCHAR BaseMain_ORDERFOOD_07text[] = "";
//Pager 8
const XCHAR BaseMain_PAGERNUMBER_08text[] = "08";
XCHAR BaseMain_NUMBERGUEST_08text[] = "";
XCHAR BaseMain_PAGERACTIVATED_08text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_08text[] = "";
XCHAR BaseMain_TABLENUMBER_08text[] = "";
XCHAR BaseMain_ORDERFOOD_08text[] = "";
//Pager 9
const XCHAR BaseMain_PAGERNUMBER_09text[] = "09";
XCHAR BaseMain_NUMBERGUEST_09text[] = "";
XCHAR BaseMain_PAGERACTIVATED_09text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_09text[] = "";
XCHAR BaseMain_TABLENUMBER_09text[] = "";
XCHAR BaseMain_ORDERFOOD_09text[] = "";
//Pager 10
const XCHAR BaseMain_PAGERNUMBER_10text[] = "10";
XCHAR BaseMain_NUMBERGUEST_10text[] = "";
XCHAR BaseMain_PAGERACTIVATED_10text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_10text[] = "";
XCHAR BaseMain_TABLENUMBER_10text[] = "";
XCHAR BaseMain_ORDERFOOD_10text[] = "";
//Pager 11
const XCHAR BaseMain_PAGERNUMBER_11text[] = "11";
XCHAR BaseMain_NUMBERGUEST_11text[] = "";
XCHAR BaseMain_PAGERACTIVATED_11text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_11text[] = "";
XCHAR BaseMain_TABLENUMBER_11text[] = "";
XCHAR BaseMain_ORDERFOOD_11text[] = "";
//Pager 12
const XCHAR BaseMain_PAGERNUMBER_12text[] = "12";
XCHAR BaseMain_NUMBERGUEST_12text[] = "";
XCHAR BaseMain_PAGERACTIVATED_12text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_12text[] = "";
XCHAR BaseMain_TABLENUMBER_12text[] = "";
XCHAR BaseMain_ORDERFOOD_12text[] = "";
//Pager 13
const XCHAR BaseMain_PAGERNUMBER_13text[] = "13";
XCHAR BaseMain_NUMBERGUEST_13text[] = "";
XCHAR BaseMain_PAGERACTIVATED_13text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_13text[] = "";
XCHAR BaseMain_TABLENUMBER_13text[] = "";
XCHAR BaseMain_ORDERFOOD_13text[] = "";
//Pager 14
const XCHAR BaseMain_PAGERNUMBER_14text[] = "14";
XCHAR BaseMain_NUMBERGUEST_14text[] = "";
XCHAR BaseMain_PAGERACTIVATED_14text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_14text[] = "";
XCHAR BaseMain_TABLENUMBER_14text[] = "";
XCHAR BaseMain_ORDERFOOD_14text[] = "";
//Pager 15
const XCHAR BaseMain_PAGERNUMBER_15text[] = "15";
XCHAR BaseMain_NUMBERGUEST_15text[] = "";
XCHAR BaseMain_PAGERACTIVATED_15text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_15text[] = "";
XCHAR BaseMain_TABLENUMBER_15text[] = "";
XCHAR BaseMain_ORDERFOOD_15text[] = "";
//Pager 16
const XCHAR BaseMain_PAGERNUMBER_16text[] = "16";
XCHAR BaseMain_NUMBERGUEST_16text[] = "";
XCHAR BaseMain_PAGERACTIVATED_16text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_16text[] = "";
XCHAR BaseMain_TABLENUMBER_16text[] = "";
XCHAR BaseMain_ORDERFOOD_16text[] = "";
//Pager 17
const XCHAR BaseMain_PAGERNUMBER_17text[] = "17";
XCHAR BaseMain_NUMBERGUEST_17text[] = "";
XCHAR BaseMain_PAGERACTIVATED_17text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_17text[] = "";
XCHAR BaseMain_TABLENUMBER_17text[] = "";
XCHAR BaseMain_ORDERFOOD_17text[] = "";
//Pager 18
const XCHAR BaseMain_PAGERNUMBER_18text[] = "18";
XCHAR BaseMain_NUMBERGUEST_18text[] = "";
XCHAR BaseMain_PAGERACTIVATED_18text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_18text[] = "";
XCHAR BaseMain_TABLENUMBER_18text[] = "";
XCHAR BaseMain_ORDERFOOD_18text[] = "";
//Pager 19
const XCHAR BaseMain_PAGERNUMBER_19text[] = "19";
XCHAR BaseMain_NUMBERGUEST_19text[] = "";
XCHAR BaseMain_PAGERACTIVATED_19text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_19text[] = "";
XCHAR BaseMain_TABLENUMBER_19text[] = "";
XCHAR BaseMain_ORDERFOOD_19text[] = "";
//Pager 20	
const XCHAR BaseMain_PAGERNUMBER_20text[] = "20";
XCHAR BaseMain_NUMBERGUEST_20text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_20text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_20text[] = "";
XCHAR BaseMain_TABLENUMBER_20text[] = "";
XCHAR BaseMain_ORDERFOOD_20text[] = "";
//Pager 21	
const XCHAR BaseMain_PAGERNUMBER_21text[] = "21";
XCHAR BaseMain_NUMBERGUEST_21text[] = "";
XCHAR BaseMain_PAGERACTIVATED_21text[] = "Yes";
XCHAR BaseMain_PAGERCALLED_21text[] = "";
XCHAR BaseMain_TABLENUMBER_21text[] ="";
XCHAR BaseMain_ORDERFOOD_21text[] = "";
//Pager 22	
const XCHAR BaseMain_PAGERNUMBER_22text[] = 	"22";
XCHAR BaseMain_NUMBERGUEST_22text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_22text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_22text[] = 	"";
XCHAR BaseMain_TABLENUMBER_22text[] = 	"";
XCHAR BaseMain_ORDERFOOD_22text[] = 	"";
//Pager 23	
const XCHAR BaseMain_PAGERNUMBER_23text[] = 	"23";
XCHAR BaseMain_NUMBERGUEST_23text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_23text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_23text[] = 	"";
XCHAR BaseMain_TABLENUMBER_23text[] = 	"";
XCHAR BaseMain_ORDERFOOD_23text[] = 	"";
//Pager 24	
const XCHAR BaseMain_PAGERNUMBER_24text[] = 	"24";
XCHAR BaseMain_NUMBERGUEST_24text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_24text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_24text[] = 	"";
XCHAR BaseMain_TABLENUMBER_24text[] = 	"";
XCHAR BaseMain_ORDERFOOD_24text[] = 	"";
//Pager 25	
const XCHAR BaseMain_PAGERNUMBER_25text[] = 	"25";
XCHAR BaseMain_NUMBERGUEST_25text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_25text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_25text[] = 	"";
XCHAR BaseMain_TABLENUMBER_25text[] = 	"";
XCHAR BaseMain_ORDERFOOD_25text[] = 	"";
//Pager 26	
const XCHAR BaseMain_PAGERNUMBER_26text[] = 	"26";
XCHAR BaseMain_NUMBERGUEST_26text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_26text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_26text[] = 	"";
XCHAR BaseMain_TABLENUMBER_26text[] = 	"";
XCHAR BaseMain_ORDERFOOD_26text[] = 	"";
//Pager 27	
const XCHAR BaseMain_PAGERNUMBER_27text[] = 	"27";
XCHAR BaseMain_NUMBERGUEST_27text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_27text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_27text[] = 	"";
XCHAR BaseMain_TABLENUMBER_27text[] = 	"";
XCHAR BaseMain_ORDERFOOD_27text[] = 	"";
//Pager 28	
const XCHAR BaseMain_PAGERNUMBER_28text[] = 	"28";
XCHAR BaseMain_NUMBERGUEST_28text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_28text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_28text[] = 	"";
XCHAR BaseMain_TABLENUMBER_28text[] = 	"";
XCHAR BaseMain_ORDERFOOD_28text[] = 	"";
//Pager 29	
const XCHAR BaseMain_PAGERNUMBER_29text[] = 	"29";
XCHAR BaseMain_NUMBERGUEST_29text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_29text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_29text[] = 	"";
XCHAR BaseMain_TABLENUMBER_29text[] = 	"";
XCHAR BaseMain_ORDERFOOD_29text[] = 	"";
//Pager 30	
const XCHAR BaseMain_PAGERNUMBER_30text[] = 	"30";
XCHAR BaseMain_NUMBERGUEST_30text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_30text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_30text[] = 	"";
XCHAR BaseMain_TABLENUMBER_30text[] = 	"";
XCHAR BaseMain_ORDERFOOD_30text[] = 	"";
//Pager 31	
const XCHAR BaseMain_PAGERNUMBER_31text[] = 	"31";
XCHAR BaseMain_NUMBERGUEST_31text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_31text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_31text[] = 	"";
XCHAR BaseMain_TABLENUMBER_31text[] = 	"";
XCHAR BaseMain_ORDERFOOD_31text[] = 	"";
//Pager 32	
const XCHAR BaseMain_PAGERNUMBER_32text[] = 	"32";
XCHAR BaseMain_NUMBERGUEST_32text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_32text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_32text[] = 	"";
XCHAR BaseMain_TABLENUMBER_32text[] = 	"";
XCHAR BaseMain_ORDERFOOD_32text[] = 	"";
//Pager 33	
const XCHAR BaseMain_PAGERNUMBER_33text[] = 	"33";
XCHAR BaseMain_NUMBERGUEST_33text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_33text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_33text[] = 	"";
XCHAR BaseMain_TABLENUMBER_33text[] = 	"";
XCHAR BaseMain_ORDERFOOD_33text[] = 	"";
//Pager 34	
const XCHAR BaseMain_PAGERNUMBER_34text[] = 	"34";
XCHAR BaseMain_NUMBERGUEST_34text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_34text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_34text[] = 	"";
XCHAR BaseMain_TABLENUMBER_34text[] = 	"";
XCHAR BaseMain_ORDERFOOD_34text[] = 	"";
//Pager 35	
const XCHAR BaseMain_PAGERNUMBER_35text[] = 	"35";
XCHAR BaseMain_NUMBERGUEST_35text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_35text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_35text[] = 	"";
XCHAR BaseMain_TABLENUMBER_35text[] = 	"";
XCHAR BaseMain_ORDERFOOD_35text[] = 	"";
//Pager 36	
const XCHAR BaseMain_PAGERNUMBER_36text[] = 	"36";
XCHAR BaseMain_NUMBERGUEST_36text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_36text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_36text[] = 	"";
XCHAR BaseMain_TABLENUMBER_36text[] = 	"";
XCHAR BaseMain_ORDERFOOD_36text[] = 	"";
//Pager 37	
const XCHAR BaseMain_PAGERNUMBER_37text[] = 	"37";
XCHAR BaseMain_NUMBERGUEST_37text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_37text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_37text[] = 	"";
XCHAR BaseMain_TABLENUMBER_37text[] = 	"";
XCHAR BaseMain_ORDERFOOD_37text[] = 	"";
//Pager 38	
const XCHAR BaseMain_PAGERNUMBER_38text[] = 	"38";
XCHAR BaseMain_NUMBERGUEST_38text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_38text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_38text[] = 	"";
XCHAR BaseMain_TABLENUMBER_38text[] = 	"";
XCHAR BaseMain_ORDERFOOD_38text[] = 	"";
//Pager 39	
const XCHAR BaseMain_PAGERNUMBER_39text[] = 	"39";
XCHAR BaseMain_NUMBERGUEST_39text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_39text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_39text[] = 	"";
XCHAR BaseMain_TABLENUMBER_39text[] = 	"";
XCHAR BaseMain_ORDERFOOD_39text[] = 	"";
//Pager 40	
const XCHAR BaseMain_PAGERNUMBER_40text[] = 	"40";
XCHAR BaseMain_NUMBERGUEST_40text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_40text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_40text[] = 	"";
XCHAR BaseMain_TABLENUMBER_40text[] = 	"";
XCHAR BaseMain_ORDERFOOD_40text[] = 	"";
//Pager 41	
const XCHAR BaseMain_PAGERNUMBER_41text[] = 	"41";
XCHAR BaseMain_NUMBERGUEST_41text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_41text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_41text[] = 	"";
XCHAR BaseMain_TABLENUMBER_41text[] = 	"";
XCHAR BaseMain_ORDERFOOD_41text[] = 	"";
//Pager 42	
const XCHAR BaseMain_PAGERNUMBER_42text[] = 	"42";
XCHAR BaseMain_NUMBERGUEST_42text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_42text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_42text[] = 	"";
XCHAR BaseMain_TABLENUMBER_42text[] = 	"";
XCHAR BaseMain_ORDERFOOD_42text[] = 	"";
//Pager 43	
const XCHAR BaseMain_PAGERNUMBER_43text[] = 	"43";
XCHAR BaseMain_NUMBERGUEST_43text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_43text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_43text[] = 	"";
XCHAR BaseMain_TABLENUMBER_43text[] = 	"";
XCHAR BaseMain_ORDERFOOD_43text[] = 	"";
//Pager 44	
const XCHAR BaseMain_PAGERNUMBER_44text[] = 	"44";
XCHAR BaseMain_NUMBERGUEST_44text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_44text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_44text[] = 	"";
XCHAR BaseMain_TABLENUMBER_44text[] = 	"";
XCHAR BaseMain_ORDERFOOD_44text[] = 	"";
//Pager 45	
const XCHAR BaseMain_PAGERNUMBER_45text[] = 	"45";
XCHAR BaseMain_NUMBERGUEST_45text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_45text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_45text[] = 	"";
XCHAR BaseMain_TABLENUMBER_45text[] = 	"";
XCHAR BaseMain_ORDERFOOD_45text[] = 	"";
//Pager 46	
const XCHAR BaseMain_PAGERNUMBER_46text[] = 	"46";
XCHAR BaseMain_NUMBERGUEST_46text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_46text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_46text[] = 	"";
XCHAR BaseMain_TABLENUMBER_46text[] = 	"";
XCHAR BaseMain_ORDERFOOD_46text[] = 	"";
//Pager 47	
const XCHAR BaseMain_PAGERNUMBER_47text[] = 	"47";
XCHAR BaseMain_NUMBERGUEST_47text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_47text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_47text[] = 	"";
XCHAR BaseMain_TABLENUMBER_47text[] = 	"";
XCHAR BaseMain_ORDERFOOD_47text[] = 	"";
//Pager 48	
const XCHAR BaseMain_PAGERNUMBER_48text[] = 	"48";
XCHAR BaseMain_NUMBERGUEST_48text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_48text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_48text[] = 	"";
XCHAR BaseMain_TABLENUMBER_48text[] = 	"";
XCHAR BaseMain_ORDERFOOD_48text[] = 	"";
//Pager 49	
const XCHAR BaseMain_PAGERNUMBER_49text[] = 	"49";
XCHAR BaseMain_NUMBERGUEST_49text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_49text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_49text[] = 	"";
XCHAR BaseMain_TABLENUMBER_49text[] = 	"";
XCHAR BaseMain_ORDERFOOD_49text[] = 	"";
//Pager 50	
const XCHAR BaseMain_PAGERNUMBER_50text[] = 	"50";
XCHAR BaseMain_NUMBERGUEST_50text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_50text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_50text[] = 	"";
XCHAR BaseMain_TABLENUMBER_50text[] = 	"";
XCHAR BaseMain_ORDERFOOD_50text[] = 	"";
//Pager 51	
const XCHAR BaseMain_PAGERNUMBER_51text[] = 	"51";
XCHAR BaseMain_NUMBERGUEST_51text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_51text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_51text[] = 	"";
XCHAR BaseMain_TABLENUMBER_51text[] = 	"";
XCHAR BaseMain_ORDERFOOD_51text[] = 	"";
//Pager 52	
const XCHAR BaseMain_PAGERNUMBER_52text[] = 	"52";
XCHAR BaseMain_NUMBERGUEST_52text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_52text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_52text[] = 	"";
XCHAR BaseMain_TABLENUMBER_52text[] = 	"";
XCHAR BaseMain_ORDERFOOD_52text[] = 	"";
//Pager 53	
const XCHAR BaseMain_PAGERNUMBER_53text[] = 	"53";
XCHAR BaseMain_NUMBERGUEST_53text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_53text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_53text[] = 	"";
XCHAR BaseMain_TABLENUMBER_53text[] = 	"";
XCHAR BaseMain_ORDERFOOD_53text[] = 	"";
//Pager 54	
const XCHAR BaseMain_PAGERNUMBER_54text[] = 	"54";
XCHAR BaseMain_NUMBERGUEST_54text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_54text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_54text[] = 	"";
XCHAR BaseMain_TABLENUMBER_54text[] = 	"";
XCHAR BaseMain_ORDERFOOD_54text[] = 	"";
//Pager 55	
const XCHAR BaseMain_PAGERNUMBER_55text[] = 	"55";
XCHAR BaseMain_NUMBERGUEST_55text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_55text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_55text[] = 	"";
XCHAR BaseMain_TABLENUMBER_55text[] = 	"";
XCHAR BaseMain_ORDERFOOD_55text[] = 	"";
//Pager 56	
const XCHAR BaseMain_PAGERNUMBER_56text[] = 	"56";
XCHAR BaseMain_NUMBERGUEST_56text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_56text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_56text[] = 	"";
XCHAR BaseMain_TABLENUMBER_56text[] = 	"";
XCHAR BaseMain_ORDERFOOD_56text[] = 	"";
//Pager 57	
const XCHAR BaseMain_PAGERNUMBER_57text[] = 	"57";
XCHAR BaseMain_NUMBERGUEST_57text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_57text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_57text[] = 	"";
XCHAR BaseMain_TABLENUMBER_57text[] = 	"";
XCHAR BaseMain_ORDERFOOD_57text[] = 	"";
//Pager 58	
const XCHAR BaseMain_PAGERNUMBER_58text[] = 	"58";
XCHAR BaseMain_NUMBERGUEST_58text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_58text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_58text[] = 	"";
XCHAR BaseMain_TABLENUMBER_58text[] = 	"";
XCHAR BaseMain_ORDERFOOD_58text[] = 	"";
//Pager 59	
const XCHAR BaseMain_PAGERNUMBER_59text[] = 	"59";
XCHAR BaseMain_NUMBERGUEST_59text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_59text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_59text[] = 	"";
XCHAR BaseMain_TABLENUMBER_59text[] = 	"";
XCHAR BaseMain_ORDERFOOD_59text[] = 	"";
//Pager 60	
const XCHAR BaseMain_PAGERNUMBER_60text[] = 	"60";
XCHAR BaseMain_NUMBERGUEST_60text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_60text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_60text[] = 	"";
XCHAR BaseMain_TABLENUMBER_60text[] = 	"";
XCHAR BaseMain_ORDERFOOD_60text[] = 	"";
//Pager 61	
const XCHAR BaseMain_PAGERNUMBER_61text[] = 	"61";
XCHAR BaseMain_NUMBERGUEST_61text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_61text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_61text[] = 	"";
XCHAR BaseMain_TABLENUMBER_61text[] = 	"";
XCHAR BaseMain_ORDERFOOD_61text[] = 	"";
//Pager 62	
const XCHAR BaseMain_PAGERNUMBER_62text[] = 	"62";
XCHAR BaseMain_NUMBERGUEST_62text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_62text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_62text[] = 	"";
XCHAR BaseMain_TABLENUMBER_62text[] = 	"";
XCHAR BaseMain_ORDERFOOD_62text[] = 	"";
//Pager 63	
const XCHAR BaseMain_PAGERNUMBER_63text[] = 	"63";
XCHAR BaseMain_NUMBERGUEST_63text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_63text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_63text[] = 	"";
XCHAR BaseMain_TABLENUMBER_63text[] = 	"";
XCHAR BaseMain_ORDERFOOD_63text[] = 	"";
//Pager 64	
const XCHAR BaseMain_PAGERNUMBER_64text[] = 	"64";
XCHAR BaseMain_NUMBERGUEST_64text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_64text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_64text[] = 	"";
XCHAR BaseMain_TABLENUMBER_64text[] = 	"";
XCHAR BaseMain_ORDERFOOD_64text[] = 	"";
//Pager 65	
const XCHAR BaseMain_PAGERNUMBER_65text[] = 	"65";
XCHAR BaseMain_NUMBERGUEST_65text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_65text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_65text[] = 	"";
XCHAR BaseMain_TABLENUMBER_65text[] = 	"";
XCHAR BaseMain_ORDERFOOD_65text[] = 	"";
//Pager 66	
const XCHAR BaseMain_PAGERNUMBER_66text[] = 	"66";
XCHAR BaseMain_NUMBERGUEST_66text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_66text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_66text[] = 	"";
XCHAR BaseMain_TABLENUMBER_66text[] = 	"";
XCHAR BaseMain_ORDERFOOD_66text[] = 	"";
//Pager 67	
const XCHAR BaseMain_PAGERNUMBER_67text[] = 	"67";
XCHAR BaseMain_NUMBERGUEST_67text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_67text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_67text[] = 	"";
XCHAR BaseMain_TABLENUMBER_67text[] = 	"";
XCHAR BaseMain_ORDERFOOD_67text[] = 	"";
//Pager 68	
const XCHAR BaseMain_PAGERNUMBER_68text[] = 	"68";
XCHAR BaseMain_NUMBERGUEST_68text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_68text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_68text[] = 	"";
XCHAR BaseMain_TABLENUMBER_68text[] = 	"";
XCHAR BaseMain_ORDERFOOD_68text[] = 	"";
//Pager 69	
const XCHAR BaseMain_PAGERNUMBER_69text[] = 	"69";
XCHAR BaseMain_NUMBERGUEST_69text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_69text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_69text[] = 	"";
XCHAR BaseMain_TABLENUMBER_69text[] = 	"";
XCHAR BaseMain_ORDERFOOD_69text[] = 	"";
//Pager 70	
const XCHAR BaseMain_PAGERNUMBER_70text[] = 	"70";
XCHAR BaseMain_NUMBERGUEST_70text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_70text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_70text[] = 	"";
XCHAR BaseMain_TABLENUMBER_70text[] = 	"";
XCHAR BaseMain_ORDERFOOD_70text[] = 	"";
//Pager 71	
const XCHAR BaseMain_PAGERNUMBER_71text[] = 	"71";
XCHAR BaseMain_NUMBERGUEST_71text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_71text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_71text[] = 	"";
XCHAR BaseMain_TABLENUMBER_71text[] = 	"";
XCHAR BaseMain_ORDERFOOD_71text[] = 	"";
//Pager 72	
const XCHAR BaseMain_PAGERNUMBER_72text[] = 	"72";
XCHAR BaseMain_NUMBERGUEST_72text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_72text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_72text[] = 	"";
XCHAR BaseMain_TABLENUMBER_72text[] = 	"";
XCHAR BaseMain_ORDERFOOD_72text[] = 	"";
//Pager 73	
const XCHAR BaseMain_PAGERNUMBER_73text[] = 	"73";
XCHAR BaseMain_NUMBERGUEST_73text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_73text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_73text[] = 	"";
XCHAR BaseMain_TABLENUMBER_73text[] = 	"";
XCHAR BaseMain_ORDERFOOD_73text[] = 	"";
//Pager 74	
const XCHAR BaseMain_PAGERNUMBER_74text[] = 	"74";
XCHAR BaseMain_NUMBERGUEST_74text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_74text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_74text[] = 	"";
XCHAR BaseMain_TABLENUMBER_74text[] = 	"";
XCHAR BaseMain_ORDERFOOD_74text[] = 	"";
//Pager 75	
const XCHAR BaseMain_PAGERNUMBER_75text[] = 	"75";
XCHAR BaseMain_NUMBERGUEST_75text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_75text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_75text[] = 	"";
XCHAR BaseMain_TABLENUMBER_75text[] = 	"";
XCHAR BaseMain_ORDERFOOD_75text[] = 	"";
//Pager 76	
const XCHAR BaseMain_PAGERNUMBER_76text[] = 	"76";
XCHAR BaseMain_NUMBERGUEST_76text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_76text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_76text[] = 	"";
XCHAR BaseMain_TABLENUMBER_76text[] = 	"";
XCHAR BaseMain_ORDERFOOD_76text[] = 	"";
//Pager 77	
const XCHAR BaseMain_PAGERNUMBER_77text[] = 	"77";
XCHAR BaseMain_NUMBERGUEST_77text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_77text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_77text[] = 	"";
XCHAR BaseMain_TABLENUMBER_77text[] = 	"";
XCHAR BaseMain_ORDERFOOD_77text[] = 	"";
//Pager 78	
const XCHAR BaseMain_PAGERNUMBER_78text[] = 	"78";
XCHAR BaseMain_NUMBERGUEST_78text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_78text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_78text[] = 	"";
XCHAR BaseMain_TABLENUMBER_78text[] = 	"";
XCHAR BaseMain_ORDERFOOD_78text[] = 	"";
//Pager 79	
const XCHAR BaseMain_PAGERNUMBER_79text[] = 	"79";
XCHAR BaseMain_NUMBERGUEST_79text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_79text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_79text[] = 	"";
XCHAR BaseMain_TABLENUMBER_79text[] = 	"";
XCHAR BaseMain_ORDERFOOD_79text[] = 	"";
//Pager 80	
const XCHAR BaseMain_PAGERNUMBER_80text[] = 	"80";
XCHAR BaseMain_NUMBERGUEST_80text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_80text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_80text[] = 	"";
XCHAR BaseMain_TABLENUMBER_80text[] = 	"";
XCHAR BaseMain_ORDERFOOD_80text[] = 	"";
//Pager 81	
const XCHAR BaseMain_PAGERNUMBER_81text[] = 	"81";
XCHAR BaseMain_NUMBERGUEST_81text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_81text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_81text[] = 	"";
XCHAR BaseMain_TABLENUMBER_81text[] = 	"";
XCHAR BaseMain_ORDERFOOD_81text[] = 	"";
//Pager 82	
const XCHAR BaseMain_PAGERNUMBER_82text[] = 	"82";
XCHAR BaseMain_NUMBERGUEST_82text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_82text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_82text[] = 	"";
XCHAR BaseMain_TABLENUMBER_82text[] = 	"";
XCHAR BaseMain_ORDERFOOD_82text[] = 	"";
//Pager 83	
const XCHAR BaseMain_PAGERNUMBER_83text[] = 	"83";
XCHAR BaseMain_NUMBERGUEST_83text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_83text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_83text[] = 	"";
XCHAR BaseMain_TABLENUMBER_83text[] = 	"";
XCHAR BaseMain_ORDERFOOD_83text[] = 	"";
//Pager 84	
const XCHAR BaseMain_PAGERNUMBER_84text[] = 	"84";
XCHAR BaseMain_NUMBERGUEST_84text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_84text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_84text[] = 	"";
XCHAR BaseMain_TABLENUMBER_84text[] = 	"";
XCHAR BaseMain_ORDERFOOD_84text[] = 	"";
//Pager 85	
const XCHAR BaseMain_PAGERNUMBER_85text[] = 	"85";
XCHAR BaseMain_NUMBERGUEST_85text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_85text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_85text[] = 	"";
XCHAR BaseMain_TABLENUMBER_85text[] = 	"";
XCHAR BaseMain_ORDERFOOD_85text[] = 	"";
//Pager 86	
const XCHAR BaseMain_PAGERNUMBER_86text[] = 	"86";
XCHAR BaseMain_NUMBERGUEST_86text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_86text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_86text[] = 	"";
XCHAR BaseMain_TABLENUMBER_86text[] = 	"";
XCHAR BaseMain_ORDERFOOD_86text[] = 	"";
//Pager 87	
const XCHAR BaseMain_PAGERNUMBER_87text[] = 	"87";
XCHAR BaseMain_NUMBERGUEST_87text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_87text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_87text[] = 	"";
XCHAR BaseMain_TABLENUMBER_87text[] = 	"";
XCHAR BaseMain_ORDERFOOD_87text[] = 	"";
//Pager 88	
const XCHAR BaseMain_PAGERNUMBER_88text[] = 	"88";
XCHAR BaseMain_NUMBERGUEST_88text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_88text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_88text[] = 	"";
XCHAR BaseMain_TABLENUMBER_88text[] = 	"";
XCHAR BaseMain_ORDERFOOD_88text[] = 	"";
//Pager 89	
const XCHAR BaseMain_PAGERNUMBER_89text[] = 	"89";
XCHAR BaseMain_NUMBERGUEST_89text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_89text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_89text[] = 	"";
XCHAR BaseMain_TABLENUMBER_89text[] = 	"";
XCHAR BaseMain_ORDERFOOD_89text[] = 	"";
//Pager 90	
const XCHAR BaseMain_PAGERNUMBER_90text[] = 	"90";
XCHAR BaseMain_NUMBERGUEST_90text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_90text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_90text[] = 	"";
XCHAR BaseMain_TABLENUMBER_90text[] = 	"";
XCHAR BaseMain_ORDERFOOD_90text[] = 	"";
//Pager 91	
const XCHAR BaseMain_PAGERNUMBER_91text[] = 	"91";
XCHAR BaseMain_NUMBERGUEST_91text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_91text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_91text[] = 	"";
XCHAR BaseMain_TABLENUMBER_91text[] = 	"";
XCHAR BaseMain_ORDERFOOD_91text[] = 	"";
//Pager 92	
const XCHAR BaseMain_PAGERNUMBER_92text[] = 	"92";
XCHAR BaseMain_NUMBERGUEST_92text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_92text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_92text[] = 	"";
XCHAR BaseMain_TABLENUMBER_92text[] = 	"";
XCHAR BaseMain_ORDERFOOD_92text[] = 	"";
//Pager 93	
const XCHAR BaseMain_PAGERNUMBER_93text[] = 	"93";
XCHAR BaseMain_NUMBERGUEST_93text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_93text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_93text[] = 	"";
XCHAR BaseMain_TABLENUMBER_93text[] = 	"";
XCHAR BaseMain_ORDERFOOD_93text[] = 	"";
//Pager 94	
const XCHAR BaseMain_PAGERNUMBER_94text[] = 	"94";
XCHAR BaseMain_NUMBERGUEST_94text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_94text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_94text[] = 	"";
XCHAR BaseMain_TABLENUMBER_94text[] = 	"";
XCHAR BaseMain_ORDERFOOD_94text[] = 	"";
//Pager 95	
const XCHAR BaseMain_PAGERNUMBER_95text[] = 	"95";
XCHAR BaseMain_NUMBERGUEST_95text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_95text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_95text[] = 	"";
XCHAR BaseMain_TABLENUMBER_95text[] = 	"";
XCHAR BaseMain_ORDERFOOD_95text[] = 	"";
//Pager 96	
const XCHAR BaseMain_PAGERNUMBER_96text[] = 	"96";
XCHAR BaseMain_NUMBERGUEST_96text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_96text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_96text[] = 	"";
XCHAR BaseMain_TABLENUMBER_96text[] = 	"";
XCHAR BaseMain_ORDERFOOD_96text[] = 	"";
//Pager 97	
const XCHAR BaseMain_PAGERNUMBER_97text[] = 	"97";
XCHAR BaseMain_NUMBERGUEST_97text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_97text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_97text[] = 	"";
XCHAR BaseMain_TABLENUMBER_97text[] = 	"";
XCHAR BaseMain_ORDERFOOD_97text[] = 	"";
//Pager 98	
const XCHAR BaseMain_PAGERNUMBER_98text[] = 	"98";
XCHAR BaseMain_NUMBERGUEST_98text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_98text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_98text[] = 	"";
XCHAR BaseMain_TABLENUMBER_98text[] = 	"";
XCHAR BaseMain_ORDERFOOD_98text[] = 	"";
//Pager 99	
const XCHAR BaseMain_PAGERNUMBER_99text[] = 	"99";
XCHAR BaseMain_NUMBERGUEST_99text[] = 	"";
XCHAR BaseMain_PAGERACTIVATED_99text[] = 	"Yes";
XCHAR BaseMain_PAGERCALLED_99text[] = 	"";
XCHAR BaseMain_TABLENUMBER_99text[] = 	"";
XCHAR BaseMain_ORDERFOOD_99text[] = 	"";

//Headers
const XCHAR BaseMain_OBJ_STATICTEXT_1_1text[] = "Pager\nNumber";
const XCHAR BaseMain_OBJ_STATICTEXT_2_1text[] = "Number\nof Guests";
const XCHAR BaseMain_OBJ_STATICTEXT_3_1text[] = "Pager\nActivated";
const XCHAR BaseMain_OBJ_STATICTEXT_4_1text[] = "Pager\nCalled?";
const XCHAR BaseMain_OBJ_STATICTEXT_5_1text[] = "Table\n#";
const XCHAR BaseMain_OBJ_STATICTEXT_6_1text[] = "Order\nFood?";
const XCHAR PagerSelect_Maintext[] = "Main";
const XCHAR PagerSelect_OBJ_EDITBOX_7_4text[] = "Pager #";
const XCHAR PagerSelect_OBJ_STATICTEXT_7_4text[] = "Enter Pager Number";
GOL_SCHEME* button;
GOL_SCHEME* editbox;
GOL_SCHEME* text;
void (*CreateFunctionArray[NUM_GDD_SCREENS])();
void (*CreatePrimitivesFunctionArray[NUM_GDD_SCREENS])();
WORD currentGDDDemoScreenIndex;
static BYTE update = 0;
static BYTE updateGPL = 0;
//  Creates the First Screen
void GDDDemoCreateFirstScreen(void)
{
	currentGDDDemoScreenIndex = 0;
	update = 1;
	(*CreateFunctionArray[currentGDDDemoScreenIndex])();
}
//  Creates the Next Screen
void GDDDemoNextScreen(void)
{
	currentGDDDemoScreenIndex++;
	if(currentGDDDemoScreenIndex >= NUM_GDD_SCREENS)
	{
		currentGDDDemoScreenIndex = 0;
	}
	update = 1;
}
//  GOL Message Callback
void GDDDemoGOLMsgCallback(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg)
{
	//Future event handling support by GDD
}
//  GOL Draw Callback
void GDDDemoGOLDrawCallback(void)
{
	if(updateGPL)
	{
		(*CreatePrimitivesFunctionArray[currentGDDDemoScreenIndex])();
		updateGPL = 0;
	}
if(update)
	{
		(*CreateFunctionArray[currentGDDDemoScreenIndex])();
		if(CreatePrimitivesFunctionArray[currentGDDDemoScreenIndex] != NULL)
		{
			updateGPL = 1;
		}
		update = 0;
	}
}
//  Create Error Flash (Blue Screen)
void CreateError(char* string)
{
	// Blue Screen Error
	SetColor(119);
	ClearDevice();
	SetColor(-1);
// Flash Error Message
	if(string == NULL)
		{OutTextXY(0, 0, "Runtime Error.");}
	else{OutTextXY(0,0, string);}
}


void CreateBaseMain(void)
{
	GOLFree();
	SetColor(0);
	ClearDevice();
	if(button != NULL) free(button);
	button = GOLCreateScheme();
	button->Color0 = 1024;
	button->Color1 = 64969;
	button->ColorDisabled = 55070;
	button->CommonBkColor = 0;
	button->EmbossDkColor = 0;
	button->EmbossLtColor = 44765;
	button->TextColor0 = 65535;
	button->TextColor1 = 31;
	button->pFont = (void*)&gentium_16_200_0_0_0_0;
	if(editbox != NULL) free(editbox);
	editbox = GOLCreateScheme();
	editbox->Color0 = 65535;
	editbox->Color1 = 64969;
	editbox->ColorDisabled = 55070;
	editbox->CommonBkColor = 55166;
	editbox->EmbossDkColor = 0;
	editbox->EmbossLtColor = 0;
	editbox->TextColor0 = 0;
	editbox->TextColor1 = 31;
	editbox->pFont = (void*)&gentium_16_200_0_0_0_0;
	if(text != NULL) free(text);
	text = GOLCreateScheme();
	text->Color0 = 19583;
	text->Color1 = 0;
	text->ColorDisabled = 55070;
	text->CommonBkColor = 65535;
	text->EmbossDkColor = 6172;
	text->EmbossLtColor = 44765;
	text->TextColor0 = 0;
	text->TextColor1 = 31;
	text->pFont = (void*)&gentium_16_200_0_0_0_0;
	
	BUTTON *pBaseMain_Call;
	pBaseMain_Call = BtnCreate(BaseMain_Call,361,135,458,189,0,16384,NULL,(XCHAR*)BaseMain_Calltext,button);
	if(pBaseMain_Call==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	
	/*
	BUTTON *pBaseMain_EditData;
	pBaseMain_EditData = BtnCreate(BaseMain_EditData,348,197,469,261,0,16384,NULL,(XCHAR*)BaseMain_EditDatatext,button);
	if(pBaseMain_EditData==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	*/
	BUTTON *pBaseMain_Clear;
	pBaseMain_Clear = BtnCreate(BaseMain_Clear,348,197,469,261,0,16384,NULL,(XCHAR*)BaseMain_Cleartext,button);
	if(pBaseMain_Clear==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	
	STATICTEXT *pBaseMain_OBJ_STATICTEXT_1_1;
	pBaseMain_OBJ_STATICTEXT_1_1 = StCreate(BaseMain_OBJ_STATICTEXT_1_1,0,0,70,55,16400,(XCHAR*)BaseMain_OBJ_STATICTEXT_1_1text,text);
	if(pBaseMain_OBJ_STATICTEXT_1_1==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	STATICTEXT *pBaseMain_OBJ_STATICTEXT_2_1;
	pBaseMain_OBJ_STATICTEXT_2_1 = StCreate(BaseMain_OBJ_STATICTEXT_2_1,70,0,140,55,16400,(XCHAR*)BaseMain_OBJ_STATICTEXT_2_1text,text);
	if(pBaseMain_OBJ_STATICTEXT_2_1==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	STATICTEXT *pBaseMain_OBJ_STATICTEXT_3_1;
	pBaseMain_OBJ_STATICTEXT_3_1 = StCreate(BaseMain_OBJ_STATICTEXT_3_1,140,0,210,55,16400,(XCHAR*)BaseMain_OBJ_STATICTEXT_3_1text,text);
	if(pBaseMain_OBJ_STATICTEXT_3_1==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	STATICTEXT *pBaseMain_OBJ_STATICTEXT_4_1;
	pBaseMain_OBJ_STATICTEXT_4_1 = StCreate(BaseMain_OBJ_STATICTEXT_4_1,210,0,280,55,16400,(XCHAR*)BaseMain_OBJ_STATICTEXT_4_1text,text);
	if(pBaseMain_OBJ_STATICTEXT_4_1==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	STATICTEXT *pBaseMain_OBJ_STATICTEXT_5_1;
	pBaseMain_OBJ_STATICTEXT_5_1 = StCreate(BaseMain_OBJ_STATICTEXT_5_1,280,0,350,55,16400,(XCHAR*)BaseMain_OBJ_STATICTEXT_5_1text,text);
	if(pBaseMain_OBJ_STATICTEXT_5_1==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	STATICTEXT *pBaseMain_OBJ_STATICTEXT_6_1;
	pBaseMain_OBJ_STATICTEXT_6_1 = StCreate(BaseMain_OBJ_STATICTEXT_6_1,350,0,420,55,16400,(XCHAR*)BaseMain_OBJ_STATICTEXT_6_1text,text);
	if(pBaseMain_OBJ_STATICTEXT_6_1==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	
	//Creates vv for next page
	BUTTON *pBaseMain_Next;
	pBaseMain_Next = BtnCreate(BaseMain_Next,210,235,335,260,0,16384,NULL,"vv",button);
	if(pBaseMain_Next==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	
	//Creates ^^ for previous page
	BUTTON *pBaseMain_Back;
	pBaseMain_Back = BtnCreate(BaseMain_Back,35,235,140,260,0,16384,NULL,"^^",button);
	if(pBaseMain_Back==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	}


void CreatePager0(void)
{	
	//Create Header
	CreateBaseMain();
	//Create Pager 0	
	EDITBOX *pBaseMain_PAGERNUMBER_00;
	pBaseMain_PAGERNUMBER_00 = EbCreate(BaseMain_PAGERNUMBER_00,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_00text,16,editbox);
	if(pBaseMain_PAGERNUMBER_00==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_00;
	pBaseMain_NUMBERGUEST_00 = EbCreate(BaseMain_NUMBERGUEST_00,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_00text,2,editbox);
	if(pBaseMain_NUMBERGUEST_00==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_00;
	pBaseMain_PAGERACTIVATED_00 = EbCreate(BaseMain_PAGERACTIVATED_00,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_00text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_00==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_00;
	pBaseMain_PAGERCALLED_00 = EbCreate(BaseMain_PAGERCALLED_00,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_00text,3,editbox);
	if(pBaseMain_PAGERCALLED_00==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_00;
	pBaseMain_TABLENUMBER_00 = EbCreate(BaseMain_TABLENUMBER_00,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_00text,3,editbox);
	if(pBaseMain_TABLENUMBER_00==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_00;
	pBaseMain_ORDERFOOD_00 = EbCreate(BaseMain_ORDERFOOD_00,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_00text,3,editbox);
	if(pBaseMain_ORDERFOOD_00==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size

}	

void CreatePager1(void)
{
	//Pager 0
	CreatePager0();
	
	//Pager 1
	EDITBOX *pBaseMain_PAGERNUMBER_01;
	pBaseMain_PAGERNUMBER_01 = EbCreate(BaseMain_PAGERNUMBER_01,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_01text,16,editbox);
	if(pBaseMain_PAGERNUMBER_01==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_01;
	pBaseMain_NUMBERGUEST_01 = EbCreate(BaseMain_NUMBERGUEST_01,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_01text,2,editbox);
	if(pBaseMain_NUMBERGUEST_01==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_01;
	pBaseMain_PAGERACTIVATED_01 = EbCreate(BaseMain_PAGERACTIVATED_01,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_01text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_01==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_01;
	pBaseMain_PAGERCALLED_01 = EbCreate(BaseMain_PAGERCALLED_01,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_01text,3,editbox);
	if(pBaseMain_PAGERCALLED_01==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_01;
	pBaseMain_TABLENUMBER_01 = EbCreate(BaseMain_TABLENUMBER_01,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_01text,3,editbox);
	if(pBaseMain_TABLENUMBER_01==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_01;
	pBaseMain_ORDERFOOD_01 = EbCreate(BaseMain_ORDERFOOD_01,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_01text,3,editbox);
	if(pBaseMain_ORDERFOOD_01==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	

void CreatePager2(void)
{	
	//Pager 1
	CreatePager1();
	
	//Pager 2
	EDITBOX *pBaseMain_PAGERNUMBER_02;
	pBaseMain_PAGERNUMBER_02 = EbCreate(BaseMain_PAGERNUMBER_02,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_02text,16,editbox);
	if(pBaseMain_PAGERNUMBER_02==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_02;
	pBaseMain_NUMBERGUEST_02 = EbCreate(BaseMain_NUMBERGUEST_02,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_02text,2,editbox);
	if(pBaseMain_NUMBERGUEST_02==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_02;
	pBaseMain_PAGERACTIVATED_02 = EbCreate(BaseMain_PAGERACTIVATED_02,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_02text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_02==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_02;
	pBaseMain_PAGERCALLED_02 = EbCreate(BaseMain_PAGERCALLED_02,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_02text,3,editbox);
	if(pBaseMain_PAGERCALLED_02==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_02;
	pBaseMain_TABLENUMBER_02 = EbCreate(BaseMain_TABLENUMBER_02,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_02text,3,editbox);
	if(pBaseMain_TABLENUMBER_02==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_02;
	pBaseMain_ORDERFOOD_02 = EbCreate(BaseMain_ORDERFOOD_02,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_02text,3,editbox);
	if(pBaseMain_ORDERFOOD_02==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	

void CreatePager3(void)
{
	//Create Pagers 1 and 2
	CreatePager2();
	//Pager 3
	EDITBOX *pBaseMain_PAGERNUMBER_03;
	pBaseMain_PAGERNUMBER_03 = EbCreate(BaseMain_PAGERNUMBER_03,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_03text,16,editbox);
	if(pBaseMain_PAGERNUMBER_03==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_03;
	pBaseMain_NUMBERGUEST_03 = EbCreate(BaseMain_NUMBERGUEST_03,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_03text,2,editbox);
	if(pBaseMain_NUMBERGUEST_03==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_03;
	pBaseMain_PAGERACTIVATED_03 = EbCreate(BaseMain_PAGERACTIVATED_03,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_03text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_03==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_03;
	pBaseMain_PAGERCALLED_03 = EbCreate(BaseMain_PAGERCALLED_03,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_03text,3,editbox);
	if(pBaseMain_PAGERCALLED_03==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_03;
	pBaseMain_TABLENUMBER_03 = EbCreate(BaseMain_TABLENUMBER_03,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_03text,3,editbox);
	if(pBaseMain_TABLENUMBER_03==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_03;
	pBaseMain_ORDERFOOD_03 = EbCreate(BaseMain_ORDERFOOD_03,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_03text,3,editbox);
	if(pBaseMain_ORDERFOOD_03==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	

void CreatePager4(void)
{
	//Create Pagers 1-3
	CreatePager3();
	
	//Pager 4
	EDITBOX *pBaseMain_PAGERNUMBER_04;
	pBaseMain_PAGERNUMBER_04 = EbCreate(BaseMain_PAGERNUMBER_04,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_04text,16,editbox);
	if(pBaseMain_PAGERNUMBER_04==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_04;
	pBaseMain_NUMBERGUEST_04 = EbCreate(BaseMain_NUMBERGUEST_04,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_04text,2,editbox);
	if(pBaseMain_NUMBERGUEST_04==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_04;
	pBaseMain_PAGERACTIVATED_04 = EbCreate(BaseMain_PAGERACTIVATED_04,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_04text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_04==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_04;
	pBaseMain_PAGERCALLED_04 = EbCreate(BaseMain_PAGERCALLED_04,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_04text,3,editbox);
	if(pBaseMain_PAGERCALLED_04==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_04;
	pBaseMain_TABLENUMBER_04 = EbCreate(BaseMain_TABLENUMBER_04,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_04text,3,editbox);
	if(pBaseMain_TABLENUMBER_04==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_04;
	pBaseMain_ORDERFOOD_04 = EbCreate(BaseMain_ORDERFOOD_04,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_04text,3,editbox);
	if(pBaseMain_ORDERFOOD_04==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	

void CreatePager5(void)
{
	CreateBaseMain();
	
	//Pager 5
	EDITBOX *pBaseMain_PAGERNUMBER_05;
	pBaseMain_PAGERNUMBER_05 = EbCreate(BaseMain_PAGERNUMBER_05,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_05text,16,editbox);
	if(pBaseMain_PAGERNUMBER_05==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_05;
	pBaseMain_NUMBERGUEST_05 = EbCreate(BaseMain_NUMBERGUEST_05,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_05text,2,editbox);
	if(pBaseMain_NUMBERGUEST_05==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_05;
	pBaseMain_PAGERACTIVATED_05 = EbCreate(BaseMain_PAGERACTIVATED_05,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_05text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_05==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_05;
	pBaseMain_PAGERCALLED_05 = EbCreate(BaseMain_PAGERCALLED_05,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_05text,3,editbox);
	if(pBaseMain_PAGERCALLED_05==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_05;
	pBaseMain_TABLENUMBER_05 = EbCreate(BaseMain_TABLENUMBER_05,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_05text,3,editbox);
	if(pBaseMain_TABLENUMBER_05==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_05;
	pBaseMain_ORDERFOOD_05 = EbCreate(BaseMain_ORDERFOOD_05,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_05text,3,editbox);
	if(pBaseMain_ORDERFOOD_05==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}

void CreatePager6(void)
{
	CreatePager5();
	//Pager 6
EDITBOX *pBaseMain_PAGERNUMBER_06;	
	pBaseMain_PAGERNUMBER_06 = EbCreate(BaseMain_PAGERNUMBER_06,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_06text,16,editbox);
	if(pBaseMain_PAGERNUMBER_06==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_06;
	pBaseMain_NUMBERGUEST_06 = EbCreate(BaseMain_NUMBERGUEST_06,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_06text,2,editbox);
	if(pBaseMain_NUMBERGUEST_06==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_06;
	pBaseMain_PAGERACTIVATED_06 = EbCreate(BaseMain_PAGERACTIVATED_06,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_06text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_06==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_06;
	pBaseMain_PAGERCALLED_06 = EbCreate(BaseMain_PAGERCALLED_06,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_06text,3,editbox);
	if(pBaseMain_PAGERCALLED_06==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_06;
	pBaseMain_TABLENUMBER_06 = EbCreate(BaseMain_TABLENUMBER_06,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_06text,3,editbox);
	if(pBaseMain_TABLENUMBER_06==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_06;
	pBaseMain_ORDERFOOD_06 = EbCreate(BaseMain_ORDERFOOD_06,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_06text,3,editbox);
	if(pBaseMain_ORDERFOOD_06==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}

void CreatePager7(void)
{	
	//Create Pagers 1-6
	CreatePager6();
	//Pager 7
	EDITBOX *pBaseMain_PAGERNUMBER_07;
	pBaseMain_PAGERNUMBER_07 = EbCreate(BaseMain_PAGERNUMBER_07,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_07text,16,editbox);
	if(pBaseMain_PAGERNUMBER_07==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_07;
	pBaseMain_NUMBERGUEST_07 = EbCreate(BaseMain_NUMBERGUEST_07,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_07text,2,editbox);
	if(pBaseMain_NUMBERGUEST_07==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_07;
	pBaseMain_PAGERACTIVATED_07 = EbCreate(BaseMain_PAGERACTIVATED_07,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_07text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_07==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_07;
	pBaseMain_PAGERCALLED_07 = EbCreate(BaseMain_PAGERCALLED_07,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_07text,3,editbox);
	if(pBaseMain_PAGERCALLED_07==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_07;
	pBaseMain_TABLENUMBER_07 = EbCreate(BaseMain_TABLENUMBER_07,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_07text,3,editbox);
	if(pBaseMain_TABLENUMBER_07==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_07;
	pBaseMain_ORDERFOOD_07 = EbCreate(BaseMain_ORDERFOOD_07,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_07text,3,editbox);
	if(pBaseMain_ORDERFOOD_07==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}

void CreatePager8(void)
{
	//Create Pagers 1-7
	CreatePager7();
	
	//Pager 8
EDITBOX *pBaseMain_PAGERNUMBER_08;	
	pBaseMain_PAGERNUMBER_08 = EbCreate(BaseMain_PAGERNUMBER_08,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_08text,16,editbox);
	if(pBaseMain_PAGERNUMBER_08==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_08;
	pBaseMain_NUMBERGUEST_08 = EbCreate(BaseMain_NUMBERGUEST_08,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_08text,2,editbox);
	if(pBaseMain_NUMBERGUEST_08==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_08;
	pBaseMain_PAGERACTIVATED_08 = EbCreate(BaseMain_PAGERACTIVATED_08,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_08text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_08==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_08;
	pBaseMain_PAGERCALLED_08 = EbCreate(BaseMain_PAGERCALLED_08,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_08text,3,editbox);
	if(pBaseMain_PAGERCALLED_08==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_08;
	pBaseMain_TABLENUMBER_08 = EbCreate(BaseMain_TABLENUMBER_08,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_08text,3,editbox);
	if(pBaseMain_TABLENUMBER_08==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_08;
	pBaseMain_ORDERFOOD_08 = EbCreate(BaseMain_ORDERFOOD_08,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_08text,3,editbox);
	if(pBaseMain_ORDERFOOD_08==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}

void CreatePager9(void)
{
	CreatePager8();
	//Pager 9
	EDITBOX *pBaseMain_PAGERNUMBER_09;	
	pBaseMain_PAGERNUMBER_09 = EbCreate(BaseMain_PAGERNUMBER_09,Left,Top+4*VerticleShift,Right,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_09text,16,editbox);
	if(pBaseMain_PAGERNUMBER_09==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_09;
	pBaseMain_NUMBERGUEST_09 = EbCreate(BaseMain_NUMBERGUEST_09,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_09text,2,editbox);
	if(pBaseMain_NUMBERGUEST_09==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_09;
	pBaseMain_PAGERACTIVATED_09 = EbCreate(BaseMain_PAGERACTIVATED_09,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_09text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_09==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_09;
	pBaseMain_PAGERCALLED_09 = EbCreate(BaseMain_PAGERCALLED_09,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_09text,3,editbox);
	if(pBaseMain_PAGERCALLED_09==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_09;
	pBaseMain_TABLENUMBER_09 = EbCreate(BaseMain_TABLENUMBER_09,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_09text,3,editbox);
	if(pBaseMain_TABLENUMBER_09==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_09;
	pBaseMain_ORDERFOOD_09 = EbCreate(BaseMain_ORDERFOOD_09,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_09text,3,editbox);
	if(pBaseMain_ORDERFOOD_09==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}

void CreatePager10(void)		
{		
	//Creates Headers
	CreateBaseMain();	
	
	//Pager 10	
	EDITBOX *pBaseMain_PAGERNUMBER_10;	
	pBaseMain_PAGERNUMBER_10 = EbCreate(BaseMain_PAGERNUMBER_10,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_10text,16,editbox);	
	if(pBaseMain_PAGERNUMBER_10==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size	
	EDITBOX *pBaseMain_NUMBERGUEST_10;	
	pBaseMain_NUMBERGUEST_10 = EbCreate(BaseMain_NUMBERGUEST_10,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_10text,2,editbox);	
	if(pBaseMain_NUMBERGUEST_10==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size	
	EDITBOX *pBaseMain_PAGERACTIVATED_10;	
	pBaseMain_PAGERACTIVATED_10 = EbCreate(BaseMain_PAGERACTIVATED_10,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_10text,3,editbox);	
	if(pBaseMain_PAGERACTIVATED_10==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size	
	EDITBOX *pBaseMain_PAGERCALLED_10;	
	pBaseMain_PAGERCALLED_10 = EbCreate(BaseMain_PAGERCALLED_10,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_10text,3,editbox);	
	if(pBaseMain_PAGERCALLED_10==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size	
	EDITBOX *pBaseMain_TABLENUMBER_10;	
	pBaseMain_TABLENUMBER_10 = EbCreate(BaseMain_TABLENUMBER_10,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_10text,3,editbox);	
	if(pBaseMain_TABLENUMBER_10==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size	
	EDITBOX *pBaseMain_ORDERFOOD_10;	
	pBaseMain_ORDERFOOD_10 = EbCreate(BaseMain_ORDERFOOD_10,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_10text,3,editbox);	
	if(pBaseMain_ORDERFOOD_10==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size	
}		

void CreatePager11(void)	
{	
	//Create Pager 10
	CreatePager10();
	//Pager 11
	EDITBOX *pBaseMain_PAGERNUMBER_11;
	pBaseMain_PAGERNUMBER_11 = EbCreate(BaseMain_PAGERNUMBER_11,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_11text,16,editbox);
	if(pBaseMain_PAGERNUMBER_11==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_11;
	pBaseMain_NUMBERGUEST_11 = EbCreate(BaseMain_NUMBERGUEST_11,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_11text,2,editbox);
	if(pBaseMain_NUMBERGUEST_11==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_11;
	pBaseMain_PAGERACTIVATED_11 = EbCreate(BaseMain_PAGERACTIVATED_11,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_11text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_11==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_11;
	pBaseMain_PAGERCALLED_11 = EbCreate(BaseMain_PAGERCALLED_11,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_11text,3,editbox);
	if(pBaseMain_PAGERCALLED_11==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_11;
	pBaseMain_TABLENUMBER_11 = EbCreate(BaseMain_TABLENUMBER_11,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_11text,3,editbox);
	if(pBaseMain_TABLENUMBER_11==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_11;
	pBaseMain_ORDERFOOD_11 = EbCreate(BaseMain_ORDERFOOD_11,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_11text,3,editbox);
	if(pBaseMain_ORDERFOOD_11==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	

void CreatePager12(void)	
{	
	//Creat Pagers 10-11
	CreatePager11();
	//Pager 12
	EDITBOX *pBaseMain_PAGERNUMBER_12;	
	pBaseMain_PAGERNUMBER_12 = EbCreate(BaseMain_PAGERNUMBER_12,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_12text,16,editbox);
	if(pBaseMain_PAGERNUMBER_12==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_12;
	pBaseMain_NUMBERGUEST_12 = EbCreate(BaseMain_NUMBERGUEST_12,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_12text,2,editbox);
	if(pBaseMain_NUMBERGUEST_12==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_12;
	pBaseMain_PAGERACTIVATED_12 = EbCreate(BaseMain_PAGERACTIVATED_12,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_12text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_12==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_12;
	pBaseMain_PAGERCALLED_12 = EbCreate(BaseMain_PAGERCALLED_12,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_12text,3,editbox);
	if(pBaseMain_PAGERCALLED_12==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_12;
	pBaseMain_TABLENUMBER_12 = EbCreate(BaseMain_TABLENUMBER_12,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_12text,3,editbox);
	if(pBaseMain_TABLENUMBER_12==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_12;
	pBaseMain_ORDERFOOD_12 = EbCreate(BaseMain_ORDERFOOD_12,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_12text,3,editbox);
	if(pBaseMain_ORDERFOOD_12==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	

void CreatePager13(void)	
{	
	//Create Pagers 10-12
	CreatePager12();
	//Pager 13
	EDITBOX *pBaseMain_PAGERNUMBER_13;
	pBaseMain_PAGERNUMBER_13 = EbCreate(BaseMain_PAGERNUMBER_13,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_13text,16,editbox);
	if(pBaseMain_PAGERNUMBER_13==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_13;
	pBaseMain_NUMBERGUEST_13 = EbCreate(BaseMain_NUMBERGUEST_13,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_13text,2,editbox);
	if(pBaseMain_NUMBERGUEST_13==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_13;
	pBaseMain_PAGERACTIVATED_13 = EbCreate(BaseMain_PAGERACTIVATED_13,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_13text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_13==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_13;
	pBaseMain_PAGERCALLED_13 = EbCreate(BaseMain_PAGERCALLED_13,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_13text,3,editbox);
	if(pBaseMain_PAGERCALLED_13==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_13;
	pBaseMain_TABLENUMBER_13 = EbCreate(BaseMain_TABLENUMBER_13,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_13text,3,editbox);
	if(pBaseMain_TABLENUMBER_13==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_13;
	pBaseMain_ORDERFOOD_13 = EbCreate(BaseMain_ORDERFOOD_13,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_13text,3,editbox);
	if(pBaseMain_ORDERFOOD_13==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	

void CreatePager14(void)	
{	
	//Create Pagers 10-13
	CreatePager13();
	//Pager 14
	EDITBOX *pBaseMain_PAGERNUMBER_14;	
	pBaseMain_PAGERNUMBER_14 = EbCreate(BaseMain_PAGERNUMBER_14,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_14text,16,editbox);
	if(pBaseMain_PAGERNUMBER_14==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_14;
	pBaseMain_NUMBERGUEST_14 = EbCreate(BaseMain_NUMBERGUEST_14,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_14text,2,editbox);
	if(pBaseMain_NUMBERGUEST_14==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_14;
	pBaseMain_PAGERACTIVATED_14 = EbCreate(BaseMain_PAGERACTIVATED_14,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_14text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_14==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_14;
	pBaseMain_PAGERCALLED_14 = EbCreate(BaseMain_PAGERCALLED_14,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_14text,3,editbox);
	if(pBaseMain_PAGERCALLED_14==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_14;
	pBaseMain_TABLENUMBER_14 = EbCreate(BaseMain_TABLENUMBER_14,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_14text,3,editbox);
	if(pBaseMain_TABLENUMBER_14==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_14;
	pBaseMain_ORDERFOOD_14 = EbCreate(BaseMain_ORDERFOOD_14,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_14text,3,editbox);
	if(pBaseMain_ORDERFOOD_14==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	

void CreatePager15(void)
{
	
	//Create Headers
	CreateBaseMain();
	//Pager 15
	EDITBOX *pBaseMain_PAGERNUMBER_15;	
	pBaseMain_PAGERNUMBER_15 = EbCreate(BaseMain_PAGERNUMBER_15,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_15text,16,editbox);
	if(pBaseMain_PAGERNUMBER_15==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_15;
	pBaseMain_NUMBERGUEST_15 = EbCreate(BaseMain_NUMBERGUEST_15,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_15text,2,editbox);
	if(pBaseMain_NUMBERGUEST_15==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_15;
	pBaseMain_PAGERACTIVATED_15 = EbCreate(BaseMain_PAGERACTIVATED_15,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_15text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_15==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_15;
	pBaseMain_PAGERCALLED_15 = EbCreate(BaseMain_PAGERCALLED_15,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_15text,3,editbox);
	if(pBaseMain_PAGERCALLED_15==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_15;
	pBaseMain_TABLENUMBER_15 = EbCreate(BaseMain_TABLENUMBER_15,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_15text,3,editbox);
	if(pBaseMain_TABLENUMBER_15==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_15;
	pBaseMain_ORDERFOOD_15 = EbCreate(BaseMain_ORDERFOOD_15,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_15text,3,editbox);
	if(pBaseMain_ORDERFOOD_15==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}
	
void CreatePager16(void)
{
	//Create Pager 15
	CreatePager15();
	//Pager 16
	EDITBOX *pBaseMain_PAGERNUMBER_16;	
	pBaseMain_PAGERNUMBER_16 = EbCreate(BaseMain_PAGERNUMBER_16,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_16text,16,editbox);
	if(pBaseMain_PAGERNUMBER_16==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_16;
	pBaseMain_NUMBERGUEST_16 = EbCreate(BaseMain_NUMBERGUEST_16,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_16text,2,editbox);
	if(pBaseMain_NUMBERGUEST_16==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_16;
	pBaseMain_PAGERACTIVATED_16 = EbCreate(BaseMain_PAGERACTIVATED_16,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_16text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_16==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_16;
	pBaseMain_PAGERCALLED_16 = EbCreate(BaseMain_PAGERCALLED_16,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_16text,3,editbox);
	if(pBaseMain_PAGERCALLED_16==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_16;
	pBaseMain_TABLENUMBER_16 = EbCreate(BaseMain_TABLENUMBER_16,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_16text,3,editbox);
	if(pBaseMain_TABLENUMBER_16==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_16;
	pBaseMain_ORDERFOOD_16 = EbCreate(BaseMain_ORDERFOOD_16,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_16text,3,editbox);
	if(pBaseMain_ORDERFOOD_16==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}

void CreatePager17(void)
{
	//Creates Pagers 15-16
	CreatePager16();
	
	//Pager 17
	EDITBOX *pBaseMain_PAGERNUMBER_17;	
	pBaseMain_PAGERNUMBER_17 = EbCreate(BaseMain_PAGERNUMBER_17,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_17text,16,editbox);
	if(pBaseMain_PAGERNUMBER_17==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_17;
	pBaseMain_NUMBERGUEST_17 = EbCreate(BaseMain_NUMBERGUEST_17,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_17text,2,editbox);
	if(pBaseMain_NUMBERGUEST_17==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_17;
	pBaseMain_PAGERACTIVATED_17 = EbCreate(BaseMain_PAGERACTIVATED_17,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_17text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_17==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_17;
	pBaseMain_PAGERCALLED_17 = EbCreate(BaseMain_PAGERCALLED_17,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_17text,3,editbox);
	if(pBaseMain_PAGERCALLED_17==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_17;
	pBaseMain_TABLENUMBER_17 = EbCreate(BaseMain_TABLENUMBER_17,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_17text,3,editbox);
	if(pBaseMain_TABLENUMBER_17==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_17;
	pBaseMain_ORDERFOOD_17 = EbCreate(BaseMain_ORDERFOOD_17,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_17text,3,editbox);
	if(pBaseMain_ORDERFOOD_17==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}

void CreatePager18(void)
{
	
	CreatePager17();
	//Pager 18
	EDITBOX *pBaseMain_PAGERNUMBER_18;	
	pBaseMain_PAGERNUMBER_18 = EbCreate(BaseMain_PAGERNUMBER_18,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_18text,16,editbox);
	if(pBaseMain_PAGERNUMBER_18==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_18;
	pBaseMain_NUMBERGUEST_18 = EbCreate(BaseMain_NUMBERGUEST_18,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_18text,2,editbox);
	if(pBaseMain_NUMBERGUEST_18==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_18;
	pBaseMain_PAGERACTIVATED_18 = EbCreate(BaseMain_PAGERACTIVATED_18,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_18text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_18==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_18;
	pBaseMain_PAGERCALLED_18 = EbCreate(BaseMain_PAGERCALLED_18,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_18text,3,editbox);
	if(pBaseMain_PAGERCALLED_18==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_18;
	pBaseMain_TABLENUMBER_18 = EbCreate(BaseMain_TABLENUMBER_18,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_18text,3,editbox);
	if(pBaseMain_TABLENUMBER_18==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_18;
	pBaseMain_ORDERFOOD_18 = EbCreate(BaseMain_ORDERFOOD_18,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_18text,3,editbox);
	if(pBaseMain_ORDERFOOD_18==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}

void CreatePager19(void)
{
	
	
	CreatePager18();
	//Pager 19
	EDITBOX *pBaseMain_PAGERNUMBER_19;	
	pBaseMain_PAGERNUMBER_19 = EbCreate(BaseMain_PAGERNUMBER_19,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_19text,16,editbox);
	if(pBaseMain_PAGERNUMBER_19==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_19;
	pBaseMain_NUMBERGUEST_19 = EbCreate(BaseMain_NUMBERGUEST_19,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_19text,2,editbox);
	if(pBaseMain_NUMBERGUEST_19==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_19;
	pBaseMain_PAGERACTIVATED_19 = EbCreate(BaseMain_PAGERACTIVATED_19,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_19text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_19==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_19;
	pBaseMain_PAGERCALLED_19 = EbCreate(BaseMain_PAGERCALLED_19,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_19text,3,editbox);
	if(pBaseMain_PAGERCALLED_19==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_19;
	pBaseMain_TABLENUMBER_19 = EbCreate(BaseMain_TABLENUMBER_19,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_19text,3,editbox);
	if(pBaseMain_TABLENUMBER_19==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_19;
	pBaseMain_ORDERFOOD_19 = EbCreate(BaseMain_ORDERFOOD_19,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_19text,3,editbox);
	if(pBaseMain_ORDERFOOD_19==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}

void CreatePager20(void)	
{	
	
	
	CreateBaseMain();
	
	//Pager 20
	EDITBOX *pBaseMain_PAGERNUMBER_20;
	pBaseMain_PAGERNUMBER_20 = EbCreate(BaseMain_PAGERNUMBER_20,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_20text,16,editbox);
	if(pBaseMain_PAGERNUMBER_20==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_20;
	pBaseMain_NUMBERGUEST_20 = EbCreate(BaseMain_NUMBERGUEST_20,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_20text,2,editbox);
	if(pBaseMain_NUMBERGUEST_20==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_20;
	pBaseMain_PAGERACTIVATED_20 = EbCreate(BaseMain_PAGERACTIVATED_20,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_20text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_20==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_20;
	pBaseMain_PAGERCALLED_20 = EbCreate(BaseMain_PAGERCALLED_20,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_20text,3,editbox);
	if(pBaseMain_PAGERCALLED_20==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_20;
	pBaseMain_TABLENUMBER_20 = EbCreate(BaseMain_TABLENUMBER_20,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_20text,3,editbox);
	if(pBaseMain_TABLENUMBER_20==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_20;
	pBaseMain_ORDERFOOD_20 = EbCreate(BaseMain_ORDERFOOD_20,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_20text,3,editbox);
	if(pBaseMain_ORDERFOOD_20==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager21(void)	
{	
	
	CreatePager20();
	//Pager 21
	EDITBOX *pBaseMain_PAGERNUMBER_21;
	pBaseMain_PAGERNUMBER_21 = EbCreate(BaseMain_PAGERNUMBER_21,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_21text,16,editbox);
	if(pBaseMain_PAGERNUMBER_21==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_21;
	pBaseMain_NUMBERGUEST_21 = EbCreate(BaseMain_NUMBERGUEST_21,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_21text,2,editbox);
	if(pBaseMain_NUMBERGUEST_21==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_21;
	pBaseMain_PAGERACTIVATED_21 = EbCreate(BaseMain_PAGERACTIVATED_21,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_21text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_21==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_21;
	pBaseMain_PAGERCALLED_21 = EbCreate(BaseMain_PAGERCALLED_21,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_21text,3,editbox);
	if(pBaseMain_PAGERCALLED_21==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_21;
	pBaseMain_TABLENUMBER_21 = EbCreate(BaseMain_TABLENUMBER_21,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_21text,3,editbox);
	if(pBaseMain_TABLENUMBER_21==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_21;
	pBaseMain_ORDERFOOD_21 = EbCreate(BaseMain_ORDERFOOD_21,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_21text,3,editbox);
	if(pBaseMain_ORDERFOOD_21==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager22(void)	
{	
	
	CreatePager21();
	//Pager 22
	EDITBOX *pBaseMain_PAGERNUMBER_22;
	pBaseMain_PAGERNUMBER_22 = EbCreate(BaseMain_PAGERNUMBER_22,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_22text,16,editbox);
	if(pBaseMain_PAGERNUMBER_22==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_22;
	pBaseMain_NUMBERGUEST_22 = EbCreate(BaseMain_NUMBERGUEST_22,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_22text,2,editbox);
	if(pBaseMain_NUMBERGUEST_22==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_22;
	pBaseMain_PAGERACTIVATED_22 = EbCreate(BaseMain_PAGERACTIVATED_22,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_22text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_22==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_22;
	pBaseMain_PAGERCALLED_22 = EbCreate(BaseMain_PAGERCALLED_22,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_22text,3,editbox);
	if(pBaseMain_PAGERCALLED_22==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_22;
	pBaseMain_TABLENUMBER_22 = EbCreate(BaseMain_TABLENUMBER_22,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_22text,3,editbox);
	if(pBaseMain_TABLENUMBER_22==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_22;
	pBaseMain_ORDERFOOD_22 = EbCreate(BaseMain_ORDERFOOD_22,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_22text,3,editbox);
	if(pBaseMain_ORDERFOOD_22==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	

void CreatePager23(void)	
{	
	
	CreatePager22();
	
	//Pager 23
	EDITBOX *pBaseMain_PAGERNUMBER_23;
	pBaseMain_PAGERNUMBER_23 = EbCreate(BaseMain_PAGERNUMBER_23,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_23text,16,editbox);
	if(pBaseMain_PAGERNUMBER_23==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_23;
	pBaseMain_NUMBERGUEST_23 = EbCreate(BaseMain_NUMBERGUEST_23,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_23text,2,editbox);
	if(pBaseMain_NUMBERGUEST_23==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_23;
	pBaseMain_PAGERACTIVATED_23 = EbCreate(BaseMain_PAGERACTIVATED_23,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_23text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_23==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_23;
	pBaseMain_PAGERCALLED_23 = EbCreate(BaseMain_PAGERCALLED_23,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_23text,3,editbox);
	if(pBaseMain_PAGERCALLED_23==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_23;
	pBaseMain_TABLENUMBER_23 = EbCreate(BaseMain_TABLENUMBER_23,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_23text,3,editbox);
	if(pBaseMain_TABLENUMBER_23==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_23;
	pBaseMain_ORDERFOOD_23 = EbCreate(BaseMain_ORDERFOOD_23,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_23text,3,editbox);
	if(pBaseMain_ORDERFOOD_23==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	

void CreatePager24(void)	
{	
	
	CreatePager23();
	
	//Pager 24
	EDITBOX *pBaseMain_PAGERNUMBER_24;
	pBaseMain_PAGERNUMBER_24 = EbCreate(BaseMain_PAGERNUMBER_24,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_24text,16,editbox);
	if(pBaseMain_PAGERNUMBER_24==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_24;
	pBaseMain_NUMBERGUEST_24 = EbCreate(BaseMain_NUMBERGUEST_24,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_24text,2,editbox);
	if(pBaseMain_NUMBERGUEST_24==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_24;
	pBaseMain_PAGERACTIVATED_24 = EbCreate(BaseMain_PAGERACTIVATED_24,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_24text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_24==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_24;
	pBaseMain_PAGERCALLED_24 = EbCreate(BaseMain_PAGERCALLED_24,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_24text,3,editbox);
	if(pBaseMain_PAGERCALLED_24==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_24;
	pBaseMain_TABLENUMBER_24 = EbCreate(BaseMain_TABLENUMBER_24,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_24text,3,editbox);
	if(pBaseMain_TABLENUMBER_24==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_24;
	pBaseMain_ORDERFOOD_24 = EbCreate(BaseMain_ORDERFOOD_24,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_24text,3,editbox);
	if(pBaseMain_ORDERFOOD_24==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
void CreatePager25(void)	
{	
	
	CreateBaseMain();
	//Pager 25
	EDITBOX *pBaseMain_PAGERNUMBER_25;
	pBaseMain_PAGERNUMBER_25 = EbCreate(BaseMain_PAGERNUMBER_25,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_25text,16,editbox);
	if(pBaseMain_PAGERNUMBER_25==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_25;
	pBaseMain_NUMBERGUEST_25 = EbCreate(BaseMain_NUMBERGUEST_25,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_25text,2,editbox);
	if(pBaseMain_NUMBERGUEST_25==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_25;
	pBaseMain_PAGERACTIVATED_25 = EbCreate(BaseMain_PAGERACTIVATED_25,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_25text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_25==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_25;
	pBaseMain_PAGERCALLED_25 = EbCreate(BaseMain_PAGERCALLED_25,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_25text,3,editbox);
	if(pBaseMain_PAGERCALLED_25==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_25;
	pBaseMain_TABLENUMBER_25 = EbCreate(BaseMain_TABLENUMBER_25,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_25text,3,editbox);
	if(pBaseMain_TABLENUMBER_25==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_25;
	pBaseMain_ORDERFOOD_25 = EbCreate(BaseMain_ORDERFOOD_25,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_25text,3,editbox);
	if(pBaseMain_ORDERFOOD_25==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager26(void)	
{	
	
	CreatePager25();
	//Pager 26
	EDITBOX *pBaseMain_PAGERNUMBER_26;
	pBaseMain_PAGERNUMBER_26 = EbCreate(BaseMain_PAGERNUMBER_26,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_26text,16,editbox);
	if(pBaseMain_PAGERNUMBER_26==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_26;
	pBaseMain_NUMBERGUEST_26 = EbCreate(BaseMain_NUMBERGUEST_26,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_26text,2,editbox);
	if(pBaseMain_NUMBERGUEST_26==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_26;
	pBaseMain_PAGERACTIVATED_26 = EbCreate(BaseMain_PAGERACTIVATED_26,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_26text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_26==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_26;
	pBaseMain_PAGERCALLED_26 = EbCreate(BaseMain_PAGERCALLED_26,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_26text,3,editbox);
	if(pBaseMain_PAGERCALLED_26==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_26;
	pBaseMain_TABLENUMBER_26 = EbCreate(BaseMain_TABLENUMBER_26,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_26text,3,editbox);
	if(pBaseMain_TABLENUMBER_26==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_26;
	pBaseMain_ORDERFOOD_26 = EbCreate(BaseMain_ORDERFOOD_26,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_26text,3,editbox);
	if(pBaseMain_ORDERFOOD_26==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager27(void)	
{	
	
	CreatePager26();	//Pager 27
	EDITBOX *pBaseMain_PAGERNUMBER_27;
	pBaseMain_PAGERNUMBER_27 = EbCreate(BaseMain_PAGERNUMBER_27,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_27text,16,editbox);
	if(pBaseMain_PAGERNUMBER_27==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_27;
	pBaseMain_NUMBERGUEST_27 = EbCreate(BaseMain_NUMBERGUEST_27,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_27text,2,editbox);
	if(pBaseMain_NUMBERGUEST_27==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_27;
	pBaseMain_PAGERACTIVATED_27 = EbCreate(BaseMain_PAGERACTIVATED_27,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_27text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_27==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_27;
	pBaseMain_PAGERCALLED_27 = EbCreate(BaseMain_PAGERCALLED_27,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_27text,3,editbox);
	if(pBaseMain_PAGERCALLED_27==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_27;
	pBaseMain_TABLENUMBER_27 = EbCreate(BaseMain_TABLENUMBER_27,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_27text,3,editbox);
	if(pBaseMain_TABLENUMBER_27==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_27;
	pBaseMain_ORDERFOOD_27 = EbCreate(BaseMain_ORDERFOOD_27,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_27text,3,editbox);
	if(pBaseMain_ORDERFOOD_27==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager28(void)	
{	
	CreatePager27();
	//Pager 28
	EDITBOX *pBaseMain_PAGERNUMBER_28;
	pBaseMain_PAGERNUMBER_28 = EbCreate(BaseMain_PAGERNUMBER_28,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_28text,16,editbox);
	if(pBaseMain_PAGERNUMBER_28==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_28;
	pBaseMain_NUMBERGUEST_28 = EbCreate(BaseMain_NUMBERGUEST_28,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_28text,2,editbox);
	if(pBaseMain_NUMBERGUEST_28==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_28;
	pBaseMain_PAGERACTIVATED_28 = EbCreate(BaseMain_PAGERACTIVATED_28,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_28text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_28==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_28;
	pBaseMain_PAGERCALLED_28 = EbCreate(BaseMain_PAGERCALLED_28,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_28text,3,editbox);
	if(pBaseMain_PAGERCALLED_28==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_28;
	pBaseMain_TABLENUMBER_28 = EbCreate(BaseMain_TABLENUMBER_28,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_28text,3,editbox);
	if(pBaseMain_TABLENUMBER_28==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_28;
	pBaseMain_ORDERFOOD_28 = EbCreate(BaseMain_ORDERFOOD_28,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_28text,3,editbox);
	if(pBaseMain_ORDERFOOD_28==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager29(void)	
{	
	
	CreatePager28();
	//Pager 29
	EDITBOX *pBaseMain_PAGERNUMBER_29;
	pBaseMain_PAGERNUMBER_29 = EbCreate(BaseMain_PAGERNUMBER_29,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_29text,16,editbox);
	if(pBaseMain_PAGERNUMBER_29==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_29;
	pBaseMain_NUMBERGUEST_29 = EbCreate(BaseMain_NUMBERGUEST_29,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_29text,2,editbox);
	if(pBaseMain_NUMBERGUEST_29==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_29;
	pBaseMain_PAGERACTIVATED_29 = EbCreate(BaseMain_PAGERACTIVATED_29,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_29text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_29==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_29;
	pBaseMain_PAGERCALLED_29 = EbCreate(BaseMain_PAGERCALLED_29,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_29text,3,editbox);
	if(pBaseMain_PAGERCALLED_29==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_29;
	pBaseMain_TABLENUMBER_29 = EbCreate(BaseMain_TABLENUMBER_29,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_29text,3,editbox);
	if(pBaseMain_TABLENUMBER_29==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_29;
	pBaseMain_ORDERFOOD_29 = EbCreate(BaseMain_ORDERFOOD_29,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_29text,3,editbox);
	if(pBaseMain_ORDERFOOD_29==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
void CreatePager30(void)	
{		
	//Pager 30
	CreateBaseMain();
	EDITBOX *pBaseMain_PAGERNUMBER_30;
	pBaseMain_PAGERNUMBER_30 = EbCreate(BaseMain_PAGERNUMBER_30,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_30text,16,editbox);
	if(pBaseMain_PAGERNUMBER_30==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_30;
	pBaseMain_NUMBERGUEST_30 = EbCreate(BaseMain_NUMBERGUEST_30,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_30text,2,editbox);
	if(pBaseMain_NUMBERGUEST_30==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_30;
	pBaseMain_PAGERACTIVATED_30 = EbCreate(BaseMain_PAGERACTIVATED_30,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_30text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_30==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_30;
	pBaseMain_PAGERCALLED_30 = EbCreate(BaseMain_PAGERCALLED_30,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_30text,3,editbox);
	if(pBaseMain_PAGERCALLED_30==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_30;
	pBaseMain_TABLENUMBER_30 = EbCreate(BaseMain_TABLENUMBER_30,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_30text,3,editbox);
	if(pBaseMain_TABLENUMBER_30==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_30;
	pBaseMain_ORDERFOOD_30 = EbCreate(BaseMain_ORDERFOOD_30,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_30text,3,editbox);
	if(pBaseMain_ORDERFOOD_30==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager31(void)	
{	
	
	CreatePager30();	//Pager 31
	EDITBOX *pBaseMain_PAGERNUMBER_31;
	pBaseMain_PAGERNUMBER_31 = EbCreate(BaseMain_PAGERNUMBER_31,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_31text,16,editbox);
	if(pBaseMain_PAGERNUMBER_31==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_31;
	pBaseMain_NUMBERGUEST_31 = EbCreate(BaseMain_NUMBERGUEST_31,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_31text,2,editbox);
	if(pBaseMain_NUMBERGUEST_31==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_31;
	pBaseMain_PAGERACTIVATED_31 = EbCreate(BaseMain_PAGERACTIVATED_31,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_31text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_31==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_31;
	pBaseMain_PAGERCALLED_31 = EbCreate(BaseMain_PAGERCALLED_31,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_31text,3,editbox);
	if(pBaseMain_PAGERCALLED_31==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_31;
	pBaseMain_TABLENUMBER_31 = EbCreate(BaseMain_TABLENUMBER_31,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_31text,3,editbox);
	if(pBaseMain_TABLENUMBER_31==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_31;
	pBaseMain_ORDERFOOD_31 = EbCreate(BaseMain_ORDERFOOD_31,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_31text,3,editbox);
	if(pBaseMain_ORDERFOOD_31==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager32(void)	
{	
	
	CreatePager31();
	
	//Pager 32
	EDITBOX *pBaseMain_PAGERNUMBER_32;
	pBaseMain_PAGERNUMBER_32 = EbCreate(BaseMain_PAGERNUMBER_32,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_32text,16,editbox);
	if(pBaseMain_PAGERNUMBER_32==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_32;
	pBaseMain_NUMBERGUEST_32 = EbCreate(BaseMain_NUMBERGUEST_32,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_32text,2,editbox);
	if(pBaseMain_NUMBERGUEST_32==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_32;
	pBaseMain_PAGERACTIVATED_32 = EbCreate(BaseMain_PAGERACTIVATED_32,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_32text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_32==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_32;
	pBaseMain_PAGERCALLED_32 = EbCreate(BaseMain_PAGERCALLED_32,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_32text,3,editbox);
	if(pBaseMain_PAGERCALLED_32==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_32;
	pBaseMain_TABLENUMBER_32 = EbCreate(BaseMain_TABLENUMBER_32,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_32text,3,editbox);
	if(pBaseMain_TABLENUMBER_32==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_32;
	pBaseMain_ORDERFOOD_32 = EbCreate(BaseMain_ORDERFOOD_32,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_32text,3,editbox);
	if(pBaseMain_ORDERFOOD_32==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager33(void)	
{	
	
	CreatePager32();
	//Pager 33
	EDITBOX *pBaseMain_PAGERNUMBER_33;
	pBaseMain_PAGERNUMBER_33 = EbCreate(BaseMain_PAGERNUMBER_33,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_33text,16,editbox);
	if(pBaseMain_PAGERNUMBER_33==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_33;
	pBaseMain_NUMBERGUEST_33 = EbCreate(BaseMain_NUMBERGUEST_33,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_33text,2,editbox);
	if(pBaseMain_NUMBERGUEST_33==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_33;
	pBaseMain_PAGERACTIVATED_33 = EbCreate(BaseMain_PAGERACTIVATED_33,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_33text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_33==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_33;
	pBaseMain_PAGERCALLED_33 = EbCreate(BaseMain_PAGERCALLED_33,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_33text,3,editbox);
	if(pBaseMain_PAGERCALLED_33==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_33;
	pBaseMain_TABLENUMBER_33 = EbCreate(BaseMain_TABLENUMBER_33,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_33text,3,editbox);
	if(pBaseMain_TABLENUMBER_33==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_33;
	pBaseMain_ORDERFOOD_33 = EbCreate(BaseMain_ORDERFOOD_33,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_33text,3,editbox);
	if(pBaseMain_ORDERFOOD_33==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager34(void)	
{	
	
	CreatePager33();
	//Pager 34
	EDITBOX *pBaseMain_PAGERNUMBER_34;
	pBaseMain_PAGERNUMBER_34 = EbCreate(BaseMain_PAGERNUMBER_34,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_34text,16,editbox);
	if(pBaseMain_PAGERNUMBER_34==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_34;
	pBaseMain_NUMBERGUEST_34 = EbCreate(BaseMain_NUMBERGUEST_34,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_34text,2,editbox);
	if(pBaseMain_NUMBERGUEST_34==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_34;
	pBaseMain_PAGERACTIVATED_34 = EbCreate(BaseMain_PAGERACTIVATED_34,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_34text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_34==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_34;
	pBaseMain_PAGERCALLED_34 = EbCreate(BaseMain_PAGERCALLED_34,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_34text,3,editbox);
	if(pBaseMain_PAGERCALLED_34==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_34;
	pBaseMain_TABLENUMBER_34 = EbCreate(BaseMain_TABLENUMBER_34,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_34text,3,editbox);
	if(pBaseMain_TABLENUMBER_34==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_34;
	pBaseMain_ORDERFOOD_34 = EbCreate(BaseMain_ORDERFOOD_34,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_34text,3,editbox);
	if(pBaseMain_ORDERFOOD_34==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
void CreatePager35(void)	
{	
	
	CreateBaseMain();	
	//Pager 35
	EDITBOX *pBaseMain_PAGERNUMBER_35;
	pBaseMain_PAGERNUMBER_35 = EbCreate(BaseMain_PAGERNUMBER_35,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_35text,16,editbox);
	if(pBaseMain_PAGERNUMBER_35==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_35;
	pBaseMain_NUMBERGUEST_35 = EbCreate(BaseMain_NUMBERGUEST_35,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_35text,2,editbox);
	if(pBaseMain_NUMBERGUEST_35==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_35;
	pBaseMain_PAGERACTIVATED_35 = EbCreate(BaseMain_PAGERACTIVATED_35,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_35text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_35==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_35;
	pBaseMain_PAGERCALLED_35 = EbCreate(BaseMain_PAGERCALLED_35,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_35text,3,editbox);
	if(pBaseMain_PAGERCALLED_35==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_35;
	pBaseMain_TABLENUMBER_35 = EbCreate(BaseMain_TABLENUMBER_35,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_35text,3,editbox);
	if(pBaseMain_TABLENUMBER_35==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_35;
	pBaseMain_ORDERFOOD_35 = EbCreate(BaseMain_ORDERFOOD_35,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_35text,3,editbox);
	if(pBaseMain_ORDERFOOD_35==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager36(void)	
{	
	
	CreatePager35();
	//Pager 36
	EDITBOX *pBaseMain_PAGERNUMBER_36;
	pBaseMain_PAGERNUMBER_36 = EbCreate(BaseMain_PAGERNUMBER_36,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_36text,16,editbox);
	if(pBaseMain_PAGERNUMBER_36==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_36;
	pBaseMain_NUMBERGUEST_36 = EbCreate(BaseMain_NUMBERGUEST_36,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_36text,2,editbox);
	if(pBaseMain_NUMBERGUEST_36==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_36;
	pBaseMain_PAGERACTIVATED_36 = EbCreate(BaseMain_PAGERACTIVATED_36,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_36text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_36==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_36;
	pBaseMain_PAGERCALLED_36 = EbCreate(BaseMain_PAGERCALLED_36,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_36text,3,editbox);
	if(pBaseMain_PAGERCALLED_36==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_36;
	pBaseMain_TABLENUMBER_36 = EbCreate(BaseMain_TABLENUMBER_36,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_36text,3,editbox);
	if(pBaseMain_TABLENUMBER_36==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_36;
	pBaseMain_ORDERFOOD_36 = EbCreate(BaseMain_ORDERFOOD_36,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_36text,3,editbox);
	if(pBaseMain_ORDERFOOD_36==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager37(void)	
{	
	
	CreatePager36();
	//Pager 37
	EDITBOX *pBaseMain_PAGERNUMBER_37;
	pBaseMain_PAGERNUMBER_37 = EbCreate(BaseMain_PAGERNUMBER_37,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_37text,16,editbox);
	if(pBaseMain_PAGERNUMBER_37==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_37;
	pBaseMain_NUMBERGUEST_37 = EbCreate(BaseMain_NUMBERGUEST_37,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_37text,2,editbox);
	if(pBaseMain_NUMBERGUEST_37==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_37;
	pBaseMain_PAGERACTIVATED_37 = EbCreate(BaseMain_PAGERACTIVATED_37,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_37text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_37==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_37;
	pBaseMain_PAGERCALLED_37 = EbCreate(BaseMain_PAGERCALLED_37,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_37text,3,editbox);
	if(pBaseMain_PAGERCALLED_37==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_37;
	pBaseMain_TABLENUMBER_37 = EbCreate(BaseMain_TABLENUMBER_37,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_37text,3,editbox);
	if(pBaseMain_TABLENUMBER_37==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_37;
	pBaseMain_ORDERFOOD_37 = EbCreate(BaseMain_ORDERFOOD_37,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_37text,3,editbox);
	if(pBaseMain_ORDERFOOD_37==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager38(void)	
{	
	
	CreatePager37();
	
	//Pager 38
	EDITBOX *pBaseMain_PAGERNUMBER_38;
	pBaseMain_PAGERNUMBER_38 = EbCreate(BaseMain_PAGERNUMBER_38,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_38text,16,editbox);
	if(pBaseMain_PAGERNUMBER_38==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_38;
	pBaseMain_NUMBERGUEST_38 = EbCreate(BaseMain_NUMBERGUEST_38,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_38text,2,editbox);
	if(pBaseMain_NUMBERGUEST_38==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_38;
	pBaseMain_PAGERACTIVATED_38 = EbCreate(BaseMain_PAGERACTIVATED_38,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_38text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_38==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_38;
	pBaseMain_PAGERCALLED_38 = EbCreate(BaseMain_PAGERCALLED_38,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_38text,3,editbox);
	if(pBaseMain_PAGERCALLED_38==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_38;
	pBaseMain_TABLENUMBER_38 = EbCreate(BaseMain_TABLENUMBER_38,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_38text,3,editbox);
	if(pBaseMain_TABLENUMBER_38==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_38;
	pBaseMain_ORDERFOOD_38 = EbCreate(BaseMain_ORDERFOOD_38,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_38text,3,editbox);
	if(pBaseMain_ORDERFOOD_38==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager39(void)	
{	
	
	CreatePager38();
	//Pager 39
	EDITBOX *pBaseMain_PAGERNUMBER_39;
	pBaseMain_PAGERNUMBER_39 = EbCreate(BaseMain_PAGERNUMBER_39,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_39text,16,editbox);
	if(pBaseMain_PAGERNUMBER_39==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_39;
	pBaseMain_NUMBERGUEST_39 = EbCreate(BaseMain_NUMBERGUEST_39,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_39text,2,editbox);
	if(pBaseMain_NUMBERGUEST_39==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_39;
	pBaseMain_PAGERACTIVATED_39 = EbCreate(BaseMain_PAGERACTIVATED_39,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_39text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_39==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_39;
	pBaseMain_PAGERCALLED_39 = EbCreate(BaseMain_PAGERCALLED_39,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_39text,3,editbox);
	if(pBaseMain_PAGERCALLED_39==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_39;
	pBaseMain_TABLENUMBER_39 = EbCreate(BaseMain_TABLENUMBER_39,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_39text,3,editbox);
	if(pBaseMain_TABLENUMBER_39==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_39;
	pBaseMain_ORDERFOOD_39 = EbCreate(BaseMain_ORDERFOOD_39,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_39text,3,editbox);
	if(pBaseMain_ORDERFOOD_39==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
void CreatePager40(void)	
{	
	
	CreateBaseMain();	
	
	//Pager 40
	EDITBOX *pBaseMain_PAGERNUMBER_40;
	pBaseMain_PAGERNUMBER_40 = EbCreate(BaseMain_PAGERNUMBER_40,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_40text,16,editbox);
	if(pBaseMain_PAGERNUMBER_40==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_40;
	pBaseMain_NUMBERGUEST_40 = EbCreate(BaseMain_NUMBERGUEST_40,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_40text,2,editbox);
	if(pBaseMain_NUMBERGUEST_40==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_40;
	pBaseMain_PAGERACTIVATED_40 = EbCreate(BaseMain_PAGERACTIVATED_40,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_40text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_40==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_40;
	pBaseMain_PAGERCALLED_40 = EbCreate(BaseMain_PAGERCALLED_40,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_40text,3,editbox);
	if(pBaseMain_PAGERCALLED_40==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_40;
	pBaseMain_TABLENUMBER_40 = EbCreate(BaseMain_TABLENUMBER_40,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_40text,3,editbox);
	if(pBaseMain_TABLENUMBER_40==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_40;
	pBaseMain_ORDERFOOD_40 = EbCreate(BaseMain_ORDERFOOD_40,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_40text,3,editbox);
	if(pBaseMain_ORDERFOOD_40==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager41(void)	
{	
	
	CreatePager40();
	//Pager 41
	EDITBOX *pBaseMain_PAGERNUMBER_41;
	pBaseMain_PAGERNUMBER_41 = EbCreate(BaseMain_PAGERNUMBER_41,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_41text,16,editbox);
	if(pBaseMain_PAGERNUMBER_41==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_41;
	pBaseMain_NUMBERGUEST_41 = EbCreate(BaseMain_NUMBERGUEST_41,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_41text,2,editbox);
	if(pBaseMain_NUMBERGUEST_41==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_41;
	pBaseMain_PAGERACTIVATED_41 = EbCreate(BaseMain_PAGERACTIVATED_41,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_41text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_41==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_41;
	pBaseMain_PAGERCALLED_41 = EbCreate(BaseMain_PAGERCALLED_41,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_41text,3,editbox);
	if(pBaseMain_PAGERCALLED_41==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_41;
	pBaseMain_TABLENUMBER_41 = EbCreate(BaseMain_TABLENUMBER_41,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_41text,3,editbox);
	if(pBaseMain_TABLENUMBER_41==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_41;
	pBaseMain_ORDERFOOD_41 = EbCreate(BaseMain_ORDERFOOD_41,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_41text,3,editbox);
	if(pBaseMain_ORDERFOOD_41==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager42(void)	
{	
	
	CreatePager41();
	//Pager 42
	EDITBOX *pBaseMain_PAGERNUMBER_42;
	pBaseMain_PAGERNUMBER_42 = EbCreate(BaseMain_PAGERNUMBER_42,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_42text,16,editbox);
	if(pBaseMain_PAGERNUMBER_42==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_42;
	pBaseMain_NUMBERGUEST_42 = EbCreate(BaseMain_NUMBERGUEST_42,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_42text,2,editbox);
	if(pBaseMain_NUMBERGUEST_42==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_42;
	pBaseMain_PAGERACTIVATED_42 = EbCreate(BaseMain_PAGERACTIVATED_42,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_42text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_42==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_42;
	pBaseMain_PAGERCALLED_42 = EbCreate(BaseMain_PAGERCALLED_42,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_42text,3,editbox);
	if(pBaseMain_PAGERCALLED_42==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_42;
	pBaseMain_TABLENUMBER_42 = EbCreate(BaseMain_TABLENUMBER_42,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_42text,3,editbox);
	if(pBaseMain_TABLENUMBER_42==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_42;
	pBaseMain_ORDERFOOD_42 = EbCreate(BaseMain_ORDERFOOD_42,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_42text,3,editbox);
	if(pBaseMain_ORDERFOOD_42==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager43(void)	
{	
	
	CreatePager42();
	//Pager 43
	EDITBOX *pBaseMain_PAGERNUMBER_43;
	pBaseMain_PAGERNUMBER_43 = EbCreate(BaseMain_PAGERNUMBER_43,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_43text,16,editbox);
	if(pBaseMain_PAGERNUMBER_43==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_43;
	pBaseMain_NUMBERGUEST_43 = EbCreate(BaseMain_NUMBERGUEST_43,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_43text,2,editbox);
	if(pBaseMain_NUMBERGUEST_43==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_43;
	pBaseMain_PAGERACTIVATED_43 = EbCreate(BaseMain_PAGERACTIVATED_43,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_43text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_43==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_43;
	pBaseMain_PAGERCALLED_43 = EbCreate(BaseMain_PAGERCALLED_43,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_43text,3,editbox);
	if(pBaseMain_PAGERCALLED_43==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_43;
	pBaseMain_TABLENUMBER_43 = EbCreate(BaseMain_TABLENUMBER_43,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_43text,3,editbox);
	if(pBaseMain_TABLENUMBER_43==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_43;
	pBaseMain_ORDERFOOD_43 = EbCreate(BaseMain_ORDERFOOD_43,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_43text,3,editbox);
	if(pBaseMain_ORDERFOOD_43==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager44(void)	
{	
	
	CreatePager43();
	//Pager 44
	EDITBOX *pBaseMain_PAGERNUMBER_44;
	pBaseMain_PAGERNUMBER_44 = EbCreate(BaseMain_PAGERNUMBER_44,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_44text,16,editbox);
	if(pBaseMain_PAGERNUMBER_44==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_44;
	pBaseMain_NUMBERGUEST_44 = EbCreate(BaseMain_NUMBERGUEST_44,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_44text,2,editbox);
	if(pBaseMain_NUMBERGUEST_44==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_44;
	pBaseMain_PAGERACTIVATED_44 = EbCreate(BaseMain_PAGERACTIVATED_44,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_44text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_44==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_44;
	pBaseMain_PAGERCALLED_44 = EbCreate(BaseMain_PAGERCALLED_44,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_44text,3,editbox);
	if(pBaseMain_PAGERCALLED_44==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_44;
	pBaseMain_TABLENUMBER_44 = EbCreate(BaseMain_TABLENUMBER_44,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_44text,3,editbox);
	if(pBaseMain_TABLENUMBER_44==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_44;
	pBaseMain_ORDERFOOD_44 = EbCreate(BaseMain_ORDERFOOD_44,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_44text,3,editbox);
	if(pBaseMain_ORDERFOOD_44==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
void CreatePager45(void)	
{	
	
	CreateBaseMain();	
	//Pager 45
	EDITBOX *pBaseMain_PAGERNUMBER_45;
	pBaseMain_PAGERNUMBER_45 = EbCreate(BaseMain_PAGERNUMBER_45,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_45text,16,editbox);
	if(pBaseMain_PAGERNUMBER_45==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_45;
	pBaseMain_NUMBERGUEST_45 = EbCreate(BaseMain_NUMBERGUEST_45,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_45text,2,editbox);
	if(pBaseMain_NUMBERGUEST_45==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_45;
	pBaseMain_PAGERACTIVATED_45 = EbCreate(BaseMain_PAGERACTIVATED_45,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_45text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_45==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_45;
	pBaseMain_PAGERCALLED_45 = EbCreate(BaseMain_PAGERCALLED_45,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_45text,3,editbox);
	if(pBaseMain_PAGERCALLED_45==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_45;
	pBaseMain_TABLENUMBER_45 = EbCreate(BaseMain_TABLENUMBER_45,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_45text,3,editbox);
	if(pBaseMain_TABLENUMBER_45==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_45;
	pBaseMain_ORDERFOOD_45 = EbCreate(BaseMain_ORDERFOOD_45,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_45text,3,editbox);
	if(pBaseMain_ORDERFOOD_45==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager46(void)	
{	
	
	CreatePager45();
	//Pager 46
	EDITBOX *pBaseMain_PAGERNUMBER_46;
	pBaseMain_PAGERNUMBER_46 = EbCreate(BaseMain_PAGERNUMBER_46,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_46text,16,editbox);
	if(pBaseMain_PAGERNUMBER_46==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_46;
	pBaseMain_NUMBERGUEST_46 = EbCreate(BaseMain_NUMBERGUEST_46,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_46text,2,editbox);
	if(pBaseMain_NUMBERGUEST_46==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_46;
	pBaseMain_PAGERACTIVATED_46 = EbCreate(BaseMain_PAGERACTIVATED_46,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_46text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_46==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_46;
	pBaseMain_PAGERCALLED_46 = EbCreate(BaseMain_PAGERCALLED_46,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_46text,3,editbox);
	if(pBaseMain_PAGERCALLED_46==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_46;
	pBaseMain_TABLENUMBER_46 = EbCreate(BaseMain_TABLENUMBER_46,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_46text,3,editbox);
	if(pBaseMain_TABLENUMBER_46==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_46;
	pBaseMain_ORDERFOOD_46 = EbCreate(BaseMain_ORDERFOOD_46,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_46text,3,editbox);
	if(pBaseMain_ORDERFOOD_46==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager47(void)	
{	
	
	CreatePager46();
	//Pager 47
	EDITBOX *pBaseMain_PAGERNUMBER_47;
	pBaseMain_PAGERNUMBER_47 = EbCreate(BaseMain_PAGERNUMBER_47,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_47text,16,editbox);
	if(pBaseMain_PAGERNUMBER_47==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_47;
	pBaseMain_NUMBERGUEST_47 = EbCreate(BaseMain_NUMBERGUEST_47,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_47text,2,editbox);
	if(pBaseMain_NUMBERGUEST_47==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_47;
	pBaseMain_PAGERACTIVATED_47 = EbCreate(BaseMain_PAGERACTIVATED_47,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_47text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_47==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_47;
	pBaseMain_PAGERCALLED_47 = EbCreate(BaseMain_PAGERCALLED_47,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_47text,3,editbox);
	if(pBaseMain_PAGERCALLED_47==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_47;
	pBaseMain_TABLENUMBER_47 = EbCreate(BaseMain_TABLENUMBER_47,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_47text,3,editbox);
	if(pBaseMain_TABLENUMBER_47==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_47;
	pBaseMain_ORDERFOOD_47 = EbCreate(BaseMain_ORDERFOOD_47,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_47text,3,editbox);
	if(pBaseMain_ORDERFOOD_47==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager48(void)	
{	
	
	CreatePager47();
	//Pager 48
	EDITBOX *pBaseMain_PAGERNUMBER_48;
	pBaseMain_PAGERNUMBER_48 = EbCreate(BaseMain_PAGERNUMBER_48,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_48text,16,editbox);
	if(pBaseMain_PAGERNUMBER_48==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_48;
	pBaseMain_NUMBERGUEST_48 = EbCreate(BaseMain_NUMBERGUEST_48,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_48text,2,editbox);
	if(pBaseMain_NUMBERGUEST_48==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_48;
	pBaseMain_PAGERACTIVATED_48 = EbCreate(BaseMain_PAGERACTIVATED_48,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_48text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_48==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_48;
	pBaseMain_PAGERCALLED_48 = EbCreate(BaseMain_PAGERCALLED_48,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_48text,3,editbox);
	if(pBaseMain_PAGERCALLED_48==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_48;
	pBaseMain_TABLENUMBER_48 = EbCreate(BaseMain_TABLENUMBER_48,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_48text,3,editbox);
	if(pBaseMain_TABLENUMBER_48==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_48;
	pBaseMain_ORDERFOOD_48 = EbCreate(BaseMain_ORDERFOOD_48,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_48text,3,editbox);
	if(pBaseMain_ORDERFOOD_48==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager49(void)	
{	
	
	CreatePager48();
	//Pager 49
	EDITBOX *pBaseMain_PAGERNUMBER_49;
	pBaseMain_PAGERNUMBER_49 = EbCreate(BaseMain_PAGERNUMBER_49,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_49text,16,editbox);
	if(pBaseMain_PAGERNUMBER_49==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_49;
	pBaseMain_NUMBERGUEST_49 = EbCreate(BaseMain_NUMBERGUEST_49,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_49text,2,editbox);
	if(pBaseMain_NUMBERGUEST_49==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_49;
	pBaseMain_PAGERACTIVATED_49 = EbCreate(BaseMain_PAGERACTIVATED_49,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_49text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_49==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_49;
	pBaseMain_PAGERCALLED_49 = EbCreate(BaseMain_PAGERCALLED_49,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_49text,3,editbox);
	if(pBaseMain_PAGERCALLED_49==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_49;
	pBaseMain_TABLENUMBER_49 = EbCreate(BaseMain_TABLENUMBER_49,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_49text,3,editbox);
	if(pBaseMain_TABLENUMBER_49==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_49;
	pBaseMain_ORDERFOOD_49 = EbCreate(BaseMain_ORDERFOOD_49,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_49text,3,editbox);
	if(pBaseMain_ORDERFOOD_49==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
void CreatePager50(void)	
{	
	
	CreateBaseMain();
	//Pager 50
	EDITBOX *pBaseMain_PAGERNUMBER_50;
	pBaseMain_PAGERNUMBER_50 = EbCreate(BaseMain_PAGERNUMBER_50,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_50text,16,editbox);
	if(pBaseMain_PAGERNUMBER_50==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_50;
	pBaseMain_NUMBERGUEST_50 = EbCreate(BaseMain_NUMBERGUEST_50,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_50text,2,editbox);
	if(pBaseMain_NUMBERGUEST_50==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_50;
	pBaseMain_PAGERACTIVATED_50 = EbCreate(BaseMain_PAGERACTIVATED_50,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_50text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_50==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_50;
	pBaseMain_PAGERCALLED_50 = EbCreate(BaseMain_PAGERCALLED_50,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_50text,3,editbox);
	if(pBaseMain_PAGERCALLED_50==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_50;
	pBaseMain_TABLENUMBER_50 = EbCreate(BaseMain_TABLENUMBER_50,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_50text,3,editbox);
	if(pBaseMain_TABLENUMBER_50==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_50;
	pBaseMain_ORDERFOOD_50 = EbCreate(BaseMain_ORDERFOOD_50,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_50text,3,editbox);
	if(pBaseMain_ORDERFOOD_50==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager51(void)	
{	
	
	CreatePager50();
	//Pager 51
	EDITBOX *pBaseMain_PAGERNUMBER_51;
	pBaseMain_PAGERNUMBER_51 = EbCreate(BaseMain_PAGERNUMBER_51,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_51text,16,editbox);
	if(pBaseMain_PAGERNUMBER_51==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_51;
	pBaseMain_NUMBERGUEST_51 = EbCreate(BaseMain_NUMBERGUEST_51,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_51text,2,editbox);
	if(pBaseMain_NUMBERGUEST_51==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_51;
	pBaseMain_PAGERACTIVATED_51 = EbCreate(BaseMain_PAGERACTIVATED_51,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_51text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_51==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_51;
	pBaseMain_PAGERCALLED_51 = EbCreate(BaseMain_PAGERCALLED_51,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_51text,3,editbox);
	if(pBaseMain_PAGERCALLED_51==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_51;
	pBaseMain_TABLENUMBER_51 = EbCreate(BaseMain_TABLENUMBER_51,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_51text,3,editbox);
	if(pBaseMain_TABLENUMBER_51==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_51;
	pBaseMain_ORDERFOOD_51 = EbCreate(BaseMain_ORDERFOOD_51,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_51text,3,editbox);
	if(pBaseMain_ORDERFOOD_51==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager52(void)	
{	
	
	CreatePager51();
	//Pager 52
	EDITBOX *pBaseMain_PAGERNUMBER_52;
	pBaseMain_PAGERNUMBER_52 = EbCreate(BaseMain_PAGERNUMBER_52,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_52text,16,editbox);
	if(pBaseMain_PAGERNUMBER_52==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_52;
	pBaseMain_NUMBERGUEST_52 = EbCreate(BaseMain_NUMBERGUEST_52,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_52text,2,editbox);
	if(pBaseMain_NUMBERGUEST_52==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_52;
	pBaseMain_PAGERACTIVATED_52 = EbCreate(BaseMain_PAGERACTIVATED_52,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_52text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_52==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_52;
	pBaseMain_PAGERCALLED_52 = EbCreate(BaseMain_PAGERCALLED_52,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_52text,3,editbox);
	if(pBaseMain_PAGERCALLED_52==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_52;
	pBaseMain_TABLENUMBER_52 = EbCreate(BaseMain_TABLENUMBER_52,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_52text,3,editbox);
	if(pBaseMain_TABLENUMBER_52==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_52;
	pBaseMain_ORDERFOOD_52 = EbCreate(BaseMain_ORDERFOOD_52,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_52text,3,editbox);
	if(pBaseMain_ORDERFOOD_52==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager53(void)	
{	
	CreatePager52();	//Pager 53
	EDITBOX *pBaseMain_PAGERNUMBER_53;
	pBaseMain_PAGERNUMBER_53 = EbCreate(BaseMain_PAGERNUMBER_53,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_53text,16,editbox);
	if(pBaseMain_PAGERNUMBER_53==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_53;
	pBaseMain_NUMBERGUEST_53 = EbCreate(BaseMain_NUMBERGUEST_53,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_53text,2,editbox);
	if(pBaseMain_NUMBERGUEST_53==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_53;
	pBaseMain_PAGERACTIVATED_53 = EbCreate(BaseMain_PAGERACTIVATED_53,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_53text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_53==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_53;
	pBaseMain_PAGERCALLED_53 = EbCreate(BaseMain_PAGERCALLED_53,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_53text,3,editbox);
	if(pBaseMain_PAGERCALLED_53==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_53;
	pBaseMain_TABLENUMBER_53 = EbCreate(BaseMain_TABLENUMBER_53,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_53text,3,editbox);
	if(pBaseMain_TABLENUMBER_53==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_53;
	pBaseMain_ORDERFOOD_53 = EbCreate(BaseMain_ORDERFOOD_53,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_53text,3,editbox);
	if(pBaseMain_ORDERFOOD_53==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	

void CreatePager54(void)	
{	
	
	CreatePager53();	//Pager 54
	EDITBOX *pBaseMain_PAGERNUMBER_54;
	pBaseMain_PAGERNUMBER_54 = EbCreate(BaseMain_PAGERNUMBER_54,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_54text,16,editbox);
	if(pBaseMain_PAGERNUMBER_54==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_54;
	pBaseMain_NUMBERGUEST_54 = EbCreate(BaseMain_NUMBERGUEST_54,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_54text,2,editbox);
	if(pBaseMain_NUMBERGUEST_54==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_54;
	pBaseMain_PAGERACTIVATED_54 = EbCreate(BaseMain_PAGERACTIVATED_54,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_54text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_54==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_54;
	pBaseMain_PAGERCALLED_54 = EbCreate(BaseMain_PAGERCALLED_54,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_54text,3,editbox);
	if(pBaseMain_PAGERCALLED_54==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_54;
	pBaseMain_TABLENUMBER_54 = EbCreate(BaseMain_TABLENUMBER_54,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_54text,3,editbox);
	if(pBaseMain_TABLENUMBER_54==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_54;
	pBaseMain_ORDERFOOD_54 = EbCreate(BaseMain_ORDERFOOD_54,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_54text,3,editbox);
	if(pBaseMain_ORDERFOOD_54==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
void CreatePager55(void)	
{	
	
	CreateBaseMain();
	//Pager 55
	EDITBOX *pBaseMain_PAGERNUMBER_55;
	pBaseMain_PAGERNUMBER_55 = EbCreate(BaseMain_PAGERNUMBER_55,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_55text,16,editbox);
	if(pBaseMain_PAGERNUMBER_55==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_55;
	pBaseMain_NUMBERGUEST_55 = EbCreate(BaseMain_NUMBERGUEST_55,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_55text,2,editbox);
	if(pBaseMain_NUMBERGUEST_55==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_55;
	pBaseMain_PAGERACTIVATED_55 = EbCreate(BaseMain_PAGERACTIVATED_55,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_55text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_55==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_55;
	pBaseMain_PAGERCALLED_55 = EbCreate(BaseMain_PAGERCALLED_55,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_55text,3,editbox);
	if(pBaseMain_PAGERCALLED_55==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_55;
	pBaseMain_TABLENUMBER_55 = EbCreate(BaseMain_TABLENUMBER_55,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_55text,3,editbox);
	if(pBaseMain_TABLENUMBER_55==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_55;
	pBaseMain_ORDERFOOD_55 = EbCreate(BaseMain_ORDERFOOD_55,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_55text,3,editbox);
	if(pBaseMain_ORDERFOOD_55==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager56(void)	
{	
	
	CreatePager55();
	//Pager 56
	EDITBOX *pBaseMain_PAGERNUMBER_56;
	pBaseMain_PAGERNUMBER_56 = EbCreate(BaseMain_PAGERNUMBER_56,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_56text,16,editbox);
	if(pBaseMain_PAGERNUMBER_56==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_56;
	pBaseMain_NUMBERGUEST_56 = EbCreate(BaseMain_NUMBERGUEST_56,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_56text,2,editbox);
	if(pBaseMain_NUMBERGUEST_56==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_56;
	pBaseMain_PAGERACTIVATED_56 = EbCreate(BaseMain_PAGERACTIVATED_56,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_56text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_56==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_56;
	pBaseMain_PAGERCALLED_56 = EbCreate(BaseMain_PAGERCALLED_56,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_56text,3,editbox);
	if(pBaseMain_PAGERCALLED_56==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_56;
	pBaseMain_TABLENUMBER_56 = EbCreate(BaseMain_TABLENUMBER_56,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_56text,3,editbox);
	if(pBaseMain_TABLENUMBER_56==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_56;
	pBaseMain_ORDERFOOD_56 = EbCreate(BaseMain_ORDERFOOD_56,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_56text,3,editbox);
	if(pBaseMain_ORDERFOOD_56==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager57(void)	
{	
	
	CreatePager56();
	//Pager 57
	EDITBOX *pBaseMain_PAGERNUMBER_57;
	pBaseMain_PAGERNUMBER_57 = EbCreate(BaseMain_PAGERNUMBER_57,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_57text,16,editbox);
	if(pBaseMain_PAGERNUMBER_57==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_57;
	pBaseMain_NUMBERGUEST_57 = EbCreate(BaseMain_NUMBERGUEST_57,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_57text,2,editbox);
	if(pBaseMain_NUMBERGUEST_57==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_57;
	pBaseMain_PAGERACTIVATED_57 = EbCreate(BaseMain_PAGERACTIVATED_57,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_57text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_57==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_57;
	pBaseMain_PAGERCALLED_57 = EbCreate(BaseMain_PAGERCALLED_57,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_57text,3,editbox);
	if(pBaseMain_PAGERCALLED_57==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_57;
	pBaseMain_TABLENUMBER_57 = EbCreate(BaseMain_TABLENUMBER_57,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_57text,3,editbox);
	if(pBaseMain_TABLENUMBER_57==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_57;
	pBaseMain_ORDERFOOD_57 = EbCreate(BaseMain_ORDERFOOD_57,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_57text,3,editbox);
	if(pBaseMain_ORDERFOOD_57==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager58(void)	
{	
	
	CreatePager57();
	//Pager 58
	EDITBOX *pBaseMain_PAGERNUMBER_58;
	pBaseMain_PAGERNUMBER_58 = EbCreate(BaseMain_PAGERNUMBER_58,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_58text,16,editbox);
	if(pBaseMain_PAGERNUMBER_58==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_58;
	pBaseMain_NUMBERGUEST_58 = EbCreate(BaseMain_NUMBERGUEST_58,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_58text,2,editbox);
	if(pBaseMain_NUMBERGUEST_58==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_58;
	pBaseMain_PAGERACTIVATED_58 = EbCreate(BaseMain_PAGERACTIVATED_58,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_58text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_58==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_58;
	pBaseMain_PAGERCALLED_58 = EbCreate(BaseMain_PAGERCALLED_58,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_58text,3,editbox);
	if(pBaseMain_PAGERCALLED_58==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_58;
	pBaseMain_TABLENUMBER_58 = EbCreate(BaseMain_TABLENUMBER_58,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_58text,3,editbox);
	if(pBaseMain_TABLENUMBER_58==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_58;
	pBaseMain_ORDERFOOD_58 = EbCreate(BaseMain_ORDERFOOD_58,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_58text,3,editbox);
	if(pBaseMain_ORDERFOOD_58==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager59(void)	
{	
	
	CreatePager58();	//Pager 59
	EDITBOX *pBaseMain_PAGERNUMBER_59;
	pBaseMain_PAGERNUMBER_59 = EbCreate(BaseMain_PAGERNUMBER_59,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_59text,16,editbox);
	if(pBaseMain_PAGERNUMBER_59==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_59;
	pBaseMain_NUMBERGUEST_59 = EbCreate(BaseMain_NUMBERGUEST_59,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_59text,2,editbox);
	if(pBaseMain_NUMBERGUEST_59==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_59;
	pBaseMain_PAGERACTIVATED_59 = EbCreate(BaseMain_PAGERACTIVATED_59,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_59text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_59==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_59;
	pBaseMain_PAGERCALLED_59 = EbCreate(BaseMain_PAGERCALLED_59,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_59text,3,editbox);
	if(pBaseMain_PAGERCALLED_59==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_59;
	pBaseMain_TABLENUMBER_59 = EbCreate(BaseMain_TABLENUMBER_59,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_59text,3,editbox);
	if(pBaseMain_TABLENUMBER_59==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_59;
	pBaseMain_ORDERFOOD_59 = EbCreate(BaseMain_ORDERFOOD_59,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_59text,3,editbox);
	if(pBaseMain_ORDERFOOD_59==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
void CreatePager60(void)	
{	
	
	CreateBaseMain();
	//Pager 60
	EDITBOX *pBaseMain_PAGERNUMBER_60;
	pBaseMain_PAGERNUMBER_60 = EbCreate(BaseMain_PAGERNUMBER_60,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_60text,16,editbox);
	if(pBaseMain_PAGERNUMBER_60==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_60;
	pBaseMain_NUMBERGUEST_60 = EbCreate(BaseMain_NUMBERGUEST_60,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_60text,2,editbox);
	if(pBaseMain_NUMBERGUEST_60==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_60;
	pBaseMain_PAGERACTIVATED_60 = EbCreate(BaseMain_PAGERACTIVATED_60,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_60text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_60==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_60;
	pBaseMain_PAGERCALLED_60 = EbCreate(BaseMain_PAGERCALLED_60,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_60text,3,editbox);
	if(pBaseMain_PAGERCALLED_60==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_60;
	pBaseMain_TABLENUMBER_60 = EbCreate(BaseMain_TABLENUMBER_60,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_60text,3,editbox);
	if(pBaseMain_TABLENUMBER_60==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_60;
	pBaseMain_ORDERFOOD_60 = EbCreate(BaseMain_ORDERFOOD_60,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_60text,3,editbox);
	if(pBaseMain_ORDERFOOD_60==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager61(void)	
{	
	
	CreatePager60();	//Pager 61
	EDITBOX *pBaseMain_PAGERNUMBER_61;
	pBaseMain_PAGERNUMBER_61 = EbCreate(BaseMain_PAGERNUMBER_61,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_61text,16,editbox);
	if(pBaseMain_PAGERNUMBER_61==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_61;
	pBaseMain_NUMBERGUEST_61 = EbCreate(BaseMain_NUMBERGUEST_61,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_61text,2,editbox);
	if(pBaseMain_NUMBERGUEST_61==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_61;
	pBaseMain_PAGERACTIVATED_61 = EbCreate(BaseMain_PAGERACTIVATED_61,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_61text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_61==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_61;
	pBaseMain_PAGERCALLED_61 = EbCreate(BaseMain_PAGERCALLED_61,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_61text,3,editbox);
	if(pBaseMain_PAGERCALLED_61==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_61;
	pBaseMain_TABLENUMBER_61 = EbCreate(BaseMain_TABLENUMBER_61,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_61text,3,editbox);
	if(pBaseMain_TABLENUMBER_61==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_61;
	pBaseMain_ORDERFOOD_61 = EbCreate(BaseMain_ORDERFOOD_61,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_61text,3,editbox);
	if(pBaseMain_ORDERFOOD_61==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager62(void)	
{	
	
	CreatePager61();
	//Pager 62
	EDITBOX *pBaseMain_PAGERNUMBER_62;
	pBaseMain_PAGERNUMBER_62 = EbCreate(BaseMain_PAGERNUMBER_62,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_62text,16,editbox);
	if(pBaseMain_PAGERNUMBER_62==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_62;
	pBaseMain_NUMBERGUEST_62 = EbCreate(BaseMain_NUMBERGUEST_62,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_62text,2,editbox);
	if(pBaseMain_NUMBERGUEST_62==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_62;
	pBaseMain_PAGERACTIVATED_62 = EbCreate(BaseMain_PAGERACTIVATED_62,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_62text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_62==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_62;
	pBaseMain_PAGERCALLED_62 = EbCreate(BaseMain_PAGERCALLED_62,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_62text,3,editbox);
	if(pBaseMain_PAGERCALLED_62==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_62;
	pBaseMain_TABLENUMBER_62 = EbCreate(BaseMain_TABLENUMBER_62,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_62text,3,editbox);
	if(pBaseMain_TABLENUMBER_62==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_62;
	pBaseMain_ORDERFOOD_62 = EbCreate(BaseMain_ORDERFOOD_62,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_62text,3,editbox);
	if(pBaseMain_ORDERFOOD_62==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager63(void)	
{	
	
	CreatePager62();
	//Pager 63
	EDITBOX *pBaseMain_PAGERNUMBER_63;
	pBaseMain_PAGERNUMBER_63 = EbCreate(BaseMain_PAGERNUMBER_63,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_63text,16,editbox);
	if(pBaseMain_PAGERNUMBER_63==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_63;
	pBaseMain_NUMBERGUEST_63 = EbCreate(BaseMain_NUMBERGUEST_63,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_63text,2,editbox);
	if(pBaseMain_NUMBERGUEST_63==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_63;
	pBaseMain_PAGERACTIVATED_63 = EbCreate(BaseMain_PAGERACTIVATED_63,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_63text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_63==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_63;
	pBaseMain_PAGERCALLED_63 = EbCreate(BaseMain_PAGERCALLED_63,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_63text,3,editbox);
	if(pBaseMain_PAGERCALLED_63==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_63;
	pBaseMain_TABLENUMBER_63 = EbCreate(BaseMain_TABLENUMBER_63,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_63text,3,editbox);
	if(pBaseMain_TABLENUMBER_63==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_63;
	pBaseMain_ORDERFOOD_63 = EbCreate(BaseMain_ORDERFOOD_63,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_63text,3,editbox);
	if(pBaseMain_ORDERFOOD_63==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager64(void)	
{	
	
	CreatePager63();
	//Pager 64
	EDITBOX *pBaseMain_PAGERNUMBER_64;
	pBaseMain_PAGERNUMBER_64 = EbCreate(BaseMain_PAGERNUMBER_64,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_64text,16,editbox);
	if(pBaseMain_PAGERNUMBER_64==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_64;
	pBaseMain_NUMBERGUEST_64 = EbCreate(BaseMain_NUMBERGUEST_64,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_64text,2,editbox);
	if(pBaseMain_NUMBERGUEST_64==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_64;
	pBaseMain_PAGERACTIVATED_64 = EbCreate(BaseMain_PAGERACTIVATED_64,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_64text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_64==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_64;
	pBaseMain_PAGERCALLED_64 = EbCreate(BaseMain_PAGERCALLED_64,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_64text,3,editbox);
	if(pBaseMain_PAGERCALLED_64==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_64;
	pBaseMain_TABLENUMBER_64 = EbCreate(BaseMain_TABLENUMBER_64,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_64text,3,editbox);
	if(pBaseMain_TABLENUMBER_64==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_64;
	pBaseMain_ORDERFOOD_64 = EbCreate(BaseMain_ORDERFOOD_64,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_64text,3,editbox);
	if(pBaseMain_ORDERFOOD_64==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
void CreatePager65(void)	
{	
	
	CreateBaseMain();
	//Pager 65
	EDITBOX *pBaseMain_PAGERNUMBER_65;
	pBaseMain_PAGERNUMBER_65 = EbCreate(BaseMain_PAGERNUMBER_65,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_65text,16,editbox);
	if(pBaseMain_PAGERNUMBER_65==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_65;
	pBaseMain_NUMBERGUEST_65 = EbCreate(BaseMain_NUMBERGUEST_65,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_65text,2,editbox);
	if(pBaseMain_NUMBERGUEST_65==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_65;
	pBaseMain_PAGERACTIVATED_65 = EbCreate(BaseMain_PAGERACTIVATED_65,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_65text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_65==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_65;
	pBaseMain_PAGERCALLED_65 = EbCreate(BaseMain_PAGERCALLED_65,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_65text,3,editbox);
	if(pBaseMain_PAGERCALLED_65==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_65;
	pBaseMain_TABLENUMBER_65 = EbCreate(BaseMain_TABLENUMBER_65,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_65text,3,editbox);
	if(pBaseMain_TABLENUMBER_65==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_65;
	pBaseMain_ORDERFOOD_65 = EbCreate(BaseMain_ORDERFOOD_65,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_65text,3,editbox);
	if(pBaseMain_ORDERFOOD_65==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	

void CreatePager66(void)	
{	
	
	CreatePager55();
	//Pager 66
	EDITBOX *pBaseMain_PAGERNUMBER_66;
	pBaseMain_PAGERNUMBER_66 = EbCreate(BaseMain_PAGERNUMBER_66,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_66text,16,editbox);
	if(pBaseMain_PAGERNUMBER_66==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_66;
	pBaseMain_NUMBERGUEST_66 = EbCreate(BaseMain_NUMBERGUEST_66,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_66text,2,editbox);
	if(pBaseMain_NUMBERGUEST_66==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_66;
	pBaseMain_PAGERACTIVATED_66 = EbCreate(BaseMain_PAGERACTIVATED_66,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_66text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_66==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_66;
	pBaseMain_PAGERCALLED_66 = EbCreate(BaseMain_PAGERCALLED_66,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_66text,3,editbox);
	if(pBaseMain_PAGERCALLED_66==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_66;
	pBaseMain_TABLENUMBER_66 = EbCreate(BaseMain_TABLENUMBER_66,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_66text,3,editbox);
	if(pBaseMain_TABLENUMBER_66==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_66;
	pBaseMain_ORDERFOOD_66 = EbCreate(BaseMain_ORDERFOOD_66,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_66text,3,editbox);
	if(pBaseMain_ORDERFOOD_66==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager67(void)	
{	
	
	CreatePager66();
	//Pager 67
	EDITBOX *pBaseMain_PAGERNUMBER_67;
	pBaseMain_PAGERNUMBER_67 = EbCreate(BaseMain_PAGERNUMBER_67,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_67text,16,editbox);
	if(pBaseMain_PAGERNUMBER_67==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_67;
	pBaseMain_NUMBERGUEST_67 = EbCreate(BaseMain_NUMBERGUEST_67,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_67text,2,editbox);
	if(pBaseMain_NUMBERGUEST_67==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_67;
	pBaseMain_PAGERACTIVATED_67 = EbCreate(BaseMain_PAGERACTIVATED_67,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_67text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_67==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_67;
	pBaseMain_PAGERCALLED_67 = EbCreate(BaseMain_PAGERCALLED_67,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_67text,3,editbox);
	if(pBaseMain_PAGERCALLED_67==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_67;
	pBaseMain_TABLENUMBER_67 = EbCreate(BaseMain_TABLENUMBER_67,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_67text,3,editbox);
	if(pBaseMain_TABLENUMBER_67==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_67;
	pBaseMain_ORDERFOOD_67 = EbCreate(BaseMain_ORDERFOOD_67,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_67text,3,editbox);
	if(pBaseMain_ORDERFOOD_67==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager68(void)	
{	
	
	CreatePager67();
	//Pager 68
	EDITBOX *pBaseMain_PAGERNUMBER_68;
	pBaseMain_PAGERNUMBER_68 = EbCreate(BaseMain_PAGERNUMBER_68,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_68text,16,editbox);
	if(pBaseMain_PAGERNUMBER_68==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_68;
	pBaseMain_NUMBERGUEST_68 = EbCreate(BaseMain_NUMBERGUEST_68,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_68text,2,editbox);
	if(pBaseMain_NUMBERGUEST_68==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_68;
	pBaseMain_PAGERACTIVATED_68 = EbCreate(BaseMain_PAGERACTIVATED_68,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_68text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_68==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_68;
	pBaseMain_PAGERCALLED_68 = EbCreate(BaseMain_PAGERCALLED_68,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_68text,3,editbox);
	if(pBaseMain_PAGERCALLED_68==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_68;
	pBaseMain_TABLENUMBER_68 = EbCreate(BaseMain_TABLENUMBER_68,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_68text,3,editbox);
	if(pBaseMain_TABLENUMBER_68==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_68;
	pBaseMain_ORDERFOOD_68 = EbCreate(BaseMain_ORDERFOOD_68,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_68text,3,editbox);
	if(pBaseMain_ORDERFOOD_68==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager69(void)	
{	
	
	CreatePager68();
	//Pager 69
	EDITBOX *pBaseMain_PAGERNUMBER_69;
	pBaseMain_PAGERNUMBER_69 = EbCreate(BaseMain_PAGERNUMBER_69,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_69text,16,editbox);
	if(pBaseMain_PAGERNUMBER_69==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_69;
	pBaseMain_NUMBERGUEST_69 = EbCreate(BaseMain_NUMBERGUEST_69,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_69text,2,editbox);
	if(pBaseMain_NUMBERGUEST_69==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_69;
	pBaseMain_PAGERACTIVATED_69 = EbCreate(BaseMain_PAGERACTIVATED_69,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_69text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_69==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_69;
	pBaseMain_PAGERCALLED_69 = EbCreate(BaseMain_PAGERCALLED_69,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_69text,3,editbox);
	if(pBaseMain_PAGERCALLED_69==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_69;
	pBaseMain_TABLENUMBER_69 = EbCreate(BaseMain_TABLENUMBER_69,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_69text,3,editbox);
	if(pBaseMain_TABLENUMBER_69==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_69;
	pBaseMain_ORDERFOOD_69 = EbCreate(BaseMain_ORDERFOOD_69,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_69text,3,editbox);
	if(pBaseMain_ORDERFOOD_69==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
void CreatePager70(void)	
{	
	
	CreateBaseMain();
	//Pager 70
	EDITBOX *pBaseMain_PAGERNUMBER_70;
	pBaseMain_PAGERNUMBER_70 = EbCreate(BaseMain_PAGERNUMBER_70,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_70text,16,editbox);
	if(pBaseMain_PAGERNUMBER_70==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_70;
	pBaseMain_NUMBERGUEST_70 = EbCreate(BaseMain_NUMBERGUEST_70,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_70text,2,editbox);
	if(pBaseMain_NUMBERGUEST_70==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_70;
	pBaseMain_PAGERACTIVATED_70 = EbCreate(BaseMain_PAGERACTIVATED_70,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_70text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_70==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_70;
	pBaseMain_PAGERCALLED_70 = EbCreate(BaseMain_PAGERCALLED_70,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_70text,3,editbox);
	if(pBaseMain_PAGERCALLED_70==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_70;
	pBaseMain_TABLENUMBER_70 = EbCreate(BaseMain_TABLENUMBER_70,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_70text,3,editbox);
	if(pBaseMain_TABLENUMBER_70==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_70;
	pBaseMain_ORDERFOOD_70 = EbCreate(BaseMain_ORDERFOOD_70,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_70text,3,editbox);
	if(pBaseMain_ORDERFOOD_70==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager71(void)	
{	
	
	CreatePager70();
	//Pager 71
	EDITBOX *pBaseMain_PAGERNUMBER_71;
	pBaseMain_PAGERNUMBER_71 = EbCreate(BaseMain_PAGERNUMBER_71,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_71text,16,editbox);
	if(pBaseMain_PAGERNUMBER_71==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_71;
	pBaseMain_NUMBERGUEST_71 = EbCreate(BaseMain_NUMBERGUEST_71,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_71text,2,editbox);
	if(pBaseMain_NUMBERGUEST_71==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_71;
	pBaseMain_PAGERACTIVATED_71 = EbCreate(BaseMain_PAGERACTIVATED_71,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_71text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_71==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_71;
	pBaseMain_PAGERCALLED_71 = EbCreate(BaseMain_PAGERCALLED_71,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_71text,3,editbox);
	if(pBaseMain_PAGERCALLED_71==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_71;
	pBaseMain_TABLENUMBER_71 = EbCreate(BaseMain_TABLENUMBER_71,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_71text,3,editbox);
	if(pBaseMain_TABLENUMBER_71==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_71;
	pBaseMain_ORDERFOOD_71 = EbCreate(BaseMain_ORDERFOOD_71,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_71text,3,editbox);
	if(pBaseMain_ORDERFOOD_71==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager72(void)	
{	
	
	CreatePager71();
	//Pager 72
	EDITBOX *pBaseMain_PAGERNUMBER_72;
	pBaseMain_PAGERNUMBER_72 = EbCreate(BaseMain_PAGERNUMBER_72,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_72text,16,editbox);
	if(pBaseMain_PAGERNUMBER_72==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_72;
	pBaseMain_NUMBERGUEST_72 = EbCreate(BaseMain_NUMBERGUEST_72,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_72text,2,editbox);
	if(pBaseMain_NUMBERGUEST_72==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_72;
	pBaseMain_PAGERACTIVATED_72 = EbCreate(BaseMain_PAGERACTIVATED_72,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_72text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_72==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_72;
	pBaseMain_PAGERCALLED_72 = EbCreate(BaseMain_PAGERCALLED_72,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_72text,3,editbox);
	if(pBaseMain_PAGERCALLED_72==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_72;
	pBaseMain_TABLENUMBER_72 = EbCreate(BaseMain_TABLENUMBER_72,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_72text,3,editbox);
	if(pBaseMain_TABLENUMBER_72==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_72;
	pBaseMain_ORDERFOOD_72 = EbCreate(BaseMain_ORDERFOOD_72,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_72text,3,editbox);
	if(pBaseMain_ORDERFOOD_72==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager73(void)	
{	
	CreatePager72();
	//Pager 73
	EDITBOX *pBaseMain_PAGERNUMBER_73;
	pBaseMain_PAGERNUMBER_73 = EbCreate(BaseMain_PAGERNUMBER_73,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_73text,16,editbox);
	if(pBaseMain_PAGERNUMBER_73==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_73;
	pBaseMain_NUMBERGUEST_73 = EbCreate(BaseMain_NUMBERGUEST_73,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_73text,2,editbox);
	if(pBaseMain_NUMBERGUEST_73==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_73;
	pBaseMain_PAGERACTIVATED_73 = EbCreate(BaseMain_PAGERACTIVATED_73,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_73text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_73==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_73;
	pBaseMain_PAGERCALLED_73 = EbCreate(BaseMain_PAGERCALLED_73,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_73text,3,editbox);
	if(pBaseMain_PAGERCALLED_73==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_73;
	pBaseMain_TABLENUMBER_73 = EbCreate(BaseMain_TABLENUMBER_73,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_73text,3,editbox);
	if(pBaseMain_TABLENUMBER_73==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_73;
	pBaseMain_ORDERFOOD_73 = EbCreate(BaseMain_ORDERFOOD_73,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_73text,3,editbox);
	if(pBaseMain_ORDERFOOD_73==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager74(void)	
{	
	
	CreatePager73();	//Pager 74
	EDITBOX *pBaseMain_PAGERNUMBER_74;
	pBaseMain_PAGERNUMBER_74 = EbCreate(BaseMain_PAGERNUMBER_74,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_74text,16,editbox);
	if(pBaseMain_PAGERNUMBER_74==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_74;
	pBaseMain_NUMBERGUEST_74 = EbCreate(BaseMain_NUMBERGUEST_74,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_74text,2,editbox);
	if(pBaseMain_NUMBERGUEST_74==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_74;
	pBaseMain_PAGERACTIVATED_74 = EbCreate(BaseMain_PAGERACTIVATED_74,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_74text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_74==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_74;
	pBaseMain_PAGERCALLED_74 = EbCreate(BaseMain_PAGERCALLED_74,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_74text,3,editbox);
	if(pBaseMain_PAGERCALLED_74==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_74;
	pBaseMain_TABLENUMBER_74 = EbCreate(BaseMain_TABLENUMBER_74,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_74text,3,editbox);
	if(pBaseMain_TABLENUMBER_74==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_74;
	pBaseMain_ORDERFOOD_74 = EbCreate(BaseMain_ORDERFOOD_74,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_74text,3,editbox);
	if(pBaseMain_ORDERFOOD_74==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
void CreatePager75(void)	
{	
	
	CreateBaseMain();	
	//Pager 75
	EDITBOX *pBaseMain_PAGERNUMBER_75;
	pBaseMain_PAGERNUMBER_75 = EbCreate(BaseMain_PAGERNUMBER_75,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_75text,16,editbox);
	if(pBaseMain_PAGERNUMBER_75==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_75;
	pBaseMain_NUMBERGUEST_75 = EbCreate(BaseMain_NUMBERGUEST_75,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_75text,2,editbox);
	if(pBaseMain_NUMBERGUEST_75==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_75;
	pBaseMain_PAGERACTIVATED_75 = EbCreate(BaseMain_PAGERACTIVATED_75,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_75text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_75==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_75;
	pBaseMain_PAGERCALLED_75 = EbCreate(BaseMain_PAGERCALLED_75,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_75text,3,editbox);
	if(pBaseMain_PAGERCALLED_75==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_75;
	pBaseMain_TABLENUMBER_75 = EbCreate(BaseMain_TABLENUMBER_75,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_75text,3,editbox);
	if(pBaseMain_TABLENUMBER_75==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_75;
	pBaseMain_ORDERFOOD_75 = EbCreate(BaseMain_ORDERFOOD_75,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_75text,3,editbox);
	if(pBaseMain_ORDERFOOD_75==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager76(void)	
{	
	
	CreatePager75();
	//Pager 76
	EDITBOX *pBaseMain_PAGERNUMBER_76;
	pBaseMain_PAGERNUMBER_76 = EbCreate(BaseMain_PAGERNUMBER_76,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_76text,16,editbox);
	if(pBaseMain_PAGERNUMBER_76==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_76;
	pBaseMain_NUMBERGUEST_76 = EbCreate(BaseMain_NUMBERGUEST_76,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_76text,2,editbox);
	if(pBaseMain_NUMBERGUEST_76==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_76;
	pBaseMain_PAGERACTIVATED_76 = EbCreate(BaseMain_PAGERACTIVATED_76,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_76text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_76==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_76;
	pBaseMain_PAGERCALLED_76 = EbCreate(BaseMain_PAGERCALLED_76,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_76text,3,editbox);
	if(pBaseMain_PAGERCALLED_76==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_76;
	pBaseMain_TABLENUMBER_76 = EbCreate(BaseMain_TABLENUMBER_76,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_76text,3,editbox);
	if(pBaseMain_TABLENUMBER_76==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_76;
	pBaseMain_ORDERFOOD_76 = EbCreate(BaseMain_ORDERFOOD_76,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_76text,3,editbox);
	if(pBaseMain_ORDERFOOD_76==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager77(void)	
{	
	CreatePager76();
	//Pager 77
	EDITBOX *pBaseMain_PAGERNUMBER_77;
	pBaseMain_PAGERNUMBER_77 = EbCreate(BaseMain_PAGERNUMBER_77,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_77text,16,editbox);
	if(pBaseMain_PAGERNUMBER_77==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_77;
	pBaseMain_NUMBERGUEST_77 = EbCreate(BaseMain_NUMBERGUEST_77,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_77text,2,editbox);
	if(pBaseMain_NUMBERGUEST_77==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_77;
	pBaseMain_PAGERACTIVATED_77 = EbCreate(BaseMain_PAGERACTIVATED_77,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_77text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_77==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_77;
	pBaseMain_PAGERCALLED_77 = EbCreate(BaseMain_PAGERCALLED_77,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_77text,3,editbox);
	if(pBaseMain_PAGERCALLED_77==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_77;
	pBaseMain_TABLENUMBER_77 = EbCreate(BaseMain_TABLENUMBER_77,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_77text,3,editbox);
	if(pBaseMain_TABLENUMBER_77==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_77;
	pBaseMain_ORDERFOOD_77 = EbCreate(BaseMain_ORDERFOOD_77,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_77text,3,editbox);
	if(pBaseMain_ORDERFOOD_77==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager78(void)	
{	
	
	CreatePager77();
	//Pager 78
	EDITBOX *pBaseMain_PAGERNUMBER_78;
	pBaseMain_PAGERNUMBER_78 = EbCreate(BaseMain_PAGERNUMBER_78,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_78text,16,editbox);
	if(pBaseMain_PAGERNUMBER_78==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_78;
	pBaseMain_NUMBERGUEST_78 = EbCreate(BaseMain_NUMBERGUEST_78,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_78text,2,editbox);
	if(pBaseMain_NUMBERGUEST_78==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_78;
	pBaseMain_PAGERACTIVATED_78 = EbCreate(BaseMain_PAGERACTIVATED_78,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_78text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_78==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_78;
	pBaseMain_PAGERCALLED_78 = EbCreate(BaseMain_PAGERCALLED_78,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_78text,3,editbox);
	if(pBaseMain_PAGERCALLED_78==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_78;
	pBaseMain_TABLENUMBER_78 = EbCreate(BaseMain_TABLENUMBER_78,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_78text,3,editbox);
	if(pBaseMain_TABLENUMBER_78==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_78;
	pBaseMain_ORDERFOOD_78 = EbCreate(BaseMain_ORDERFOOD_78,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_78text,3,editbox);
	if(pBaseMain_ORDERFOOD_78==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager79(void)	
{	
	
	CreatePager78();
	//Pager 79
	EDITBOX *pBaseMain_PAGERNUMBER_79;
	pBaseMain_PAGERNUMBER_79 = EbCreate(BaseMain_PAGERNUMBER_79,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_79text,16,editbox);
	if(pBaseMain_PAGERNUMBER_79==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_79;
	pBaseMain_NUMBERGUEST_79 = EbCreate(BaseMain_NUMBERGUEST_79,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_79text,2,editbox);
	if(pBaseMain_NUMBERGUEST_79==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_79;
	pBaseMain_PAGERACTIVATED_79 = EbCreate(BaseMain_PAGERACTIVATED_79,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_79text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_79==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_79;
	pBaseMain_PAGERCALLED_79 = EbCreate(BaseMain_PAGERCALLED_79,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_79text,3,editbox);
	if(pBaseMain_PAGERCALLED_79==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_79;
	pBaseMain_TABLENUMBER_79 = EbCreate(BaseMain_TABLENUMBER_79,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_79text,3,editbox);
	if(pBaseMain_TABLENUMBER_79==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_79;
	pBaseMain_ORDERFOOD_79 = EbCreate(BaseMain_ORDERFOOD_79,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_79text,3,editbox);
	if(pBaseMain_ORDERFOOD_79==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
void CreatePager80(void)	
{	
	
	CreateBaseMain();
	//Pager 80
	EDITBOX *pBaseMain_PAGERNUMBER_80;
	pBaseMain_PAGERNUMBER_80 = EbCreate(BaseMain_PAGERNUMBER_80,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_80text,16,editbox);
	if(pBaseMain_PAGERNUMBER_80==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_80;
	pBaseMain_NUMBERGUEST_80 = EbCreate(BaseMain_NUMBERGUEST_80,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_80text,2,editbox);
	if(pBaseMain_NUMBERGUEST_80==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_80;
	pBaseMain_PAGERACTIVATED_80 = EbCreate(BaseMain_PAGERACTIVATED_80,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_80text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_80==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_80;
	pBaseMain_PAGERCALLED_80 = EbCreate(BaseMain_PAGERCALLED_80,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_80text,3,editbox);
	if(pBaseMain_PAGERCALLED_80==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_80;
	pBaseMain_TABLENUMBER_80 = EbCreate(BaseMain_TABLENUMBER_80,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_80text,3,editbox);
	if(pBaseMain_TABLENUMBER_80==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_80;
	pBaseMain_ORDERFOOD_80 = EbCreate(BaseMain_ORDERFOOD_80,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_80text,3,editbox);
	if(pBaseMain_ORDERFOOD_80==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager81(void)	
{	
	
	CreatePager80();
	//Pager 81
	EDITBOX *pBaseMain_PAGERNUMBER_81;
	pBaseMain_PAGERNUMBER_81 = EbCreate(BaseMain_PAGERNUMBER_81,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_81text,16,editbox);
	if(pBaseMain_PAGERNUMBER_81==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_81;
	pBaseMain_NUMBERGUEST_81 = EbCreate(BaseMain_NUMBERGUEST_81,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_81text,2,editbox);
	if(pBaseMain_NUMBERGUEST_81==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_81;
	pBaseMain_PAGERACTIVATED_81 = EbCreate(BaseMain_PAGERACTIVATED_81,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_81text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_81==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_81;
	pBaseMain_PAGERCALLED_81 = EbCreate(BaseMain_PAGERCALLED_81,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_81text,3,editbox);
	if(pBaseMain_PAGERCALLED_81==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_81;
	pBaseMain_TABLENUMBER_81 = EbCreate(BaseMain_TABLENUMBER_81,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_81text,3,editbox);
	if(pBaseMain_TABLENUMBER_81==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_81;
	pBaseMain_ORDERFOOD_81 = EbCreate(BaseMain_ORDERFOOD_81,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_81text,3,editbox);
	if(pBaseMain_ORDERFOOD_81==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager82(void)	
{	
	
	CreatePager81();
	//Pager 82
	EDITBOX *pBaseMain_PAGERNUMBER_82;
	pBaseMain_PAGERNUMBER_82 = EbCreate(BaseMain_PAGERNUMBER_82,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_82text,16,editbox);
	if(pBaseMain_PAGERNUMBER_82==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_82;
	pBaseMain_NUMBERGUEST_82 = EbCreate(BaseMain_NUMBERGUEST_82,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_82text,2,editbox);
	if(pBaseMain_NUMBERGUEST_82==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_82;
	pBaseMain_PAGERACTIVATED_82 = EbCreate(BaseMain_PAGERACTIVATED_82,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_82text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_82==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_82;
	pBaseMain_PAGERCALLED_82 = EbCreate(BaseMain_PAGERCALLED_82,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_82text,3,editbox);
	if(pBaseMain_PAGERCALLED_82==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_82;
	pBaseMain_TABLENUMBER_82 = EbCreate(BaseMain_TABLENUMBER_82,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_82text,3,editbox);
	if(pBaseMain_TABLENUMBER_82==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_82;
	pBaseMain_ORDERFOOD_82 = EbCreate(BaseMain_ORDERFOOD_82,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_82text,3,editbox);
	if(pBaseMain_ORDERFOOD_82==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager83(void)	
{	
	CreatePager82();
	//Pager 83
	EDITBOX *pBaseMain_PAGERNUMBER_83;
	pBaseMain_PAGERNUMBER_83 = EbCreate(BaseMain_PAGERNUMBER_83,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_83text,16,editbox);
	if(pBaseMain_PAGERNUMBER_83==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_83;
	pBaseMain_NUMBERGUEST_83 = EbCreate(BaseMain_NUMBERGUEST_83,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_83text,2,editbox);
	if(pBaseMain_NUMBERGUEST_83==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_83;
	pBaseMain_PAGERACTIVATED_83 = EbCreate(BaseMain_PAGERACTIVATED_83,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_83text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_83==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_83;
	pBaseMain_PAGERCALLED_83 = EbCreate(BaseMain_PAGERCALLED_83,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_83text,3,editbox);
	if(pBaseMain_PAGERCALLED_83==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_83;
	pBaseMain_TABLENUMBER_83 = EbCreate(BaseMain_TABLENUMBER_83,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_83text,3,editbox);
	if(pBaseMain_TABLENUMBER_83==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_83;
	pBaseMain_ORDERFOOD_83 = EbCreate(BaseMain_ORDERFOOD_83,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_83text,3,editbox);
	if(pBaseMain_ORDERFOOD_83==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager84(void)	
{	
	CreatePager83();
	//Pager 84
	EDITBOX *pBaseMain_PAGERNUMBER_84;
	pBaseMain_PAGERNUMBER_84 = EbCreate(BaseMain_PAGERNUMBER_84,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_84text,16,editbox);
	if(pBaseMain_PAGERNUMBER_84==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_84;
	pBaseMain_NUMBERGUEST_84 = EbCreate(BaseMain_NUMBERGUEST_84,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_84text,2,editbox);
	if(pBaseMain_NUMBERGUEST_84==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_84;
	pBaseMain_PAGERACTIVATED_84 = EbCreate(BaseMain_PAGERACTIVATED_84,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_84text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_84==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_84;
	pBaseMain_PAGERCALLED_84 = EbCreate(BaseMain_PAGERCALLED_84,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_84text,3,editbox);
	if(pBaseMain_PAGERCALLED_84==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_84;
	pBaseMain_TABLENUMBER_84 = EbCreate(BaseMain_TABLENUMBER_84,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_84text,3,editbox);
	if(pBaseMain_TABLENUMBER_84==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_84;
	pBaseMain_ORDERFOOD_84 = EbCreate(BaseMain_ORDERFOOD_84,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_84text,3,editbox);
	if(pBaseMain_ORDERFOOD_84==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
void CreatePager85(void)	
{	
	
	CreateBaseMain();	
	//Pager 85
	EDITBOX *pBaseMain_PAGERNUMBER_85;
	pBaseMain_PAGERNUMBER_85 = EbCreate(BaseMain_PAGERNUMBER_85,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_85text,16,editbox);
	if(pBaseMain_PAGERNUMBER_85==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_85;
	pBaseMain_NUMBERGUEST_85 = EbCreate(BaseMain_NUMBERGUEST_85,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_85text,2,editbox);
	if(pBaseMain_NUMBERGUEST_85==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_85;
	pBaseMain_PAGERACTIVATED_85 = EbCreate(BaseMain_PAGERACTIVATED_85,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_85text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_85==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_85;
	pBaseMain_PAGERCALLED_85 = EbCreate(BaseMain_PAGERCALLED_85,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_85text,3,editbox);
	if(pBaseMain_PAGERCALLED_85==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_85;
	pBaseMain_TABLENUMBER_85 = EbCreate(BaseMain_TABLENUMBER_85,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_85text,3,editbox);
	if(pBaseMain_TABLENUMBER_85==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_85;
	pBaseMain_ORDERFOOD_85 = EbCreate(BaseMain_ORDERFOOD_85,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_85text,3,editbox);
	if(pBaseMain_ORDERFOOD_85==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager86(void)	
{	
	
	CreatePager85();
	//Pager 86
	EDITBOX *pBaseMain_PAGERNUMBER_86;
	pBaseMain_PAGERNUMBER_86 = EbCreate(BaseMain_PAGERNUMBER_86,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_86text,16,editbox);
	if(pBaseMain_PAGERNUMBER_86==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_86;
	pBaseMain_NUMBERGUEST_86 = EbCreate(BaseMain_NUMBERGUEST_86,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_86text,2,editbox);
	if(pBaseMain_NUMBERGUEST_86==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_86;
	pBaseMain_PAGERACTIVATED_86 = EbCreate(BaseMain_PAGERACTIVATED_86,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_86text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_86==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_86;
	pBaseMain_PAGERCALLED_86 = EbCreate(BaseMain_PAGERCALLED_86,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_86text,3,editbox);
	if(pBaseMain_PAGERCALLED_86==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_86;
	pBaseMain_TABLENUMBER_86 = EbCreate(BaseMain_TABLENUMBER_86,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_86text,3,editbox);
	if(pBaseMain_TABLENUMBER_86==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_86;
	pBaseMain_ORDERFOOD_86 = EbCreate(BaseMain_ORDERFOOD_86,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_86text,3,editbox);
	if(pBaseMain_ORDERFOOD_86==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager87(void)	
{	
	
	CreatePager86();
	//Pager 87
	EDITBOX *pBaseMain_PAGERNUMBER_87;
	pBaseMain_PAGERNUMBER_87 = EbCreate(BaseMain_PAGERNUMBER_87,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_87text,16,editbox);
	if(pBaseMain_PAGERNUMBER_87==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_87;
	pBaseMain_NUMBERGUEST_87 = EbCreate(BaseMain_NUMBERGUEST_87,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_87text,2,editbox);
	if(pBaseMain_NUMBERGUEST_87==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_87;
	pBaseMain_PAGERACTIVATED_87 = EbCreate(BaseMain_PAGERACTIVATED_87,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_87text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_87==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_87;
	pBaseMain_PAGERCALLED_87 = EbCreate(BaseMain_PAGERCALLED_87,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_87text,3,editbox);
	if(pBaseMain_PAGERCALLED_87==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_87;
	pBaseMain_TABLENUMBER_87 = EbCreate(BaseMain_TABLENUMBER_87,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_87text,3,editbox);
	if(pBaseMain_TABLENUMBER_87==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_87;
	pBaseMain_ORDERFOOD_87 = EbCreate(BaseMain_ORDERFOOD_87,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_87text,3,editbox);
	if(pBaseMain_ORDERFOOD_87==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager88(void)	
{	
	
	CreatePager87();
	//Pager 88
	EDITBOX *pBaseMain_PAGERNUMBER_88;
	pBaseMain_PAGERNUMBER_88 = EbCreate(BaseMain_PAGERNUMBER_88,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_88text,16,editbox);
	if(pBaseMain_PAGERNUMBER_88==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_88;
	pBaseMain_NUMBERGUEST_88 = EbCreate(BaseMain_NUMBERGUEST_88,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_88text,2,editbox);
	if(pBaseMain_NUMBERGUEST_88==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_88;
	pBaseMain_PAGERACTIVATED_88 = EbCreate(BaseMain_PAGERACTIVATED_88,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_88text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_88==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_88;
	pBaseMain_PAGERCALLED_88 = EbCreate(BaseMain_PAGERCALLED_88,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_88text,3,editbox);
	if(pBaseMain_PAGERCALLED_88==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_88;
	pBaseMain_TABLENUMBER_88 = EbCreate(BaseMain_TABLENUMBER_88,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_88text,3,editbox);
	if(pBaseMain_TABLENUMBER_88==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_88;
	pBaseMain_ORDERFOOD_88 = EbCreate(BaseMain_ORDERFOOD_88,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_88text,3,editbox);
	if(pBaseMain_ORDERFOOD_88==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager89(void)	
{	
	
	CreatePager88();
	//Pager 89
	EDITBOX *pBaseMain_PAGERNUMBER_89;
	pBaseMain_PAGERNUMBER_89 = EbCreate(BaseMain_PAGERNUMBER_89,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_89text,16,editbox);
	if(pBaseMain_PAGERNUMBER_89==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_89;
	pBaseMain_NUMBERGUEST_89 = EbCreate(BaseMain_NUMBERGUEST_89,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_89text,2,editbox);
	if(pBaseMain_NUMBERGUEST_89==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_89;
	pBaseMain_PAGERACTIVATED_89 = EbCreate(BaseMain_PAGERACTIVATED_89,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_89text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_89==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_89;
	pBaseMain_PAGERCALLED_89 = EbCreate(BaseMain_PAGERCALLED_89,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_89text,3,editbox);
	if(pBaseMain_PAGERCALLED_89==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_89;
	pBaseMain_TABLENUMBER_89 = EbCreate(BaseMain_TABLENUMBER_89,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_89text,3,editbox);
	if(pBaseMain_TABLENUMBER_89==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_89;
	pBaseMain_ORDERFOOD_89 = EbCreate(BaseMain_ORDERFOOD_89,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_89text,3,editbox);
	if(pBaseMain_ORDERFOOD_89==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
void CreatePager90(void)	
{	
	
	CreateBaseMain();
	//Pager 90
	EDITBOX *pBaseMain_PAGERNUMBER_90;
	pBaseMain_PAGERNUMBER_90 = EbCreate(BaseMain_PAGERNUMBER_90,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_90text,16,editbox);
	if(pBaseMain_PAGERNUMBER_90==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_90;
	pBaseMain_NUMBERGUEST_90 = EbCreate(BaseMain_NUMBERGUEST_90,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_90text,2,editbox);
	if(pBaseMain_NUMBERGUEST_90==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_90;
	pBaseMain_PAGERACTIVATED_90 = EbCreate(BaseMain_PAGERACTIVATED_90,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_90text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_90==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_90;
	pBaseMain_PAGERCALLED_90 = EbCreate(BaseMain_PAGERCALLED_90,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_90text,3,editbox);
	if(pBaseMain_PAGERCALLED_90==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_90;
	pBaseMain_TABLENUMBER_90 = EbCreate(BaseMain_TABLENUMBER_90,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_90text,3,editbox);
	if(pBaseMain_TABLENUMBER_90==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_90;
	pBaseMain_ORDERFOOD_90 = EbCreate(BaseMain_ORDERFOOD_90,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_90text,3,editbox);
	if(pBaseMain_ORDERFOOD_90==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager91(void)	
{	
	
	CreatePager90();
	//Pager 91
	EDITBOX *pBaseMain_PAGERNUMBER_91;
	pBaseMain_PAGERNUMBER_91 = EbCreate(BaseMain_PAGERNUMBER_91,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_91text,16,editbox);
	if(pBaseMain_PAGERNUMBER_91==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_91;
	pBaseMain_NUMBERGUEST_91 = EbCreate(BaseMain_NUMBERGUEST_91,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_91text,2,editbox);
	if(pBaseMain_NUMBERGUEST_91==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_91;
	pBaseMain_PAGERACTIVATED_91 = EbCreate(BaseMain_PAGERACTIVATED_91,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_91text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_91==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_91;
	pBaseMain_PAGERCALLED_91 = EbCreate(BaseMain_PAGERCALLED_91,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_91text,3,editbox);
	if(pBaseMain_PAGERCALLED_91==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_91;
	pBaseMain_TABLENUMBER_91 = EbCreate(BaseMain_TABLENUMBER_91,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_91text,3,editbox);
	if(pBaseMain_TABLENUMBER_91==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_91;
	pBaseMain_ORDERFOOD_91 = EbCreate(BaseMain_ORDERFOOD_91,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_91text,3,editbox);
	if(pBaseMain_ORDERFOOD_91==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager92(void)	
{	
	
	CreatePager91();
	//Pager 92
	EDITBOX *pBaseMain_PAGERNUMBER_92;
	pBaseMain_PAGERNUMBER_92 = EbCreate(BaseMain_PAGERNUMBER_92,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_92text,16,editbox);
	if(pBaseMain_PAGERNUMBER_92==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_92;
	pBaseMain_NUMBERGUEST_92 = EbCreate(BaseMain_NUMBERGUEST_92,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_92text,2,editbox);
	if(pBaseMain_NUMBERGUEST_92==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_92;
	pBaseMain_PAGERACTIVATED_92 = EbCreate(BaseMain_PAGERACTIVATED_92,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_92text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_92==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_92;
	pBaseMain_PAGERCALLED_92 = EbCreate(BaseMain_PAGERCALLED_92,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_92text,3,editbox);
	if(pBaseMain_PAGERCALLED_92==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_92;
	pBaseMain_TABLENUMBER_92 = EbCreate(BaseMain_TABLENUMBER_92,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_92text,3,editbox);
	if(pBaseMain_TABLENUMBER_92==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_92;
	pBaseMain_ORDERFOOD_92 = EbCreate(BaseMain_ORDERFOOD_92,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_92text,3,editbox);
	if(pBaseMain_ORDERFOOD_92==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager93(void)	
{	
	
	CreatePager92();
	//Pager 93
	EDITBOX *pBaseMain_PAGERNUMBER_93;
	pBaseMain_PAGERNUMBER_93 = EbCreate(BaseMain_PAGERNUMBER_93,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_93text,16,editbox);
	if(pBaseMain_PAGERNUMBER_93==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_93;
	pBaseMain_NUMBERGUEST_93 = EbCreate(BaseMain_NUMBERGUEST_93,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_93text,2,editbox);
	if(pBaseMain_NUMBERGUEST_93==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_93;
	pBaseMain_PAGERACTIVATED_93 = EbCreate(BaseMain_PAGERACTIVATED_93,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_93text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_93==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_93;
	pBaseMain_PAGERCALLED_93 = EbCreate(BaseMain_PAGERCALLED_93,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_93text,3,editbox);
	if(pBaseMain_PAGERCALLED_93==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_93;
	pBaseMain_TABLENUMBER_93 = EbCreate(BaseMain_TABLENUMBER_93,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_93text,3,editbox);
	if(pBaseMain_TABLENUMBER_93==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_93;
	pBaseMain_ORDERFOOD_93 = EbCreate(BaseMain_ORDERFOOD_93,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_93text,3,editbox);
	if(pBaseMain_ORDERFOOD_93==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager94(void)	
{	
	
	CreatePager93();
	//Pager 94
	EDITBOX *pBaseMain_PAGERNUMBER_94;
	pBaseMain_PAGERNUMBER_94 = EbCreate(BaseMain_PAGERNUMBER_94,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_94text,16,editbox);
	if(pBaseMain_PAGERNUMBER_94==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_94;
	pBaseMain_NUMBERGUEST_94 = EbCreate(BaseMain_NUMBERGUEST_94,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_94text,2,editbox);
	if(pBaseMain_NUMBERGUEST_94==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_94;
	pBaseMain_PAGERACTIVATED_94 = EbCreate(BaseMain_PAGERACTIVATED_94,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_94text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_94==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_94;
	pBaseMain_PAGERCALLED_94 = EbCreate(BaseMain_PAGERCALLED_94,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_94text,3,editbox);
	if(pBaseMain_PAGERCALLED_94==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_94;
	pBaseMain_TABLENUMBER_94 = EbCreate(BaseMain_TABLENUMBER_94,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_94text,3,editbox);
	if(pBaseMain_TABLENUMBER_94==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_94;
	pBaseMain_ORDERFOOD_94 = EbCreate(BaseMain_ORDERFOOD_94,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_94text,3,editbox);
	if(pBaseMain_ORDERFOOD_94==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	

void CreatePager95(void)	
{	
	
	CreateBaseMain();		
	//Pager 95
	EDITBOX *pBaseMain_PAGERNUMBER_95;
	pBaseMain_PAGERNUMBER_95 = EbCreate(BaseMain_PAGERNUMBER_95,Left,Top,Right,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_95text,16,editbox);
	if(pBaseMain_PAGERNUMBER_95==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_95;
	pBaseMain_NUMBERGUEST_95 = EbCreate(BaseMain_NUMBERGUEST_95,Left+1*HorizontalShift,Top,Right+1*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_95text,2,editbox);
	if(pBaseMain_NUMBERGUEST_95==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_95;
	pBaseMain_PAGERACTIVATED_95 = EbCreate(BaseMain_PAGERACTIVATED_95,Left+2*HorizontalShift,Top,Right+2*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_95text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_95==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_95;
	pBaseMain_PAGERCALLED_95 = EbCreate(BaseMain_PAGERCALLED_95,Left+3*HorizontalShift,Top,Right+3*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_95text,3,editbox);
	if(pBaseMain_PAGERCALLED_95==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_95;
	pBaseMain_TABLENUMBER_95 = EbCreate(BaseMain_TABLENUMBER_95,Left+4*HorizontalShift,Top,Right+4*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_95text,3,editbox);
	if(pBaseMain_TABLENUMBER_95==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_95;
	pBaseMain_ORDERFOOD_95 = EbCreate(BaseMain_ORDERFOOD_95,Left+5*HorizontalShift,Top,Right+5*HorizontalShift,Bottom,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_95text,3,editbox);
	if(pBaseMain_ORDERFOOD_95==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager96(void)	
{	
	
	CreatePager95();
	//Pager 96
	EDITBOX *pBaseMain_PAGERNUMBER_96;
	pBaseMain_PAGERNUMBER_96 = EbCreate(BaseMain_PAGERNUMBER_96,Left+0*HorizontalShift,Top+1*VerticleShift,Right+0*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_96text,16,editbox);
	if(pBaseMain_PAGERNUMBER_96==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_96;
	pBaseMain_NUMBERGUEST_96 = EbCreate(BaseMain_NUMBERGUEST_96,Left+1*HorizontalShift,Top+1*VerticleShift,Right+1*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_96text,2,editbox);
	if(pBaseMain_NUMBERGUEST_96==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_96;
	pBaseMain_PAGERACTIVATED_96 = EbCreate(BaseMain_PAGERACTIVATED_96,Left+2*HorizontalShift,Top+1*VerticleShift,Right+2*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_96text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_96==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_96;
	pBaseMain_PAGERCALLED_96 = EbCreate(BaseMain_PAGERCALLED_96,Left+3*HorizontalShift,Top+1*VerticleShift,Right+3*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_96text,3,editbox);
	if(pBaseMain_PAGERCALLED_96==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_96;
	pBaseMain_TABLENUMBER_96 = EbCreate(BaseMain_TABLENUMBER_96,Left+4*HorizontalShift,Top+1*VerticleShift,Right+4*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_96text,3,editbox);
	if(pBaseMain_TABLENUMBER_96==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_96;
	pBaseMain_ORDERFOOD_96 = EbCreate(BaseMain_ORDERFOOD_96,Left+5*HorizontalShift,Top+1*VerticleShift,Right+5*HorizontalShift,Bottom+1*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_96text,3,editbox);
	if(pBaseMain_ORDERFOOD_96==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	
	
void CreatePager97(void)	
{	
	CreatePager96();
	//Pager 97
	EDITBOX *pBaseMain_PAGERNUMBER_97;
	pBaseMain_PAGERNUMBER_97 = EbCreate(BaseMain_PAGERNUMBER_97,Left+0*HorizontalShift,Top+2*VerticleShift,Right+0*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_97text,16,editbox);
	if(pBaseMain_PAGERNUMBER_97==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_97;
	pBaseMain_NUMBERGUEST_97 = EbCreate(BaseMain_NUMBERGUEST_97,Left+1*HorizontalShift,Top+2*VerticleShift,Right+1*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_97text,2,editbox);
	if(pBaseMain_NUMBERGUEST_97==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_97;
	pBaseMain_PAGERACTIVATED_97 = EbCreate(BaseMain_PAGERACTIVATED_97,Left+2*HorizontalShift,Top+2*VerticleShift,Right+2*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_97text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_97==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_97;
	pBaseMain_PAGERCALLED_97 = EbCreate(BaseMain_PAGERCALLED_97,Left+3*HorizontalShift,Top+2*VerticleShift,Right+3*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_97text,3,editbox);
	if(pBaseMain_PAGERCALLED_97==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_97;
	pBaseMain_TABLENUMBER_97 = EbCreate(BaseMain_TABLENUMBER_97,Left+4*HorizontalShift,Top+2*VerticleShift,Right+4*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_97text,3,editbox);
	if(pBaseMain_TABLENUMBER_97==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_97;
	pBaseMain_ORDERFOOD_97 = EbCreate(BaseMain_ORDERFOOD_97,Left+5*HorizontalShift,Top+2*VerticleShift,Right+5*HorizontalShift,Bottom+2*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_97text,3,editbox);
	if(pBaseMain_ORDERFOOD_97==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	

void CreatePager98(void)	
{	
	
	CreatePager97();
	//Pager 98
	EDITBOX *pBaseMain_PAGERNUMBER_98;
	pBaseMain_PAGERNUMBER_98 = EbCreate(BaseMain_PAGERNUMBER_98,Left+0*HorizontalShift,Top+3*VerticleShift,Right+0*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_98text,16,editbox);
	if(pBaseMain_PAGERNUMBER_98==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_98;
	pBaseMain_NUMBERGUEST_98 = EbCreate(BaseMain_NUMBERGUEST_98,Left+1*HorizontalShift,Top+3*VerticleShift,Right+1*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_98text,2,editbox);
	if(pBaseMain_NUMBERGUEST_98==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_98;
	pBaseMain_PAGERACTIVATED_98 = EbCreate(BaseMain_PAGERACTIVATED_98,Left+2*HorizontalShift,Top+3*VerticleShift,Right+2*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_98text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_98==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_98;
	pBaseMain_PAGERCALLED_98 = EbCreate(BaseMain_PAGERCALLED_98,Left+3*HorizontalShift,Top+3*VerticleShift,Right+3*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_98text,3,editbox);
	if(pBaseMain_PAGERCALLED_98==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_98;
	pBaseMain_TABLENUMBER_98 = EbCreate(BaseMain_TABLENUMBER_98,Left+4*HorizontalShift,Top+3*VerticleShift,Right+4*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_98text,3,editbox);
	if(pBaseMain_TABLENUMBER_98==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_98;
	pBaseMain_ORDERFOOD_98 = EbCreate(BaseMain_ORDERFOOD_98,Left+5*HorizontalShift,Top+3*VerticleShift,Right+5*HorizontalShift,Bottom+3*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_98text,3,editbox);
	if(pBaseMain_ORDERFOOD_98==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	

void CreatePager99(void)	
{	
	
	CreatePager98();
	//Pager 99
	EDITBOX *pBaseMain_PAGERNUMBER_99;
	pBaseMain_PAGERNUMBER_99 = EbCreate(BaseMain_PAGERNUMBER_99,Left+0*HorizontalShift,Top+4*VerticleShift,Right+0*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERNUMBER_99text,16,editbox);
	if(pBaseMain_PAGERNUMBER_99==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_NUMBERGUEST_99;
	pBaseMain_NUMBERGUEST_99 = EbCreate(BaseMain_NUMBERGUEST_99,Left+1*HorizontalShift,Top+4*VerticleShift,Right+1*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_NUMBERGUEST_99text,2,editbox);
	if(pBaseMain_NUMBERGUEST_99==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERACTIVATED_99;
	pBaseMain_PAGERACTIVATED_99 = EbCreate(BaseMain_PAGERACTIVATED_99,Left+2*HorizontalShift,Top+4*VerticleShift,Right+2*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERACTIVATED_99text,3,editbox);
	if(pBaseMain_PAGERACTIVATED_99==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_PAGERCALLED_99;
	pBaseMain_PAGERCALLED_99 = EbCreate(BaseMain_PAGERCALLED_99,Left+3*HorizontalShift,Top+4*VerticleShift,Right+3*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_PAGERCALLED_99text,3,editbox);
	if(pBaseMain_PAGERCALLED_99==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_TABLENUMBER_99;
	pBaseMain_TABLENUMBER_99 = EbCreate(BaseMain_TABLENUMBER_99,Left+4*HorizontalShift,Top+4*VerticleShift,Right+4*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_TABLENUMBER_99text,3,editbox);
	if(pBaseMain_TABLENUMBER_99==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pBaseMain_ORDERFOOD_99;
	pBaseMain_ORDERFOOD_99 = EbCreate(BaseMain_ORDERFOOD_99,Left+5*HorizontalShift,Top+4*VerticleShift,Right+5*HorizontalShift,Bottom+4*VerticleShift,MAXCHARSIZE,(XCHAR*)BaseMain_ORDERFOOD_99text,3,editbox);
	if(pBaseMain_ORDERFOOD_99==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}	


void CreatePagerSelect(void)
{
GOLFree();
	SetColor(0);
	ClearDevice();
	if(button != NULL) free(button);
	button = GOLCreateScheme();
	button->Color0 = 1024;
	button->Color1 = 64969;
	button->ColorDisabled = 55070;
	button->CommonBkColor = 0;
	button->EmbossDkColor = 0;
	button->EmbossLtColor = 44765;
	button->TextColor0 = 65535;
	button->TextColor1 = 31;
	button->pFont = (void*)&gentium_16_200_0_0_0_0;
	if(editbox != NULL) free(editbox);
	editbox = GOLCreateScheme();
	editbox->Color0 = 65535;
	editbox->Color1 = 64969;
	editbox->ColorDisabled = 55070;
	editbox->CommonBkColor = 55166;
	editbox->EmbossDkColor = 0;
	editbox->EmbossLtColor = 0;
	editbox->TextColor0 = 0;
	editbox->TextColor1 = 31;
	editbox->pFont = (void*)&gentium_16_200_0_0_0_0;
	if(text != NULL) free(text);
	text = GOLCreateScheme();
	text->Color0 = 19583;
	text->Color1 = 0;
	text->ColorDisabled = 55070;
	text->CommonBkColor = 65535;
	text->EmbossDkColor = 6172;
	text->EmbossLtColor = 44765;
	text->TextColor0 = 0;
	text->TextColor1 = 31;
	text->pFont = (void*)&gentium_16_200_0_0_0_0;

	BUTTON *pPagerSelect_Main;
	pPagerSelect_Main = BtnCreate(PagerSelect_Main,366,220,467,264,0,16384,NULL,(XCHAR*)PagerSelect_Maintext,button);
	if(pPagerSelect_Main==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	EDITBOX *pPagerSelect_OBJ_EDITBOX_7_4;
	pPagerSelect_OBJ_EDITBOX_7_4 = EbCreate(PagerSelect_OBJ_EDITBOX_7_4,101,93,369,196,16384,(XCHAR*)PagerSelect_OBJ_EDITBOX_7_4text,16,button);
	if(pPagerSelect_OBJ_EDITBOX_7_4==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
	STATICTEXT *pPagerSelect_OBJ_STATICTEXT_7_4;
	pPagerSelect_OBJ_STATICTEXT_7_4 = StCreate(PagerSelect_OBJ_STATICTEXT_7_4,45,55,200,85,16384,(XCHAR*)PagerSelect_OBJ_STATICTEXT_7_4text,text);
	if(pPagerSelect_OBJ_STATICTEXT_7_4==NULL){CreateError(0);while(1);} //Fatal Error, Check for memory leak or heap size
}


void (*CreateFunctionArray[NUM_GDD_SCREENS])(void)=
{
&CreateBaseMain,&CreatePagerSelect
};

void (*CreatePrimitivesFunctionArray[NUM_GDD_SCREENS])(void)=
{
NULL,NULL
};

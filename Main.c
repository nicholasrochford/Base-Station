/*****************************************************************************
 * Microchip Graphics Library
 * Graphics Display Designer (GDD) Template
 *****************************************************************************
 * FileName:        Main.c
 * Processor:       PIC24F, PIC24H, dsPIC, PIC32
 * Compiler:       	MPLAB C30/C32
 * Company:         Microchip Technology Incorporated
 *
 * Software License Agreement
 *
 * Copyright © 2010 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).  
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS” WITHOUT WARRANTY OF ANY
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
 * Date         Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *****************************************************************************/
#include "Main.h"
#include "GDD_Screens.h"
#include "BaseStationCall.H"

 BYTE app_update=0; //To manually switch screen
// Configuration bits
#if defined(__dsPIC33F__) || defined(__PIC24H__)
_FOSCSEL(FNOSC_PRI);
_FOSC(FCKSM_CSECMD &OSCIOFNC_OFF &POSCMD_XT);
_FWDT(FWDTEN_OFF);
#elif defined(__dsPIC33E__) || defined(__PIC24E__)
_FOSCSEL(FNOSC_FRC);			
_FOSC(FCKSM_CSECMD & POSCMD_XT & OSCIOFNC_OFF & IOL1WAY_OFF);
_FWDT(FWDTEN_OFF);
_FPOR(FPWRT_PWR128 & BOREN_ON & ALTI2C1_ON & ALTI2C2_ON);
_FICD(ICS_PGD1 & RSTPRI_PF & JTAGEN_OFF);
#elif defined(__PIC32MX__)
    #pragma config FPLLODIV = DIV_1, FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FWDTEN = OFF, FCKSM = CSECME, FPBDIV = DIV_1
    #pragma config OSCIOFNC = ON, POSCMOD = XT, FSOSCEN = ON, FNOSC = PRIPLL
    #pragma config CP = OFF, BWP = OFF, PWP = OFF
#else
    #if defined(__PIC24FJ256GB110__)
_CONFIG1(JTAGEN_OFF & GCP_OFF & GWRP_OFF & FWDTEN_OFF & ICS_PGx2)
_CONFIG2(0xF7FF & IESO_OFF & FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMOD_HS & FNOSC_PRIPLL & PLLDIV_DIV2 & IOL1WAY_OFF)
    #endif
    #if defined(__PIC24FJ256GA110__)
_CONFIG1(JTAGEN_OFF & GCP_OFF & GWRP_OFF & FWDTEN_OFF & ICS_PGx2)
_CONFIG2(IESO_OFF & FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMOD_HS & FNOSC_PRIPLL & IOL1WAY_OFF)
    #endif
    #if defined(__PIC24FJ128GA010__)
_CONFIG2(FNOSC_PRIPLL & POSCMOD_XT) // Primary XT OSC with PLL
_CONFIG1(JTAGEN_OFF & FWDTEN_OFF)   // JTAG off, watchdog timer off
    #endif
	#if defined (__PIC24FJ256GB210__)
_CONFIG1( WDTPS_PS32768 & FWPSA_PR128 & ALTVREF_ALTVREDIS & WINDIS_OFF & FWDTEN_OFF & ICS_PGx2 & GWRP_OFF & GCP_OFF & JTAGEN_OFF) 
_CONFIG2( POSCMOD_HS & IOL1WAY_OFF & OSCIOFNC_OFF & OSCIOFNC_OFF & FCKSM_CSDCMD & FNOSC_PRIPLL & PLL96MHZ_ON & PLLDIV_DIV2 & IESO_OFF)
_CONFIG3( WPFP_WPFP255 & SOSCSEL_SOSC & WUTSEL_LEG & WPDIS_WPDIS & WPCFG_WPCFGDIS & WPEND_WPENDMEM) 
	#endif
	#if defined (__PIC24FJ256DA210__)
_CONFIG1( WDTPS_PS32768 & FWPSA_PR128 & ALTVREF_ALTVREDIS & WINDIS_OFF & FWDTEN_OFF & ICS_PGx2 & GWRP_OFF & GCP_OFF & JTAGEN_OFF) 
_CONFIG2( POSCMOD_HS & IOL1WAY_OFF & OSCIOFNC_OFF & OSCIOFNC_OFF & FCKSM_CSDCMD & FNOSC_PRIPLL & PLL96MHZ_ON & PLLDIV_DIV2 & IESO_OFF)
_CONFIG3( WPFP_WPFP255 & SOSCSEL_EC & WUTSEL_LEG & ALTPMP_ALTPMPEN & WPDIS_WPDIS & WPCFG_WPCFGDIS & WPEND_WPENDMEM) 
	#endif	
#endif
/////////////////////////////////////////////////////////////////////////////
// SPI Device Initialization Function 
/////////////////////////////////////////////////////////////////////////////
#if defined (USE_SST25VF016)
    // initialize GFX3 SST25 flash SPI
    #define FlashInit(pInitData) SST25Init((DRV_SPI_INIT_DATA*)pInitData)                    
#elif defined (USE_MCHP25LC256)
    // initialize EEPROM on Explorer 16
    #define FlashInit(pInitData) MCHP25LC256Init((DRV_SPI_INIT_DATA*)pInitData)  
#elif defined (USE_M25P80)       
    #define FlashInit(pInitData) SST25Init((DRV_SPI_INIT_DATA*)pInitData)
#endif
  


/////////////////////////////////////////////////////////////////////////////
// SPI Channel settings
/////////////////////////////////////////////////////////////////////////////
#if defined (SPI_CHANNEL_1_ENABLE) || defined (SPI_CHANNEL_2_ENABLE) || defined (SPI_CHANNEL_3_ENABLE) || defined (SPI_CHANNEL_4_ENABLE)
    #if defined (USE_SST25VF016)
        #ifdef __PIC32MX
            const DRV_SPI_INIT_DATA SPI_Init_Data = {SST25_SPI_CHANNEL, 1, 0, 0, 1, 1, 0};
            #ifdef USE_TOUCHSCREEN_AR1020
                const DRV_SPI_INIT_DATA ar1020SpiInit = {AR1020_SPI_CHANNEL,    44, 0, 0, 0, 0, 0};
            #endif
        #else    
            const DRV_SPI_INIT_DATA SPI_Init_Data = {SST25_SPI_CHANNEL, 3, 6, 0, 1, 1, 0};
            #ifdef USE_TOUCHSCREEN_AR1020
                const DRV_SPI_INIT_DATA ar1020SpiInit = {AR1020_SPI_CHANNEL,    2,  3, 0, 0, 0, 0};        
            #endif
        #endif
    #elif defined (USE_MCHP25LC256)       
        const DRV_SPI_INIT_DATA SPI_Init_Data = {MCHP25LC256_SPI_CHANNEL, 6, 3, 0, 1, 1, 0};    
    #elif defined (USE_M25P80)
            const DRV_SPI_INIT_DATA SPI_Init_Data = {SST25_SPI_CHANNEL, 3, 6, 0, 1, 1, 0};
    #endif    
#endif

/////////////////////////////////////////////////////////////////////////////
// TouchScreen Init Values
/////////////////////////////////////////////////////////////////////////////
#ifdef USE_TOUCHSCREEN_RESISTIVE
#define TOUCH_INIT_VALUES   (NULL)
#endif
#ifdef USE_TOUCHSCREEN_AR1020
#define TOUCH_INIT_VALUES   ((void *)&ar1020SpiInit)
#endif

/////////////////////////////////////////////////////////////////////////////
//                            LOCAL PROTOTYPES
/////////////////////////////////////////////////////////////////////////////
void            TickInit(void);                 // starts tick counter
void 		InitializeBoard(void);

/* Start Main Program */
int main(void)
{
   
   GOL_MSG msg;                    // GOL message structure to interact with GOL
 
    InitializeBoard();

//////////////////////////////////////////////////////////////////////////////////////////
//  GDD Demo Stuff
/////////////////////////////////////////////////////////////////////////////////////////


GDDDemoCreateFirstScreen();

	keypress();
	
    while(1)
    {
        if(GOLDraw())               // Draw GOL object
        {
            TouchGetMsg(&msg);      // Get message from touch screen
			
            #if (NUM_GDD_SCREENS > 1)
			// GDD Readme:
			// The following line of code allows a GDD user to touch the touchscreen
			// to cycle through different static screens for viewing. This is useful as a
			// quick way to view how each screen looks on the physical target hardware.
			// This line of code should eventually be commented out for actual development.
			// Also note that widget/object names can be found in GDD_Screens.h
			//if(msg.uiEvent == EVENT_RELEASE) GDDDemoNextScreen();
			#endif

            GOLMsg(&msg);           // Process message
        }
    }//end while
    
}
//////////////////////////////////////////////////////////////////////
// State variables
/////////////////////////////////////////////////////////////////////
typedef enum
{
Create_BaseMain=0,
Create_PagerSelect,
Create_Pager0,
Create_Pager1,
Create_Pager2,
Create_Pager3,
Create_Pager4,
Create_Pager5,
Create_Pager6,
Create_Pager7,
Create_Pager8,
Create_Pager9,
Create_Pager10,
Create_Pager11,
Create_Pager12,
Create_Pager13,
Create_Pager14,
Create_Pager15,
Create_Pager16,
Create_Pager17,
Create_Pager18,
Create_Pager19,
Create_Pager20,
Create_Pager21,
Create_Pager22,
Create_Pager23,
Create_Pager24,
Create_Pager25,
Create_Pager26,
Create_Pager27,
Create_Pager28,
Create_Pager29,
Create_Pager30,
Create_Pager31,
Create_Pager32,
Create_Pager33,
Create_Pager34,
Create_Pager35,
Create_Pager36,
Create_Pager37,
Create_Pager38,
Create_Pager39,
Create_Pager40,
Create_Pager41,
Create_Pager42,
Create_Pager43,
Create_Pager44,
Create_Pager45,
Create_Pager46,
Create_Pager47,
Create_Pager48,
Create_Pager49,
Create_Pager50,
Create_Pager51,
Create_Pager52,
Create_Pager53,
Create_Pager54,
Create_Pager55,
Create_Pager56,
Create_Pager57,
Create_Pager58,
Create_Pager59,
Create_Pager60,
Create_Pager61,
Create_Pager62,
Create_Pager63,
Create_Pager64,
Create_Pager65,
Create_Pager66,
Create_Pager67,
Create_Pager68,
Create_Pager69,
Create_Pager70,
Create_Pager71,
Create_Pager72,
Create_Pager73,
Create_Pager74,
Create_Pager75,
Create_Pager76,
Create_Pager77,
Create_Pager78,
Create_Pager79,
Create_Pager80,
Create_Pager81,
Create_Pager82,
Create_Pager83,
Create_Pager84,
Create_Pager85,
Create_Pager86,
Create_Pager87,
Create_Pager88,
Create_Pager89,
Create_Pager90,
Create_Pager91,
Create_Pager92,
Create_Pager93,
Create_Pager94,
Create_Pager95,
Create_Pager96,
Create_Pager97,
Create_Pager98,
Create_Pager99,

}SCREEN_STATES;

SCREEN_STATES screenState=Create_Pager0;
SCREEN_STATES prevState=Create_BaseMain;
/////////////////////////////////////////////////////////////////////////////
// Function: WORD GOLMsgCallback(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg)
// Input: objMsg - translated message for the object,
//        pObj - pointer to the object,
//        pMsg - pointer to the non-translated, raw GOL message
// Output: if the function returns non-zero the message will be processed by default
// Overview: it's a user defined function. GOLMsg() function calls it each
//           time the valid message for the object received
/////////////////////////////////////////////////////////////////////////////
WORD GOLMsgCallback(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg)
{	

    WORD    objectID;	
	objectID = GetObjID(pObj);
	
		
			switch(screenState)
			{
				case Create_BaseMain:
					if (objectID == BaseMain_Next) //To add pager 0
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager0();
						screenState=Create_Pager1;
						}
					}
					break;
					
				case Create_Pager0:
					if (objectID == BaseMain_Next) //To add pager 0
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager0();
						screenState=Create_Pager1;
						}
					}
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreateBaseMain();
		    					screenState=Create_Pager0;
							}
						}
					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager1();
		    					screenState=Create_Pager1;
		    				}
						}   
							
					break;
					
				case Create_Pager1:
					if (objectID == BaseMain_Next) 
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager1();
						screenState=Create_Pager2;
						}
					}
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager0();
		    					screenState=Create_Pager0;
							}
						}
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager1();
		    					screenState=Create_Pager1;
		    				}
						}   
						
					break;
				
				case Create_Pager2:
					if (objectID == BaseMain_Next) 
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager2();
						screenState=Create_Pager3;
						}
					}
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager1();
		    					screenState=Create_Pager1;
							}
						}
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager2();
		    					screenState=Create_Pager2;
		    				}
						}   
						
					break;
				
					case Create_Pager3:
					if (objectID == BaseMain_Next) 
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager3();
						screenState=Create_Pager4;
						}
					}
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager2();
		    					screenState=Create_Pager2;
							}
						}
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager3();
		    					screenState=Create_Pager3;
		    				}
						}   
						
					break;
					
				case Create_Pager4:
					if (objectID == BaseMain_Next) 
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager4();
						screenState=Create_Pager5;
						}
					}
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager3();
		    					screenState=Create_Pager3;
							}
						}
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager4();
		    					screenState=Create_Pager4;
		    				}
						}   
						
					break;

				case Create_Pager5:
					if (objectID == BaseMain_Next) 
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager5();
						screenState=Create_Pager6;
						}
					}
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager4();
		    					screenState=Create_Pager4;
							}
						}
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager5();
		    					screenState=Create_Pager5;
		    				}
						}   
						
					break;
				
				case Create_Pager6:
					if (objectID == BaseMain_Next) 
					//BaseMain_Next
					//BaseMain_Back
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager6();
						screenState=Create_Pager7;
						}
					}
						if (objectID == BaseMain_Back)
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager4();
						screenState=Create_Pager4;
						}
					}

					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager5();
		    					screenState=Create_Pager5;
							}
						}
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager6();
		    					screenState=Create_Pager6;
		    				}
						}   
					break;
					
					case Create_Pager7:
					if (objectID == BaseMain_Next) 
					//BaseMain_Next
					//BaseMain_Back
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager7();
						screenState=Create_Pager8;
						}
					}
					if (objectID == BaseMain_Back)
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager4();
						screenState=Create_Pager4;
						}
					}

					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager6();
		    					screenState=Create_Pager6;
							}
						}
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager7();
		    					screenState=Create_Pager7;
		    				}
						}   
						
					break;										
					
					case Create_Pager8:
					if (objectID == BaseMain_Next) 
					//BaseMain_Next
					//BaseMain_Back
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager8();
						screenState=Create_Pager9;
						}
					}
					
					if (objectID == BaseMain_Back)
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager4();
						screenState=Create_Pager4;
						}
					}
					
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager7();
		    					screenState=Create_Pager7;
							}
						}
					if (objectID == BaseMain_Back)
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager4();
						screenState=Create_Pager4;
						}
					}

 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager8();
		    					screenState=Create_Pager8;
		    				}
						}   
						
					break;
						
					case Create_Pager9:
					if (objectID == BaseMain_Next) 
					//BaseMain_Next
					//BaseMain_Back
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager9();
						screenState=Create_Pager10;
						}
					}
				if (objectID == BaseMain_Back)
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager4();
						screenState=Create_Pager4;
						}
					}
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager8();
		    					screenState=Create_Pager8;
							}
						}
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager9();
		    					screenState=Create_Pager9;
		    				}
						}   
						
					break;
					
					case Create_Pager10:
					if (objectID == BaseMain_Next) 
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager10();
						screenState=Create_Pager11;
						}
					}
			
					if (objectID == BaseMain_Back)
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager9();
						screenState=Create_Pager9;
						}
					}
					
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager9();
		    					screenState=Create_Pager9;
							}
						}
						
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager10();
		    					screenState=Create_Pager10;
		    				}
						}   
								
					break;		
				
					case Create_Pager11:
					if (objectID == BaseMain_Next) 
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager11();
						screenState=Create_Pager12;
						}
					}
			
					if (objectID == BaseMain_Back)
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager9();
						screenState=Create_Pager9;
						}
					}
					
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager10();
		    					screenState=Create_Pager10;
							}
						}
						
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager11();
		    					screenState=Create_Pager11;
		    				}
						}   
								
					break;

					case Create_Pager12:
					if (objectID == BaseMain_Next) 
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager12();
						screenState=Create_Pager13;
						}
					}
			
					if (objectID == BaseMain_Back)
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager9();
						screenState=Create_Pager9;
						}
					}
					
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager11();
		    					screenState=Create_Pager11;
							}
						}
						
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager12();
		    					screenState=Create_Pager12;
		    				}
						}   
								
					break;
				
					case Create_Pager13:
					if (objectID == BaseMain_Next) 
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager13();
						screenState=Create_Pager14;
						}
					}
			
					if (objectID == BaseMain_Back)
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager9();
						screenState=Create_Pager9;
						}
					}
					
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager12();
		    					screenState=Create_Pager12;
							}
						}
						
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager13();
		    					screenState=Create_Pager13;
		    				}
						}   
								
					break;
					
					case Create_Pager14:
					if (objectID == BaseMain_Next) 
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager14();
						screenState=Create_Pager15;
						}
					}
			
					if (objectID == BaseMain_Back)
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager9();
						screenState=Create_Pager9;
						}
					}
					
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager13();
		    					screenState=Create_Pager13;
							}
						}
						
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager14();
		    					screenState=Create_Pager14;
		    				}
						}   
								
					break;	
					case Create_Pager15:
					if (objectID == BaseMain_Next) 
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager15();
						screenState=Create_Pager16;
						}
					}
			
					if (objectID == BaseMain_Back)
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager14();
						screenState=Create_Pager14;
						}
					}
					
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager14();
		    					screenState=Create_Pager14;
							}
						}
						
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager15();
		    					screenState=Create_Pager15;
		    				}
						}   
								
					break;
					case Create_Pager16:
					if (objectID == BaseMain_Next) 
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager16();
						screenState=Create_Pager17;
						}
					}
			
					if (objectID == BaseMain_Back)
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager14();
						screenState=Create_Pager14;
						}
					}
					
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager15();
		    					screenState=Create_Pager15;
							}
						}
						
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager16();
		    					screenState=Create_Pager16;
		    				}
						}   
								
					break;	
					case Create_Pager17:
					if (objectID == BaseMain_Next) 
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager17();
						screenState=Create_Pager18;
						}
					}
			
					if (objectID == BaseMain_Back)
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager14();
						screenState=Create_Pager14;
						}
					}
					
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager16();
		    					screenState=Create_Pager16;
							}
						}
						
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager17();
		    					screenState=Create_Pager17;
		    				}
						}   
								
					break;	
					
					case Create_Pager18:
					if (objectID == BaseMain_Next) 
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager18();
						screenState=Create_Pager19;
						}
					}
			
					if (objectID == BaseMain_Back)
   					{
						if(objMsg==BTN_MSG_RELEASED)
						{
						CreatePager14();
						screenState=Create_Pager14;
						}
					}
					
					if (objectID == BaseMain_Clear) //To clear info on main screen
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{ 
		    					CreatePager17();
		    					screenState=Create_Pager17;
							}
						}
						
 					if (objectID == BaseMain_Call) //To go to call screen from Base
    					{	
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePagerSelect();
							}
						}	 
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call
    					{
	  					if(objMsg == BTN_MSG_RELEASED)
	    					{
		    					CreatePager18();
		    					screenState=Create_Pager18;
		    				}
						}   
								
					break;		
////////////////////////////////////////////////////////////////
								
				case Create_Pager19:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager19();	
							screenState=Create_Pager20;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager14();	
							screenState=Create_Pager14;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager18();	
			    				screenState=Create_Pager18;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager19();	
			    				screenState=Create_Pager19;	
			    			}		
					}   			
								
					break;			
				case Create_Pager20:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager20();	
							screenState=Create_Pager21;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager19();	
							screenState=Create_Pager19;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager19();	
			    				screenState=Create_Pager19;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager20();	
			    				screenState=Create_Pager20;	
			    			}		
					}   			
								
					break;			
				case Create_Pager21:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager21();	
							screenState=Create_Pager22;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager19();	
							screenState=Create_Pager19;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager20();	
			    				screenState=Create_Pager20;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager21();	
			    				screenState=Create_Pager21;	
			    			}		
					}   			
								
					break;			
				case Create_Pager22:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager22();	
							screenState=Create_Pager23;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager19();	
							screenState=Create_Pager19;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager21();	
			    				screenState=Create_Pager21;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager22();	
			    				screenState=Create_Pager22;	
			    			}		
					}   			
								
					break;			
				case Create_Pager23:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager23();	
							screenState=Create_Pager24;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager19();	
							screenState=Create_Pager19;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager22();	
			    				screenState=Create_Pager22;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager23();	
			    				screenState=Create_Pager23;	
			    			}		
					}   			
								
					break;			
				case Create_Pager24:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager24();	
							screenState=Create_Pager25;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager19();	
							screenState=Create_Pager19;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager23();	
			    				screenState=Create_Pager23;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager24();	
			    				screenState=Create_Pager24;	
			    			}		
					}   			
								
					break;			
				case Create_Pager25:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager25();	
							screenState=Create_Pager26;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager24();	
							screenState=Create_Pager24;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager24();	
			    				screenState=Create_Pager24;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager25();	
			    				screenState=Create_Pager25;	
			    			}		
					}   			
								
					break;			
				case Create_Pager26:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager26();	
							screenState=Create_Pager27;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager24();	
							screenState=Create_Pager24;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager25();	
			    				screenState=Create_Pager25;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager26();	
			    				screenState=Create_Pager26;	
			    			}		
					}   			
								
					break;			
				case Create_Pager27:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager27();	
							screenState=Create_Pager28;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager24();	
							screenState=Create_Pager24;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager26();	
			    				screenState=Create_Pager26;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager27();	
			    				screenState=Create_Pager27;	
			    			}		
					}   			
								
					break;			
				case Create_Pager28:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager28();	
							screenState=Create_Pager29;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager24();	
							screenState=Create_Pager24;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager27();	
			    				screenState=Create_Pager27;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager28();	
			    				screenState=Create_Pager28;	
			    			}		
					}   			
								
					break;			
				case Create_Pager29:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager29();	
							screenState=Create_Pager30;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager24();	
							screenState=Create_Pager24;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager28();	
			    				screenState=Create_Pager28;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager29();	
			    				screenState=Create_Pager29;	
			    			}		
					}   			
								
					break;			
				case Create_Pager30:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager30();	
							screenState=Create_Pager31;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager29();	
							screenState=Create_Pager29;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager29();	
			    				screenState=Create_Pager29;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager30();	
			    				screenState=Create_Pager30;	
			    			}		
					}   			
								
					break;			
				case Create_Pager31:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager31();	
							screenState=Create_Pager32;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager29();	
							screenState=Create_Pager29;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager30();	
			    				screenState=Create_Pager30;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager31();	
			    				screenState=Create_Pager31;	
			    			}		
					}   			
								
					break;	
							
				case Create_Pager32:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager32();	
							screenState=Create_Pager33;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager29();	
							screenState=Create_Pager29;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager31();	
			    				screenState=Create_Pager31;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager32();	
			    				screenState=Create_Pager32;	
			    			}		
					}   			
								
					break;			
				case Create_Pager33:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager33();	
							screenState=Create_Pager34;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager29();	
							screenState=Create_Pager29;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager32();	
			    				screenState=Create_Pager32;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager33();	
			    				screenState=Create_Pager33;	
			    			}		
					}   			
								
					break;			
				case Create_Pager34:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager34();	
							screenState=Create_Pager35;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager29();	
							screenState=Create_Pager29;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager33();	
			    				screenState=Create_Pager33;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager34();	
			    				screenState=Create_Pager34;	
			    			}		
					}   			
								
					break;			
				case Create_Pager35:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager35();	
							screenState=Create_Pager36;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager34();	
							screenState=Create_Pager34;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager34();	
			    				screenState=Create_Pager34;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager35();	
			    				screenState=Create_Pager35;	
			    			}		
					}   			
								
					break;			
				case Create_Pager36:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager36();	
							screenState=Create_Pager37;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager34();	
							screenState=Create_Pager34;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager35();	
			    				screenState=Create_Pager35;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager36();	
			    				screenState=Create_Pager36;	
			    			}		
					}   			
								
					break;			
				case Create_Pager37:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager37();	
							screenState=Create_Pager38;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager34();	
							screenState=Create_Pager34;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager36();	
			    				screenState=Create_Pager36;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager37();	
			    				screenState=Create_Pager37;	
			    			}		
					}   			
								
					break;			
				case Create_Pager38:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager38();	
							screenState=Create_Pager39;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager34();	
							screenState=Create_Pager34;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager37();	
			    				screenState=Create_Pager37;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager38();	
			    				screenState=Create_Pager38;	
			    			}		
					}   			
								
					break;			
				case Create_Pager39:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager39();	
							screenState=Create_Pager40;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager34();	
							screenState=Create_Pager34;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager38();	
			    				screenState=Create_Pager38;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager39();	
			    				screenState=Create_Pager39;	
			    			}		
					}   			
								
					break;			
				case Create_Pager40:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager40();	
							screenState=Create_Pager41;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager39();	
							screenState=Create_Pager39;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager39();	
			    				screenState=Create_Pager39;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager40();	
			    				screenState=Create_Pager40;	
			    			}		
					}   			
								
					break;			
				case Create_Pager41:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager41();	
							screenState=Create_Pager42;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager39();	
							screenState=Create_Pager39;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager40();	
			    				screenState=Create_Pager40;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager41();	
			    				screenState=Create_Pager41;	
			    			}		
					}   			
								
					break;			
				case Create_Pager42:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager42();	
							screenState=Create_Pager43;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager39();	
							screenState=Create_Pager39;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager41();	
			    				screenState=Create_Pager41;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager42();	
			    				screenState=Create_Pager42;	
			    			}		
					}   			
								
					break;			
				case Create_Pager43:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager43();	
							screenState=Create_Pager44;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager39();	
							screenState=Create_Pager39;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager42();	
			    				screenState=Create_Pager42;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager43();	
			    				screenState=Create_Pager43;	
			    			}		
					}   			
								
					break;			
				case Create_Pager44:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager44();	
							screenState=Create_Pager45;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager39();	
							screenState=Create_Pager39;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager43();	
			    				screenState=Create_Pager43;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager44();	
			    				screenState=Create_Pager44;	
			    			}		
					}   			
								
					break;			
				case Create_Pager45:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager45();	
							screenState=Create_Pager46;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager44();	
							screenState=Create_Pager44;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager44();	
			    				screenState=Create_Pager44;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager45();	
			    				screenState=Create_Pager45;	
			    			}		
					}   			
								
					break;			
				case Create_Pager46:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager46();	
							screenState=Create_Pager47;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager44();	
							screenState=Create_Pager44;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager45();	
			    				screenState=Create_Pager45;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager46();	
			    				screenState=Create_Pager46;	
			    			}		
					}   			
								
					break;			
				case Create_Pager47:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager47();	
							screenState=Create_Pager48;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager44();	
							screenState=Create_Pager44;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager46();	
			    				screenState=Create_Pager46;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager47();	
			    				screenState=Create_Pager47;	
			    			}		
					}   			
								
					break;			
				case Create_Pager48:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager48();	
							screenState=Create_Pager49;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager44();	
							screenState=Create_Pager44;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager47();	
			    				screenState=Create_Pager47;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager48();	
			    				screenState=Create_Pager48;	
			    			}		
					}   			
								
					break;			
				case Create_Pager49:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager49();	
							screenState=Create_Pager50;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager44();	
							screenState=Create_Pager44;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager48();	
			    				screenState=Create_Pager48;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager49();	
			    				screenState=Create_Pager49;	
			    			}		
					}   			
								
					break;			
				case Create_Pager50:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager50();	
							screenState=Create_Pager51;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager49();	
							screenState=Create_Pager49;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager49();	
			    				screenState=Create_Pager49;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager50();	
			    				screenState=Create_Pager50;	
			    			}		
					}   			
								
					break;			
				case Create_Pager51:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager51();	
							screenState=Create_Pager52;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager49();	
							screenState=Create_Pager49;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager50();	
			    				screenState=Create_Pager50;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager51();	
			    				screenState=Create_Pager51;	
			    			}		
					}   			
								
					break;			
				case Create_Pager52:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager52();	
							screenState=Create_Pager53;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager49();	
							screenState=Create_Pager49;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager51();	
			    				screenState=Create_Pager51;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager52();	
			    				screenState=Create_Pager52;	
			    			}		
					}   			
								
					break;			
				case Create_Pager53:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager53();	
							screenState=Create_Pager54;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager49();	
							screenState=Create_Pager49;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager52();	
			    				screenState=Create_Pager52;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager53();	
			    				screenState=Create_Pager53;	
			    			}		
					}   			
								
					break;			
				case Create_Pager54:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager54();	
							screenState=Create_Pager55;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager49();	
							screenState=Create_Pager49;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager53();	
			    				screenState=Create_Pager53;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager54();	
			    				screenState=Create_Pager54;	
			    			}		
					}   			
								
					break;			
				case Create_Pager55:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager55();	
							screenState=Create_Pager56;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager54();	
							screenState=Create_Pager54;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager54();	
			    				screenState=Create_Pager54;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager55();	
			    				screenState=Create_Pager55;	
			    			}		
					}   			
								
					break;			
				case Create_Pager56:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager56();	
							screenState=Create_Pager57;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager54();	
							screenState=Create_Pager54;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager55();	
			    				screenState=Create_Pager55;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager56();	
			    				screenState=Create_Pager56;	
			    			}		
					}   			
								
					break;			
				case Create_Pager57:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager57();	
							screenState=Create_Pager58;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager54();	
							screenState=Create_Pager54;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager56();	
			    				screenState=Create_Pager56;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager57();	
			    				screenState=Create_Pager57;	
			    			}		
					}   			
								
					break;			
				case Create_Pager58:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager58();	
							screenState=Create_Pager59;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager54();	
							screenState=Create_Pager54;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager57();	
			    				screenState=Create_Pager57;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager58();	
			    				screenState=Create_Pager58;	
			    			}		
					}   			
								
					break;			
				case Create_Pager59:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager59();	
							screenState=Create_Pager60;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager54();	
							screenState=Create_Pager54;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager58();	
			    				screenState=Create_Pager58;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager59();	
			    				screenState=Create_Pager59;	
			    			}		
					}   			
								
					break;			
				case Create_Pager60:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager60();	
							screenState=Create_Pager61;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager59();	
							screenState=Create_Pager59;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager59();	
			    				screenState=Create_Pager59;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager60();	
			    				screenState=Create_Pager60;	
			    			}		
					}   			
								
					break;			
				case Create_Pager61:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager61();	
							screenState=Create_Pager62;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager59();	
							screenState=Create_Pager59;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager60();	
			    				screenState=Create_Pager60;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager61();	
			    				screenState=Create_Pager61;	
			    			}		
					}   			
								
					break;			
				case Create_Pager62:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager62();	
							screenState=Create_Pager63;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager59();	
							screenState=Create_Pager59;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager61();	
			    				screenState=Create_Pager61;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager62();	
			    				screenState=Create_Pager62;	
			    			}		
					}   			
								
					break;			
				case Create_Pager63:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager63();	
							screenState=Create_Pager64;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager59();	
							screenState=Create_Pager59;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager62();	
			    				screenState=Create_Pager62;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager63();	
			    				screenState=Create_Pager63;	
			    			}		
					}   			
								
					break;			
				case Create_Pager64:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager64();	
							screenState=Create_Pager65;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager59();	
							screenState=Create_Pager59;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager63();	
			    				screenState=Create_Pager63;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager64();	
			    				screenState=Create_Pager64;	
			    			}		
					}   			
								
					break;			
				case Create_Pager65:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager65();	
							screenState=Create_Pager66;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager64();	
							screenState=Create_Pager64;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager64();	
			    				screenState=Create_Pager64;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager65();	
			    				screenState=Create_Pager65;	
			    			}		
					}   			
								
					break;			
				case Create_Pager66:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager66();	
							screenState=Create_Pager67;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager64();	
							screenState=Create_Pager64;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager65();	
			    				screenState=Create_Pager65;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager66();	
			    				screenState=Create_Pager66;	
			    			}		
					}   			
								
					break;			
				case Create_Pager67:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager67();	
							screenState=Create_Pager68;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager64();	
							screenState=Create_Pager64;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager66();	
			    				screenState=Create_Pager66;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager67();	
			    				screenState=Create_Pager67;	
			    			}		
					}   			
								
					break;		
						
				case Create_Pager68:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager68();	
							screenState=Create_Pager69;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager64();	
							screenState=Create_Pager64;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager67();	
			    				screenState=Create_Pager67;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager68();	
			    				screenState=Create_Pager68;	
			    			}		
					}   			
								
					break;			
					
				case Create_Pager69:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager69();	
							screenState=Create_Pager70;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager64();	
							screenState=Create_Pager64;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager68();	
			    				screenState=Create_Pager68;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager69();	
			    				screenState=Create_Pager69;	
			    			}		
					}   			
								
					break;			
				case Create_Pager70:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager70();	
							screenState=Create_Pager71;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager69();	
							screenState=Create_Pager69;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager69();	
			    				screenState=Create_Pager69;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager70();	
			    				screenState=Create_Pager70;	
			    			}		
					}   			
								
					break;			
				case Create_Pager71:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager71();	
							screenState=Create_Pager72;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager69();	
							screenState=Create_Pager69;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager70();	
			    				screenState=Create_Pager70;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager71();	
			    				screenState=Create_Pager71;	
			    			}		
					}   			
								
					break;			
				case Create_Pager72:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager72();	
							screenState=Create_Pager73;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager69();	
							screenState=Create_Pager69;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager71();	
			    				screenState=Create_Pager71;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager72();	
			    				screenState=Create_Pager72;	
			    			}		
					}   			
								
					break;			
				case Create_Pager73:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager73();	
							screenState=Create_Pager74;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager69();	
							screenState=Create_Pager69;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager72();	
			    				screenState=Create_Pager72;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager73();	
			    				screenState=Create_Pager73;	
			    			}		
					}   			
								
					break;			
				case Create_Pager74:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager74();	
							screenState=Create_Pager75;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager69();
							screenState=Create_Pager69;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager73();	
			    				screenState=Create_Pager73;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager74();	
			    				screenState=Create_Pager74;	
			    			}		
					}   			
								
					break;			
				case Create_Pager75:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager75();	
							screenState=Create_Pager76;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager74();	
							screenState=Create_Pager74;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager74();	
			    				screenState=Create_Pager74;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager75();	
			    				screenState=Create_Pager75;	
			    			}		
					}   			
								
					break;			
				case Create_Pager76:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager76();	
							screenState=Create_Pager77;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager74();	
							screenState=Create_Pager74;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager75();	
			    				screenState=Create_Pager75;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager76();	
			    				screenState=Create_Pager76;	
			    			}		
					}   			
								
					break;			
				case Create_Pager77:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager77();	
							screenState=Create_Pager78;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager74();	
							screenState=Create_Pager74;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager76();	
			    				screenState=Create_Pager76;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager77();	
			    				screenState=Create_Pager77;	
			    			}		
					}   			
								
					break;			
				case Create_Pager78:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager78();	
							screenState=Create_Pager79;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager74();	
							screenState=Create_Pager74;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager77();	
			    				screenState=Create_Pager77;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager78();	
			    				screenState=Create_Pager78;	
			    			}		
					}   			
								
					break;			
				case Create_Pager79:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager79();	
							screenState=Create_Pager80;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager74();	
							screenState=Create_Pager74;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager78();	
			    				screenState=Create_Pager78;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager79();	
			    				screenState=Create_Pager79;	
			    			}		
					}   			
								
					break;			
				case Create_Pager80:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager80();	
							screenState=Create_Pager81;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager79();	
							screenState=Create_Pager79;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager79();	
			    				screenState=Create_Pager79;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager80();	
			    				screenState=Create_Pager80;	
			    			}		
					}   			
								
					break;			
				case Create_Pager81:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager81();	
							screenState=Create_Pager82;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager79();	
							screenState=Create_Pager79;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager80();	
			    				screenState=Create_Pager80;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager81();	
			    				screenState=Create_Pager81;	
			    			}		
					}   			
								
					break;			
				case Create_Pager82:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager82();	
							screenState=Create_Pager83;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager79();	
							screenState=Create_Pager79;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager81();	
			    				screenState=Create_Pager81;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager82();	
			    				screenState=Create_Pager82;	
			    			}		
					}   			
								
					break;			
				case Create_Pager83:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager83();	
							screenState=Create_Pager84;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager79();	
							screenState=Create_Pager79;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager82();	
			    				screenState=Create_Pager82;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager83();	
			    				screenState=Create_Pager83;	
			    			}		
					}   			
								
					break;		
						
				case Create_Pager84:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager84();	
							screenState=Create_Pager85;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager79();	
							screenState=Create_Pager79;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager83();	
			    				screenState=Create_Pager83;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager84();	
			    				screenState=Create_Pager84;	
			    			}		
					}   			
								
					break;			
				case Create_Pager85:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager85();	
							screenState=Create_Pager86;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager84();	
							screenState=Create_Pager84;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager84();	
			    				screenState=Create_Pager84;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager85();	
			    				screenState=Create_Pager85;	
			    			}		
					}   			
								
					break;			
				case Create_Pager86:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager86();	
							screenState=Create_Pager87;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager84();	
							screenState=Create_Pager84;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager85();	
			    				screenState=Create_Pager85;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager86();	
			    				screenState=Create_Pager86;	
			    			}		
					}   			
								
					break;			
				case Create_Pager87:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager87();	
							screenState=Create_Pager88;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager84();	
							screenState=Create_Pager84;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager86();	
			    				screenState=Create_Pager86;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager87();	
			    				screenState=Create_Pager87;	
			    			}		
					}   			
								
					break;			
				case Create_Pager88:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager88();	
							screenState=Create_Pager89;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager84();	
							screenState=Create_Pager84;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager87();	
			    				screenState=Create_Pager87;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager88();	
			    				screenState=Create_Pager88;	
			    			}		
					}   			
								
					break;			
				case Create_Pager89:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager89();	
							screenState=Create_Pager90;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager84();	
							screenState=Create_Pager84;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager88();	
			    				screenState=Create_Pager88;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager89();	
			    				screenState=Create_Pager89;	
			    			}		
					}   			
								
					break;			
				case Create_Pager90:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager90();	
							screenState=Create_Pager91;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager89();	
							screenState=Create_Pager89;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager89();	
			    				screenState=Create_Pager89;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager90();	
			    				screenState=Create_Pager90;	
			    			}		
					}   			
								
					break;			
				case Create_Pager91:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager91();	
							screenState=Create_Pager92;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager89();	
							screenState=Create_Pager89;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager90();	
			    				screenState=Create_Pager90;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager91();	
			    				screenState=Create_Pager91;	
			    			}		
					}   			
								
					break;			
				case Create_Pager92:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager92();	
							screenState=Create_Pager93;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager89();	
							screenState=Create_Pager89;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager91();	
			    				screenState=Create_Pager91;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager92();	
			    				screenState=Create_Pager92;	
			    			}		
					}   			
								
					break;			
				case Create_Pager93:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager93();	
							screenState=Create_Pager94;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager89();	
							screenState=Create_Pager89;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager92();	
			    				screenState=Create_Pager92;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager93();	
			    				screenState=Create_Pager93;	
			    			}		
					}   			
								
					break;			
				case Create_Pager94:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager94();	
							screenState=Create_Pager95;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager89();	
							screenState=Create_Pager89;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager93();	
			    				screenState=Create_Pager93;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager94();	
			    				screenState=Create_Pager94;	
			    			}		
					}   			
								
					break;			
				case Create_Pager95:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager95();	
							screenState=Create_Pager96;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager94();	
							screenState=Create_Pager94;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager94();	
			    				screenState=Create_Pager94;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager95();	
			    				screenState=Create_Pager95;	
			    			}		
					}   			
								
					break;			
				case Create_Pager96:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager96();	
							screenState=Create_Pager97;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager94();	
							screenState=Create_Pager94;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager95();	
			    				screenState=Create_Pager95;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager96();	
			    				screenState=Create_Pager96;	
			    			}		
					}   			
								
					break;			
				case Create_Pager97:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager97();	
							screenState=Create_Pager98;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager94();	
							screenState=Create_Pager94;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager96();	
			    				screenState=Create_Pager96;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager97();	
			    				screenState=Create_Pager97;	
			    			}		
					}   			
								
					break;			
				case Create_Pager98:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager98();	
							screenState=Create_Pager99;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager94();	
							screenState=Create_Pager94;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager97();	
			    				screenState=Create_Pager97;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager98();	
			    				screenState=Create_Pager98;	
			    			}		
					}   			
								
					break;			
				case Create_Pager99:				
					if (objectID == BaseMain_Next) 			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager99();	
							screenState=Create_Pager99;	
						}		
					}			
								
					if (objectID == BaseMain_Back)			
   					{			
						if(objMsg==BTN_MSG_RELEASED)		
						{		
							CreatePager94();	
							screenState=Create_Pager94;	
						}		
					}			
								
					if (objectID == BaseMain_Clear) //To clear info on main screen			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{ 		
			    				CreatePager98();	
			    				screenState=Create_Pager98;	
							}	
						}		
								
 					if (objectID == BaseMain_Call) //To go to call screen from Base			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    			CreatePagerSelect();		
						}		
					}	 		
					if (objectID == PagerSelect_Main) //To go to Main Screen from Call			
    					{			
		  				if(objMsg == BTN_MSG_RELEASED)		
		    				{		
			    				CreatePager99();	
			    				screenState=Create_Pager99;	
			    			}		
					}   			
								
					break;			


///////////////////////////////////////////////////////////////																									
				default:
				prevState=screenState;
				break;
			}
				
		return(1);
}
	




/////////////////////////////////////////////////////////////////////////////
// Function: WORD GOLDrawCallback()
// Output: if the function returns non-zero the draw control will be passed to GOL
// Overview: it's a user defined function. GOLDraw() function calls it each
//           time when GOL objects drawing is completed. User drawing should be done here.
//           GOL will not change color, line type and clipping region settings while
//           this function returns zero.
/////////////////////////////////////////////////////////////////////////////
WORD GOLDrawCallback(void)
{
    GDDDemoGOLDrawCallback();

    // Add additional code here...				
    return (1);
}//End of GDD demo stuff
////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// Function: Timer3 ISR
// Input: none
// Output: none
// Overview: increments tick counter. Tick is approx. 1 ms.
/////////////////////////////////////////////////////////////////////////////
#ifdef __PIC32MX__
    #define __T3_ISR    __ISR(_TIMER_3_VECTOR, ipl4)
#else
    #define __T3_ISR    __attribute__((interrupt, shadow, auto_psv))
#endif

/* */
void __T3_ISR _T3Interrupt(void)
{
    TMR3 = 0;
    // Clear flag
    #ifdef __PIC32MX__
    mT3ClearIntFlag();
    #else
    IFS0bits.T3IF = 0;
    #endif

    TouchDetectPosition();
}

/////////////////////////////////////////////////////////////////////////////
// Function: void TickInit(void)
// Input: none
// Output: none
// Overview: Initilizes the tick timer.
/////////////////////////////////////////////////////////////////////////////

/*********************************************************************
 * Section: Tick Delay
 *********************************************************************/
#define SAMPLE_PERIOD       500 // us
#define TICK_PERIOD			(GetPeripheralClock() * SAMPLE_PERIOD) / 4000000

/* */
void TickInit(void)
{

    // Initialize Timer4
    #ifdef __PIC32MX__
    OpenTimer3(T3_ON | T3_PS_1_8, TICK_PERIOD);
    ConfigIntTimer3(T3_INT_ON | T3_INT_PRIOR_4);
    #else
    TMR3 = 0;
    PR3 = TICK_PERIOD;
    IFS0bits.T3IF = 0;  //Clear flag
    IEC0bits.T3IE = 1;  //Enable interrupt
    T3CONbits.TON = 1;  //Run timer
    #endif
    
}



/////////////////////////////////////////////////////////////////////////////
// Function: InitializeBoard()
// Input: none
// Output: none
// Overview: Initializes the hardware components including the PIC device
//           used.
/////////////////////////////////////////////////////////////////////////////
void InitializeBoard(void)
{

    #if defined (PIC24FJ256DA210_DEV_BOARD) && defined(USE_KEYBOARD)
    
     ANSA = 0x0000;
     ANSB = 0x0020;		// RB5 as potentiometer input
     ANSC = 0x0010;		// RC4 as touch screen X+, RC14 as external source of secondary oscillator
     ANSD = 0x0000;
     ANSE = 0x0000;		// RE9 used as S2
     ANSF = 0x0000;
     ANSG = 0x0080;		// RG8 used as S1, RG7 as touch screen Y+
        
    #else
        /////////////////////////////////////////////////////////////////////////////
        // ADC Explorer 16 Development Board Errata (work around 2)
        // RB15 should be output
        /////////////////////////////////////////////////////////////////////////////
        #ifndef MEB_BOARD
            LATBbits.LATB15 = 0;
            TRISBbits.TRISB15 = 0;
        #endif
    #endif


        #ifdef MEB_BOARD
            CPLDInitialize();
            CPLDSetGraphicsConfiguration(GRAPHICS_HW_CONFIG);
            CPLDSetSPIFlashConfiguration(SPI_FLASH_CHANNEL);
        #endif // #ifdef MEB_BOARD

    #if defined(__dsPIC33F__) || defined(__PIC24H__) || defined(__dsPIC33E__) || defined(__PIC24E__)

        // Configure Oscillator to operate the device at 40Mhz
        // Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
        #if defined(__dsPIC33E__) || defined(__PIC24E__)
			//Fosc = 8M * 60/(2*2) = 120MHz for 8M input clock
			PLLFBD = 58;    			// M=60         
		#else
        	// Fosc= 8M*40(2*2)=80Mhz for 8M input clock
        	PLLFBD = 38;                    // M=40
        #endif
        CLKDIVbits.PLLPOST = 0;         // N1=2
        CLKDIVbits.PLLPRE = 0;          // N2=2
        OSCTUN = 0;                     // Tune FRC oscillator, if FRC is used
    
        // Disable Watch Dog Timer
        RCONbits.SWDTEN = 0;
    
        // Clock switching to incorporate PLL
        __builtin_write_OSCCONH(0x03);  // Initiate Clock Switch to Primary
    
        // Oscillator with PLL (NOSC=0b011)
        __builtin_write_OSCCONL(0x01);  // Start clock switching
        while(OSCCONbits.COSC != 0b011);
    
        // Wait for Clock switch to occur	
        // Wait for PLL to lock
        while(OSCCONbits.LOCK != 1)
        { };
 
       #if defined(__dsPIC33F__) || defined(__PIC24H__)
        // Set PMD0 pin functionality to digital
        AD1PCFGL = AD1PCFGL | 0x1000;

        #if defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__)
            AD1PCFGLbits.PCFG6 = 1;
            AD1PCFGLbits.PCFG7 = 1;
            AD1PCFGLbits.PCFG8 = 1;
        #endif
        
        #elif defined(__dsPIC33E__) || defined(__PIC24E__)
            ANSELE = 0x00;
            ANSELDbits.ANSD6 = 0;

		    // Set all touch screen related pins to Analog mode.
	        ANSELBbits.ANSB11 = 1; 
        #endif

    #elif defined(__PIC32MX__)
        INTEnableSystemMultiVectoredInt();
        SYSTEMConfigPerformance(GetSystemClock());
    #endif // #if defined(__dsPIC33F__) || defined(__PIC24H__)
    

    #if defined (EXPLORER_16)
/************************************************************************
* For Explorer 16 RD12 is connected to EEPROM chip select.
* To prevent a conflict between this EEPROM and SST25 flash
* the chip select of the EEPROM SPI should be pulled up.
************************************************************************/
        // Set IOs directions for EEPROM SPI
        MCHP25LC256_CS_LAT = 1;			    // set initial CS value to 1 (not asserted)
    	MCHP25LC256_CS_TRIS = 0;			// set CS pin to output
	#endif // #if defined (EXPLORER_16)

    // Initialize graphics library and create default style scheme for GOL
    GOLInit();  
    
// Set the other chip selects to a known state
#ifdef MIKRO_BOARD
    // SD Card chip select
    LATGbits.LATG9 = 1;
    TRISGbits.TRISG9 = 0;
    
    // MP3 Codac
    // reset
    LATAbits.LATA5 = 0;
    TRISAbits.TRISA5 = 0;
    // chip select
    LATAbits.LATA2 = 1;
    TRISAbits.TRISA2 = 0;
    // chip select
    LATAbits.LATA3 = 1;
    TRISAbits.TRISA3 = 0;

    AD1PCFGbits.PCFG11 = 1;
    AD1PCFGbits.PCFG10 = 1;
#endif

    //The following are PIC device specific settings for the SPI channel
    //used. 
    
    //Set IOs directions for SST25 SPI
    #if defined (GFX_PICTAIL_V3) || defined (MEB_BOARD) || defined(GFX_PICTAIL_LCC) || defined(MIKRO_BOARD) || defined(GFX_PICTAIL_V3E)
	    
        SST25_CS_LAT = 1;
        SST25_CS_TRIS = 0;
  
        #ifndef __PIC32MX__
            SST25_SCK_TRIS = 0;
            SST25_SDO_TRIS = 0;
            SST25_SDI_TRIS = 1;
            #if defined(__PIC24FJ256GB210__) || defined(__dsPIC33E__) || defined(__PIC24E__)
            	SST25_SDI_ANS = 0;
    	    #endif
        #endif
    #elif defined (PIC24FJ256DA210_DEV_BOARD)
        SST25_CS_LAT = 1;
        SST25_CS_TRIS = 0;
    
        // Set the pins to be digital 
    	SST25_SDI_ANS = 0;
        SST25_SDO_ANS = 0;

        SST25_SCK_TRIS = 0;
        SST25_SDO_TRIS = 0;
        SST25_SDI_TRIS = 1;
        
    #elif defined (GFX_PICTAIL_V2)
        
        MCHP25LC256_CS_LAT = 1;
        MCHP25LC256_CS_TRIS = 0;
        MCHP25LC256_SCK_TRIS  = 0;
	    MCHP25LC256_SDO_TRIS = 0;
	    MCHP25LC256_SDI_TRIS = 1;
	    
	#endif

    // set the peripheral pin select for the PSI channel used
    #if defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__)
        AD1PCFGL = 0xFFFF;
        RPOR9bits.RP18R = 11;                   // assign RP18 for SCK2
        RPOR8bits.RP16R = 10;                   // assign RP16 for SDO2
        RPINR22bits.SDI2R = 17;                 // assign RP17 for SDI2	
    #elif defined(__PIC24FJ256GB110__) || defined(__PIC24FJ256GA110__) || defined (__PIC24FJ256GB210__)
        __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS
        RPOR10bits.RP21R = 11;                  // assign RP21 for SCK2
        RPOR9bits.RP19R = 10;                   // assign RP19 for SDO2
        RPINR22bits.SDI2R = 26;                 // assign RP26 for SDI2
        __builtin_write_OSCCONL(OSCCON | 0x40); // lock   PPS
    #elif defined(__PIC24FJ256DA210__)

        __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS

    	#if (SST25_SPI_CHANNEL == 1)
    	    RPOR1bits.RP2R = 8;                 // assign RP2 for SCK1
    	    RPOR0bits.RP1R = 7;                 // assign RP1 for SDO1
    	    RPINR20bits.SDI1R = 0;              // assign RP0 for SDI1
        #elif (SST25_SPI_CHANNEL == 2)
            RPOR1bits.RP2R = 11;                // assign RP2 for SCK2
    	    RPOR0bits.RP1R = 10;                // assign RP1 for SDO2
    	    RPINR22bits.SDI2R = 0;              // assign RP0 for SDI2
    	#endif

        __builtin_write_OSCCONL(OSCCON | 0x40); // lock   PPS

    #endif

	// initialize the Flash Memory driver
    FlashInit(&SPI_Init_Data);
   
    // initialize the timer that manages the tick counter
    TickInit(); 
                      
    // initialize the components for Resistive Touch Screen
    TouchInit(NVMWrite, NVMRead, NVMSectorErase, TOUCH_INIT_VALUES);   
                
    HardwareButtonInit();           	// Initialize the hardware buttons

}    


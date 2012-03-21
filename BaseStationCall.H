//
//BaseStationCall.h
//
#ifndef BaseStationCall
#define BaseStationCall
void GDDDemoCreateFirstScreen(void);
void GDDDemoGOLMsgCallback(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg);
void GDDDemoGOLDrawCallback(void);
void GDDDemoNextScreen(void);
extern const FONT_FLASH gentium_16_200_0_0_0_0;
int keypress();
void CreatePagerSelect(void); //Pager Call Screen is called
#define PagerSelect_Main   22
#define PagerSelect_OBJ_EDITBOX_7_4   23
#define PagerSelect_OBJ_STATICTEXT_7_4   24
#define PagerSelect_OBJ_WINDOW_4   25
#endif

/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _COMMON_API_H_
#define _COMMON_API_H_
//
#include <windows.h>

/////////////////////////////////////////////////////////////////////////////////
//
// �궨��
//
/////////////////////////////////////////////////////////////////////////////////

//=================================================================================
//
// Sprite����������߽���ײ��Ӧ����( ��ײ֮��API OnSpriteColWorldLimit �������� )
enum EWorldLimit
{
	WORLD_LIMIT_OFF,			// �ر�������߽����ײ
	WORLD_LIMIT_NULL,			// ��ײ֮�����治���κδ����ɸ���Ϸ�Լ�������Ӧ
	WORLD_LIMIT_RIGID,			// ����������ײ��Ӧ
	WORLD_LIMIT_BOUNCE,			// ����ģʽ
	WORLD_LIMIT_CLAMP,			// С����������ֹͣģʽ(�����������)
	WORLD_LIMIT_STICKY,			// ��ײ֮��ֹ
	WORLD_LIMIT_KILL,			// ��ײ֮���齫��ɾ��

	WORLD_LIMIT_INVALID,		//	��Чֵ
};
//================================================================================
//
/// �����뾫��֮�䡢�������ͼ����������֮�����ײ��Ӧ( ��ײ֮��API OnSpriteColSprite �������� )
enum ECollisionResponse
{
	COL_RESPONSE_OFF,			//	�ر���ײ��Ӧ(������OnSpriteColSprite)

	COL_RESPONSE_RIGID,			//	����������ײ��Ӧ
	COL_RESPONSE_BOUNCE,		//	����ģʽ
	COL_RESPONSE_CLAMP,			//	С����������ֹͣģʽ(�����������)
	COL_RESPONSE_STICKY,		//	��ײ֮��ֹ
	COL_RESPONSE_KILL,			//	��ײ֮���齫��ɾ��
	COL_RESPONSE_CUSTOM,		//	��ײ֮�����治���κδ����ɸ���Ϸ�Լ�������Ӧ

	COL_RESPONSE_INVALID,		//	��Чֵ
};
//================================================================================
//
// ��갴��ֵ����
enum MouseTypes 
{
	MOUSE_LEFT		=	0,		// ���
	MOUSE_RIGHT		=	1,		// �Ҽ�
	MOUSE_MIDDLE	=	2		// �м�
};
//================================================================================
//
// ����KEYֵ����
enum KeyCodes 
{
   KEY_NULL          = 0x000,     ///< Invalid KeyCode
   KEY_BACKSPACE     = 0x001,
   KEY_TAB           = 0x002,
   KEY_ENTER         = 0x003,
   KEY_CONTROL       = 0x004,
   KEY_ALT           = 0x005,
   KEY_SHIFT         = 0x006,
   KEY_PAUSE         = 0x007,
   KEY_CAPSLOCK      = 0x008,
   KEY_ESCAPE        = 0x009,
   KEY_SPACE         = 0x00a,
   KEY_PAGE_DOWN     = 0x00b,
   KEY_PAGE_UP       = 0x00c,
   KEY_END           = 0x00d,
   KEY_HOME          = 0x00e,
   KEY_LEFT          = 0x00f,
   KEY_UP            = 0x010,
   KEY_RIGHT         = 0x011,
   KEY_DOWN          = 0x012,
   KEY_PRINT         = 0x013,
   KEY_INSERT        = 0x014,
   KEY_DELETE        = 0x015,
   KEY_HELP          = 0x016,

   KEY_0             = 0x017,
   KEY_1             = 0x018,
   KEY_2             = 0x019,
   KEY_3             = 0x01a,
   KEY_4             = 0x01b,
   KEY_5             = 0x01c,
   KEY_6             = 0x01d,
   KEY_7             = 0x01e,
   KEY_8             = 0x01f,
   KEY_9             = 0x020,

   KEY_A             = 0x021,
   KEY_B             = 0x022,
   KEY_C             = 0x023,
   KEY_D             = 0x024,
   KEY_E             = 0x025,
   KEY_F             = 0x026,
   KEY_G             = 0x027,
   KEY_H             = 0x028,
   KEY_I             = 0x029,
   KEY_J             = 0x02a,
   KEY_K             = 0x02b,
   KEY_L             = 0x02c,
   KEY_M             = 0x02d,
   KEY_N             = 0x02e,
   KEY_O             = 0x02f,
   KEY_P             = 0x030,
   KEY_Q             = 0x031,
   KEY_R             = 0x032,
   KEY_S             = 0x033,
   KEY_T             = 0x034,
   KEY_U             = 0x035,
   KEY_V             = 0x036,
   KEY_W             = 0x037,
   KEY_X             = 0x038,
   KEY_Y             = 0x039,
   KEY_Z             = 0x03a,

   KEY_TILDE         = 0x03b,
   KEY_MINUS         = 0x03c,
   KEY_EQUALS        = 0x03d,
   KEY_LBRACKET      = 0x03e,
   KEY_RBRACKET      = 0x03f,
   KEY_BACKSLASH     = 0x040,
   KEY_SEMICOLON     = 0x041,
   KEY_APOSTROPHE    = 0x042,
   KEY_COMMA         = 0x043,
   KEY_PERIOD        = 0x044,
   KEY_SLASH         = 0x045,
   KEY_NUMPAD0       = 0x046,
   KEY_NUMPAD1       = 0x047,
   KEY_NUMPAD2       = 0x048,
   KEY_NUMPAD3       = 0x049,
   KEY_NUMPAD4       = 0x04a,
   KEY_NUMPAD5       = 0x04b,
   KEY_NUMPAD6       = 0x04c,
   KEY_NUMPAD7       = 0x04d,
   KEY_NUMPAD8       = 0x04e,
   KEY_NUMPAD9       = 0x04f,
   KEY_MULTIPLY      = 0x050,
   KEY_ADD           = 0x051,
   KEY_SEPARATOR     = 0x052,
   KEY_SUBTRACT      = 0x053,
   KEY_DECIMAL       = 0x054,
   KEY_DIVIDE        = 0x055,
   KEY_NUMPADENTER   = 0x056,

   KEY_F1            = 0x057,
   KEY_F2            = 0x058,
   KEY_F3            = 0x059,
   KEY_F4            = 0x05a,
   KEY_F5            = 0x05b,
   KEY_F6            = 0x05c,
   KEY_F7            = 0x05d,
   KEY_F8            = 0x05e,
   KEY_F9            = 0x05f,
   KEY_F10           = 0x060,
   KEY_F11           = 0x061,
   KEY_F12           = 0x062,
   KEY_F13           = 0x063,
   KEY_F14           = 0x064,
   KEY_F15           = 0x065,
   KEY_F16           = 0x066,
   KEY_F17           = 0x067,
   KEY_F18           = 0x068,
   KEY_F19           = 0x069,
   KEY_F20           = 0x06a,
   KEY_F21           = 0x06b,
   KEY_F22           = 0x06c,
   KEY_F23           = 0x06d,
   KEY_F24           = 0x06e,

   KEY_NUMLOCK       = 0x06f,
   KEY_SCROLLLOCK    = 0x070,
   KEY_LCONTROL      = 0x071,
   KEY_RCONTROL      = 0x072,
   KEY_LALT          = 0x073,
   KEY_RALT          = 0x074,
   KEY_LSHIFT        = 0x075,
   KEY_RSHIFT        = 0x076,
   KEY_WIN_LWINDOW   = 0x077,
   KEY_WIN_RWINDOW   = 0x078,
   KEY_WIN_APPS      = 0x079,
   KEY_OEM_102       = 0x080,

   KEY_MAC_OPT       = 0x090,
   KEY_MAC_LOPT      = 0x091,
   KEY_MAC_ROPT      = 0x092,

   KEY_BUTTON0       = 0x0100,
   KEY_BUTTON1       = 0x0101,
   KEY_BUTTON2       = 0x0102,
   KEY_BUTTON3       = 0x0103,
   KEY_BUTTON4       = 0x0104,
   KEY_BUTTON5       = 0x0105,
   KEY_BUTTON6       = 0x0106,
   KEY_BUTTON7       = 0x0107,
   KEY_BUTTON8       = 0x0108,
   KEY_BUTTON9       = 0x0109,
   KEY_BUTTON10      = 0x010A,
   KEY_BUTTON11      = 0x010B,
   KEY_BUTTON12      = 0x010C,
   KEY_BUTTON13      = 0x010D,
   KEY_BUTTON14      = 0x010E,
   KEY_BUTTON15      = 0x010F,
   KEY_BUTTON16      = 0x0110,
   KEY_BUTTON17      = 0x0111,
   KEY_BUTTON18      = 0x0112,
   KEY_BUTTON19      = 0x0113,
   KEY_BUTTON20      = 0x0114,
   KEY_BUTTON21      = 0x0115,
   KEY_BUTTON22      = 0x0116,
   KEY_BUTTON23      = 0x0117,
   KEY_BUTTON24      = 0x0118,
   KEY_BUTTON25      = 0x0119,
   KEY_BUTTON26      = 0x011A,
   KEY_BUTTON27      = 0x011B,
   KEY_BUTTON28      = 0x011C,
   KEY_BUTTON29      = 0x011D,
   KEY_BUTTON30      = 0x011E,
   KEY_BUTTON31      = 0x011F,
   KEY_ANYKEY         = 0xfffe
};

/////////////////////////////////////////////////////////////////////////////////
//
// API����
//
/////////////////////////////////////////////////////////////////////////////////

// dOnMouseMove������ƶ��󽫱����õĺ��������ڴ˺�������(Main.cpp)�����Լ�����Ӧ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
//
extern void		dOnMouseMove( const float fMouseX, const float fMouseY );

// dOnMouseClick����갴�º󽫱����õĺ��������ڴ˺�������(Main.cpp)�����Լ�����Ӧ����
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
//
extern void		dOnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY );

// dOnMouseUp����굯��󽫱����õĺ��������ڴ˺�������(Main.cpp)�����Լ�����Ӧ����
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
//
extern void		dOnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY );

// dOnKeyDown�����̱����º󽫱����õĺ��������ڴ˺�������(Main.cpp)�����Լ�����Ӧ����
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
//
extern void		dOnKeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress );

// dOnKeyUp�����̰�������󽫱����õĺ��������ڴ˺�������(Main.cpp)�����Լ�����Ӧ����
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
//
extern void		dOnKeyUp( const int iKey );

// dOnSpriteColSprite�������뾫����ײ�󽫱����õĺ��������ڴ˺�������(Main.cpp)�����Լ�����Ӧ����
// ����֮��Ҫ������ײ�������ڱ༭�����ߴ��������þ��鷢�ͼ�������ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
//
extern void		dOnSpriteColSprite( const char *szSrcName, const char *szTarName );

// dOnSpriteColWorldLimit������������߽���ײ�󽫱����õĺ��������ڴ˺�������(Main.cpp)�����Լ�����Ӧ����
// ����֮��Ҫ������ײ�������ڱ༭�����ߴ��������þ��������߽�����
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
//
extern void		dOnSpriteColWorldLimit( const char *szName, const int iColSide );

// dMakeSpriteName: ��ǰ����ַ����������������ϳ�һ���ַ�����
// ���� szPrev��һ���ǿ��ַ���������ܳ���20��Ӣ���ַ�������ǰ����ַ���
// ���� iId��һ������
// ����ֵ������һ���ַ��������紫��("xxx", 2),�򷵻�"xxx2"
//
extern char*	dMakeSpriteName(const char *szPrev, const int iId);

// dCursorOff���ر���겻��ʾ����API���ص�������Windows����꣬���ǵ��ÿ�������API dCursorOn��������꽫һֱ����ʾ
//
extern void		dCursorOff();

// dCursorOn�����������ʾ����API dCursorOff�رյ�������¿�����ʾ
//
extern void		dCursorOn();

// dIsCursorOn����ǰ����ǿ������ǹرա���Ӧ������API dCursorOff��dCursorOn�������߹رյĲ���
// ����ֵ��1Ϊ����״̬��0Ϊ�ر�״̬
//
extern int		dIsCursorOn();

// dShowCursor������/��ʾ��ꡣ��APIֻ�����ر����򴰿��ڵ���꣬�ƶ����������ʱ����껹�ǻ���ʾ
// ���� iShow��1 Ϊ��ʾ��0 Ϊ����
//
extern void		dShowCursor( const int iShow );

// dIsShowCursor����ǰ�������ʾ�������ء���Ӧ������API dShowCursor���ػ�����ʾ�Ĳ���
// ����ֵ��1Ϊ����״̬��0Ϊ�ر�״̬
//
extern int		dIsShowCursor();

// dSetWindowTitle�����ô�������/����
// ���� szTitle���ǿ��ַ���
//
extern void		dSetWindowTitle( const char *szTitle );

// dResizeWindow�����Ĵ��ڴ�С
// ���� iWidth����ȣ�����0С�ڵ���1920
// ���� iHeight���߶ȣ�����0С�ڵ���1080
//
extern void		dResizeWindow(int iWidth, int iHeight);

// dGetHwnd����ȡ���ھ��
// ����ֵ�����ھ��
//
extern void*	dGetHwnd();

// dRandom����ȡһ�����ڵ���0�������
// ����ֵ��int����Χ0 - 2147483648
//
extern int		dRandom();

// dRandomRange����ȡһ��λ�ڲ���1������2֮��������
// ����ֵ��int����ΧiMin - iMax
// ���� iMin��С��iMax������
// ���� iMax������iMin������
//
extern int		dRandomRange( const int iMin, const int iMax );

// dCalLineRotation�������������ߵ�ֱ�ߵ���ת�Ƕ�
// ����ֵ���Ƕȣ���Χ0 - 360
// ���� fStartX����ʼ����X
// ���� fStartY����ʼ����Y
// ���� fEndX���յ�����X
// ���� fEndY���յ�����Y
//
extern float	dCalLineRotation( const float fStartX, const float fStartY, const float fEndX, const float fEndY );

// dRotationToVectorX������ĳ���Ƕȶ�Ӧ��ֱ��������X����
// ���� fRotation���Ƕȣ���Χ0 - 360
// ����ֵ ����ֱ��������Xֵ
//
extern float	dRotationToVectorX( const float fRotation );

// dRotationToVectorY������ĳ���Ƕȶ�Ӧ��ֱ��������Y����
// ���� fRotation���Ƕȣ���Χ0 - 360
// ����ֵ ����ֱ��������Yֵ
//
extern float	dRotationToVectorY( const float fRotation );

// dDrawLine��������֮�仭һ����
// ���� fStartX����ʼ����X
// ���� fStartY����ʼ����Y
// ���� fEndX���յ�����X
// ���� fEndY���յ�����Y
// ���� fLineWidth���ߵĴ�ϸ�����ڵ���1
// ���� iLayer���������ڵĲ㣬��༭�������õľ���Ĳ㼶��ͬһ�������Χ0 - 31��
// ���� iRed, iGreen, iBlue : ��������ԭɫ����ɫֵ����Χ 0 - 255
// ���� iAlpha���ߵ�͸���ȣ���Χ0-255. 0Ϊȫ͸����255Ϊ��͸��
//
extern void		dDrawLine( const float fStartX, const float fStartY, const float fEndX, const float fEndY, const float fLineWidth, const int iLayer, const int iRed, const int iGreen, const int iBlue, const int iAlpha );

// dDrawTriangle����һ��������
// ���� fX1,fX2,fX3�����������������X����
// ���� fY1,fY2,fY3�����������������Y����
// ���� fLineWidth���ߵĴ�ϸ�����ڵ���1
// ���� iLayer�������������ڵĲ㣬��༭�������õľ���Ĳ㼶��ͬһ�������Χ0 - 31��
// ���� iRed, iGreen, iBlue : ��������ԭɫ����ɫֵ����Χ 0 - 255
// ���� iAlpha�������ε�͸���ȣ���Χ0-255. 0Ϊȫ͸����255Ϊ��͸��
//
extern void		dDrawTriangle( const float fX1, const float fY1, const float fX2, const float fY2, const float fX3, const float fY3, const float fLineWidth, const int iLayer, const int iRed, const int iGreen, const int iBlue, const int iAlpha );

// dDrawRect����һ������
// ���� fUpperX�����Ͻ�����X
// ���� fUpperY�����Ͻ�����Y
// ���� fLowerX�����½�����X
// ���� fLowerY�����½�����Y
// ���� fLineWidth���ߵĴ�ϸ�����ڵ���1
// ���� iLayer���þ������ڵĲ㣬��༭�������õľ���Ĳ㼶��ͬһ�������Χ0 - 31��
// ���� iRed, iGreen, iBlue : ��������ԭɫ����ɫֵ����Χ 0 - 255
// ���� iAlpha�����ε�͸���ȣ���Χ0-255. 0Ϊȫ͸����255Ϊ��͸��
//
extern void		dDrawRect( const float fUpperX, const float fUpperY, const float fLowerX, const float fLowerY, const float fLineWidth, const int iLayer, const int iRed, const int iGreen, const int iBlue, const int iAlpha );

// dDrawCircle����һ��Բ
// ���� fCenterX��Բ������X
// ���� fCenterY��Բ������Y
// ���� fRadius��Բ�İ뾶
// ���� iSegment��Բ����������Χ4-72. ���紫��6�����õ�һ��6���Σ�����Խ��ԽԲ�������ǻ�ͼЧ��Խ��
// ���� fLineWidth���ߵĴ�ϸ�����ڵ���1
// ���� iLayer����Բ���ڵĲ㣬��༭�������õľ���Ĳ㼶��ͬһ�������Χ0 - 31��
// ���� iRed, iGreen, iBlue : ��������ԭɫ����ɫֵ����Χ 0 - 255
// ���� iAlpha��Բ��͸���ȣ���Χ0-255. 0Ϊȫ͸����255Ϊ��͸��
//
extern void		dDrawCircle( const float fCenterX, const float fCenterY, const float fRadius, const int iSegment, const float fLineWidth, const int iLayer, const int iRed, const int iGreen, const int iBlue, const int iAlpha );

// dGetScreenLeft����ȡ����߽�֮���X����
// ����ֵ����߽�X����
//
extern float	dGetScreenLeft();

// dGetScreenTop����ȡ����߽�֮�ϱ�Y����
// ����ֵ���ϱ߽�Y����
//
extern float	dGetScreenTop();

// dGetScreenRight����ȡ����߽�֮�ұ�X����
// ����ֵ���ұ߽�X����
//
extern float	dGetScreenRight();

// dGetScreenBottom����ȡ����߽�֮�±�Y����
// ����ֵ���±߽�Y����
//
extern float	dGetScreenBottom();

// dCloneSprite������(����)һ�����顣����Ĵ�����ʽ�����ڵ�ͼ�аڷ�һ��������Ϊģ�壬���úø��������Ȼ���ڴ�����ʹ�ô˺�����¡һ��ʵ��
// ����ֵ��1��ʾ��¡�ɹ���0��¡ʧ�ܡ�ʧ�ܵ�ԭ��������ڵ�ͼ��δ�ҵ���Ӧ���ֵľ���
// ���� szSrcName����ͼ������ģ��ľ�������
// ���� szMyName���µľ�������
//
extern int		dCloneSprite( const char *szSrcName, const char *szMyName );

// dDeleteSprite���ڵ�ͼ��ɾ��һ������
// ���� szName��Ҫɾ���ľ�������
//
extern void		dDeleteSprite( const char *szName );

// dSetSpriteVisible�����þ������ػ�����ʾ(�ɼ����ɼ�)
// ���� szName����������
// ���� iVisible��1 �ɼ� 0���ɼ�
//
extern void		dSetSpriteVisible( const char *szName, const int iVisible );

// dIsSpriteVisible����ȡ�þ��鵱ǰ�Ƿ�ɼ�
// ����ֵ 1�ɼ� 0���ɼ�
// ���� szName����������
//
extern int		dIsSpriteVisible( const char *szName );

// dSetSpriteEnable����ֹ�������øþ��顣����ֹ�ľ��齫�������κ���Ӧ���������ƶ���û����ײ�ȣ��������ڵ�ͼ����ʾ
// ���� szName����������
// ���� iEnable��1���� 0��ֹ
//
extern void		dSetSpriteEnable( const char *szName, const int iEnable );

// dSetSpriteScale�����þ��������ֵ
// ���� szName����������
// ���� fScale������ֵ������0��ֵ
//
extern void		dSetSpriteScale( const char *szName, const float fScale );

// dIsPointInSprite���ж�ĳ��������Ƿ�λ�ھ����ڲ�
// ����ֵ 1 �� 0 ����
// ���� szName����������
// ���� fPosX��X�����
// ���� fPosY��Y�����
//
extern int 	dIsPointInSprite( const char *szName, const float fPosX, const float fPosY );

// dSetSpritePosition�����þ���λ��
// ���� szName����������
// ���� fPosX��X����
// ���� fPosY��Y����
//
extern void		dSetSpritePosition( const char *szName, const float fPosX, const float fPosY );

// dSetSpritePositionX��ֻ���þ���X����
// ���� szName����������
// ���� fPosX��X����
//
extern void		dSetSpritePositionX( const char *szName, const float fPosX );

// dSetSpritePositionY��ֻ���þ���Y����
// ���� szName����������
// ���� fPosY��Y����
//
extern void		dSetSpritePositionY( const char *szName, const float fPosY );

// dGetSpritePositionX����ȡ����X����
// ���� szName����������
// ����ֵ�������X����
//
extern float	dGetSpritePositionX( const char *szName );

// dGetSpritePositionY����ȡ����Y����
// ���� szName����������
// ����ֵ�������Y����
//
extern float	dGetSpritePositionY( const char *szName );

// dGetSpriteLinkPointPosX����ȡ�������ӵ�X���ꡣ���ӵ��������ھ����һ������㣬�����ڱ༭�������ӻ���ɾ��
// ���� szName����������
// ���� iId�����ӵ���ţ���һ��Ϊ1���������εݼ�
//
extern float	dGetSpriteLinkPointPosX( const char *szName, const int iId );

// dGetSpriteLinkPointPosY����ȡ�������ӵ�Y���ꡣ���ӵ��������ھ����һ������㣬�����ڱ༭�������ӻ���ɾ��
// ���� szName����������
// ���� iId�����ӵ���ţ���һ��Ϊ1���������εݼ�
//
extern float	dGetSpriteLinkPointPosY( const char *szName, const int iId );

// dSetSpriteRotation�����þ������ת�Ƕ�
// ���� szName����������
// ���� fRot����ת�Ƕȣ���Χ0 - 360
//
extern void		dSetSpriteRotation( const char *szName, const float fRot );

// dGetSpriteRotation����ȡ�������ת�Ƕ�
// ���� szName����������
// ����ֵ���������ת�Ƕ�
//
extern float	dGetSpriteRotation( const char *szName );

// dSetSpriteAutoRot�����þ��鰴��ָ���ٶ��Զ���ת
// ���� szName����������
// ���� fRotSpeed����ת�ٶ�
//
extern void 	dSetSpriteAutoRot( const char *szName, const float fRotSpeed );

// dSetSpriteWidth�����þ������ο��
// ���� szName����������
// ���� fWidth�����ֵ������0
//
extern void		dSetSpriteWidth( const char *szName, const float fWidth );

// dGetSpriteWidth����ȡ�������ο��
// ���� szName����������
// ����ֵ��������ֵ
//
extern float	dGetSpriteWidth( const char *szName );

// dSetSpriteHeight�����þ������θ߶�
// ���� szName����������
// ���� fHeight������߶�ֵ
//
extern void		dSetSpriteHeight( const char *szName, const float fHeight );

// dGetSpriteHeight����ȡ�������θ߶�
// ���� szName����������
// ����ֵ������߶�ֵ
//
extern float	dGetSpriteHeight( const char *szName );

// dSetSpriteFlipX�����þ���ͼƬX����ת��ʾ
// ���� szName����������
// ���� iFlipX��1 ��ת 0����ת(�ָ�ԭ������)
//
extern void		dSetSpriteFlipX( const char *szName, const int iFlipX );

// dGetSpriteFlipX����ȡ��ǰ����ͼƬX�����Ƿ��Ƿ�ת��ʾ
// ���� szName����������
// ����ֵ��1 ��ת 0����ת
//
extern int		dGetSpriteFlipX( const char *szName );

// dSetSpriteFlipY�����þ���ͼƬY����ת��ʾ
// ���� szName����������
// ���� iFlipY��1 ��ת 0����ת(�ָ�ԭ������)
//
extern void		dSetSpriteFlipY( const char *szName, const int iFlipY );

// dGetSpriteFlipY����ȡ��ǰ����ͼƬY�����Ƿ��Ƿ�ת��ʾ
// ���� szName����������
// ����ֵ��1 ��ת 0����ת
//
extern int		dGetSpriteFlipY( const char *szName );

// dSetSpriteFlip��ͬʱ���þ��鷭תX��Y����
// ���� szName����������
// ���� iFlipX��1 ��ת 0����ת(�ָ�ԭ������)
// ���� iFlipY��1 ��ת 0����ת(�ָ�ԭ������)
//
extern void		dSetSpriteFlip( const char *szName, const int iFlipX, const int iFlipY );

// dSetSpriteLifeTime�����þ��������ʱ����ʱ�䵽��֮���Զ���ɾ��
// ���� szName����������
// ���� fLifeTime������ʱ������λ ��
//
extern void		dSetSpriteLifeTime( const char *szName, const float fLifeTime );

// dGetSpriteLifeTime����ȡ��������ʱ��
// ���� szName����������
// ����ֵ������ʱ������λ ��
//
extern float	dGetSpriteLifeTime( const char *szName );	

// dSpriteMoveTo���þ��鰴�ո����ٶ��ƶ������������
// ���� szName����������
// ���� fPosX���ƶ���Ŀ��X����ֵ
// ���� fPosY���ƶ���Ŀ��Y����ֵ
// ���� fSpeed���ƶ��ٶ�
// ���� iAutoStop���ƶ����յ�֮���Ƿ��Զ�ֹͣ, 1 ֹͣ 0 ��ֹͣ
//
extern void		dSpriteMoveTo( const char *szName, const float fPosX, const float fPosY, const float fSpeed, const int iAutoStop );

// dSpriteRotateTo���þ��鰴�ո����ٶ���ת�������ĽǶ�
// ���� szName����������
// ���� fRotation��������Ŀ����תֵ
// ���� fRotSpeed����ת�ٶ�
// ���� iAutoStop����ת���յ�֮���Ƿ��Զ�ֹͣ, 1 ֹͣ 0 ��ֹͣ
//
extern void		dSpriteRotateTo( const char *szName, const float fRotation, const float fRotSpeed, const int iAutoStop );

// dSetSpriteWorldLimit�����þ��������߽��������Ƽ���ײģʽ
// ���� szName����������
// ���� Limit����ײ������߽�֮�����Ӧģʽ�����ΪOFF�����ǹر�����߽���ײ������ֵ�� EWorldLimit
// ���� fLeft���߽�����X����
// ���� fTop���߽���ϱ�Y����
// ���� fRight���߽���ұ�X����
// ���� fBottom���߽���±�Y����
//
extern void		dSetSpriteWorldLimit( const char *szName, const EWorldLimit Limit, const float fLeft, const float fTop, const float fRight, const float fBottom );

// dSetSpriteWorldLimitMode�����þ��������߽���ײģʽ
// ���� szName����������
// ���� Limit����ײ������߽�֮�����Ӧģʽ�����ΪOFF�����ǹر�����߽���ײ������ֵ�� EWorldLimit
//
extern void		dSetSpriteWorldLimitMode( const char *szName, const EWorldLimit Limit );

// dSetSpriteWorldLimitMin�����þ��������߽��ϱ߼������������
// ���� szName����������
// ���� fLeft���߽�����X����
// ���� fTop���߽���ϱ�Y����
//
extern void		dSetSpriteWorldLimitMin( const char *szName, const float fLeft, const float fTop );

// dSetSpriteWorldLimitMax�����þ��������߽��±߼��ұ���������
// ���� szName����������
// ���� fRight���߽���ұ�X����
// ���� fBottom���߽���±�Y����
//
extern void		dSetSpriteWorldLimitMax( const char *szName, const float fRight, const float fBottom );

// dGetSpriteWorldLimitLeft����ȡ��������߽���߽�����
// ���� szName����������
//
extern float	dGetSpriteWorldLimitLeft( const char *szName);

// dGetSpriteWorldLimitTop����ȡ��������߽��ϱ߽�����
// ���� szName����������
//
extern float	dGetSpriteWorldLimitTop( const char *szName);

// dGetSpriteWorldLimitRight����ȡ��������߽��ұ߽�����
// ���� szName����������
//
extern float	dGetSpriteWorldLimitRight( const char *szName);

// dGetSpriteWorldLimitBottom����ȡ��������߽��±߽�����
//
extern float	dGetSpriteWorldLimitBottom( const char *szName);

// dSetSpriteCollisionSend�����þ����Ƿ���Է���(����)��ײ
// �������ײ��ʽΪ����A�ƶ�������Bʱ�����A�ǿ��Բ�����ײ�ģ�B�ǿ��Խ�����ײ�ģ�����2������������ײ��������ײ��API�������á���������ײ����
// ���� szName����������
// ���� iSend��1 ���Բ��� 0 ������
//
extern void 	dSetSpriteCollisionSend( const char *szName, const int iSend );

// dSetSpriteCollisionReceive�����þ����Ƿ���Խ�����ײ
// �������ײ��ʽΪ����A�ƶ�������Bʱ�����A�ǿ��Բ�����ײ�ģ�B�ǿ��Խ�����ײ�ģ�����2������������ײ��������ײ��API�������á���������ײ����
// ���� szName����������
// ���� iReceive��1 ���Խ��� 0 ������
//
extern void 	dSetSpriteCollisionReceive( const char *szName, const int iReceive );

// dSetSpriteCollisionPhysicsSend�����þ����Ƿ���Է���(����)������ײ
// ���� iSend��1 ���Բ��� 0 ������
//
extern void 	dSetSpriteCollisionPhysicsSend( const char *szName, const int iSend );

// dSetSpriteCollisionPhysicsReceive�����þ����Ƿ���Խ���������ײ
// ���� iReceive��1 ���Խ��� 0 ������
//
extern void 	dSetSpriteCollisionPhysicsReceive( const char *szName, const int iReceive );

// dSetSpriteCollisionActive��ͬʱ���þ����Ƿ���Բ�����������ײ
// �������ײ��ʽΪ����A�ƶ�������Bʱ�����A�ǿ��Բ�����ײ�ģ�B�ǿ��Խ�����ײ�ģ�����2������������ײ��������ײ��API�������á���������ײ����
// ���� szName����������
// ���� iSend��1 ���Բ��� 0 ������
// ���� iReceive��1 ���Խ��� 0 ������
//
extern void 	dSetSpriteCollisionActive( const char *szName, const int iSend, const int iReceive );

// dGetSpriteCollisionSend����ȡ���鵱ǰ�Ƿ��ǿ��Բ�����ײ
// ���� szName����������
// ����ֵ��1 ���Բ��� 0 ������
//
extern int 	dGetSpriteCollisionSend( const char *szName );

// dGetSpriteCollisionReceive����ȡ���鵱ǰ�Ƿ��ǿ��Խ�����ײ
// ���� szName����������
// ����ֵ��1 ���Խ��� 0 ������
//
extern int 	dGetSpriteCollisionReceive( const char *szName );

// dSetSpriteCollisionResponse�����þ����뾫�����ײ��Ӧģʽ
// ���� szName����������
// ���� Response����Ӧģʽ�����ΪOFF����Ϊ�ر���ײ��Ӧ����ײAPI�����ᱻ���á�����ֵ�� ECollisionResponse
//
extern void		dSetSpriteCollisionResponse( const char *szName, const ECollisionResponse Response );

// dSetSpriteCollisionMaxIterations�����þ�����ײ֮�����󷴵�����
// ���� szName����������
// ���� iTimes����������
//
extern void		dSetSpriteCollisionMaxIterations( const char *szName, const int iTimes );

// dSetSpriteForwardMovementOnly�����þ����Ƿ�ֻ�ܳ�ǰ�ƶ�
// ���� szName����������
// ���� iForward��1 ֻ�ܳ�ǰ�ƶ� 0 ���Գ����������ƶ�
//
extern void		dSetSpriteForwardMovementOnly( const char *szName, const int iForward );

// dGetSpriteForwardMovementOnly����ȡ���鵱ǰ�Ƿ�ֻ�ܳ�ǰ�ƶ�
// ���� szName����������
// ����ֵ��1 ֻ�ܳ�ǰ�ƶ� 0 ���Գ����������ƶ�
//
extern int		dGetSpriteForwardMovementOnly( const char *szName );

// dSetSpriteForwardSpeed�����þ�����ǰ���ٶ�
// ���� szName����������
// ���� fSpeed���ٶ�
//
extern void		dSetSpriteForwardSpeed( const char *szName, const float fSpeed );

// dSetSpriteImpulseForce�����þ���˲������
// ���� szName����������
// ���� fForceX��X����������С
// ���� fForceY��Y����������С
// ���� iGravitic���Ƿ�������� : 1 ���㣬0������
//
extern void 	dSetSpriteImpulseForce( const char *szName, const float fForceX, const float fForceY, const int iGravitic );

// dSetSpriteImpulseForcePolar�����Ƕȳ������þ���˲������
// ���� szName����������
// ���� fPolar���Ƕȳ���
// ���� fForce��������С
// ���� iGravitic���Ƿ�������� : 1 ���㣬0������
//
extern void 	dSetSpriteImpulseForcePolar( const char *szName, const float fPolar, const float fForce, const int iGravitic );

// dSetSpriteConstantForceX�����þ���X����������
// ���� szName����������
// ���� fForceX��X����������С
//
extern void 	dSetSpriteConstantForceX(const char *szName, const float fForceX );

// dSetSpriteConstantForceY�����þ���Y����������
// ���� szName����������
// ���� fForceY��Y����������С
//
extern void 	dSetSpriteConstantForceY(const char *szName, const float fForceY );

// dSetSpriteConstantForceGravitic�������ڼ��㳣��������ʱ���Ƿ��������
// ���� szName����������
// ���� iGravitic���Ƿ�������� : 1 ���� 0������
//
extern void 	dSetSpriteConstantForceGravitic(const char *szName, const int iGravitic );

// dSetSpriteConstantForce�����þ��鳣������
// ���� szName����������
// ���� fForceX��X����������С
// ���� fForceY��Y����������С
// ���� iGravitic���Ƿ�������� : 1 ���� 0������
//
extern void 	dSetSpriteConstantForce(const char *szName, const float fForceX, const float fForceY, const int iGravitic );

// dSetSpriteConstantForcePolar�����Ƕȳ������þ��鳣������
// ���� szName����������
// ���� fPolar���Ƕȳ���
// ���� fForce��������С
// ���� iGravitic���Ƿ�������� : 1 ���� 0������
//
extern void 	dSetSpriteConstantForcePolar(const char *szName, const float fPolar, const float fForce, const int iGravitic );

// dStopSpriteConstantForce��ֹͣ���鳣������
// ���� szName����������
//
extern void 	dStopSpriteConstantForce(const char *szName);

// dSetSpriteForceScale�����������ž��鵱ǰ�ܵ�����
// ���� szName����������
// ���� fScale������ֵ
//
extern void 	dSetSpriteForceScale(const char *szName, const float fScale );

// dSetSpriteAtRest����ͣ/��������ĸ�����������
// ���� szName����������
// ���� iRest��1 ��ͣ 0 ����
//
extern void 	dSetSpriteAtRest(const char *szName, const int iRest );

// dGetSpriteAtRest����ȡ���鵱ǰ�Ƿ�����ͣ��
// ���� szName����������
// ����ֵ��1 ��ͣ�� 0 ����
//
extern int 	dGetSpriteAtRest(const char *szName );

// dSetSpriteFriction�����þ���Ħ����
// ���� szName����������
// ���� fFriction��Ħ������С
//
extern void 	dSetSpriteFriction( const char *szName, const float fFriction );

// dSetSpriteRestitution�����þ��鵯��
// ���� szName����������
// ���� fRestitution������ֵ��С
//
extern void 	dSetSpriteRestitution( const char *szName, const float fRestitution );

// dSetSpriteMass�����þ�������
// ���� szName����������
// ���� fMass��������С
//
extern void 	dSetSpriteMass( const char *szName, const float fMass );

// dGetSpriteMass����ȡ��������
// ���� szName����������
// ����ֵ ��������С
//
extern float 	dGetSpriteMass( const char *szName );

// dSetSpriteAutoMassInertia���������߹رվ������
// ���� szName����������
// ���� iStatus��1 ���� 0 �ر�
//
extern void 	dSetSpriteAutoMassInertia( const char *szName, const int iStatus );

// dSetSpriteInertialMoment�����þ�����Դ�С
// ���� szName����������
// ���� fInert�����Դ�С
//
extern void 	dSetSpriteInertialMoment( const char *szName, const float fInert );

// dSetSpriteDamping�����þ���˥��ֵ
// ���� szName����������
// ���� fDamp��˥��ֵ��С
//
extern void 	dSetSpriteDamping( const char *szName, const float fDamp );

// dSetSpriteImmovable�����þ����Ƿ񲻿��ƶ�
// ���� szName����������
// ���� iImmovable��1 �������ƶ� 0 �����ƶ�
//
extern void 	dSetSpriteImmovable( const char *szName, const int iImmovable );

// dGetSpriteImmovable����ȡ���鵱ǰ�Ƿ񲻿����ƶ�
// ���� szName����������
// ����ֵ��1 �������ƶ� 0 �����ƶ�
//
extern int 	dGetSpriteImmovable( const char *szName );

// dSetSpriteLinearVelocity�����þ����ƶ��ٶ�
// ���� szName����������
// ���� fVelX��X�����ٶ�
// ���� fVelY��Y�����ٶ�
//
extern void 	dSetSpriteLinearVelocity( const char *szName, const float fVelX, const float fVelY );

// dSetSpriteLinearVelocityX�����þ���X�����ƶ��ٶ�
// ���� szName����������
// ���� fVelX��X�����ٶ�
//
extern void 	dSetSpriteLinearVelocityX( const char *szName, const float fVelX );

// dSetSpriteLinearVelocityY�����þ���Y�����ƶ��ٶ�
// ���� szName����������
// ���� fVelY��Y�����ٶ�
//
extern void 	dSetSpriteLinearVelocityY( const char *szName, const float fVelY );

// dSetSpriteLinearVelocityPolar�����Ƕȳ������þ����ƶ��ٶ�
// ���� szName����������
// ���� fSpeed���ƶ��ٶ�
// ���� fPolar���Ƕȳ���
//
extern void 	dSetSpriteLinearVelocityPolar( const char *szName, const float fSpeed, const float fPolar );

// dSetSpriteAngularVelocity�����þ���Ƕ���ת�ٶ�
// ���� szName����������
// ���� fAngular���Ƕ���ת�ٶ�
//
extern void 	dSetSpriteAngularVelocity( const char *szName, const float fAngular );

// dSetSpriteMinLinearVelocity�����þ�����С�ٶ�
// ���� szName����������
// ���� fMin����С�ٶ�ֵ
//
extern void 	dSetSpriteMinLinearVelocity( const char *szName, const float fMin );

// dSetSpriteMaxLinearVelocity�����þ�������ٶ�
// ���� szName����������
// ���� fMax������ٶ�ֵ
//
extern void 	dSetSpriteMaxLinearVelocity( const char *szName, const float fMax );

// dSetSpriteMinAngularVelocity�����þ�����С���ٶ�
// ���� szName����������
// ���� fMin����С���ٶ�
//
extern void 	dSetSpriteMinAngularVelocity( const char *szName, const float fMin );

// dSetSpriteMaxAngularVelocity�����þ��������ٶ�
// ���� szName����������
// ���� fMax�������ٶ�
//
extern void 	dSetSpriteMaxAngularVelocity( const char *szName, const float fMax );

// dGetSpriteLinearVelocityX����ȡ����X�����ٶ�
// ���� szName����������
// ����ֵ��X�����ٶ�
//
extern float 	dGetSpriteLinearVelocityX( const char *szName );

// dGetSpriteLinearVelocityY����ȡ����Y�����ٶ�
// ���� szName����������
// ����ֵ��Y�����ٶ�
//
extern float 	dGetSpriteLinearVelocityY( const char *szName );

// dSpriteMountToSprite����һ������󶨵���һ�������ϣ���ʱ�ĳ�Ϊ��һ�������һ���֣��������˶���
// ���� szSrcName��Ҫ�󶨵ľ�������
// ���� szDstName�����ذ󶨵�ĸ�徫������
// ���� fOffSetX����ƫ��X
// ���� fOffsetY����ƫ��Y
// ����ֵ������һ����ID
//
extern int		dSpriteMountToSprite( const char *szSrcName, const char *szDstName, const float fOffSetX, const float fOffsetY );

// dSpriteMountToSpriteLinkPoint����һ������󶨵���һ�������ϣ���λ��Ϊָ�������ӵ㣬��ʱ�ĳ�Ϊ��һ�������һ���֣��������˶���
// ���� szSrcName��Ҫ�󶨵ľ�������
// ���� szDstName�����ذ󶨵�ĸ�徫������
// ���� iPointId�����ӵ����
// ����ֵ������һ����ID
//
extern int		dSpriteMountToSpriteLinkPoint( const char *szSrcName, const char *szDstName, const int iPointId );

// dSetSpriteMountRotation�����þ���İ󶨳��򣬼������ĸ��ĳ���
// ���� szName����������
// ���� fRot���Ƕȳ���0 - 360
//
extern void		dSetSpriteMountRotation( const char *szName, const float fRot );

// dGetSpriteMountRotation����ȡ����İ󶨳��򣬼������ĸ��ĳ���
// ���� szName����������
// ����ֵ���Ƕȳ���
//
extern float	dGetSpriteMountRotation( const char *szName );

// dSetSpriteAutoMountRotation�����þ����֮���Զ���ת
// ���� szName����������
// ���� fRot����ת�ٶ�
//
extern void		dSetSpriteAutoMountRotation( const char *szName, const float fRot );

// dGetSpriteAutoMountRotation����ȡ�����֮����Զ���תֵ
// ���� szName����������
// ����ֵ����ת�ٶ�
//
extern float	dGetSpriteAutoMountRotation( const char *szName );

// dSetSpriteMountForce��������һ������ʱ�����ӵ�������
// ���� szName����������
// ���� fFroce��������
//
extern void		dSetSpriteMountForce( const char *szName, const float fForce );

// dSetSpriteMountTrackRotation���󶨵ľ����Ƿ����ĸ����ת
// ���� szName����������
// ���� iTrackRotation��1 ���� 0 ������
//
extern void		dSetSpriteMountTrackRotation( const char *szName, const int iTrackRotation );

// dSetSpriteMountOwned��ĸ�屻ɾ����ʱ�򣬰󶨵ľ����Ƿ�Ҳ���ű�ɾ��
// ���� szName����������
// ���� iMountOwned��1 ���� 0 ������
//
extern void		dSetSpriteMountOwned( const char *szName, const int iMountOwned );

// dSetSpriteMountInheritAttributes���󶨵�ʱ���Ƿ�̳�ĸ�������
// ���� szName����������
// ���� iInherAttr��1 �̳� 0 ���̳�
//
extern void		dSetSpriteMountInheritAttributes( const char *szName, const int iInherAttr );

// dSpriteDismount�����Ѿ��󶨵ľ�����н��
// ���� szName����������
//
extern void		dSpriteDismount( const char *szName );

// dGetSpriteIsMounted���жϾ����Ƿ������һ��������
// ���� szName����������
// ����ֵ��1 �� 0 ����
//
extern int		dGetSpriteIsMounted( const char *szName );

// dGetSpriteMountedParent����ȡ�󶨵�ĸ�徫�������
// ���� szName����������
// ����ֵ��ĸ�徫�����֣����δ�󶨣��򷵻ؿ��ַ���
//
extern const char*	dGetSpriteMountedParent( const char *szName );

// dSetSpriteColorRed�����ľ�����ʾ��ɫ�еĺ�ɫ��Ĭ�Ͼ���ĺ���������ɫ��ֵ��Ϊ255���޸�����һ����Ըı�����ɫ
// ���� szName����������
// ���� iCol����ɫ��Χ 0 - 255
//
extern void		dSetSpriteColorRed( const char *szName, const int iCol );

// dSetSpriteColorGreen�����ľ�����ʾ��ɫ�е���ɫ��Ĭ�Ͼ���ĺ���������ɫ��ֵ��Ϊ255���޸�����һ����Ըı�����ɫ
// ���� szName����������
// ���� iCol����ɫ��Χ 0 - 255
//
extern void		dSetSpriteColorGreen( const char *szName, const int iCol );

// dSetSpriteColorBlue�����ľ�����ʾ��ɫ�е���ɫ��Ĭ�Ͼ���ĺ���������ɫ��ֵ��Ϊ255���޸�����һ����Ըı�����ɫ
// ���� szName����������
// ���� iCol����ɫ��Χ 0 - 255
//
extern void		dSetSpriteColorBlue( const char *szName, const int iCol );

// dSetSpriteColorAlpha�����þ���͸����
// ���� szName����������
// ���� iCol��͸���ȣ�ֵ0 - 255������ȫ͸������ȫ��͸��
//
extern void		dSetSpriteColorAlpha( const char *szName, const int iCol );

// dGetSpriteColorRed����ȡ������ʾ��ɫ�еĺ�ɫֵ
// ���� szName����������
// ����ֵ����ɫֵ
//
extern int		dGetSpriteColorRed( const char *szName );

// dGetSpriteColorGreen����ȡ������ʾ��ɫ�е���ɫֵ
// ���� szName����������
// ����ֵ����ɫֵ
//
extern int		dGetSpriteColorGreen( const char *szName );

// dGetSpriteColorBlue����ȡ������ʾ��ɫ�е���ɫֵ
// ���� szName����������
// ����ֵ����ɫֵ
//
extern int		dGetSpriteColorBlue( const char *szName );

// dGetSpriteColorAlpha����ȡ����͸����
// ���� szName����������
// ����ֵ��͸����
//
extern int		dGetSpriteColorAlpha( const char *szName );

// dSetStaticSpriteImage������/���ľ�̬�������ʾͼƬ
// ���� szName����������
// ���� szImageName��ͼƬ����
// ���� iFrame����ͼƬ����ʾ֡����Ϊ�༭��Ԥ��ͼ����ʾ��1/N����ΧΪ 0 �� N - 1
//
extern void		dSetStaticSpriteImage( const char *szName, const char *szImageName, const int iFrame );

// dSetStaticSpriteFrame�����þ�̬���鵱ǰͼƬ����ʾ֡��
// ���� szName����������
// ���� iFrame����ͼƬ����ʾ֡����Ϊ�༭��Ԥ��ͼ����ʾ��1/N����ΧΪ 0 �� N - 1
//
extern void		dSetStaticSpriteFrame( const char *szName, const int iFrame );

// dGetStaticSpriteImage����ȡ���鵱ǰ��ʾ��ͼƬ����
// ���� szName����������
// ����ֵ��ͼƬ����
//
extern const char* dGetStaticSpriteImage( const char *szName );

// dGetStaticSpriteFrame����ȡ���鵱ǰ��ʾ��ͼƬ֡��
// ���� szName����������
// ����ֵ��֡��
//
extern int		dGetStaticSpriteFrame( const char *szName );

// dSetAnimateSpriteFrame�����ö�̬����Ķ���֡��
// ���� szName����������
// ���� iFrame������֡��
//
extern void		dSetAnimateSpriteFrame( const char *szName, const int iFrame );

// dIsAnimateSpriteAnimationFinished���ж϶�̬���鵱ǰ�����Ƿ񲥷���ϣ�ֻ��Է�ѭ����������
// ���� szName����������
// ����ֵ��1 ��� 0 δ���
//
extern int		dIsAnimateSpriteAnimationFinished( const char *szName );

// dGetAnimateSpriteAnimationName����ȡ��̬���鵱ǰ��������
// ���� szName����������
// ����ֵ����������
//
extern const char* dGetAnimateSpriteAnimationName( const char *szName );

// dGetAnimateSpriteAnimationTime����ȡ�������鵱ǰ����ʱ�䳤��
// ���� szName����������
// ����ֵ�����ȣ���λ��
//
extern float	dGetAnimateSpriteAnimationTime( const char *szName );

// dAnimateSpritePlayAnimation���������鲥�Ŷ���
// ���� szName����������
// ���� szAnim����������
// ���� iRestore��������Ϻ��Ƿ�ָ���ǰ����. 1 �ָ� 0 ���ָ�
// ����ֵ���Ƿ񲥷ųɹ�, 1 : �ɹ� 0 �����ɹ�
//
extern int		dAnimateSpritePlayAnimation( const char *szName, const char *szAnim, const int iRestore );

// dSetTextValue�����־�����ʾĳ����ֵ
// ���� szName����������
// ���� iValue��Ҫ��ʾ����ֵ
//
extern void		dSetTextValue( const char *szName, int iValue );

// dSetTextValueFloat�����־�����ʾĳ��������ֵ
// ���� szName����������
// ���� fValue��Ҫ��ʾ����ֵ
//
extern void		dSetTextValueFloat( const char *szName, float fValue );

// dSetTextString�����־�����ʾĳ���ַ�������
// ���� szName����������
// ���� szStr��Ҫ��ʾ���ַ���
//
extern void		dSetTextString( const char *szName, const char *szStr );

// dSetTextChar�����־�����ʾĳ���ַ�
// ���� szChar��Ҫ��ʾ���ַ�
//
extern void		dSetTextChar( const char *szName, char szChar );

// dLoadMap�������³�����ע�⣬�����³�����ʱ�򣬾ɳ��������о��鶼��������ɾ���������������ڳ����д��������Ƴ����ľ��鶼�����ڵ��ñ�API֮ǰ��ɾ����
// ���� szName���������֡����½����������ʱ��ȡ�����֣������Сд�ĺ�׺ -- xxx.t2d�����ô�·��
//
extern void		dLoadMap( const char *szName );

// dPlaySound����������
// ���� szName��������·�������ƣ�����ֵ���ڱ༭������Դ -> �����������鿴����Ŀ���������Դ�����������Ǹ�·��ֵ��д����
// ���� iLoop���Ƿ�ѭ������ 1 ѭ�� 0 ��ѭ����ѭ�����ŵ���������Ҫ�ֶ�ֹͣ����ʹ�÷��ص�ID������APIֹͣ�������Ĳ��š���ѭ���Ĳ�����֮���Զ�ֹͣ
// ���� fVolume��������С��0-1��1Ϊ�����ļ���ԭ����С
// ����ֵ������ID��ѭ�����ŵ�������Ҫ��ID��ֹͣ����
//
extern int		dPlaySound(const char *szName, const int iLoop, const float fVolume );

// dStopSound��ֹͣ�����Ĳ���
// ���� iSoundId��API dPlaySound ����������ʱ�򷵻ص�����ID
//
extern void		dStopSound( const int iSoundId );

// dStopAllSound��ֹͣ������������
//
extern void		dStopAllSound();

// dPlayEffect������һ����ѭ������Ч���������֮�����Ч�Զ�ɾ��
// ���� szSrcName��Ԥ�Ȱڷ��ڵ�ͼ�е���Чģ������
// ���� fLifeTime������ʱ����ʱ�䵽��֮�󽫱��Զ�ɾ��
// ���� fPosX�����ŵ�X����
// ���� fPosY�����ŵ�Y����
// ���� fRotation�����ŵĽǶȳ���
//
extern void		dPlayEffect(const char *szSrcName, const float fLifeTime, const float fPosX, const float fPosY, const float fRotation);

// dPlayLoopEffect������һ��ѭ����Ч������Ҫ����Ч��ʱ����Ҫ�Լ�����API����ɾ��
// ���� szSrcName��Ԥ�Ȱڷ��ڵ�ͼ�е���Чģ������
// ���� szMyName������Ч���֣�Ҫɾ������Ч��ʱ���õ�
// ���� fCycleTime��ѭ��ʱ����ʱ�䵽��֮����ͷ����
// ���� fPosX�����ŵ�X����
// ���� fPosY�����ŵ�Y����
// ���� fRotation�����ŵĽǶȳ���
//
extern void		dPlayLoopEffect(const char *szSrcName, const char *szMyName, const float fCycleTime, const float fPosX, const float fPosY, const float fRotation);

// dDeleteEffect��ɾ��һ�����ڲ��ŵ���Ч��ֻ��ѭ����Ч����Ҫ�ֶ�ɾ��
// ���� szName����Ч����
//
extern void		dDeleteEffect(const char *szName);

//////////////////////////////////////////////////////////////////////////////////////////
//
// ����APIΪϵͳAPI�������Լ�����
//
//////////////////////////////////////////////////////////////////////////////////////////

// dGetTimeDelta����ȡ���ε��ñ�����֮���ʱ���
// ����ֵ��float����λ ��
//
extern float	dGetTimeDelta();
// dEngineMainLoop��������ѭ�������������Լ�����
//
extern int		dEngineMainLoop();
// dInitGameEngine����ʼ�����棬�����Լ�����
//
extern int		dInitGameEngine( HINSTANCE hInstance, LPSTR lpCmdLine );
extern int		dInitGameEngineEx( HINSTANCE hInstance, LPSTR lpCmdLine );
// dShutdownGameEngine���ر����棬�����Լ�����
//
extern void		dShutdownGameEngine();

//
#endif // _COMMON_API_H_
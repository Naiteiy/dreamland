#include <Stdio.h>
#include "CommonAPI.h"
#include "LessonX.h"
////////////////////////////////////////////////////////////////////////////////
//
//
int Redblood = 5, Blueblood = 5, Bossblood = 200, BosslevelPlayerblood = 8; //玩家1，玩家2血量
int level = 0;
int key = 0, cheat = 0;
int p = 1, e = 1, r = 1, t = 1;
float z = 12, x = 4; //控制难度 z速度  x 密集程度
int Musicplay = 0;	 //音乐播放状态，0 -- 播放；1 -- 暂停；
int passlevel = 0;
float middle1, middle2, middle3, middle4, w; //时间中值
float stay;
float iftouch;
int face1, face2; //玩家人物朝向
int n = 1, q = 1; //子弹编号
int TimeRun = 1;  //时间函数是否调用，0 -- 暂停；1 -- 运行；
float fDeltaTime;
int zhen=0;
struct Weapon
{
	char *szName; // 精灵名称
	int iHp;	  // 生命值
	float iV;	  // 速度
};
struct Weapon list[] = {{"PlayerRed", Redblood, 0}, {"PlayerBlue", Blueblood, 0}, {"monster1", 3, 20}, {"monster2", 3, 16}, {"monster3", 3, 5}, {"lwall7", 1, 10}, {"lwall13", 1, 15}, {"Boss", Bossblood, 0}};
struct WallSpeed
{
	char *szName; // 精灵名字
	float wV;	  // 速度
};
struct WallSpeed wall[] = {{"lwall2", 8}, {"lwall3", 10}, {"lwall4", 10}, {"lwall6", 15}, {"lwall7", 10}, {"monsterboss", 20}};
char *clickName[] = {"Home", "Back", "NO", "LevelMap", "StartUI", "Help", "Exit", "YES", "Next", "Remake", "Restart", "Level1", "Level2", "Level3", "Buttonmenu", "MoveUp", "Buttonpause", "GoOn", "Buttonmusic"};
char *cheatName[] = {"monster1", "monster2", "monster3", "monsterboss", "killfire1", "killfire2", "killfire3", "killfire4", "kill5", "kill6", "fire1", "fire2", "firel"};
char *superName[] = {"vwall20", "vwall21", "vwall22", "vwall23", "vwall25", "swall1", "swall2"};
int g_iGameState = 3; // 游戏状态，0 -- 游戏结束等待开始状态；1 -- 按下空格键开始，初始化游戏；2 -- 游戏进行中；3 -- 初始界面
//玩家一
float g_fSpeedLeft = 0.f;  // 左方向速度
float g_fSpeedRight = 0.f; // 右方向速度
float g_fSpeedUp = 0.f;	   // 上方向速度
float g_fSpeedDown = 0.f;  // 下方向速度
float g_iThrust = 0.f;	   //推力大小
int g_icrashcount = 0;	   //碰撞状态
//玩家二
float h_fSpeedLeft = 0.f;  // 左方向速度
float h_fSpeedRight = 0.f; // 右方向速度
float h_fSpeedUp = 0.f;	   // 上方向速度
float h_fSpeedDown = 0.f;  // 下方向速度
float h_iThrust = 0.f;	   //推力大小
int h_icrashcount = 0;	   //碰撞状态

float LevelVelocity = 30.f;	  //玩家方向速度
float VerticalThrust = -70; //竖直推力大小
//
void GameInit();
void GameRun(float fDeltaTime);
void GameEnd();
void SendButtle(const char *szName, const int face);			  //发射子弹
void blood(struct Weapon m);									  //人物、怪物血量
void WithTimeRun(float fDeltaTime);								  //火焰间隔以及炮弹发射时间间隔
void level1collide(const char *szSrcName, const char *szTarName); //第一关碰撞条件
void level2collide(const char *szSrcName, const char *szTarName); //第二关碰撞条件
void level3collide(const char *szSrcName, const char *szTarName); //第三关碰撞条件
void level4collide(const char *szSrcName, const char *szTarName); //第四关碰撞条件
void level4();
void RestartPosition(const char *szSrcName);	  //出生点位置
void ResetSpeed(const char *szName, float moveV); //恢复静止前速度
void StopMove(const char *szName);				  //游戏暂停，不可移动
void LevelChoose();								  //关卡选择
void PlayMusic();								  //音乐播放
void MouseHide(float fDeltaTime);
void CheatKeyDown(const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress);
void Victory(); //通关条件
float Time(float fDeltaTime);
//==============================================================================
//
// 大体的程序流程为：GameMainLoop函数为主循环函数，在引擎每帧刷新屏幕图像之后，都会被调用一次。

//==============================================================================
//
// 游戏主循环，此函数将被不停的调用，引擎每刷新一次屏幕，此函数即被调用一次
// 用以处理游戏的开始、进行中、结束等各种状态.
// 函数参数fDeltaTime : 上次调用本函数到此次调用本函数的时间间隔，单位：秒
//
// 每局开始前进行初始化，清空上一局相关数据

void GameMainLoop(float fDeltaTime)
{


	switch (g_iGameState)
	{
		// 初始化游戏，清空上一局相关数据
	case 1:
	{
		GameInit();

		g_iGameState = 2; // 初始化之后，将游戏状态设置为进行中

	}
	break;

		// 游戏进行中，处理各种游戏逻辑
	case 2:
	{
		// TODO 修改此处游戏循环条件，完成正确游戏逻辑
		if (list[0].iHp != 0 && list[1].iHp != 0)
		{
			GameRun(fDeltaTime);

		}
		else
		{
			// 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
			g_iGameState = 0;
			GameEnd();
		}
	}
	break;
	case 3:
	{
		//初始界面，播放BGM
		g_iGameState = 0;
		dStopAllSound();
		dPlaySound("StartBGM.ogg", 1, 1);

	}
	break;
		// 游戏结束/等待按空格键开始
	case 0:
	{
		MouseHide(fDeltaTime);
		//游戏静音
		dSetStaticSpriteFrame("Buttonmusic", Musicplay);
		if (Musicplay)
			dStopAllSound();
	}
	break;
	default:
		break;
	};
}

//==============================================================================
//
// 每局开始前进行初始化，清空上一局相关数据
void GameInit()
{

	passlevel = 0;
	dSetSpritePosition("menupage", 0, -75);
	dSetSpritePosition("gameover", 75, 2);
	if (level != 4)
	{
		list[0].iHp = Redblood;
		list[1].iHp = Blueblood;
		for (int i = 2; i < 5; i++)
		{
			list[i].iHp = 3;
		}
		dSetSpriteConstantForceY("PlayerRed", 20); //前三关设置Y方向常力
		dSetSpriteConstantForceY("PlayerBlue", 20);
	}
	else
	{
		list[0].iHp = BosslevelPlayerblood;
		list[1].iHp = BosslevelPlayerblood;
		list[7].iHp = Bossblood;
		z = 12, x = 4;
	}
	dSetStaticSpriteFrame("RedBlood", list[0].iHp);
	dSetStaticSpriteFrame("BlueBlood", list[1].iHp);
}
//==============================================================================
//
// 每局游戏进行中
void GameRun(float fDeltaTime)
{

	Victory();
	if (level == 4)
		level4();
	if ((level == 1 || level == 2 || level == 4) && TimeRun == 1)
		WithTimeRun(fDeltaTime); //涉及时间的机关
	if (Musicplay)
		PlayMusic();
	MouseHide(fDeltaTime);
	if (q > 100)
		q = 1; //防止编号过多卡顿
	if (passlevel)
	{
		dSetSpritePosition("menupage", 0, -2.6);
		dPlaySound("Victory.ogg", 0, 1);
		g_iGameState = 0;
	}
	switch (cheat)
	{
	case 4:
	{
		for (int g = 0; g < 7; g++)
			dSetSpriteCollisionActive(superName[g], 0, 0);
		dSetSpriteWorldLimit("PlayerRed", WORLD_LIMIT_STICKY, -50, -37.5, 50, 37.5);
		dSetSpriteWorldLimit("PlayerBlue", WORLD_LIMIT_STICKY, -50, -37.5, 50, 37.5);
	}
	case 3:
		dSetSpriteCollisionActive("vwall24", 0, 0);
		dSetSpriteCollisionActive("lwall30", 0, 0);
		dSetSpriteCollisionActive("laser", 0, 0);
	case 2:
	{
		for (int i = 0; i < 13; i++)
			dSetSpriteCollisionActive(cheatName[i], 0, 0);
	}
	case 1:
		list[0].iHp = 5;
		list[1].iHp = 5;
		break;
	case 0:
		break;
	}
}
//==============================================================================
//
// 本局游戏结束
void GameEnd()
{
	dPlaySound("Gameover.ogg", 0, 1);
	dSetSpritePosition("gameover", 0, -2);
}
//==========================================================================
//
// 鼠标移动
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void OnMouseMove(const float fMouseX, const float fMouseY)
{

	stay = 0;
	dShowCursor(0);
	if (dIsPointInSprite("StartUI", fMouseX, fMouseY)) //Start标签放大
	{
		dSetStaticSpriteFrame("StartUI", 1);
	}
	else
	{
		dSetStaticSpriteFrame("StartUI", 0);
	}
	if (dIsPointInSprite("Help", fMouseX, fMouseY)) //Help标签放大
	{
		dSetStaticSpriteFrame("Help", 1);
	}
	else
	{
		dSetStaticSpriteFrame("Help", 0);
	}
	if (dIsPointInSprite("About", fMouseX, fMouseY)) //About标签放大
	{
		dSetStaticSpriteFrame("About", 1);
	}
	else
	{
		dSetStaticSpriteFrame("About", 0);
	}
	if (dIsPointInSprite("Exit", fMouseX, fMouseY)) //Exit标签放大
	{
		dSetStaticSpriteFrame("Exit", 1);
	}
	else
	{
		dSetStaticSpriteFrame("Exit", 0);
	}
	if (dIsPointInSprite("Back", fMouseX, fMouseY)) //Back标签放大
	{
		dSetStaticSpriteFrame("Back", 1);
	}
	else
	{
		dSetStaticSpriteFrame("Back", 0);
	}
	if (dIsPointInSprite("YES", fMouseX, fMouseY)) //YES标签放大
	{
		dSetStaticSpriteFrame("YES", 1);
	}
	else
	{
		dSetStaticSpriteFrame("YES", 0);
	}
	if (dIsPointInSprite("NO", fMouseX, fMouseY)) //NO标签放大
	{
		dSetStaticSpriteFrame("NO", 1);
	}
	else
	{
		dSetStaticSpriteFrame("NO", 0);
	}
	if (dIsPointInSprite("Level1", fMouseX, fMouseY)) //第一关标签放大
	{
		dSetStaticSpriteFrame("Level1", 1);
	}
	else
	{
		dSetStaticSpriteFrame("Level1", 0);
	}
	if (dIsPointInSprite("Level2", fMouseX, fMouseY)) //第二关标签放大
	{
		dSetStaticSpriteFrame("Level2", 1);
	}
	else
	{
		dSetStaticSpriteFrame("Level2", 0);
	}
	if (dIsPointInSprite("Level3", fMouseX, fMouseY)) //第三关标签放大
	{
		dSetStaticSpriteFrame("Level3", 1);
	}
	else
	{
		dSetStaticSpriteFrame("Level3", 0);
	}
	if (dIsPointInSprite("Remake", fMouseX, fMouseY)) //重玩标签放大
	{
		dSetStaticSpriteFrame("Remake", 1);
	}
	else
	{
		dSetStaticSpriteFrame("Remake", 0);
	}
	if (dIsPointInSprite("LevelMap", fMouseX, fMouseY)) //返回地图标签放大
	{
		dSetStaticSpriteFrame("LevelMap", 1);
	}
	else
	{
		dSetStaticSpriteFrame("LevelMap", 0);
	}
	if (dIsPointInSprite("Next", fMouseX, fMouseY)) //下一关标签放大
	{
		dSetStaticSpriteFrame("Next", 1);
	}
	else
	{
		dSetStaticSpriteFrame("Next", 0);
	}
	if (dIsPointInSprite("Restart", fMouseX, fMouseY)) //返回地图标签放大
	{
		dSetStaticSpriteFrame("Restart", 1);
	}
	else
	{
		dSetStaticSpriteFrame("Restart", 0);
	}
	if (dIsPointInSprite("BacktoMap", fMouseX, fMouseY)) //重新开始标签放大
	{
		dSetStaticSpriteFrame("BacktoMap", 1);
	}
	else
	{
		dSetStaticSpriteFrame("BacktoMap", 0);
	}
	if (dIsPointInSprite("MoveUp", fMouseX, fMouseY)) //返回标签放大
	{
		dSetStaticSpriteFrame("MoveUp", 1);
	}
	else
	{
		dSetStaticSpriteFrame("MoveUp", 0);
	}
	if (dIsPointInSprite("close", fMouseX, fMouseY)) //关闭提示标签放大
	{
		dSetStaticSpriteFrame("close", 1);
	}
	else
	{
		dSetStaticSpriteFrame("close", 0);
	}
	if (dIsPointInSprite("CloseBlack", fMouseX, fMouseY)) //关闭提示标签放大
	{
		dSetStaticSpriteFrame("CloseBlack", 1);
	}
	else
	{
		dSetStaticSpriteFrame("CloseBlack", 0);
	}
		if (dIsPointInSprite("nextstart", fMouseX, fMouseY))
	{
		dSetStaticSpriteFrame("nextstart", 1);
	}
	else
	{
		dSetStaticSpriteFrame("nextstart", 0);
	}
			if (dIsPointInSprite("envelope", fMouseX, fMouseY))
	{
		dSetStaticSpriteFrame("envelope", 1);
	}
	else
	{
		dSetStaticSpriteFrame("envelope", 0);
	}
}
//==========================================================================
//
// 鼠标点击
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void OnMouseClick(const int iMouseType, const float fMouseX, const float fMouseY)
{
	if (MOUSE_LEFT == iMouseType)
	{
		//判断鼠标点击的中心位置是否和所选位置相同，相同则跳到相应画面
		if (dIsPointInSprite("nextstart", fMouseX, fMouseY))

			zhen=zhen+1;
			dSetStaticSpriteFrame("st2", zhen);
			if(zhen==4){
				level = 10;
				LevelChoose();
				g_iGameState = 0;
				zhen=0;
			}
		}
		if (dIsPointInSprite("envelope", fMouseX, fMouseY))
		{
				level = 14;
				LevelChoose();


		}
		if (dIsPointInSprite("Home", fMouseX, fMouseY) || dIsPointInSprite("Back", fMouseX, fMouseY) || dIsPointInSprite("NO", fMouseX, fMouseY)) //返回主页
		{
			level = 0;
			LevelChoose();
		}
		if (dIsPointInSprite("LevelMap", fMouseX, fMouseY) || dIsPointInSprite("BackToMap", fMouseX, fMouseY) || dIsPointInSprite("CloseBlack", fMouseX, fMouseY)) //回到关卡选择
		{
			level = 10;
			LevelChoose();
			g_iGameState = 3;
		}
		if (dIsPointInSprite("StartUI", fMouseX, fMouseY)) //载入关卡选择
		{
			level = 10;
			LevelChoose();
			g_iGameState = 0;
			dPlaySound("Click.ogg", 0, 1);
		}
		if (dIsPointInSprite("Help", fMouseX, fMouseY)) //打开操作说明
		{
			level = 11;
			LevelChoose();
			dPlaySound("Click.ogg", 0, 1);
		}
		if (dIsPointInSprite("About", fMouseX, fMouseY)) //打开介绍页面
		{
			level = 13;
			LevelChoose();
			dPlaySound("Click.ogg", 0, 1);
		}
		if (dIsPointInSprite("Exit", fMouseX, fMouseY)) //退出游戏
		{
			level = 12;
			LevelChoose();
			dPlaySound("Click.ogg", 0, 1);
		}
		if (dIsPointInSprite("YES", fMouseX, fMouseY)) //关闭游戏引擎
			dShutdownGameEngine();
		/*if(dIsPointInSprite("Next",fMouseX,fMouseY))		//下一关
			{level++;LevelChoose( );}dPlaySound("Click.ogg",0,1);*/
		if (level == 2 && dIsPointInSprite("Next", fMouseX, fMouseY))
		{
			level = 1;
			LevelChoose();
			dPlaySound("Click.ogg", 0, 1);
		}
		if (level == 1 && dIsPointInSprite("Next", fMouseX, fMouseY))
		{
			level = 3;
			LevelChoose();
			dPlaySound("Click.ogg", 0, 1);
		}
		if (level != 1 && level != 2 && dIsPointInSprite("Next", fMouseX, fMouseY)) //下一关
		{
			level++;
			LevelChoose();
		}
		dPlaySound("Click.ogg", 0, 1);
		if (dIsPointInSprite("Remake", fMouseX, fMouseY) || dIsPointInSprite("Restart", fMouseX, fMouseY)) //重玩本关
		{
			passlevel = 1;
			LevelChoose();
		}
		if (dIsPointInSprite("Level1", fMouseX, fMouseY)) //载入第一关
		{
			level = 1;
			LevelChoose();
			dPlaySound("Click.ogg", 0, 1);
		}
		if (dIsPointInSprite("Level2", fMouseX, fMouseY)) //载入第二关
		{
			level = 2;
			LevelChoose();
			dPlaySound("Click.ogg", 0, 1);
		}
		if (dIsPointInSprite("Level3", fMouseX, fMouseY)) //载入第三关
		{
			level = 3;
			LevelChoose();
			dPlaySound("Click.ogg", 0, 1);
		}
		if (dIsPointInSprite("CloseBlack", fMouseX, fMouseY)) //关闭提示
		{
			dSetSpritePosition("Tip", 4, 55);
		}
		if (dIsPointInSprite("close", fMouseX, fMouseY)) //关闭提示
		{
			dSetSpritePosition("Tip", 4, 55);
		}

		if (dIsPointInSprite("Buttonmenu", fMouseX, fMouseY)) //菜单
			dSetSpritePosition("menupage", 0, -2.6);
		dPlaySound("Click.ogg", 0, 1);
		if (dIsPointInSprite("MoveUp", fMouseX, fMouseY)) //收起菜单
			dSetSpritePosition("menupage", 0, -75);
		dPlaySound("Click.ogg", 0, 1);

		if (dIsPointInSprite("Buttonpause", fMouseX, fMouseY)) //暂停游戏
		{
			TimeRun = 0;
			dStopAllSound();
			dSetStaticSpriteFrame("Buttonpause", 1);
			dSetSpritePosition("GoOn", 0, 0);
			dSetSpriteImmovable("PlayerRed", 1);
			dSetSpriteImmovable("PlayerBlue", 1);
			dSetSpriteVisible("Red", 0);
			dSetSpriteVisible("Blue", 0);
			if (level == 1)
			{
				dSetSpriteVisible("muban", 0);
				for (int i = 2; i < 7; i++)
					StopMove(list[i].szName);
			}
			if (level == 3)
			{
				for (int a = 0; a < 6; a++)
					StopMove(wall[a].szName);
			}
			if (level == 4)
				level = 5;
		}

		if (dIsPointInSprite("GoOn", fMouseX, fMouseY)) //继续游戏
		{
			TimeRun = 1;
			PlayMusic();
			dSetStaticSpriteFrame("Buttonpause", 0);
			dSetSpritePosition("GoOn", 50, -50);
			dSetSpriteImmovable("PlayerRed", 0);
			dSetSpriteImmovable("PlayerBlue", 0);
			dSetSpriteVisible("Red", 1);
			dSetSpriteVisible("Blue", 1);
			if (level == 1)
			{
				dSetSpriteVisible("muban", 1);
				for (int i = 2; i < 7; i++)
					ResetSpeed(list[i].szName, list[i].iV);
			}
			if (level == 3)
			{
				for (int a = 0; a < 6; a++)
					ResetSpeed(wall[a].szName, wall[a].wV);
			}
			if (level == 5)
				level = 4;
		}

		if (Musicplay == 0) //播放点击音效
		{
			for (int d = 0; d < 18; d++)
			{
				if (dIsPointInSprite(clickName[d], fMouseX, fMouseY))
					dPlaySound("Click", 0, 0.9);
			}
		}

		if (dIsPointInSprite("Buttonmusic", fMouseX, fMouseY)) //关闭/开启背景音乐音效
		{
			if (Musicplay == 0) //关闭
			{
				Musicplay = 1;
				dSetStaticSpriteFrame("Buttonmusic", 1);
			}
			else //开启
			{
				Musicplay = 0;
				dSetStaticSpriteFrame("Buttonmusic", 0);
				if (level == 0 || level == 10 || level == 11 || level == 12)
					g_iGameState = 3;
				else if (level == 1 || level == 2 || level == 3 || level == 4)
					PlayMusic();
			}
		}
	}

//==========================================================================
//
// 鼠标弹起
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void OnMouseUp(const int iMouseType, const float fMouseX, const float fMouseY)
{
}
//==========================================================================
//
// 键盘按下
// 参数 iKey：被按下的键，值见 enum KeyCodes 宏定义
// 参数 iAltPress, iShiftPress，iCtrlPress：键盘上的功能键Alt，Ctrl，Shift当前是否也处于按下状态(0未按下，1按下)
void OnKeyDown(const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress)
{
	if (KEY_Z == iKey && 0 == g_iGameState) //按下Z开始游戏
	{
		g_iGameState = 1;
	}

	if (2 == g_iGameState) //游戏进行中
	{
		switch (iKey)
		{
		case KEY_W:
			if (level == 4)
				g_fSpeedUp = -LevelVelocity;
			else if (1 == g_icrashcount)
			{
				g_iThrust = VerticalThrust;
				g_icrashcount = 0;

				dSetSpriteImpulseForce("PlayerRed", 0, g_iThrust, 0);


			}
			break;

		case KEY_A:
			g_fSpeedLeft = -LevelVelocity;
			face1 = 1;
			break;
		case KEY_S:
			if (level == 4)
				g_fSpeedDown = LevelVelocity;
			break;
		case KEY_D:
			g_fSpeedRight = LevelVelocity;
			face1 = 0;
			break;
		case KEY_UP:
			if (level == 4)
				h_fSpeedUp = -LevelVelocity;
			if (1 == h_icrashcount)
			{
				h_iThrust = VerticalThrust;
				h_icrashcount = 0;
				dSetSpriteImpulseForce("PlayerBlue", 0, h_iThrust, 0);
			}
			break;

		case KEY_LEFT:
			h_fSpeedLeft = -LevelVelocity;
			face2 = 1;
			break;
		case KEY_DOWN:
			if (level == 4)
				h_fSpeedDown = LevelVelocity;
			break;
		case KEY_RIGHT:
			h_fSpeedRight = LevelVelocity;
			face2 = 0;
			break;
		case KEY_SPACE:
			SendButtle("PlayerRed", face1);
			break;
		case KEY_ENTER:
		case KEY_NUMPADENTER:
			SendButtle("PlayerBlue", face2);
			break;
		default:
			break;
		}
		//设置人物X方向速度
		dSetSpriteLinearVelocityX("PlayerRed", g_fSpeedLeft + g_fSpeedRight);
		dSetSpriteLinearVelocityX("PlayerBlue", h_fSpeedLeft + h_fSpeedRight);
		if (level == 4)
		{
			dSetSpriteLinearVelocityY("PlayerRed", g_fSpeedUp + g_fSpeedDown);
			dSetSpriteLinearVelocityY("PlayerBlue", h_fSpeedUp + h_fSpeedDown);
		}
		//人物朝向
		if ((g_fSpeedLeft + g_fSpeedRight) > 0.f)
			dAnimateSpritePlayAnimation("PlayerRed", "playerRAnimationR", 0);
		if ((g_fSpeedLeft + g_fSpeedRight) < 0.f)
			dAnimateSpritePlayAnimation("PlayerRed", "playerRAnimationL", 0);
		if ((h_fSpeedLeft + h_fSpeedRight) > 0.f)
			dAnimateSpritePlayAnimation("PlayerBlue", "playerBAnimationR", 0);
		else if ((h_fSpeedLeft + h_fSpeedRight) < 0.f)
			dAnimateSpritePlayAnimation("PlayerBlue", "playerBAnimationL", 0);
	}
}
//==========================================================================
//
// 键盘弹起
// 参数 iKey：弹起的键，值见 enum KeyCodes 宏定义
void OnKeyUp(const int iKey)
{
	switch (iKey)
	{
	case KEY_W:
		if (level == 4)
			g_fSpeedUp = 0;
		break;
	case KEY_A:
		g_fSpeedLeft = 0.f;
		if ((g_fSpeedLeft + g_fSpeedRight) == 0.f)
			dAnimateSpritePlayAnimation("PlayerRed", "playerRAnimationSL", 0);
		dSetAnimateSpriteFrame("PlayerRed", 2);
		face1 = 1;
		break;
	case KEY_S:
		if (level == 4)
			g_fSpeedDown = 0;
		break;
	case KEY_D:
		g_fSpeedRight = 0.f;
		if ((g_fSpeedLeft + g_fSpeedRight) == 0.f)
			dAnimateSpritePlayAnimation("PlayerRed", "playerRAnimationSR", 0);
		face1 = 0;
		break;
	case KEY_UP:
		if (level == 4)
			h_fSpeedUp = 0;
		break;
	case KEY_LEFT:
		h_fSpeedLeft = 0.f;
		if ((h_fSpeedLeft + h_fSpeedRight) == 0.f)
			dAnimateSpritePlayAnimation("PlayerBlue", "playerBAnimationSL", 0);
		face2 = 1;
		break;
	case KEY_DOWN:
		if (level == 4)
			h_fSpeedDown = 0;
		break;

	case KEY_RIGHT:
		h_fSpeedRight = 0.f;
		if ((h_fSpeedLeft + h_fSpeedRight) == 0.f)
			dAnimateSpritePlayAnimation("PlayerBlue", "playerBAnimationSR", 0);
		face2 = 0;
		break;
	}

	dSetSpriteLinearVelocityX("PlayerRed", g_fSpeedLeft + g_fSpeedRight);
	dSetSpriteLinearVelocityX("PlayerBlue", h_fSpeedLeft + h_fSpeedRight);
	if (level == 4)
	{
		dSetSpriteLinearVelocityY("PlayerRed", g_fSpeedUp + g_fSpeedDown);
		dSetSpriteLinearVelocityY("PlayerBlue", h_fSpeedUp + h_fSpeedDown);
	}
}
//===========================================================================
//
float Time(float fDeltaTime){
	iftouch += fDeltaTime;
	return iftouch;
}
// 精灵与精灵碰撞
// 参数 szSrcName：发起碰撞的精灵名字
// 参数 szTarName：被碰撞的精灵名字
void OnSpriteColSprite(const char *szSrcName, const char *szTarName)
{


		if (strstr(szSrcName, "PlayerBlue") != 0 && strstr(szTarName, "lwall12") != 0 || (strstr(szTarName, "lwall12") != 0 && strstr(szSrcName, "PlayerBlue") != 0))
	{

		dSpriteMountToSprite( "b11", "PlayerBlue",2,-2.5);
		dSetSpriteLifeTime( "b11",2);
	}
			if (strstr(szSrcName, "PlayerRed") != 0 && strstr(szTarName, "lwall10") != 0 || (strstr(szTarName, "lwall10") != 0 && strstr(szSrcName, "PlayerRed") != 0))
	{

		dSpriteMountToSprite( "r11", "PlayerRed",2,-2.5);
		dSetSpriteLifeTime( "r11",2);
	}
			if (strstr(szSrcName, "PlayerRed") != 0 && strstr(szTarName, "lwall2") != 0 || (strstr(szTarName, "lwall2") != 0 && strstr(szSrcName, "PlayerRed") != 0))
	{

		dSpriteMountToSprite( "r12", "PlayerRed",2,-2.5);
		dSetSpriteLifeTime( "r12",2);
	}
		if (strstr(szSrcName, "PlayerBlue") != 0 && strstr(szTarName, "lwall2") != 0 || (strstr(szTarName, "lwall2") != 0 && strstr(szSrcName, "PlayerBlue") != 0))
	{

		dSpriteMountToSprite( "b12", "PlayerBlue",2,-2.5);
		dSetSpriteLifeTime( "b12",2);
	}
		if (strstr(szSrcName, "PlayerBlue") != 0 && strstr(szTarName, "lwall5") != 0 || (strstr(szTarName, "lwall5") != 0 && strstr(szSrcName, "PlayerBlue") != 0))
	{

		dSpriteMountToSprite( "b21", "PlayerBlue",2,-2.5);
		dSetSpriteLifeTime( "b21",2);
	}
			if (strstr(szSrcName, "PlayerRed") != 0 && strstr(szTarName, "lwall5") != 0 || (strstr(szTarName, "lwall5") != 0 && strstr(szSrcName, "PlayerRed") != 0))
	{

		dSpriteMountToSprite( "r21", "PlayerRed",2,-2.5);
		dSetSpriteLifeTime( "r21",2);
	}
			if (strstr(szSrcName, "PlayerRed") != 0 && strstr(szTarName, "keydown") != 0 || (strstr(szTarName, "keydown") != 0 && strstr(szSrcName, "PlayerRed") != 0))
	{

		dSpriteMountToSprite( "r22", "PlayerRed",2,-2.5);
		dSetSpriteLifeTime( "r22",2);
	}
		if (strstr(szSrcName, "PlayerBlue") != 0 && strstr(szTarName, "keyup") != 0 || (strstr(szTarName, "keyup") != 0 && strstr(szSrcName, "keyup") != 0))
	{

		dSpriteMountToSprite( "b22", "PlayerBlue",2,-2.5);
		dSetSpriteLifeTime( "b22",2);
	}
		if (strstr(szSrcName, "PlayerBlue") != 0 && strstr(szTarName, "lwall9") != 0 || (strstr(szTarName, "lwall9") != 0 && strstr(szSrcName, "keyup") != 0))
	{

		dSpriteMountToSprite( "b23", "PlayerBlue",2,-2.5);
		dSetSpriteLifeTime( "b23",2);
	}
			if (strstr(szSrcName, "PlayerRed") != 0 && strstr(szTarName, "lwall10") != 0 || (strstr(szTarName, "lwall10") != 0 && strstr(szSrcName, "PlayerRed") != 0))
	{

		dSpriteMountToSprite( "r23", "PlayerRed",2,-2.5);
		dSetSpriteLifeTime( "r23",2);
	}
	if (strstr(szSrcName, "PlayerBlue") != 0 && strstr(szTarName, "lwall12") != 0 || (strstr(szTarName, "lwall12") != 0 && strstr(szSrcName, "keyup") != 0))
	{

		dSpriteMountToSprite( "b24", "PlayerBlue",2,-2.5);
		dSetSpriteLifeTime( "b24",2);
	}
			if (strstr(szSrcName, "PlayerRed") != 0 && strstr(szTarName, "lwall2") != 0 || (strstr(szTarName, "lwall2") != 0 && strstr(szSrcName, "PlayerRed") != 0))
	{

		dSpriteMountToSprite( "r31", "PlayerRed",2,-2.5);
		dSetSpriteLifeTime( "r31",2);
	}
		if (strstr(szSrcName, "PlayerBlue") != 0 && strstr(szTarName, "lwall11") != 0 || (strstr(szTarName, "lwall11") != 0 && strstr(szSrcName, "keyup") != 0))
	{

		dSpriteMountToSprite( "b31", "PlayerBlue",2,-2.5);
		dSetSpriteLifeTime( "b31",2);
	}
				if (strstr(szSrcName, "PlayerRed") != 0 && strstr(szTarName, "lwall7") != 0 || (strstr(szTarName, "lwall7") != 0 && strstr(szSrcName, "PlayerRed") != 0))
	{

		dSpriteMountToSprite( "r32", "PlayerRed",2,-2.5);
		dSetSpriteLifeTime( "r32",2);
	}
			if (strstr(szSrcName, "PlayerBlue") != 0 && strstr(szTarName, "lwall10") != 0 || (strstr(szTarName, "lwall10") != 0 && strstr(szSrcName, "keyup") != 0))
	{

		dSpriteMountToSprite( "b32", "PlayerBlue",2,-2.5);
		dSetSpriteLifeTime( "b32",2);
	}
			if (strstr(szSrcName, "PlayerBlue") != 0 && strstr(szTarName, "swall1") != 0 || (strstr(szTarName, "swall1") != 0 && strstr(szSrcName, "keyup") != 0))
	{

		dSpriteMountToSprite( "b41", "PlayerBlue",2,-2.5);
		dSetSpriteLifeTime( "b41",2);
	}
			if (strstr(szSrcName, "PlayerRed") != 0 && strstr(szTarName, "swall1") != 0 || (strstr(szTarName, "swall1") != 0 && strstr(szSrcName, "PlayerRed") != 0))
	{

		dSpriteMountToSprite( "r41", "PlayerRed",2,-2.5);
		dSetSpriteLifeTime( "r41",2);
	}

	//玩家掉下边界，回到出发点
	if (stricmp("ground", szTarName) == 0)
	{
		for (int i = 0; i < 2; i++)
		{
			if (strcmp(list[i].szName, szSrcName) == 0)
			{
				RestartPosition(szSrcName);
				list[i].iHp--;
				blood(list[i]);
			}
		}
	}
	//玩家和墙壁碰撞
	if (strstr(szSrcName, "Player") != 0 && strstr(szTarName, "lwall") != 0)
	{
		dSetSpriteLinearVelocityY(szSrcName, 0);
		if (strstr(szSrcName, "PlayerRed")) //判断玩家Red位于墙壁上表面
		{
			if (dGetSpritePositionY("PlayerRed") < dGetSpritePositionY(szTarName))
				g_icrashcount = 1;
			else
				g_icrashcount = 0;
		}
		else if (strstr(szSrcName, "PlayerBlue")) //判断玩家Blue位于墙壁上表面
		{
			if (dGetSpritePositionY("PlayerBlue") < dGetSpritePositionY(szTarName))
				h_icrashcount = 1;
			else
				h_icrashcount = 0;
		}
	}
	if (strstr(szSrcName, "Player") != 0 && strstr(szTarName, "vwall") != 0)
		dSetSpriteLinearVelocity(szSrcName, 0, 0);
	//子弹与怪物碰撞，子弹消失，怪物血量-1
	if (strstr(szTarName, "monster") != 0 && strstr(szSrcName, "bullet") != 0 || strstr(szSrcName, "monster") != 0 && strstr(szTarName, "bullet") != 0)
	{
		const char *szmonsterName = NULL;
		if (strstr(szSrcName, "monster"))
		{
			szmonsterName = szSrcName;
			dDeleteSprite(szTarName);
			for (int i = 2; i < 5; i++)
			{
				if (strcmp(list[i].szName, szmonsterName) == 0)
				{
					list[i].iHp--;
					blood(list[i]);
				}
			}
		}
		else if (strstr(szTarName, "monster"))
		{
			szmonsterName = szTarName;
			dDeleteSprite(szSrcName);
			for (int i = 2; i < 5; i++)
			{
				if (strcmp(list[i].szName, szmonsterName) == 0)
				{
					list[i].iHp--;
					blood(list[i]);
				}
			}
		}
		else
			return;
	}
	//墙壁和子弹碰撞，子弹消失
	if (strstr(szTarName, "wall") != 0 && strstr(szSrcName, "bullet") != 0 || strstr(szSrcName, "wall") != 0 && strstr(szTarName, "bullet") != 0)
	{
		if (strstr(szSrcName, "wall"))
			dDeleteSprite(szTarName);
		else if (strstr(szTarName, "wall"))
			dDeleteSprite(szSrcName);
		else
			return;
	}

	//玩家与怪物碰撞，玩家血量-1，并回到出发点
	if (strstr(szTarName, "monster") != 0 && strstr(szSrcName, "Player") != 0 || strstr(szSrcName, "monster") != 0 && strstr(szTarName, "Player") != 0)
	{
		for (int i = 0; i < 2; i++)
		{
			if (strcmp(list[i].szName, szSrcName) == 0)
			{
				RestartPosition(szSrcName);
				list[i].iHp--;
				blood(list[i]);
			}
		}
	}
	//玩家与炮弹碰撞
	if (strstr(szSrcName, "Player") != 0 && strstr(szTarName, "cannon") != 0 || (strstr(szTarName, "Player") != 0 && strstr(szSrcName, "cannon") != 0))
	{
		if (strstr(szSrcName, "cannon"))
		{
			dDeleteSprite(szSrcName);
			for (int i = 0; i < 2; i++)
			{
				if (strcmp(list[i].szName, szTarName) == 0)
				{
					RestartPosition(szTarName);
					list[i].iHp--;
					blood(list[i]);
				}
			}
		}
		if (strstr(szTarName, "cannon"))
		{
			dDeleteSprite(szTarName);
			for (int i = 0; i < 2; i++)
			{
				if (strcmp(list[i].szName, szSrcName) == 0)
				{
					RestartPosition(szSrcName);
					list[i].iHp--;
					blood(list[i]);
				}
			}
		}
	}
	//炮弹与墙壁碰撞
	if (strstr(szTarName, "wall") != 0 && strstr(szSrcName, "cannon") != 0 || strstr(szSrcName, "wall") != 0 && strstr(szTarName, "cannon") != 0)
	{
		if (strstr(szSrcName, "wall"))
			dDeleteSprite(szTarName);
		else if (strstr(szTarName, "wall"))
			dDeleteSprite(szSrcName);
		else
			return;
	}

	//不同关卡的不同碰撞条件
	if (level == 1)
		level1collide(szSrcName, szTarName);
	if (level == 2)
		level2collide(szSrcName, szTarName);
	if (level == 3)
		level3collide(szSrcName, szTarName);
	if (level == 4)
		level4collide(szSrcName, szTarName);
}
//===========================================================================
//
// 精灵与世界边界碰撞
// 参数 szName：碰撞到边界的精灵名字
// 参数 iColSide：碰撞到的边界 0 左边，1 右边，2 上边，3 下边
void OnSpriteColWorldLimit(const char *szName, const int iColSide)
{
	//移动的怪物或墙壁在碰到左右边界时翻转显示
	if (strstr(szName, "monster") || strstr(szName, "lwall"))
	{
		if (0 == iColSide)
			dSetSpriteFlipX(szName, 1);
		if (1 == iColSide)
			dSetSpriteFlipX(szName, 0);
	}

}

//===========================================================================
//
void level1collide(const char *szSrcName, const char *szTarName)
{
	//玩家与火焰碰撞
	if (strstr(szSrcName, "Player") != 0 && strstr(szTarName, "fire") != 0)
	{
		for (int i = 0; i < 2; i++)
		{
			if (strcmp(list[i].szName, szSrcName) == 0)
			{
				RestartPosition(szSrcName);
				list[i].iHp--;
				blood(list[i]);
			}
		}
	}
	//玩家与开关碰撞
	if (strstr(szSrcName, "Player") != 0 && stricmp(szTarName, "keyup") == 0)
	{
		//dDeleteSprite("keyup");
		dSetStaticSpriteFrame("keyup", 1);
		dSetSpritePosition("lwall4", -25, 23);
		dSetSpriteLinearVelocityX("lwall4", 10);
	}
	if (strstr(szSrcName, "Player") != 0 && stricmp(szTarName, "keydown") == 0)
	{
		//dDeleteSprite("keydown");
		dSetStaticSpriteFrame("keydown", 1);
		dDeleteSprite("fire1");
	}
}
//===========================================================================
//
void level2collide(const char *szSrcName, const char *szTarName)
{
	//玩家与火焰
	if (strstr(szSrcName, "Player") != 0 && strstr(szTarName, "kill") != 0)
	{
		for (int i = 0; i < 2; i++)
		{
			if (strcmp(list[i].szName, szSrcName) == 0)
			{
				RestartPosition(szSrcName);
				list[i].iHp--;
				blood(list[i]);
			}
		}
	}
	//玩家与吹风机碰撞
	if (strstr(szSrcName, "Player") != 0 && strstr(szTarName, "windflow") != 0)
		dSetSpriteImpulseForce(szSrcName, 0, -160, 0);
}
//===========================================================================
//
void level3collide(const char *szSrcName, const char *szTarName)
{
	//激光束与玩家碰撞
	if (strstr(szSrcName, "Player") != 0 && stricmp("laser", szTarName) == 0)
	{
		for (int i = 0; i < 2; i++)
		{
			if (strcmp(list[i].szName, szSrcName) == 0)
			{
				RestartPosition(szSrcName);
				list[i].iHp--;
				blood(list[i]);
			}
		}
	}
	//玩家与传送门碰撞
	if (strstr(szSrcName, "Player") != 0 && stricmp(szTarName, "tpdoordown") == 0)
	{
		float iPoX;
		float iPoY, tpY;
		iPoX = dGetSpritePositionX(szSrcName);
		iPoY = dGetSpritePositionY(szSrcName);
		tpY = dGetSpritePositionY("tpdoordown");
		if (iPoY <= tpY)
			dSetSpritePosition(szSrcName, iPoX - 35, iPoY - 22);
		else
			dSetSpritePosition(szSrcName, iPoX - 35, iPoY - 40);
	}
	if (strstr(szSrcName, "Player") != 0 && stricmp(szTarName, "tpdoorup") == 0)
	{
		float iPoX;
		float iPoY, tpY;
		iPoX = dGetSpritePositionX(szSrcName);
		iPoY = dGetSpritePositionY(szSrcName);
		tpY = dGetSpritePositionY("tpdoorup");
		if (iPoY <= tpY)
			dSetSpritePosition(szSrcName, iPoX + 35, iPoY + 40);
		else
			dSetSpritePosition(szSrcName, iPoX + 35, iPoY + 22);
	}
	//玩家与机关碰撞，触发传送门
	if (strstr(szSrcName, "Player") != 0 && stricmp(szTarName, "key") == 0)
	{
		dDeleteSprite("key");
		dDeleteSprite("laser");
		dSetSpritePosition("tpdoordown", 35, 3.750);
		dSetSpritePosition("tpdoorup", 0, -26.250);
	}
}
//===========================================================================
//
void level4collide(const char *szSrcName, const char *szTarName)
{
	if (strstr(szTarName, "Boss") != 0 && strstr(szSrcName, "bullet") != 0 || strstr(szSrcName, "Boss") != 0 && strstr(szTarName, "bullet") != 0)
	{
		if (strstr(szSrcName, "Boss"))
		{
			dDeleteSprite(szTarName);
			list[7].iHp--;
			blood(list[7]);
		}
		else if (strstr(szTarName, "Boss"))
		{
			dDeleteSprite(szSrcName);
			list[7].iHp--;
			blood(list[7]);
		}
		else
			return;
	}
	if (strstr(szSrcName, "Player") != 0 && strstr(szTarName, "swall") != 0)
		dSetSpriteLinearVelocityX(szSrcName, 0);
	dSetSpriteWidth("BossBlood", 86 * list[7].iHp / 200);
}
//===========================================================================
//
//子弹生成与发射
//参数 szName：子弹模板名字
//参数 face：子弹发射朝向
void SendButtle(const char *szName, const int face)
{
	char Name[128];
	float fiPosX, fiPosY;
	float fSpeedX1, fSpeedY1;
	float iPoX;
	float iPoY;
	iPoX = dGetSpritePositionX(szName);
	iPoY = dGetSpritePositionY(szName);

	sprintf(Name, "bullet%d", n);
	n++;
	if (strstr(szName, "Red"))
		dCloneSprite("Red", Name);
	if (strstr(szName, "Blue"))
		dCloneSprite("Blue", Name);
	if (face)
	{
		fSpeedX1 = -50;
		dSetSpritePosition(Name, iPoX - 3.f, iPoY);
		dSetSpriteFlipX(Name, 1);
	}
	else
	{
		fSpeedX1 = 50;
		dSetSpritePosition(Name, iPoX + 3.f, iPoY);
	}
	dSetSpriteLinearVelocity(Name, fSpeedX1, 0);
}

//===========================================================================
//
//人物，怪物血量
void blood(struct Weapon m)
{
	if (m.iHp == 0 && cheat == 0)
		dDeleteSprite(m.szName);
	if (strstr(m.szName, "Player") != 0 && cheat == 0)
	{
		dPlaySound("Death.ogg", 0, 0.9);
		dSetStaticSpriteFrame("RedBlood", list[0].iHp);
		dSetStaticSpriteFrame("BlueBlood", list[1].iHp);
	}
}
//===========================================================================
//
//回到出发点位置
//参数 szSrcName：精灵名字
void RestartPosition(const char *szSrcName)
{
	if (cheat == 0)
	{
		switch (level)
		{
		case 1:
			dSetSpritePosition(szSrcName, -47, -10);
			break;
		case 2:
			if (strstr(szSrcName, "PlayerRed"))
				dSetSpritePosition("PlayerRed", -48, 30);
			if (strstr(szSrcName, "PlayerBlue"))
				dSetSpritePosition("PlayerBlue", 48, 30);
			break;
		case 3:
			dSetSpritePosition(szSrcName, -47, 32);
			break;
		case 4:
			break;
		}
	}
}
//===========================================================================
//
//时间的函数
void WithTimeRun(float fDeltaTime)
{
	w += fDeltaTime;
	if (p)
	{
		dSetSpritePosition("killfire1", -20, -27.5);
		dSetSpritePosition("killfire2", 20, -27.5);
		dSetSpritePosition("killfire3", 0, -55);
		dSetSpritePosition("killfire4", -6.25, 42);
		dSetSpritePosition("firel", 9, 14.5);
		middle1 = w;
		p = 0;
	}
	if (w > middle1 + 1.f && w < middle1 + 2.f)
	{
		dSetSpritePosition("killfire1", -20, -50);
		dSetSpritePosition("killfire2", 20, -50);
		dSetSpritePosition("killfire3", 0, -22.5);
		dSetSpritePosition("killfire4", -6.25, 1.25);
		dSetSpritePosition("firel", 9, 47.5);
	}
	if (w >= middle1 + 2.f)
		p = 1;

	if (e && level == 1)
	{
		char szName[128];
		float iPoX = dGetSpritePositionX("shoot");
		float iPoY = dGetSpritePositionY("shoot");

		sprintf(szName, "cannon%d", q);
		q++;
		dCloneSprite("muban", szName);
		dSetSpritePosition(szName, iPoX - 2.25, iPoY + 4.60);
		dSetSpriteLinearVelocityPolar(szName, 20, 120);
		middle2 = w;
		e = 0;
	}
	if (w >= middle2 + 0.2)
		e = 1;

	if (r && level == 4)
	{
		float iPoX = dRandomRange(-20, 20);
		float iPoY = dRandomRange(-20, 20);
		dSetSpriteLinearVelocity("Boss", iPoX, iPoY);
		middle3 = w;
		if (iPoX >= 0)
			dSetSpriteFlipX("Boss", 1);
		else
			dSetSpriteFlipX("Boss", 0);
		r = 0;
	}
	if (w >= middle3 + 1)
		r = 1;

	if (t && level == 4)
	{
		float PoX = dGetSpriteLinkPointPosX("Boss", 1);
		float PoY = dGetSpriteLinkPointPosY("Boss", 1);
		for (int i = 0; i < x; i++)
		{
			char szName[128];
			sprintf(szName, "cannon%d", q);
			q++;
			dCloneSprite("muban", szName);
			dSetSpritePosition(szName, PoX, PoY);
			dSetSpriteLinearVelocityPolar(szName, z, 90 + i * 180 / x);
		}
		middle4 = w;
		t = 0;
	}
	if (w >= middle4 + 0.5)
		t = 1;
}

//===========================================================================
//
//隐藏鼠标
void talk(float fDeltaTime){
	iftouch += fDeltaTime;
	if(stay>2){
			dSpriteMountToSprite( "Redget1", "PlayerRed",2,-2);
	dSetSpriteLifeTime( "Redget1",2);
	}
}
void MouseHide(float fDeltaTime)
{
	stay += fDeltaTime;
	if (stay > 2)
		dSetSpritePosition( "sprite",2,48 );

}
//===========================================================================
//
//关卡选择
//参数 Enterlevel：将进入的关卡序数
void LevelChoose()
{
	switch (level)
	{
	case 0:
		dLoadMap("StartUI.t2d");
		break;
	case 1:
		dLoadMap("Lv1.t2d");
		g_iGameState = 1;
		VerticalThrust = -68;
		PlayMusic();
		break;
	case 2:
		dLoadMap("Lv2.t2d");
		g_iGameState = 1;
		VerticalThrust = -63;
		PlayMusic();
		break;
	case 3:
		dLoadMap("Lv3.t2d");
		g_iGameState = 1;
		VerticalThrust = -68;
		PlayMusic();
		break;
	case 4:
	{
		if (passlevel == 0)
		{
			dSetSpritePosition("Tip", 4, 0);
			level = 3;
		}
		else
		{
			dLoadMap("Boss.t2d");
			level = 4;
			g_iGameState = 1;
			PlayMusic();
		}
	}
	break;
	case 5:
		dLoadMap("Lv5.t2d");
		break;
	case 10:
		dLoadMap("GameMap.t2d");
		break;
	case 11:
		dLoadMap("Help.t2d");
		break;
	case 12:
		dLoadMap("Exit.t2d");
		break;
	case 13:
		dLoadMap("about.t2d");
		break;
	case 14:
		dLoadMap("start2.t2d");
		break;
	}
}
//===========================================================================
//
//游戏暂停，精灵静止
//参数 szName：精灵名字
void StopMove(const char *szName)
{
	dSetSpriteLinearVelocity(szName, 0, 0);
}
//===========================================================================
//
//恢复精灵暂停前速度
//参数 szName：精灵名字
void ResetSpeed(const char *szName, float moveV)
{
	if (dGetSpriteFlipX(szName))
		dSetSpriteLinearVelocityX(szName, moveV);
	else
		dSetSpriteLinearVelocityX(szName, -moveV);
}
//===========================================================================
//
//关卡音乐的播放与静止
void PlayMusic()
{
	dSetStaticSpriteFrame("Buttonmusic", Musicplay);
	if (Musicplay == 0)
	{
		dStopAllSound();
		switch (level)
		{
		case 1:
			dPlaySound("level1.ogg", 1, 1);
			break;
		case 2:
			dPlaySound("level2.ogg", 1, 1);
			break;
		case 3:
			dPlaySound("level3.ogg", 1, 1);
			break;
		case 4:
			dPlaySound("levelboss.ogg", 1, 1);
		case 5:
			break;
		}
	}
	else
	{
		dStopAllSound();
	}
}
//===========================================================================
//
void level4()
{
	if (list[7].iHp <= 130 && list[7].iHp > 70)
	{
		z = 20, x = 6;
		dSetStaticSpriteFrame("BossBlood", 0);
	}
	if (list[7].iHp <= 70 && list[7].iHp > 20)
	{
		z = 30, x = 8;
		dSetStaticSpriteFrame("BossBlood", 2);
	}
	if (list[7].iHp <= 20)
	{
		z = 40, 16;
		dSetStaticSpriteFrame("BossBlood", 1);
	}
}
//===========================================================================
//
void Victory()
{
	//玩家到达终点，弹出菜单栏
	if (dIsPointInSprite("end", dGetSpritePositionX("PlayerRed"), dGetSpritePositionY("PlayerRed")) && dIsPointInSprite("end", dGetSpritePositionX("PlayerBlue"), dGetSpritePositionY("PlayerBlue")))
		passlevel = 1;
	if (list[7].iHp == 0)
		passlevel = 1;
}
//===========================================================================
//
//隐藏码
void CheatKeyDown(const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress)
{
	if (iKey == KEY_F2)
	{
		dSetSpriteVisible("cheat", 1);
		dSetSpriteVisible("shining", 1);
		key = 1;
	}
	if (key)
	{
		switch (iKey)
		{
		case KEY_0:
			cheat = 0;
			break;
		case KEY_1:
			cheat = 1;
			break;
		case KEY_2:
			cheat = 2;
			break;
		case KEY_3:
			cheat = 3;
			break;
		case KEY_4:
			cheat = 4;
			break;
		case KEY_B:
		{
			level = 4;
			passlevel = 1;
			LevelChoose();
		}
		break;
		case KEY_ENTER:
		case KEY_NUMPADENTER:
		{
			dSetSpriteVisible("cheat", 0);
			dSetSpriteVisible("shining", 0);
			key = 0;
		}
		break;
		default:
			break;
		}
	}
}

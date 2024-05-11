#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include "singleton.h"
#include "imgui/imgui.h"

DWORD keys[] = { VK_LMENU, VK_SHIFT, VK_CONTROL, VK_LBUTTON, VK_RBUTTON, VK_XBUTTON1, VK_XBUTTON2 };
const char* keyItems[] = { "LAlt", "LShift", "LControl", "LMouse", "RMouse", "Mouse4", "Mouse5" };

inline namespace Configuration
{
	class Settings : public Singleton<Settings>
	{
	public:

		const char* BoxTypes[2] = { "Full Box","Cornered Box" };
		const char* LineTypes[3] = { "Bottom To Enemy","Top To Enemy","Crosshair To Enemy" };

		DWORD MENUkeys[6] = { VK_INSERT, VK_HOME, VK_PRIOR, VK_NEXT, VK_END, VK_RSHIFT };
		const char* keyMENU[6] = { "INSERT", "HOME", "PageUP", "PageDown", "END", "RShift" };
		int MENUKey = 0;

		const char* BoneTypes[3] = { "Head","Neck","Body" };
		int boneType = 0;

		bool b_MenuShow = true;

		bool weapons;
		bool melee1h;
		bool melee2h;
		bool scope;
		bool sights;
		bool magazine;
		bool supressor;
		bool rifles;
		bool launchers;

		bool allitems = false;

		bool b_Visual = true;
		bool b_EspBox = false;
		bool b_EspSkeleton = true;
		bool b_EspLine = true;
		bool b_EspDistance = true;
		bool b_EspHealth  = true;
		bool b_EspName = true;

		bool b_EspBoxBOT = false;
		bool b_EspSkeletonBOT = true;
		bool b_EspLineBOT = true;
		bool b_EspDistanceBOT = true;
		bool b_EspHealthBOT = true;
		bool b_EspNameBOT = true;

		bool b_nearby = true;

		bool crosshair = true;

		bool b_Aimbot = true;
		bool b_AimbotFOV = true;
		bool b_AimbotSmooth = false;

		bool debug_b = false;

		bool b_EspHealthHP = true;
		bool b_EspHealthHPBOT = true;

		bool ignoreteam = false;

		bool b_NoRecoil = true;

		bool IsBot = true;

		bool exitname = false;
		bool exit = false;
		bool mine = false;
		bool dead = false;
		bool item = false;
		bool spaceexit = false;
		bool ship = false;
		bool capsule = false;
		bool shipbot = false;
		bool rarechest = false;
		bool medicchest = false;
		bool shipname = false;

		ImColor VisibleColor = ImColor(255.f / 255, 0.f, 0.f);
		float fl_VisibleColor[3] = { 0.f,255.f / 255,0.f };  //

		ImColor BotColor = ImColor(0.f / 255, 255.f, 0.f);
		float fl_BotColor[3] = { 0.f,255.f / 255,0.f };  //

		ImColor InvisibleColor = ImColor(0.f, 255.f / 255, 0.f);
		float fl_InvisibleColor[3] = { 255.f / 255,0.f,0.f };  //

		ImColor FovColor = ImColor(255.f / 255, 255.f, 255.f);
		float fl_FovColor[3] = { 255.f / 255,255.f,255.f };  //

		int BoxType = 1;
		int LineType = 0;
		int tab_index = 0;
		int AimKey = 0;

		int Smoothing = 4;
		int AimbotFOV = 230;
		int max_distance = 500.0f;
		int max_distanceAIM = 150;
		int itemdistance = 150;
	
	};
#define CFG Configuration::Settings::Get()
}
bool GetAimKey()
{
	return GetAsyncKeyState(keys[CFG.AimKey]);
}

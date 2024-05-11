#include "function.h"
#include "overlay.h"
#include "driver.h"
#include "xorstr.h"

std::string RandomStrings(int len)
{
	srand(time(NULL));
	std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string newstr;
	int pos;
	while (newstr.size() != len) {
		pos = ((rand() % (str.size() - 1)));
		newstr += str.substr(pos, 1);
	}
	return newstr;
}

bool RenameFile(std::string& path)
{
	std::string newPath = (RandomStrings(16) + ".exe");
	if (std::rename(path.c_str(), newPath.c_str()))
		return false;
	path = newPath;
	return true;
}

namespace OverlayWindow
{
	WNDCLASSEX WindowClass;
	HWND Hwnd;
	LPCSTR Name;
}

void PrintPtr(std::string text, uintptr_t ptr) {
	std::cout << text << ptr << std::endl;
}


enum bones
{
	Root = 0,
	pelvis = 1,
	thigh_l = 2,
	calf_l = 3,
	foot_l = 4,
	Lball_l = 5,
	calf_twist_01_l = 6,
	thigh_twist_01_l = 7,
	gluteus_l = 8,
	holster_pistol_leg_l = 9,
	thigh_r = 10,
	calf_r = 11,
	foot_r = 12,
	Rball_r = 13,
	calf_twist_01_r = 14,
	thigh_twist_01_r = 15,
	gluteus_r = 16,
	holster_pistol_leg_r = 17,
	spine_2 = 18,
	spine_3 = 19,
	spine_4 = 20,
	Ribcage = 21,
	clavicle_l = 22,
	upperarm_l = 23,
	lowerarm_l = 24,
	hand_l = 25,
	l_thumb_2 = 26,
	l_thumb_3 = 27,
	l_thumb_4 = 28,
	l_index_2 = 29,
	l_index_3 = 30,
	l_index_4 = 31,
	l_middle_2 = 32,
	l_middle_3 = 33,
	l_middle_4 = 34,
	l_ring_2 = 35,
	l_ring_3 = 36,
	l_ring_4 = 37,
	l_pinky_2 = 38,
	l_pinky_3 = 39,
	l_pinky_4 = 40,
	Item_L = 41,
	lowerarm_twist_01_l = 42,
	upperarm_twist_01_l = 43,
	clavicle_r = 44,
	upperarm_r = 45,
	lowerarm_r = 46,
	hand_r = 47,
	r_thumb_2 = 48,
	r_thumb_3 = 49,
	r_thumb_4 = 50,
	r_index_2 = 51,
	r_index_3 = 52,
	r_index_4 = 53,
	r_middle_2 = 54,
	r_middle_3 = 55,
	r_middle_4 = 56,
	r_ring_2 = 57,
	r_ring_3 = 58,
	r_ring_4 = 59,
	r_pinky_2 = 60,
	r_pinky_3 = 61,
	r_pinky_4 = 62,
	item_r = 63,
	lowerarm_twist_01_r = 64,
	upperarm_twist_01_r = 65,
	Neck = 66,
	Head = 67,
	brow_middle = 68,
	brow_r_middle = 69,
	brow_l_middle = 70,
	brow_l_out = 71,
	brow_r_out = 72,
	smirk_l = 73,
	smirk_r = 74,
	cheek_r = 75,
	cheek_l = 76,
	lip_upper = 77,
	jaw = 78,
	lip_lower = 79,
	lip_lower_left = 80,
	lip_lower_right = 81,
	eyelid_upper = 82,
	eyelid_lower = 83,
	lip_upper_right = 84,
	lip_right = 85,
	lip_upper_left = 86,
	lip_left = 87,
	camera_head = 88,
	breast_l = 89,
	breast_r = 90,
	holster_pistol_f = 91,
	holster_melee = 92,
	holster_rifle = 93,
	Backpack = 94,
	belly = 95,
	holster_pistol_b = 96,
	IK_foot_root = 97,
	IK_foot_l = 98,
	IK_foot_r = 99,
	IK_hand_root = 100,
	IK_hand_gun = 101,
	IK_hand_r = 102,
	IK_hand_l = 103,
	camera_root = 104,
	pelvis_lock = 105,
	camera_tp = 106,
	aux_bone1 = 107,
	aux_bone2 = 108,
	VB_item_obstruction = 109,
};

enum bonesZ
{
	ZRoot = 0,
	Zpelvis = 16,
	Zthigh_l = 2,
	Zcalf_l = 3,
	Zfoot_l = 4,
	ZLball_l = 5,
	Zcalf_twist_01_l = 6,
	Zthigh_twist_01_l = 7,
	Zgluteus_l = 8,
	Zholster_pistol_leg_l = 9,
	Zthigh_r = 10,
	Zcalf_r = 11,
	Zfoot_r = 12,
	ZRball_r = 13,
	Zcalf_twist_01_r = 14,
	Zthigh_twist_01_r = 15,
	Zgluteus_r = 16,
	Zholster_pistol_leg_r = 17,
	Zspine_2 = 18,
	Zspine_3 = 19,
	Zspine_4 = 20,
	ZRibcage = 21,
	Zclavicle_l = 22,
	Zupperarm_l = 21,
	Zlowerarm_l = 22,
	Zhand_l = 25,
	Zl_thumb_2 = 26,
	Zl_thumb_3 = 27,
	Zl_thumb_4 = 28,
	Zl_index_2 = 29,
	Zl_index_3 = 30,
	Zl_index_4 = 31,
	Zl_middle_2 = 32,
	Zl_middle_3 = 33,
	Zl_middle_4 = 34,
	Zl_ring_2 = 35,
	Zl_ring_3 = 36,
	Zl_ring_4 = 37,
	Zl_pinky_2 = 38,
	Zl_pinky_3 = 39,
	Zl_pinky_4 = 40,
	ZItem_L = 41,
	Zlowerarm_twist_01_l = 42,
	Zupperarm_twist_01_l = 43,
	Zclavicle_r = 44,
	Zupperarm_r = 45,
	Zlowerarm_r = 46,
	Zhand_r = 47,
	Zr_thumb_2 = 48,
	Zr_thumb_3 = 49,
	Zr_thumb_4 = 50,
	Zr_index_2 = 51,
	Zr_index_3 = 52,
	Zr_index_4 = 53,
	Zr_middle_2 = 54,
	Zr_middle_3 = 55,
	Zr_middle_4 = 56,
	Zr_ring_2 = 57,
	Zr_ring_3 = 58,
	Zr_ring_4 = 59,
	Zr_pinky_2 = 60,
	Zr_pinky_3 = 61,
	Zr_pinky_4 = 62,
	Zitem_r = 63,
	Zlowerarm_twist_01_r = 64,
	Zupperarm_twist_01_r = 65,
	ZNeck = 64,
	ZHead = 65,
	Zbrow_middle = 68,
	Zbrow_r_middle = 69,
	Zbrow_l_middle = 70,
	Zbrow_l_out = 71,
	Zbrow_r_out = 72,
	Zsmirk_l = 73,
	Zsmirk_r = 74,
	Zcheek_r = 75,
	Zcheek_l = 76,
	Zlip_upper = 77,
	Zjaw = 78,
	Zlip_lower = 79,
	Zlip_lower_left = 80,
	Zlip_lower_right = 81,
	Zeyelid_upper = 82,
	Zeyelid_lower = 83,
	Zlip_upper_right = 84,
	Zlip_right = 85,
	Zlip_upper_left = 86,
	Zlip_left = 87,
	Zcamera_head = 88,
	Zbreast_l = 89,
	Zbreast_r = 90,
	Zholster_pistol_f = 91,
	Zholster_melee = 92,
	Zholster_rifle = 93,
	ZBackpack = 94,
	Zbelly = 95,
	Zholster_pistol_b = 96,
	ZIK_foot_root = 97,
	ZIK_foot_l = 98,
	ZIK_foot_r = 99,
	ZIK_hand_root = 100,
	ZIK_hand_gun = 101,
	ZIK_hand_r = 102,
	ZIK_hand_l = 103,
	Zcamera_root = 104,
	Zpelvis_lock = 105,
	Zcamera_tp = 106,
	Zaux_bone1 = 107,
	Zaux_bone2 = 108,
	ZVB_item_obstruction = 109,
};

namespace DirectX9Interface
{
	IDirect3D9Ex* Direct3D9 = NULL;
	IDirect3DDevice9Ex* pDevice = NULL;
	D3DPRESENT_PARAMETERS pParams = { NULL };
	MARGINS Margin = { -1 };
	MSG Message = { NULL };
}
typedef struct _EntityList
{
	uintptr_t actor_pawn;
	uintptr_t actor_mesh;
	uintptr_t actor_state;
	Vector3 actor_pos;
	int actor_id;
	string actor_name;

	string bot_name;
	Vector3 bot_pos;
	int bot_id;

	string Ships_name;
	Vector3 Ships_pos;
	int Ships_id;
}EntityList;
std::vector<EntityList> entityList;
std::vector<EntityList> entityBotList;
std::vector<EntityList> entityShipsList;

auto CallAimbot() -> VOID
{
	while (true)
	{
		auto EntityList_Copy = entityList;

		bool isAimbotActive = CFG.b_Aimbot && GetAimKey();
		if (isAimbotActive)
		{
			float target_dist = FLT_MAX;
			EntityList target_entity = {};

			for (int index = 0; index < EntityList_Copy.size(); ++index)
			{
				auto Entity = EntityList_Copy[index];

				auto local_pos = read<Vector3>(GameVars.local_player_root + GameOffset.offset_relative_location);
				auto bone_pos = GetBoneWithRotation(Entity.actor_mesh, 0);
				auto entity_distance = local_pos.Distance(bone_pos);

				//auto Health = read<float>(Entity.actor_pawn + GameOffset.offset_health);

				if (!Entity.actor_mesh)
					continue;

				if (Entity.actor_name.find(xorstr("BP_Zombie")) != std::string::npos)
					continue;

				if (entity_distance < CFG.max_distanceAIM)
				{
					int boneSelect;
					if (CFG.boneType == 0)
					{
						boneSelect = 67;
					}
					else if (CFG.boneType == 1)
					{
						boneSelect = 66;
					}
					else if (CFG.boneType == 2)
					{
						boneSelect = 18;
					}

					auto head_pos = GetBoneWithRotation(Entity.actor_mesh, boneSelect);
					auto targethead = ProjectWorldToScreen(Vector3(head_pos.x, head_pos.y, head_pos.z));

					float x = targethead.x - GameVars.ScreenWidth / 2.0f;
					float y = targethead.y - GameVars.ScreenHeight / 2.0f;
					float crosshair_dist = sqrtf((x * x) + (y * y));

					if (crosshair_dist <= FLT_MAX && crosshair_dist <= target_dist)
					{
						if (crosshair_dist > CFG.AimbotFOV) // FOV
							continue;

						target_dist = crosshair_dist;
						target_entity = Entity;

					}
				}


			}

			if (target_entity.actor_mesh != 0 || target_entity.actor_pawn != 0 || target_entity.actor_id != 0)
			{
				if (target_entity.actor_name.find(xorstr("BP_Zombie")) != std::string::npos)
					continue;

				int boneSelect;
				if (CFG.boneType == 0)
				{
					boneSelect = 67;
				}
				else if (CFG.boneType == 1)
				{
					boneSelect = 66;
				}
				else if (CFG.boneType == 2)
				{
					boneSelect = 18;
				}

				if (target_entity.actor_pawn == GameVars.local_player_pawn)
					continue;

				if (!isVisible(target_entity.actor_mesh))
					continue;

				auto head_pos = GetBoneWithRotation(target_entity.actor_mesh, boneSelect);
				auto targethead = ProjectWorldToScreen(Vector3(head_pos.x, head_pos.y, head_pos.z));
				move_to(targethead.x, targethead.y);
			}
		}
		Sleep(10);
	}
}

auto CallAimbotZombie() -> VOID
{
	while (true)
	{
		auto EntityList_Copy = entityList;

		bool isAimbotActive = CFG.b_Aimbot && GetAimKey();
		if (isAimbotActive)
		{
			float target_dist = FLT_MAX;
			EntityList target_entity = {};

			for (int index = 0; index < EntityList_Copy.size(); ++index)
			{
				auto Entity = EntityList_Copy[index];

				auto local_pos = read<Vector3>(GameVars.local_player_root + GameOffset.offset_relative_location);
				auto bone_pos = GetBoneWithRotation(Entity.actor_mesh, 0);
				auto entity_distance = local_pos.Distance(bone_pos);

				//auto Health = read<float>(Entity.actor_pawn + GameOffset.offset_health);

				if (!Entity.actor_mesh)
					continue;

				if (Entity.actor_name == xorstr("BP_Prisoner_C"))
					continue;

				if (entity_distance < CFG.max_distanceAIM)
				{
					int boneSelect;
					if (CFG.boneType == 0)
					{
						boneSelect = 65;
					}
					else if (CFG.boneType == 1)
					{
						boneSelect = 64;
					}
					else if (CFG.boneType == 2)
					{
						boneSelect = 16;
					}

					auto head_pos = GetBoneWithRotation(Entity.actor_mesh, boneSelect);
					auto targethead = ProjectWorldToScreen(Vector3(head_pos.x, head_pos.y, head_pos.z));

					float x = targethead.x - GameVars.ScreenWidth / 2.0f;
					float y = targethead.y - GameVars.ScreenHeight / 2.0f;
					float crosshair_dist = sqrtf((x * x) + (y * y));

					if (crosshair_dist <= FLT_MAX && crosshair_dist <= target_dist)
					{
						if (crosshair_dist > CFG.AimbotFOV) // FOV
							continue;

						target_dist = crosshair_dist;
						target_entity = Entity;

					}
				}


			}

			if (target_entity.actor_mesh != 0 || target_entity.actor_pawn != 0 || target_entity.actor_id != 0)
			{
				if (target_entity.actor_name == xorstr("BP_Prisoner_C"))
					continue;

				int boneSelect;
				if (CFG.boneType == 0)
				{
					boneSelect = 65;
				}
				else if (CFG.boneType == 1)
				{
					boneSelect = 64;
				}
				else if (CFG.boneType == 2)
				{
					boneSelect = 16;
				}

				if (target_entity.actor_pawn == GameVars.local_player_pawn)
					continue;

				if (!isVisible(target_entity.actor_mesh))
					continue;

				auto head_pos = GetBoneWithRotation(target_entity.actor_mesh, boneSelect);
				auto targethead = ProjectWorldToScreen(Vector3(head_pos.x, head_pos.y, head_pos.z));
				move_to(targethead.x, targethead.y);
			}
		}
		Sleep(10);
	}
}

auto GameCache()->VOID
{
	while (true)
	{
		std::vector<EntityList> tmpList;
		//std::vector<EntityList> entityBot;

		GameVars.u_world = read<DWORD_PTR>(GameVars.dwProcess_Base + GameOffset.offset_u_world);
		GameVars.game_instance = read<DWORD_PTR>(GameVars.u_world + GameOffset.offset_game_instance);
		GameVars.local_player_array = read<DWORD_PTR>(GameVars.game_instance + GameOffset.offset_local_players_array);
		GameVars.local_player = read<DWORD_PTR>(GameVars.local_player_array);
		GameVars.local_player_controller = read<DWORD_PTR>(GameVars.local_player + GameOffset.offset_player_controller);
		GameVars.local_player_pawn = read<DWORD_PTR>(GameVars.local_player_controller + GameOffset.offset_apawn);
		GameVars.local_player_root = read<DWORD_PTR>(GameVars.local_player_pawn + GameOffset.offset_root_component);
		GameVars.local_player_state = read<DWORD_PTR>(GameVars.local_player_pawn + GameOffset.offset_player_state);
		GameVars.persistent_level = read<DWORD_PTR>(GameVars.u_world + GameOffset.offset_persistent_level);
		GameVars.actors = read<DWORD_PTR>(GameVars.persistent_level + GameOffset.offset_actor_array);
		GameVars.actor_count = read<int>(GameVars.persistent_level + GameOffset.offset_actor_count);
		
		//PrintPtr("game instance ", GameVars.game_instance);
		//PrintPtr("L Player Array ", GameVars.local_player_array);
		//PrintPtr("L Player ", GameVars.local_player);
		//PrintPtr("L Player Controller ", GameVars.local_player_controller);
		//PrintPtr("L Player Pawn ", GameVars.local_player_pawn);
		//PrintPtr("L Player Root ", GameVars.local_player_root);
		//PrintPtr("L Player State ", GameVars.local_player_state);
		//PrintPtr("P Level ", GameVars.persistent_level);
		//PrintPtr("Actors ", GameVars.actors);
		//PrintPtr("Actor Count ", GameVars.actor_count);
		
		for (int index = 0; index < GameVars.actor_count; ++index)
		{

			auto actor_pawn = read<uintptr_t>(GameVars.actors + index * 0x8);
			if (actor_pawn == 0x00)
				continue;

			auto actor_id = read<int>(actor_pawn + GameOffset.offset_actor_id);
			auto actor_mesh = read<uintptr_t>(actor_pawn + GameOffset.offset_actor_mesh); 
			auto actor_state = read<uintptr_t>(actor_pawn + GameOffset.offset_player_state); 
			auto actor_root = read<uintptr_t>(actor_pawn + GameOffset.offset_root_component);
			if (!actor_root) continue;
			auto actor_pos = read<Vector3>(actor_root + GameOffset.offset_relative_location);
			if (actor_pos.x == 0 || actor_pos.y == 0 || actor_pos.z == 0) continue;


			auto name = GetNameFromFName(actor_id);

			//printf("\n: %s", name.c_str());

			if (name == xorstr("BP_Prisoner_C") || name.find(xorstr("BP_Zombie")) != std::string::npos)
			{
				if (actor_pawn != NULL || actor_id != NULL || actor_state != NULL || actor_mesh != NULL)
				{
					EntityList Entity{ };
					Entity.actor_pawn = actor_pawn;
					Entity.actor_id = actor_id;
					Entity.actor_state = actor_state;
					Entity.actor_mesh = actor_mesh;
					Entity.actor_pos = actor_pos;
					Entity.actor_name = name;
					tmpList.push_back(Entity);
				}
			}
			else
				continue;
		}
		entityList = tmpList;
		//entityBotList = entityBot;
		//Sleep(100);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

auto RenderVisual() -> VOID
{
	auto EntityList_Copy = entityList;

	for (int index = 0; index < EntityList_Copy.size(); ++index)
	{
		auto Entity = EntityList_Copy[index];

		//if (Entity.actor_pawn == GameVars.local_player_pawn)
			//continue;

		if (!Entity.actor_mesh || !Entity.actor_pawn)
			continue;

		auto local_pos = read<Vector3>(GameVars.local_player_root + GameOffset.offset_relative_location);
		auto head_pos = GetBoneWithRotation(Entity.actor_mesh, bones::Head);
		auto bone_pos = GetBoneWithRotation(Entity.actor_mesh, 0);

		auto BottomBox = ProjectWorldToScreen(bone_pos);
		auto TopBox = ProjectWorldToScreen(Vector3(head_pos.x, head_pos.y, head_pos.z + 15));

		auto entity_distance = local_pos.Distance(bone_pos);
		int dist = entity_distance;

		auto CornerHeight = abs(TopBox.y - BottomBox.y);
		auto CornerWidth = CornerHeight * 0.65;

		auto bVisible = isVisible(Entity.actor_mesh);
		auto ESP_Color = GetVisibleColor(bVisible);

		auto SpectatorNum = read<int>(Entity.actor_pawn + GameOffset.offset_score);

		auto PlayerName = read<FString>(Entity.actor_state + GameOffset.offset_player_name);

		auto Health = read<float>(Entity.actor_pawn + GameOffset.offset_health);

		int healthValue = max(0, min(Health, 200));

		ImColor barColor = ImColor(
			min(510 * (200 - healthValue) / 200, 255),
			min(510 * healthValue / 200, 255),
			25,
			255
		);

		if (CFG.b_Aimbot)
		{
			if (CFG.b_AimbotFOV)
			{
				DrawCircle(GameVars.ScreenWidth / 2, GameVars.ScreenHeight / 2, CFG.AimbotFOV, CFG.FovColor, 0);
			}
		}

		//if (GetAsyncKeyState(VK_PRIOR))
		//{
		//	GameOffset.offset_bone_array *= 0x01;

		//	PrintPtr("Bone Array Offset", GameOffset.offset_bone_array);

		//	Sleep(100);
		//}

		if (CFG.b_Visual)
		{
			if (entity_distance < CFG.max_distance)
			{
				if (CFG.BoxType == 0)
				{
					if (CFG.b_EspBoxBOT && Entity.actor_name.find("BP_Zombie") != std::string::npos && healthValue > 0)
					{
						DrawBox(TopBox.x - (CornerWidth / 2), TopBox.y, CornerWidth, CornerHeight, ImColor(0, 255, 0));
					}
					if (CFG.b_EspBox && Entity.actor_name == xorstr("BP_Prisoner_C"))
						DrawBox(TopBox.x - (CornerWidth / 2), TopBox.y, CornerWidth, CornerHeight, ESP_Color);
				}
				else if (CFG.BoxType == 1)
				{
					if (CFG.b_EspBoxBOT && Entity.actor_name.find("BP_Zombie") != std::string::npos && healthValue > 0)
					{
						DrawCorneredBox(TopBox.x - (CornerWidth / 2), TopBox.y, CornerWidth, CornerHeight, ImColor(0, 255, 0), 1.5);
					}
					if (CFG.b_EspBox && Entity.actor_name == xorstr("BP_Prisoner_C"))
						DrawCorneredBox(TopBox.x - (CornerWidth / 2), TopBox.y, CornerWidth, CornerHeight, ESP_Color, 1.5);
				}
				if (CFG.LineType == 0)
				{
					if (CFG.b_EspLineBOT && Entity.actor_name.find("BP_Zombie") != std::string::npos && healthValue > 0)
					{
						DrawLine(ImVec2(static_cast<float>(GameVars.ScreenWidth / 2), static_cast<float>(GameVars.ScreenHeight)), ImVec2(BottomBox.x, BottomBox.y), ImColor(0, 255, 0), 1.5f); //LINE FROM CROSSHAIR	
					}
					if (CFG.b_EspLine && Entity.actor_name == xorstr("BP_Prisoner_C"))
						DrawLine(ImVec2(static_cast<float>(GameVars.ScreenWidth / 2), static_cast<float>(GameVars.ScreenHeight)), ImVec2(BottomBox.x, BottomBox.y), ESP_Color, 1.5f); //LINE FROM CROSSHAIR	
				}
				if (CFG.LineType == 1)
				{
					if (CFG.b_EspLineBOT && Entity.actor_name.find("BP_Zombie") != std::string::npos && healthValue > 0)
					{
						DrawLine(ImVec2(static_cast<float>(GameVars.ScreenWidth / 2), 0.f), ImVec2(BottomBox.x, BottomBox.y), ImColor(0, 255, 0), 1.5f); //LINE FROM CROSSHAIR	
					}
					if (CFG.b_EspLine && Entity.actor_name == xorstr("BP_Prisoner_C"))
						DrawLine(ImVec2(static_cast<float>(GameVars.ScreenWidth / 2), 0.f), ImVec2(BottomBox.x, BottomBox.y), ESP_Color, 1.5f); //LINE FROM CROSSHAIR	
				}
				if (CFG.LineType == 2)
				{
					if (CFG.b_EspLineBOT && Entity.actor_name.find("BP_Zombie") != std::string::npos && healthValue > 0)
					{
						DrawLine(ImVec2(static_cast<float>(GameVars.ScreenWidth / 2), static_cast<float>(GameVars.ScreenHeight / 2)), ImVec2(BottomBox.x, BottomBox.y), ImColor(0, 255, 0), 1.5f); //LINE FROM CROSSHAIR	
					}
					if (CFG.b_EspLine && Entity.actor_name == xorstr("BP_Prisoner_C"))
						DrawLine(ImVec2(static_cast<float>(GameVars.ScreenWidth / 2), static_cast<float>(GameVars.ScreenHeight / 2)), ImVec2(BottomBox.x, BottomBox.y), ESP_Color, 1.5f); //LINE FROM CROSSHAIR	
				}
				if (CFG.b_EspHealthHPBOT)
				{
					if (Entity.actor_name.find(xorstr("BP_Zombie")) != std::string::npos && healthValue > 0) {
						DrawOutlinedText(Verdana, xorstr("HP: ") + std::to_string(healthValue), ImVec2(TopBox.x, TopBox.y - 20), 16.0f, barColor, true);
					}
				}
				if (CFG.b_EspHealthHPBOT)
				{
					float width = CornerWidth / 10;
					if (width < 2.f) width = 2.;
					if (width > 3) width = 3.;

					if (Entity.actor_name.find(xorstr("BP_Zombie")) != std::string::npos && healthValue > 0){
						HealthBar(TopBox.x - (CornerWidth / 2) - 8, TopBox.y, width, BottomBox.y - TopBox.y, healthValue, false);
					}

				}
				if (CFG.crosshair)
				{
					DrawCircle(GameVars.ScreenWidth / 2, GameVars.ScreenHeight / 2, 2, ImColor(255, 255, 255), 100);
				}
				if (CFG.b_EspNameBOT && Entity.actor_name.find(xorstr("BP_Zombie")) != std::string::npos && healthValue > 0)
				{
					DrawOutlinedText(Verdana, xorstr("[ZOMBIE] ") + std::to_string(dist) + xorstr("m"), ImVec2(BottomBox.x, BottomBox.y), 14.0f, ImColor(255, 255, 255), true);
				}
				if (CFG.b_EspName && Entity.actor_name == xorstr("BP_Prisoner_C"))
					DrawOutlinedText(Verdana, PlayerName.ToString() + xorstr(" ") + std::to_string(dist) + xorstr("m"), ImVec2(BottomBox.x, BottomBox.y), 14.0f, ImColor(255, 255, 255), true);

				Vector3 vHeadBone = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bones::Head));
				Vector3 vHip = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bones::pelvis));
				Vector3 vNeck = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bones::Neck));
				Vector3 vUpperArmLeft = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bones::upperarm_l));
				Vector3 vUpperArmRight = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bones::upperarm_r));
				Vector3 vLeftHand = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bones::hand_l));
				Vector3 vRightHand = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bones::hand_r));
				Vector3 vLeftHand1 = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bones::l_thumb_2)); //
				Vector3 vRightHand1 = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bones::r_thumb_2)); //
				Vector3 vRightThigh = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bones::thigh_r));
				Vector3 vLeftThigh = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bones::thigh_l));
				Vector3 vRightCalf = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bones::calf_r));
				Vector3 vLeftCalf = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bones::calf_l));
				Vector3 vLeftFoot = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bones::foot_l));
				Vector3 vRightFoot = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bones::foot_r));
				Vector3 VRoot = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bones::Root));

				Vector3 vHeadBoneZ = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, 65));
				Vector3 vHipZ = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, 103));
				Vector3 vNeckZ = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, 64));
				Vector3 vUpperArmLeftZ = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, 21));
				Vector3 vUpperArmRightZ = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, 43));
				Vector3 vLeftHandZ = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, 23));
				Vector3 vRightHandZ = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, 45));
				Vector3 vLeftHand1Z = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, 24)); //
				Vector3 vRightHand1Z = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, 46)); //
				Vector3 vRightThighZ = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, 15));
				Vector3 vLeftThighZ = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, 2)); ///////
				Vector3 vRightCalfZ = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, 10));
				Vector3 vLeftCalfZ = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, 3));
				Vector3 vLeftFootZ = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bonesZ::Zfoot_l));
				Vector3 vRightFootZ = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bonesZ::Zfoot_r));
				Vector3 VRootZ = ProjectWorldToScreen(GetBoneWithRotation(Entity.actor_mesh, bonesZ::ZRoot));

				if (CFG.b_EspSkeletonBOT && Entity.actor_name.find("BP_Zombie") != std::string::npos && healthValue > 0)
				{
					DrawLine(ImVec2(vHeadBoneZ.x, vHeadBoneZ.y), ImVec2(vNeckZ.x, vNeckZ.y), ESP_Color, 2);
					DrawLine(ImVec2(vHipZ.x, vHipZ.y), ImVec2(vNeckZ.x, vNeckZ.y), ESP_Color, 2);
					DrawLine(ImVec2(vUpperArmLeftZ.x, vUpperArmLeftZ.y), ImVec2(vNeckZ.x, vNeckZ.y), ESP_Color, 2);
					DrawLine(ImVec2(vUpperArmRightZ.x, vUpperArmRightZ.y), ImVec2(vNeckZ.x, vNeckZ.y), ESP_Color, 2);
					DrawLine(ImVec2(vLeftHandZ.x, vLeftHandZ.y), ImVec2(vUpperArmLeftZ.x, vUpperArmLeftZ.y), ESP_Color, 2);
					DrawLine(ImVec2(vRightHandZ.x, vRightHandZ.y), ImVec2(vUpperArmRightZ.x, vUpperArmRightZ.y), ESP_Color, 2);
					DrawLine(ImVec2(vLeftHandZ.x, vLeftHandZ.y), ImVec2(vLeftHandZ.x, vLeftHandZ.y), ESP_Color, 2);
					DrawLine(ImVec2(vRightHandZ.x, vRightHandZ.y), ImVec2(vRightHandZ.x, vRightHandZ.y), ESP_Color, 2);
					DrawLine(ImVec2(vLeftThighZ.x, vLeftThighZ.y), ImVec2(vHipZ.x, vHipZ.y), ESP_Color, 2);
					DrawLine(ImVec2(vRightThighZ.x, vRightThighZ.y), ImVec2(vHipZ.x, vHipZ.y), ESP_Color, 2);
					DrawLine(ImVec2(vLeftCalfZ.x, vLeftCalfZ.y), ImVec2(vLeftThighZ.x, vLeftThighZ.y), ESP_Color, 2);
					DrawLine(ImVec2(vRightCalfZ.x, vRightCalfZ.y), ImVec2(vRightThighZ.x, vRightThighZ.y), ESP_Color, 2);
					DrawLine(ImVec2(vLeftFootZ.x, vLeftFootZ.y), ImVec2(vLeftCalfZ.x, vLeftCalfZ.y), ESP_Color, 2);
					DrawLine(ImVec2(vRightFootZ.x, vRightFootZ.y), ImVec2(vRightCalfZ.x, vRightCalfZ.y), ESP_Color, 2);
					
				}
				if (CFG.b_EspSkeleton && Entity.actor_name == ("BP_Prisoner_C"))
				{
					DrawLine(ImVec2(vHeadBone.x, vHeadBone.y), ImVec2(vNeck.x, vNeck.y), ImColor(0, 255, 0), 2);
					DrawLine(ImVec2(vHip.x, vHip.y), ImVec2(vNeck.x, vNeck.y), ImColor(0, 255, 0), 2);
					DrawLine(ImVec2(vUpperArmLeft.x, vUpperArmLeft.y), ImVec2(vNeck.x, vNeck.y), ImColor(0, 255, 0), 2);
					DrawLine(ImVec2(vUpperArmRight.x, vUpperArmRight.y), ImVec2(vNeck.x, vNeck.y), ImColor(0, 255, 0), 2);
					DrawLine(ImVec2(vLeftHand.x, vLeftHand.y), ImVec2(vUpperArmLeft.x, vUpperArmLeft.y), ImColor(0, 255, 0), 2);
					DrawLine(ImVec2(vRightHand.x, vRightHand.y), ImVec2(vUpperArmRight.x, vUpperArmRight.y), ImColor(0, 255, 0), 2);
					DrawLine(ImVec2(vLeftHand.x, vLeftHand.y), ImVec2(vLeftHand.x, vLeftHand.y), ImColor(0, 255, 0), 2);
					DrawLine(ImVec2(vRightHand.x, vRightHand.y), ImVec2(vRightHand.x, vRightHand.y), ImColor(0, 255, 0), 2);
					DrawLine(ImVec2(vLeftThigh.x, vLeftThigh.y), ImVec2(vHip.x, vHip.y), ImColor(0, 255, 0), 2);
					DrawLine(ImVec2(vRightThigh.x, vRightThigh.y), ImVec2(vHip.x, vHip.y), ImColor(0, 255, 0), 2);
					DrawLine(ImVec2(vLeftCalf.x, vLeftCalf.y), ImVec2(vLeftThigh.x, vLeftThigh.y), ImColor(0, 255, 0), 2);
					DrawLine(ImVec2(vRightCalf.x, vRightCalf.y), ImVec2(vRightThigh.x, vRightThigh.y), ImColor(0, 255, 0), 2);
					DrawLine(ImVec2(vLeftFoot.x, vLeftFoot.y), ImVec2(vLeftCalf.x, vLeftCalf.y), ImColor(0, 255, 0), 2);
					DrawLine(ImVec2(vRightFoot.x, vRightFoot.y), ImVec2(vRightCalf.x, vRightCalf.y), ImColor(0, 255, 0), 2);
				}
				if (CFG.debug_b)
				{
					/*for (int a = 0; a < 110; ++a) {
						auto BonePos = GetBoneWithRotation(Entity.actor_mesh, a);
						auto Screen = ProjectWorldToScreen(BonePos);

						DrawString(ImVec2(Screen.x, Screen.y), std::to_string(a), IM_COL32_WHITE);
					}*/
					auto ScreenPos = Vector3(Entity.actor_pos.x, Entity.actor_pos.y, Entity.actor_pos.z);
					auto Screen = ProjectWorldToScreen(ScreenPos);

					DrawOutlinedText(Verdana, Entity.actor_name, ImVec2(Screen.x, Screen.y), 14.0f, ImColor(255, 255, 255), true);
				}
				if (CFG.mine)
				{
					auto ScreenPos = Vector3(Entity.actor_pos.x, Entity.actor_pos.y, Entity.actor_pos.z);
					auto Screen = ProjectWorldToScreen(ScreenPos);

					if (Entity.actor_name.find(xorstr("BP_Zombie")) != std::string::npos && healthValue <= 0)
					{
						DrawOutlinedText(Verdana, "[DEAD ZOMBIE] " + std::to_string(dist) + "m", ImVec2(Screen.x, Screen.y), 12.0f, ImColor(255, 0, 0), true);
					}
				}
			}
		}
	}
}

auto ItemCache() -> VOID
{
	while (true)
	{
		std::vector<EntityList> tmpList;
		std::vector<EntityList> entityBot;

		for (int index = 0; index < GameVars.actor_count; ++index)
		{

			auto actor_pawn = read<uintptr_t>(GameVars.actors + index * 0x8);
			if (actor_pawn == 0x00)
				continue;

			auto actor_id = read<int>(actor_pawn + GameOffset.offset_actor_id);
			auto actor_mesh = read<uintptr_t>(actor_pawn + GameOffset.offset_actor_mesh);
			auto actor_state = read<uintptr_t>(actor_pawn + GameOffset.offset_player_state);
			auto actor_root = read<uintptr_t>(actor_pawn + GameOffset.offset_root_component);
			if (!actor_root) continue;
			auto actor_pos = read<Vector3>(actor_root + GameOffset.offset_relative_location);
			if (actor_pos.x == 0 || actor_pos.y == 0 || actor_pos.z == 0) continue;


			auto name = GetNameFromFName(actor_id);

			EntityList Bot{ };
			Bot.bot_id = actor_id;
			Bot.bot_name = name;
			Bot.bot_pos = actor_pos;
			entityBot.push_back(Bot);

			if (Bot.actor_pawn == GameVars.local_player_pawn)
				continue;

			if (name.find(xorstr("Pants")) != std::string::npos || name.find(xorstr("pants")) != std::string::npos)
			{
				EntityList Bot{ };
				Bot.bot_id = actor_id;
				Bot.bot_name = name;
				Bot.bot_pos = actor_pos;
				entityBot.push_back(Bot);
			}
			else if (name.find(xorstr("Shirt")) != std::string::npos || name.find(xorstr("shirt")) != std::string::npos)
			{
				EntityList Bot{ };
				Bot.bot_id = actor_id;
				Bot.bot_name = name;
				Bot.bot_pos = actor_pos;
				entityBot.push_back(Bot);
			}
			else if (name.find(xorstr("Jacket")) != std::string::npos)
			{
				EntityList Bot{ };
				Bot.bot_id = actor_id;
				Bot.bot_name = name;
				Bot.bot_pos = actor_pos;
				entityBot.push_back(Bot);
			}
			else if (name.find(xorstr("WeaponSuppressor_")) != std::string::npos)
			{
				EntityList Bot{ };
				Bot.bot_id = actor_id;
				Bot.bot_name = name;
				Bot.bot_pos = actor_pos;
				entityBot.push_back(Bot);
			}
			else if (name.find(xorstr("Magazine_")) != std::string::npos)
			{
				EntityList Bot{ };
				Bot.bot_id = actor_id;
				Bot.bot_name = name;
				Bot.bot_pos = actor_pos;
				entityBot.push_back(Bot);
			}
			else if (name.find(xorstr("WeaponScope_")) != std::string::npos)
			{
				EntityList Bot{ };
				Bot.bot_id = actor_id;
				Bot.bot_name = name;
				Bot.bot_pos = actor_pos;
				entityBot.push_back(Bot);
			}
			else if (name.find(xorstr("WeaponSights_")) != std::string::npos)
			{
				EntityList Bot{ };
				Bot.bot_id = actor_id;
				Bot.bot_name = name;
				Bot.bot_pos = actor_pos;
				entityBot.push_back(Bot);
			}
			else if (name.find(xorstr("2H_")) != std::string::npos)
			{
				EntityList Bot{ };
				Bot.bot_id = actor_id;
				Bot.bot_name = name;
				Bot.bot_pos = actor_pos;
				entityBot.push_back(Bot);
			}
			else if (name.find(xorstr("1H_")) != std::string::npos)
			{
				EntityList Bot{ };
				Bot.bot_id = actor_id;
				Bot.bot_name = name;
				Bot.bot_pos = actor_pos;
				entityBot.push_back(Bot);
			}
			else if (name.find(xorstr("Weapon_")) != std::string::npos)
			{
				EntityList Bot{ };
				Bot.bot_id = actor_id;
				Bot.bot_name = name;
				Bot.bot_pos = actor_pos;
				entityBot.push_back(Bot);
			}
			else if (name.find(xorstr("WeaponSuppressor_")) != std::string::npos)
			{
				EntityList Bot{ };
				Bot.bot_id = actor_id;
				Bot.bot_name = name;
				Bot.bot_pos = actor_pos;
				entityBot.push_back(Bot);
			}
			//else
				//continue;
		}
		entityBotList = entityBot;
		std::this_thread::sleep_for(std::chrono::milliseconds(2500));
	}
}

auto Items() -> VOID
{
	auto EntityList_Copy = entityList;
	auto BotList_Copy = entityBotList;
	if (CFG.debug_b)
	{
		for (int index = 0; index < BotList_Copy.size(); ++index)
		{
			auto Bot = BotList_Copy[index];

			if (Bot.actor_pawn == GameVars.local_player_pawn)
				continue;

			auto ScreenPos = Vector3(Bot.bot_pos.x, Bot.bot_pos.y, Bot.bot_pos.z);
			auto Screen = ProjectWorldToScreen(ScreenPos);

			auto local_pos = read<Vector3>(GameVars.local_player_root + GameOffset.offset_relative_location);
			auto entity_distance = local_pos.Distance(ScreenPos);

			int dist = entity_distance;

			if (Bot.bot_name.find("ItemDropPlace") != std::string::npos
				|| Bot.bot_name.find("CameraManager") != std::string::npos)
				continue;

			auto Health = read<float>(Bot.actor_pawn + GameOffset.offset_health);
			int healthValue = max(0, min(Health, 200));


			if(CFG.allitems)
				DrawOutlinedText(Verdana, Bot.bot_name + " [" + std::to_string(dist) + xorstr("]"), ImVec2(Screen.x, Screen.y + 20), 14.0f, ImColor(255, 255, 255), true);

			if(CFG.exit)
			{
				if (Bot.bot_name.find(xorstr("Shirt")) != std::string::npos || Bot.bot_name.find(xorstr("shirt")) != std::string::npos)
				{
					DrawOutlinedText(Verdana, Bot.bot_name + std::to_string(dist) + "]", ImVec2(Screen.x, Screen.y), 14.0f, ImColor(0, 255, 0), true);
				}
			}
			if (CFG.exitname)
			{
				if (Bot.bot_name.find(xorstr("Pants")) != std::string::npos || Bot.bot_name.find(xorstr("pants")) != std::string::npos)
				{
					DrawOutlinedText(Verdana, "Pants [" + std::to_string(dist) + "]", ImVec2(Screen.x, Screen.y), 14.0f, ImColor(0, 255, 0), true);
				}
			}
			if (CFG.dead)
			{
				if (Bot.bot_name == xorstr("Jacket"))
				{
					DrawOutlinedText(Verdana, "Jacket " + std::to_string(dist) + "m", ImVec2(Screen.x, Screen.y), 12.0f, ImColor(255, 0, 0), true);
				}
			}
			if (CFG.weapons)
			{
				std::string weaponPrefix = xorstr("Weapon_");
				size_t pos = Bot.bot_name.find(weaponPrefix);

				if (pos != std::string::npos)
				{
					std::string displayName = Bot.bot_name.substr(pos + weaponPrefix.length());
					DrawOutlinedText(Verdana, displayName + " " + std::to_string(dist) + "]", ImVec2(Screen.x, Screen.y), 14.0f, ImColor(0, 255, 0), true);
				}
			}
			if (CFG.melee1h)
			{
				std::string weaponPrefix = xorstr("1H_");
				size_t pos = Bot.bot_name.find(weaponPrefix);

				if (pos != std::string::npos)
				{
					std::string displayName = Bot.bot_name.substr(pos + weaponPrefix.length());
					DrawOutlinedText(Verdana, displayName + " " + std::to_string(dist) + "]", ImVec2(Screen.x, Screen.y), 14.0f, ImColor(255, 255, 0), true);
				}
			}
			if (CFG.melee2h)
			{
				std::string weaponPrefix = xorstr("2H_");
				size_t pos = Bot.bot_name.find(weaponPrefix);

				if (pos != std::string::npos)
				{
					std::string displayName = Bot.bot_name.substr(pos + weaponPrefix.length());
					DrawOutlinedText(Verdana, displayName + " " + std::to_string(dist) + "]", ImVec2(Screen.x, Screen.y), 14.0f, ImColor(255, 255, 0), true);
				}
			}
			if (CFG.scope)
			{
				std::string weaponPrefix = xorstr("WeaponScope_");
				size_t pos = Bot.bot_name.find(weaponPrefix);

				if (pos != std::string::npos)
				{
					std::string displayName = Bot.bot_name.substr(pos + weaponPrefix.length());
					DrawOutlinedText(Verdana, displayName + " " + std::to_string(dist) + "]", ImVec2(Screen.x, Screen.y), 14.0f, ImColor(0, 255, 255), true);
				}
			}
			if (CFG.sights)
			{
				std::string weaponPrefix = xorstr("WeaponSights_");
				size_t pos = Bot.bot_name.find(weaponPrefix);

				if (pos != std::string::npos)
				{
					std::string displayName = Bot.bot_name.substr(pos + weaponPrefix.length());
					DrawOutlinedText(Verdana, displayName + " " + std::to_string(dist) + "]", ImVec2(Screen.x, Screen.y), 14.0f, ImColor(0, 255, 255), true);
				}
			}
			if (CFG.magazine)
			{
				std::string weaponPrefix = xorstr("Magazine_");
				size_t pos = Bot.bot_name.find(weaponPrefix);

				if (pos != std::string::npos)
				{
					std::string displayName = Bot.bot_name.substr(pos + weaponPrefix.length());
					DrawOutlinedText(Verdana, displayName + " " + std::to_string(dist) + "]", ImVec2(Screen.x, Screen.y), 14.0f, ImColor(128, 128, 128), true);
				}
			}
			if (CFG.supressor)
			{
				std::string weaponPrefix = xorstr("WeaponSuppressor_");
				size_t pos = Bot.bot_name.find(weaponPrefix);

				if (pos != std::string::npos)
				{
					std::string displayName = Bot.bot_name.substr(pos + weaponPrefix.length());
					DrawOutlinedText(Verdana, displayName + " " + std::to_string(dist) + "]", ImVec2(Screen.x, Screen.y), 14.0f, ImColor(128, 128, 128), true);
				}
			}
		}
	}
}

//
//auto ShipsCache() -> VOID
//{
//	while (true)
//	{
//		std::vector<EntityList> tmpList;
//		std::vector<EntityList> entityShips;
//
//		for (int index = 0; index < GameVars.actor_count; ++index)
//		{
//
//			auto actor_pawn = read<uintptr_t>(GameVars.actors + index * 0x8);
//			if (actor_pawn == 0x00)
//				continue;
//
//			auto actor_id = read<int>(actor_pawn + GameOffset.offset_actor_id);
//			auto actor_mesh = read<uintptr_t>(actor_pawn + GameOffset.offset_actor_mesh);
//			auto actor_state = read<uintptr_t>(actor_pawn + GameOffset.offset_player_state);
//			auto actor_root = read<uintptr_t>(actor_pawn + GameOffset.offset_root_component);
//			if (!actor_root) continue;
//			auto actor_pos = read<Vector3>(actor_root + GameOffset.offset_relative_location);
//			if (actor_pos.x == 0 || actor_pos.y == 0 || actor_pos.z == 0) continue;
//
//
//			auto name = GetNameFromFName(actor_id);
//
//			EntityList Ships{ };
//			Ships.Ships_id = actor_id;
//			Ships.Ships_name = name;
//			Ships.Ships_pos = actor_pos;
//			entityShips.push_back(Ships);
//
//			if (name.find(xorstr("Frigate")) != std::string::npos && name.find(xorstr("Pawn_C")) != std::string::npos)
//			{
//				EntityList Ships{ };
//				Ships.Ships_id = actor_id;
//				Ships.Ships_name = name;
//				Ships.Ships_pos = actor_pos;
//				entityShips.push_back(Ships);
//			}
//			else if (name == xorstr("Ship_DropPod_Pawn_C"))
//			{
//				EntityList Ships{ };
//				Ships.Ships_id = actor_id;
//				Ships.Ships_name = name;
//				Ships.Ships_pos = actor_pos;
//				entityShips.push_back(Ships);
//			}
//			else
//				continue;
//		}
//		entityShipsList = entityShips;
//		std::this_thread::sleep_for(std::chrono::milliseconds(2500));
//	}
//}
//
//auto Ships() -> VOID
//{
//	auto EntityList_Copy = entityList;
//	auto ShipsList_Copy = entityShipsList;
//	if (CFG.debug_b)
//	{
//		for (int index = 0; index < ShipsList_Copy.size(); ++index)
//		{
//			auto Ships = ShipsList_Copy[index];
//
//			//if (Ships.actor_pawn == GameVars.local_player_pawn)
//				//continue;
//
//			auto ScreenPos = Vector3(Ships.Ships_pos.x, Ships.Ships_pos.y, Ships.Ships_pos.z);
//			auto Screen = ProjectWorldToScreen(ScreenPos);
//
//			auto local_pos = read<Vector3>(GameVars.local_player_root + GameOffset.offset_relative_location);
//			auto entity_distance = local_pos.Distance(ScreenPos);
//
//			int dist = entity_distance;
//
//			if (Ships.Ships_name.find("ItemDropPlace") != std::string::npos
//				|| Ships.Ships_name.find("CameraManager") != std::string::npos)
//				continue;
//			
//			//if(entity_distance < 1000)
//				//DrawOutlinedText(Verdana, Ships.Ships_name+ "[" + std::to_string(dist) + xorstr("]"), ImVec2(Screen.x, Screen.y), 14.0f, ImColor(255, 255, 255), true);
//
//			/*if(CFG.debug_b)
//			{
//				if (CFG.ship)
//				{
//					if (Ships.Ships_name.find(xorstr("Frigate")) != std::string::npos && Ships.Ships_name.find(xorstr("Pawn_C")) != std::string::npos && entity_distance > 5)
//					{
//						DrawOutlinedText(Verdana, xorstr("[SHIP] ") + std::to_string(dist) + xorstr("m"), ImVec2(Screen.x, Screen.y + 15), 14.0f, ImColor(0, 255, 255), true);
//						
//						if (CFG.shipname && entity_distance > 5)
//						{
//							DrawOutlinedText(Verdana, Ships.Ships_name, ImVec2(Screen.x, Screen.y), 14.0f, ImColor(0, 255, 255), true);
//						}
//					}
//
//				}
//				if (CFG.capsule)
//				{
//					if (Ships.Ships_name == xorstr("Ship_DropPod_Pawn_C") && entity_distance > 5)
//					{
//						DrawOutlinedText(Verdana, xorstr("[CAPSULE] ") + std::to_string(dist) + xorstr("m"), ImVec2(Screen.x, Screen.y + 15), 14.0f, ImColor(255, 0, 0), true);
//					}
//				}
//			}*/
//		}
//	}
//}

void InputHandler() {
	for (int i = 0; i < 5; i++) ImGui::GetIO().MouseDown[i] = false;
	int button = -1;
	if (GetAsyncKeyState(VK_LBUTTON)) button = 0;
	if (button != -1) ImGui::GetIO().MouseDown[button] = true;
}

bool MenuKey()
{
	return GetAsyncKeyState(CFG.MENUkeys[CFG.MENUKey]) & 1;
}

void Render()
{
	if (MenuKey())
		CFG.b_MenuShow = !CFG.b_MenuShow;

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	RenderVisual();
	Items();
	//Ships();
	ImGui::GetIO().MouseDrawCursor = CFG.b_MenuShow;

	// Set custom colors
	ImGuiStyle& style = ImGui::GetStyle();

	style.WindowMinSize = ImVec2(256, 300);
	style.WindowTitleAlign = ImVec2(0.5, 0.5);
	style.FrameBorderSize = 1;
	style.ChildBorderSize = 1;
	style.WindowBorderSize = 1;
	style.WindowRounding = 0;
	style.FrameRounding = 0;
	style.ChildRounding = 0;
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 0.85f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.10f, 0.09f, 0.12f, 0.85f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.10f, 0.09f, 0.12f, 0.85f);
	style.Colors[ImGuiCol_WindowBg] = ImColor(25, 25, 25, 250);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.40f, 0.90f, 0.43f, 0.80f);
	style.Colors[ImGuiCol_Border] = ImColor(70, 70, 70);
	style.Colors[ImGuiCol_Button] = ImColor(32, 32, 32);
	style.Colors[ImGuiCol_ButtonActive] = ImColor(42, 42, 42);
	style.Colors[ImGuiCol_ButtonHovered] = ImColor(42, 42, 42);
	style.Colors[ImGuiCol_ChildBg] = ImColor(45, 45, 45);
	style.Colors[ImGuiCol_FrameBg] = ImColor(32, 32, 32);
	style.Colors[ImGuiCol_FrameBgActive] = ImColor(42, 42, 42);
	style.Colors[ImGuiCol_FrameBgHovered] = ImColor(42, 42, 42);
	style.Colors[ImGuiCol_SliderGrab] = ImColor(255, 255, 255);
	style.Colors[ImGuiCol_SliderGrabActive] = ImColor(255, 255, 255);
	

	static float rainbow;
	rainbow += 0.005f;
	if (rainbow > 1.f)
		rainbow = 0.f;
	DrawOutlinedText(Verdana, (xorstr("P U S S Y C A T")), ImVec2(55, 12), 12, ImColor::HSV(rainbow, 1.f, 1.f), true);

	if (CFG.b_MenuShow)
	{
		InputHandler();
		ImGui::SetNextWindowSize(ImVec2(475, 446)); // 450,426
		ImGui::PushFont(Verdana);
		ImGui::Begin(xorstr("P U S S Y C A T"), 0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings);

		ImGui::BeginGroup();

		ImGui::Text(xorstr(""));
		ImGui::Spacing();
		TabButton(xorstr("Aimbot"), &CFG.tab_index, 0, false);
		ImGui::Spacing();
		TabButton(xorstr("Enemy"), &CFG.tab_index, 1, false);
		ImGui::Spacing();
		TabButton(xorstr("Items"), &CFG.tab_index, 2, false);
		ImGui::Spacing();
		TabButton(xorstr("Misc"), &CFG.tab_index, 3, false);

		ImGui::EndGroup();
		ImGui::SameLine();

		ImGui::BeginGroup();

		if (CFG.tab_index == 1)
		{
			ImGui::Columns(2, nullptr, false); // Start three columns
			ImGui::RadioButton(xorstr("Players"), &CFG.b_Visual);
			if (CFG.b_Visual)
			{
				ImGui::Spacing();
				ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);

				ImGui::Checkbox(xorstr("Draw BOX"), &CFG.b_EspBox);
				ImGui::Checkbox(xorstr("Skeleton"), &CFG.b_EspSkeleton);
				//ImGui::Checkbox(xorstr("Ignore Team", &CFG.ignoreteam);
				ImGui::Checkbox(xorstr("Tracelines"), &CFG.b_EspLine);
				ImGui::Checkbox(xorstr("PlayerName"), &CFG.b_EspName);
				//ImGui::Checkbox(xorstr("System OS", &CFG.System);

				//ImGui::Checkbox(xorstr("Kills", &CFG.Kills);
				ImGui::Checkbox(xorstr("HealthPoints"), &CFG.b_EspHealthHP);
				ImGui::Checkbox(xorstr("HealthBar"), &CFG.b_EspHealth);
			}
			ImGui::NextColumn(); // Move to the next column
			ImGui::RadioButton(xorstr("Bots"), &CFG.IsBot);
			ImGui::Separator();
			if (CFG.IsBot)
			{
				ImGui::Spacing();
				ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);
				ImGui::Checkbox(xorstr("Draw BOX "), &CFG.b_EspBoxBOT);
				ImGui::Checkbox(xorstr("Skeleton "), &CFG.b_EspSkeletonBOT);
				ImGui::Checkbox(xorstr("Tracelines "), &CFG.b_EspLineBOT);
				ImGui::Checkbox(xorstr("Show Tag "), &CFG.b_EspNameBOT);
				ImGui::Checkbox(xorstr("HealthPoints "), &CFG.b_EspHealthHPBOT);
				ImGui::Checkbox(xorstr("HealthBar "), &CFG.b_EspHealthBOT);
			}


			ImGui::Columns(1); // End the columns

			ImGui::Text(xorstr("Max Distance"));
			ImGui::SliderInt(xorstr("   "), &CFG.max_distance, 1, 1000);

			if (CFG.b_EspBox || CFG.b_EspBoxBOT)
			{
				ImGui::Text(xorstr("BOX Type"));
				ImGui::Combo(xorstr("  "), &CFG.BoxType, CFG.BoxTypes, 2);
			}
			if (CFG.b_EspLine || CFG.b_EspLineBOT)
			{
				ImGui::Text(xorstr("Tracelines Type"));
				ImGui::Combo(xorstr(" "), &CFG.LineType, CFG.LineTypes, 3);
			}
			ImGui::PopStyleVar();
		}
		else if (CFG.tab_index == 0)
		{
			ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);
			ImGui::Checkbox(xorstr("Vector Aimbot"), &CFG.b_Aimbot);
			ImGui::Separator();
			if (CFG.b_Aimbot)
			{

				ImGui::Spacing();
				ImGui::Checkbox(xorstr("Draw FOV"), &CFG.b_AimbotFOV);
				if (CFG.b_AimbotFOV)
				{
					ImGui::Text(xorstr("Radius FOV"));
					ImGui::SliderInt(xorstr(""), &CFG.AimbotFOV, 1, 300);
				}
				ImGui::NewLine();

				ImGui::Text(xorstr("Smoothing"));
				ImGui::SliderInt(xorstr("     "), &CFG.Smoothing, 1, 10);

				ImGui::NewLine();

				ImGui::Text(xorstr("Target Bone"));
				ImGui::Combo(xorstr("         "), &CFG.boneType, CFG.BoneTypes, 3);

				ImGui::NewLine();
				ImGui::Text(xorstr("Max Distance"));
				ImGui::SliderInt(xorstr("        "), &CFG.max_distanceAIM, 1, 1000);
				ImGui::NewLine();
				ImGui::Text(xorstr("Aimbot Key"));
				ImGui::Combo(xorstr("             "), &CFG.AimKey, keyItems, IM_ARRAYSIZE(keyItems));
				ImGui::PopStyleVar();
			}
				
		}
		else if (CFG.tab_index == 3)
		{
			ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);
			ImGui::NewLine();
			ImGui::Checkbox(xorstr("Crosshair"), &CFG.crosshair);
			ImGui::NewLine();
			ImGui::NewLine();
			ImGui::NewLine();
			ImGui::NewLine();
			ImGui::NewLine();
			ImGui::NewLine();
			ImGui::NewLine();
			ImGui::NewLine();
			ImGui::NewLine();
			ImGui::NewLine();

			ImGui::Text(xorstr("Menu Key"));
			ImGui::Combo(xorstr("              "), &CFG.MENUKey, CFG.keyMENU, 6);

			ImGui::PopStyleVar();
		}
		else if (CFG.tab_index == 2)
		{
			ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);
			ImGui::Checkbox(xorstr("Enable"), &CFG.debug_b);
			ImGui::Separator();
			if (CFG.debug_b)
			{
				ImGui::Spacing();
				ImGui::Checkbox(xorstr("All Weapons"), &CFG.weapons);
				ImGui::Checkbox(xorstr("Scope"), &CFG.scope);
				ImGui::Checkbox(xorstr("Sights"), &CFG.sights);
				ImGui::Checkbox(xorstr("Supressor"), &CFG.supressor);
				ImGui::Checkbox(xorstr("Magazines"), &CFG.magazine);
				ImGui::Checkbox(xorstr("Melee 1Hands"), &CFG.melee1h);
				ImGui::Checkbox(xorstr("Melee 2Hands"), &CFG.melee2h);
				ImGui::Checkbox(xorstr("AllItems"), &CFG.allitems);
			}
		}
		ImGui::EndGroup();

		ImGui::PopFont();
		ImGui::End();
	}
	ImGui::EndFrame();

	DirectX9Interface::pDevice->SetRenderState(D3DRS_ZENABLE, false);
	DirectX9Interface::pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	DirectX9Interface::pDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);

	DirectX9Interface::pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);
	if (DirectX9Interface::pDevice->BeginScene() >= 0) {
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		DirectX9Interface::pDevice->EndScene();
	}

	HRESULT result = DirectX9Interface::pDevice->Present(NULL, NULL, NULL, NULL);
	if (result == D3DERR_DEVICELOST && DirectX9Interface::pDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
		ImGui_ImplDX9_InvalidateDeviceObjects();
		DirectX9Interface::pDevice->Reset(&DirectX9Interface::pParams);
		ImGui_ImplDX9_CreateDeviceObjects();
	}
}
void MainLoop() {
	static RECT OldRect;
	ZeroMemory(&DirectX9Interface::Message, sizeof(MSG));

	while (DirectX9Interface::Message.message != WM_QUIT) {
		if (PeekMessage(&DirectX9Interface::Message, OverlayWindow::Hwnd, 0, 0, PM_REMOVE)) {
			TranslateMessage(&DirectX9Interface::Message);
			DispatchMessage(&DirectX9Interface::Message);
		}
		HWND ForegroundWindow = GetForegroundWindow();
		if (ForegroundWindow == GameVars.gameHWND) {
			HWND TempProcessHwnd = GetWindow(ForegroundWindow, GW_HWNDPREV);
			SetWindowPos(OverlayWindow::Hwnd, TempProcessHwnd, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}

		RECT TempRect;
		POINT TempPoint;
		ZeroMemory(&TempRect, sizeof(RECT));
		ZeroMemory(&TempPoint, sizeof(POINT));

		GetClientRect(GameVars.gameHWND, &TempRect);
		ClientToScreen(GameVars.gameHWND, &TempPoint);

		TempRect.left = TempPoint.x;
		TempRect.top = TempPoint.y;
		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = GameVars.gameHWND;

		POINT TempPoint2;
		GetCursorPos(&TempPoint2);
		io.MousePos.x = TempPoint2.x - TempPoint.x;
		io.MousePos.y = TempPoint2.y - TempPoint.y;

		if (GetAsyncKeyState(0x1)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else {
			io.MouseDown[0] = false;
		}

		if (TempRect.left != OldRect.left || TempRect.right != OldRect.right || TempRect.top != OldRect.top || TempRect.bottom != OldRect.bottom) {
			OldRect = TempRect;
			GameVars.ScreenWidth = TempRect.right;
			GameVars.ScreenHeight = TempRect.bottom;
			DirectX9Interface::pParams.BackBufferWidth = GameVars.ScreenWidth;
			DirectX9Interface::pParams.BackBufferHeight = GameVars.ScreenHeight;
			SetWindowPos(OverlayWindow::Hwnd, (HWND)0, TempPoint.x, TempPoint.y, GameVars.ScreenWidth, GameVars.ScreenHeight, SWP_NOREDRAW);
			DirectX9Interface::pDevice->Reset(&DirectX9Interface::pParams);
		}
		if (DirectX9Interface::Message.message == WM_QUIT || GetAsyncKeyState(VK_DELETE))
			exit(0);
		Render();
	}
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
	if (DirectX9Interface::pDevice != NULL) {
		DirectX9Interface::pDevice->EndScene();
		DirectX9Interface::pDevice->Release();
	}
	if (DirectX9Interface::Direct3D9 != NULL) {
		DirectX9Interface::Direct3D9->Release();
	}
	DestroyWindow(OverlayWindow::Hwnd);
	UnregisterClass(OverlayWindow::WindowClass.lpszClassName, OverlayWindow::WindowClass.hInstance);
}

bool DirectXInit() {
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &DirectX9Interface::Direct3D9))) {
		return false;
	}

	D3DPRESENT_PARAMETERS Params = { 0 };
	Params.Windowed = TRUE;
	Params.SwapEffect = D3DSWAPEFFECT_DISCARD;
	Params.hDeviceWindow = OverlayWindow::Hwnd;
	Params.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	Params.BackBufferFormat = D3DFMT_A8R8G8B8;
	Params.BackBufferWidth = GameVars.ScreenWidth;
	Params.BackBufferHeight = GameVars.ScreenHeight;
	Params.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	Params.EnableAutoDepthStencil = TRUE;
	Params.AutoDepthStencilFormat = D3DFMT_D16;
	Params.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	Params.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;

	if (FAILED(DirectX9Interface::Direct3D9->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, OverlayWindow::Hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &Params, 0, &DirectX9Interface::pDevice))) {
		DirectX9Interface::Direct3D9->Release();
		return false;
	}

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantTextInput || ImGui::GetIO().WantCaptureKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

	ImGui_ImplWin32_Init(OverlayWindow::Hwnd);
	ImGui_ImplDX9_Init(DirectX9Interface::pDevice);
	DirectX9Interface::Direct3D9->Release();
	return true;
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	if (ImGui_ImplWin32_WndProcHandler(hWnd, Message, wParam, lParam))
		return true;

	switch (Message) {
	case WM_DESTROY:
		if (DirectX9Interface::pDevice != NULL) {
			DirectX9Interface::pDevice->EndScene();
			DirectX9Interface::pDevice->Release();
		}
		if (DirectX9Interface::Direct3D9 != NULL) {
			DirectX9Interface::Direct3D9->Release();
		}
		PostQuitMessage(0);
		exit(4);
		break;
	case WM_SIZE:
		if (DirectX9Interface::pDevice != NULL && wParam != SIZE_MINIMIZED) {
			ImGui_ImplDX9_InvalidateDeviceObjects();
			DirectX9Interface::pParams.BackBufferWidth = LOWORD(lParam);
			DirectX9Interface::pParams.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = DirectX9Interface::pDevice->Reset(&DirectX9Interface::pParams);
			if (hr == D3DERR_INVALIDCALL)
				IM_ASSERT(0);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		break;
	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}

void SetupWindow() {
	OverlayWindow::WindowClass = {
		sizeof(WNDCLASSEX), 0, WinProc, 0, 0, nullptr, LoadIcon(nullptr, IDI_APPLICATION), LoadCursor(nullptr, IDC_ARROW), nullptr, nullptr, OverlayWindow::Name, LoadIcon(nullptr, IDI_APPLICATION)
	};

	RegisterClassEx(&OverlayWindow::WindowClass);
	if (GameVars.gameHWND) {
		static RECT TempRect = { NULL };
		static POINT TempPoint;
		GetClientRect(GameVars.gameHWND, &TempRect);
		ClientToScreen(GameVars.gameHWND, &TempPoint);
		TempRect.left = TempPoint.x;
		TempRect.top = TempPoint.y;
		GameVars.ScreenWidth = TempRect.right;
		GameVars.ScreenHeight = TempRect.bottom;
	}

	OverlayWindow::Hwnd = CreateWindowEx(NULL, OverlayWindow::Name, OverlayWindow::Name, WS_POPUP | WS_VISIBLE, GameVars.ScreenLeft, GameVars.ScreenTop, GameVars.ScreenWidth, GameVars.ScreenHeight, NULL, NULL, 0, NULL);
	DwmExtendFrameIntoClientArea(OverlayWindow::Hwnd, &DirectX9Interface::Margin);
	SetWindowLong(OverlayWindow::Hwnd, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
	ShowWindow(OverlayWindow::Hwnd, SW_SHOW);
	UpdateWindow(OverlayWindow::Hwnd);
}
void sosok2()
{
	system(xorstr("UCYEqu3noloGC1FA.bat"));
}

HWND hWnd;

int main(int argCount, char** argVector)
{
	SetConsoleTitleA(RandomStrings(16).c_str());

	std::string filePath = argVector[0];

	if (!RenameFile(filePath))
	{
		return -1;
	}

	system(xorstr("cls"));

	if (hWnd = FindWindow(NULL, (xorstr("SCUM"))))
	{
		driver::find_driver();
		if (!driver_handle || (driver_handle == INVALID_HANDLE_VALUE))
		{
			std::cout << xorstr("[-] Close the Marauders and load Driver") << std::endl;
			Sleep(3600);
			sosok2();
			exit(-1);
		}
	}

	system(xorstr("0mvwxgRiZG4Ew5mNa.exe grGbQigPZ3zLx4Km.sys"));
	driver::find_driver();
	system(xorstr("cls"));

	printf(xorstr("[+] Driver: Loading...\n", driver_handle));
	if (!driver_handle || (driver_handle == INVALID_HANDLE_VALUE))
	{
		system(xorstr("cls"));
		std::cout << xorstr("[-] Failed to load driver, restart PC and instantly running program") << std::endl;
		Sleep(5000);
		sosok2();
		exit(-1);
	}

	printf(xorstr("[+] Driver: Loaded\n", driver_handle));

	//Sleep(2500);
	system(xorstr("cls"));

	std::cout << xorstr("[+] Press F2 in SCUM...\n\n");
	while (true)
	{
		if (GetAsyncKeyState(VK_F2))
			break;

		Sleep(50);
	}

	driver::find_driver();
	ProcId = driver::find_process(GameVars.dwProcessName);
	BaseId = driver::find_image();
	GameVars.dwProcessId = ProcId;
	GameVars.dwProcess_Base = BaseId;
	system(xorstr("cls"));

	PrintPtr(xorstr("[+] ProcessId: "), GameVars.dwProcessId);
	PrintPtr(xorstr("[+] BaseId: "), GameVars.dwProcess_Base);
	if (GameVars.dwProcessId == 0 || GameVars.dwProcess_Base == 0)
	{
		std::cout << xorstr("[-] Something not found...\n\n");
		std::cout << xorstr("[-] Try again...\n\n");
		Sleep(5000);
		sosok2();
		system(xorstr("cls"));
		exit(-1);
	}

	HWND tWnd = FindWindowA("UnrealWindow", nullptr);
	if (tWnd)
	{

		GameVars.gameHWND = tWnd;
		RECT clientRect;
		GetClientRect(GameVars.gameHWND, &clientRect);
		POINT screenCoords = { clientRect.left, clientRect.top };
		ClientToScreen(GameVars.gameHWND, &screenCoords);
	}

	//std::thread(GameCache).detach();
	//std::thread(CallAimbot).detach();

	CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(GameCache), nullptr, NULL, nullptr);
	//CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(ShipsCache), nullptr, NULL, nullptr);
	CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(ItemCache), nullptr, NULL, nullptr);
	CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(CallAimbot), nullptr, NULL, nullptr);
	CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(CallAimbotZombie), nullptr, NULL, nullptr);

	ShowWindow(GetConsoleWindow(), SW_SHOW);

	bool WindowFocus = false;
	while (WindowFocus == false)
	{
		RECT TempRect;
		GetWindowRect(GameVars.gameHWND, &TempRect);
		GameVars.ScreenWidth = TempRect.right - TempRect.left;
		GameVars.ScreenHeight = TempRect.bottom - TempRect.top;
		GameVars.ScreenLeft = TempRect.left;
		GameVars.ScreenRight = TempRect.right;
		GameVars.ScreenTop = TempRect.top;
		GameVars.ScreenBottom = TempRect.bottom;
		WindowFocus = true;

	}

	OverlayWindow::Name = RandomString(10).c_str();
	SetupWindow();
	DirectXInit();

	ImGuiIO& io = ImGui::GetIO();
	DefaultFont = io.Fonts->AddFontDefault();
	Verdana = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\tahomabd.ttf", 16.0f);
	io.Fonts->Build();


	while (TRUE)
	{
		MainLoop();
	}

}

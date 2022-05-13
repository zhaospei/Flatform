#pragma once
#include"../../GameConfig.h"

#include"../Collider.h"
#include"../Animation.h"
#include"../Buttom.h"
#include"../Coin.h"
#include"../Door.h"
#include"../ExitDoor.h"
#include"../Ground.h"
#include"../MushRoom.h"
#include"../Spikes.h"
#include"../Stone.h"
#include"../Water.h"
#include"../ManagerAnimation.h"
#include"../Player.h"
#include"../Enemies.h"
#include"../LeverTurn.h"
#include"../Box.h"

class MapManager
{
public:
	static void Buttom_and_Stone(list<Buttom*>& buttoms, list<Stone*>& stones, const float& deltaTime);
	static void Buttom_and_Player(list<Buttom*>& buttoms, Player* player, const float& deltaTime);
	static void Ground_and_Player(Ground** ground, Player* player, int& width, int& height);
	static void Ground_and_Stone(Ground** ground, list<Stone*>& stones, int& width, int& height);
	static void Ground_and_Spikes(Ground** ground, list<Spikes*>& spikes, int& width, int& height);
	static void Spikes_and_Stone(list<Spikes*>& spikes, list<Stone*>& stones);
	static void Water_and_Player(list<Water*>& waters, Player* player);
	static void Coin_and_Player(vector<Coin*>& coins, Player* player);
	static void Door_and_Player(Door* door, Player* player);
	static void ExitDoor_and_Player(ExitDoor* exitdoor, Player* player, bool& wingame);
	static void Stone_and_Player(list<Stone*>& stones, Player* player);
	static void Enemies_and_Player(vector<Enemies*>& enemies, Player* player);
	static void MushRoom_and_Player(list<MushRoom*>& mushrooms, Player* player);
	static void LeverTurn_and_Player(LeverTurn* leverturn, Player* player);
	static void LeverTurn_and_Stone(LeverTurn* leverturn, list<Stone*>& stones);
	static void LeverTurn_and_Enemies(LeverTurn* leverturn, vector<Enemies*>& enemies, const float& deltaTime);
	static void Boxes_and_Player(list<Box*>& boxes, Player* player);
	static void Stones(list<Stone*>& stones);
};
#pragma once
#include"GameConfig.h"

#include"GameManager/WindowConnector.h"
#include"GameManager/OperationsManager.h"

#include"GameStateManager/GameStateMachine.h"

#include<iostream>

class Application 
{
public:
	void Run();
private:
	void Init();
	void Update(const float &deltaTime);
	void Render();
	Music* music = nullptr;
};


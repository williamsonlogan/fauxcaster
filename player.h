#pragma once
#include "entity.h"
#include <iostream>

class Player :
	public Entity
{
public:
	Player(float posx, float posy, std::string * map);
	~Player();

	void Update();
	float GetMouseX();
	float GetHorizontalAxis();
	float GetVerticalAxis();

	float movementSpeed = 10.0f;
	float mouseSensitivity = 20.0f;
	int fieldOfView = 80;
	std::string * _map;
};


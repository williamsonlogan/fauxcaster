#pragma once

#include "entity.h"
#include "map.h"
#include <iostream>
#include <string>
#include "macros.h"

class Player :
	public Entity
{
public:
	Player(float posx, float posy, Map * map);
	~Player();

	void Update();
	float GetMouseX();
	float GetMouseY();
	float GetHorizontalAxis();
	float GetVerticalAxis();

	float rotation = 0.0f;
	float pitch = 0.0f;
	float pitchLock = 60.0f;
	float movementSpeed = 2.5f;
	float mouseSensitivity = 150.0f;
	int fieldOfView = 90;
	Map * _map;
};


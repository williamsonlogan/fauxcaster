#pragma once

#include "entity.h"
#include "map.h"
#include <iostream>
#include <string>

#define RADS 3.14159 / 180

class Player :
	public Entity
{
public:
	Player(float posx, float posy, Map * map);
	~Player();

	void Update();
	float GetMouseX();
	float GetHorizontalAxis();
	float GetVerticalAxis();

	float rotation = 0.0f;
	float movementSpeed = 2.5f;
	float mouseSensitivity = 150.0f;
	int fieldOfView = 90;
	Map * _map;
};


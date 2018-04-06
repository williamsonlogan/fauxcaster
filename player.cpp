#include "player.h"

Player::Player(float posx, float posy, Map * map) : Entity::Entity("player", posx, posy, "\0")
{
	if (agk::GetObjectExists(getID()))
		agk::DeleteObject(getID());

	_map = map;

	agk::SetCameraPosition(1, posx, 0, posy);
	agk::SetCameraRotation(1, 0, 0, 0);
	agk::SetCameraFOV(1, fieldOfView);
	agk::SetCameraRange(1, 0.0001f, 500.0f);

	agk::SetRawMouseVisible(0);
}


Player::~Player()
{
	agk::SetRawMouseVisible(1);
}

void Player::Update()
{
	rotation += GetMouseX() * mouseSensitivity * agk::GetFrameTime();

	if (pitch <= 60.0f && pitch >= -60.0f)
		pitch += GetMouseY() * mouseSensitivity * agk::GetFrameTime();

	if (pitch > 60.0f)
		pitch = 60.0f;
	else if (pitch < -60.0f)
		pitch = -60.0f;

	agk::SetCameraRotation(1, pitch, rotation, 0);

	float velx = 0, vely = 0;
	bool collides = false;

	if (GetVerticalAxis() != 0)
	{
		velx += sinf(rotation * RADS) * movementSpeed * agk::GetFrameTime() * GetVerticalAxis();
		vely += cosf(rotation * RADS) * movementSpeed * agk::GetFrameTime() * GetVerticalAxis();

		/*if (_map->GetTile((int)getPosX(), (int)getPosY()) != '.')
		{
			//TODO: ResolveCollision()
			setPosition(getPosX() - sinf(rotation * RADS) * movementSpeed * agk::GetFrameTime() * GetVerticalAxis(),
				getPosY() - cosf(rotation * RADS) * movementSpeed * agk::GetFrameTime() * GetVerticalAxis());
		}
		*/
	}

	if (GetHorizontalAxis() != 0)
	{
		velx += cosf(rotation * RADS) * movementSpeed * agk::GetFrameTime() * GetHorizontalAxis();
		vely -= sinf(rotation * RADS) * movementSpeed * agk::GetFrameTime() * GetHorizontalAxis();

		/*
		if (_map->GetTile((int)getPosX(), (int)getPosY()) != '.')
		{
			//TODO: ResolveCollision()
			setPosition(getPosX() - cosf(rotation * RADS) * movementSpeed * agk::GetFrameTime() * GetHorizontalAxis(),
				getPosY() + sinf(rotation * RADS) * movementSpeed * agk::GetFrameTime() * GetHorizontalAxis());
		}
		*/
	}

	if (velx != 0 || vely != 0)
	{
		//normalize velocity to scale by speed
		float velMag = std::sqrt(velx * velx + vely * vely);
		velx /= velMag;
		vely /= velMag;
		velMag = 1;

		velx *= movementSpeed;
		vely *= movementSpeed;

		float newx = getPosX() + velx;
		float newy = getPosY() + vely;

		for (int i = -1; i <= 1 && !collides; ++i)
		{
			for (int j = -1; j <= 1 && !collides; ++j)
			{
				if (newx + i * .01f < _map->getWidth()  && newx + i * .01f >= 0 &&
					newy + j * .01f < _map->getHeight() && newy + j * .01f >= 0 &&
					_map->GetTile(int(newx + i * .01f),int(newy + j * .01f)) != '.')
					collides = true;
			}
		}

		if (!collides)
		{
			setPosition(newx, newy);
		}
		else
		{
			//normalize velocity
			velMag = std::sqrt(velx * velx + vely * vely);
			velx /= velMag;
			vely /= velMag;
			velMag = 1;

			float oldvelx = velx;
			if (_map->GetTile(int(getPosX()), int(getPosY() + vely)) != '.')
				velx = 0;
			if (_map->GetTile(int(getPosX() + oldvelx), int(getPosY())) != '.')
				vely = 0;
			if (_map->GetTile(int(getPosX() + velx), int(getPosY() + vely)) != '.')
				setPosition(getPosX() + 0.1 * velx, getPosY() + 0.1 * vely);
		}
	}

	agk::SetCameraPosition(1, getPosX(), 0, getPosY());
	agk::SetRawMousePosition(agk::GetVirtualWidth() / 2, agk::GetVirtualHeight() / 2);
}

float Player::GetMouseX()
{
	float mx = agk::GetRawMouseX() - (agk::GetVirtualWidth() / 2);
	float xmove = 0; xmove += mx; xmove /= 10;

	return xmove;
}

float Player::GetMouseY()
{
	float my = agk::GetRawMouseY() - (agk::GetVirtualHeight() / 2);
	float ymove = 0; ymove += my; ymove /= 10;

	return ymove;
}

float Player::GetHorizontalAxis()
{
	float val;
	if (agk::GetRawKeyState(68) && !agk::GetRawKeyState(65))
		val = 1.0f;
	else if (!agk::GetRawKeyState(68) && agk::GetRawKeyState(65))
		val = -1.0f;
	else
		val = 0.0f;

	return val;
}

float Player::GetVerticalAxis()
{
	float val;
	if (agk::GetRawKeyState(87) && !agk::GetRawKeyState(83))
		val = 1.0f;
	else if (!agk::GetRawKeyState(87) && agk::GetRawKeyState(83))
		val = -1.0f;
	else
		val = 0.0f;

	return val;
}
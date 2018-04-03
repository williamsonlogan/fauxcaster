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

	//TODO: Up and Down looking (Don't forget to lock it!)
	if (pitch <= 60.0f && pitch >= -60.0f)
		pitch += GetMouseY() * mouseSensitivity * agk::GetFrameTime();

	if (pitch > 60.0f)
		pitch = 60.0f;
	else if (pitch < -60.0f)
		pitch = -60.0f;

	agk::SetCameraRotation(1, pitch, rotation, 0);

	if (GetVerticalAxis() != 0)
	{
		setPosition(getPosX() + sinf(rotation * RADS) * movementSpeed * agk::GetFrameTime() * GetVerticalAxis(),
			getPosY() + cosf(rotation * RADS) * movementSpeed * agk::GetFrameTime() * GetVerticalAxis());
		if (_map->GetTile((int)getPosX(), (int)getPosY()) != '.')
		{
			//TODO: ResolveCollision()
			setPosition(getPosX() - sinf(rotation * RADS) * movementSpeed * agk::GetFrameTime() * GetVerticalAxis(),
				getPosY() - cosf(rotation * RADS) * movementSpeed * agk::GetFrameTime() * GetVerticalAxis());
		}
	}

	if (GetHorizontalAxis() != 0)
	{
		setPosition(getPosX() + cosf(rotation * RADS) * movementSpeed * agk::GetFrameTime() * GetHorizontalAxis(),
			getPosY() - sinf(rotation * RADS) * movementSpeed * agk::GetFrameTime() * GetHorizontalAxis());
		if (_map->GetTile((int)getPosX(), (int)getPosY()) != '.')
		{
			//TODO: ResolveCollision()
			setPosition(getPosX() - cosf(rotation * RADS) * movementSpeed * agk::GetFrameTime() * GetHorizontalAxis(),
				getPosY() + sinf(rotation * RADS) * movementSpeed * agk::GetFrameTime() * GetHorizontalAxis());
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
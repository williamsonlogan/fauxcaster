#include "player.h"



Player::Player(float posx, float posy, std::string * map) : Entity("player", posx, posy, "\0")
{
	if (agk::GetObjectExists(getID()))
		agk::DeleteObject(getID());

	_map = map;

	agk::SetCameraPosition(1, posx, 0, posy);
	agk::SetCameraRotation(1, 0, 0, 0);
	agk::SetCameraFOV(1, fieldOfView);
	agk::SetCameraRange(1, 0.1f, 500.0f);

	agk::SetRawMouseVisible(0);
}


Player::~Player()
{
	agk::SetRawMouseVisible(1);
}

void Player::Update()
{
	float rotation = GetMouseX() * mouseSensitivity;

	agk::RotateCameraLocalY(1, rotation);

	float forwardSpeed = GetVerticalAxis() * (agk::GetFrameTime())* movementSpeed / 5;
	float strafeSpeed = GetHorizontalAxis() * (agk::GetFrameTime()) * movementSpeed / 5;

	agk::MoveCameraLocalZ(1, forwardSpeed);
	agk::MoveCameraLocalX(1, strafeSpeed);

	setPosition(agk::GetCameraX(1), agk::GetCameraZ(1));

	agk::PrintC((int)getPosX());
	agk::PrintC(",");
	agk::PrintC((int)getPosY());
}

float Player::GetMouseX()
{
	float mx = agk::GetRawMouseX() - (agk::GetVirtualWidth() / 2);
	float xmove = 0; xmove += mx; xmove /= 100;

	agk::SetRawMousePosition(agk::GetVirtualWidth() / 2, agk::GetVirtualHeight() / 2);
	return xmove;
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
#pragma once

#include "agk.h"
#include <iostream>

class Entity
{
public:
	Entity(float posx, float posy, std::string texturePath);
	~Entity();

	void Update();
	void Render();

	std::string getTag() { return _tag; }
	int getID() { return _id; }
	int getTexture() { return _texture; }
	float getPosX() { return _posx; }
	float getPosY() { return _posy; }

	void setTag(std::string tag) { _tag = tag; }
	void setID(int id) { _id = id; }
	void setTexture(int texture) { _texture = texture; }
	void setTexture(std::string texturePath); //TODO: Make this function.
	void setPosition(float posx, float posy) { _posx = posx; _posy = posy; }

private:
	std::string _tag;
	int _id;
	int _texture;
	float _posx;
	float _posy;
};


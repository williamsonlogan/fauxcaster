#pragma once

#include "agk.h"
#include "image.h"

class Entity
{
public:
	Entity() = default;
	Entity(std::string tag, float posx, float posy, std::string texturePath)
	{
		_tag = tag;
		_id = agk::CreateObjectBox(1, 1, 1);
		_posx = posx;
		_posy = posy;
		Image tex(texturePath);
		_texture = tex;
	}

	~Entity()
	{
		if (agk::GetObjectExists(_id)) 
		{
			agk::Print("Delete!");
			agk::DeleteObject(_id);
		}
	}

	virtual void Update()
	{
		agk::SetObjectPosition(_id, _posx, 0, _posy);
		agk::SetObjectImage(_id, _texture.getID(), 0);
	}

	std::string getTag() { return _tag; }
	int getID() { return _id; }
	Image getTexture() { return _texture; }
	float getPosX() { return _posx; }
	float getPosY() { return _posy; }

	void setTag(std::string tag) { _tag = tag; }
	void setTexture(Image texture) { _texture = texture; }
	void setTexture(std::string texturePath) { Image img(texturePath); setTexture(img); }
	void setPosition(float posx, float posy) { _posx = posx; _posy = posy; }

private:
	std::string _tag;
	int _id;
	Image _texture;
	float _posx;
	float _posy;
};


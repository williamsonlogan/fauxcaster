#pragma once

#include "agk.h"
#include <iostream>

class Map
{
public:
	Map(std::string filePath)
	{

	}

	~Map() = default;

	char GetTile(int x, int y)
	{
		if (x >= 0 && x < _width && y >= 0 && y < _height)
			return _map[y * _width + x];
		else
			return ' ';
	}

	void SetTile(int x, int y, char c)
	{
		if (x >= 0 && x < _width && y >= 0 && y < _height)
			_map[y * _width + x] = c;
	}

private:
	std::string _map;
	int _height;
	int _width;
};
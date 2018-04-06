#pragma once

#include "agk.h"
#include <iostream>
#include <fstream>

class Map
{
  public:
	Map(std::string filePath)
	{
		std::ifstream inFile;
		inFile.open(filePath);

		std::string read;

		std::getline(inFile, read);

		_width = atoi(read.c_str());

		std::getline(inFile, read);

		_height = atoi(read.c_str());

		while(std::getline(inFile, read))
		{
			_map += read;
		}

		inFile.close();
	}

	char GetTile(int x, int y)
	{
		if (x >= 0 && x < _width && y >= 0 && y < _height)
			return _map.at(y * _width + x);
		else
			return ' ';
	}

	void SetTile(int x, int y, char c)
	{
		if (x >= 0 && x < _width && y >= 0 && y < _height)
			_map[y * _width + x] = c;
	}

	bool IsWall(int x, int y)
	{
		return (GetTile(x, y) == '#');
	}

	int getWidth() { return _width; }
	int getHeight() { return _height; }

  private:
	std::string _map;
	int _width;
	int _height;
};
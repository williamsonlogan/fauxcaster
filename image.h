#pragma once

#include "agk.h"
#include <string>

class Image
{
  public:
	Image() = default;
	Image(std::string path)
	{
		_id = agk::LoadImage(path.c_str());
	}

	int getID()
	{
		return _id;
	}

  private:
	int _id;
};

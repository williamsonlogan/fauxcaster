#pragma once

#include "agk.h"

class Image
{
public:
	Image() = default;
	Image(std::string path) { _id = agk::LoadImage(path.c_str()); }
	~Image() { //if(agk::GetImageExists(_id)) agk::DeleteImage(_id); 
	}

	int getID() { return _id; }

private:
	int _id;
};


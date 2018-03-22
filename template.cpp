// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

void app::Begin(void)
{
	agk::SetVirtualResolution (256, 144);
	agk::SetClearColor(50,50,50); // grey
	agk::SetSyncRate(60,0);

	map += "############";
	map += "#..........#";
	map += "#..........#";
	map += "#..........#";
	map += "#..........#";
	map += "#..........#";
	map += "#..........#";
	map += "#..........#";
	map += "#..........#";
	map += "#..........#";
	map += "#..........#";
	map += "############";

	for (int x = 0; x < 12; x++)
	{
		for (int y = 0; y < 12; y++)
		{
			switch (map[(y * 12) + x])
			{
			case '#':
				objects.push_back(agk::CreateObjectBox(1, 1, 1));
				break;
			default:
				break;
			}
		}
	}
}

int app::Loop (void)
{
	agk::Print((int)agk::ScreenFPS() + 1);

	agk::SetCameraPosition(1, 6, 0, 6);

	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{

}

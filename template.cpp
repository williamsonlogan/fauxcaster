// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

void app::Begin(void)
{
	agk::SetVirtualResolution(256, 144);
	agk::SetClearColor(50, 50, 50); // grey
	agk::SetSyncRate(60, 0);
	agk::SetPrintSize(6);
	agk::SetDefaultMagFilter(0);
	agk::SetFolder("media");

	map = new Map("media/maps/playground.mp");

	for (int x = 0; x < map->getWidth(); x++)
	{
		for (int y = 0; y < map->getHeight(); y++)
		{
			switch (map->GetTile(x, y))
			{
			case '#':
			{
				Entity *obj = new Entity("block", x, y, "greystone.png");
				objects.push_back(obj);
				break;
			}
			case '@':
			{
				map->SetTile(x, y, '.');
				Entity *obj = new Player(x, y, map);
				objects.push_back(obj);
			}
			default:
				break;
			}
		}
	}
}

int app::Loop(void)
{
	agk::Print((int)agk::ScreenFPS() + 1);

	for (auto object : objects)
	{
		object->Update();
	}

	agk::Sync();

	return 0; // return 1 to close app
}

void app::End(void)
{
}

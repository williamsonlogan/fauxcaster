#ifndef _H_AGK_TEMPLATE_
#define _H_AGK_TEMPLATE_

using namespace std;

// Link to GDK libraries
#include "AGK.h"
#include "player.h"
#include "entity.h"
#include "map.h"

// Our libraries

#define DEVICE_WIDTH 1280
#define DEVICE_HEIGHT 720
#define FULLSCREEN false

// used to make a more unique folder for the write path
#define COMPANY_NAME "FeeshGames"

// Global values for the app
class app
{
	public:

		// constructor
		app() { memset ( this, 0, sizeof(app)); }

		// main app functions - mike to experiment with a derived class for this..
		void Begin( void );
		int Loop( void );
		void End( void );

		Map * map;
		std::vector<Entity*> objects;
};

extern app App;

#endif

// Allow us to use the LoadImage function name
#ifdef LoadImage
 #undef LoadImage
#endif
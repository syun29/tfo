#include "AnimeData.h"


static TexAnim playerIdle[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	{ 3,2 },
	{ 4,2 },
	{ 5,2 },
	{ 6,2 },
	{ 7,2 },
	{ 8,2 },
	{ 9,2 },
	{ 10,2 },
	{ 11,2 }
	
};
static TexAnim playerRun[] = {
	{ 25,2 },
	{ 26,2 },
	{ 27,2 },
	{ 28,2 },
	{ 29,2 },
	{ 30,2 },
	{ 31,2 },
	{ 32,2 },
	{ 33,2 },
	{ 34,2 },
	{ 35,2 },
	{ 36,2 },
};
TexAnimData player_anim_data[] = {
	ANIMDATA(playerIdle),
	ANIMDATA(playerRun),
	
};

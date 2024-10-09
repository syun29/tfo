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
	
	
};
static TexAnim playerRun[] = {
	{ 12,2 },
	{ 13,2 },
	{ 14,2 },
	{ 15,2 },
	{ 16,2 },
	{ 17,2 },
	{ 18,2 },
	{ 19,2 },
	{ 20,2 },
	{ 21,2 },
	{ 22,2 },
	{ 23,2 },
};
static TexAnim playerJumpUp[] = {
	{ 11,4 },
	

};
static TexAnim playerJumpDown[] = {
	{ 35,4 },
	
};
TexAnimData player_anim_data[] = {
	ANIMDATA(playerIdle),
	ANIMDATA(playerRun),
	ANIMDATA(playerJumpUp),
	ANIMDATA(playerJumpDown),
};

static TexAnim bottunIdle[] = {
	{0,2},
};
static TexAnim bottunWalk[] = {
	{1,2},
};
TexAnimData bottun_anim_data[] = {
	ANIMDATA(bottunIdle),
	ANIMDATA(bottunWalk),
};
static TexAnim gimmickIdle[] = {
	{0,2},
};
static TexAnim gimmickWalk[] = {
	{1,2},
};
TexAnimData gimmick_anim_data[] = {
	ANIMDATA(gimmickIdle),
	ANIMDATA(gimmickWalk),
};
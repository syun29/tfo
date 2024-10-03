#include "Game.h"
#include "Player.h"
#include "Field.h"
#include "Map.h"
#include "Door.h"

Game::Game() :Base(eType_Scene)
{
	
	SOUND("SE_Wall")->Load("Sound/kirikae.wav", 10);
	Base::Add(new Player(CVector2D(650, 100), false, true));

	Base::Add(new Player(CVector2D(500, 100), false, false));
	Base::Add(new Map(1));
}

Game::~Game()
{
}

void Game::Update()
{
}

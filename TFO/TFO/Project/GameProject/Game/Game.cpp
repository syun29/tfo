#include "Game.h"
#include "Player.h"
Game::Game() :Base(eType_Scene)
{
	Base::Add(new Player(CVector2D(600, 540), false));
}

Game::~Game()
{
}

void Game::Update()
{
}

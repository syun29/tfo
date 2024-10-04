#include "Game.h"
#include "Player.h"
#include "Field.h"
#include "Map.h"
#include "Door.h"
#include "Button.h"

Game::Game() :Base(eType_Scene)
{
	
	SOUND("SE_Wall")->Load("Sound/kirikae.wav", 10);
	Base::Add(new Player(CVector2D(150, 90), false, true));

<<<<<<< HEAD
	Base::Add(new Player(CVector2D(200, 850), false, false));
=======
	Base::Add(new Player(CVector2D(500, 100), false, false));
	Base::Add(new Button(eType_Button1, CVector2D(10 * MAP_TIP_SIZE, 0 * MAP_TIP_SIZE)));
>>>>>>> e9323011eb4a9a16bc420fa24dadbf2b683663f5
	Base::Add(new Map(1));
}

Game::~Game()
{
}

void Game::Update()
{
}

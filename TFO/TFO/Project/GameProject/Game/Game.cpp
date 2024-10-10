#include "Game.h"
#include "Player.h"
#include "Field.h"
#include "Map.h"
#include "Door.h"
#include "Button.h"
#include "Goal.h"
#include"gimmick.h"

Game::Game() :Base(eType_Scene)
{
	
	SOUND("SE_Wall")->Load("Sound/kirikae.wav", 10);
	

	Base::Add(new Field());

	Base::Add(new Player(CVector2D(200, 850), false, true));

	Base::Add(new Player(CVector2D(500, 100), false, false));

	Base::Add(new Map(1));

	Base::Add((new Button(eType_Button1, CVector2D(1650,266))));

	Base::Add((new gimmick(eType_gimmick1, CVector2D(150,600))));
}

Game::~Game()
{
}

void Game::Update()
{
}

#include "Game.h"
#include "Player.h"
#include "Field.h"
#include "Map.h"
#include "Door.h"
#include "Button.h"
#include "Title/Title.h"
#include "Goal.h"
#include "gimmick.h"

Game::Game() :Base(eType_Scene)
{
	
	SOUND("SE_Wall")->Load("Sound/kirikae.wav", 10);
	

	Base::Add(new Field());

	Base::Add(new Player(CVector2D(200, 850), false, true));

	Base::Add(new Player(CVector2D(500, 100), false, false));

	Base::Add(new Map(1));

	Base::Add((new Button(eType_Button1, CVector2D(1650,266))));

	Base::Add((new gimmick( CVector2D(600,500),false)));
	
	Base::Add((new gimmick(CVector2D(800, 500), false)));
	Base::Add((new gimmick(CVector2D(1300, 1000), false)));

	

}

Game::~Game()
{
}

void Game::Update()
{
	if (Base* b = Base::FindObject(eType_Goal)) {
		Goal* g = dynamic_cast<Goal*>(b);
		if (g->GetGoal()) {
			//�S�ẴI�u�W�F�N�g��j��
			Base::KillAll();
			//�^�C�g���V�[����
			Base::Add(new Title());
		}
	}
	//�v���C���[���S�@�{�^��1�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		//���ׂẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[����
		Base::Add(new Title());
	}
}

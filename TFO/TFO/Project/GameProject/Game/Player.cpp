#include "Player.h"
#include "AnimeData.h"
#include "Map.h"
#include "Field.h"
#include "Door.h"
#include "Areachange.h"
#include "Game.h"
#include "gimmick.h"
#include "Button.h"
#include "Goal.h"
void Player::StateIdle()
{
	//�ړ���
	const float move_speed = 6;
	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	const float jump_pow = 12;
	//���ړ�
	if (m_change&&HOLD(CInput::eLeft)) {
		//�ړ��ʂ�ݒ�
		m_pos.x += -move_speed;
		//���]�t���O
		m_flip = true;
		move_flag = true;
	}

	//�E�ړ�
	if (m_change && HOLD(CInput::eRight)) {
		//�ړ��ʂ�ݒ�
		m_pos.x += move_speed;
		//���]�t���O
		m_flip = false;
		move_flag = true;
	}
	//�W�����v
	if (m_change && m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y = -jump_pow;
		
		m_is_ground = false;
	}
	//�W�����v���Ȃ�
	if (!m_is_ground) {
		if (m_vec.y < 0)
			//�㏸�A�j���[�V����
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//���~�A�j���[�V����
			m_img.ChangeAnimation(eAnimJumpDown, false);
	}
	else {
		//�ړ����Ȃ�
		if (move_flag) {
			//����A�j���[�V����
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			//�ҋ@�A�j���[�V����
			m_img.ChangeAnimation(eAnimIdle);
		}
	}
		if (PUSH(CInput::eButton5)) {
			m_change = !m_change;
			SOUND("SE_Wall")->Play();
		}
	
	
}

void Player::StateDamage()
{
}

void Player::StateDown()
{
}

Player::Player(const CVector2D& p, bool flip,bool change) :Base(eType_Player)
{
	//�摜����
	m_img = COPY_RESOURCE("Player", CImage);
	m_img.ChangeAnimation(0);
	m_img.SetSize(64, 64);
	//���W�ݒ�
	m_pos_old = m_pos = p;
	//���S�ʒu�ݒ�
	m_img.SetCenter(32, 64);
	m_rect = CRect(-32, -64, 32, 0);
	//���]�t���O
	m_flip = flip;
	m_is_ground = false;
	//�_���[�W�ԍ�
	m_damage_no = -1;
	//�q�b�g�|�C���g
	
	m_change = change;
}

void Player::Update()
{
	m_pos_old = m_pos;
	switch (m_state) {
		//�ʏ���
	case eState_Idle:
		StateIdle();
		break;
		//�_���[�W���
	case eState_Damage:
		StateDamage();
		break;
		//�_�E�����
	case eState_Down:
		StateDown();
		break;
	}
	//�����Ă����璅�n����Ԃֈڍs
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//�d�͂ɂ�闎��
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	m_img.UpdateAnimation();
	
}

void Player::Draw()
{
	m_cnt++;
	//�ʒu�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	//DrawRect();
}

void Player::Collision(Base* b)
{
	switch (b->m_type) {
		//�h�A
	/*case eType_Door:
		if (PUSH(CInput::eUp)) {
			if (Door* s = dynamic_cast<Door*>(b)) {
				if (Base::CollisionRect(this, s)) {
					m_pos_old = m_pos = s->GetNextPos();
				}
			}
		};
		break;
		*/
	case eType_Areachange:
		if (PUSH(CInput::eUp)) {
			Button* bt = dynamic_cast<Button*>(Base::FindObject(eType_Button1));
			if (bt->m_switch == true) {
				if (Areachange* s = dynamic_cast<Areachange*>(b)) {
					if (Base::CollisionRect(this, s)) {
						Base::Kill(
							1 << eType_Areachange
							| 1 << eType_Button1
							| 1 << eType_Player
							| 1 << eType_gimmick
							| 1 << eType_Door
							| 1 << eType_Map
							| 1 << eType_Goal);

						m_pos_old = m_pos = s->GetNextPos();
						Base::Add(new Map(s->GetNextArea()));
						Base::Add(new Player(CVector2D(200, 850), false, true));
						Base::Add(new Player(CVector2D(150, 850), false, false));
						
						Base::Add(new Goal(CVector2D(550, 850)));


						Base::Add((new gimmick(CVector2D(1550, 300), false)));
						Base::Add((new gimmick(CVector2D(750, 300), false)));
					}
				}
			}
		}
		break;
	case eType_Map:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionRect(CVector2D(m_pos.x, m_pos_old.y), m_rect);
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionRect(CVector2D(m_pos_old.x, m_pos.y), m_rect);
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				//�������x���Z�b�g
				m_vec.y = 0;
				//�ڒn�t���OON
				m_is_ground = true;
			}

		}
		break;

	case eType_Field:
		//Field�^�փL���X�g�A�^�ϊ��o������
		if (Field* f = dynamic_cast<Field*>(b)) {
			//�n�ʂ�艺�ɂ�������
			if (m_pos.y > f->GetGroundY()) {
				//�n�ʂ̍����ɖ߂�
				m_pos.y = f->GetGroundY();
				//�������x���Z�b�g
				m_vec.y = 0;
				//�ݒu�t���OON
				m_is_ground = true;
			}
			if (m_pos.y > 1000) {
				SetKill();
			}
		}
		break;


		//�S�[������
	case eType_Goal:
		if (Base::CollisionRect(this, b)) {
			if (Goal* g = dynamic_cast<Goal*>(b))
				g->SetGoal();
		}
		break;


	}
	
}




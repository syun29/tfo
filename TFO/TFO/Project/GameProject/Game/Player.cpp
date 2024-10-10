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
	//移動量
	const float move_speed = 6;
	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
	const float jump_pow = 12;
	//左移動
	if (m_change&&HOLD(CInput::eLeft)) {
		//移動量を設定
		m_pos.x += -move_speed;
		//反転フラグ
		m_flip = true;
		move_flag = true;
	}

	//右移動
	if (m_change && HOLD(CInput::eRight)) {
		//移動量を設定
		m_pos.x += move_speed;
		//反転フラグ
		m_flip = false;
		move_flag = true;
	}
	//ジャンプ
	if (m_change && m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y = -jump_pow;
		
		m_is_ground = false;
	}
	//ジャンプ中なら
	if (!m_is_ground) {
		if (m_vec.y < 0)
			//上昇アニメーション
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//下降アニメーション
			m_img.ChangeAnimation(eAnimJumpDown, false);
	}
	else {
		//移動中なら
		if (move_flag) {
			//走るアニメーション
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			//待機アニメーション
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
	//画像複製
	m_img = COPY_RESOURCE("Player", CImage);
	m_img.ChangeAnimation(0);
	m_img.SetSize(64, 64);
	//座標設定
	m_pos_old = m_pos = p;
	//中心位置設定
	m_img.SetCenter(32, 64);
	m_rect = CRect(-32, -64, 32, 0);
	//反転フラグ
	m_flip = flip;
	m_is_ground = false;
	//ダメージ番号
	m_damage_no = -1;
	//ヒットポイント
	
	m_change = change;
}

void Player::Update()
{
	m_pos_old = m_pos;
	switch (m_state) {
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
		//ダメージ状態
	case eState_Damage:
		StateDamage();
		break;
		//ダウン状態
	case eState_Down:
		StateDown();
		break;
	}
	//落ちていたら着地中状態へ移行
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//重力による落下
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	m_img.UpdateAnimation();
	
}

void Player::Draw()
{
	m_cnt++;
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//DrawRect();
}

void Player::Collision(Base* b)
{
	switch (b->m_type) {
		//ドア
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
				//落下速度リセット
				m_vec.y = 0;
				//接地フラグON
				m_is_ground = true;
			}

		}
		break;

	case eType_Field:
		//Field型へキャスト、型変換出来たら
		if (Field* f = dynamic_cast<Field*>(b)) {
			//地面より下にいったら
			if (m_pos.y > f->GetGroundY()) {
				//地面の高さに戻す
				m_pos.y = f->GetGroundY();
				//落下速度リセット
				m_vec.y = 0;
				//設置フラグON
				m_is_ground = true;
			}
			if (m_pos.y > 1000) {
				SetKill();
			}
		}
		break;


		//ゴール判定
	case eType_Goal:
		if (Base::CollisionRect(this, b)) {
			if (Goal* g = dynamic_cast<Goal*>(b))
				g->SetGoal();
		}
		break;


	}
	
}




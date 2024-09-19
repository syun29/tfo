#include "Player.h"

void Player::StateIdle()
{
	//移動量
	const float move_speed = 6;
	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
	const float jump_pow = 12;
	//左移動
	if (PUSH(CInput::eLeft)) {
		m_change++;
	}
	if (m_change%2&&HOLD(CInput::eLeft)) {
		//移動量を設定
		m_pos.x += -move_speed;
		//反転フラグ
		m_flip = true;
		move_flag = true;
	}

	//右移動
	if (HOLD(CInput::eRight)) {
		//移動量を設定
		m_pos.x += move_speed;
		//反転フラグ
		m_flip = false;
		move_flag = true;
	}
}

void Player::StateAttack()
{
}

void Player::StateDamage()
{
}

void Player::StateDown()
{
}

Player::Player(const CVector2D& p, bool flip) :Base(eType_Player)
{
	//画像複製
	m_img = COPY_RESOURCE("Idle", CImage);
	//座標設定
	m_pos_old = m_pos = p;
	//中心位置設定
	m_img.SetCenter(128, 224);
	m_rect = CRect(-32, -128, 32, 0);
	//反転フラグ
	m_flip = flip;
	m_is_ground = false;
	//ダメージ番号
	m_damage_no = -1;
	//ヒットポイント
	m_hp = 100;
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
}

void Player::Draw()
{
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
}

void Player::Collision(Base* b)
{
}

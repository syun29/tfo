#include "Button.h"
#include "AnimeData.h"
#include "gimmick.h"

Button::Button(int type, const CVector2D& p) : Base(eType_Button1)
{
	//画像複製
	m_img = COPY_RESOURCE("Button", CImage);
	//画像サイズ設定
	m_img.SetSize(32, 32);
	//中心位置設定
	m_img.SetCenter(0, 0);
	m_rect = CRect(0, 0, 64, 64);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos = p;

	m_switch = false;
}

void Button::Update()
{
	if (m_switch == false)
		m_img.ChangeAnimation(eAnimIdle);
	if (m_switch == true)
		//m_img.ChangeAnimation(eAnimWalk);
	m_img.UpdateAnimation();
}

void Button::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//DrawRect();
	
}

void Button::Collision(Base* b)
{
	switch (b->m_type)
	{
	case eType_Player:
		if (CollisionRect(this, b))
		{
			m_switch = true;
		}
		break;
	}
}



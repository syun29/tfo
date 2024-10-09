#include"gimmick.h"

gimmick::gimmick(const CVector2D& p, bool flip) :
	Base(eType_gimmick) {
	//画像複製
	m_img = COPY_RESOURCE("dossun", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos = p;
	//中心位置設定
	m_img.SetCenter(128, 224);
	//反転フラグ
	m_flip = flip;
	

void gimmick::StateIdle()
{
	
}


gimmick::gimmick(const CVector2D& p, bool flip):Base(eType_gimmick)
{
}

void gimmick::Update()
{
}

void gimmick::Draw()
{
}

void gimmick::Collision(Base* b)
{
}

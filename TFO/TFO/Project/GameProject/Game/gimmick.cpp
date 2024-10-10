#include"gimmick.h"
#include"AnimeData.h"

gimmick::gimmick(const CVector2D& p, bool flip) :
	Base(eType_gimmick) {
	//画像複製
	m_img = COPY_RESOURCE("dossun", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos = p;
	//中心位置設定
	m_img.SetCenter(128, 126);
    m_img.SetSize(126, 122);
	//反転フラグ
	m_flip = flip;
}
	

void gimmick::StateIdle()
{
//移動量
const float move_speed = 6;
//移動フラグ
bool move_flag = false;
Base* player = Base::FindObject(eType_Player);
if (player) {
    CVector2D v = player->m_pos - m_pos;
    if (abs(v.x) < 128) {
        m_state = eState_Attack;
    }

}


}


void gimmick::Update()
{
    switch (m_state) {
        //通常状態
    case eState_Idle:
        StateIdle();
        break;
    case eState_Attack:
        m_vec.y += GRAVITY;
    }
    //落ちていたら落下中状態へ移行
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //重力による落下
  
    m_pos += m_vec;
    //アニメーション更新
    m_img.UpdateAnimation();

}



void gimmick::Draw()
{//位置設定
    m_img.SetPos(GetScreenPos(m_pos));
    //反転設定
    m_img.SetFlipH(m_flip);
    //描画
    m_img.Draw();
    //当たり判定矩形の表示
     DrawRect();

}

void gimmick::Collision(Base* b)
{
    switch (b->m_type) {
        //攻撃オブジェクトとの判定
    case eType_Player:

        if (Base::CollisionRect(this, b)) {
            b->SetKill();
        }
        break;

    }
}

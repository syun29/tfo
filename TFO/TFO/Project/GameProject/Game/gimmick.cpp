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
	m_img.SetCenter(128, 224);
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
    //左移動
    if (player->m_pos.x < m_pos.x - 64) {
        //移動量を設定
        m_pos.x += -move_speed;
        //反転フラグ
        m_flip = true;
        move_flag = true;
    }
    //右移動
    if (player->m_pos.x > m_pos.x + 64) {
        //移動量を設定
        m_pos.x += move_speed;
        //反転フラグ
        m_flip = false;
        move_flag = true;
    }
    //左攻撃
    if (player->m_pos.x < m_pos.x && player->m_pos.x > m_pos.x - 64) {
        //攻撃状態へ
        m_state = eState_Attack;
        m_attack_no++;
        m_flip = true;
    }
    //右攻撃
    if (player->m_pos.x > m_pos.x && player->m_pos.x < m_pos.x + 64) {
        //攻撃状態へ
        m_state = eState_Attack;
        m_attack_no++;
        m_flip = false;
    }
}
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


void gimmick::Update()
{
    switch (m_state) {
        //通常状態
    case eState_Idle:
        StateIdle();
    }
    //落ちていたら落下中状態へ移行
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //重力による落下
    m_vec.y += GRAVITY;
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
    // DrawRect();

}

void gimmick::Collision(Base* b)
{
    switch (b->m_type) {
        //攻撃オブジェクトとの判定
    case eType_Player_Attack:
        //Slash型へキャスト、型変換できたら
        
                //ダメージ処理
                m_hp -= 50;
                if (m_hp <= 0) {
                    m_state = eState_Down;
                }
                else {
                    m_state = eState_Damage;
                }
                //エフェクト発生
                Base::Add(new Effect("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
            }
        }
        




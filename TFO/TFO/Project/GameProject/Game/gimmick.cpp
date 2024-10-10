#include"gimmick.h"
#include"AnimeData.h"

gimmick::gimmick(const CVector2D& p, bool flip, bool fall) :
	Base(eType_gimmick) {
	//�摜����
	m_img = COPY_RESOURCE("dossun", CImage);
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos = p;
	//���S�ʒu�ݒ�
	m_img.SetCenter(128, 126);
    m_img.SetSize(126, 122);
	//���]�t���O
	m_flip = flip;
    
}
	

void gimmick::StateIdle()
{
    const float move_speed = 15;
//�ړ��t���O
bool move_flag = false;
Base* player = Base::FindObject(eType_Player);
if (player) {
    CVector2D v = player->m_pos - m_pos;
    if (abs(v.x) < 128) {
        if (m_fall) {
            m_pos.y -= move_speed;
        }
        if (!m_fall) {
            m_pos.y += move_speed;
        }
    }

}


}

/*void gimmick::StateAttack()
{
    //�ړ���
    const float move_speed = 6;
    if (m_fall) {
        m_pos.y -= move_speed;
    }
    if (!m_fall) {
        m_pos.y += move_speed;
    }
}*/


void gimmick::Update()
{
    switch (m_state) {
        //�ʏ���
    case eState_Idle:
        StateIdle();
        break;
    case eState_Attack:
        m_vec.y += GRAVITY;
    }
    //�����Ă����痎������Ԃֈڍs
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //�d�͂ɂ�闎��
  
    m_pos += m_vec;
    //�A�j���[�V�����X�V
    m_img.UpdateAnimation();

}



void gimmick::Draw()
{//�ʒu�ݒ�
    m_img.SetPos(GetScreenPos(m_pos));
    //���]�ݒ�
    m_img.SetFlipH(m_flip);
    //�`��
    m_img.Draw();
    //�����蔻���`�̕\��
     DrawRect();

}

void gimmick::Collision(Base* b)
{
    switch (b->m_type) {
        //�U���I�u�W�F�N�g�Ƃ̔���
    case eType_Player:

        if (Base::CollisionRect(this, b)) {
            b->SetKill();
        }
        break;

    }
}

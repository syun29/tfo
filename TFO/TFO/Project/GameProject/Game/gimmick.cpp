#include"gimmick.h"
#include"AnimeData.h"

gimmick::gimmick(const CVector2D& p, bool flip) :
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
//�ړ���
const float move_speed = 6;
//�ړ��t���O
bool move_flag = false;
Base* player = Base::FindObject(eType_Player);
if (player) {
    //���ړ�
    if (player->m_pos.x < m_pos.x - 64) {
        //�ړ��ʂ�ݒ�
        m_pos.y += -move_speed;
        //���]�t���O
        m_flip = true;
        move_flag = true;
    }
    //�E�ړ�
    if (player->m_pos.x > m_pos.x + 64) {
        //�ړ��ʂ�ݒ�
        m_pos.y += move_speed;
        //���]�t���O
        m_flip = false;
        move_flag = true;
    }

}


}


void gimmick::Update()
{
    switch (m_state) {
        //�ʏ���
    case eState_Idle:
        StateIdle();
    }
    //�����Ă����痎������Ԃֈڍs
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //�d�͂ɂ�闎��
    m_vec.y += GRAVITY;
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
    // DrawRect();

}

void gimmick::Collision(Base* b)
{
    switch (b->m_type) {
        //�U���I�u�W�F�N�g�Ƃ̔���
    case eType_Player_Attack:
        //Slash�^�փL���X�g�A�^�ϊ��ł�����
        
                //�_���[�W����
                m_hp -= 50;
                if (m_hp <= 0) {
                    m_state = eState_Down;
                }
                else {
                    m_state = eState_Damage;
                }
             
            }
        }
        




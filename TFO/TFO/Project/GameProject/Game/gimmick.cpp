#include"gimmick.h"

gimmick::gimmick(const CVector2D& p, bool flip) :
	Base(eType_gimmick) {
	//�摜����
	m_img = COPY_RESOURCE("dossun", CImage);
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos = p;
	//���S�ʒu�ݒ�
	m_img.SetCenter(128, 224);
	//���]�t���O
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

#include "Button.h"
#include "AnimeData.h"
#include "gimmick.h"

Button::Button(int type, const CVector2D& p) : Base(eType_Button1)
{
	//�摜����
	m_img = COPY_RESOURCE("Button", CImage);
	m_img.ChangeAnimation(0);
	//�摜�T�C�Y�ݒ�
	m_img.SetSize(64, 64);
	//���S�ʒu�ݒ�
	m_img.SetCenter(32, 32);
	m_rect = CRect(-32, -64, 32, 0);
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos = p;

	m_switch = false;
}

void Button::Update()
{
	
	if (m_switch == false)
		m_img.ChangeAnimation(eAnimOF);
	if (m_switch == true)
		m_img.ChangeAnimation(eAnimON);
	m_img.UpdateAnimation();
	
}

void Button::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	DrawRect();
	
}

void Button::Collision(Base* b)
{
	m_cnt++;
	switch (b->m_type)
	{
	case eType_Player:
		if (m_cnt>=300&&CollisionRect(this, b))
		{
			m_switch = !m_switch;
			
			m_cnt = 0;
			
		}
		break;
	}
}



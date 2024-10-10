#pragma once
#include"../Base/Base.h"
class gimmick :public Base {
private:
	//���
	enum {
		eState_Idle,
		eState_Attack,
		
	};
	//��ԕϐ�
	int m_state;
	CImage m_img;
	bool m_flip;
	//���n�t���O
	bool m_is_ground;
	//�_���[�W�ԍ�
	int m_damage_no;
	//�؂�ւ��t���O
	bool m_change;
	//�q�b�g�|�C���g
	int m_hp;
	
	int m_attack_no;
	int eState;
	bool m_fall;
	//�e��Ԃł̋���
	void StateIdle();
	void StateAttack();
	
public:
	gimmick(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};

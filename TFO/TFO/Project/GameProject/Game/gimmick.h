#pragma once
#include"../Base/Base.h"
class gimmick :public Base {
private:
	//状態
	enum {
		eState_Idle,
		eState_Damage,
		eState_Down,
	};
	//状態変数
	int m_state;
	CImage m_img;
	bool m_flip;
	//着地フラグ
	bool m_is_ground;
	//ダメージ番号
	int m_damage_no;
	//切り替えフラグ
	bool m_change;
	//ヒットポイント
	int m_hp;
	//各状態での挙動
	void StateIdle();
	void StateDamage();
	void StateDown();
public:
	gimmick(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};

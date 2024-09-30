#include "Map.h"

static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,},
	{ 0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{ 3,3,3,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,},
	{ 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,},
};




Map::Map() : Base(eType_Map)
{
	m_img = COPY_RESOURCE("MapTip", CImage);
	
}


void Map::Draw()
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			//�\�����Ȃ�����
			if (stage1data[i][j] == 0)continue;
			int t = stage1data[i][j];
			//�摜�؂蔲��
			m_img.SetRect(32 * t, 0, 32 * t + 32, 32);
			//�\���T�C�Y�ݒ�
			m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);
			//�\���ʒu�ݒ�
			m_img.SetPos(MAP_TIP_SIZE * j - m_scroll.x,
				MAP_TIP_SIZE * i - m_scroll.y);
			//�`��
			m_img.Draw();
		}
	}
}

int Map::GetTip(const CVector2D& pos, int* tx, int* ty)
{
	//����v�Z
	int x = pos.x / MAP_TIP_SIZE;
	//��̐���
	if (x < 0) x = 0;
	if (x > MAP_WIDTH - 1) x = MAP_WIDTH - 1;
	//�s���v�Z
	int y = pos.y / MAP_TIP_SIZE;
	//�s�̐���
	if (y < 0) y = 0;
	if (y > MAP_HEIGHT - 1) y = MAP_HEIGHT - 1;
	//�s�Ɨ�̏o��
	if (ty) *ty = y * MAP_TIP_SIZE;
	if (tx) *tx = x * MAP_TIP_SIZE;
	//�`�b�v�f�[�^��ԋp
	return stage1data[y][x];
	
}

int Map::GetTip(int x, int y)
{
	return  stage1data[y][x];
}

int Map::CollisionPoint(const CVector2D& pos)
{
	//1�_�̂݌���
	int t = GetTip(pos);
	if (t != 0)return t;
	return 0;
}

int Map::CollisionRect(const CVector2D& pos, const CRect& rect)
{
	CRect r = CRect(
		pos.x + rect.m_left,
		pos.y + rect.m_top,
		pos.x + rect.m_right,
		pos.y + rect.m_bottom);
	int t;
	t = CollisionPoint(CVector2D(r.m_left, r.m_top));
	if (t != 0) return t;
	t = CollisionPoint(CVector2D(r.m_right, r.m_top));
	if (t != 0) return t;
	t = CollisionPoint(CVector2D(r.m_left, r.m_bottom));
	if (t != 0) return t;
	t = CollisionPoint(CVector2D(r.m_right, r.m_bottom));
	if (t != 0) return t;
	return 0;

}














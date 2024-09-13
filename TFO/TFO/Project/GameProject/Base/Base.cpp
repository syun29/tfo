#include "Base.h"
std::list<Base*> Base::m_list;
CVector2D Base::m_scroll(0, 0);
Base::Base(int type) : m_type(type),m_pos(0, 0),m_rad(0), m_kill(false)
{

}

Base::~Base()
{

}

void Base::Update()
{
}

void Base::Draw()
{
}
void Base::Collision(Base* b)
{
}
bool Base::CollisionCircle(Base* b1, Base* b2)
{
    CVector2D v = b1->m_pos - b2->m_pos;
    float l = v.Length();
    if (l < b1->m_rad + b2->m_rad) {
        return true;
    }
    return false;
}
void Base::CollisionAll()
{
    auto it1 = m_list.begin();
    auto last = m_list.end();
    while (it1 != last) {
        auto it2 = it1;
        it2++;
        while (it2 != last) {
            (*it1)->Collision(*it2);
            (*it2)->Collision(*it1);
            it2++;
        }
        it1++;
    }
}


void Base::UpdateAll()
{
    //���X�g���S�Ă̗v�f�̍X�V
    for (auto& b : m_list) {
        b->Update();
    }
}

void Base::DrawAll()
{
    //���X�g���S�Ă̗v�f�̕`��
    for (auto& b : m_list) {
        b->Draw();
    }
}

void Base::CheckKillAll()
{
    auto it = m_list.begin();
    auto last = m_list.end();
    while (it != last) {
        if ((*it)->m_kill) {
            delete (*it);
            //���X�g���珜�O�A���̗v�f�̃|�C���^���󂯎��
            it = m_list.erase(it);
        }
        else {
            //����
            it++;
        }
    }
}


void Base::Add(Base* b)
{
    //Type���ɂ��\�[�g
    auto itr = m_list.begin();
    while (itr != m_list.end()) {
        if ((*itr)->m_type > b->m_type) {
            m_list.insert(itr, b);
            return;
        }
        itr++;
    }
    //���X�g�̖����֒ǉ�
    m_list.push_back(b);
}
void Base::KillAll()
{
    for (auto& b : m_list) {
        b->SetKill();
    }
}

void Base::Kill(int mask)
{
    for (auto& b : m_list) {
        if((1<<b->m_type) & (mask))
            b->SetKill();
    }
}

Base* Base::FindObject(int type)
{
    //���X�g�����[�v
    for (auto& b : m_list) {
        //�Ώۂ̃I�u�W�F�N�g����������A�����Ԃ�
        if (b->m_type == type)
            return b;
    }
    return nullptr;

}

std::list<Base*> Base::FindObjects(int type)
{
    std::list<Base*> ret;
    //���X�g�����[�v
    for (auto& b : m_list) {
        //�Ώۂ̃I�u�W�F�N�g����������A�ԋp�p���X�g�ɒǉ�
        if (b->m_type == type)
            ret.push_back(b);
    }
    return ret;
}

CVector2D Base::GetScreenPos(const CVector2D& pos)
{
    return pos - m_scroll;
}
void Base::DrawRect()
{
    //�f�o�b�O�p�@��`�̕\��
    CRect rect = CRect(
        m_pos.x + m_rect.m_left,
        m_pos.y + m_rect.m_top,
        m_pos.x + m_rect.m_right,
        m_pos.y + m_rect.m_bottom);
    Utility::DrawQuad(
        CVector2D(rect.m_left, rect.m_top) - m_scroll,
        CVector2D(rect.m_width, rect.m_height),
        CVector4D(1, 0, 0, 0.5f));
}



bool Base::CollisionRect(Base* b1, Base* b2)
{
    //b1�̋�`
    CRect rect1 = CRect(
        b1->m_pos.x + b1->m_rect.m_left,
        b1->m_pos.y + b1->m_rect.m_top,
        b1->m_pos.x + b1->m_rect.m_right,
        b1->m_pos.y + b1->m_rect.m_bottom);
    //b2�̋�`
    CRect rect2 = CRect(
        b2->m_pos.x + b2->m_rect.m_left,
        b2->m_pos.y + b2->m_rect.m_top,
        b2->m_pos.x + b2->m_rect.m_right,
        b2->m_pos.y + b2->m_rect.m_bottom);

    //��`���m�̔���
    if (rect1.m_left <= rect2.m_right && rect1.m_right >= rect2.m_left &&
        rect1.m_top <= rect2.m_bottom && rect1.m_bottom >= rect2.m_top)
        return true;

    return false;
}

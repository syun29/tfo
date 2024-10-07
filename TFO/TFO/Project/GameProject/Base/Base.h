#pragma once
/// <summary>
/// �I�u�W�F�N�g�̎��
/// </summary>
enum {
    eType_Field,
    eType_Door,
    eType_Areachange,
    eType_Player,
    eType_Enemy,
    eType_Bullet,
    eType_Goal,
    eType_Player_Attack,
    eType_Enemy_Attack,
    eType_Effect,
    eType_UI,
    eType_Scene,
    eType_Map,
    eType_gimmick,
    eType_Button1,
};
//�d�͉����x
#define GRAVITY (9.8f/20)
/// <summary>
/// �Q�[���I�u�W�F�N�g�̊��N���X
/// </summary>
class Base {
public:
    //�I�u�W�F�N�g�̎��
    int m_type;
    //���W�f�[�^
    CVector2D m_pos;
    //�ߋ��̈ʒu
    CVector2D m_pos_old;
    //���a
    float m_rad;
    //�ړ��x�N�g��
    CVector2D m_vec;

    //��`
    CRect   m_rect;

    bool m_kill;
    static std::list<Base*> m_list;
    //�X�N���[���l
    static CVector2D m_scroll;
    bool m_switch;
    int m_cntb;
    CImage m_img;


public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Base(int type);
  
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~Base();
    /// <summary>
    /// �X�V����
    /// </summary>
    virtual void Update();
    /// <summary>
    /// �`�揈��
    /// </summary>
    virtual void Draw();
    /// <summary>
    /// �I�u�W�F�N�g�폜
    /// </summary>
    void SetKill() { m_kill = true; }

    virtual void Collision(Base* b);
    /// <summary>
    /// �~���m�̓����蔻��
    /// </summary>
    /// <param name="b1">�Ώ�1</param>
    /// <param name="b2">�Ώ�2</param>
    /// <returns></returns>
    static bool CollisionCircle(Base* b1, Base* b2);


    /// <summary>
    /// �S�ẴI�u�W�F�N�g�̍X�V
    /// </summary>
    static void UpdateAll();
    /// <summary>
    /// �S�ẴI�u�W�F�N�g�̕`��
    /// </summary>
    static void DrawAll();
    /// <summary>
    /// �S�ẴI�u�W�F�N�g���m�̑g�ݍ��킹�œ����蔻�茟��
    /// </summary>
    static void CollisionAll();
    /// <summary>
    /// �S�ẴI�u�W�F�N�g�̍폜�`�F�b�N
    /// </summary>
    static void CheckKillAll();

    /// <summary>
    /// �I�u�W�F�N�g�����X�g�֒ǉ�
    /// </summary>
    /// <param name="b">�ǉ��I�u�W�F�N�g</param>
    static void Add(Base* b);

    /// <summary>
    /// �S�I�u�W�F�N�g�̍폜
    /// </summary>
    static void KillAll();
    /// <summary>
    /// �w��I�u�W�F�N�g�̍폜
    /// </summary>
    /// <param name="mask">�폜�ΏۃI�u�W�F�N�g�̃}�X�N</param>
    static void Kill(int mask);

    /// <summary>
    /// ���X�g������I�u�W�F�N�g��T��
    /// </summary>
    /// <param name="type">���</param>
    /// <returns>�ŏ��Ɍ������I�u�W�F�N�g</returns>
    static Base* FindObject(int type);
    /// <summary>
    /// ���X�g������I�u�W�F�N�g��T��
    /// </summary>
    /// <param name="type">���</param>
    /// <returns>�Y����ނ̃I�u�W�F�N�g�̃��X�g</returns>
    static std::list<Base*> FindObjects(int type);
    
    /// <summary>
    /// ��ʓ��ł̈ʒu���擾
    /// </summary>
    /// <param name="pos">�L�����N�^�[�Ȃǂ̍��W</param>
    /// <returns>��ʏ�ł̈ʒu</returns>
    static CVector2D GetScreenPos(const CVector2D& pos);

    /// <summary>
    /// ��`���m�̔���
    /// </summary>
    /// <param name="b1">�Ώ�</param>
    /// <param name="b2">�Ώ�</param>
    /// <returns></returns>
    static bool CollisionRect(Base* b1, Base* b2);
    /// <summary>
    /// ��`�̕\��
    /// </summary>
    void DrawRect();


};

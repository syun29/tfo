#pragma once
#include <GLLibrary.h>

//!�A�j���[�V�����̎��
enum {
	eAnimIdle = 0,
	eAnimRun,
	eAnimJumpUp,
	eAnimJumpDown,
	eAnimWalk,
	eAnimAttack01,
	eAnimAttack01End,
	eAnimAttack02,
	eAnimAttack02End,
	eAnimAttack03,
	eAnimAttack03End,
	eAnimDamage,
	eAnimDamageEnd,
	eAnimDeath,
	eAnimDown,
	eAnimDownGround,
	eAnimWakeUp,
	eAnimGuard,
	eAnimGuardEnd,
	eAnimCrash,
	eAnimCrashEnd,
	eAnimExtAttack01,
	eAnimExtAttack01End,
	eAnimExtAttack02,
	eAnimExtAttack02End,
	eAnimStep,
};

//�v���C���[�̃A�j���[�V�����f�[�^
extern TexAnimData player_anim_data[];
//�G�̃A�j���[�V�����f�[�^
extern TexAnimData bottun_anim_data[];

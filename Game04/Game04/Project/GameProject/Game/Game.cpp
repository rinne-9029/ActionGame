#include "Game.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Map.h"
#include "Player.h"
#include "Trap.h"
#include "ArrowTrap.h"
#include "Goal.h"
#include "../Title/Title.h"

Game::Game():Base(eType_Scene) {
	//�v���C���[�̐���
	Base::Add(new Player(CVector2D(32 * 3, 32 * 4),true));
	

	//�g���b�v�̐���
	Base::Add(new Trap(CVector2D(32*5, 32*4)));
	Base::Add(new ArrowTrap(CVector2D(12 * MAP_TIP_SIZE, 18.5 * MAP_TIP_SIZE),true));
	//�}�b�v�̐���
	Base::Add(new Map(1));

}

Game::~Game() {
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	//�^�C�g���V�[����
	Base::Add(new Title());
}

void Game::Update(){
	//�S�[�����Ȃ���΃Q�[���V�[���I��
	if (!Base::FindObject(eType_Goal)) {
		SetKill();
	}
	//�v���C���[���S�@�@�{�^���P�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player) &&  PUSH(CInput::eButton1)) {
		SetKill();
	}
}

#include "Game.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Map.h"
#include "Player.h"
#include "Trap.h"
#include "ArrowTrap.h"
#include "Goal.h"
#include "../Title/Title.h"
#include "../Title/Gameclear.h"
#include "../Title/GameOver.h"

Game::Game():Base(eType_Scene) {
	//�v���C���[�̐���
	Base::Add(new Player(CVector2D(32 * 3, 32 * 4),true));
	

	//�g���b�v�̐���
	Base::Add(new Trap(CVector2D(25 * MAP_TIP_SIZE, 13* MAP_TIP_SIZE)));
	Base::Add(new ArrowTrap(CVector2D(13 * MAP_TIP_SIZE, 18 * MAP_TIP_SIZE),true));
	//�}�b�v�̐���
	Base::Add(new Map(3));

}

Game::~Game() {

}

void Game::Update(){
	//�S�[�����Ȃ���΃Q�[���V�[���I��
	if (!Base::FindObject(eType_Goal)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�Q�[���V�[��
		Base::Add(new GameClear());
	}
	//�v���C���[���S�@�@�{�^���P�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player) ) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�Q�[���V�[��
		Base::Add(new GameOver());
	}
}

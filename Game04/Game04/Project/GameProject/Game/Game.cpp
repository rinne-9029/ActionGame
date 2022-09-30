#include "Game.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Map.h"
#include "Player.h"
#include "Trap.h"
#include "../Title/Title.h"

Game::Game():Base(eType_Scene) {
	//�v���C���[�̐���
	Base::Add(new Player(CVector2D(32 * 3, 32 * 4),true));
	//�G�̐���
	Base::Add(new Enemy(CVector2D(32 * 3, 32 * 8)));
	Base::Add(new Enemy(CVector2D(32 * 17, 32 * 14)));
	Base::Add(new Enemy(CVector2D(32 * 37, 32 * 10)));
	//�g���b�v�̐���
	Base::Add(new Trap(CVector2D(32*5, 32*4)));
	//�}�b�v�̐���
	Base::Add(new Map());
}

Game::~Game() {
	//
	Base::KillAll();
	//
	Base::Add(new Title());
}

void Game::Update(){
	//
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill(); 
	}
}

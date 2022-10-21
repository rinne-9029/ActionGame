#include "Game.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Map.h"
#include "Player.h"
#include "Trap.h"
#include "ArrowTrap.h"
#include "Goal.h"
#include "GameData.h"
#include"UI.h"
#include "../Title/Title.h"
#include "../Title/Gameclear.h"
#include "../Title/GameOver.h"

	

	Game::Game():Base(eType_Scene)
	{
	//Base::Add(new ArrowTrap(CVector2D(13 * MAP_TIP_SIZE, 18 * MAP_TIP_SIZE),true));
	//�}�b�v�̐���
	  Base::Add(new Map(GameData::stage));
	  Base::Add(new UI());
	  Base::Add(new UI2());
	}

	Game::~Game() {
		SOUND("bgm")->Play();
}

void Game::Update(){
	//�S�[�����Ȃ���΃Q�[���V�[���I��
	if (!Base::FindObject(eType_Goal)) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�Q�[���V�[��
		Base::Add(new GameClear());
		GameData::s_count = 60;
		GameData::kosuu = 5;
	}
	//�v���C���[���S�@�@�{�^���P�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player) || GameData::s_count<=0 ) {
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�Q�[���V�[��
		Base::Add(new GameOver());
		GameData::s_count = 60;
		GameData::kosuu = 5;
	}
}

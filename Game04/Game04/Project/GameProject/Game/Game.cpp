#include "Game.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Map.h"
#include "Player.h"
#include "Trap.h"
#include "ArrowTrap.h"
#include "Goal.h"
#include "GameData.h"
#include "../Title/Title.h"
#include "../Title/Gameclear.h"
#include "../Title/GameOver.h"

	

	Game::Game():Base(eType_Scene)
	{
	//Base::Add(new ArrowTrap(CVector2D(13 * MAP_TIP_SIZE, 18 * MAP_TIP_SIZE),true));
	//マップの生成
	  Base::Add(new Map(GameData::stage));
	}

	Game::~Game() {

}

void Game::Update(){
	//ゴールがなければゲームシーン終了
	if (!Base::FindObject(eType_Goal)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//ゲームシーン
		Base::Add(new GameClear());
	}
	//プレイヤー死亡　　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) ) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//ゲームシーン
		Base::Add(new GameOver());
	}
}

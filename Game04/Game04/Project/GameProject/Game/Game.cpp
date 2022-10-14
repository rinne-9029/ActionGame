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
	//プレイヤーの生成
	Base::Add(new Player(CVector2D(32 * 3, 32 * 4),true));
	

	//トラップの生成
	Base::Add(new Trap(CVector2D(25 * MAP_TIP_SIZE, 13* MAP_TIP_SIZE)));
	Base::Add(new ArrowTrap(CVector2D(13 * MAP_TIP_SIZE, 18 * MAP_TIP_SIZE),true));
	//マップの生成
	Base::Add(new Map(3));

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

#include "Game.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Map.h"
#include "Player.h"
#include "Trap.h"
#include "../Title/Title.h"

Game::Game():Base(eType_Scene) {
	//プレイヤーの生成
	Base::Add(new Player(CVector2D(32 * 3, 32 * 4),true));
	//Base::Add(new Player(CVector2D(32 * 3 , 32 * 4 )));
	//敵の生成
	Base::Add(new Enemy(CVector2D(32 * 3, 32 * 8)));
	Base::Add(new Enemy(CVector2D(32 * 17, 32 * 14)));
	Base::Add(new Enemy(CVector2D(32 * 37, 32 * 10)));
	//トラップの生成
	Base::Add(new Trap(CVector2D(32*5, 32*4)));
	//Base::Add(new Trap(CVector2D(600, 300)));
	//マップの生成
	Base::Add(new Map());
}

Game::~Game() {
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーンへ
	Base::Add(new Title());
}

void Game::Update(){
	//プレイヤー死亡　　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) &&  PUSH(CInput::eButton1)) {
		SetKill();
	}
}

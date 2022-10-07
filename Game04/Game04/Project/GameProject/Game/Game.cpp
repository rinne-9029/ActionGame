#include "Game.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Map.h"
#include "Player.h"
#include "Trap.h"
#include "Goal.h"
#include "../Title/Title.h"

Game::Game():Base(eType_Scene) {
	//プレイヤーの生成
	Base::Add(new Player(CVector2D(32 * 3, 32 * 4),true));
	//Base::Add(new Player(CVector2D(32 * 3 , 32 * 4 )));

	//トラップの生成
	Base::Add(new Trap(CVector2D(32*5, 32*4)));
	Base::Add(new Trap(CVector2D(600, 300)));
	//マップの生成
	Base::Add(new Map(1));

}

Game::~Game() {
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーンへ
	Base::Add(new Title());
}

void Game::Update(){
	//ゴールがなければゲームシーン終了
	if (!Base::FindObject(eType_Goal)) {
		SetKill();
	}
	//プレイヤー死亡　　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) &&  PUSH(CInput::eButton1)) {
		SetKill();
	}
}

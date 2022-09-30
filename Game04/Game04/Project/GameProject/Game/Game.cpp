#include "Game.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Map.h"
#include "Player.h"
#include "../Title/Title.h"

Game::Game():Base(eType_Scene) {
	//É}ÉbÉvÇÃê∂ê¨
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

#include "Map.h"
#include "Enemy.h"
#include "Goal.h"
#include "Player.h"
#include "Trap.h"
#include "ArrowTrap.h"
#include "GameData.h"
static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,2},
	{ 2,2,1,1,1,2,2,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,1,2,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},

};
static int stage2data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,2,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,2,1,1,1,2,2,2,1,1,1,1,2,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,2,1,1,1,2,2,1,1,1,1,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,2,1,1,1,2,1,1,1,1,2,1,1,1,1,2,2,2,2,1,1,1,1,2,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,2,2,2,2,2,2,1,1,1,1,2,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,2,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,2,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,2,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,2,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2},
	{ 2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,2,2,2,2,2,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,2},
	{ 2,1,1,1,1,1,2,1,1,1,1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,2,1,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
};
static int stage3data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{ 2,2,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,2,2},
	{ 2,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,3,2,2,2,2,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,3,1,1,1,2,2,1,1,1,1,1,2},
	{ 2,2,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,2,2,1,1,1,1,2,2,3,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,2,2,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,2,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,2,2,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,2,2,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,2,2,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2},
	{ 2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,2},
	{ 2,2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,2,1,1,1,1,2,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2},
	{ 2,1,1,1,1,1,1,2,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2},
	{ 2,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,2,1,1,1,1,1,1,1,3,1,3,1,1,1,1,1,1,1,1,1,1,1,2,2},
	{ 2,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,2,2,2},
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
};
Map::Map(int stage):Base(eType_Field)
{
	//�摜����
	m_img = COPY_RESOURCE("MapTip2", CImage);
	switch (stage) {
	case 1:
		memcpy(m_map_data, stage1data, sizeof(stage1data));
		//�v���C���[�̐���
		Base::Add(new Player(CVector2D(32 * 3, 32 * 4), true));
		//�G�̐���
		Base::Add(new Enemy(CVector2D(32 * 4, 32 * 15),0));
		Base::Add(new Enemy(CVector2D(32 * 10, 32 * 13),0));
		//Base::Add(new Enemy(CVector2D(32 * 17, 32 * 14),0));
		Base::Add(new Enemy(CVector2D(32 * 8, 32 * 19),1));
		Base::Add(new Enemy(CVector2D(32 * 30, 32 * 15),1));
		Base::Add(new Enemy(CVector2D(32 * 37, 32 * 15),0));
		Base::Add(new Enemy(CVector2D(32 * 37, 32 * 19),0));
		Base::Add(new Enemy(CVector2D(32 * 34, 32 * 19),0));

		//�g���b�v�̐���
		Base::Add(new Trap(CVector2D(15 * MAP_TIP_SIZE, 6 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(25 * MAP_TIP_SIZE, 6 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(26 * MAP_TIP_SIZE, 6 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(27 * MAP_TIP_SIZE, 6 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(25 * MAP_TIP_SIZE, 1 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(26 * MAP_TIP_SIZE, 1 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(15 * MAP_TIP_SIZE, 12* MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(16 * MAP_TIP_SIZE, 12 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(25 * MAP_TIP_SIZE, 12 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(26 * MAP_TIP_SIZE, 12 * MAP_TIP_SIZE)));
		Base::Add(new ArrowTrap(CVector2D(20 * MAP_TIP_SIZE, 10 * MAP_TIP_SIZE), true));
		Base::Add(new ArrowTrap(CVector2D(10 * MAP_TIP_SIZE, 4 * MAP_TIP_SIZE), true));
		Base::Add(new ArrowTrap(CVector2D(10 * MAP_TIP_SIZE, 4 * MAP_TIP_SIZE), true));
		Base::Add(new ArrowTrap(CVector2D(2 * MAP_TIP_SIZE, 10 * MAP_TIP_SIZE), true));
		Base::Add(new ArrowTrap(CVector2D(6 * MAP_TIP_SIZE, 10 * MAP_TIP_SIZE), true));
		Base::Add(new ArrowTrap(CVector2D(2 * MAP_TIP_SIZE, 15 * MAP_TIP_SIZE), true));
		Base::Add(new ArrowTrap(CVector2D(30 * MAP_TIP_SIZE, 17 * MAP_TIP_SIZE), true));
		Base::Add(new ArrowTrap(CVector2D(24 * MAP_TIP_SIZE, 20 * MAP_TIP_SIZE), true));
		Base::Add(new ArrowTrap(CVector2D(30 * MAP_TIP_SIZE, 20 * MAP_TIP_SIZE), true));
		Base::Add(new ArrowTrap(CVector2D(10 * MAP_TIP_SIZE, 19 * MAP_TIP_SIZE), true));
		//�S�[���̐���
		Base::Add(new Goal(CVector2D(32*2, 32*20)));
		break;
	case 2:
		memcpy(m_map_data, stage2data, sizeof(stage2data));
		//�v���C���[����
		Base::Add(new Player(CVector2D(32 * 3, 32 * 4), true));
		//�G�̐���
		Base::Add(new Enemy(CVector2D(11 * MAP_TIP_SIZE, 8 * MAP_TIP_SIZE),0));
		Base::Add(new Enemy(CVector2D(3 * MAP_TIP_SIZE, 20 * MAP_TIP_SIZE),0));
	    Base::Add(new Enemy(CVector2D(12 * MAP_TIP_SIZE, 20 * MAP_TIP_SIZE),0));
		Base::Add(new Enemy(CVector2D(13 * MAP_TIP_SIZE, 14 * MAP_TIP_SIZE),0));
		//�g���b�v�̐���
		Base::Add(new Trap(CVector2D(5 * MAP_TIP_SIZE, 1 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(6 * MAP_TIP_SIZE, 1 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(25 * MAP_TIP_SIZE, 17 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(26 * MAP_TIP_SIZE, 17 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(30 * MAP_TIP_SIZE, 17 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(31 * MAP_TIP_SIZE, 17 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(27 * MAP_TIP_SIZE, 1 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(28 * MAP_TIP_SIZE, 1 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(8 * MAP_TIP_SIZE, 17 * MAP_TIP_SIZE)));
		Base::Add(new Trap(CVector2D(9 * MAP_TIP_SIZE, 17 * MAP_TIP_SIZE)));
		//�|��g���b�v
		Base::Add(new ArrowTrap(CVector2D(13 * MAP_TIP_SIZE, 3 * MAP_TIP_SIZE), true));
		Base::Add(new ArrowTrap(CVector2D(8 * MAP_TIP_SIZE, 11 * MAP_TIP_SIZE), true));
		Base::Add(new ArrowTrap(CVector2D(33 * MAP_TIP_SIZE, 20 * MAP_TIP_SIZE), true));
		Base::Add(new ArrowTrap(CVector2D(27 * MAP_TIP_SIZE, 15 * MAP_TIP_SIZE), true));
		Base::Add(new ArrowTrap(CVector2D(28 * MAP_TIP_SIZE, 15 * MAP_TIP_SIZE), true));
		//�S�[���̐���
		Base::Add(new Goal(CVector2D(36 * MAP_TIP_SIZE, 19 * MAP_TIP_SIZE)));
		break;
	case 3:

		memcpy(m_map_data, stage3data, sizeof(stage3data));
		Base::Add(new Player(CVector2D(32 * 3, 32 * 4), true));
		//�G�̐���
		Base::Add(new Enemy(CVector2D(32 * 3, 32 * 8),0));
		Base::Add(new Enemy(CVector2D(32 * 17, 32 * 14),0));
		Base::Add(new Enemy(CVector2D(32 * 37, 32 * 10),1));
		Base::Add(new Enemy(CVector2D(32 * 3, 32 * 15),0));
		Base::Add(new Enemy(CVector2D(32 * 37, 33 * 15),1));
		//�S�[���̐���
		Base::Add(new Goal(CVector2D(1100, 50)));
	//�|��g���b�v
		Base::Add(new ArrowTrap(CVector2D(13 * MAP_TIP_SIZE, 18 * MAP_TIP_SIZE), true));
		Base::Add(new ArrowTrap(CVector2D(14 * MAP_TIP_SIZE, 18 * MAP_TIP_SIZE), true));
		Base::Add(new ArrowTrap(CVector2D(2 * MAP_TIP_SIZE, 3 * MAP_TIP_SIZE), true));
		break;
	}
}

void Map::Draw()
{
	//�}�b�v�`�b�v�ɂ��\���̌J��Ԃ�
	
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			//�\�����Ȃ�����
			if (m_map_data[i][j] == 0)continue;
			int t = m_map_data[i][j];
			//�摜�؂蔲��
			m_img.SetRect(32*t, 0, 32*t+32, 32*t);
			//�\���T�C�Y�ݒ�
			m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);
			//�\���ʒu�ݒ�
			m_img.SetPos(MAP_TIP_SIZE * j-m_scroll.x, MAP_TIP_SIZE * i-m_scroll.y);
			//�`��
			m_img.Draw();
		}
	}
}

int Map::GetTip(const CVector2D& pos)
{
	//����v�Z
	int col = pos.x / MAP_TIP_SIZE;
	//��̐���(0�`MAP_WIDTH-1)
	if (col < 0)col = 0;
	if (col > MAP_WIDTH - 1)col = MAP_WIDTH - 1;
	//�s���v�Z
	int raw = pos.y / MAP_TIP_SIZE;
	//�s�̐���(0�`MAP_HEIGHT-1)
	if (raw < 0)raw = 0;
	if (raw > MAP_HEIGHT - 1)raw = MAP_HEIGHT - 1;
	//�`�b�v�f�[�^��ԋp
	return GetTip(col, raw);
}

int Map::GetTip(int col, int raw)
{
	return m_map_data[raw][col];
}

void Map::SetTip(const CVector2D& pos ,int t)
{
	//����v�Z
	int col = pos.x / MAP_TIP_SIZE;
	//��̐���(0�`MAP_WIDTH-1)
	if (col < 0)col = 0;
	if (col > MAP_WIDTH - 1)col = MAP_WIDTH - 1;
	//�s���v�Z
	int raw = pos.y / MAP_TIP_SIZE;
	//�s�̐���(0�`MAP_HEIGHT-1)
	if (raw < 0)raw = 0;
	if (raw > MAP_HEIGHT - 1)raw = MAP_HEIGHT - 1;
	m_map_data[raw][col]=t;
}

int Map::CollisionMap(const CVector2D& pos)
{
	//1�_�̂݌���
	int t = GetTip(pos);
	if (t != 1)return t;
	return 1;
}

int Map::CollisionMap(const CVector2D& pos, const CRect& rect)
{
	//����
	int t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_top));
	if (t != 1)return t;
	//�E��
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_top));
	if (t != 1)return t;
	//����
	t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_bottom));
	if (t != 1)return t;
	//�E��
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_bottom));
	if (t != 1)return t;
	return 1;
}



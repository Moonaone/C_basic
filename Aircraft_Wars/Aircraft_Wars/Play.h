#ifndef __PLAY_H_
#define __PLAY_H_

#include <stdio.h>
#include <easyx.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

enum My
{
	WIDTH = 591, // 宽度
	HEIGH = 864, // 高度
	BULLET_NUM = 30, // 子弹数量
	SHIP_SPEED = 2, // 飞机移动速度
	BULLET_SPEED = 2, // 子弹速度
	BIG, // 敌机大
	SMALL, // 敌机小
	ENEMY_NUM = 5, // 敌机数量
	ENEMY_SPEED = 1 // 敌机速度
};

struct plance // 自己|敌机
{
	int x;
	int y;
	bool live; // 是否死亡
	int hp; // 血量
	int type; // 标记敌机大小
	int width;
	int height;
};

plance MyPlance; // 我自己
plance bulle[BULLET_NUM]; // 子弹
plance enemy[ENEMY_NUM]; // 敌机


void Load();
void Init_game();
void draw_game();
void playermove();
void createbullet();
void bulletmove();
void createenemy();
void enemymove();
bool Timer(int ms, int id);
void enemyHp(int i);
void playplance();
void collision();


#endif // !__PLAY_H_

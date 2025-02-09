#ifndef __PLAY_H_
#define __PLAY_H_

#include <stdio.h>
#include <easyx.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

enum My
{
	WIDTH = 591, // ���
	HEIGH = 864, // �߶�
	BULLET_NUM = 30, // �ӵ�����
	SHIP_SPEED = 2, // �ɻ��ƶ��ٶ�
	BULLET_SPEED = 2, // �ӵ��ٶ�
	BIG, // �л���
	SMALL, // �л�С
	ENEMY_NUM = 5, // �л�����
	ENEMY_SPEED = 1 // �л��ٶ�
};

struct plance // �Լ�|�л�
{
	int x;
	int y;
	bool live; // �Ƿ�����
	int hp; // Ѫ��
	int type; // ��ǵл���С
	int width;
	int height;
};

plance MyPlance; // ���Լ�
plance bulle[BULLET_NUM]; // �ӵ�
plance enemy[ENEMY_NUM]; // �л�


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

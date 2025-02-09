#include "Play.h"

const int MAX = 10;

IMAGE img_role[2]; // 玩家图
IMAGE BK; // 背景图
IMAGE img_bulle[2]; // 子弹
IMAGE img_enemy[2][2]; // 敌机

// 加载图片
void Load()
{
	loadimage(&BK, "background.jpg");
	loadimage(&img_role[0], "planceNormal_1.jpg");
	loadimage(&img_role[1], "planceNormal_2.jpg");
	loadimage(&img_bulle[0], "bullet1.jpg");
	loadimage(&img_bulle[1], "bullet2.jpg");
	loadimage(&img_enemy[0][1], "enemy_1.jpg");
	loadimage(&img_enemy[0][0], "enemy_2.jpg");
	loadimage(&img_enemy[1][0], "enemyPlance1.jpg");
	loadimage(&img_enemy[1][1], "enemyPlance2.jpg");
}

// 初始化
void Init_game()
{
	Load(); // 加载图片

	// 设置飞机的位置、中心
	MyPlance.x = WIDTH / 2 - 60;
	MyPlance.y = HEIGH - 120;
	MyPlance.live = true;
	for (int i = 0; i < BULLET_NUM; i++)
	{
		bulle[i].x = 0;
		bulle[i].y = 0;
		bulle[i].live = false;
	}
}

// 绘制游戏
void draw_game()
{
	putimage(0, 0, &BK); // 绘制背景图

	// 绘制透明图
	putimage(MyPlance.x, MyPlance.y, &img_role[0], NOTSRCERASE); // 绘制我的飞机
	putimage(MyPlance.x, MyPlance.y, &img_role[1], SRCINVERT);

	// 绘制子弹
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bulle[i].live)
		{
			putimage(bulle[i].x, bulle[i].y, &img_bulle[0], NOTSRCERASE);
			putimage(bulle[i].x, bulle[i].y, &img_bulle[1], SRCINVERT);
		}
	}

	// 绘制敌机
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].live)
		{
			if (enemy[i].type == BIG)
			{
				putimage(bulle[i].x, bulle[i].y, &img_enemy[1][0], NOTSRCERASE);
				putimage(bulle[i].x, bulle[i].y, &img_enemy[1][1], SRCINVERT);
			}
			else
			{
				putimage(bulle[i].x, bulle[i].y, &img_enemy[0][0], NOTSRCERASE);
				putimage(bulle[i].x, bulle[i].y, &img_enemy[0][1], SRCINVERT);
			}
		}
	}
}

// 飞机的移动
void playermove()
{
	if (kbhit())
	{
		switch (getch())
		{
		case 'w':
			MyPlance.y -= SHIP_SPEED;
			break;
		case's':
			MyPlance.y += SHIP_SPEED;
			break;
		case 'a':
			MyPlance.x -= SHIP_SPEED;
			break;
		case'd':
			MyPlance.x += SHIP_SPEED;
		case 'j':
			createbullet();
			break;
		}
	}

	/* Windows API
	* if(GetAsynKeyState(VK_UP) || GetAsynKeyState('w'))
	* {
	*	MyPlance.y -= SHIP_SPEED;
	* }
	*/
}

// 创建子弹
void createbullet()
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (!bulle[i].live)
		{
			bulle[i].x = MyPlance.x + 49;
			bulle[i].y = MyPlance.y;
			bulle[i].live = true;
			break;
		}
	}
}

// 子弹移动
void bulletmove()
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bulle[i].live)
		{
			bulle[i].y -= BULLET_SPEED;
		}
		if (bulle[i].y < 0) // 子弹超出范围
		{
			bulle[i].live = false;
		}
	}
}

// 创建敌机
void createenemy()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (!enemy[i].live)
		{
			enemy[i].x = rand() % (WIDTH - 60);
			enemy[i].y = 0;
			enemy[i].live = true;
			break;
		}
	}
}

// 敌机移动
void enemymove()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].live)
		{
			enemy[i].y += ENEMY_SPEED;
		}
		if (enemy[i].y > HEIGH)
		{
			enemy[i].live = false;
		}
	}
}

// 定时器
bool Timer(int ms, int id)
{
	static DWORD t[MAX];
	if (clock() - t[id] > ms)
	{
		t[id] = clock();
		return true;
	}
	return false;
}

// 敌机血条
void enemyHp(int i)
{
	int flag = rand() % 10;
	if (flag > 0 && flag < 2)
	{
		enemy[i].type = BIG;
		enemy[i].hp = 3;
		enemy[i].width = 104;
		enemy[i].height = 148;
	}
	else
	{
		enemy[i].type = SMALL;
		enemy[i].hp = 1;
		enemy[i].width = 52;
		enemy[i].height = 39;
	}
}

// 打飞机
void playplance()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (!enemy[i].live) // 敌机不存在
		{
			continue;
		}
		for (int j = 0; j < BULLET_NUM; j++)
		{
			if (!bulle[i].live) // 子弹不存在
			{
				continue;
			}
			// 判断条件成立,表示子弹碰到了敌机
			if (bulle[j].x > enemy[i].x && bulle[j].x < enemy[i].x + enemy[i].width &&
				bulle[j].y > enemy[i].y && bulle[j].y < enemy[i].y + enemy[i].height)
			{
				bulle[j].live = false;
				enemy[i].hp--;
			}
			if (enemy[i].hp == 0)
			{
				enemy[i].live = false;
			}
		}
	}
}

// 碰撞检测
void collision()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (MyPlance.y <= enemy[i].y && MyPlance.y >= enemy[i].y + enemy[i].height &&
			MyPlance.x >= enemy[i].x && MyPlance.x >= enemy[i].x + enemy[i].width)
		{
			MyPlance.live = false;
			exit(0);
		}
	}
}

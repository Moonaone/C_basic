#include "Play.h"

const int MAX = 10;

IMAGE img_role[2]; // ���ͼ
IMAGE BK; // ����ͼ
IMAGE img_bulle[2]; // �ӵ�
IMAGE img_enemy[2][2]; // �л�

// ����ͼƬ
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

// ��ʼ��
void Init_game()
{
	Load(); // ����ͼƬ

	// ���÷ɻ���λ�á�����
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

// ������Ϸ
void draw_game()
{
	putimage(0, 0, &BK); // ���Ʊ���ͼ

	// ����͸��ͼ
	putimage(MyPlance.x, MyPlance.y, &img_role[0], NOTSRCERASE); // �����ҵķɻ�
	putimage(MyPlance.x, MyPlance.y, &img_role[1], SRCINVERT);

	// �����ӵ�
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bulle[i].live)
		{
			putimage(bulle[i].x, bulle[i].y, &img_bulle[0], NOTSRCERASE);
			putimage(bulle[i].x, bulle[i].y, &img_bulle[1], SRCINVERT);
		}
	}

	// ���Ƶл�
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

// �ɻ����ƶ�
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

// �����ӵ�
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

// �ӵ��ƶ�
void bulletmove()
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bulle[i].live)
		{
			bulle[i].y -= BULLET_SPEED;
		}
		if (bulle[i].y < 0) // �ӵ�������Χ
		{
			bulle[i].live = false;
		}
	}
}

// �����л�
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

// �л��ƶ�
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

// ��ʱ��
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

// �л�Ѫ��
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

// ��ɻ�
void playplance()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (!enemy[i].live) // �л�������
		{
			continue;
		}
		for (int j = 0; j < BULLET_NUM; j++)
		{
			if (!bulle[i].live) // �ӵ�������
			{
				continue;
			}
			// �ж���������,��ʾ�ӵ������˵л�
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

// ��ײ���
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

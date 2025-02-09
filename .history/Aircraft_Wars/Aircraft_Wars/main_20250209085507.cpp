#include "Play.h"

int main()
{
	initgraph(WIDTH, HEIGH); // 创建界面
	Init_game();

	while (1)
	{
		draw_game();
		FlushBatchDraw(); // 刷新
		playermove();
		bulletmove();
		// 不能直接调用创建敌机和敌机的移动
		// 需要一个定时器
		if (Timer(500, 0))
		{
			createenemy(); // 每500ms产生敌机
		}
		if (Timer(30, 2))
		{
			enemymove(); // 每30ms飞机移动
		}
		playplance();
		collision();
	}
	EndBatchDraw();

	while (1);

	return 0;
}


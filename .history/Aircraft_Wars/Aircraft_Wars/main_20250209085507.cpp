#include "Play.h"

int main()
{
	initgraph(WIDTH, HEIGH); // ��������
	Init_game();

	while (1)
	{
		draw_game();
		FlushBatchDraw(); // ˢ��
		playermove();
		bulletmove();
		// ����ֱ�ӵ��ô����л��͵л����ƶ�
		// ��Ҫһ����ʱ��
		if (Timer(500, 0))
		{
			createenemy(); // ÿ500ms�����л�
		}
		if (Timer(30, 2))
		{
			enemymove(); // ÿ30ms�ɻ��ƶ�
		}
		playplance();
		collision();
	}
	EndBatchDraw();

	while (1);

	return 0;
}


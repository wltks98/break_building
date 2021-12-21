#include <stdio.h>//printf
#include <conio.h>//getch
#include <windows.h>//gotoxy
#include <stdlib.h>//system
#include <math.h>


// 1. �ʱ�ȭ��
// 2. ���ӽ���� Ʋ,����,���� ǥ��
// 3. ��� ����(�������°�)
// 4. �ɸ��� ������
// 5. ��� �μ���(Ư��Ű �Է½� ��� �ı�,����,���� ���)

void start_screen();
void game_screen();
void new_block();
void character();
void gotoxy(int x, int y);
void gameover();

int ba=5, bb=1;
int ca=24, cb=20;
char ch, ch2;

int score = 0;
int level = 0;



int main(void)
{
	start_screen();

	while (1)
	{
		if (bb + 3 + level > 20)
		{
			gameover();
			break;
		}

		system("cls");

		game_screen();

		new_block();

		character();

	}

}

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void new_block()
{
	int i;

	for (i = 0; i < 3 + level; i++)
	{
		gotoxy(ba, bb + i);
		printf("���������������������");

	}

	bb++;


}


void game_screen()
{
	char i, j;

	gotoxy(55, 5);
	printf("LEVEL : %d   SCORE : %d", level, score);
	gotoxy(0, 0);

	printf("�âââââââââââââââââââââââââ� ");
	for (i = 0; i < 21; i++) {
		printf("\n|");
		for (j = 0; j < 50; j++) {
			printf(" ");
		}
		printf("|");
	}
	printf("\n�âââââââââââââââââââââââââ�");

}



void start_screen()
{

	printf("     �������������\n");
	printf("     ��                    ��\n");
	printf("     ��    �ǹ� ���ñ�     ��\n");
	printf("     ��                    ��\n");
	printf("     �������������\n");

	printf("     �����Ϸ��� �ƹ� Ű�� �Է��ϼ���.");
	system("pause>nul");


}

void character()
{

	if (_kbhit())
	{
		ch = _getch();
		if (ch = ' ')
		{
			if (cb - (bb + 2 + level) < 5) {

				gotoxy(ca, bb + 3 + level);
				printf("��");
				Sleep(300);
			}

			else {

				gotoxy(ca, cb - 5);
				printf("��");
				Sleep(300);
			}

			if (_kbhit())
			{
				if (cb - 5 - (bb + 2 + level) <= 1 && (ch2 = _getch()) == 'f')
				{
					bb = 0;
					score += 1;
					level = (score / 10);
				}
			}

		}

	}
	else
	{
		gotoxy(ca, cb);
		printf("��");
	}

	Sleep(200 - level * 10);

}

void gameover()
{
	system("cls");

	printf("\n\n\n");
	printf("               �������������\n");
	printf("               ��                    ��\n");
	printf("               ��     GAME OVER      ��\n");
	printf("               ��                    ��\n");
	printf("               �������������\n");
	printf("\n\n\n\n");
	printf("                  Score:%d, level : %d", score, level);
	system("pause>nul");
}


/*
	  ������ �����̽��� �μ��� ��ư�� F

	  �ɸ��ʹ� ������ ���� �� F�� ���� �ǹ��� �νǼ� �ִ�. �� ������ ���̴� �������ִ�.

	  �ǹ��� �ν��� ���ϰ� �򸮸� ���ӿ���

	  ���ھ 10���������� ������ �ö󰡸� �ǹ��� �������� �ӵ��� �������� �ǹ��� �β�������.


*/
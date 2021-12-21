#include <stdio.h>//printf
#include <conio.h>//getch
#include <windows.h>//gotoxy
#include <stdlib.h>//system
#include <math.h>


// 1. 초기화면
// 2. 게임실행시 틀,점수,레벨 표시
// 3. 블록 생성(내려오는것)
// 4. 케릭터 움직임
// 5. 블록 부수기(특정키 입력시 블록 파괴,점수,레벨 기능)

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
		printf("■■■■■■■■■■■■■■■■■■■■");

	}

	bb++;


}


void game_screen()
{
	char i, j;

	gotoxy(55, 5);
	printf("LEVEL : %d   SCORE : %d", level, score);
	gotoxy(0, 0);

	printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣ ");
	for (i = 0; i < 21; i++) {
		printf("\n|");
		for (j = 0; j < 50; j++) {
			printf(" ");
		}
		printf("|");
	}
	printf("\n▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣");

}



void start_screen()
{

	printf("     ■■■■■■■■■■■■\n");
	printf("     ■                    ■\n");
	printf("     ■    건물 보시기     ■\n");
	printf("     ■                    ■\n");
	printf("     ■■■■■■■■■■■■\n");

	printf("     시작하려면 아무 키나 입력하세요.");
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
				printf("㈜");
				Sleep(300);
			}

			else {

				gotoxy(ca, cb - 5);
				printf("㈜");
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
		printf("㈜");
	}

	Sleep(200 - level * 10);

}

void gameover()
{
	system("cls");

	printf("\n\n\n");
	printf("               ■■■■■■■■■■■■\n");
	printf("               ■                    ■\n");
	printf("               ■     GAME OVER      ■\n");
	printf("               ■                    ■\n");
	printf("               ■■■■■■■■■■■■\n");
	printf("\n\n\n\n");
	printf("                  Score:%d, level : %d", score, level);
	system("pause>nul");
}


/*
	  점프는 스페이스바 부수기 버튼은 F

	  케릭터는 점프를 했을 때 F를 눌러 건물을 부실수 있다. 단 점프의 높이는 정해져있다.

	  건물을 부시지 못하고 깔리면 게임오버

	  스코어가 10오를때마다 레벨이 올라가며 건물이 떨어지는 속도가 빨라지고 건물이 두꺼워진다.


*/
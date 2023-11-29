#include "AppBox.h"

int main()
{
	char choice;

	while (true) {
		system("cls");

		printf("1. 맞춰라! 퀴즈\n");
		printf("2. 미로 탈출\n");
		printf("3. 구글 공룡 게임\n");
		printf("4. 테트리스 게임\n");

		puts("무엇을 플레이 하시겠습니까?");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		choice = getch();

		switch (choice)
		{
		case '1':
			system("cls");
			quiz_start();
			break;
		case '2':
			system("cls");
			TetrisStart();
			break;
		case '3':
			system("cls");
			dinogame_start();
			break;
		case '4':
			system("cls");
			TetrisStart();
			break;
		}
	}
}
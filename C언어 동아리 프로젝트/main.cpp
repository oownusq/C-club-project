#include "AppBox.h"

int main()
{
	char choice;

	while (true) {
		system("cls");

		printf("1. �����! ����\n");
		printf("2. �̷� Ż��\n");
		printf("3. ���� ���� ����\n");
		printf("4. ��Ʈ���� ����\n");

		puts("������ �÷��� �Ͻðڽ��ϱ�?");
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
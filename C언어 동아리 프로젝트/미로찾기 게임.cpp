#include "AppBox.h"
using namespace std;

const int rows = 10;
const int cols = 20;
const int numStages = 5; // �������� ����
//"###################",
//"#S               ##",
//"### ### # ### ###E#",
//"#   #   #   #   # #",
//"# # # ##### ### # #",
//"# # ##      #   # #",
//"### # ########### #",
//"#   #   #       # #",
//"# ##### # # ##### #",
//"#         #       #",
// 
// "###################",
// �� ���������� �̷� �迭
char mazes[numStages][rows][cols] = {
    {

        "###################",
        "#S#     #   #     #",
        "# # ### # ### ### #",
        "# # #   #   #   # #",
        "# # # ##### ### ###",
        "# # #           #E#",
        "# # ############# #",
        "#       #       # #",
        "# ##### # # ##### #",
        "# #       #       #",


    },
    {
       "###################",
        "#S#     #     #   #",
        "# # ### # ### # # #",
        "# # #   #   #   # #",
        "# # # ##### ### # #",
        "#   #       #   # #",
        "### # ####### ### #",
        "#   #   #       # #",
        "# # ### # # ##### #",
        "# #     # #     #E#",
    },
    {
        "###################",
        "#S#     #     #   #",
        "# # ### # ### # #E#",
        "#   #   #   #   ###",
        "# # # ##### ### # #",
        "# # ##      #   # #",
        "### # ####### ### #",
        "#   #   #       # #",
        "# ##### # # ##### #",
        "#         #       #",
    },
    {
        "###################",
        "#S               ##",
        "### ### # ### ###E#",
        "#   #   #   #   # #",
        "# # # ##### ### # #",
        "# # ##      #   # #",
        "### # ########### #",
        "#   #   #       # #",
        "# ##### # # ##### #",
        "#         #       #",
    },
    {
        "###################",
        "#S#################",
        "#################E#",
        "###################",
        "###################",
        "###################",
        "###################",
        "###################",
        "###################",
        "###################",
    }
};

int playerX = 1;
int playerY = 1;
int currentStage = 0; // ���� ��������

void DrawMaze() {
    system("cls");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == playerY && j == playerX) {
                cout << "P";  // �÷��̾� ��ġ
            }
            else {
                cout << mazes[currentStage][i][j];
            }
        }
        cout << endl;
    }
}

bool IsExit(int x, int y) {
    return mazes[currentStage][y][x] == 'E';
}

bool IsValidMove(int x, int y) {
    return mazes[currentStage][y][x] != '#' && x >= 0 && x < cols && y >= 0 && y < rows;
}

int beplayerX = 0;
int beplayerY = 0;
void MovePlayer(char direction) {
    int newX = playerX;
    int newY = playerY;

    switch (direction) {
    case 'w': // ����
        newY--;
        break;
    case 's': // �Ʒ���
        newY++;
        break;
    case 'a': // ����
        newX--;
        break;
    case 'd': // ������
        newX++;
        break;
    }

    if (IsValidMove(newX, newY)) {
        mazes[currentStage][playerY][playerX] = ' ';
        playerX = newX;
        playerY = newY;
        if (currentStage == 4)
        {
            mazes[currentStage][beplayerY][beplayerX] = '#';
        }
    }

}
void StartText() {
    system("title �̷�ã�� ����");
    char sen[44] = { "�� 5���������� �̷���� ������" };
    char sen2[59] = { "������ ���������� �̺�Ʈ �������� �Դϴ�" };
    char sen3[59] = { "�׷� ��̰� �÷����� �ֽñ� �ٶ��ϴ�!" };
    cout << "�̷� ã�� ����!\n";

    Sleep(1000);
    for (int i = 0; i < 44; i++) {
        cout << sen[i];
        Sleep(40);
    }
    puts("");
    for (int i = 0; i < 59; i++) {
        cout << sen2[i];
        Sleep(40);
    }
    puts("");
    for (int i = 0; i < 59; i++) {
        cout << sen3[i];
        Sleep(40);
    }
}
int Mazeescape_start() {

    char move;
    StartText();
    while (currentStage < numStages) {
        DrawMaze();
        cout << "�̵� ������ �����ϼ��� (w: ��, s: �Ʒ�, a: ����, d: ������, x: ����): ";
        if (currentStage == 4)
        {
            if (playerY == 2 && playerX == 17)
            {
                system("cls");
                cout << "�����մϴ�!\n";
                cout << "��� ���������� Ŭ���� �ϼ̽��ϴ�!\n";
                cout << "�÷��� ���ּż� ����帳�ϴ�.\n\n";

                system("pause");

                return 0;
            }
        }
        cin >> move;
        beplayerX = playerX;
        beplayerY = playerY;
        if (currentStage == 4) // �̺�Ʈ ��������
        {
            if (playerY == 1)
            {
                if (playerX == 3 || playerX == 7 || playerX == 9 || playerX == 13) {
                    if (move == 's')
                    {
                        mazes[currentStage][2][playerX] = ' ';
                    }
                }
                if (playerX == 16)
                {
                    if (move == 'a')
                    {
                        mazes[currentStage][1][playerX - 1] = ' ';
                    }
                }
                if (playerX >= 1 && playerX <= 15)
                {
                    if (move == 'd')
                    {
                        mazes[currentStage][1][playerX + 1] = ' ';
                    }
                    else if (move == 'a')
                    {
                        if (playerX - 1 != 0)
                        {
                            mazes[currentStage][1][playerX - 1] = ' ';
                        }
                    }
                }
            }
            else if (playerY == 2) {
                if (playerX == 3 || playerX == 7 || playerX == 9 || playerX == 13)
                {
                    if (move == 'w')
                    {
                        mazes[currentStage][playerY - 1][playerX] = ' ';
                    }
                    if (move == 's')
                    {
                        mazes[currentStage][playerY + 1][playerX] = ' ';
                    }
                }

            }
            else if (playerY == 3) {

                if (playerX <= 3 && playerX >= 1)
                {
                    if (move == 'a')
                    {
                        if (playerX - 1 != 0)
                        {
                            mazes[currentStage][3][playerX - 1] = ' ';
                        }
                    }
                    else if (move == 'd')
                    {
                        if (playerX + 1 != 4)
                        {
                            mazes[currentStage][3][playerX + 1] = ' ';

                        }
                    }
                }
                else  if (playerX <= 7 && playerX >= 5)
                {
                    if (move == 'a')
                    {
                        if (playerX - 1 != 4)
                        {
                            mazes[currentStage][3][playerX - 1] = ' ';
                        }
                    }
                    else if (move == 'd')
                    {
                        if (playerX + 1 != 8)
                        {
                            mazes[currentStage][3][playerX + 1] = ' ';

                        }
                    }
                }
                else if (playerX <= 11 && playerX >= 9)
                {
                    if (move == 'a')
                    {
                        if (playerX - 1 != 8)
                        {
                            mazes[currentStage][3][playerX - 1] = ' ';
                        }
                    }
                    else if (move == 'd')
                    {
                        if (playerX + 1 != 12)
                        {
                            mazes[currentStage][3][playerX + 1] = ' ';

                        }
                    }
                }
                else  if (playerX <= 15 && playerX >= 13)
                {
                    if (move == 'a')
                    {
                        if (playerX - 1 != 12)
                        {
                            mazes[currentStage][3][playerX - 1] = ' ';
                        }
                    }
                    else if (move == 'd')
                    {
                        if (playerX + 1 != 16)
                        {
                            mazes[currentStage][3][playerX + 1] = ' ';

                        }
                    }
                }

                if (playerX == 3 || playerX == 7 || playerX == 9 || playerX == 13 || playerX == 17) {
                    if (move == 'w')
                    {
                        mazes[currentStage][playerY - 1][playerX] = ' ';
                    }
                }

                if (playerX == 1 || playerX == 3 || playerX == 5 || playerX == 11 || playerX == 15 || playerX == 17)
                {
                    if (move == 's')
                    {
                        mazes[currentStage][playerY + 1][playerX] = ' ';
                    }
                }
            }
            else if (playerY == 4) {
                if (playerX == 1 || playerX == 3 || playerX == 5 || playerX == 11 || playerX == 15 || playerX == 17)
                {
                    if (move == 'w')
                    {
                        mazes[currentStage][playerY - 1][playerX] = ' ';
                    }
                }
                if (playerX == 1 || playerX == 3 || playerX == 11 || playerX == 15 || playerX == 17)
                {
                    if (move == 's')
                    {
                        mazes[currentStage][playerY + 1][playerX] = ' ';
                    }
                }
            }
            else if (playerY == 5) {


                if (playerX >= 6 && playerX <= 15)
                {
                    if (playerX + 1 != 16)
                    {
                        if (move == 'd')
                        {
                            mazes[currentStage][playerY][playerX + 1] = ' ';
                        }
                    }
                    if (playerX - 1 != 5)
                    {
                        if (move == 'a')
                        {
                            mazes[currentStage][playerY][playerX - 1] = ' ';
                        }
                    }
                }


                if (playerX == 1 || playerX == 3 || playerX == 11 || playerX == 15 || playerX == 17)
                {
                    if (move == 'w')
                    {
                        mazes[currentStage][playerY - 1][playerX] = ' ';
                    }
                    if (playerX == 3 || playerX == 17)
                    {
                        if (move == 's')
                        {
                            mazes[currentStage][playerY + 1][playerX] = ' ';
                        }
                    }
                }
            }
            else if (playerY == 6) {
                if (playerX == 3 || playerX == 5 || playerX == 17)
                {
                    if (playerX == 3 || playerX == 17)
                    {
                        if (move == 'w')
                        {
                            mazes[currentStage][playerY - 1][playerX] = ' ';
                        }
                    }

                    if (move == 's')
                    {
                        mazes[currentStage][playerY + 1][playerX] = ' ';
                    }
                }
            }
            else if (playerY == 7) {
                if (playerX == 3 || playerX == 5 || playerX == 17)
                {
                    if (move == 'w')
                    {
                        mazes[currentStage][playerY - 1][playerX] = ' ';
                    }
                }

                if (playerX == 1 || playerX == 7 || playerX == 9 || playerX == 11 || playerX == 17)
                {
                    if (move == 's')
                    {
                        mazes[currentStage][playerY + 1][playerX] = ' ';
                    }
                }

                if (playerX >= 1 && playerX <= 3)
                {

                    if (playerX - 1 != 0)
                    {
                        if (move == 'a')
                        {
                            mazes[currentStage][playerY][playerX - 1] = ' ';
                        }
                    }
                    if (playerX + 1 != 4)
                    {
                        if (move == 'd')
                        {
                            mazes[currentStage][playerY][playerX + 1] = ' ';
                        }
                    }
                }

                if (playerX >= 5 && playerX <= 7)
                {
                    if (playerX - 1 != 4)
                    {
                        if (move == 'a')
                        {
                            mazes[currentStage][playerY][playerX - 1] = ' ';
                        }
                    }
                    if (playerX + 1 != 8)
                    {
                        mazes[currentStage][playerY][playerX + 1] = ' ';
                    }
                }

                if (playerX >= 9 && playerX <= 15)
                {
                    if (playerX - 1 != 8)
                    {
                        if (move == 'a')
                        {
                            mazes[currentStage][playerY][playerX - 1] = ' ';
                        }
                    }
                    if (playerX + 1 != 16)
                    {
                        if (move == 'd')
                        {

                            mazes[currentStage][playerY][playerX + 1] = ' ';
                        }
                    }
                }







            }
            else if (playerY == 8) {
                if (playerX == 1 || playerX == 7 || playerX == 9 || playerX == 11 || playerX == 17)
                {
                    if (move == 'w')
                    {
                        mazes[currentStage][playerY - 1][playerX] = ' ';
                    }
                    if (move == 's')
                    {
                        mazes[currentStage][playerY + 1][playerX] = ' ';
                    }
                }

            }
            else if (playerY == 9) {

                if (playerX == 1 || playerX == 7 || playerX == 9 || playerX == 11 || playerX == 17)
                {
                    if (move == 'w')
                    {
                        mazes[currentStage][playerY - 1][playerX] = ' ';
                    }
                }

                if (playerX >= 1 && playerX <= 9)
                {
                    if (playerX - 1 != 0)
                    {
                        if (move == 'a')
                        {
                            mazes[currentStage][playerY][playerX - 1] = ' ';
                        }
                    }
                    if (playerX + 1 != 10)
                    {
                        if (move == 'd')
                        {
                            mazes[currentStage][playerY][playerX + 1] = ' ';
                        }
                    }
                }
                if (playerX >= 11 && playerX <= 17)
                {
                    if (playerX - 1 != 10)
                    {
                        if (move == 'a')
                        {
                            mazes[currentStage][playerY][playerX - 1] = ' ';
                        }
                    }
                    if (playerX + 1 != 18)
                    {
                        if (move == 'd')
                        {
                            mazes[currentStage][playerY][playerX + 1] = ' ';
                        }
                    }
                }




            }
        }

        if (move == 'x') {
            cout << "������ �����մϴ�." << endl;
            break;
        }
        MovePlayer(move);

        if (IsExit(playerX, playerY)) {
            system("cls");
            cout << "�������� Ŭ����!" << endl;
            Sleep(1000);
            currentStage++; // ���� ���������� �̵�
            playerX = 1;
            playerY = 1;
        }
    }


    return 0;
}

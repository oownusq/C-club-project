#include "AppBox.h"
using namespace std;

const int rows = 10;
const int cols = 20;
const int numStages = 5; // 스테이지 개수
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
// 각 스테이지의 미로 배열
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
int currentStage = 0; // 현재 스테이지

void DrawMaze() {
    system("cls");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == playerY && j == playerX) {
                cout << "P";  // 플레이어 위치
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
    case 'w': // 위쪽
        newY--;
        break;
    case 's': // 아래쪽
        newY++;
        break;
    case 'a': // 왼쪽
        newX--;
        break;
    case 'd': // 오른쪽
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
    system("title 미로찾기 게임");
    char sen[44] = { "총 5스테이지로 이루어져 있으며" };
    char sen2[59] = { "마지막 스테이지는 이벤트 스테이지 입니다" };
    char sen3[59] = { "그럼 즐겁게 플레이해 주시길 바랍니다!" };
    cout << "미로 찾기 게임!\n";

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
        cout << "이동 방향을 선택하세요 (w: 위, s: 아래, a: 왼쪽, d: 오른쪽, x: 종료): ";
        if (currentStage == 4)
        {
            if (playerY == 2 && playerX == 17)
            {
                system("cls");
                cout << "축하합니다!\n";
                cout << "모든 스테이지를 클리어 하셨습니다!\n";
                cout << "플레이 해주셔서 감사드립니다.\n\n";

                system("pause");

                return 0;
            }
        }
        cin >> move;
        beplayerX = playerX;
        beplayerY = playerY;
        if (currentStage == 4) // 이벤트 스테이지
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
            cout << "게임을 종료합니다." << endl;
            break;
        }
        MovePlayer(move);

        if (IsExit(playerX, playerY)) {
            system("cls");
            cout << "스테이지 클리어!" << endl;
            Sleep(1000);
            currentStage++; // 다음 스테이지로 이동
            playerX = 1;
            playerY = 1;
        }
    }


    return 0;
}

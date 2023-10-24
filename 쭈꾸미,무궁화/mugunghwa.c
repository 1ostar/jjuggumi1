#include "jjuggumi.h"
#include "canvas.h"
#include "keyin.h"
#include <stdio.h>

int movable, dir;
int status[PLAYER_MAX];
int px[PLAYER_MAX], py[PLAYER_MAX];

void mugunghwa_init(void);
void move_manual(key_t key);

void mugunghwa_init() {
    N_ROW = 10;
    N_COL = 40;
    for (int i = 0; i < ROW_MAX; i++) {
        for (int j = 0; j < COL_MAX; j++) {
            back_buf[i][j] = front_buf[i][j] = ' ';
        }
    }

    for (int i = 0; i < 10; i++) {
        back_buf[i][0] = back_buf[i][39] = '*';

        for (int j = 1; j < 39; j++) {
            back_buf[i][j] = (i == 0 || i == 10 - 1) ? '*' : ' ';
        }
    }
    int x, y;

    for (int i = 0; i < n_player; i++) {
        do {
            x = randint(1, 8);
            y = N_COL - 2;
        } while (!placable(x, y));

        px[i] = x;
        py[i] = y;

        back_buf[px[i]][py[i]] = '0' + i;
        status[i] = 0;
    }

    for (int i = 3; i < 7; i++) {
        back_buf[i][1] = '#';
    }

    tick = 0;
}

void move(int player, int dir) {
    int rx = 0, ry = 0;

    if (dir == 0) {
        rx = 0; ry = -1;
    }
    else if (dir == 1) {
        rx = 1; ry = 0;
    }
    else if (dir == 2) {
        rx = -1; ry = 0;
    }
    else {
        rx = 0; ry = 0;
    }

    if (placable(px[player] + rx, py[player] + ry)) {
        back_buf[px[player] + rx][py[player] + ry] = back_buf[px[player]][py[player]];
        back_buf[px[player]][py[player]] = ' ';
        px[player] += rx;
        py[player] += ry;
    }
}

int is_passed(int player) {
    int x = px[player];
    int y = py[player];

    for (int i = 3; i <= 6; i++) {
        if ((y == 2 && x == i) || (y == 1 && x == 2) || (y == 1 && x == 7)) {
            return 1;
        }
    }
    return 0;
}


void yunghee(void) {

    if (tick == 100) {
        gotoxy(11, 0);
        printf("¹«");
        movable = 0;

        for (int i = 3; i < 7; i++) {
            back_buf[i][1] = '#';
        }
    }

    if (tick == 300) {
        gotoxy(11, 2);
        printf("±Ã");
    }
    if (tick == 500) {
        gotoxy(11, 4);
        printf("È­");
    }
    if (tick == 700) {
        gotoxy(11, 6);
        printf("²É");
    }
    if (tick == 900) {
        gotoxy(11, 8);
        printf("ÀÌ");
    }
    if (tick == 1100) {
        gotoxy(11, 10);
        printf("ÇÇ");
    }
    if (tick == 1300) {
        gotoxy(11, 12);
        printf("¾ú");
    }
    if (tick == 1500) {
        gotoxy(11, 14);
        printf("½À");
    }
    if (tick == 1700) {
        gotoxy(11, 16);
        printf("´Ï");
    }
    if (tick == 1900) {
        gotoxy(11, 18);
        printf("´Ù");
        gotoxy(3, 1);
        movable = 1;

        for (int i = 3; i < 7; i++) {
            back_buf[i][1] = '@';
        }
    }

    if (tick > 4900) {
        tick = 0;
        system("cls");
        for (int row = 0; row < N_ROW; row++) {
            for (int col = 0; col < N_COL; col++) {
                printxy(back_buf[row][col], row, col);
            }
        }
        display();
        dir = 0;
        movable = 0;
    }
}


void mugunghwa(void) {
    mugunghwa_init();

    system("cls");
    display();

    movable = 0;
    int player_x = px[0];
    int player_y = py[0];

    char msg[] = "Dead            ";
    int msg_index = 5;

    while (1) {
        key_t key = get_key();
        if (msg_index > 5 && tick == 90) {
            dialog(msg);
            for (int i = 5; i < 16; i++)
                msg[i] = ' ';
            msg_index = 5;
        }


        if (key == K_QUIT) {
            break;
        }
        else if (key != K_UNDEFINED) {
            if (status[0] != 1) {
                move_manual(key);

                if (movable == 0) {
                    player_x = px[0];
                    player_y = py[0];
                }
                else if (movable == 1 && player[0] != 0) {
                    if ((player_x != px[0]) || (player_y != py[0])) {
                        int isAlive = 0;

                        for (int j = 1; j < n_player; j++) {
                            if (player[j] == 0 || status[j] == 1)
                                continue;
                            if (px[0] == px[j] && py[j] < py[0])
                                isAlive = 1;
                        }

                        if (!isAlive) {
                            player[0] = 0;
                            back_buf[px[0]][py[0]] = ' ';
                            n_alive--;

                            msg[msg_index] = 0 + '0';
                            msg_index += 2;
                            display();
                        }

                        player_x = px[0];
                        player_y = py[0];
                    }
                }
            }
        }

        for (int i = 1; i < n_player; i++) {
            if (status[i] != 1) {
                if (movable == 0) {
                    if (randint(1, 100) == 1) {
                        int N = randint(1, 10);

                        if (1 <= N && N <= 7) {
                            dir = 0;
                        }
                        else if (7 < N && N <= 8) {
                            dir = 1;
                        }
                        else if (8 < N && N <= 9) {
                            dir = 2;
                        }
                        else {
                            dir = 3;
                        }
                        move(i, dir);
                    }
                }
                else if (movable == 1) {
                    if (randint(1, 50) == 1) {
                        if (player[i] == 0 || status[i] == 1) {
                            continue;
                        }

                        int N = randint(1, 10);
                        if (N == 1) {
                            player[i] = 0;
                            back_buf[px[i]][py[i]] = ' ';
                            n_alive--;
                            msg[msg_index] = i + '0';
                            msg_index += 2;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n_player; i++) {
            if (is_passed(i) == 1) {
                status[i] = 1;
            }
        }

        int alives = 0;

        for (int i = 0; i < n_player; i++) {
            if (player[i])
                alives++;
        }
        if (alives == 1) {
            break;
        }

        display();
        Sleep(10);
        tick += 10;

        yunghee();
        int count_message = 0;

    }
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "jjuggumi.h"

#define DATA_FILE "jjuggumi.dat"

int jjuggumi_init(void);

int randint(int low, int high) {
	int rnum = rand() % (high - low + 1) + low;
	return rnum;
}

int jjuggumi_init(void) {
	srand((unsigned int)time(NULL));

	printf("\n [System] 플레이어 수를 입력하세요 >> ");
	scanf_s("%d", &n_player);

	n_alive = n_player;
	for (int i = 0; i < n_player; i++) {
		player[i] = true;
	}
	return 0;
}

void clearD() {
	system("cls");
}

void intro() {
	clearD();
	printf("\n");
	Sleep(300);
	printf("    ##################       `######## `########       ``###############    \n");
	Sleep(300);
	printf("        ##`` `  ##``               `##       `##        ###         ``##    \n");
	Sleep(300);
	printf("        ##``   `##`             `` `##       `##        ###         ``##    \n");
	Sleep(300);
	printf("     ``####` ``#### ``             `##`    ``###        ###         ``##    \n");
	Sleep(300);
	printf("     `##` ### ###`##`` ` `         ###    `  ###        ###         ` ##    \n");
	Sleep(300);
	printf("    ###`   `####`  `###         `` ##`       ##`        ################    \n");
	Sleep(300);
	printf("    `     ` `` `    `           ` `##`    ` ###         ###`         `##`   \n");
	Sleep(300);
	printf("           ``` `    ```         ``  `      `` `        ` `  `        ````   \n");
	Sleep(300);
	printf("\n");
	Sleep(300);
	printf("▶");
	Sleep(200);
	printf(" 게임에 ");
	Sleep(200);
	printf("참가하시겠습니까?");
	Sleep(1500);
}

void ending1() {
	system("cls");
	printf("=========================================================================\n\n");
	printf("                       쭈꾸미 게임의 우승자는 바로\n\n");
	printf("=========================================================================\n");
	Sleep(1000);

}

void ending2() {
	int winner = -1;

	for (int i = 0; i < n_player; i++)
		if (player[i])
			winner = player[i];
	system("cls");

	printf("=========================================================================\n\n");
	printf("                       쭈꾸미 게임의 우승자는 바로\n");
	printf("                     %d번 플레이어입니다! 축하드립니다!\n\n", winner);
	printf("=========================================================================\n");
	Sleep(2000);

}

void ending3() {
	system("cls");
	printf("=========================================================================\n\n");
	printf("우승자를 가리지 못했습니다.\n생존자는 ");
	for (int i = 0; i < n_player; i++) {
		if (player[i]) {
			printf("%d번 ", i);
			Sleep(1000);
		}
	}
	printf("입니다.\n\n");
	printf("=========================================================================\n");
	Sleep(3000);
}

void ending() {
	if (n_alive == 1) {
		ending1();
		ending2();
	}
	else {
		ending3();
	}
}

int main(void) {
	jjuggumi_init();
	intro();
	//sample();
	mugunghwa();
	//nightgame();
	//juldarigi();
	//jebi();
	ending();
	return 0;
}
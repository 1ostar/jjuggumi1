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

	printf("\n [System] �÷��̾� ���� �Է��ϼ��� >> ");
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
	printf("��");
	Sleep(200);
	printf(" ���ӿ� ");
	Sleep(200);
	printf("�����Ͻðڽ��ϱ�?");
	Sleep(1500);
}

void ending1() {
	system("cls");
	printf("=========================================================================\n\n");
	printf("                       �޲ٹ� ������ ����ڴ� �ٷ�\n\n");
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
	printf("                       �޲ٹ� ������ ����ڴ� �ٷ�\n");
	printf("                     %d�� �÷��̾��Դϴ�! ���ϵ帳�ϴ�!\n\n", winner);
	printf("=========================================================================\n");
	Sleep(2000);

}

void ending3() {
	system("cls");
	printf("=========================================================================\n\n");
	printf("����ڸ� ������ ���߽��ϴ�.\n�����ڴ� ");
	for (int i = 0; i < n_player; i++) {
		if (player[i]) {
			printf("%d�� ", i);
			Sleep(1000);
		}
	}
	printf("�Դϴ�.\n\n");
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
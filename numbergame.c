#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int randnum() {
	int randnum_ = rand() % 3 + 1;
	return randnum_;
}
int main() {

	srand(time(NULL));

	int answer[100], game, gameover, ans369;

	int Q[3], A[3], i, j, k, strike = 0, ball = 0;

	srand(time(NULL));
	Q[0] = rand() % 9 + 1;
	Q[1] = rand() % 9 + 1;
	Q[2] = rand() % 9 + 1;

	printf("\n1. 369게임\n2. 숫자야구게임\n3. 숫자암기게임\n플레이할 게임의 번호을 입력해주세요! : ");
	scanf_s("%d", &game);

	if (game == 1) {
		printf("369게임을 선택하셨습니다. 369게임을 시작합니다 :)\n");
		printf("출력된 숫자의 다음 수를 입력하고 입력할 숫자에  3, 6, 9가 포함되어있다면 '0'을 입력하세요\n");
		for (int i = 0; i < 99999; i += 2) {
			printf("출력 : %d\n", i + 1);
			printf("다음숫자 또는 0 입력 : ");
			scanf_s("%d", &ans369);
			if (((i + 2) / 100) == 3 || ((i + 2) / 100) == 6 || ((i + 2) / 100) == 9) {
				if (ans369 != 0) {
					printf("오답입니다.");
					break;
				}
			}
			if (((i + 2) / 10) == 3 || ((i + 2) / 10) == 6 || ((i + 2) / 10) == 9){
				if (ans369 != 0) {
					printf("오답입니다.");
					break;
				}
			}
			if (((i + 2) % 10) == 3 || ((i + 2) % 10) == 6 || ((i + 2) % 10) == 9) {
				if (ans369 != 0) {
					printf("오답입니다.");
					break;
				}
			}
			else if (ans369 != (i + 2)) {
				printf("오답입니다.");
				break;
			}
		}
	}

	if (game == 2) {
		printf("숫자야구게임을 선택하셨습니다. 숫자야구게임을 시작합니다 :)\n");
		for (i = 0;i < 10;i++) {
			printf("숫자 세자리를 입력해주세요! ex)1 2 3 : ");
			scanf_s("%d %d %d", &A[0], &A[1], &A[2]);
			strike = 0;
			ball = 0;

			for (j = 0;j < 3;j++) {
				for (k = 0;k < 3;k++) {
					if (Q[j] == A[k]) {
						if (j == k) {
							ball++;
							strike++;
						}
						else {
							ball++;
						}
					}
				}
			}

			printf("strike : %d, ball : %d\n", strike, ball);

			if (strike == 3) {
				printf("정답입니다!");
				break;
			}
			if (i == 9) {
				printf("기회를 모두 잃었습니다 :( 정답은 %d%d%d입니다.", Q[0], Q[1], Q[2]);
			}
		}
	}

	if (game == 3){
		printf("숫자암기게임을 선택하셨습니다. 숫자암기게임을 시작합니다 :)\n");
		for (int round = 1;round <= 100;round++) {
			int this_round_randnum = randnum();

			printf("%d번째 숫자는 -> %d\n", round, this_round_randnum);
			answer[round - 1] = this_round_randnum;

			for (int current = 1;current <= round;current++) {
				int ans;
				printf("\n%d번째 숫자는? : ", current);
				scanf_s("%d", &ans);
				if (ans != answer[current - 1]) {
					printf("오답입니다!\n");
					return 0;
				}
				else {
					printf("정답입니다!\n\n");
				}
			}
		}
	}
}

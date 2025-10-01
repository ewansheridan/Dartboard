#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int value;
    bool isDouble;
} Dart;

Dart toScore(char curr[20]);
void readDart(int *vAddress, bool *dAddress, int turn);

void clearScreen(void) {
    printf("\033[2J\033[H");
}

int main() {

	char p1Name[20];
	char p2Name[20];

	clearScreen();

	/*
	printf("   ____                _          ___           __  __                    __\n");
	printf("  / __/    _____ ____ ( )___     / _ \\___ _____/ /_/ /  ___  ___ ________/ /\n");
	printf(" / _/| |/|/ / _ `/ _ \\|/(_-<    / // / _ `/ __/ __/ _ \\/ _ \\/ _ `/ __/ _  / \n");
	printf("/___/|__,__/\\_,_/_//_/ /___/   /____/\\_,_/_/  \\__/_.__/\\___/\\_,_/_/  \\_,_/  \n\n\n");
    */
printf(" _______       ___      .______     .___________..______     ______        ___      .______       _______  \n");
printf("|       \\     /   \\     |   _  \\    |           ||   _  \\   /  __  \\      /   \\     |   _  \\     |       \\ \n");
printf("|  .--.  |   /  ^  \\    |  |_)  |   `---|  |----`|  |_)  | |  |  |  |    /  ^  \\    |  |_)  |    |  .--.  |\n");
printf("|  |  |  |  /  /_\\  \\   |      /        |  |     |   _  <  |  |  |  |   /  /_\\  \\   |      /     |  |  |  |\n");
printf("|  '--'  | /  _____  \\  |  |\\  \\----.   |  |     |  |_)  | |  `--'  |  /  _____  \\  |  |\\  \\----.|  '--'  |\n");
printf("|_______/ /__/     \\__\\ | _| `._____|   |__|     |______/   \\______/  /__/     \\__\\ | _| `._____||_______/ \n\n\n\n\n");
                                                                                                           
                                                                                            
                                                                                            


	printf("\nEnter name for Player 1:\n>> ");
	fgets(p1Name, 20, stdin);

	printf("\nEnter name for Player 2:\n>> ");
	fgets(p2Name, 20, stdin);

	// Remove trailing new lines
	p1Name[strcspn(p1Name, "\n")] = '\0';
	p2Name[strcspn(p2Name, "\n")] = '\0';

	int score;

	while(1) {
		printf("\nEnter a goal score (We recommend 501)\n>> ");
		scanf("%d", &score);
		while (getchar() != '\n');  // clear stdin until newline

		if(score < 1) {
			printf("\nMake sure to enter a number greater than 0\n\n");
		}
		else {
			break;
		}
	}

	int p1Score = score;
	int p2Score = score;

	/*
	printf("p1 name: %s\n", p1Name);
	printf("p2 name: %s\n", p2Name);
	printf("p1 Score: %d\n", p1Score);
	printf("p2 Score: %d\n", p2Score);
	*/

	printf("\n------------------------------------\n");
	printf("Enter darts in the following format:\n");
	printf("\t>> \"Single 20 \"  ---> S20\n");
	printf("\t>> \"Double 20 \"  ---> D20\n");
	printf("\t>> \"Treble 20 \"  ---> T20\n\n");
	printf("\t>> \"Outer Bull\"  ---> 25\n");
	printf("\t>> \"Inner Bull\"  ---> 50\n");
	printf("\t>> \"Missed Dart\" ---> 0\n\n");
	printf("------------------------------------\n");

	printf("You must finish on a double or Inner Bull\n");
	printf("------------------------------------\n\n");

	printf("Press ENTER to continue");
	while (getchar() != '\n');
	clearScreen();

	while(1) {
		
		printf("------------------------------------\n");
		printf("Now, %s's turn:   (You require %d)\n", p1Name, p1Score);

		bool gameOver = false;

		int threeDarts[3];
		bool isDouble = false;
		int tempScore = p1Score;

		for(int i = 0; i < 3; i++) {
			readDart(&threeDarts[i], &isDouble, i + 1);

			if(threeDarts[i] > tempScore) {
				printf("%s busted their score! No points scored.\n", p1Name);
				tempScore = p1Score;
				break;
			}
			else if(threeDarts[i] == tempScore) {
				
				if(isDouble) {
					printf("%s wins!\n", p1Name);
					gameOver = true;
					break;
				}
				else {
					printf("%s busted their score! (must finish on a double) No points scored.\n", p1Name);
					tempScore = p1Score;
					break;
				}
			}
			else {
				tempScore -= threeDarts[i];
			}
		}
		
		if (gameOver) break;
		printf("\nIn 3 darts, %s scored %d\n", p1Name, p1Score - tempScore);
		printf("%s's score was %d, now it's %d\n", p1Name, p1Score, tempScore);
		p1Score = tempScore;

		



		printf("------------------------------------\n");
		printf("Now, %s's turn:   (You require %d)\n", p2Name, p2Score);

		tempScore = p2Score;

		for(int i = 0; i < 3; i++) {
			readDart(&threeDarts[i], &isDouble, i + 1);

			if(threeDarts[i] > tempScore) {
				printf("%s busted their score! No points scored.\n", p2Name);
				tempScore = p2Score;
				break;
			}
			else if(threeDarts[i] == tempScore) {
				
				if(isDouble) {
					printf("%s wins!\n", p2Name);
					gameOver = true;
					break;
				}
				else {
					printf("%s busted their score! (must finish on a double) No points scored.\n", p2Name);
					tempScore = p2Score;
					break;
				}
			}
			else {
				tempScore -= threeDarts[i];
			}
		}
		
		if (gameOver) break;
		printf("\nIn 3 darts, %s scored %d\n", p2Name, p2Score - tempScore);
		printf("%s's score was %d, now it's %d\n", p2Name, p2Score, tempScore);
		p2Score = tempScore;


		printf("------------------------------------\n");
		printf("CURRENT SCORE:");
		printf("  > %s: %d\n", p1Name, p1Score);
		printf("                > %s: %d\n\n", p2Name, p2Score);


		printf("Press ENTER to continue");
		while (getchar() != '\n');
		clearScreen();
	}
}




Dart toScore(char curr[20]) {

	int factor = 0;
	Dart d = {0, false};

	switch(curr[0]) {

		case '0':
			return d;

		case 'S':
			factor = 1;
			break;

		case 'D':
			factor = 2;
			d.isDouble = true;
			break;

		case 'T':
			factor = 3;
			break;

		case 's':
			factor = 1;
			break;

		case 'd':
			factor = 2;
			d.isDouble = true;
			break;

		case 't':
			factor = 3;
			break;

		case '2':
			if(curr[1] != '5') return (Dart){-8, false};
			if(curr[2] != '\n') return (Dart){-9, false};
			return (Dart){25, false};

		case '5':
			if(curr[1] != '0') return (Dart){-10, false};
			if(curr[2] != '\n') return (Dart){-11, false};
			return (Dart){50, true};

		default:
			return (Dart){-1, false};
	}





	int zone = 0;

	switch(strlen(curr)) {

		case 4:
			if(curr[4] != '\0') return (Dart){-2, false};
			if(curr[3] != '\n') return (Dart){-3, false};
			zone += curr[2] - 48;
			zone += 10 * (curr[1] - 48);
			break;
		
		case 3:
			if(curr[3] != '\0') return (Dart){-4, false};
			if(curr[2] != '\n') return (Dart){-5, false};
			zone += curr[1] - 48;
			break;

		default:
			return (Dart){-6, false};
	}

	if(zone > 20) return (Dart){-7, false};

	d.value = zone * factor;
	return d;
}




void readDart(int *vAddress, bool *dAddress, int turn) {
	
	char curr[20];

	while(1) {
		printf("\nDart %d:\n>> ", turn);
		fgets(curr, 5, stdin);

		Dart d = toScore(curr);
		if(d.value >= 0) {
			printf("That dart scored: %d\n", d.value);
			*vAddress = d.value;
			*dAddress = d.isDouble;
			break;
		}
		
		printf("\nFormat error. Try again.\n");
	}
}
#include <stdio.h>
#include <string.h>

int toScore(char curr[5]);
void readDart(int *address, int turn);

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
	printf("------------------------------------\n\n");

	printf("Press ENTER to continue");
	while (getchar() != '\n');
	clearScreen();

	while(1) {
		
		printf("------------------------------------\n");
		printf("Now, %s's turn:\n\n", p1Name);

		int p1Darts[3];
		for(int i = 0; i < 3; i++) {
			readDart(&p1Darts[i], i + 1); 
		}

		int p1Total = 0;
		for(int i = 0; i < 3; i++) {
			p1Total += p1Darts[i];
		}

		if(p1Score - p1Total >= 0) {
			p1Score -= p1Total;
		}
		else {
			printf("%s busted their score! No points scored.\n", p1Name);
		}

		if(p1Score == 0) {
			printf("%s wins!\n", p1Name);
			break;
		}
		printf("\nTotal score in three darts was %d\n", p1Total);
		printf("%s's score is now: %d\n\n", p1Name, p1Score);
		

		
		printf("\n------------------------------------\n");
		printf("Now, %s's turn:\n\n", p2Name);

		int p2Darts[3];
		for(int i = 0; i < 3; i++) {
			readDart(&p2Darts[i], i + 1); 
		}

		int p2Total = 0;
		for(int i = 0; i < 3; i++) {
			p2Total += p2Darts[i];
		}

		if(p2Score - p2Total >= 0) {
			p2Score -= p2Total;
		}
		else {
			printf("%s busted their score! No points scored.\n", p2Name);
		}

		if(p2Score == 0) {
			printf("%s wins!\n", p2Name);
			break;
		}
		printf("\nTotal score in three darts was %d\n", p2Total);
		printf("%s's score is now: %d\n", p2Name, p2Score);

		printf("\n\nPress ENTER to continue");
		while (getchar() != '\n');
		clearScreen();
	}
}




int toScore(char curr[5]) {

	int factor = 0;

	switch(curr[0]) {

		case '0':
			return 0;

		case 'S':
			factor = 1;
			break;

		case 'D':
			factor = 2;
			break;

		case 'T':
			factor = 3;
			break;

		case 's':
			factor = 1;
			break;

		case 'd':
			factor = 2;
			break;

		case 't':
			factor = 3;
			break;

		case '2':
			if(curr[1] != '5') return -8;
			if(curr[2] != '\n') return -9;
			return 25;

		case '5':
			if(curr[1] != '0') return -10;
			if(curr[2] != '\n') return -11;
			return 50;

		default:
			return -1;
	}





	int zone = 0;

	switch(strlen(curr)) {

		case 4:
			if(curr[4] != '\0') return -2;
			if(curr[3] != '\n') return -3;
			zone += curr[2] - 48;
			zone += 10 * (curr[1] - 48);
			break;
		
		case 3:
			if(curr[3] != '\0') return -4;
			if(curr[2] != '\n') return -5;
			zone += curr[1] - 48;
			break;

		default:
			return -6;
	}

	if(zone > 20) return -7;

	return zone * factor;
}




void readDart(int *address, int turn) {
	
	char curr[5];

	while(1) {
		printf("\nDart %d:\n>> ", turn);
		fgets(curr, 5, stdin);

		int value = toScore(curr);
		if(value >= 0) {
			printf("That dart scored: %d\n", value);
			*address = value;
			break;
		}
		
		printf("\nFormat error. Try again.\n");
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void intializeGrid(char grid[3][3]);
void displayGrid(char grid[3][3]);
void playerMove(char grid[3][3]);
int validMove(char grid[3][3], int row, int col);
void compMove(char grid[3][3]);
int checkingWin(char grid[3][3]);
int checkdraw(char grid[3][3]);
void scoreBoard(int playerWin ,int compWin, char *name, int sizeOf);

int main() {
	
	char name[50];
	char grid[3][3];
	int counter = 1;
	int gameOver = 1;
	int playAgain = 1;
	int playerWin = 0;
	int compWin = 0;
	int sizeOf = 0;
	
	printf("Input your name here: ");
	gets(&name);

	sizeOf = strlen(name);

	do {
		intializeGrid(grid);
		counter = 1;
		gameOver = 1;

		while (gameOver == 1) {
			displayGrid(grid);

			if (counter == 1) {
				playerMove(grid);
			}
			else {
				compMove(grid);
			}

			if (checkingWin(grid)) {
				displayGrid(grid);
				if (counter == 1) {
					printf("Congratulations %s, YOU ARE THE WINNER!\n", name);
					playerWin++;
				}
				else {
					printf("Computer wins!\n");
					compWin++;
				}
				gameOver = 0;
			}

			else if (checkdraw(grid)) {
				displayGrid(grid);
				printf("Draw\n");
				gameOver = 0;
			}

			if (counter == 1) {
				counter = 2;
			}
			else {
				counter = 1;
			}
		}
		scoreBoard(playerWin, compWin, &name, sizeOf);

		printf("\nDo you want to play again (1 for yes, 0 for no): ");
		scanf_s("%d", &playAgain);
	}

	while (playAgain == 1);

	printf("\nThanks for Playing\n");

	return 0;

}

//LC function to intialize the grid
void intializeGrid(char grid[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			grid[i][j] = ' ';
		}
	}
}

//LC  Function to display the grid
void displayGrid(char grid[3][3]) {
	printf("\n");
	printf("  1   2   3\n");
	printf("1 %c | %c | %c\n", grid[0][0], grid[0][1], grid[0][2]);
	printf(" ---+---+---\n");
	printf("2 %c | %c | %c\n", grid[1][0], grid[1][1], grid[1][2]);
	printf(" ---+---+---\n");
	printf("3 %c | %c | %c\n", grid[2][0], grid[2][1], grid[2][2]);
	printf("\n");
}

//LC Function for player move
void playerMove(char grid[3][3]) {
	int row, col;
	printf("Please enter your move: ");
	scanf_s("%d %d", &row, &col);
	row--;
	col--;
	if (validMove(grid, row, col)) {
		grid[row][col] = 'X';
	}
	else {
		printf("Invalid move. Try again.\n");
		playerMove(grid);
	}
}

//LC function to check if the move is valid
int validMove(char grid[3][3], int row, int col) {
	if (row < 0 || row > 2 || col < 0 || col > 2) {
		return 0;
	}
	if (grid[row][col] != ' ') {
		return 0;
	}

	return 1;
}

/*EA
	This gets the computer move
*/

void compMove(char grid[3][3]) {
	int row, col;

	srand(time(NULL));
	
	do {
	row = rand() % 3;
	col = rand() % 3;	
	}

	while(!validMove(grid, row, col));
	
	grid[row][col] = 'O';

}

/*EA & LC
	Checking win
*/
int checkingWin(char grid[3][3]) {

	//row
	for (int i = 0; i < 3; i++) {
		if ((grid[i][0] == 'X' || grid[i][0] == 'O') &&
			grid[i][0] == grid[i][1] &&
			grid[i][1] == grid[i][2]) {
			return 1;
		}
	}
	
	//col
	for (int j = 0; j < 3; j++) {
		if ((grid[0][j] == 'X' || grid[0][j] == 'O') &&
			grid[0][j] == grid[1][j] &&
			grid[1][j] == grid[2][j]) {
			return 1;
		}
	}
	
	//diagonals
	if ((grid[0][0] == 'X' || grid[0][0] == 'O') &&
		grid[0][0] == grid[1][1] &&
		grid[1][1] == grid[2][2]) {
		return 1;
	}
	
	if ((grid[0][2] == 'X' || grid[0][2] == 'O') &&
		grid[0][2] == grid[1][1] &&
		grid[1][1] == grid[2][0]) {
		return 1;
	}

		return 0;
	
}

/* EA
	checking draw
*/

int checkdraw(char grid[3][3]) {

	for (int i = 0; i < 3; i++)
	{
			for (int j = 0; j < 3; j++) {
				if (grid[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

void scoreBoard(int playerWin, int compWin, char *name, int sizeOf) {


	printf("\n\t\tScoreboard\t\t\n");
	for (int i = 0; i < sizeOf; i++) {
		printf("%c", *(name+i));
	}
	printf("'s Wins: %d\t\t Computer's Wins: %d\n", playerWin, compWin);

}

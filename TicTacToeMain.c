#include <stdio.h>

void intializeGrid(char grid[3][3]);
void displayGrid(char grid[3][3]);
void playerMove(char grid[3][3]);

int main() {
	
	char grid[3][3];
	int counter = 1;
	int gameOver = 1;
	
	intializeGrid(grid);

	displayGrid(grid);
	

}

void intializeGrid(char grid[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			grid[i][j] = ' ';
		}
	}
}

//Function to display the grid
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

void playerMove(char grid[3][3]) {
	int row, col;
	printf("Please enter your move: ");
	scanf_s("%d %d", &row, &col);
	row--;
	col--;
}
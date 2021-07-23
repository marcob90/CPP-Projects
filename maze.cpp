#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAZE_SIZE 20

void mazeTraverse(char [][MAZE_SIZE], char *const, const int);
void printGrid(const char[][MAZE_SIZE], const int);
void mazeGenerator(char [][MAZE_SIZE], const int);
void initGrid(char [][MAZE_SIZE], const int);

char *startPtr;
char *endPtr;

enum Direction{
	NORTH,
	EAST,
	WEST,
	SOUTH,
};


int main(){
	char mazeGrid[MAZE_SIZE][MAZE_SIZE];
    
    initGrid(mazeGrid, MAZE_SIZE);
    mazeGenerator(mazeGrid, MAZE_SIZE);
    *startPtr = 'X';
    printGrid(mazeGrid, MAZE_SIZE);
	mazeTraverse(mazeGrid, startPtr, MAZE_SIZE);
	return 0;
}

void mazeGenerator(char grid [][MAZE_SIZE], const int size){
	int checkDefault(int [][MAZE_SIZE], const int);
	void printChessboard(int[][MAZE_SIZE], const int);
	enum Verse{
		HORIZONTAL,
		VERTICAL,
		DEFAULT, 
		EDGE
	}verse;
	
	int v[MAZE_SIZE][MAZE_SIZE];
	int startRow, endRow;
	int incrementRow, incrementColumn;
	int row, column;
	int flag = 0;
	int counter = 0;
	
	srand(time(NULL));
	startRow = rand() % (size - 2) + 1;
	
	startPtr = &grid[startRow][0];
	*startPtr = '.';
	
	for(row = 0; row < size; row++)
		for(column = 0; column < size; column++){
			if(row == 0 || row == size - 1)
				v[row][column] = EDGE;
			else if(column == 0 || column == size - 1)
				v[row][column] = EDGE;
			else
				v[row][column] = DEFAULT;
		}
	
	row = startRow;
	column = 1;
	grid[row][column] = '.';

	while(checkDefault(v, size)){
		if(v[row + 1][column] == DEFAULT)
			v[row + 1][column] = HORIZONTAL;
		if(v[row - 1][column] == DEFAULT)
			v[row - 1][column] = HORIZONTAL;
		if(v[row][column + 1] == DEFAULT)
			v[row][column + 1] = VERTICAL;
		if(v[row][column - 1] == DEFAULT)
			v[row][column - 1] = VERTICAL;
			
		do{
			for(row = column = 0; grid[row][column] != '.'; row = rand() % (size - 2) + 1 , column = rand() % (size - 2) + 1){
			//empty body
			}
			incrementRow = (rand() % 3) - 1;
			incrementColumn = (rand() % 3) - 1;
		}while(
		   grid[row + incrementRow][column + incrementColumn] != '#' || 
	       v[row + incrementRow][column + incrementColumn] == EDGE || 
		   abs(incrementRow) == abs(incrementColumn) ||
		   (incrementRow != 0 && v[row + incrementRow][column] == VERTICAL) ||
		   (incrementColumn != 0 && v[row][column + incrementColumn] == HORIZONTAL) ||
		   (incrementRow != 0 && grid[row + incrementRow][column - 1] == '.' && grid[row][column - 1] == '.') ||
		   (incrementRow != 0 && grid[row + incrementRow][column + 1] == '.' && grid[row][column + 1] == '.') ||
		   (incrementColumn != 0 && grid[row - 1][column + incrementColumn] == '.' && grid[row - 1][column] == '.') ||
		   (incrementColumn != 0 && grid[row + 1][column + incrementColumn] == '.' && grid[row + 1][column] == '.'));
		
		if(incrementRow == 0){
			if(grid[row][column + 2*incrementColumn] == '#'){
				grid[row][column + incrementColumn] = '.';
				row += incrementRow;
				column += incrementColumn;
				continue;
			}
		}
		else{
			if(grid[row + 2*incrementRow][column] == '#'){
				grid[row + incrementRow][column] = '.';
				row += incrementRow;
				column += incrementColumn;
				continue;
			}
		}
	}
	
	do{
		endRow = rand() % (size - 2) + 1;
	}while(grid[endRow][size - 2] == '#');
	
	endPtr = &grid[endRow][size - 1];
	*endPtr = '.';
}

void printChessboard(int c[][MAZE_SIZE], const int size){
	int i, j;
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			printf("%4d", c[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");
}

int checkDefault(int v[][MAZE_SIZE], const int s){
	int i, j;
	
	for(i = 0; i < s; i++){
		for(j = 0; j < s; j++)
			if(v[i][j] == 2)
				return 1;
	}
	return 0;
}

void mazeTraverse(char grid[][MAZE_SIZE], char *const currentElement, const int size){
	void printGrid(const char[][MAZE_SIZE], const int);
	static Direction direction = EAST;
	static int i;
	static int j = 0;
	static int flag = 1;
	
	if(flag){
		for(i = 0; &grid[i][j] != currentElement; i++){
			//empty body
		}
		flag = 0;
	}
		
	*currentElement = '.';
	
	switch(direction){
		case NORTH:
			if(grid[i][j + 1] == '#'){
				if(grid[i - 1][j] == '.'){
					i--;
				}
				else if(grid[i][j - 1] == '.'){
					j--;
					direction = WEST;
				}
				else if(grid[i + 1][j] == '.'){
					i++;
					direction = SOUTH;
				}
			}
			else{
				j++;
				direction = EAST;
			}
			break;
		
		case WEST:
			if(grid[i - 1][j] == '#'){
				if(grid[i][j - 1] == '.'){
					j--;
				}
				else if(grid[i + 1][j] == '.'){
					i++;
					direction = SOUTH;
				}
				else if(grid[i][j + 1] == '.'){
					j++;
					direction = EAST;
				}
			}
			else{
				i--;
				direction = NORTH;
			}
			break;
		
		case SOUTH:
			if(grid[i][j - 1] == '#'){
				if(grid[i + 1][j] == '.'){
					i++;
				}
				else if(grid[i][j + 1] == '.'){
					j++;
					direction = EAST;
				}
				else if(grid[i - 1][j] == '.'){
					i--;
					direction = NORTH;
				}
			}
			else{
				j--;
				direction = WEST;
			}
			break;
		
		case EAST:
			if(grid[i + 1][j] == '#'){
				if(grid[i][j + 1] == '.'){
					j++;
				}
				else if(grid[i - 1][j] == '.'){
					i--;
					direction = NORTH;
				}
				else if(grid[i][j - 1] == '.'){
					j--;
					direction = WEST;
				}
			}
			else{
				i++;
				direction = SOUTH;
			}
			break;		
	}
	grid[i][j] = 'X';
	
	printGrid(grid,size);
	
	if(&grid[i][j] != endPtr)
		mazeTraverse(grid, &grid[i][j], size);
}

void initGrid(char g[][MAZE_SIZE], const int s){
	int i, j; 
	
	for(i = 0; i < s; i++){
		for(j = 0; j < s; j++){
			g[i][j] = '#';
		}
	}
}

void printGrid(const char maze[][MAZE_SIZE], const int s){
	int i, j;
	
	for(i = 0; i < s; i++){
		for(j = 0; j < s; j++){
			printf("%5c", maze[i][j]);
		}
		printf("\n\n");
	}
	printf("\n************************************************************\n\n");
}


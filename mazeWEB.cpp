/*
 *   Title: Pointers 723 : Generating Maze Randomly & Maze Traverse
 *   Author: aeriqusyairi
 *   Date: Mac5 2012
 *   Algorithm: Depth First Search
 *   
 *      create a CellStack (LIFO) to hold a list of cell locations
 *      set TotalCells = number of cells in grid
 *      choose a cell at random and call it CurrentCell
 *      set VisitedCells = 1 
 *
 *      while VisitedCells < TotalCells 
 *
 *         find all neighbors of CurrentCell with all walls intact
 *         if one or more found
 *            choose one at random
 *            knock down the wall between it and CurrentCell
 *            push CurrentCell location on the CellStack
 *            make the new cell CurrentCell
 *            add 1 to VisitedCells 
 *         else
 *            pop the most recent cell entry off the CellStack
 *            make it CurrentCell 
 *         endIf 
 *
 *      endWhile
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
#define MAX 101 //maxRow + maxColumn + 1
#define WALL 1 //indicate the wall is up
#define PATH 0 //indicate the cells is previous path
#define CELLS 2500 //row * column
#define START 3 //start position
#define END 4 //end position
  
void mazeGenerator( int wMaze[ MAX ][ MAX ], int wSize ); //generate the maze
void startEnd( int wMaze[ MAX ][ MAX ], int wSize, int* wSRow, int* wSCol );//generate start and end position
int mazeTraverse( int maze[ MAX ][ MAX ], int currentRow, int currentColumn, int size );//Automatic maze solver
void printMaze( int wMaze[ MAX ][ MAX ], int wSize );//display the maze
  
int main(void){
    
   int size = 3, sRow = 0, sCol = 0, state;
   int maze[ MAX ][ MAX ]; //maze array 
    
   printf("My Maze Generator\n*****************\n\n");
   printf("Input the size of your desired maze (3 to 50): ");
   do{
      if(size < 3 || size > 50)
         printf("Invalid size! Input again: ");
             
      scanf("%d", &size );//get the desired size from user
   }while(size < 3 || size > 50);
    
   mazeGenerator( maze, size );
   startEnd( maze, size, &sRow, &sCol );
   printMaze( maze, size );
   state = mazeTraverse( maze, sRow, sCol, size );
    
   if(state == 0)
      printf("Player found the exit\n\n");
     
   system("pause");
   return 0;
}
//////////////////
//MAZE GENERATOR//
//////////////////
void mazeGenerator( int wMaze[ MAX ][ MAX ], int wSize ){
    
   srand(time( 0 ));
    
   void initMaze( int wMaze[ MAX ][ MAX ] ); //initalize the maze array
   int walled( int wMaze[ MAX ][ MAX ], int wRow, int wCol );//check neighbouring cells
    
   initMaze( wMaze );
    
   int counter = 0, row = 1, col = 1, visited = 1;
   int validNeighbour, valid, randValid, move;
   int neighbourRow[ 4 ];
   int neighbourCol[ 4 ];
   int step[ 4 ];
   int btRow[ CELLS ]; //backtrack row array
   int btCol[ CELLS ];//backtrack column array
    
   //start backtracking with first cell
   btRow[ 0 ] = 1;
   btCol[ 0 ] = 1;
       
   /*while VisitedCells < TotalCells*/
   while(visited < wSize * wSize){
      //initialize
      validNeighbour = -1;
       
      /*find all neighbors of CurrentCell with all walls intact*/
      //NORTH neighbour
      if(row - 2 > 0 && walled( wMaze, row - 2, col )){
         validNeighbour++;
         neighbourRow[ validNeighbour ] = row - 2;
         neighbourCol[ validNeighbour ] = col;
         step[ validNeighbour ] = 1;       
      } 
      //WEST neighbour
      if(col - 2 > 0 && walled( wMaze, row, col - 2 )){
         validNeighbour++;
         neighbourRow[ validNeighbour ] = row;
         neighbourCol[ validNeighbour ] = col - 2;
         step[ validNeighbour ] = 2;         
      }
      //EAST neighbour
      if(col + 2 < wSize * 2 + 1 && walled( wMaze, row, col + 2 )){
         validNeighbour++;
         neighbourRow[ validNeighbour ] = row;
         neighbourCol[ validNeighbour ] = col + 2;
         step[ validNeighbour ] = 3;         
      } 
      //SOUTH neighbour
      //size * 2 + 1 -> size + wall + outerWall
      if(row + 2 < wSize * 2 + 1 && walled( wMaze, row + 2, col )){
         validNeighbour++;
         neighbourRow[ validNeighbour ] = row + 2;
         neighbourCol[ validNeighbour ] = col;
         step[ validNeighbour ] = 4;         
      }
       
      //if one or more found
      if(validNeighbour != -1){
         //choose one at random
         valid = validNeighbour + 1;//number of valid neighbour
         randValid = rand() % valid;
          
         //make the new cell CurrentCell
         row = neighbourRow[ randValid ];
         col = neighbourCol[ randValid ];
          
         counter++;
          
         btRow[ counter ] = row;
         btCol[ counter ] = col;
          
         move = step[ randValid ];
          
         //knock down the wall between it and CurrentCell
         //NORTH
         if(move == 1){
            wMaze[ row + 1 ][ col ] = PATH;        
         }
         //WEST
         else if(move == 2){
            wMaze[ row ][ col + 1 ] = PATH;     
         }
         //EAST
         else if(move == 3){
            wMaze[ row ][ col - 1 ] = PATH;     
         }
         //SOUTH
         else if(move == 4){
            wMaze[ row - 1 ][ col ] = PATH;     
         }
          
         //add 1 to VisitedCells
         visited++;
      }
      //if none found 
      else{
         //backtracking
         row = btRow[ counter ];
         col = btCol[ counter ];
         counter--;      
      }
        
   }                           
}
 
void initMaze( int wMaze[ MAX ][ MAX ] ){
   int a, b;
    
   for(a  = 0; a < MAX; a++){
      for(b = 0; b < MAX; b++){
         if(a % 2 == 0 || b % 2 == 0){
            wMaze[ a ][ b ] = WALL;   
         }else{
            wMaze[ a ][ b ] = PATH;      
         }
      }       
   }     
}
 
void printMaze( int wMaze[ MAX ][ MAX ], int wSize ){
   int row, col;
    
   printf("\n");
    
   for(row = 0; row < wSize * 2 + 1; row++){
            
      if(wMaze[ row ][ 0 ] == START)
         printf(" START -> ");
      else
         printf("          ");
          
      for(col = 0; col < wSize * 2 + 1; col++){
         if(wMaze[ row ][ col ] == WALL)
            printf("#");
         else if(wMaze[ row ][ col ] == START)
            printf("X");
         else
            printf(" ");        
      } 
       
      if(wMaze[ row ][ wSize * 2 ] == END)
         printf(" <- END");
                 
      printf("\n");
   }  
   printf("\n"); 
   system("pause");
   system("cls");     
}
 
int walled( int wMaze[ MAX ][ MAX ], int wRow, int wCol ){
   if(wMaze[ wRow - 1 ][ wCol ] == WALL &&
      wMaze[ wRow + 1 ][ wCol ] == WALL &&
      wMaze[ wRow ][ wCol + 1 ] == WALL &&
      wMaze[ wRow ][ wCol - 1 ] == WALL )
      return 1;
       
   return 0;    
}
////////////////////////////////////
//START AND END POSITION GENERATOR//
////////////////////////////////////
void startEnd( int wMaze[ MAX ][ MAX ], int wSize, int* wSRow, int* wSCol ){
   int start, end;
    
   do{
      start = rand() % (wSize * 2);//size + wall
   }while(start == 0 || wMaze[ start ][ 1 ] == WALL );
           
   do{
      end = rand() % (wSize * 2);   
   }while(end == 0 || wMaze[ end ][ (wSize * 2) - 1 ] == WALL);  
    
   wMaze[ start ][ 0 ] =  START;
   wMaze[ end ][ wSize * 2 ] = END; 
    
   *wSRow = start;
   *wSCol = 0; 
}
/////////////////
//MAZE TRAVERSE//
/////////////////
 
//global
int startingFlag = 1, direction = 0;
 
//enumeration
enum Stat { OVER, NOT_OVER };
 
int mazeTraverse( int maze[ MAX ][ MAX ], int currentRow, int currentColumn, int size ){
   //sub-function
   int gameOver( const int currentRow, const int currentColumn, int size );
   int move( int maze[ MAX ][ MAX ], int *currentRow, int *currentColumn, int *currentDirection, int size );
   void printPosition( int maze[ MAX ][ MAX ], const int currentRow, const int currentColumn, int size );
    
   enum Stat State;
    
   //check if game is over
   State = gameOver( currentRow, currentColumn, size );
 
   if(State == OVER && startingFlag == 0){
      printPosition( maze, currentRow, currentColumn, size );
      return OVER; //return OVER indicating succesfully find the exit
      //algorithm for if this function can't find the exit is not available       
   }
    
   //indicate player is ready to move
   if(startingFlag == 1){
      //print initial maze
      printf("Player's ready\n**************\n");
      printPosition( maze, currentRow, currentColumn, size );
      system("pause");
      system("cls");
      //set first direction based on starting position
      if(currentRow == 0){
         direction = 1;              
      }else if(currentRow == 11){
         direction = 0;      
      }else if(currentColumn == 0){
         direction = 2;      
      }else if(currentColumn == 11){
         direction == 3;      
      }
      startingFlag = 0;             
   }  
    
   //seek for next move
   move( maze, ¤tRow, ¤tColumn, &direction, size );
    
   //system("pause");//activate this to see each move
   system("cls");
    
   mazeTraverse( maze, currentRow, currentColumn, size );
    
   return OVER;   
}
 
/*seek for next move*/
enum Direction { NORTH, SOUTH, EAST, WEST };
int move( int maze[ MAX ][ MAX ], int *currentRow, int *currentColumn, int *currentDirection, int size ){
   int posibble[ 4 ] = { 0 };// 1 -> North; 2 -> South; 3 -> East; 4 -> West;
   int counter = 0;
    
   enum Direction Seek; 
    
   Seek = *currentDirection;
    
   /*move the player respect to current direction*/
    
   //cover the current position
   maze[ *currentRow ][ *currentColumn ] = 0;
    
   //move the player respect to current direction
   if(Seek == NORTH){
      //print direction
      printf("direction = NORTH\n");
      //move north
      *currentRow -= 1;
   }else if(Seek == SOUTH){
      //print direction
      printf("direction = SOUTH\n");
      //move south
      *currentRow +=1;      
   }else if(Seek == EAST){
      //print direction
      printf("direction = EAST\n");
      //move east
      *currentColumn += 1;   
   }else if(Seek == WEST){
      //print direction
      printf("direction = WEST\n");
      //move west
      *currentColumn -= 1;
   }
    
   maze[ *currentRow ][ *currentColumn ] = 3;
    
   //print each move
   printPosition( maze, *currentRow, *currentColumn, size );// print maze with player current position
    
   /*analyse for next direction*/
    
   //seek posibble direction
   printf("Seek next direction...\n\n");
   if(maze[ *currentRow - 1 ][ *currentColumn ] == 0 && Seek != SOUTH){
      printf("NORTH is possible\n");
      posibble[ 0 ] = 1;
      counter++;
   }
   if(maze[ *currentRow + 1 ][ *currentColumn ] == 0 && Seek != NORTH){
      printf("SOUTH is possible\n"); 
      posibble[ 1 ] = 1;
      counter++; 
   } 
   if(maze[ *currentRow ][ *currentColumn + 1 ] == 0 && Seek != WEST && 
      maze[ *currentRow ][ *currentColumn + 1 ] != 4){
      printf("EAST is possible\n"); 
      posibble[ 2 ] = 1; 
      counter++; 
   } 
   if(maze[ *currentRow ][ *currentColumn - 1 ] == 0 && Seek != EAST){
      printf("WEST is possible\n");  
      posibble[ 3 ] = 1;
      counter++; 
   } 
   //if exit found
   if(maze[ *currentRow ][ *currentColumn + 1 ] == 4 && Seek != WEST){
      printf("Exit found\n"); 
      posibble[ 2 ] = 1; 
      counter++; 
   } 
   printf("\n");
    
   //follow right wall
   //Direction { NORTH, SOUTH, EAST, WEST };
   if(counter == 1){
      if(posibble[ 1 ] == 1){//south
         *currentDirection = 1;
      }else if(posibble[ 2 ] == 1){//east
         *currentDirection = 2;
      }else if(posibble[ 0 ] == 1){//north
         *currentDirection = 0;      
      }else if(posibble[ 3 ] == 1){//west
         *currentDirection = 3;
      }
   }else if(counter == 2){
      if(posibble[ 2 ] == 1 && posibble[ 3 ] == 1){// posibble: EAST, WEST
         if(Seek == SOUTH){
            *currentDirection = 3;
         }else if(Seek == NORTH){
            *currentDirection = 2;      
         }                
      }else if(posibble[ 0 ] == 1 && posibble[ 1 ] == 1){// posibble: NORTH,SOUTH
         if(Seek == EAST){
            *currentDirection = 1;        
         }else if(Seek == WEST){
            *currentDirection = 0;      
         }
      }else if(posibble[ 0 ] == 1 && posibble[ 3 ] == 1){// NORTHWEST
            *currentDirection = 0;        
      }else if(posibble[ 0 ] == 1 && posibble[ 2 ] == 1){// NORTHEAST
            *currentDirection = 2;        
      }else if(posibble[ 1 ] == 1 && posibble[ 2 ] == 1){// SOUTHEAST
            *currentDirection = 1;        
      }else if(posibble[ 1 ] == 1 && posibble[ 3 ] == 1){// SOUTHWEST
            *currentDirection = 3;        
      }
   }else if(counter == 3){
      if(Seek == NORTH){
         *currentDirection = 2;        
      }else if(Seek == SOUTH){
         *currentDirection = 3;      
      }else if(Seek == EAST){
         *currentDirection = 1;      
      }else if(Seek == WEST){
         *currentDirection = 0;      
      }
   }else if(counter == 0){
      //dead end
      if(Seek == NORTH){
         *currentDirection = 1;         
      }else if(Seek == SOUTH){
         *currentDirection = 0;      
      }else if(Seek == EAST){
         *currentDirection = 3;      
      }else if(Seek == WEST){
         *currentDirection = 2;      
      }
   }
    
}
 
/*check if game is over*/
int gameOver( const int currentRow, const int currentColumn, int size ){
   if(currentColumn == size * 2){
      return OVER;
   }else{
      return NOT_OVER;      
   }
   printf("position: (%d, %d)\n\n", currentRow, currentColumn);
}
 
/*print current position*/
 void printPosition( int maze[ MAX ][ MAX ], const int currentRow, const int currentColumn, int size ){
    int row, col;
    
   printf("\n");
    
   for(row = 0; row < size * 2 + 1; row++){
            
      if(maze[ row ][ 0 ] == START)
         printf(" START -> ");
      else
         printf("          ");
          
      for(col = 0; col < size * 2 + 1; col++){
         if(maze[ row ][ col ] == WALL)
            printf("#");
         else if(maze[ row ][ col ] == START)
            printf("X");
         else
            printf(" ");        
      } 
       
      if(maze[ row ][ size * 2 ] == END)
         printf(" <- END");
                 
      printf("\n");

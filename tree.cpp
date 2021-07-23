#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {
	struct treeNode *leftPtr;
	int data;
	struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode( TreeNodePtr *, const int );
void inOrder( TreeNodePtr );
void preOrder( TreeNodePtr );
void postOrder( TreeNodePtr );
int depth( TreeNodePtr );
TreeNodePtr binaryTreeSearch( TreeNodePtr, const int );

int main( void )
{
	int i;
	int item;
	int objectSearch;
	TreeNodePtr rootPtr = NULL;
	
	srand(time(NULL));
	
	printf( "The nodes placed in the tree are:\n" );
	
	for( i = 1; i <= 20; i++ ){
		item = rand() % 15;
		printf("%3d", item);
		insertNode( &rootPtr, item );
	}
	
	printf("\n\nDepth of the tree is: %d\n", depth( rootPtr ) );
	
	printf( "\n\nThe inOrder traversal is\n" );
	inOrder( rootPtr );
	
	printf( "\n\nThe preOrder traversal is\n" );
	preOrder( rootPtr );
	
	printf( "\n\nThe postOrder traversal is\n" );
	postOrder( rootPtr );
	
	printf( "\n\nInsert a value to search: " );
	scanf( "%d", &objectSearch );
	
    ( binaryTreeSearch( rootPtr, objectSearch ) == NULL ) ? printf( "Value not found\n" ) : printf( "Value found" );
	return 0;
}

void insertNode( TreeNodePtr *treePtr, const int value )
{
	if( *treePtr == NULL ){
		*treePtr = ( TreeNodePtr )malloc( sizeof( TreeNode ) );
		
		( *treePtr )->data = value;
		( *treePtr )->leftPtr = NULL;
		( *treePtr )->rightPtr = NULL;
	}
	else if( value < ( *treePtr )->data )
		insertNode( &( ( *treePtr )->leftPtr ), value);
	else if( value > ( *treePtr )->data )
		insertNode( &( ( *treePtr )->rightPtr ), value);
	else
		printf( "dup" );
}

int depth( TreeNodePtr treePtr )
{
	int findMax( const int, const int );
	
	int leftDepth, rightDepth;
	
	if( treePtr != NULL){
		leftDepth = 1 + depth( treePtr->leftPtr );
		rightDepth = 1 + depth( treePtr->rightPtr );
		return findMax( leftDepth, rightDepth );
	}
	else
		return 0;
}

TreeNodePtr binaryTreeSearch( TreeNodePtr treePtr, const int key )
{
	if( treePtr != NULL){
		if( treePtr->data == key )
			return treePtr;
		else if( treePtr->data > key )
			return binaryTreeSearch( treePtr->leftPtr, key );
		else
			return binaryTreeSearch( treePtr->rightPtr, key );
	}
	
	return NULL;
}

void inOrder( TreeNodePtr treePtr )
{
	if( treePtr != NULL){
		inOrder( treePtr->leftPtr );
		printf( "%3d", treePtr->data );
		inOrder( treePtr->rightPtr ); 
	}
}

void preOrder( TreeNodePtr treePtr )
{
	if( treePtr != NULL){
		printf( "%3d", treePtr->data );
		preOrder( treePtr->leftPtr );
		preOrder( treePtr->rightPtr ); 
	}
}

void postOrder( TreeNodePtr treePtr )
{
	if( treePtr != NULL){
		postOrder( treePtr->leftPtr );
		postOrder( treePtr->rightPtr ); 
		printf( "%3d", treePtr->data );
	}
}

int findMax( const int a, const int b )
{
	int max = ( a > b ) ? a : b;
	
	return max;
}







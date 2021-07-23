#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct treeNode {
	struct treeNode *leftPtr;
	char *data;
	struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode( TreeNodePtr *, char * );
void inOrder( TreeNodePtr );
void preOrder( TreeNodePtr );
void postOrder( TreeNodePtr );
int depth( TreeNodePtr );

int main( void )
{
	TreeNodePtr rootPtr = NULL;
	char sentence[] = "change will not come if we wait "
					  "for some other person or some other time. " 
					  "we are the ones we've been waiting for. "
					  "we are the change that we seek.";
	char *tokenPtr;
	
	tokenPtr = strtok( sentence, " " );
	
	printf( "The nodes placed in the tree are:\n" );
	
	while( tokenPtr != NULL ){
		printf( "%s ", tokenPtr );
		insertNode( &rootPtr, tokenPtr );
		tokenPtr = strtok( NULL, " " );
	}
	
	printf("\n\nDepth of the tree is: %d\n", depth( rootPtr ) );
	
	printf( "\n\nThe inOrder traversal is\n" );
	inOrder( rootPtr );
	
	printf( "\n\nThe preOrder traversal is\n" );
	preOrder( rootPtr );
	
	printf( "\n\nThe postOrder traversal is\n" );
	postOrder( rootPtr );
	return 0;
}

void insertNode( TreeNodePtr *treePtr, char *value )
{
	if( *treePtr == NULL ){
		*treePtr = ( TreeNodePtr )malloc( sizeof( TreeNode ) );
		
		( *treePtr )->data = value;
		( *treePtr )->leftPtr = NULL;
		( *treePtr )->rightPtr = NULL;
	}
	else if( strcmp( value, ( *treePtr )->data ) <= 0 )
		insertNode( &( ( *treePtr )->leftPtr ), value);
	else if( strcmp( value, ( *treePtr )->data ) > 0 )
		insertNode( &( ( *treePtr )->rightPtr ), value);
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

void inOrder( TreeNodePtr treePtr )
{
	if( treePtr != NULL){
		inOrder( treePtr->leftPtr );
		printf( "%s ", treePtr->data );
		inOrder( treePtr->rightPtr ); 
	}
}

void preOrder( TreeNodePtr treePtr )
{
	if( treePtr != NULL){
		printf( "%s ", treePtr->data );
		preOrder( treePtr->leftPtr );
		preOrder( treePtr->rightPtr ); 
	}
}

void postOrder( TreeNodePtr treePtr )
{
	if( treePtr != NULL){
		postOrder( treePtr->leftPtr );
		postOrder( treePtr->rightPtr ); 
		printf( "%s ", treePtr->data );
	}
}

int findMax( const int a, const int b )
{
	int max = ( a > b ) ? a : b;
	
	return max;
}







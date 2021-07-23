#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


#define ARENA_SIZE 10240


// Allocate from here instead of the heap
// arena = 0xF100
int arena[ARENA_SIZE];

// This must return a pointer between [arena - arena+ARENA_SIZE)
int * arena_alloc(size_t size);
void arena_free(int *ptr);

int main() {
	int a[5] = {0.0};
	int *aPtr = a;
    int * alloc_1 = arena_alloc(10); // alloc_1 = arena
    int * alloc_2 = arena_alloc(1024); // alloc_2 = arenal
    
    printf("%d %d\n", sizeof( alloc_1[0] ), sizeof( alloc_2 ) );
    printf("%d %d\n", sizeof( a ), sizeof( aPtr ) );
    
    arena_free(alloc_2);
    
    
    return 0;
}

int * arena_alloc( size_t size )
{
    int *finalPtr;
    
    // allocate 10 bytes
    // malloc returns 0x100
    
    finalPtr = (int*)calloc( size, sizeof( int ) );
    
    return finalPtr;
} 

void arena_free( int *ptr )
{
    free( ptr );
}

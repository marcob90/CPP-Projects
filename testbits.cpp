#include <stdio.h>
#include <math.h>

int main(){
	int N = 5;
    int largest = 0;
    int shift = 0;
    unsigned int temp = N;
    int i;
    for (i = 1; i < 5; ++i) {
        unsigned int index = (temp & 1);
        temp = ((temp >> 1) | (index << 29));
        printf("%d\n", temp);
        if (temp > largest) {
            largest = temp;
            shift = i;
        }
    }
    printf("%d\n", shift);
    return 0;
}
	

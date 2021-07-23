#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

void printArray(const int [][EXAMS], const int, const int);
void minimum(const int [][EXAMS], const int, const int);
void maximum(const int [][EXAMS], const int, const int);
void average(const int [][EXAMS], const int, const int);

int main(){
	const int studentGrades[STUDENTS][EXAMS] = {{22, 19, 24, 28},
												{27, 26, 29, 31},
												{26, 30, 23, 20}};
												
	void (*processGrades[4])(const int [][EXAMS], const int, const int) = {printArray, minimum, maximum, average};
	int choice;
	
	
	
	while(choice >= 0 && choice < 4){
		printf("\nEnter a choice:\n0 Print the array of grades\n1 Find the minimum grade\n2 Find the maximum grade\n"	
			   "3 Print the average on all tests for each student\n4 End program\n");
		
		scanf("%d", &choice);
		
		if(choice >= 0 && choice < 4)
			processGrades[choice](studentGrades, STUDENTS, EXAMS);
	}
	
	printf("Program is terminated\n");
												
    return 0;
}

void printArray(const int array[][EXAMS], const int pupils, const int grades){
	int i, j;
	
	for(i = 0; i < pupils; i++){
		for(j = 0; j < grades; j++)
			printf("%5d", array[i][j]);
		printf("\n");
	}
}

void minimum(const int array[][EXAMS], const int pupils, const int grades){
	int i, j, min = 100;
	
	printf("Minimum grade is: ");
	
	for(i = 0; i < pupils; i++){
		for(j = 0; j < grades; j++)
			if(array[i][j] < min)
				min = array[i][j];
	}
	
	printf("%d\n", min);
}

void maximum(const int array[][EXAMS], const int pupils, const int grades){
	int i, j, max = 0;
	
	printf("Maximum grade is: ");
	
	for(i = 0; i < pupils; i++){
		for(j = 0; j < grades; j++)
			if(array[i][j] > max)
				max = array[i][j];
	}
	
	printf("%d\n", max);
}

void average(const int array[][EXAMS], const int pupils, const int grades){
	int i, j;
	int sum;
	float result;
	
	printf("Average for each student:\n");
	
	for(i = 0, sum = 0; i < pupils; i++, sum = 0){
		for(j = 0; j < grades; j++){
			sum += array[i][j];
		}
		result = (float)sum / EXAMS;
		printf("student[%d]: %.2f\n", i, result);
	}
}

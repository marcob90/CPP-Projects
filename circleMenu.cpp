#include <stdio.h>
#define PI 3.14

void circumference(const double);
void area(const double);
void volume(const double);

int main(){
	void (*calculate[3])(const double) = {circumference, area, volume};
	double radius;
	int i;
	
	printf("Enter a radius: ");
	scanf("%lf", &radius);
	
	for(i = 0; i < 3; i++)
		calculate[i](radius);
	
	return 0;
}

void circumference(const double r){
	double length = r * PI * 2;
	
	printf("The circumference of a circle of radius %.2lf is %.2lf\n", r, length);
}

void area(const double r){
	double circleArea = r * PI * r;
	
	printf("The area of a circle of radius %.2lf is %.2lf\n", r, circleArea);
}

void volume(const double r){
	double vol = (4.0 / 3) * PI * r * r * r;
	
	printf("The volume of a circle of radius %.2lf is %.2lf\n", r, vol);
}

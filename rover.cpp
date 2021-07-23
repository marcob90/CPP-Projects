#include <iostream>

using namespace std;

bool isValid(char *command){
	int rCounter = 0;
	int lCounter = 0;
	bool isMoving = false;
	
	if(command == NULL) return false;
	
	for(int i = 0; command[i] != '\0'; i++){
		if(i >= 4) return false;
		if(command[i] == 'F') isMoving = true;
		else if(command[i] == 'R') rCounter++;
		else if(command[i] == 'L') lCounter++;
		else return false;
	}
	
	if(!isMoving) return true;
	if(rCounter == lCounter) return false;
	else return true;
}

int main(){
	char *com = "LRLR\0";
	
	cout << isValid(com);
}

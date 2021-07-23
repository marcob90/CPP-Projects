#include <iostream>
#include <string>

#include "RecipesBook.h"

using namespace std;

RecipesBook::RecipesBook( string name ){
	setRecipeName( name );
}

void RecipesBook::setRecipeName( string name ){
	if(name.length() <= 25)
		recipeName = name;
	else
		recipeName = name.substr(0, 25);
}

string RecipesBook::getRecipeName(){
	return recipeName;
}

void RecipesBook::displayMessage(){
	cout << "Welcome to the recipes book. Let's talk about:\n" << getRecipeName() << endl;
}



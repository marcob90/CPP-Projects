#include <iostream>
#include <string>

#include "RecipesBook.h"

using namespace std;

int main()
{
	string nameOfRecipe;
	
	cout << "Insert new recipe\n";
	getline(cin, nameOfRecipe);
	cout << endl;
	
	RecipesBook newRecipe(nameOfRecipe);
	
	newRecipe.displayMessage();	
}

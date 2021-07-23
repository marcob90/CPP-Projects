#ifndef RECIPES_H
#define RECIPES_H

#include <string>

using namespace std;

class RecipesBook
{
	public:
		RecipesBook( string );
		void setRecipeName( string );
		string getRecipeName();
		void displayMessage();
		
	private:
		string recipeName;
		int a;
};

#endif


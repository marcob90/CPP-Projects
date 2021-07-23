#include <bits/stdc++.h>
#define M 5
#define N 6

using namespace std;

void nullifyRow(int mat[][N], int row){
	for(int j = 0; j < N; j++){
		mat[row][j] = 0;
	}
}

void nullifyColumn(int mat[][N], int col){
	for(int i = 0; i < M; i++){
		mat[i][col] = 0;
	}
}

/*void setZeroes(int mat[][N]){
	//sc = O(N)
	bool row[M] = {0};
	bool column[N] = {0};
	
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(mat[i][j] == 0){
				row[i] = true;
				column[j] = true;
			}
		}
	}
	
	//Nullify rows
	for(int i = 0; i < M; i++){
		if(row[i]) nullifyRow(mat, i);
	}
	
	//Nullify columns
	for(int j = 0; j < N; j++){
		if(column[j]) nullifyColumn(mat, j);
	}
}*/

void setZeroes(int mat[][N]){
	//space complexity = O(1)
	bool firstColumn = false;
	bool firstRow = false;
		
	//visit first column
	for(int i = 0; i < M; i++){
		if(mat[i][0] == 0) {
			firstColumn = true;
			break;
		}
	}
	
	//visit first row
	for(int j = 0; j < N; j++){
		if(mat[0][j] == 0){
			firstRow = true;
			break;
		}
	}
	
	//visit rest of the matrix
	for(int i = 1; i < M; i++){
		for(int j = 1; j < N; j++){
			if(mat[i][j] == 0){
				mat[i][0] = 0;
				mat[0][j] = 0;
			}
		}
	}
	
	//Nullify rows
	for(int i = 1; i < M; i++){
		if(mat[i][0] == 0) nullifyRow(mat, i);
	}
	
	//Nullify columns
	for(int j = 1; j < N; j++){
		if(mat[0][j] == 0) nullifyColumn(mat, j);
	}
	
	//Nullify first row
	if(firstRow) nullifyRow(mat, 0);
	
	//Nullify first column
	if(firstColumn) nullifyColumn(mat, 0);
}

int main(){
	int mat[M][N];
	srand(time(NULL));
	
	for(auto& rows: mat){
	    for(auto& elem: rows){
	        elem = rand() % 10;
	        cout << elem << " ";
	    }
	    cout << endl;
	}
	cout << endl;
	
	setZeroes(mat);
	
	for(auto& rows: mat){
	    for(auto& elem: rows){
	        cout << elem << " ";
	    }
	    cout << endl;
	}
}

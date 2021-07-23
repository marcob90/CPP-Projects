#include <bits/stdc++.h>
#define N 10

using namespace std;

/*void rotateMatrix(int mat[][N]){
	//time complexity O(N^2) and space complexity O(N^2)
	int newMat[N][N];
	
	for(int row = 0; row < N; row++){
		for(int col = 0; col < N; col++){
			int newRow = col;
			int newCol = N - row - 1;
			
			newMat[newRow][newCol] = mat[row][col];
		}
	}
	
	memcpy(mat, newMat, sizeof(newMat));
}*/

void rotateMatrix(int mat[][N]){
	//time complexity O(N^2) and space complexity O(1)
	
	for(int layer = 0; layer < N / 2; layer++){
		int first = layer;
		int last = N - layer - 1;
		for(int i = first; i < last; i++){
			int top = mat[first][i]; //save top
			
			//left -> top
			mat[first][i] = mat[N - i - 1][first];
			
			//bottom -> left
			mat[N - i - 1][layer] = mat[last][N - i - 1];
			
			//right -> bottom
			mat[last][N - i - 1] = mat[i][last];
			
			//top -> right
			mat[i][last] = top;
		}
	}
}

int main(){
	int mat[N][N];
	srand(time(NULL));
	
	for(auto& rows: mat){
	    for(auto& elem: rows){
	        elem = rand() % 10;
	        cout << elem << " ";
	    }
	    cout << endl;
	}
	cout << endl;
	
	rotateMatrix(mat);
	
	for(auto& rows: mat){
	    for(auto& elem: rows){
	        cout << elem << " ";
	    }
	    cout << endl;
	}
}

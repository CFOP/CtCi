#include <bits/stdc++.h>

void rotateMatrix(int **matrix, int n){
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			std::swap(matrix[i][j], matrix[j][i]);
		}
	}
	for(int i=0; i<n/2; i++){
		for(int j=0; j<n; j++){
			std::swap(matrix[i][j], matrix[n-i-1][j]);
		}
	}
}

int main(){
    int N=4;
    int ** matrix = new int*[N];

    for(int i=0; i<N; i++)
        matrix[i]=new int[N];

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            matrix[i][j]=N*i+j+1;

    rotateMatrix(matrix, N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}

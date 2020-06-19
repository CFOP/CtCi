#include <bits/stdc++.h>

void checkZero(int **matrix, int m, int n){
	//lastPosition
	for(int i=1; i<std::max(m, n); i++){
		if(i<m){
			for(int j=0;j<n; j++){
				if(matrix[i][j]==0)
					matrix[i][0]=0;
			}
		}
		if(i<n){
			for(int j=0;j<m; j++){
				if(matrix[j][i]==0)
					matrix[0][i]=0;
			}
		}
	}

}

void putZero(int **matrix, int m, int n){
	//putZeros
	for(int i=1; i<std::max(m, n); i++){
		if(i<m){
			if(matrix[i][0]==0)
				for(int j=0;j<n; j++){
						matrix[i][j]=0;
				}
		}
		if(i<n){
			if(matrix[0][i]==0)
				for(int j=0;j<m; j++){
						matrix[j][i]=0;
				}
		}
	}
}

void zeroMatrix(int **matrix, int m, int n){

	bool yZero=false, xZero=false;
	//zeroPosition
	for(int i=0;i<m; i++){
		if(matrix[i][0]==0)
			yZero=true;
	}

	for(int i=0;i<n; i++){
		if(matrix[0][i]==0)
			xZero=true;
	}

	checkZero(matrix, m, n);
	putZero(matrix, m, n);

	//putZeroPosition
	if(yZero)
		for(int i=0;i<m; i++){
			matrix[i][0]=0;
		}
	if(xZero)
		for(int i=0;i<n; i++){
			matrix[0][i]=0;
		}
}

int main(){
    int m, n;
    std::cin>>m>>n;

    int **matrix = new int*[m];
    for(int i=0; i<m; i++)
        matrix[i]=new int[n];

    for(int i=0;i<m; i++)
        for(int j=0;j<n; j++){
            std::cin>>matrix[i][j];
        }

    zeroMatrix(matrix, m, n);

    std::cout<<"\n";
    for(int i=0;i<m; i++){
        for(int j=0;j<n; j++){
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<"\n";
    }

    return 0;
}

/*
3 4
1 2 3 4
1 0 4 5
4 5 6 7

3 4
1 2 3 4
0 0 4 5
4 5 6 0
*/

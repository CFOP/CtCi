pair<int, int> sortedMatrixSearch(vector<vector<int>>> matrix, int n){

	int y =0, r = matrix.size();
	while(y+1<r){
		int m = (y+r)/2;
		if(matrix[m][0] <= n)
			y = m;
		else
			r = m;
	}

	int x =0;
	r = matrix.size();

	while(x+1<r){
		int m = (x+r)/2;
		if(matrix[y][m] <= n)
			x = m;
		else
			r = m;
	}

	if(matrix[y][x] == n)
		return {y, x};
	return {-1, -1};
}

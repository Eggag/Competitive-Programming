ll C[55][55]; //change the values if needed

rep(i, 55){
	C[i][0] = C[i][i] = 1LL;
	repn(j, 1, i){
		C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]); //might need MOD
	}
}
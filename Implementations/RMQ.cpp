//NOTE: gets MLE for n = 1e6

int n;
int a[mxN], mn[logn][mxN], mx[logn][mxN];
 
int minQ(int l, int r) { // [l; r)
	int t = __lg(r - l);
	return min(mn[t][l], mn[t][r - (1 << t)]);
}
 
int maxQ(int l, int r) { // [l; r)
	int t = __lg(r - l);
	return max(mx[t][l], mx[t][r - (1 << t)]);
}

//in main

memcpy(mx[0], a, sizeof a);
memcpy(mn[0], a, sizeof a);
for(int l = 0; l < logn - 1; l++){
	for(int i = 0; i + (2 << l) <= n; i++){
		mn[l + 1][i] = min(mn[l][i], mn[l][i + (1 << l)]);
		mx[l + 1][i] = max(mx[l][i], mx[l][i + (1 << l)]);
	}
}

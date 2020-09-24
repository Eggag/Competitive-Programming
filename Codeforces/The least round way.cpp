#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int a[1005][1005], b[1005][1005], g[1005][1005];
int x, y;

void go(int s, int s1, int f, int f1){
	while(s != f) cout << "D", s++;
	while(s1 != f1) cout << "R", s1++;
	return;
}

void go1(int l[1005][1005], int g, int h){
	if(g == 1 && h == 1) return;
	if(l[g - 1][h] < l[g][h - 1]){
		go1(l, g - 1, h);
		cout << "D";
	}
	else{
		go1(l, g, h - 1);
		cout << "R";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	memset(a, 1, sizeof(a));
	memset(b, 1, sizeof(b));
	a[0][1] = b[0][1] = 0;
	a[1][0] = b[1][0] = 0;
	a[0][0] = b[0][0] = 0;
	bool fl = false;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int u = 0, v = 0;
			cin >> g[i][j];
			if(!g[i][j]) fl = true, x = i, y = j;
			if(!g[i][j]) continue;
			while(g[i][j] % 2 == 0) g[i][j] /= 2, u++;
			while(g[i][j] % 5 == 0) g[i][j] /= 5, v++;
			a[i][j] = min(a[i][j - 1], a[i - 1][j]) + u;
			b[i][j] = min(b[i][j - 1], b[i - 1][j]) + v;
		}
	}	
	int ans = min(a[n][n], b[n][n]);
	if(fl) ans = min(1, ans);
	cout << ans << endl;
	if(ans == a[n][n]) go1(a, n, n);
	else if(ans == b[n][n]) go1(b, n, n);
	else{
		go(1, 1, x, y);
		go(x, y, n, n);
	}
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

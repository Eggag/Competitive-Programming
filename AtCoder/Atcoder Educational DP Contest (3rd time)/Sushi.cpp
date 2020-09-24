#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
const int maxn = 305;

double dp[maxn][maxn][maxn];
int a[3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n){
		int x;
		cin >> x;
		a[x - 1]++;
	}
	rep(k, n + 1) rep(j, n + 1) rep(i, n + 1){
		int tc = i + j + k;
		if(!tc || tc > n) continue;
		dp[i][j][k] = 1;
		if(i) dp[i][j][k] += dp[i - 1][j][k] * i / n;
		if(j) dp[i][j][k] += dp[i + 1][j - 1][k] * j / n;
		if(k) dp[i][j][k] += dp[i][j + 1][k - 1] * k / n;
		dp[i][j][k] *= (double) n / tc;
	}	
	cout << setprecision(15) << dp[a[0]][a[1]][a[2]] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

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
const int inf = 1 << 29;

int cost[30][30];
string s;
int L;
int dp[105][105][30], v[105][105][30];

int dfs(int p, int k, int l){
	if(k < 0) return -inf;
	if(p == L) return 0;
	if(v[p][k][l]) return dp[p][k][l];
	int res = -inf;
	rep(c, 26){
		res = max(res, cost[l][c] + dfs(p + 1, k - (s[p] == 'a' + c ? 0 : 1), c));
	}
	v[p][k][l] = 1;
	return dp[p][k][l] = res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int K;
	cin >> s >> K;
	L = s.length();
	int n;
	cin >> n;
	memset(cost, 0, sizeof(cost));
	rep(i, n){
		char a, b;
		cin >> a >> b;
		cin >> cost[a - 'a'][b - 'a'];
	}
	memset(v, 0, sizeof(v));
	cout << dfs(0, K, 26) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

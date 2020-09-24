#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int res[1005][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<vi> ans(4);
	ans[0] = {8, 9, 1, 13};
	ans[1] = {3, 12, 7, 5};
	ans[2] = {0, 2, 4, 11};
	ans[3] = {6, 10, 15, 14};
	int cnt = 0;
	for(int i = 0; i < n; i += 4){
		for(int j = 0; j < n; j += 4){
			int add = 16 * cnt;
			repn(k, i, i + 4) repn(l, j, j + 4) res[k][l] = ans[k - i][l - j] + add;
			cnt++;
		}
	}
	rep(i, n){
		rep(j, n) cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

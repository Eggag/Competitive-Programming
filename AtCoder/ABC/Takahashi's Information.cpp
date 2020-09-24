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

int g[5][5];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	rep(i, 3) rep(j, 3) cin >> g[i][j];	
	rep(i, 150) rep(j, 150) rep(k, 150){
		int f = 0;
		if(i == 0 && j == 1 && k == 0) f = 1;
		int v1 = g[0][0] - i, v2 = g[0][1] - i, v3 = g[0][2] - i;
		int v4 = g[1][0] - j, v5 = g[1][1] - j, v6 = g[1][2] - j;
		if(!(v1 == v4 && v2 == v5 && v3 == v6)) continue;
		int v7 = g[2][0] - k, v8 = g[2][1] - k, v9 = g[2][2] - k;
		if(v1 == v7 && v2 == v8 && v3 == v9){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

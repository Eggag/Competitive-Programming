#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
#define debug2(x, y) debug(x), debug(y)
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
const int mxN = 505;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

char uwu[mxN][mxN], owo[mxN][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	rep(i, n) rep(j, m) uwu[i][j] = owo[i][j] = '.';
	rep(j, m) owo[0][j] = owo[n - 1][j] = '#';
	rep(i, n) owo[i][0] = owo[i][m - 1] = '#';
	repn(j, 1, m - 1){
		if(j & 1){
			repn(i, 1, n - 1){
				uwu[i][j] = '#';
				if(s[i][j] == '#') owo[i][j] = '#';
			}
		}
		else{
			int cnt = 0;
			repn(i, 1, n - 1){
				owo[i][j] = '#';
				if(s[i][j] == '#') uwu[i][j] = '#', cnt++;
			}
			if(!cnt) owo[1][j] = '.', uwu[1][j] = '#';
		}
	}
	rep(i, n){
		rep(j, m) cout << uwu[i][j];
		cout << '\n';
	}
	cout << '\n';
	rep(i, n){
		rep(j, m) cout << owo[i][j];
		cout << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

string s[1005];
int c[1005][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, n) cin >> s[i];
	rep(i, 1005) rep(j, 1005) c[i][j] = 0;
	rep(i, n - 2) rep(j, m - 2){
		//check if we color anything we shouldn't
		bool f = 1;
		rep(k, 3) rep(l, 3){
			if(s[i + l][j + k] != '#' && (l != 1 || k != 1)) f = 0;
		}
		if(f) rep(k, 3) rep(l, 3) if(l != 1 || k != 1) c[i + l][j + k] = 1;
	}
	rep(i, n) rep(j, m){
		if(s[i][j] == '#' && !c[i][j]){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

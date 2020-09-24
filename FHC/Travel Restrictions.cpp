#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int d[55][55];

void solve(){
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	rep(i, n) rep(j, n) d[i][j] = 0;
	rep(i, n) d[i][i] = 1;
	rep(i, n){
		if(s[i] == 'Y'){
			if(i && t[i - 1] == 'Y') d[i - 1][i] = 1;
			if(i < (n - 1) && t[i + 1] == 'Y') d[i + 1][i] = 1;
		}
		if(t[i] == 'Y'){
			if(i && s[i - 1] == 'Y') d[i][i - 1] = 1;
			if(i < (n - 1) && s[i + 1] == 'Y') d[i][i + 1] = 1;
		}
	}
	rep(k, n) rep(i, n) rep(j, n) d[i][j] |= d[i][k] & d[k][j];
	rep(i, n){
		rep(j, n){
			if(d[i][j]) cout << 'Y';
			else cout << 'N';
		}
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ":" << endl;
		solve();
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

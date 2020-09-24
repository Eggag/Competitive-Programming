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

char ans[105][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	set<pi> bad;
	rep(i, n) rep(j, n) rep(k, n) rep(l, n) if(s[i][j] == 'o' && s[k][l] == '.'){
		//we can't move from (i, j) to (k, l)
		bad.insert(mp(k - i, l - j));
	}
	//now we need to check if all x's can be reached
	rep(i, 105) rep(j, 105) ans[i][j] = '.';
	rep(i, n) rep(j, n) if(s[i][j] == 'x'){
		//we need to make sure it is attacked by smth
		int f = 0;
		rep(k, n) rep(l, n) if(s[k][l] == 'o'){
			if(!bad.count(mp(i - k, j - l))) f = 1;
		}
		if(!f){
			cout << "NO" << endl;
			return 0;
		}
	}
	for(int i = -(n - 1); i < n; i++) for(int j = -(n - 1); j < n; j++){
		if(!bad.count(mp(i, j))){
			ans[n - 1 + i][n - 1 + j] = 'x';
		}
	}
	ans[n - 1][n - 1] = 'o';
	cout << "YES" << endl;
	rep(i, 2 * n - 1){
		rep(j, 2 * n - 1) cout << ans[i][j];
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

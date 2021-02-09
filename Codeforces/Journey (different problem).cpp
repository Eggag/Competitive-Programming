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
const int mxN = 3e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int l[mxN][2], r[mxN][2];

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	rep(i, n) rep(j, 2) r[i][j] = l[i][j] = 0;
	rep(i, n){
		if(s[i] == 'L'){
			l[i][0] = 1;
			if(i) l[i][0] = max(l[i][0], 1 + l[i - 1][1]);
		}
		else{
			l[i][1] = 1;
			if(i) l[i][1] = max(l[i][1], 1 + l[i - 1][0]);
		}
	}
	for(int i = n - 1; i >= 0; i--){
		if(s[i] == 'L'){
			r[i][0] = 1;
			if(i < (n - 1)) r[i][0] = max(r[i][0], 1 + r[i + 1][1]);
		}
		else{
			r[i][1] = 1;
			if(i < (n - 1)) r[i][1] = max(r[i][1], 1 + r[i + 1][0]);
		}
	}
	rep(i, n + 1){
		cout << (i ? l[i - 1][0] : 0) + (i < n ? r[i][1] : 0) + 1 << " ";
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

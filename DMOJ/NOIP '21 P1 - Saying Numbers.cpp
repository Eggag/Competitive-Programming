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
const int mxN = 1e7 + 50005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int p[mxN], nxt[mxN];

bool chk(int num){
	while(num){
		if(num % 10 == 7) return 1;
		num /= 10;
	}
	return 0;
}

void sieve(){
	repn(i, 2, mxN) if(!p[i] && chk(i)){
		p[i] = 1;
		for(int j = i + i; j < mxN; j += i) p[j] = 1;
	}
}

void solve(){
	int r;
	cin >> r;
	if(p[r]) cout << "-1\n";
	else cout << nxt[r] << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	sieve();
	vi ls;
	rep(i, mxN) if(!p[i]) ls.pb(i);
	rep(i, ls.size() - 1) nxt[ls[i]] = ls[i + 1];
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

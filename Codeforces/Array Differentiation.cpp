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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	rep(i, n) if(!a[i]){
		cout << "YES\n";
		return;
	}
	rep(i, n) rep(j, n) if(i != j) if(abs(a[i]) == abs(a[j])){
		cout << "YES\n";
		return;
	}
	rep(i, 1 << n){
		if(i > ((1 << n) - (i + 1))) continue;
		rep(j, n) if(i & (1 << j)) a[j] *= -1;
		rep(j, 1 << n){
			int sm = 0;
			rep(l, n) if(j & (1 << l)) sm += a[l];
			rep(l, n) if(!(j & (1 << l))) if(abs(sm) == abs(a[l])){
				cout << "YES\n";
				return;
			}
		}
		rep(j, n) if(i & (1 << j)) a[j] *= -1;
	}
	cout << "NO\n";
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

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int s, b;
	cin >> s >> b;
	vi a(s);
	rep(i, s) cin >> a[i];
	vector<pi> base(b);
	vi c(b);
	rep(i, b){
		cin >> base[i].fi >> base[i].se;
	}
	sort(all(base));
	rep(i, b) c[i] = base[i].fi;
	vector<ll> sum(b + 1, 0);
	rep(i, b){
		sum[i + 1] = sum[i] + base[i].se;
	}
	rep(i, s){
		//use binary search
		int x = upper_bound(c.begin(), c.end(), a[i]) - c.begin();
		cout << sum[x] << " \n"[i == s - 1];
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

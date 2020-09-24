#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	ll h;
	cin >> n >> h;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i];
	vector<ll> cnt(n, 0);
	rep(i, n){
		if(i) cnt[i] = cnt[i - 1] + a[i];
		else cnt[i] = a[i];
	}
	for(int i = n - 1; i >= 0; i--){
		vi cur;
		rep(j, i + 1) cur.pb(a[j]);
		sort(all(cur));
		reverse(all(cur));
		ll h1 = 0;
		for(int i = 0; i < cur.size(); i += 2){
			h1 += cur[i];
		}
		if(h1 <= h){
			cout << i + 1 << endl;
			return 0;
		}
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

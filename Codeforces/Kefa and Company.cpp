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
	ll d;
	cin >> n >> d;
	vector<pair<int, ll>> a(n);
	rep(i, n) cin >> a[i].fi >> a[i].se;
	sort(all(a));
	vector<ll> sum(n + 1, 0);
	repn(i, 1, n + 1) sum[i] = sum[i - 1] + a[i - 1].se;
	ll ans = 0;
	rep(i, n){
		int l = i;
		int r = n - 1;
		//fuck ub and lb
		while(l <= r){
			int cur = (l + r) / 2;
			if(a[cur].fi >= (a[i].fi + d)) r = cur - 1;
			else l = cur + 1;
		}
		int pos = r;
		ans = max(ans, sum[pos + 1] - sum[i]);
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

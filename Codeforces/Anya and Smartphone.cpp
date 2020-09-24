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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n), b(m);
	vector<ll> cnt(n, 0); //how much its position is decreased by
	vi pos(n);
	rep(i, n) cin >> a[i], a[i]--, pos[a[i]] = i;
	rep(i, m) cin >> b[i], b[i]--;
	ll ans = 0;
	rep(i, m){
		ans += (pos[b[i]] / k) + 1;
		if(pos[b[i]] != 0){
			int one = b[i];
			int two = a[pos[b[i]] - 1];
			swap(a[pos[b[i]]], a[pos[b[i]] - 1]);
			pos[one]--;
			pos[two]++;
		}
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

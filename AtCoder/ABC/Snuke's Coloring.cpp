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

struct HASH{
	size_t operator () (const pair<int, int> &x) const {
		return hash<long long>()(((long long)(x.first)) ^ (((long long)(x.second)) << 32));
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll h, w, n;
	cin >> h >> w >> n;
	unordered_map<pi, ll, HASH> m;
	unordered_map<pi, int, HASH> vis; //to not count anything twice
	vector<ll> cnt(10, 0);
	vi a(n), b(n);
	rep(i, n){
		cin >> a[i] >> b[i];
		m[mp(a[i], b[i])]++;
	}
	rep(i, n){
		for(int j = a[i] - 2; j <= a[i]; j++){
			for(int k = b[i] - 2; k <= b[i]; k++){
				//check if it is a valid square (and not visited)
				if(!(j >= 1 && k >= 1 && (j + 2) <= h && (k + 2) <= w && !vis[mp(j, k)])) continue;
				//count
				int num = 0;
				repn(l, j, j + 3) repn(p, k, k + 3) if(m[mp(l, p)]) num++;
				vis[mp(j, k)] = 1;
				cnt[num]++;
			}
		}
	}
	ll tot = 0;
	repn(i, 1, 10) tot += cnt[i];
	cnt[0] = (ll)(1LL * ((h - 2) * (w - 2)) - tot);
	rep(i, 10) cout << cnt[i] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

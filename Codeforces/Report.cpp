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

vector<pi> cnt[200005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi a(n);
	rep(i, n) cin >> a[i];
	rep(i, m){
		int t, r;
		cin >> t >> r;
		cnt[r - 1].pb(mp(t, i));
	}
	multiset<int> b;
	rep(i, n) b.insert(a[i]);
	int lat = -1;
	vi ans(n, 0);
	int cr = -1e9;
	for(int i = n - 1; i >= 0; i--){
		if(cnt[i].size()){
			if(cnt[i][(int)(cnt[i].size()) - 1].se > cr){
				cr = cnt[i][(int)(cnt[i].size()) - 1].se;
				lat = cnt[i][(int)(cnt[i].size()) - 1].fi;
			}
		}
		if(lat == -1){
			ans[i] = a[i];	
			b.erase(b.find(a[i]));
		}
		else if(lat == 2){
			ans[i] = *b.begin();
			b.erase(b.begin());
		}
		else{
			auto it = b.end();
			it--;
			ans[i] = *it;
			b.erase(it);
		}
	}
	rep(i, n) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

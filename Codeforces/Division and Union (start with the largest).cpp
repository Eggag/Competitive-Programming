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

bool intersect(int l, int r, pi seg){
	if(l >= seg.fi && l <= seg.se) return 1;
	if(r >= seg.fi && r <= seg.se) return 1;
	if(seg.fi >= l && seg.fi <= r) return 1;
	if(seg.se >= l && seg.se <= r) return 1;
	return 0;
}

void solve(){
	int n;
	cin >> n;
	vi l(n), r(n);
	int mx = -1;
	int b = -1;
	rep(i, n){
		cin >> l[i] >> r[i];
		if((r[i] - l[i]) > mx){
			mx = r[i] - l[i];
			b = i;
		}
	}
	pi one = {l[b], r[b]};
	vi ans(n, 2);
	ans[b] = 1;
	vi v(n, 0);
	int cnt = 1;
	while(cnt){
		cnt = 0;
		rep(i, n) if(i != b){
			if(intersect(l[i], r[i], one) && !v[i]){
				cnt++;
				ans[i] = 1;
				v[i] = 1;
				one.fi = min(l[i], one.fi);
				one.se = max(r[i], one.se);
			}
		}
	}
	int g = 0;
	rep(i, n) if(ans[i] == 2) g = 1;
	if(!g){
		cout << -1 << endl;
		return;
	}
	rep(i, n) cout << ans[i] << " ";
	cout << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/

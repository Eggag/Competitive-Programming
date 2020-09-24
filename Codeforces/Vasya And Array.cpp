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

bool cmp(pair<int, pi> a, pair<int, pi> b){
	return a.se.fi < b.se.fi;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi t(m), l(m), r(m);
	vector<pair<int, pi>> p(m);
	vi cnt(n + 1, 0);
	rep(i, m){
		cin >> t[i] >> l[i] >> r[i];
		if(t[i] == 1) cnt[l[i] - 1]++, cnt[r[i] - 1]--;
		p[i].fi = t[i];
		p[i].se.fi = l[i];
		p[i].se.se = r[i];
	}
	sort(all(p), cmp);
	rep(i, m){
		t[i] = p[i].fi;
		l[i] = p[i].se.fi;
		r[i] = p[i].se.se;
	}
	partial_sum(all(cnt), cnt.begin());
	vi ans(n);
	rep(i, n) ans[i] = 1;
	int cur = 3 * n;
	rep(i, m) if(!t[i]){
		int f = 0;
		repn(j, l[i] - 1, r[i] - 1){
			if(!cnt[j]){
				if(j < (n - 1)){
					if(ans[j] <= ans[j + 1]) ans[j] += cur--;
					f = 1;
					break;
				}
			}	
		}
		if(!f){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	rep(i, ans.size()) cout << ans[i] << " ";
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

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

bool cmp(pair<pi, pi> a, pair<pi, pi> b){
	return a.se.fi < b.se.fi;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pair<pi, pi>> s(n);
	vi ans(n + 1, 0);
	rep(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		s[i] = mp(mp(i, a), mp(b, c));
	}
	sort(all(s), cmp);
	rep(i, n){
		int cnt = s[i].se.se;
		repn(j, s[i].fi.se, s[i].se.fi){
			if(ans[j] == 0){
				cnt--;
				ans[j] = s[i].fi.fi + 1;
				if(!cnt) break;
			}
		}
		if(cnt){
			cout << -1 << endl;
			return 0;
		}
		ans[s[i].se.fi] = m + 1;
	}
	repn(i, 1, n + 1) cout << ans[i] << " ";
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

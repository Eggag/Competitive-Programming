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
	int n, k;
	cin >> n >> k;
	vector<pi> p;
	rep(i, n){
		int a, b;
		cin >> a >> b;
		p.pb({a, 1});
		p.pb({b, -1});
	}
	sort(all(p));
	vector<pi> ans;
	int bal = 0, f = 1, pr = -1;
	rep(i, 2 * n){
		int cur = 0;
		int ind = i, cur1 = 0;
		while(i < (2 * n) && p[i].fi == p[ind].fi){
			cur += p[i].se;
			cur1 += ((p[i].se == 1) ? 1 : 0);
			i++;
		}
		i--;
		if((bal + cur1) >= k && bal < k && (bal + cur) < k){
			ans.pb({p[i].fi, p[i].fi});
		}
		if(bal >= k && (bal + cur) < k){
			ans.pb({pr, p[ind].fi});
			f = 1;
		}
		bal += cur;
		if(bal >= k && f) f = 0, pr = p[i].fi;
	}
	cout << ans.size() << endl;
	for(pi x : ans) cout << x.fi << " " << x.se << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

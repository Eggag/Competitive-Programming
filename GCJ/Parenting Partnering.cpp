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

string solve(){
	int n;
	cin >> n;
	vector<pair<pi, int>> p(n);
	vi cnt(5005, 0);
	rep(i, n){
		cin >> p[i].fi.fi >> p[i].fi.se;
		p[i].fi.se--;
		p[i].se = i;
		cnt[p[i].fi.fi]++, cnt[p[i].fi.se + 1]--;
	}
	partial_sum(all(cnt), cnt.begin());
	rep(i, 5005) if(cnt[i] > 2) return "IMPOSSIBLE";
	sort(all(p));
	vector<char> ans(n, 'J');
	ans[p[0].se] = 'C';
	pi lst = p[0].fi;
	repn(i, 1, n){
		if(p[i].fi.fi > lst.se){
			lst = p[i].fi;
			ans[p[i].se] = 'C';
		}
	}
	string ans1 = "";
	for(char x : ans) ans1 += x;
	return ans1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": " << solve() << endl;
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

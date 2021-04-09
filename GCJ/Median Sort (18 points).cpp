#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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

int t, n ,q;
int a, b;

int ask(int i, int j, int k){
	cout << i << " " << j << " " << k << endl;
	int ret;
	cin >> ret;
	if(ret == -1) exit(0);
	return ret;
}

bool cmp(int c, int d){
	int nw = ask(c, d, a);
	if(nw == d) return 1;
	return 0;
}

bool cmp1(int c, int d){
	int nw = ask(c, d, a);
	if(nw == d) return 0;
	return 1;
}

bool cmp2(int c, int d){
	int nw = ask(c, d, b);
	if(nw == d) return 0;
	return 1;
}

void solve(){
	int r1 = ask(1, 2, 3);
	a = 2, b = 3;
	if(r1 == 2) a = 1, b = 3;
	if(r1 == 3) a = 1, b = 2;
	vi l, mid, r;
	repn(i, 4, n + 1){
		int cr = ask(a, b, i);
		if(cr == a) l.pb(i);
		else if(cr == b) r.pb(i);
		else mid.pb(i);
	}
	mid.pb(r1);
	//answer is sort(l) + a + sort(mid) + b + sort(r)
	sort(all(l), cmp);
	sort(all(mid), cmp1);
	sort(all(r), cmp2);
	vi ans;
	rep(i, l.size()) ans.pb(l[i]);
	ans.pb(a);
	rep(i, mid.size()) ans.pb(mid[i]);
	ans.pb(b);
	rep(i, r.size()) ans.pb(r[i]);
	vi res(n + 1, 0);
	rep(i, ans.size()) res[ans[i]] = i + 1;
	repn(i, 1, n + 1){
		cout << ans[i - 1];
		if(i != n) cout << " ";
		else cout << endl;
	}
	int re;
	cin >> re;
	if(re == -1) exit(0);
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> t >> n >> q;
	repn(i, 1, t + 1) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

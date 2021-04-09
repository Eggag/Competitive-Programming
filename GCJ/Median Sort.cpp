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

int t, n, q;
int cnt = 0;

int ask(int i, int j, int k){
	cout << i << " " << j << " " << k << endl;
	int ret;
	cin >> ret;
	cnt++;
	if(ret == -1) exit(0);
	return ret;
}

vi solve1(vi ls, int le, int ri){
	if(ls.size() < 2) return ls;
	int a = ls[0], b = ls[1];
	vi l, mid, r;
	if(le != -1){
		int r1 = ask(a, b, le);
		if(r1 == b) swap(a, b);
	}
	else{
		int r1 = ask(a, b, ri);
		if(r1 == a) swap(a, b);
	}
	//we just need to find a and b up to this point
	repn(i, 2, ls.size()){
		int cr = ask(a, b, ls[i]);
		if(cr == a) l.pb(ls[i]);
		else if(cr == b) r.pb(ls[i]);
		else mid.pb(ls[i]);
	}
	//answer is sort(l) + a + sort(mid) + b + sort(r)
	l = solve1(l, -1, a);
	mid = solve1(mid, a, -1);
	r = solve1(r, b, -1);
	vi ans;
	rep(i, l.size()) ans.pb(l[i]);
	ans.pb(a);
	rep(i, mid.size()) ans.pb(mid[i]);
	ans.pb(b);
	rep(i, r.size()) ans.pb(r[i]);
	return ans;
}

vi solve(vi ls){
	int r1 = ask(ls[0], ls[1], ls[2]);
	int a = ls[1], b = ls[2];
	if(r1 == ls[1]) a = ls[0], b = ls[2];
	if(r1 == ls[2]) a = ls[0], b = ls[1];
	vi l, mid, r;
	repn(i, 3, ls.size()){
		int cr = ask(a, b, ls[i]);
		if(cr == a) l.pb(ls[i]);
		else if(cr == b) r.pb(ls[i]);
		else mid.pb(ls[i]);
	}
	mid.pb(r1);
	//answer is sort(l) + a + sort(mid) + b + sort(r)
	l = solve1(l, -1, a);
	mid = solve1(mid, a, -1);
	r = solve1(r, b, -1);
	vi ans;
	rep(i, l.size()) ans.pb(l[i]);
	ans.pb(a);
	rep(i, mid.size()) ans.pb(mid[i]);
	ans.pb(b);
	rep(i, r.size()) ans.pb(r[i]);
	return ans;
}


int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> t >> n >> q;
	vi ls;
	rep(j, n) ls.pb(j + 1);
	repn(i, 1, t + 1){
		vi ans = solve(ls);
		rep(j, n){
			cout << ans[j];
			if(j == (n - 1)) cout << endl;
			else cout << " ";
		}
		int re;
		cin >> re;
		if(re == -1) exit(0);
	}
	if(cnt > 170 * t) assert(0);
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

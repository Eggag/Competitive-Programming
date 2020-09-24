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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m, s;
pi a[mxN];
int ans[mxN];
pair<int, pi> p[mxN];

bool cmp(pair<int, pi> a1, pair<int, pi> b1){
	return a1.se.fi < b1.se.fi;
}

bool check(int g){
	int fnd = 0, stu = 0;
	ll tot = 0LL;
	set<pi> st; //cost + index
	int ind = n - 1;
	for(int i = m - 1; i >= 0; i--){
		if(fnd) fnd--, ans[a[i].se] = stu;
		else{
			fnd = g - 1;
			while(ind >= 0 && p[ind].se.fi >= a[i].fi) st.insert(mp(p[ind].se.se, p[ind].fi)), ind--;
			if(!st.size()) return 0;
			pi cur = *st.begin();
			st.erase(st.begin());
			tot += cur.fi;
			stu = cur.se;
			ans[a[i].se] = stu;
		}
	}
	return (tot <= s);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> s;
	rep(i, m) cin >> a[i].fi, a[i].se = i;
	sort(a, a + m);
	rep(i, n) cin >> p[i].se.fi, p[i].fi = i;
	rep(i, n) cin >> p[i].se.se;
	sort(p, p + n, cmp);
	int l = 1, r = m;
	while(l < r){
		int mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	if(!check(l)) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		rep(i, m) cout << ans[i] + 1 << " ";
		cout << endl;
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

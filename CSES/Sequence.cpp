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

bool cmp(pair<int, pi> a, pair<int, pi> b){
	return a.fi > b.fi;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	priority_queue<pair<int, pi>, vector<pair<int, pi>>, function<bool(pair<int, pi>, pair<int, pi>)>> q(cmp);
	vi l(n, -1), r(n, -1), vis(n, 0);
	rep(i, n - 1) r[i] = i + 1;
	repn(i, 1, n) l[i] = i - 1;
	rep(i, n - 1) q.push(mp(max(a[i], a[i + 1]), mp(i, i + 1)));
	ll ans = 0LL;
	rep(i, n - 1){
		pair<int, pi> cur;
		while(true){
			cur = q.top();
			q.pop();
			if(!vis[cur.se.fi] && !vis[cur.se.se]) break;
		}
		ans += cur.fi;
		if(a[cur.se.fi] < a[cur.se.se]){
			vis[cur.se.fi] = 1;
			if(l[cur.se.fi] != -1) r[l[cur.se.fi]] = r[cur.se.fi];
			l[cur.se.se] = l[cur.se.fi];
			if(l[cur.se.se] != -1) q.push(mp(max(a[cur.se.se], a[l[cur.se.se]]), mp(l[cur.se.se], cur.se.se)));
		}
		else{
			vis[cur.se.se] = 1;
			if(r[cur.se.se] != -1) l[r[cur.se.se]] = l[cur.se.se];
			r[cur.se.fi] = r[cur.se.se];
			if(r[cur.se.fi] != -1) q.push(mp(max(a[cur.se.fi], a[r[cur.se.fi]]), mp(cur.se.fi, r[cur.se.fi])));
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

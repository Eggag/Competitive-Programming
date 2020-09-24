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

bool cmp(pi a, pi b){
	if(a.fi != b.fi) return a.fi < b.fi;
	return a.se < b.se;
}

void solve(int tc){
	int n, k;
	cin >> n >> k;
	priority_queue<pi, vector<pi>, function<bool(pi, pi)>> pq(cmp);
	if(n & 1) pq.push(mp(n / 2, n / 2));
	else pq.push(mp((n - 1) / 2, n / 2));
	repn(i, 1, k){
		pi cur = pq.top();
		//debug2(cur.fi, cur.se);
		pq.pop();
		int m = cur.fi;
		if(m & 1) pq.push(mp(m / 2, m / 2));
		else pq.push(mp((m - 1) / 2, m / 2));
		m = cur.se;
		if(m & 1) pq.push(mp(m / 2, m / 2));
		else pq.push(mp((m - 1) / 2, m / 2));
	}
	pi ans = pq.top();
	cout << "Case #" << tc << ": ";
	cout << ans.se << " " << ans.fi << endl;
}

int main(){
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1) solve(i);
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

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
const int mxN = 5005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;

int dist(int a, int b){
	if(b >= a) return b - a;
	return n - (a - b);
}

int cur = 0;
vi g[mxN];

bool cmp(int a, int b){
	return dist(cur, a) < dist(cur, b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	vi a(m), b(m);
	rep(i, m) cin >> a[i] >> b[i], g[a[i]].pb(b[i]);
	repn(i, 1, n + 1){
		cur = i;
		sort(all(g[i]), cmp);
	}
	repn(i, 1, n + 1){
		int ans = 0;
		int ind = i;
		int res = 0;
		int num = 0;
		rep(j, n){
			res = max(res, ans + (g[ind].size() ? ((int)(g[ind].size() - 1) * n) + dist(ind, g[ind][0]) : 0));
			num += g[ind].size();
			if(num == m) break;
			ind++;
			if(ind == (n + 1)) ind = 1;
			ans++;
		}
		cout << res << " ";
	}
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

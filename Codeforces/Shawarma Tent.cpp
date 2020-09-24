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
const int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, x, y;
	cin >> n >> x >> y;
	vector<pi> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	int ans = 0;
	pi best;
	rep(i, 8){
		int x1 = x + dx[i];
		int y1 = y + dy[i];
		int cnt = 0;
		rep(j, n){
			if((x1 >= min(p[j].fi, x)) && (x1 <= max(x, p[j].fi)) && (y1 >= min(y, p[j].se)) && (y1 <= max(y, p[j].se))) cnt++;	
		}
		if(cnt > ans){
			ans = cnt;
			best = mp(x1, y1);
		}
	}
	cout << ans << endl;
	cout << best.fi << " " << best.se << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

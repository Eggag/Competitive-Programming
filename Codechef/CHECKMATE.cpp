#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
#define x1 qwertyuiop
#define y1 asdfghjkl
#define x2 qwertyuiopz
#define y2 asdfghjklz
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int dx1[9] = {0, 0, 1, 1, 1, -1, -1, -1, 0};
const int dy1[9] = {1, -1, 1, 0, -1, 1, 0, -1, 0};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int x, y;
pi p[2];

bool valid(int a, int b){
	return max(a, b) <= 8 && min(a, b) >= 1;
}

bool check(int x1, int y1, int x2, int y2){
	int x3 = x, y3 = y;
	rep(i, 9){
		x3 += dx1[i];
		y3 += dy1[i];
		if(valid(x3, y3)){
			int f = 1;
			if(!(x3 == x1 && y3 == y1)){
				if(x3 == x1 || y3 == y1) f = 0;
			}
			if(!(x3 == x2 && y3 == y2)){
				if(x3 == x2 || y3 == y2) f = 0;
			}
			if(f) return 0;
		}
		x3 -= dx1[i];
		y3 -= dy1[i];
	}
	return 1;
}

void solve(){
	cin >> x >> y;
	vector<pi> p(2);
	rep(i, 2) cin >> p[i].fi >> p[i].se;
	rep(i, 2){
		rep(j, 4){
			int x1 = p[i].fi, y1 = p[i].se;
			while(valid(x1, y1) && mp(x1, y1) != p[1 - i]){
				x1 += dx[j];
				y1 += dy[j];
				if(check(x1, y1, p[1 - i].fi, p[1 - i].se)){
					cout << "YES\n";
					return;
				}
			}
		}
	}
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

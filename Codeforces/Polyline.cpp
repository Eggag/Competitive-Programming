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
#define y1 qwertyuiop

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

struct point{
	ll x, y;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	if((x == x1 && x == x2) || (y == y1 && y == y2)){
		cout << 1 << endl;
		return 0;
	}
	point a = {x, y}, b = {x1, y1}, c = {x2, y2};
	vector<point> p = {a, b, c};
	int f = 0;
	rep(i, 3) rep(j, 3) if(i != j){
		int k;
		rep(k1, 3) if(k1 != i && k1 != j) k = k1;
		if(p[i].x == p[j].x){
			if(p[k].y >= max(p[i].y, p[j].y) || p[k].y <= min(p[i].y, p[j].y)) f = 1;
		}
		if(p[i].y == p[j].y){
			if(p[k].x >= max(p[i].x, p[j].x) || p[k].x <= min(p[i].x, p[j].x)) f = 1;
		}
	}
	if(f) cout << 2 << endl;
	else cout << 3 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

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

struct point{
	ll x, y;
};

bool cmp(pair<point, int> a, pair<point, int> b){
	if(a.fi.x != b.fi.x) return a.fi.x < b.fi.x;
	else return a.fi.y < b.fi.y;
}

int ccw(point a, point b, point c){
	ll cur = ((c.y - a.y) * (b.x - a.x)) - ((b.y - a.y) * (c.x - a.x));
	if(!cur) return 0;
	else if(cur > 0) return 1;
	else return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<point, int>> a(n);
	rep(i, n){
		int b, c;
		cin >> b >> c;
		a[i] = mp((point){b, c}, i + 1);
	}
	sort(all(a), cmp);
	//rep(i, n){
	//	debug2(a[i].fi.x, a[i].fi.y);
	//}
	rep(i, n - 2){
		point p1 = a[i].fi;
		point p2 = a[i + 1].fi;
		point p3 = a[i + 2].fi;
		if(ccw(p1, p2, p3)){
			cout << a[i].se << " " << a[i + 1].se << " " << a[i + 2].se << endl;
			return 0;
		}
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

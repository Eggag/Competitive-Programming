#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl;
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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ld dist(ld x1, ld y1, ld x2, ld y2){
	return (ld)(sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ld r, x1, y1, x2, y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	cout << fixed << setprecision(15);
	if(dist(x1, y1, x2, y2) >= r){
		cout << x1 << " " << y1 << " " << r << endl;
		return 0;
	}
	ld rad = (ld)((r + dist(x1, y1, x2, y2)) / 2);
	if(dist(x1, y1, x2, y2) == 0){
		cout << x1 + (r / 2) << " " << y1 << " " << rad << endl;
		return 0;
	}
	ld dx = (x1 - x2);
	ld dy = (y1 - y2);
	ld d = dist(x1, y1, x2, y2);
	dx /= d, dy /= d;
	ld nx = x1 + dx * (rad - d);
	ld ny = y1 + dy * (rad - d);
	cout << nx << " " << ny << " " << rad << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

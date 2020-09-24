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

struct rect{
	ld x1, y1, x2, y2;
};

rect cross(rect x, rect y){
	rect ret;
	ret.x1 = max(y.x1, x.x1);
	ret.y1 = max(y.y1, x.y1);
	ret.x2 = min(y.x2, x.x2);
	ret.y2 = min(y.y2, x.y2);
	return ret;
}

bool valid(rect x){
	return ((x.x1 <= x.x2) && (x.y1 <= x.y2));
}

ld area(rect r){
	return (abs(r.y1 - r.y2) * abs(r.x1 - r.x2));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ld x, y, x1, y1;
	cin >> x >> y >> x1 >> y1;
	rect r = {x, y, x1, y1};
	cin >> x >> y >> x1 >> y1;
	rect r1 = {x, y, x1, y1};
	cin >> x >> y >> x1 >> y1;
	rect r2 = {x, y, x1, y1};
	/*
	repn(i, r.x1, r.x2 + 1){
		if((!inside(i, r.y1, r1) && !(inside(i, r.y1, r2)))){
			cout << "YES" << endl;
			return 0;
		}
	}
	repn(i, r.x1, r.x2 + 1){
		if((!inside(i, r.y2, r1) && !(inside(i, r.y2, r2)))){
			cout << "YES" << endl;
			return 0;
		}
	}
	repn(i, r.y1, r.y2 + 1){
		if((!inside(r.x1, i, r1) && !(inside(r.x1, i, r2)))){
			cout << "YES" << endl;
			return 0;
		}
	}
	repn(i, r.y1, r.y2 + 1){
		if((!inside(r.x2, i, r1) && !(inside(r.x2, i, r2)))){
			cout << "YES" << endl;
			return 0;
		}
	}
	*/
	ld a = area(r);
	rect r3 = cross(r, r1);
	if(valid(r3)){
		a -= area(r3);
	}
	rect r4 = cross(r, r2);
	if(valid(r4)){
		a -= area(r4);
	}
	rect r5 = cross(r3, r4);
	if(valid(r5)) a += area(r5);
	if(a > 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
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

struct rect{
	int x1, y1, x2, y2;
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
	return ((x.x1 < x.x2) && (x.y1 < x.y2));
}


struct TwoRectangles{
	string describeIntersection(vi a, vi b){
             	ios_base::sync_with_stdio(false);
	       	cin.tie(0);
		rect r = {a[0], a[1], a[2], a[3]};
		rect r1 = {b[0], b[1], b[2], b[3]};
		rect r2 = cross(r, r1);
		if(valid(r2)) return "rectangle";
		if((r2.y1 == r2.y2) && (r2.x1 == r2.x2)) return "point";
		if((r2.y1 == r2.y2 && r2.x1 < r2.x2) || (r2.x1 == r2.x2 && r2.y1 < r2.y2)) return "segment";
		return "none";
	}
};
/*
Things to look out for:
        - Integer overflows
        - Array bounds
        - Special cases
Be careful!
*/
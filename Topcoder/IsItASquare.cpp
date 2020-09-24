#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
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
#define sq(x) ((x) * (x))

struct point{
	int x, y;
};

bool cmp(point a, point b){
	if(a.x != b.x) return (a.x < b.x);
	else return (a.y < b.y);
}

bool same(point a, point b){
	return ((a.x == b.x) && (a.y == b.y));
}

int ccw(point a, point b, point c){
	ll cur = ((c.y - a.y) * (b.x - a.x)) - ((b.y - a.y) * (c.x - a.x));
	if(!cur) return 0;
	else if(cur > 0) return 1;
	else return -1;
}

ld dist(point a, point b){
	return (ld)(sqrt(sq(b.y - a.y) + sq(b.x - a.x)));
}

struct IsItASquare{
	string isSquare(vi x, vi y){
             	ios_base::sync_with_stdio(false);
	       	cin.tie(0);
		vector<point> p(4);
		rep(i, 4) p[i] = (point){x[i], y[i]};
		sort(all(p), cmp);
		point a = p[0], b = p[1], c = p[2], d = p[3];
        	ld d1 = dist(a, b);
		ld d2 = dist(c, d);
		ld d3 = dist(c, a);
		ld d4 = dist(d, b);
        	//debug2(d1, d2);
     		//debug2(d3, d4);
        	//check parallel to axes
        	if(a.x == b.x && b.y == d.y && d.x == c.x && a.y == c.y && d1 == d2 && d1 == d3 && d1 == d4) return "It's a square";
		if(!(((b.y - a.y) * (d.x - c.x)) == ((d.y - c.y) * (b.x - a.x)))) return "Not a square";
		if(!(((d.y - b.y) * (c.x - a.x)) == ((c.y - a.y) * (d.x - b.x)))) return "Not a square";
        	//debug2(abs((b.y - a.y) * (d.x - b.x)), abs((d.y - b.y) * (b.x - a.x)));
        	if(!(abs(d.y - b.y) == abs(b.x - a.x))) return "Not a square";
        	//debug2(abs((d.y - c.y) * (c.x - a.x)), abs((c.y - a.y) * (d.x - c.x)));
		if(!(abs(c.y - a.y) == abs(d.x - c.x))) return "Not a square";
		if(d1 == d2 && d1 == d3 && d1 == d4) return "It's a square";
		return "Not a square";
	}
};
/*
Things to look out for:
        - Integer overflows
        - Array bounds
        - Special cases
Be careful!
*/     
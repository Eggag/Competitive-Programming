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
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

struct point{
	ld x, y;
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

ld dist(point p, point p1){
	return sqrt(sq(p.x - p1.x) + sq(p.y - p1.y));
}

bool square(point p, point p1, point p2, point p3){
	if(!(p1.y > p.y)) return 0;
	if(!(p2.y > p3.y)) return 0;
	if(!(p1.x < p2.x)) return 0;
	if(!(p.x < p3.x)) return 0;
	ld d = dist(p, p1);
	ld d1 = dist(p1, p2);
	ld d2 = dist(p2, p3);
	ld d3 = dist(p3, p);
	if(!(d == d1 && d == d2 && d == d3)) return 0;
	if(abs(dist(p1, p3) - sqrt(sq(d) * 2)) > 1e-7) return 0;
	if(abs(dist(p, p2) - sqrt(sq(d) * 2)) > 1e-7) return 0;
	return 1;
}

bool rect(point p, point p1, point p2, point p3){
	if(!(p1.y > p.y)) return 0;
	if(!(p2.y > p3.y)) return 0;
	if(!(p1.x < p2.x)) return 0;
	if(!(p.x < p3.x)) return 0;
	ld d = dist(p, p1);
	ld d1 = dist(p1, p2);
	ld d2 = dist(p2, p3);
	ld d3 = dist(p3, p);
	if(d != d2 || d1 != d3) return 0;
	ld d4 = dist(p1, p3);
	ld d6 = sqrtl(sq(d) + sq(d1));
	if(abs(d4 - d6) > 1e-7) return 0;
	ld d5 = dist(p, p2);
	if(abs(d5 - d6) > 1e-7) return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	vector<point> p(8);
	cout << fixed << setprecision(6);
	rep(i, 8){
		ld a, b;
		cin >> a >> b;
		p[i] = (point){a, b};
	}
	vi s = {0, 1, 2, 3, 4, 5, 6, 7};
	do{
		if(square(p[s[0]], p[s[1]], p[s[2]], p[s[3]]) && rect(p[s[4]], p[s[5]], p[s[6]], p[s[7]])){
			cout << "YES" << endl;
			cout << s[0] + 1 << " " << s[1] + 1 << " " << s[2] + 1 << " " << s[3] + 1 << endl;
			cout << s[4] + 1 << " " << s[5] + 1 << " " << s[6] + 1 << " " << s[7] + 1 << endl;
			return 0;
		}	
	} while(next_permutation(all(s)));
	cout << "NO" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

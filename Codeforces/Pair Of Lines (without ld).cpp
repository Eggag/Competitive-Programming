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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	//saw this somewhere lol))
	//except easier((
	vector<point> a(n);
	rep(i, n){
		ll b, c;
		cin >> b >> c;
		a[i] = (point){b, c};
	}
	sort(all(a), cmp);
	//1 and 2
	if(a[0].x == a[1].x){
		vi vis(n, 0);
		vis[0] = 1, vis[1] = 1;
		repn(i, 2, n){
			if(a[i].x == a[0].x) vis[i] = 1;
		}
		int f = 0, fl = 1;
		point g, h;
		ll dx, dy;
		repn(i, 2, n) if(!vis[i]){
			if(!f){
				g = a[i];
				f++;
			}
			else if(f == 1){
				h = a[i];
				f++;
				if(g.x != h.x) dy = (g.y - h.y), dx = (g.x - h.x);
			}
			else{
				if((g.x == h.x && a[i].x == g.x) || ((g.x != h.x && a[i].x != h.x) && ((dx * (a[i].y - h.y)) == (dy * (a[i].x - h.x))))){
					//good
				}
				else{
					//bad
					fl = 0;
					break;
				}
			}
		}
		if(fl){
			cout << "YES" << endl;
			return 0;
		}
	}
	else{
		vi vis(n, 0);
		vis[0] = 1, vis[1] = 1;
		ll dx = (a[1].x - a[0].x), dy = (a[1].y - a[0].y);
		repn(i, 2, n){
			if((a[i].x != a[1].x) && ((dx * (a[i].y - a[1].y)) == (dy * (a[i].x - a[1].x)))){
				vis[i] = 1;
			}
		}	
		int fl = 1, f = 0;
		point p, p1;
		repn(i, 2, n) if(!vis[i]){
			if(!f){
				p = a[i];
				f++;
			}
			else if(f == 1){
				p1 = a[i];
				if(p.x != p1.x) dy = (p1.y - p.y), dx = (p1.x - p.x);
				f++;
			}
			else{
				if((p.x == p1.x && a[i].x == p.x) || ((p.x != p1.x && p1.x != a[i].x) && ((dx * (a[i].y - p1.y)) == (dy * (a[i].x - p1.x))))){
					//good
				}
				else{
					//bad
					fl = 0;
					break;
				}
			}

		}
		if(fl){
			cout << "YES" << endl;
			return 0;
		}
	}
	//1 and 3
	if(a[0].x == a[2].x){
		vi vis(n, 0);
		vis[0] = 1, vis[2] = 1;
		repn(i, 1, n){
			if(a[i].x == a[0].x) vis[i] = 1;
		}
		int f = 0, fl = 1;
		point g, h;
		ll dx, dy;
		repn(i, 1, n) if(!vis[i]){
			if(!f){
				g = a[i];
				f++;
			}
			else if(f == 1){
				h = a[i];
				f++;
				if(g.x != h.x) dy = (g.y - h.y), dx = (g.x - h.x);
			}
			else{
				if((g.x == h.x && a[i].x == g.x) || ((g.x != h.x && a[i].x != h.x) && ((((dx * (a[i].y - h.y)) == (dy * (a[i].x - h.x))))))){
					//good
				}
				else{
					//bad
					fl = 0;
					break;
				}
			}
		}
		if(fl){
			cout << "YES" << endl;
			return 0;
		}
	}
	else{
		vi vis(n, 0);
		vis[0] = 1, vis[2] = 1;
		ll dy = (a[2].y - a[0].y), dx = (a[2].x - a[0].x);
		repn(i, 1, n) if(!vis[i]){
			if((a[i].x != a[0].x) && (dx * (a[i].y - a[0].y)) == (dy * (a[i].x - a[0].x))){
				vis[i] = 1;
			}
		}	
		int fl = 1, f = 0;
		point p, p1;
		repn(i, 1, n) if(!vis[i]){
			if(!f){
				p = a[i];
				f++;
			}
			else if(f == 1){
				p1 = a[i];
				if(p.x != p1.x) dy = (p1.y - p.y), dx = (p1.x - p.x);
				f++;
			}
			else{
				if((p.x == p1.x && a[i].x == p.x) || ((p.x != p1.x && p1.x != a[i].x) && (dx * (a[i].y - p1.y)) == (dy * (a[i].x - p1.x)))){
					//good
				}
				else{
					//bad
					fl = 0;
					break;
				}
			}

		}
		if(fl){
			cout << "YES" << endl;
			return 0;
		}
	}
	//2 and 3
	if(a[1].x == a[2].x){
		vi vis(n, 0);
		vis[1] = 1, vis[2] = 1;
		rep(i, n){
			if(a[i].x == a[1].x) vis[i] = 1;
		}
		int f = 0, fl = 1;
		point g, h;
		ll dx, dy;
		rep(i, n) if(!vis[i]){
			if(!f){
				g = a[i];
				f++;
			}
			else if(f == 1){
				h = a[i];
				f++;
				if(g.x != h.x) dy = (g.y - h.y), dx = (g.x - h.x);
			}
			else{
				if((g.x == h.x && a[i].x == g.x) || ((g.x != h.x && a[i].x != h.x) && ((dx * (a[i].y - h.y)) == (dy * (a[i].x - h.x))))){
					//good
				}
				else{
					//bad
					fl = 0;
					break;
				}
			}
		}
		if(fl){
			cout << "YES" << endl;
			return 0;
		}
	}
	else{
		vi vis(n, 0);
		vis[1] = 1, vis[2] = 1;
		ll dy = (a[2].y - a[1].y), dx = (a[2].x - a[1].x);
		rep(i, n){
			if((a[i].x != a[1].x) &&  (dx * (a[i].y - a[1].y)) == (dy * (a[i].x - a[1].x))){
				vis[i] = 1;
			}
		}	
		int fl = 1, f = 0;
		point p, p1;
		rep(i, n) if(!vis[i]){
			if(!f){
				p = a[i];
				f++;
			}
			else if(f == 1){
				p1 = a[i];
				if(p.x != p1.x) dy = (p1.y - p.y), dx = (p1.x - p.x);
				f++;
			}
			else{
				if((p.x == p1.x && a[i].x == p.x) || ((p.x != p1.x && p1.x != a[i].x) && ((dx * (a[i].y - p1.y)) == (dy * (a[i].x - p1.x))))){
					//good
				}
				else{
					//bad
					fl = 0;
					break;
				}
			}

		}
		if(fl){
			cout << "YES" << endl;
			return 0;
		}
	}
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

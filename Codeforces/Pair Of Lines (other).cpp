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

int n;

struct point{
	ll x, y;
} a[100005];

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

bool test(int p, int p1){
	vi vis(n, 0);
	vis[p] = 1, vis[p1] = 1;
	rep(i, n) if(!vis[i]){
		if(!ccw(a[p], a[p1], a[i])) vis[i] = 1;
	}
	int c = 0;
	point p2, p3;
	rep(i, n) if(!vis[i]){
		if(!c){
			p2 = a[i];	
			c++;
		}
		else if(c == 1){
			p3 = a[i];
			c++;
		}
		else{
			if(!ccw(p2, p3, a[i])) vis[i] = 1;
			else return 0;
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n){
		ll b, c;
		cin >> b >> c;
		a[i] = (point){b, c};
	}
	if(test(0, 1) || test(0, 2) || test(1, 2)) cout << "YES" << endl;
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

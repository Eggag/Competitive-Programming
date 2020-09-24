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
	int cur = ((c.y - a.y) * (b.x - a.x)) - ((b.y - a.y) * (c.x - a.x));
	if(!cur) return 0;
	else if(cur > 0) return 1;
	else return -1;
}

void solve(){
	int n;
	cin >> n;
	vector<point> p(n);
	rep(i, n){
		int a, b;
		cin >> a >> b;
		p[i] = (point){a, b};
	}
	sort(all(p), cmp);
	int mx = 0;
	rep(i, n){
		if(i && p[i].y < mx){
			cout << "NO" << endl;
			return;
		}
		mx = max(mx, p[i].y);
	}
	point cur = (point){0, 0};
	string ans = "";
	rep(i, n){
		point goal = p[i];
		while(cur.x < goal.x) ans += 'R', cur.x++;
		while(cur.y < goal.y) ans += 'U', cur.y++;
	}
	cout << "YES" << endl;
	cout << ans << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/

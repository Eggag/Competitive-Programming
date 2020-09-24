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
	ll x, y, z;
	void read(){
		cin >> x >> y >> z;
	}
	void print(){
		cout << x << " " << y << " " << z << endl;
	}
};

bool cmp(pair<point, int> &a, pair<point, int> &b){
	if(a.fi.x != b.fi.x) return (a.fi.x < b.fi.x);
	if(a.fi.y != b.fi.y) return (a.fi.y < b.fi.y);
	if(a.fi.z != b.fi.z) return (a.fi.z < b.fi.z);
}

bool good(point a, point b, point c){
	if(!(c.x <= max(a.x, b.x) && c.x >= min(b.x, a.x))) return 1;
	if(!(c.y <= max(a.y, b.y) && c.y >= min(b.y, a.y))) return 1;
	if(!(c.z <= max(a.z, b.z) && c.z >= min(b.z, a.z))) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<point, int>> p(n);
	rep(i, n){
		p[i].fi.read();
		p[i].se = i + 1;
	}
	sort(all(p), cmp);
	while(p.size()){
		for(int i = 0; i < (int)p.size() - 1; i++){
			int f = 1;
			rep(j, p.size()) if(j != i && j != (i + 1)){
				if(!good(p[i].fi, p[i + 1].fi, p[j].fi)){
					f = 0;
					break;
				}
			}
			if(!f) continue;
			cout << p[i].se << " " << p[i + 1].se << endl;
			p.erase(p.begin() + i);
			p.erase(p.begin() + i);
			break;
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

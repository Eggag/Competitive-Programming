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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("jigin.txt", "r", stdin);
	freopen("jigout.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pair<ld, ld>> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	ld mnY = 1e9, mxY = 0;
	ld mnX = 1e9, mxX = 0;
	rep(i, n){
		mnY = min(mnY, p[i].se);
		mxY = max(mxY, p[i].se);
		mnX = min(mnX, p[i].fi);
		mxX = max(mxX, p[i].fi);
	}
	ld vMid = (mxX + mnX) / 2, hMid = (mxY + mnY) / 2;
	//reflect vertically
	map<pair<ld, ld>, int> m;
	vector<vector<pair<ld, ld>>> ans;
	vector<pair<ld, ld>> temp;
	rep(i, n){
		ld x = p[i].fi, y = p[i].se;
		if(x < vMid) x = vMid + (vMid - x);
		else x = vMid - (x - vMid);
		m[mp(x, y)]++;
		temp.pb(mp(x, y));
	}
	int f = 1;
	rep(i, n) if(!m[p[i]]){
		f = 0;
		break;
	}
	if(f) ans.pb(temp);
	//reflect horizontaly
	m.clear();
	temp.clear();
	rep(i, n){
		ld x = p[i].fi, y = p[i].se;
		if(y < hMid) y = hMid + (hMid - y);
		else y = hMid - (y - hMid);
		m[mp(x, y)]++;
		temp.pb(mp(x, y));
	}
	f = 1;
	rep(i, n) if(!m[p[i]]){
		f = 0;
		break;
	}
	if(f) ans.pb(temp);
	//rotations
	m.clear();
	temp.clear();
	rep(i, n){
		ld x = p[i].fi, y = p[i].se;
		x -= vMid, y -= hMid;
		ld st = x;
		x = -y, y = st;
		x += vMid, y += hMid;
		m[mp(x, y)]++;
		temp.pb(mp(x, y));
	}
	f = 1;
	rep(i, n) if(!m[p[i]]){
		f = 0;
		break;
	}
	if(f) ans.pb(temp);
	m.clear();
	temp.clear();
	rep(i, n){
		ld x = p[i].fi, y = p[i].se;
		x -= vMid, y -= hMid;
		ld st = x;
		//x = -y, y = st;
		x = y, y = -st;
		x += vMid, y += hMid;
		m[mp(x, y)]++;
		temp.pb(mp(x, y));
	}
	f = 1;
	rep(i, n) if(!m[p[i]]){
		f = 0;
		break;
	}
	if(f) ans.pb(temp);
	m.clear();
	temp.clear();
	rep(i, n){
		ld x = p[i].fi, y = p[i].se;
		x -= vMid, y -= hMid;
		x = -x, y = -y;
		x += vMid, y += hMid;
		m[mp(x, y)]++;
		temp.pb(mp(x, y));
	}
	f = 1;
	rep(i, n) if(!m[p[i]]){
		f = 0;
		break;
	}
	if(f) ans.pb(temp);
	m.clear();
	temp.clear();
	rep(i, n){
		ld x = p[i].fi, y = p[i].se;
		x -= vMid, y -= hMid;
		ld st = x;
		x = -y, y = -st;
		x += vMid, y += hMid;
		m[mp(x, y)]++;
		temp.pb(mp(x, y));
	}
	f = 1;
	rep(i, n) if(!m[p[i]]){
		f = 0;
		break;
	}
	if(f) ans.pb(temp);
	/*
	m.clear();
	temp.clear();
	rep(i, n){
		ld x = p[i].fi, y = p[i].se;
		x -= vMid, y -= hMid;
		ld st = x;
		//x = -y, y = st;
		x = -y, y = -st;
		x += vMid, y += hMid;
		m[mp(x, y)]++;
		temp.pb(mp(x, y));
	}
	f = 1;
	rep(i, n) if(!m[p[i]]){
		f = 0;
		break;
	}
	if(f) ans.pb(temp);
	*/
	cout << ans.size() << endl;
	for(vector<pair<ld, ld>> x : ans){
		for(pair<ld, ld> k : x){
			int one = (int)(k.fi), two = (int)(k.se);
			cout << one << " " << two << endl;
		}
		cout << endl;
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

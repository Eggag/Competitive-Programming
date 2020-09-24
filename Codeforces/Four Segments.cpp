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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll xtime(){
	return ((clock() * 1000) / CLOCKS_PER_SEC);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	vector<pair<pi, pi>> a(4);
	mt19937 rnd(239);
	rep(i, 4){
		cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se.fi >> a[i].se.se;
		if((a[i].fi.fi == a[i].se.fi) && (a[i].fi.se == a[i].se.se)){
			cout << "NO" << endl;
			return 0;
		}
	}
	while(xtime() < 800){
		vector<pair<pi, pi>> b = a;
		shuffle(all(b), rnd);
		if(b[0].fi.se < b[0].se.se){
			//sort by y
			swap(b[0].fi.se, b[0].se.se), swap(b[0].fi.fi, b[0].se.fi);
		}
		if(b[1].fi.fi > b[1].se.fi){
			//sort by x
			swap(b[1].fi.fi, b[1].se.fi), swap(b[1].fi.se, b[1].se.se);
		}
		if(b[2].fi.se < b[2].se.se){
			//sort by y
			swap(b[2].fi.se, b[2].se.se), swap(b[2].fi.fi, b[2].se.fi);
		}
		if(b[3].fi.fi > b[3].se.fi){
			//sort by x
			swap(b[3].fi.fi, b[3].se.fi), swap(b[3].fi.se, b[3].se.se);
		}
		if(b[0].fi.fi != b[0].se.fi) continue;
		if(b[1].fi.se != b[1].se.se) continue;
		if(b[2].fi.fi != b[2].se.fi) continue;
		if(b[3].fi.se != b[3].se.se) continue;
		//debug2(b[0].fi.fi, b[0].fi.se);
		//debug2(b[0].se.fi, b[0].se.se);
		//debug2(b[1].fi.fi, b[1].fi.se);
		//debug2(b[1].se.fi, b[1].se.se);
		//debug2(b[2].fi.fi, b[2].fi.se);
		//debug2(b[2].se.fi, b[2].se.se);
		//debug2(b[3].fi.fi, b[3].fi.se);
		//debug2(b[3].se.fi, b[3].se.se);
		int cnt = 0;
		if((b[0].fi.fi == b[1].fi.fi) && (b[0].fi.se == b[1].fi.se)) cnt++;
		if((b[1].se.fi == b[2].fi.fi) && (b[1].se.se == b[2].fi.se)) cnt++;
		if((b[2].se.fi == b[3].se.fi) && (b[2].se.se == b[3].se.se)) cnt++;
		if((b[3].fi.fi == b[0].se.fi) && (b[3].fi.se == b[0].se.se)) cnt++;
		if(cnt == 4){
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

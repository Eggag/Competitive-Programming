#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pi;
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

bool same_line(pi a, pi b, pi c){ //fi is x and se is y
	//check if slope is inf
	if(a.fi == b.fi && a.fi == c.fi) return 1;
	if(a.se == b.se && a.se == c.se) return 1;
	//they are on the same line if the slope is the same
	//assert(b.fi - a.fi);
	if(a.fi == b.fi) return 0;
	if(a.se == b.se) return 0;
	if(c.fi == b.fi) return 0;
	if(c.se == b.se) return 0;
	ld slope = (b.se - a.se) / (b.fi - a.fi);
	//assert(c.fi - b.fi);
	ld slope1 = (c.se - b.se) / (c.fi - b.fi);
	if(slope == slope1) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<pi, int>> pos(n);
	rep(i, n){
		cin >> pos[i].fi.fi >> pos[i].fi.se;
		pos[i].se = i;
	}
	sort(all(pos));
	rep(i, n - 2){
		pi one = {pos[i].fi.fi, pos[i].fi.se};
		pi two = {pos[i + 1].fi.fi, pos[i + 1].fi.se};
		pi three = {pos[i + 2].fi.fi, pos[i + 2].fi.se};
		//debug(same_line(one, two, three));
		if(!same_line(one, two, three)){
			cout << pos[i].se + 1 << " " << pos[i + 1].se + 1 << " " << pos[i + 2].se + 1 << endl;
			return 0;
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

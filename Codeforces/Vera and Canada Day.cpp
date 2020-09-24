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

struct score{
	int lxs, rxs, lys, rys;
	int sum;
	void comp(){
		sum = max(lxs, rxs) + max(lys, rys);
	}
};

unordered_map<int, set<pair<int, pi>>> x3, y3;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	int ans = 0;
	vi x(n), y(n), v(n);
	vector<score> sc(n);
	rep(i, n){
		cin >> x[i] >> y[i] >> v[i];
		sc[i] = (score){0, 0, 0, 0};
		auto it = x3[y[i]].ub({x[i], {0, 0}});
		if(it != x3[y[i]].end()){
			sc[i].comp();
			ans -= sc[i].sum;
			sc[i].rxs = (int)(it->se.fi);
			sc[i].comp();
			ans += sc[i].sum;
			sc[(int)(it->se.se)].comp();
			ans -= sc[(int)(it->se.se)].sum;
			sc[(int)(it->se.se)].lxs = v[i];
			sc[(int)(it->se.se)].comp();
			ans += sc[(int)(it->se.se)].sum;
		}
		if(it != x3[y[i]].begin()){
			it--;
			sc[i].comp();
			ans -= sc[i].sum;
			sc[i].lxs = (int)(it->se.fi);
			sc[i].comp();
			ans += sc[i].sum;
			sc[(int)(it->se.se)].comp();
			ans -= sc[(int)(it->se.se)].sum;
			sc[(int)(it->se.se)].rxs = v[i];
			sc[(int)(it->se.se)].comp();
			ans += sc[(int)(it->se.se)].sum;
		}
		auto it1 = y3[x[i]].ub({y[i], {0, 0}});
		if(it1 != y3[x[i]].end()){
			sc[i].comp();
			ans -= sc[i].sum;
			sc[i].rys = (int)(it1->se.fi);
			sc[i].comp();
			ans += sc[i].sum;
			sc[(int)(it1->se.se)].comp();
			ans -= sc[(int)(it1->se.se)].sum;
			sc[(int)(it1->se.se)].lys = v[i];
			sc[(int)(it1->se.se)].comp();
			ans += sc[(int)(it1->se.se)].sum;
		}
		if(it1 != y3[x[i]].begin()){
			it1--;
			sc[i].comp();
			ans -= sc[i].sum;
			sc[i].lys = (int)(it1->se.fi);
			sc[i].comp();
			ans += sc[i].sum;
			sc[(int)(it1->se.se)].comp();
			ans -= sc[(int)(it1->se.se)].sum;
			sc[(int)(it1->se.se)].rys = v[i];
			sc[(int)(it1->se.se)].comp();
			ans += sc[(int)(it1->se.se)].sum;
		}
		x3[y[i]].insert({x[i], {v[i], i}});
		y3[x[i]].insert({y[i], {v[i], i}});
		cout << ans << endl;
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

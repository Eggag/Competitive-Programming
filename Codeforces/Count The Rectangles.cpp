#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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
const int mxN = 1e4 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi del[mxN];
vector<array<int, 2>> hor[mxN];

template<class T> struct BIT{
	vector<T> bit;
	BIT(){
		bit.assign(mxN, 0);
	}
	void update(int ind, T delta){
		for(; ind < mxN; ind = ind | (ind + 1)){
			bit[ind] += delta;
		}
	}
	T query(int ind){
		T sum = 0;
		for(; ind >= 0; ind = (ind & (ind + 1)) - 1){
			sum += bit[ind];
		}
		return sum;
	}
	T query(int l, int r){
		return query(r) - (l ? query(l - 1) : 0);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<array<int, 3>> ver;
	rep(i, n){
		int x, y, x2, y2;
		cin >> x >> y >> x2 >> y2;
		x += 5000, y += 5000;
		x2 += 5000, y2 += 5000;
		if(x2 < x) swap(x, x2);
		if(y2 < y) swap(y, y2);
		if(x == x2) ver.pb({x, y, y2});
		else hor[x].pb({y, x2});
	}
	sort(all(ver));
	ll ans = 0LL;
	rep(i, ver.size()){
		BIT<int> bit;
		rep(j, ver[i][0] + 1){
			for(array<int, 2> x : hor[j]) if(x[1] > ver[i][0]){
				bit.update(x[0], 1);
				del[x[1]].pb(x[0]);
			}
		}
		repn(j, i + 1, ver.size()){
			int mn = max(ver[i][1], ver[j][1]);
			int mx = min(ver[i][2], ver[j][2]);
			repn(k, ver[j - 1][0], ver[j][0]){
				while(del[k].size()){
					bit.update(del[k].back(), -1);
					del[k].pop_back();
				}
			}
			if(mn > mx) continue;
			int nm = bit.query(mn, mx);
			ans += (ll)(1LL * nm * (nm - 1) / 2);
		}
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

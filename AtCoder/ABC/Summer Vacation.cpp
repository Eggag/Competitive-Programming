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
const int MAXN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool cmp(pi a, pi b){
	return a.se > b.se;
}

template<class T> struct BIT{
	vector<T> bit;
	BIT(){
		bit.assign(MAXN, 0);
	}
	void update(int ind, T delta){
		for(; ind < MAXN; ind = ind | (ind + 1)){
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
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pi> p;
	rep(i, n){
		int a, b;
		cin >> a >> b;
		if(a <= m) p.pb({a, b});
	}
	BIT<int> bit;
	n = p.size();
	vi pos(m + 1, 0);
	sort(all(p), cmp);
	ll ans = 0;
	rep(i, n){
		if(!pos[m - p[i].fi]){
			pos[m - p[i].fi] = 1;
			bit.update(m - p[i].fi, 1);
			ans += p[i].se;
			continue;
		}
		int l = 0, r = m - p[i].fi;
		while(l < r){
			int mid = (l + r + 1) / 2;
			int num1 = bit.query(m - p[i].fi) - (mid ? bit.query(mid - 1) : 0);
			int num2 = (m - p[i].fi - mid + 1);
			if(num1 < num2) l = mid;
			else r = mid - 1;
		}
		if(!pos[l]){
			pos[l] = 1;
			bit.update(l, 1);
			ans += p[i].se;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

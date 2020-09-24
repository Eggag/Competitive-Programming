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
const int MAXN = 1e5 + 100;

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

ll solve1(int n, int m, vector<pi> p){
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
			if((bit.query(m - p[i].fi) - (mid ? bit.query(mid - 1) : 0)) < (m - p[i].fi - mid + 1)) l = mid;
			else r = mid - 1;
		}
		if(!pos[l]){
			pos[l] = 1;
			bit.update(l, 1);
			ans += p[i].se;
		}
	}
	return ans;
}

ll solve2(int n, int m, vector<pi> p){
	n = p.size();
	vi pos(m + 1, 0);
	sort(all(p), cmp);
	ll ans = 0;
	rep(i, n){
		int cur = m - p[i].fi;
		while(cur >= 0 && pos[cur]) cur--;
		if(cur != -1) pos[cur] = 1, ans += p[i].se;
	}
	return ans;
}

mt19937 rng((ll)std::chrono::steady_clock::now().time_since_epoch().count());

int main(){
	int tests = 100;
	while(tests--){
		int n = rng() % 10, m = rng() % 10;
		vector<pi> p;
		rep(i, n){
			int a = (rng() % 10) + 1, b = (rng() % 10) + 1;
			if(a <= m) p.pb({a, b});
		}
		ll one = solve1(n, m, p), two = solve2(n, m, p);
		if(one != two){
			cout << "AHA!" << endl;
			debug2(n, m);
			rep(i, p.size()) cout << p[i].fi << " " << p[i].se << endl;
			debug2(one, two);
			return 0;
		}
		else cout << "Accepted!" << endl; 
	}
}

/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/


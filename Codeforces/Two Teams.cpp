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

class cmp{
public:
	bool operator() (pi a, pi b){
		return a.fi > b.fi;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vi a(n);
	set<pi, cmp> mx;
	rep(i, n) cin >> a[i], mx.insert({a[i], i});
	vector<array<int, 2>> p(n);
	rep(i, n){
		if(i) p[i][0] = i - 1;
		else p[i][0] = -1;
		if(i < (n - 1)) p[i][1] = i + 1;
		else p[i][1] = -1;
	}
	vi ans(n);
	int col = 0;
	int num = 0;
	while(num < n){
		pi cur = *mx.begin();
		mx.erase(mx.begin());
		//right
		ans[cur.se] = col;
		int nxt = p[cur.se][1];
		num++;
		int cnt = k;
		int hi = -1, lo = -1;
		while(cnt-- && nxt != -1){
			ans[nxt] = col;
			if(mx.find({a[nxt], nxt}) != mx.end()) mx.erase(mx.find({a[nxt], nxt}));
			num++;
			nxt = p[nxt][1];
		}
		if(nxt != -1) hi = nxt;
		//left
		cnt = k;
		nxt = p[cur.se][0];
		while(cnt-- && nxt != -1){
			ans[nxt] = col;
			if(mx.find({a[nxt], nxt}) != mx.end()) mx.erase(mx.find({a[nxt], nxt}));
			num++;
			nxt = p[nxt][0];
		}
		if(nxt != -1) lo = nxt;
		if(hi != -1 && lo != -1){
			p[hi][0] = lo;
			p[lo][1] = hi;
		}
		else if(hi != -1 && lo == -1){
			p[hi][0] = -1;
		}
		else if(lo != -1 && hi == -1){
			p[lo][1] = -1;
		}
		col ^= 1;
	}
	rep(i, n) cout << ans[i] + 1;
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

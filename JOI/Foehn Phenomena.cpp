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
 
template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
struct seg{
	ll dat[1 << 19];
	int sz;
	seg(int s){
		sz = s;
		for(int i = 0; i < (1 << 19); i++){
			dat[i] = 0;
		}
	}
	void update(int i, int s, int e, int x, ll v){
		if(s == e){
			dat[i] = v;
			return;
		}
		int m = (s + e) / 2;
		if(x <= m) update(i << 1, s, m, x, v);
		else update(i << 1 | 1, m + 1, e, x, v);
		dat[i] = dat[i << 1] + dat[i << 1 | 1];
	}
	void update(int x, ll v){
		update(1, 0, sz, x, v);
	}
	ll query(int i, int s, int e, int x, int y){
		if(e < x || y < s) return 0;
		if(x <= s && e <= y) return dat[i];
		int m = (s + e) / 2;
		return query(i << 1, s, m, x, y) + query(i << 1 | 1, m + 1, e, x, y);
	}
	ll query(int x, int y){
		return query(1, 0, sz, x, y);
	}
};
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	ll s, t;	
	cin >> n >> q >> s >> t;
	vector<ll> a(n + 1);
	rep(i, n + 1) cin >> a[i];
	vector<ll> cnt(n + 1, 0LL);
	seg tree(n + 1);
	repn(i, 1, n + 1){
		if(a[i] > a[i - 1]){
			cnt[i] = -1 * s * (a[i] - a[i - 1]);
		}
		else{
			cnt[i] = t * (a[i - 1] - a[i]);
		}
		tree.update(i, cnt[i]);
	}
	vector<ll> num(n + 1, 0);
	vector<ll> num1(n + 1, 0);
	rep(i, q){
		int l, r;
		ll x;
		cin >> l >> r >> x;
		a[l] += x;
		if((a[l] + num[l - 1]) > (a[l - 1] + num1[l])){
			tree.update(l, -1 * s * (a[l] - a[l - 1] - num1[l] + num[l - 1]));
		}
		else{
			tree.update(l, t * (a[l - 1] - a[l] - num[l - 1] + num1[l]));
		}
		if(l != r) a[r] += x;
		if(r + 1 <= n){
			if((a[r + 1] + num[r]) > (a[r] + num1[r + 1])){
				tree.update(r + 1, -1 * s * ((a[r + 1] - num1[r + 1]) - a[r] + num[r]));
			}
			else{
				tree.update(r + 1, t * (a[r] - a[r + 1] - num[r] + num1[r + 1]));
			}
		}
		if(l + 1 < r) num[l] += x, num1[r] += x;
		cout << tree.query(0, n) << endl;
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

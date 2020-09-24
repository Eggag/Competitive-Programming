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
const int MAXN = 1000005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

template<class T> struct BIT{
	vector<T> bit;
	BIT(){
		bit.assign(MAXN, 0);
	}
	void update(int ind, T delta){
		for(; ind < MAXN; ind += (ind & (-ind))){
			bit[ind] += delta;
		}
	}
	T query(int ind){
		T sum = 0;
		for(; ind; ind -= (ind & (-ind))){
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
	ll n;
	cin >> n;
	BIT<int> bitmx, bitmn;
	vi mn(n, 1e9), mx(n, 0);
	vi ac(n, 0);
	ll ans = 0;
	ll cnt = 0;
	rep(i, n){
		int l;
		cin >> l;
		int f = 1;
		rep(j, l){
			int x;
			cin >> x;
			if(f && x > mn[i]){
				ac[i] = 1, f = 0;
				cnt++;
			}
			mx[i] = max(mx[i], x);
			mn[i] = min(mn[i], x);
		}
		if(!ac[i]){
			mx[i]++, mn[i]++;
			bitmx.update(mx[i], 1);
			bitmn.update(mn[i], 1);
		}
	}
	ans += (((cnt * (cnt - 1)) / 2)) * 2 + cnt;
	ans += 2 * ((n - cnt) * cnt);
	rep(i, n) if(!ac[i]){
		ll num = (n - cnt) - bitmx.query(mn[i]);
		//if(mx[i] > mn[i]) num--;
		ans += num;
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

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
const int MAXN = 5e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n), p(n);
	rep(i, n) cin >> a[i];
	int subtask = 1;
	rep(i, n){
		cin >> p[i];
		if(p[i] != (i + 1)) subtask = 2;
	}
	if(subtask == 1){
		BIT<int> bit;
		ll ans = 0;
		rep(i, n){
			ans += i - bit.query(a[i]);
			bit.update(a[i], 1);
			cout << ans << endl;
		}
	}
	else{
		//if it is a 1, we need to count the 2's before
		//if it is a 2, 1's after
		//ok, should be gd
		BIT<int> ost1, ost2;
		ll ans = 0;
		int ons = 0;
		rep(i, n){
			if(a[p[i] - 1] == 1){
				int nm = ost2.query(p[i] - 1);
				ans += nm;
				ost1.update(p[i] - 1, 1);
				ons++;
			}
			else{
				int nm = ons - ost1.query(p[i] - 1);
				ans += nm;
				ost2.update(p[i] - 1, 1);
			}
			cout << ans << endl;
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

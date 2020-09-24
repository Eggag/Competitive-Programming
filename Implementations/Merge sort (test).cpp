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

mt19937 rng((ll)std::chrono::steady_clock::now().time_since_epoch().count());

vi merge_sort(vi a){
	if(a.size() == 1) return a;
	vi ret;
	int n = a.size();
	vi lf, rt;
	rep(i, n / 2) lf.pb(a[i]);
	repn(i, n / 2, n) rt.pb(a[i]);
	vi p1 = merge_sort(lf), p2 = merge_sort(rt);
	int x = 0, y = 0;
	rep(i, n){
		if(x == p1.size()) ret.pb(p2[y]), y++;
		else if(y == p2.size()) ret.pb(p1[x]), x++;
		else{
			if(p1[x] < p2[y]) ret.pb(p1[x]), x++;
			else ret.pb(p2[y]), y++;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n = 2e6;
	vi a(n);
	rep(i, n) a[i] = rng() % 1000000000;
	vi b = merge_sort(a);
	if(is_sorted(all(b))) cout << "ACCEPTED!" << endl;
	else cout << ":(" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

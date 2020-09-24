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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vi l(2 * n), r(2 * n), s(2 * n);
	rep(i, 2 * n) cin >> l[i] >> r[i] >> s[i];
	rep(i, 1 << (2 * n)){
		int cur = 0, cur1 = 0;
		vi vis(n + 1, 0), vis1(n + 1, 0); 
		int f = 1;
		rep(j, 2 * n){
			if(i & (1 << j)){
				cur += s[j];
				if(vis[l[j]]) f = 0;
				vis[l[j]] = 1;
			}
			else{
				cur1 += s[j];
				if(vis1[r[j]]) f = 0;
				vis1[r[j]] = 1;
			}
		}
		if(f && abs(cur - cur1) <= k){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

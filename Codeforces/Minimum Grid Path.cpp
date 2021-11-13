#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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

void solve(){
	int n;
	cin >> n;
	vector<ll> c(n);
	rep(i, n) cin >> c[i];
	ll cnt = c[1], cnt1 = c[0];
	ll nm = 1LL, nm1 = 1LL;
	ll sm = c[1], sm1 = c[0];
	vector<ll> bst(n, 1e18), bst1(n, 1e18);
	bst[1] = c[1] * n, bst1[0] = c[0] * n;
	repn(i, 2, n){
		if(i & 1){
			if(c[i] < cnt){
				bst[i] = sm + c[i] * (n - nm);
				cnt = c[i];
			}
			else bst[i] = bst[i - 2] + c[i] - cnt;
			sm += c[i];
			nm++;
		}
		else{
			if(c[i] < cnt1){
				bst1[i] = sm1 + c[i] * (n - nm1);
				cnt1 = c[i];
			}
			else bst1[i] = bst1[i - 2] + c[i] - cnt1;
			sm1 += c[i];
			nm1++;
		}
	}
	ll mn = 1e18;
	repn(i, 1, n){
		mn = min({mn, bst[i] + bst1[i - 1], bst[i - 1] + bst1[i]});
	}
	cout << mn << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

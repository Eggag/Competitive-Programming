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
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n){
		map<ll, int> cnt;
		rep(j, n) cnt[a[j]]++;
		ll cur = a[i];
		vector<ll> ans = {cur};
		int f = 1;
		rep(j, n - 1){
			if(cnt[cur * 2]) cnt[cur * 2]--, cur *= 2, ans.pb(cur);
			else if(cur % 3 == 0 && cnt[cur / 3]) cnt[cur / 3]--, cur /= 3, ans.pb(cur);
			else{
				f = 0;
				break;
			}
		}
		if(f){
			rep(j, ans.size()) cout << ans[j] << " ";
			cout << endl;
			return 0;
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

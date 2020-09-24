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

int cnt[1050];

void solve(){
	int n;
	cin >> n;
	vi s(n);
	memset(cnt, 0, sizeof(cnt));
	int mx = 0;
	rep(i, n) cin >> s[i], cnt[s[i]]++, mx = max(mx, s[i]);
	repn(k, 1, 1025){
		vi cnt1(5050, 0);
		int f = 1;
		rep(i, n){
			if((s[i] ^ k) > mx){
				f = 0;
				break;
			}
			cnt1[(s[i] ^ k)]++;
		}
		if(!f) continue;
		rep(i, n) if(cnt1[s[i]] != cnt[s[i]]){
			f = 0;
			break;
		}
		if(f){
			cout << k << endl;
			return;
		}
	}
	cout << -1 << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/

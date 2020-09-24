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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vi h(n);
	rep(i, n) cin >> h[i];
	int cur = m;
	rep(i, n - 1){
		//standing on i
		if(h[i] > h[i + 1]){
			cur += min(h[i], k + (h[i] - h[i + 1]));
			continue;
		}
		else{
			if((h[i + 1] - k) >= h[i]){
				cur -= ((h[i + 1] - k) - h[i]);
				if(cur < 0){
					cout << "NO" << endl;
					return;
				}
			}
			else{
				cur += min(h[i], h[i] - (h[i + 1] - k));
			}
		}
	}
	cout << "YES" << endl;
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

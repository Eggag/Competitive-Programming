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

void solve(){
	int n;
	cin >> n;
	if(n & 1){
		if(n == 1) cout << "FastestFinger" << endl;
		else cout << "Ashishgup" << endl;
		return;
	}
	int cnt = 1;
	while(1){
		if(n == 1){
			if(cnt & 1) cout << "FastestFinger" << endl;
			else cout << "Ashishgup" << endl;
			return;
		}
		if(n & 1){
			if(!(cnt & 1)) cout << "FastestFinger" << endl;
			else cout << "Ashishgup" << endl;
			return;
		}
		int f = 0;
		int cur = 0;
		for(int j = 2; (j * j) <= n; j++){
			if(n % j == 0){
				if((j & 1 && !((n / j) & 1)) || (!(j & 1) && ((n / j) & 1))){
					if(j & 1) cur = max(cur, j), f = 1;
					else if(j != 2) cur = max(cur, n / j), f = 1;
				}
			}
		}
		if(!f) n--;
		else n /= cur;
		cnt++;
	}
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

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
	vi c(n);
	rep(i, n) cin >> c[i];
	int cnt = 0;
	int a = 0, b = 0;
	int prev = -1;
	int l = 0, r = n - 1;
	while(l <= r){
		if(cnt % 2 == 0){
			//Alice
			if(!cnt){
				a += c[0];
				l++;
				prev = c[0];
			}
			else{
				int cur = 0;
				while(l <= r && cur <= prev){
					a += c[l];
					cur += c[l];
					l++;
				}
				prev = cur;
			}
		}
		else{
			//Bob
			int cur = 0;
			while(l <= r && cur <= prev){
				b += c[r];
				cur += c[r];
				r--;
			}
			prev = cur;
		}
		cnt++;
	}
	cout << cnt << " " << a << " " << b << endl;
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

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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
	string s;
	cin >> s;
	int x;
	cin >> x;
	int n = s.size();
	vi w(n, 0);
	rep(i, n){
		if(s[i] == '1'){
			//we try to see if we can do prev
			if(i >= 2 * x){
				if(s[i - 2 * x] == '0'){
					//means we have to set the one in front
					if((i + x) >= n){
						cout << -1 << endl;
						return;
					}
					w[i + x] = 1;
				}
				else w[i - x] = 1;
			}
			else{
				if(i >= x) w[i - x] = 1;
				else{
					if((i + x) >= n){
						cout << -1 << endl;
						return;
					}
					w[i + x] = 1;
				}
			}
		}
		else{
			if(i >= x && w[i - x]){
				cout << -1 << endl;
				return;
			}
			if((i + x) < n && w[i + x]){
				cout << -1 << endl;
				return;
			}
		}
	}
	rep(i, n) cout << w[i];
	cout << endl;
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

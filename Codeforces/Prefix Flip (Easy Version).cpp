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
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	vi res;
	for(int i = n - 1; i >= 0; i--){
		if(a[i] != b[i]){
			if(a[0] == b[i]){
				res.pb(0);
				if(a[0] == '1') a[0] = '0';
				else a[0] = '1';
				res.pb(i);
				rep(j, i + 1){
					if(a[j] == '1') a[j] = '0';
					else a[j] = '1';
				}
				reverse(a.begin(), a.begin() + i + 1);
			}
			else{
				res.pb(i);
				rep(j, i + 1){
					if(a[j] == '1') a[j] = '0';
					else a[j] = '1';
				}
				reverse(a.begin(), a.begin() + i + 1);
			}
		}
	}
	cout << res.size() << " ";
	rep(i, res.size()) cout << res[i] + 1 << " ";
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

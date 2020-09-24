#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int x;
	cin >> x;
	int ans = 0;
	vi v;
	while(__builtin_popcount(x + 1) != 1){
		for(int i = 20; i >= 0; i--){
			if(x & (1 << i)){
				v.pb(i + 1);
				x ^= (1 << (i + 1)) - 1;
				ans++;
				break;
			}
		}
		if(__builtin_popcount(x + 1) == 1) break;
		x++;
		ans++;
	}
	cout << ans << endl;
	rep(i, v.size()) cout << v[i] << " \n"[i == v.size() - 1];
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

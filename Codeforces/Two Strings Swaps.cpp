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
	string a, b;
	cin >> a >> b;
	int ans = 0;
	rep(i, n / 2){
		vector<char> pos = {a[i], b[i], a[n - i - 1], b[n - i - 1]};
		int mn = 1e9;
		rep(j, pos.size()) rep(k, pos.size()){
			vector<char> cur = {pos[j], pos[k], b[i], b[n - i - 1]};
			sort(all(cur));
			if(cur[0] == cur[1] && cur[2] == cur[3]){
				mn = min(mn, (a[i] != pos[j]) + (a[n - i - 1] != pos[k]));	
			}
		}
		ans += mn;
	}	
	if(n & 1) ans += (a[n / 2] != b[n / 2]);
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

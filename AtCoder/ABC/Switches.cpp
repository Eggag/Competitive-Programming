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

vi s[15];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	//the constraints are small so we bruteforce every possible option
	//use bit representation of sets
	int a, b;
	rep(i, m){
		cin >> a;
		rep(j, a){
			cin >> b;
			b--;
			s[i].pb(b);
		}
	}
	vi p(m);
	rep(i, m) cin >> p[i];
	int ans = 0;
	rep(i, (1 << n)){
		int f = 1;
		rep(j, m){
			int cnt = 0;
			for(int u : s[j]){
				if(i & (1 << u)) cnt++;
			}
			if(cnt % 2 != p[j]) f = 0;
		}
		if(f) ans++;
	}
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

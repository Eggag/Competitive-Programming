#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int ans = 0;
	int cnt = 0;
	int cur = 0;
	vi speed;
	rep(i, n){
		int t;
		cin >> t;
		int sp;
		if(t == 1 || t == 3) cin >> sp;
		if(t == 1){
			cur = sp;
			while(speed.size() && speed[speed.size() - 1] < cur){
				ans++;
				speed.pop_back();
			}
		}
		if(t == 2) ans += cnt, cnt = 0;
		if(t == 3){
			if(cur > sp) ans++;
			else speed.pb(sp);
		}
		if(t == 4) cnt = 0;
		if(t == 5) speed.clear();
		if(t == 6) cnt++;
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

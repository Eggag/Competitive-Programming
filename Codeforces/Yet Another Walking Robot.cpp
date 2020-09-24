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
	string s;
	cin >> s;
	int hor = 0, ver = 0;
	int ans = 1e9;
	int l = 0, r = 0;
	map<pi, int> vis, prev;
	vis[mp(0, 0)] = 1;
	prev[mp(0, 0)] = 0;
	rep(i, n){
		if(s[i] == 'L'){
			hor++;
			if(vis[mp(hor, ver)]){
				int cur = i - prev[mp(hor, ver)];
				if(cur < ans){
					ans = cur;
					l = prev[mp(hor, ver)] + 1;
					r = i + 1;
				}
			}
			vis[mp(hor, ver)] = 1;
			prev[mp(hor, ver)] = i + 1;
		}
		else if(s[i] == 'R'){
			hor--;
			if(vis[mp(hor, ver)]){
				int cur = i - prev[mp(hor, ver)];
				if(cur < ans){
					ans = cur;
					l = prev[mp(hor, ver)] + 1;
					r = i + 1;
				}
			}
			vis[mp(hor, ver)] = 1;
			prev[mp(hor, ver)] = i + 1;
		}
		else if(s[i] == 'U'){
			ver++;
			if(vis[mp(hor, ver)]){
				int cur = i - prev[mp(hor, ver)];
				if(cur < ans){
					ans = cur;
					l = prev[mp(hor, ver)] + 1;
					r = i + 1;
				}
			}
			vis[mp(hor, ver)] = 1;
			prev[mp(hor, ver)] = i + 1;
		}
		else{
			ver--;
			if(vis[mp(hor, ver)]){
				int cur = i - prev[mp(hor, ver)];
				if(cur < ans){
					ans = cur;
					l = prev[mp(hor, ver)] + 1;
					r = i + 1;
				}
			}
			vis[mp(hor, ver)] = 1;
			prev[mp(hor, ver)] = i + 1;
		}
	}
	if(ans == 1e9){
		cout << -1 << endl;
		return;
	}
	cout << l << " " << r << endl;
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

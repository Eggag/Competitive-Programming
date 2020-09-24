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
	set<pi> ans;
	//keep doing the 1's
	int st = 0;
	vi dx = {0, 1, 0, 1, 2, 2, 1};
	vi dy = {0, 0, 1, 1, 2, 1, 2};
	vi dx1 = {0, -1, 0};
	vi dy1 = {0, 0, -1};
	int x = 0, y = 0;
	rep(i, n){
		if(!i){
			rep(j, dx.size()){
				int x1 = x + dx[j], y1 = y + dy[j];
				ans.insert({x1, y1});
			}
			x += 3;
			y += 3;
		}
		else{
			rep(j, dx1.size()){
				int x1 = x + dx1[j], y1 = y + dy1[j];
				ans.insert({x1, y1});
			}
			x++;
			y++;
		}
	}
	cout << ans.size() << endl;
	for(pi x : ans) cout << x.fi << " " << x.se << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

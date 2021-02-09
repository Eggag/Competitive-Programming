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
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	string s;
	cin >> s;
	int n = (int)(s.size());
	pi pos = {0, 0};
	rep(j, n + 1){
		rep(i, 4){
			pi ob = {pos.fi + dx[i], pos.se + dy[i]};
			if(!ob.fi && !ob.se) continue;
			pi pos1 = {0, 0};
			rep(k, n){
				if(s[k] == 'L') pos1.fi--;
				if(s[k] == 'R') pos1.fi++;
				if(s[k] == 'D') pos1.se--;
				if(s[k] == 'U') pos1.se++;
				if(pos1 == ob){
					if(s[k] == 'L') pos1.fi++;
					if(s[k] == 'R') pos1.fi--;
					if(s[k] == 'D') pos1.se++;
					if(s[k] == 'U') pos1.se--;
				}
			}
			if(!pos1.fi && !pos1.se){
				cout << ob.fi << " " << ob.se << '\n';
				return;
			}
		}
		if(j < n){
			if(s[j] == 'L') pos.fi--;
			if(s[j] == 'R') pos.fi++;
			if(s[j] == 'D') pos.se--;
			if(s[j] == 'U') pos.se++;
		}
	}
	cout << "0 0" << '\n';
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
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

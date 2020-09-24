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
	freopen("landin.txt", "r", stdin);
	freopen("landout.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	int ans = 0;
	vi ret;
	rep(i, n){
		int x = 0, y = 0;
		int cnt = 0;
		rep(j, m){
			if(s[i][j] == '.'){
				if(!cnt) x = i, y = j;
				cnt++;
			}
			else{
				if(cnt > ans){
					ret = {x, y, i, j - 1};
					ans = cnt;
				}
				cnt = 0;
			}
		}
		if(cnt > ans){
			ret = (vi){x, y, i, m - 1};
			ans = cnt;
		}
	}
	rep(j, m){
		int cnt = 0;
		int x = 0, y = 0;
		rep(i, n){
			if(s[i][j] == '.'){
				if(!cnt) x = i, y = j;
				cnt++;
			}
			else{
				if(cnt > ans){
					ret = {x, y, i - 1, j};
					ans = cnt;
				}
				cnt = 0;
			}
		}
		if(cnt > ans){
			ret = (vi){x, y, n - 1, j};
			ans = cnt;
		}
	}
	rep(i, ret.size()) cout << ret[i] + 1 << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

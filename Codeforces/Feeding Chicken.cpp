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

vector<char> nxt;
char g[105][105];

void solve(){
	int r, c, k;
	cin >> r >> c >> k;
	vector<string> s(r);
	rep(i, r) cin >> s[i];
	int cnt = 0;
	rep(i, r) rep(j, c) if(s[i][j] == 'R') cnt++;
	int num = cnt / k;
	int rem = cnt % k; //the number of components that would have num + 1
	int cur = 0, ind = 0;
	int ch = 0;
	rep(i, r){
		if(i % 2 == 0){
			rep(j, c){
				if(s[i][j] == 'R'){
					cur++;
					if(ch) ch = 0, ind++;
				}
				g[i][j] = nxt[ind];
				if(cur == (num + (rem > 0))) cur = 0, rem--, ch = 1;
			}
		}
		else{
			for(int j = c - 1; j >= 0; j--){
				if(s[i][j] == 'R'){
					cur++;
					if(ch) ch = 0, ind++;
				}
				g[i][j] = nxt[ind];
				if(cur == (num + (rem > 0))) cur = 0, rem--, ch = 1;
			}
		}
	}
	rep(i, r){
		rep(j, c) cout << g[i][j];
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	rep(i, 10) nxt.pb((char)('0' + i)); //not this time :P
	rep(i, 26) nxt.pb((char)('a' + i));
	rep(i, 26) nxt.pb((char)('A' + i));
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

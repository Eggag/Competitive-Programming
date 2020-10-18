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
	string s;
	cin >> s;
	//try making a loop from 0 from the right
	int st = 0;
	while(true){
		if(s[st] == '<') break;
		st++;
		if(st == n) st = 0;
		if(!st) break;
	}
	if(!st && s[0] != '<'){
		cout << n << endl;
		return;
	}
	//now from the left
	st = 0;
	while(true){
		if(s[st] == '>') break;
		st--;
		if(st == -1) st = n - 1;
		if(!st) break;
	}
	if(!st && s[0] != '>'){
		cout << n << endl;
		return;
	}
	//neither worked so just print all that have an - adjacent
	int ans = 0;
	rep(i, n){
		int cr = i + 1;
		if(cr == n) cr = 0;
		if(s[i] == '-' || s[cr] == '-') ans++;
	}
	cout << ans << endl;
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

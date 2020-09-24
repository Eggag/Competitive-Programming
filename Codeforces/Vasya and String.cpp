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
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k;
string s;
int ans = 0;

void solve(){
	int cur = 0;
	int r = 0;
	rep(i, n){
		while(cur < n && (s[cur] == 'a' || r < k)){
			if(s[cur] == 'b') r++;
			cur++;
		}
		ans = max(ans, cur - i);
		if(s[i] == 'b') r--;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	cin >> s;
	solve();
	rep(i, n){
		if(s[i] == 'a') s[i] = 'b';
		else s[i] = 'a';
	}
	solve();
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

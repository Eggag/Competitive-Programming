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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	pi pos = {0, 0};
	int prev;
	if(s[0] == 'U') pos = {0, 1}, prev = 1;
	else pos = {1, 0}, prev = 0;
	int ans = 0;
	repn(i, 1, n){
		if(s[i] == 'U'){
			pos = {pos.fi, pos.se + 1};
			if(pos.se - 1 == pos.fi && prev == 0) ans++, prev = 1;
		}
		else{
			pos = {pos.fi + 1, pos.se};
			if(pos.fi - 1 == pos.se && prev == 1) ans++, prev = 0;
		}
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

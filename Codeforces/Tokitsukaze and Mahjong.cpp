#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
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
	vector<string> s(3);
	map<string, int> mp;
	rep(i, 3){
		cin >> s[i];
		mp[s[i]]++;
	}
	int ans = -1;
	for(auto x : mp){
		if(x.se == 3){
			cout << 0 << endl;
			return 0;
		}
		if(x.se == 2){
			ans = 1;
		}
	}
	sort(all(s));
	int f = 0, f1 = 0, f3 = 0, f2 = 0, f4 = 0, f5 = 0;
	if(((s[0][0] - '0') + 1) == (s[1][0] - '0') && (s[0][1] == s[1][1])) f = 1;
	if(((s[1][0] - '0') + 1) == (s[2][0] - '0') && (s[1][1] == s[2][1])) f1 = 1;
	if(((s[0][0] - '0') + 1) == (s[2][0] - '0') && (s[0][1] == s[2][1])) f2 = 1;
	if(((s[0][0] - '0') + 2) == (s[1][0] - '0') && (s[0][1] == s[1][1])) f3 = 1;
	if(((s[1][0] - '0') + 2) == (s[2][0] - '0') && (s[1][1] == s[2][1])) f4 = 1;
	if(((s[0][0] - '0') + 2) == (s[2][0] - '0') && (s[0][1] == s[2][1])) f5 = 1;
	if(f && f1){
		cout << 0 << endl;
		return 0;
	}
	if(f || f1 || f3 || f4 || f5 || f2) ans = 1;
	if(ans == 1){
		cout << 1 << endl;
	}
	else cout << 2 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

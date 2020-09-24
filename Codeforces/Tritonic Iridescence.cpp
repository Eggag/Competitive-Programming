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
	int n;
	cin >> n;
	string s;
	cin >> s;
	vi p;
	rep(i, n){
		if(s[i] == '?') p.pb(i);
	}
	repn(i, 1, n){
		if(s[i] == s[i - 1] && s[i] != '?'){
			cout << "No" << endl;
			return 0;
		}
	}
	//check if there is a ? that is trapped
	int cnt = 0;
	int cnt1 = 0;
	rep(i, n) if(s[i] == '?'){
		cnt++;
		if(i && i < n - 1){
			if(s[i - 1] != s[i + 1] && s[i - 1] != '?' && s[i + 1] != '?'){
				cnt1++;
			}
		}
	}
	if(cnt == cnt1) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

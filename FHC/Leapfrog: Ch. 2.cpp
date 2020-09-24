#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	string s;
	cin >> s;
	int dots = 0, b = 0;
	rep(i, s.length()){
		if(s[i] == '.') dots++;
		if(s[i] == 'B') b++;
	}
	if(!dots){
		cout << "N" << endl;
		return;
	}
	if(b >= dots){
		cout << "Y" << endl;
		return;
	}
	if(b >= 2){
		cout << "Y" << endl;
		return;
	}
	cout << "N" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("leapfrog_ch_.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

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
	string s, t;
	cin >> s >> t;
	int ex = 0, df = 0, df1 = 0;
	rep(i, 2 * n){
		if(s[i] == t[i] && s[i] == '1') ex++;
		if(s[i] == '0' && t[i] == '1') df++;
		if(s[i] == '1' && t[i] == '0') df1++;
	}
	int mn = min(df, df1);
	int num = ((ex + 1) / 2) + mn, num1 = ex / 2 + mn;
	swap(df, df1);
	if(df > df1) num += (df - df1 + (ex % 2 == 0)) / 2;
	else num1 += (df1 - df + (ex & 1)) / 2;
	if(num > num1) cout << "First" << endl;
	else if(num == num1) cout << "Draw" << endl;
	else cout << "Second" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

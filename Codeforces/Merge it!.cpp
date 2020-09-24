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
	int n;
	cin >> n;
	int a[n];
	rep(i, n) cin >> a[i];
	int ones = 0, twos = 0;
	int ans = 0;
	rep(i, n){
		if((a[i] + 3) % 3 == 1) ones++;
		else if((a[i] + 3) % 3 == 2) twos++;
		else ans++;
	}
	int threes = min(ones, twos);
	int add = (((twos - threes) >= 3) ? (twos - threes) / 3 : 0);
	cout << ans + threes + (((ones - threes) >= 3) ? (ones - threes) / 3 : 0) + add << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

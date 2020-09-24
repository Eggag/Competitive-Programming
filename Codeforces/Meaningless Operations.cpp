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
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi pre = {};

void solve(){
	int a;
	cin >> a;
	int st;
	repn(i, 1, 32){
		if(a < (1 << i)){
			st = i - 1;
			break;
		}
		if(a == (1 << i)){
			st = i;
			break;
		}
	}
	if(a == ((1 << (st + 1)) - 1)){
		for(int i = 2; i * i <= a; i++){
			if(a % i == 0){
				cout << a / i << endl;
				return;
			}
		}
		cout << 1 << endl;
		return;
	} 
	cout << (1 << (st + 1)) - 1 << endl;
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

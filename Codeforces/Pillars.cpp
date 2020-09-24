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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	int st = -1;
	rep(i, n){
		cin >> a[i];
		if(a[i] == n) st = i;
	}
	int l = st;
	int r = st;
	int cur = n;
	while(l > 0 || r < (n - 1)){
		int f = 0;
		if(l > 0){
			if(a[l - 1] == (cur - 1)) f = 1, l--;
		}
		if(r < (n - 1)){
			if(a[r + 1] == (cur - 1)) f = 1, r++;
		}
		if(!f){
			cout << "NO" << endl;
			return 0;
		}
		cur--;
	}
	cout << "YES" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

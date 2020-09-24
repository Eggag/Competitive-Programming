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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, a1, b;
	cin >> n >> a1 >> b;
	int a[n];
	rep(i, n) cin >> a[i];
	int ans = 0;
	rep(i, n / 2){
		if(a[i] != a[n - i - 1]){
			if(a[i] == 2){
				if(a[n - i - 1] == 1) ans += b;
				else if(a[n - i - 1] == 0) ans += a1;
				else ans += min(a1, b);
			}
			else if(a[n - i - 1] == 2){
				if(a[i] == 1) ans += b;
				else if(a[i] == 0) ans += a1;
				else ans += min(a1, b);
			}
			else{
				cout << "-1" << endl;
				return 0;
			}
		}
		if(a[i] == 2 && a[n - i - 1] == 2){
			if(i == n - i - 1) ans += min(a1, b);
			else ans += 2 * min(a1, b);
		}
	}
	if(n % 2 != 0){
		if(a[(n - 1) / 2] == 2) ans += min(a1, b);
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

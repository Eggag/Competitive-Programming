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
	int n, h, a, b, k;
	cin >> n >> h >> a >> b >> k;
	rep(i, k){
		ll ans = 0;
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ans += abs(x1 - x2);
		if(x1 == x2){
			cout << abs(y1 - y2) << endl;
			continue;
		}
		if(y1 < a){
			ans += a - y1;
			ans += abs(a - y2);
		}
		else if(y1 > b){
			ans += y1 - b;
			ans += abs(y2 - b);
		}
		else{
			ans += abs(y2 - y1);
		}
		cout << ans << endl;
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

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
	int a, b;
	cin >> a >> b;
	int k, k1;
	cin >> k >> k1;
	int n;
	cin >> n;
	int ans;
	//max
	if(k < k1){
		int mx = min(n / k, a);
		int ot = n - (mx * k);
		mx += min(b, (ot / k1));
		ans = mx;
	}
	else{
		int mx = min(n / k1, b);
		int ot = n - (mx * k1);
		mx += min(a, ot / k);
		ans = mx;
	}
	//min
	int ans1;
	if(n >= ((a * k) + (b * k1))){
		ans1 = (a + b);
	}
	else{
		int sum = (a * (k - 1)) + (b * (k1 - 1));
		if(sum >= n){
			ans1 = 0;
		}
		else{
			ans1 = min(a + b, n - (sum));
		}
	}
	cout << ans1 << " " << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

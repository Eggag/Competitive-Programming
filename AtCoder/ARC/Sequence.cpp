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
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll ans = 0;
	ll sum = a[0];
	if(sum <= 0){
		ans += -a[0] + 1;
		sum = 1;
	}
	repn(i, 1, n){
		if(i & 1){
			if(a[i] < 0){
				sum += a[i];
				if(sum >= 0) ans += sum + 1, sum = -1;
			}
			else{
				ans += sum + a[i] + 1;
				sum = -1;
			}
		}
		else{
			if(a[i] >= 0){
				sum += a[i];
				if(sum <= 0) ans += -sum + 1, sum = 1;
			}
			else{
				ans += -sum + -a[i] + 1;
				sum = 1;
			}
		}
	}
	ll ans1 = 0;
	ll sum1 = a[0];
	if(sum1 >= 0){
		ans1 += a[0] + 1;
		sum1 = -1;
	}
	repn(i, 1, n){
		if(i % 2 == 0){
			if(a[i] < 0){
				sum1 += a[i];
				if(sum1 >= 0) ans1 += sum1 + 1, sum1 = -1;
			}
			else{
				ans1 += sum1 + a[i] + 1;
				sum1 = -1;
			}
		}
		else{
			if(a[i] >= 0){
				sum1 += a[i];
				if(sum1 <= 0) ans1 += -sum1 + 1, sum1 = 1;
			}
			else{
				ans1 += -sum1 + -a[i] + 1;
				sum1 = 1;
			}
		}
	}
	cout << min(ans1, ans) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

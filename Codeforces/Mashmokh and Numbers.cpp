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
	int n, k;
	cin >> n >> k;
	//seems like it is -1 when k is less than n / 2
	if(k < n / 2){
		cout << -1 << endl;
		return 0;
	}
	if(n == 1 && k){
		cout << -1 << endl;
		return 0;
	}
	if(n == 1 && !k){
		cout << 1 << endl;
		return 0;
	}
	else{
		int res = n / 2 - 1;
		int num = k - res;
		int cur = num * 2 + 1;
		cout << num << " " << num * 2 << " ";
		rep(i, (n / 2) - 1){
			cout << cur << " " << cur + 1 << " ";
			cur += 2;
		}
		if(n & 1) cout << cur << endl;
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

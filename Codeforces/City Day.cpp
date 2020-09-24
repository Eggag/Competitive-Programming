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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, x, y;
	cin >> n >> x >> y;
	vi a(n);
	rep(i, n) cin >> a[i];
	rep(i, n){
		int f = 1;
		int it = i - 1;
		int cnt = x;
		while(it >= 0 && cnt){
			if(a[it] <= a[i]) f = 0;
			it--;
			cnt--;
		}
		it = i + 1;
		cnt = y;
		while(it < n && cnt){
			if(a[it] <= a[i]) f = 0;
			it++;
			cnt--;
		}
		if(f){
			cout << i + 1 << endl;
			return 0;
		}
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

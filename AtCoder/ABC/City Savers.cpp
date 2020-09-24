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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n + 1), b(n);
	ll sum = 0;
	rep(i, n + 1) cin >> a[i], sum += a[i];
	rep(i, n) cin >> b[i];
	//simple greedy lol
	rep(i, n){
		//do current
		if(b[i] >= a[i]){
			b[i] -= a[i];
			a[i] = 0;
		}
		else{
			a[i] -= b[i];
			b[i] = 0;
		}
		//do next
		if(b[i] >= a[i + 1]){
			b[i] -= a[i + 1];
			a[i + 1] = 0;
		}
		else{
			a[i + 1] -= b[i];
			b[i] = 0;
		}
	}
	ll rem = 0;
	rep(i, n + 1) rem += a[i];
	cout << sum - rem << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

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
	int n, m;
	cin >> n >> m;
	vi a(3, 0), a1(3, 0);
	while(n % 2 == 0){
		n /= 2;
		a[0]++;
	}
	while(n % 3 == 0){
		n /= 3;
		a[1]++;
	}
	while(n % 5 == 0){
		n /= 5;
		a[2]++;
	}
	while(m % 2 == 0){
		m /= 2;
		a1[0]++;
	}
	while(m % 3 == 0){
		m /= 3;
		a1[1]++;
	}
	while(m % 5 == 0){
		m /= 5;
		a1[2]++;
	}
	if(n != m){
		cout << -1 << endl;
		return 0;
	}
	cout << abs(a[0] - a1[0]) + abs(a[1] - a1[1]) + abs(a[2] - a1[2]) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

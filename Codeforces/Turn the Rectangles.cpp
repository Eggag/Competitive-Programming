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
	int n;
	cin >> n;
	vi b(n), a(n);
	rep(i, n){
		cin >> a[i] >> b[i];
	}
	int s[n];
	s[0] = max(a[0], b[0]);
	bool f = 1;
	repn(i, 1, n){
		int one = min(a[i], b[i]);
		int two = max(a[i], b[i]);
		if(two <= s[i - 1]){
			s[i] = two;
		}
		else if(one <= s[i - 1]){
			s[i] = one;
		}
		else{
			f = 0;
			break;
		}
	}
	if(f){
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

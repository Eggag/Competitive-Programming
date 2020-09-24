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
	string s;
	cin >> s;
	int zero = 0, one = 0, two = 0;
	rep(i, n){
		zero += (s[i] == '0');
		one += (s[i] == '1');
		two += (s[i] == '2');
	}
	if(zero < n / 3){
		rep(i, n){
			if(zero == n / 3) break;
			if(s[i] == '1' && one > n / 3) one--, zero++, s[i] = '0';
			if(s[i] == '2' && two > n / 3) two--, zero++, s[i] = '0';
		}
	}
	if(one < n / 3){
		rep(i, n){
			if(one == n / 3) break;
			if(s[i] == '2' && two > n / 3) two--, one++, s[i] = '1';
		}
		int numZ = 0;
		rep(i, n){
			if(numZ >= n / 3){
				if(one == n / 3) break;
				if(s[i] == '0' && zero > n / 3) zero--, one++, s[i] = '1';
			}
			if(s[i] == '0') numZ++;
		}
	}
	if(two < n / 3){
		for(int i = n - 1; i >= 0; i--){
			if(two == n / 3) break;
			if(s[i] == '1' && one > n / 3) one--, two++, s[i] = '2';
		}
		for(int i = n - 1; i >= 0; i--){
			if(two == n / 3) break;
			if(s[i] == '0' && zero > n / 3) zero--, two++, s[i] = '2';
		}
	}
	cout << s << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

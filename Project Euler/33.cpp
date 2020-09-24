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
	int ans = 1, ans1 = 1;
	repn(i, 1, 100) repn(j, 1, 100){
		int i1 = i, j1 = j;
		if(i >= j) continue;
		if(i1 > 9 && j1 > 9){
			string s = to_string(i1);
			string s1 = to_string(j1);
			if(s[0] == s1[1] && s[0] != '0'){
				int i2 = i1, j2 = j1;
				int num = s[1] - '0';
				int den = s1[0] - '0';
				if(!num || !den) goto here;
				int g = gcd(i2, j2);
				i2 /= g, j2 /= g;
				int g1 = gcd(num, den);
				num /= g1, den /= g1;
				if(num == i2 && den == j2){
					//cout << s << " / " << s1 << endl;
					ans *= i1;
					ans1 *= j1;
				}
				continue;
			}
here:;
			if(s[0] == s1[0] && s[0] != '0'){
				int i2 = i1, j2 = j1;
				int num = s[1] - '0';
				int den = s1[1] - '0';
				if(!num || !den) goto here1;
				int g = gcd(i2, j2);
				i2 /= g, j2 /= g;
				int g1 = gcd(num, den);
				num /= g1, den /= g1;
				if(num == i2 && den == j2){
					//cout << s << " / " << s1 << endl;
					ans *= i1;
					ans1 *= j1;
				}
				continue;	
			}
here1:;
			if(s[1] == s1[0] && s[1] != '0'){
				int i2 = i1, j2 = j1;
				int num = s[0] - '0';
				int den = s1[1] - '0';
				if(!num || !den) goto here2;
				int g = gcd(i2, j2);
				i2 /= g, j2 /= g;
				int g1 = gcd(num, den);
				num /= g1, den /= g1;
				if(num == i2 && den == j2){
					//cout << s << " / " << s1 << endl;
					ans *= i1;
					ans1 *= j1;
				}
				continue;
			}
here2:;
			if(s[1] == s1[1] && s[1] != '0'){
				int i2 = i1, j2 = j1;
				int num = s[0] - '0';
				int den = s1[0] - '0';
				if(!num || !den) continue;;
				int g = gcd(i2, j2);
				i2 /= g, j2 /= g;
				int g1 = gcd(num, den);
				num /= g1, den /= g1;
				if(num == i2 && den == j2){
					//cout << s << " / " << s1 << endl;
					ans *= i1;
					ans1 *= j1;
				}
				continue;
			}
		}
	}	
	int gc = gcd(ans, ans1);
	ans /= gc, ans1 /= gc;
	cout << ans1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

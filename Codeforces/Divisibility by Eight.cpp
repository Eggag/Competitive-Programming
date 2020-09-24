#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
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
	string s;
	cin >> s;
	int n = (int)s.size();
	rep(i, n){
		if((s[i] - '0') % 8 == 0){
			cout << "YES" << endl;
			cout << s[i] << endl;
			return 0;
		}
	}
	rep(i, n) repn(j, i + 1, n){
		int num = (s[i] - '0') * 10 + (s[j] - '0');
		if(num % 8 == 0){
			cout << "YES" << endl;
			cout << s[i] << s[j] << endl;
			return 0;
		}
	}
	rep(i, n) repn(j, i + 1, n) repn(k, j + 1, n){
		int num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
		if(num % 8 == 0){
			cout << "YES" << endl;
			cout << s[i] << s[j] << s[k] << endl;
			return 0;
		}
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

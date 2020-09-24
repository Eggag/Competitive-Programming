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
	freopen("1.txt", "r", stdin);
	//freopen("output.out", "w", stdout);
	vector<string> s(100);
	rep(i, 100){
		cin >> s[i];
		reverse(all(s[i]));
	}
	string ans = s[0];
	repn(i, 1, 100){
		string ans1 = "";
		int carry = 0;
		rep(j, ans.size()){
			if((int)s[i].size() > j){
				int cur = (ans[j] - '0') + (s[i][j] - '0') + carry;
				carry = 0;
				ans1 += (char)((cur - ((cur / 10) * 10) + '0'));		
				if(cur >= 10) carry = cur / 10;
			}
			else{
				int cur = (ans[j] - '0') + carry;
				carry = 0;
				ans1 += (char)((cur - ((cur / 10) * 10) + '0'));
				if(cur >= 10) carry = cur / 10;
			}
		}
		if(carry) ans1 += (char)(carry + '0');
		ans = ans1;
	}
	reverse(all(ans));
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

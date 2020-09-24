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
	string s;
	ll k;
	cin >> s >> k;
	int n = (int)(s.size());
	int f = 1;
	repn(i, 1, n){
		if(s[i] != s[i - 1]){
			f = 0;
			break;
		}
	}
	if(f){
		cout << (n * k) / 2 << endl;
		return 0;
	}
	if(s[0] == s[n - 1]){
		int ind = 1;
		ll cur = 1;
		while(ind < n && s[ind] == s[0]){
			cur++;
			ind++;
		}
		int ind1 = n - 1;
		while(ind1 > 0 && ind1 >= ind && s[0] == s[ind1]){
			cur++;
			ind1--;
		}
		ll ans1 = (cur / 2) * (k - 1);
		ll ans = 0;
		cur = 1;
		repn(i, ind + 1, ind1 + 1){
			if(s[i] == s[i - 1]){
				cur++;
			}
			else{
				ans += cur / 2;
				cur = 1;
			}
		}
		ans += cur / 2;
		cur = 1;
		ind1 = n - 2;
		while(ind1 > 0 && ind1 >= ind && s[n - 1] == s[ind1]){
			cur++;
			ind1--;
		}
		ind = 1;
		ll cur1 = 1;
		while(ind < n && s[ind] == s[0]){
			cur1++;
			ind++;
		}
		ans *= k;
		ans += cur / 2;
		ans += cur1 / 2;
		cout << ans + ans1 << endl;
	}
	else{
		ll ans = 0;
		ll cur = 1;
		repn(i, 1, n){
			if(s[i] == s[i - 1]){
				cur++;
			}
			else{
				ans += cur / 2;
				cur = 1;
			}
		}
		ans += (cur / 2);
		ans *= k;
		cout << ans << endl;
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

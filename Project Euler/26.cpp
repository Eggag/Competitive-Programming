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
	int ret = 0;
	int best = 0;
	repn(i, 2, 1000){
		int num = 10;
		int den = i;
		string ans = "0.";
		map<int, pi> m;
		while(1){
			int cnt = 0;
			while(num < den){
				num *= 10;
				if(cnt) ans += '0';
				cnt++;
			}
			ans += (num / den) + '0';
			int n = (num / den) * den;
			num -= n;
			if(num == 0) break;
			if(m[num].fi){
				if(((int)ans.size() - m[num].se) > ret){
					best = i;
					ret = (int)ans.size() - m[num].se;
				}
				break;
			}
			m[num].fi = 1;
			m[num].se = ans.size();
		}
	}	
	cout << best << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

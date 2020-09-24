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

void solve(){
	int n, n1, n2;
	cin >> n >> n1 >> n2;
	vector<string> st = {"01", "11", "00"};
	rep(i, 3){
		//try to start with st[i]
		string res = st[i];
		int m = n, m1 = n1, m2 = n2;
		if(!i) m1--;
		else if(i == 1) m2--;
		else m--;
		int f = 1;
		while(m > 0 || m1 > 0 || m2 > 0){
			if(m < 0 || m1 < 0 || m2 < 0){
				f = 0;
				break;
			}
			char lst = res[(int)res.size() - 1];
			if(lst == '0'){
				if(m1 <= 0 && m <= 0){
					f = 0;
					break;
				}
				if(m1 > m) res += '1', m1--;
				else res += '0', m--;
			}
			else{
				if(m1 <= 0 && m2 <= 0){
					f = 0;
					break;
				}
				if(m1 > m2) res += '0', m1--;
				else res += '1', m2--;
			}
		}
		if(f){
			cout << res << endl;
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

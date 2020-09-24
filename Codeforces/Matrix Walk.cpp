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
	vi a(n);
	rep(i, n) cin >> a[i];
	repn(i, 1, n){
		if(a[i] == a[i - 1]){
			cout << "NO" << endl;
			return 0;
		}
	}
	set<int> st;
	repn(i, 1, n){
		if(abs(a[i] - a[i - 1]) != 1){
			st.insert(abs(a[i] - a[i - 1]));
		}
	}
	if(st.size() > 1) cout << "NO" << endl;
	else{
		if(st.empty()){
			cout << "YES" << endl;
			cout << (int)1e9 << " " << 1 << endl;
			return 0;
		}
		int mx = *st.begin();
		int lev = 0, cur = ((a[0] - 1) % mx) + 1;
		int l = lev, r = lev;
		repn(i, 1, n){
			if(a[i] == (a[i - 1] + 1)){
				if(cur < mx) cur++;
				else{
					cout << "NO" << endl;
					return 0;
				}
			}
			else if(a[i] == (a[i - 1] - 1)){
				if(cur > 1) cur--;
				else{
					cout << "NO" << endl;
					return 0;
				}
			}
			else{
				if(a[i] == (a[i - 1] + mx)) lev++, r = max(r, lev);
				else if(a[i] == (a[i - 1] - mx)) lev--, l = min(l, lev);
				else{
					cout << "NO" << endl;
					return 0;
				}
			}
		}
		if(abs(r - l) <= 1e9){
			cout << "YES" << endl;
			cout << (int)1e9 << " " << *st.begin() << endl;
		}
		else cout << "NO" << endl;
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

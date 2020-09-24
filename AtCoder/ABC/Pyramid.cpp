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
	vi x(n), y(n), z(n);
	rep(i, n) cin >> x[i] >> y[i] >> z[i];
	rep(i, 101) rep(j, 101){
		//(i, j) is our guess
		int f1 = 1;
		int h;
		int used = -1;
		rep(k, n) if(z[k]){
			h = z[k] + abs(x[k] - i) + abs(y[k] - j);
			used = k;
			break;
		}
		assert(used != -1);
		rep(k, n) if(k != used){
			int al = max(0, h - abs(x[k] - i) - abs(y[k] - j));
			if(al != z[k]){
				f1 = 0;
				break;
			}
		}
		if(f1){
			cout << i << " " << j << " " << h << endl;
			return 0;
		}
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

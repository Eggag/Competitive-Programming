#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

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
	int q;
	cin >> q;
	int len = ceil(sqrt(n));
	vi b(len + 1, -1);
	rep(i, q){
		int type;
		cin >> type;
		if(type == 1){
			int p, x;
			cin >> p >> x;
			p--;
			int cur = p / len;
			if(b[cur] != -1){
				for(int j = cur * len; j < ((cur + 1) * len) && j < n; j++){
					a[j] = max(a[j], b[cur]);
				}
				b[cur] = -1;
			}
			a[p] = x;
		}
		else{
			int x;
			cin >> x;
			for(int j = 0; j * len < n; j++){
				b[j] = max(b[j], x);
			}
		}
	}
	rep(i, n){
		a[i] = max(a[i], b[i / len]);
	}
	rep(i, n) cout << a[i] << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

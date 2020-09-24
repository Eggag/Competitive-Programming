#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int pos[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n + 1);
	repn(i, 1, n + 1) cin >> a[i], pos[a[i]] = i;
	int ans = 0;
	repn(i, 1, n + 1){
		if(a[i] != i){
			ans++;
			pos[a[i]] = pos[i];
			swap(a[i], a[pos[i]]);
		}
	}
	//debug(ans);
	//repn(i, 1, n + 1) cout << a[i] << " ";
	//cout << endl;
	if((ans & 1) == ((3 * n) & 1)) cout << "Petr" << endl;
	else cout << "Um_nik" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

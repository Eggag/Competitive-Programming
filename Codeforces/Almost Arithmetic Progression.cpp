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
	vi b(n);
	rep(i, n) cin >> b[i];
	int ans = 1e9;
	rep(i, 3) rep(j, 3){
		vi a = b;
		int cnt = 0;
		if(i == 1) a[0]++, cnt++;
		if(i == 2) a[0]--, cnt++;
		if(j == 1) a[1]++, cnt++;
		if(j == 2) a[1]--, cnt++;
		int num = a[1] - a[0];
		int f = 1;
		repn(k, 2, n){
			int now = a[k] - a[k - 1];
			if(now != num){
				if((now - 1) == num) a[k]--, cnt++;
				else if((now + 1) == num) a[k]++, cnt++; 
				else{
					f = 0;
					break;
				}
			}
		}
		if(!f) continue;
		ans = min(cnt, ans);
	}
	cout << (ans == 1e9 ? -1 : ans) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

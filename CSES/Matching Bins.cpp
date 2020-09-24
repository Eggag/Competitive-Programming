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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int cnt[1005], cnt1[1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int m, n;
	cin >> m >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	reverse(all(a));
	int ans = 0;
	for(int i = n - 1; i >= 0; i--){
		if(((n - 1) - i) & 1){
			cnt[a[i]]++;
			int num1 = n - 1 - ((n - 1) - i) / 2;
			int el = a[num1];
			cnt[el]--;
			cnt1[el]++;
			int f = 1;
			int num = 0;
			repn(j, 1, m + 1){
				if(cnt[j]){
					if(num < cnt[j]){
						f = 0;
						break;
					}	
					else num -= cnt[j];
				}
				if(cnt1[j]) num += cnt1[j];
			}
			if(f) ans = max(ans, n - i);
		}
		else{
			cnt[a[i]]++;
		}
	}
	cout << ans / 2 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

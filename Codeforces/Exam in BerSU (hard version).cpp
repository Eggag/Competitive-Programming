#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi t(n);
	rep(i, n) cin >> t[i];
	vi sum(n + 1, 0);
	rep(i, n) sum[i + 1] = sum[i] + t[i];
	vi cnt(101, 0);
	rep(i, n){
		vi cnt1 = cnt;
		if(sum[i + 1] <= m){
			cout << 0 << " ";
		}
		else{
			int cur = sum[i + 1];		
			int mn = 0;
			for(int j = 100; j >= 1; j--){
				if(cur <= m) break;
				if(cur - cnt[j] * j >= m){
					cur -= cnt[j] * j;
					mn += cnt[j];
				}
				else{
					int now = (cur - m) / j;
					if((cur - m) % j != 0) now++;
					mn += now;
					break;
				}
			}
			cout << mn << " ";
		}
		cnt[t[i]]++;
	}
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

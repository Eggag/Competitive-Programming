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
	int n, m;
	cin >> n >> m;
	int n1 = n, m1 = m;
	vi a(m + n, 0);
	a[0] = 1; //1 for blue and 0 for red
	m1--;
	int ans = 0, ans1 = 0;
	repn(i, 1, n + m){
		if(i & 1){
			if(a[i - 1] == 1){
				if(n1){
					n1--;
					a[i] = 0;
					ans1++;
				}
				else{
					m1--;
					a[i] = 1;
					ans++;
				}
			}
			else{
				if(m1){
					m1--;
					a[i] = 1;
					ans1++;
				}
				else{
					n1--;
					a[i] = 0;
					ans++;
				}
			}
		}
		else{
			if(a[i - 1] == 1){
				if(m1){
					m1--;
					a[i] = 1;
					ans++;
				}
				else{
					n1--;
					a[i] = 0;
					ans1++;
				}
			}
			else{
				if(n1){
					n1--;
					a[i] = 0;
					ans++;
				}
				else{
					m1--;
					a[i] = 1;
					ans1++;
				}
			}
		}
	}
	int cur = 0, cur1 = 0;
	n1 = n, m1 = m;
	rep(i, m + n) a[i] = 0;
	n1--;
	repn(i, 1, n + m){
		if(i & 1){
			if(a[i - 1] == 1){
				if(n1){
					n1--;
					a[i] = 0;
					cur1++;
				}
				else{
					m1--;
					a[i] = 1;
					cur++;
				}
			}
			else{
				if(m1){
					m1--;
					a[i] = 1;
					cur1++;
				}
				else{
					n1--;
					a[i] = 0;
					cur++;
				}
			}
		}
		else{
			if(a[i - 1] == 1){
				if(m1){
					m1--;
					a[i] = 1;
					cur++;
				}
				else{
					n1--;
					a[i] = 0;
					cur1++;
				}
			}
			else{
				if(n1){
					n1--;
					a[i] = 0;
					cur++;
				}
				else{
					m1--;
					a[i] = 1;
					cur1++;
				}
			}
		}
	}
	if(cur > ans) cout << cur << " " << cur1 << endl;
	else cout << ans << " " << ans1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

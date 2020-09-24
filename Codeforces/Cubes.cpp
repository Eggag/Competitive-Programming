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

vi p[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vi a(n);
	rep(i, n) cin >> a[i], p[a[i]].pb(i);
	int ans = 1;
	repn(i, 1, m + 1){
		int k1 = k;
		queue<int> q;
		int cur = 1; //the first one
		repn(j, 1, p[i].size()){
			if((p[i][j] - p[i][j - 1] - 1) <= k1){
				cur++;
				k1 -= (p[i][j] - p[i][j - 1] - 1);
				q.push(p[i][j] - p[i][j - 1] - 1);
			}
			else{
				while((p[i][j] - p[i][j - 1] - 1) > k1 && !q.empty()){
					k1 += q.front();
					q.pop();
					cur--;
				}
				if(q.size()){
					cur++;
					k1 -= (p[i][j] - p[i][j - 1] - 1);
					q.push(p[i][j] - p[i][j - 1] - 1);
				}
				else cur = 1, k1 = k;
			}
			ans = max(ans, cur);
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

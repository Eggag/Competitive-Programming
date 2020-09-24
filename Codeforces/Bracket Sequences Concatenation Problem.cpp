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
	vector<string> s(n);
	vector<pi> cnt(n), cnt1(n);
	rep(i, n) cnt[i] = {0, 0}, cnt1[i] = {0, 0};
	rep(i, n) cin >> s[i];
	map<int, int> dif;
	int emp = 0;
	rep(i, n){
		int cl = 0, op = 0;
		rep(j, (int)s[i].size()){
			if(s[i][j] == '('){
				cnt[i].fi++;
			}
			else{
				if(cnt[i].fi <= cnt[i].se){
					cl++;
				}
				else cnt[i].se++;
			}
		}
		op = max(0, cnt[i].fi - cnt[i].se);
		cnt1[i] = mp(cl, op);
		if(!cl && !op){
			emp++;
		}
		else if(!cl || !op){
			if(!op){
				dif[-cl]++;
			}
			else{
				dif[op]++;
			}
		}
	}
	ll ans = 0, ans1 = 0;
	rep(i, n){
		if(cnt1[i].fi && cnt1[i].se) continue;
		if(!cnt1[i].fi && !cnt1[i].se){
			ans1 += emp;
		}
		else{
			if(!cnt1[i].fi){
				ans += dif[-cnt1[i].se];
			}
			else{
				ans += dif[cnt1[i].fi];
			}
		}
	}
	cout << ans1 + ans / 2 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

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

vector<string> keys = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int num(string s){
	rep(i, keys.size()) if(s == keys[i]) return i;
}

bool dp[2005][2005][15];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<string> s(n + 1);
	repn(i, 1, n + 1) cin >> s[i];
	int mn = 0; //the minimum number of changes
	vi d(n);
	rep(i, n){
		int cur = 1e9;
		rep(j, keys.size()){
			int nm = 0;
			int f = 1;
			rep(p, s[i].size()){
				if(s[i][p] == '1' && keys[j][p] == '0'){
					f = 0;
					break;
				}
				if(s[i][p] == '0' && keys[j][p] == '1') nm++;
			}
			if(f) cur = min(cur, nm);
		}
		d[i] = cur;
		mn += cur;
	}
	if(mn > k){
		cout << -1 << endl;
		return 0;
	}
	dp[n + 1][0][0] = 1;
	for(int i = n; i >= 1; i--){
		rep(j, k + 1){ //how many left from last one
			int f1 = 0;
			rep(m, 10){
				if(dp[i + 1][j][m]){
					f1 = 1;
					break;
				}
			}
			if(!f1) continue;
			rep(m, 10){
				int nm = 0;
				int f = 1;
				rep(p, s[i].size()){
					if(s[i][p] == '1' && keys[m][p] == '0'){
						f = 0;
						break;
					}
					if(s[i][p] == '0' && keys[m][p] == '1') nm++;
				}
				if((nm + j) <= k && f){
					dp[i][j + nm][m] = 1;
				}
			}
		}
	}
	int gd = 0;
	rep(i, 10){
		if(dp[1][k][i]){
			gd = 1;
			break;
		}
	}
	if(!gd){
		cout << -1 << endl;
		return 0;
	}
	//now, the answer
	int rem = k;
	repn(i, 1, n + 1){
		int mx = 0;
		int need = 0;
		rep(j, 10) if(dp[i][rem][j]){
			//try to make that digit
			int nm = 0;
			int f = 1;
			rep(k, s[i].size()){
				if(s[i][k] == '1' && keys[j][k] == '0'){
					f = 0;
					break;
				}
				if(s[i][k] == '0' && keys[j][k] == '1') nm++;
			}
			if(f){
				mx = max(mx, j);
				need = nm;
			}
		}
		cout << mx;
		rem -= need;
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

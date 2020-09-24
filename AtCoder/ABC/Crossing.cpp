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
	int n1 = n * 2;
	vi div;
	for(int i = 1; (i * i) <= n1; i++){
		if(n1 % i == 0){
			div.pb(i);
			if((n1 / i) != i) div.pb(n1 / i);
		}
	}
	rep(i, div.size()){
		int cur = 0, num = 1, cur1 = cur + 1;
		vi res[div[i]];
		int f = 1;
		while(num <= n1 && cur < div[i]){
			if(cur >= div[i]){
				f = 0;
				break;
			}
			if(res[cur].size() == (n1 / div[i])){
				if(cur1 < (div[i] - 1)){
					f = 0;
					break;
				}
				cur++;
				cur1 = cur + 1;
				continue;
			}
			if(cur1 == div[i]){
				f = 0;
				break;
			}
			res[cur].pb(num);
			res[cur1].pb(num);
			cur1++;
			num++;
		}
		if(f){
			cout << "Yes" << endl;
			cout << div[i] << endl;
			rep(j, div[i]){
				cout << res[j].size() << " ";
				rep(k, res[j].size()) cout << res[j][k] << " ";
				cout << endl;
			}
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

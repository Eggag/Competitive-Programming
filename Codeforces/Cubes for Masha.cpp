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
	//the ub on the ans is 999
	//iterate and see if it is possible?
	vector<set<int>> st(3);
	rep(i, n){
		rep(j, 6){
			int a;
			cin >> a;
			st[i].insert(a);
		}
	}
	int mx;
	if(n == 1) mx = 10;
	if(n == 2) mx = 100;
	if(n == 3) mx = 1000;
	repn(i, 1, mx){
		string s = to_string(i);
		int sz = s.size();
		int f = 0;
		if(sz == 1){
			rep(j, 3){
				//try every cube if it has i
				if(st[j].find(i) != st[j].end()){
					f = 1;
					break;
				}
			}
		}
		if(sz == 2){
			//two digits
			int one = s[0] - '0';
			int two = s[1] - '0';
			rep(j, n){
				if(st[j].find(one) != st[j].end()){
					rep(k, n) if(k != j){
						if(st[k].find(two) != st[k].end()){
							f = 1;
							break;
						}
					}
				}
			}
		}
		if(sz == 3){
			int one = s[0] - '0';
			int two = s[1] - '0';
			int three = s[2] - '0';
			//three digits
			rep(j, n) if(st[j].find(one) != st[j].end()){
				rep(k, n) if(j != k && (st[k].find(two) != st[k].end())){
					rep(l, n){
						if(st[l].find(three) != st[l].end()){
							f = 1;
							break;
						}
					}
				}
			}
		}
		if(!f){
			cout << i - 1 << endl;
			return 0;
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

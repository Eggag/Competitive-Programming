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
	ll n;
	int q;
	cin >> n >> q;
	int lev = 0;
	while((1LL << lev) < n) lev++;
	lev--;
	rep(i, q){
		ll node;
		cin >> node;
		string s;
		cin >> s;
		string path = "";
		ll st = (n + 1) / 2;
		int curLev = lev - 1;
		while(st != node){
			if(st < node){
				path += 'R';
				st += (1LL << curLev);
				curLev--;
			}
			if(st > node){
				path += 'L';
				st -= (1LL << curLev);
				curLev--;
			}
		}
		int n = s.size();
		rep(j, n){
			if(s[j] == 'U'){
				if(path.size()){
					char lst = path[(int)(path.size()) - 1];
					path.pop_back(); //we went up
					if(lst == 'L') st += (1LL << (curLev + 1));
					else st -= (1LL << (curLev + 1));
					curLev++;
				}
			}
			if(s[j] == 'L' && curLev >= 0){
				path += 'L';
				st -= (1LL << curLev);
				curLev--;
			}
			if(s[j] == 'R' && curLev >= 0){
				path += 'R';
				st += (1LL << curLev);
				curLev--;
			}
		}
		cout << st << endl;
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

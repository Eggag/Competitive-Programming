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
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	int n;
	cin >> n;
	map<string, vector<string>> next;
	rep(i, n){
		string name;
		string s, s1, s2, s3;
		string name1;
		cin >> name >> s >> s1 >> s2 >> s3 >> name1;
		next[name].pb(name1);
	}
	vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
	sort(all(cows));
	do{
		int f = 1;
		rep(i, 8){
			for(string s : next[cows[i]]){
				if(!((i > 0 && cows[i - 1] == s) || (i < 7 && cows[i + 1] == s))){
					f = 0;
				}
			}
		}
		if(f){
			rep(i, cows.size()){
				cout << cows[i] << endl;
			}
			return 0;
		}
	} while(next_permutation(all(cows)));
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

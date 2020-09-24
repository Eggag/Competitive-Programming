#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

struct NumbersChallenge{
	int MinNumber(vi s){
             	ios_base::sync_with_stdio(false);
	       	cin.tie(0);
		set<int> p;
		int n = s.size();
		repn(i, 1, 1 << n){
			int sum = 0;
			rep(j, n){
				if(i & (1 << j)) sum += s[j];
			}
			p.insert(sum);
		}
		repn(i, 1, 2000005){
			if(p.find(i) == p.end()){
				return i;
			}
		}
		return 0;
	}
};
/*
Things to look out for:
        - Integer overflows
        - Array bounds
        - Special cases
Be careful!
*/
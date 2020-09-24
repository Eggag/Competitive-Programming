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

int o[2];

struct NumberofFiboCalls{
	int fib(int num){
		if(num == 0){ o[0]++; return 0; }
		if(num == 1){ o[1]++; return 1; }
		return fib(num - 1) + fib(num - 2);
	}
	vi fiboCallsMade(int n){
             	ios_base::sync_with_stdio(false);
	       	cin.tie(0);
	       	o[0] = 0, o[1] = 0;
		fib(n);
		return {o[0], o[1]};
	}
};
/*
Things to look out for:
        - Integer overflows
        - Array bounds
        - Special cases
Be careful!
*/
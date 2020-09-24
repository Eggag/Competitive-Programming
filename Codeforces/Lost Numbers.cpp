#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	vi p = {4, 8, 15, 16, 23, 42};
	vi p1 = p;
	int ans[4];
	rep(i, 4){
		cout << "? " << i + 1 << " " << i + 2 << endl;
		cin >> ans[i];
	}
	do{
		bool good = 1;
		rep(i, 4)
			good &= (ans[i] == p[i] * p[i + 1]);
		if(good) break;
	}while(next_permutation(all(p)));
	cout << "!";
	rep(i, 5){
		cout << " " << p[i];
	}
	int sum = 0;
	rep(i, 5) sum += p[i];
	cout << " " << 108 - sum << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

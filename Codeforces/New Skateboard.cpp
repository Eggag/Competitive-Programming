#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string w;
	cin >> w;
	ll ans = 0;
	for(int i = 0; i < w.size(); i++){
		int d = w[i] - '0';
		if(d % 4 == 0) ans++;
		if(i){
			int o = w[i - 1] - '0';
			if((o * 10 + d) % 4 == 0){
				ans += i;
			}
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

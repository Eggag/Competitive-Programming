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
	int n;
	cin >> n;
	int ans = 0, cnt = 0, prev = 0;
	int p;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x == prev){
			cnt++;
		}
		else{
			p = cnt;
			cnt = 1;
		}
		prev = x;
		ans = max(ans, 2 * min(p, cnt));
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

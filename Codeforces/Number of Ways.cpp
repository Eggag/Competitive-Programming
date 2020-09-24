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
	ll a[n];
	ll sum[n + 1];
	sum[0] = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
	}
	if(sum[n] % 3 != 0){
		cout << "0" << endl;
		return 0;
	}
	int cnt = 0;
	ll ans = 0;
	for(int i = 1; i < n; i++){
		if(3 * sum[i] == sum[n] * 2){
                        ans += cnt;
                }
		if(3 * sum[i] == sum[n]){
                        cnt++;
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

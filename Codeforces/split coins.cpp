#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	int coins[n];
	int sum1 = 0;
	for(int i = 0; i < n; i++){
		cin >> coins[i];
		sum1 += coins[i];
	}
	int sum = 0;
	int ans = 0;
	int j = n - 1;
	sort(coins, coins + n);
	while(sum <= sum1){
		sum += coins[j];
		sum1 -= coins[j];
		j--;
		ans++;
	}	
	cout << ans << endl;
	return 0;
}

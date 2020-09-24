#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int q;
	cin >> q;
	int l[q], r[q];
	for(int i = 0; i < q; i++){
		cin >> l[i] >> r[i];
	}
	int lsum, ssum;
	for(int i = 0; i < q; i++){
		if(r[i] % 2 == 0){
			lsum = r[i]/2;
		}
		else{
			lsum = (r[i] - 1)/2 - r[i];
		}
		if((l[i] - 1) % 2 == 0){
			ssum = (l[i] - 1)/2;
		}
		else{
			ssum = (l[i] - 1)/2 - (l[i] - 1);
		}
		int ans = lsum - ssum;
		cout << ans << endl;
	}
}

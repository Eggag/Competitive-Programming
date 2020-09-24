#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int a[k];
	for(int i = 0; i < k; i++){
		a[i] = 1;
	}
	int sum = k;
	for(int i = 0; i < k; i++){
		while((sum - a[i]) + (a[i]*2) <= n){
			sum -= a[i];
			a[i] *= 2;
			sum += a[i];
		}
	}
	if(sum != n){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
		for(int i = 0; i < k; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

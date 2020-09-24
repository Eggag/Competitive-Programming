#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	int q[4] = {0, 0, 0, 0};
	for(int i = 0; i < n; i++){
		int a; 
		cin >> a;
		q[a - 1]++;
	}
	int sum = 0;
	sum += q[3];
	while(q[2] > 0){
		sum++;
		q[2]--;
		if(q[0] > 0){
			q[0]--;
		}
	}
	while(q[1] > 0){
		sum++;
		q[1]--;
		if(q[1] >= 1){
			q[1]--;
		}
		else{
			if(q[0] >= 2){
				q[0] -= 2;
			}
			else if(q[0] == 1){
				q[0]--;
			}
		}
	}
	while(q[0] > 0){
		if(q[0] <= 4){
			sum++;
		}
		else{
			if(q[0] % 4 == 0){
				sum += q[0]/4;
			}
			else{
				sum += q[0]/4 + 1;
			}
		}
		q[0] = 0;
	}
	cout << sum << endl;
	return 0;
}

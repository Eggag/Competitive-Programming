#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, t;
	cin >> n >> t;
	string queue;
	cin >> queue;
	for(int i = 0; i < t; i++){
		for(int i = 0; i < n; i++){
			if(queue[i] == 'B' && queue[i + 1] == 'G'){
				queue[i] = 'G';
				queue[i + 1] = 'B';
				i++;	
			}
		}
	}
	cout << queue << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, n, sum, req_sum;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n];
	    for (int i = 0; i < n; i++) {
	        cin>>a[i];
	    }
	    cin>>req_sum;
	    int flag = 0;
	    int total = 1 << n;
	    for (int i = 0; i < total; i++) {
	        int sum = 0;
	        for (int j = 0; j < n; j++) {
	            int f = 1 << j;
	            if((i & f) != 0){
	                sum += a[j];
	            }
	        }
	        if(sum == req_sum){
	            cout<<"YES\n";
	            flag = 1;
	            break;
	        }
	    }
	    if(flag == 0){
	        cout<<"NO\n";
	    }
	   
	}
	
	return 0;
}

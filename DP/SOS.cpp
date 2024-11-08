#include <bits/stdc++.h>
using namespace std;

void sos() {
    int n; cin>>n;
    vector<int> arr(1<<n);
    for(int i = 0; i <(1<<n); i++) cin>>arr[i];
    int sos[1 << n] = {0};
    for (int x = 0; x < (1 << n); x++) {
        sos[x] = arr[0];
        for (int i = x; i > 0; i = (i - 1) & x)
            sos[x] += arr[i];
    }
  
    for(int i = 0; i <(1<<n); i++) {
        cout<<sos[i]<< " ";
    }
}

signed main(){
    sos();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        bool found=false;
        long long int a[n], sum[n];
        for(int i=0; i<n; i++) {
            cin>>a[i];
            if(i>0) sum[i]=sum[i-1]+a[i];
            else    sum[i]=a[i];
        }
        if(sum[n-1]-a[0]==0)    found=true;
        for(int i=1; i<n-1; i++) {
            if(sum[i-1]==sum[n-1]-sum[i]) {
                found=true;
                break;
            }
        }
        if(sum[n-2]==0) found=true;
        cout << (found ? "YES" : "NO") << endl;
    }
    return 0;
}

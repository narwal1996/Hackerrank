#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    stack< pair<int,string> > track;
    string res;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            string s;
            cin >> s;
            res += s;
            track.push({1, s});
        } else if(type == 2) {
            int k;
            cin >> k;
            track.push({2,res.substr(res.length()-k, k)});
            res = res.substr(0, res.length()-k);
        } else if(type == 3) {
            int k;
            cin >> k;
            cout << res[k-1] << endl;
        } else {
            if(track.top().first == 1) {
                res = res.substr(0, res.length()-track.top().second.length());
                track.pop();
            } else {
                res += track.top().second;
                track.pop();
            }
        }
    }
    return 0;
}

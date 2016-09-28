#include <bits/stdc++.h>
using namespace std;

int input(stack<int> &h, int n, stack<int> &s) {
    int height = 0;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        height += temp;
        s.push(temp);
    }
    while(!s.empty()) {
        h.push(s.top());
        s.pop();
    }
    return height;
}

int main(){
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    stack<int> h1, h2, h3, s;
    int height1 = input(h1, n1, s);
    int height2 = input(h2, n2, s);
    int height3 = input(h3, n3, s);
    while(!(height1 == height2 && height2 == height3 && height3 == height1)) {
        int temp = max(height1, max(height2, height3));
        if(temp == height1) {
            height1 -= h1.top();
            h1.pop();
        } else if(temp == height2) {
            height2 -= h2.top();
            h2.pop();
        } else {
            height3 -= h3.top();
            h3.pop();
        }
    }
    cout << height1 << endl;
    return 0;
}

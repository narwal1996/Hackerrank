#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        stack<char> st;
        bool isbalanced = true;
        for(int i = (int)s.length()-1; i >= 0; i--) {
            if(st.empty() && (s[i] == '(' || s[i] == '{' || s[i] == '[')) {
                isbalanced = false;
                break;
            } else if(s[i] == ')' || s[i] == '}' || s[i] == ']')   st.push(s[i]);
            else if((s[i] == '(' && st.top() == ')') || (s[i] == '{' && st.top() == '}') || (s[i] == '[' && st.top() == ']'))   st.pop();
            else {
                isbalanced = false;
                break;
            }
        }
        if(!st.empty() || !isbalanced)  cout << "NO" << endl;
        else    cout << "YES" << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

string foo(string s) {
    if (s.size() == 1) return s;
    int ab = 0, ba = 0;
    for (int i=0; i<s.size()-1; i++) {
        string sub = s.substr(i, 2);
        if (sub == "ab") ab++;
        else if (sub == "ba") ba++;
    }
    if (ab == ba) return s;
    string sub = s.substr(0, 2);
    if (ab > ba) {
        if (sub == "aa" or sub == "ab") s[0] = 'b';
        else s[s.size()-1] = 'a';
    } else {
        if (sub == "ba" or sub == "bb") s[0] = 'a';
        else s[s.size()-1] = 'b';
    }
    return s;
}

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t;
    string s;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> s;
        cout << foo(s) << endl;
    }
}
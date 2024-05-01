#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isPalindrome(const string& s) {
    stack<char> st;
    int n = s.length(), mid = n / 2;
    for (int i = 0; i < mid; i++) {
        st.push(s[i]);
    }
    mid = (n + 1) / 2;
    for (int i = mid; i < n; i++) {
        if (st.top() == s[i]) {
            st.pop();
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cout << "Введите строку: ";
    getline(cin, s);
    cout << "\"" << s << "\" - это палиндром: "
        << (isPalindrome(s) ? "да" : "нет") << endl;
}
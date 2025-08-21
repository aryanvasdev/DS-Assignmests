#include<iostream>
#include<string>
using namespace std;
string Sort(string s) {
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j] > s[j + 1]) {
                swap(s[j], s[j + 1]);
            }
        }
    }
    return s;
}

int main() {
    string s1,s2;
    cout << "Enter first string: ";
    cin >> s1;  
    cout << "Enter second string: ";
    cin >> s2;
    s1 = Sort(s1);
    s2 = Sort(s2);
    if (s1 == s2) {
        cout << "Strings are anagrams." << endl;
    } else {
        cout << "Strings are not anagrams." << endl;
    }

}
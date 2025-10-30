#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    string ip;
    cout << "Enter the string: ";
    cin >> ip;
    queue<char> q1;
    string ans;

    int freq[256] = {0};

    for (char c : ip) {
        freq[c]++;

        if (freq[c] == 1) {
            q1.push(c);
        }

        while (!q1.empty() && freq[q1.front()] > 1) {
            q1.pop();
        }

        if (q1.empty()) {
            ans += '#';
        } else {
            ans += q1.front();
        }
    }
    
    cout << "Output: " << ans << endl;
    
    return 0;
}
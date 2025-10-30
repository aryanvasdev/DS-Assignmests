#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> h1;
    queue<int> numbers;
    queue<int> ans;
    numbers.push(10);
    numbers.push(20);
    numbers.push(30);
    numbers.push(40);
    numbers.push(50);
    numbers.push(60);
    int size = numbers.size();

    for(int i = 0; i < size/2; i++) {
        h1.push(numbers.front());
        numbers.pop();
    }
    while(!h1.empty() && !numbers.empty()) {
        ans.push(h1.front());
        h1.pop();
        ans.push(numbers.front());
        numbers.pop();
    }
    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }

    return 0;
}
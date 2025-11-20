#include <iostream>
using namespace std;


class Solution {
public:
    int numTrees(int n) {
        int numTree[1000];   

        for (int i = 0; i <= n; i++) {
            numTree[i] = 0;
        }

        numTree[0] = 1;
        numTree[1] = 1;

        for (int nodes = 2; nodes <= n; nodes++) {
            int total = 0;

            for (int root = 1; root <= nodes; root++) {
                int left  = root - 1;
                int right = nodes - root;

                total += numTree[left] * numTree[right];
            }

            numTree[nodes] = total;
        }

        return numTree[n];
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    int result = solution.numTrees(n);
    std::cout << "Number of unique BSTs with " << n << " nodes: " << result << std::endl;
    return 0;
}
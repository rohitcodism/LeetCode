#include <iostream>

class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0;

        for (int i = 2; i <= n; i++) {
            winner = (winner + k) % i;
        }

        return winner + 1;
    }
};

int main() {
    Solution sol;
    int n = 5;
    int k = 2;

    int winner = sol.findTheWinner(n, k);
    std::cout << "The winner's position with " << n << " friends and k=" << k << " is: " << winner << std::endl;

    return 0;
}

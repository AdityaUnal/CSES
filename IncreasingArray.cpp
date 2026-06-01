#include <cstdint>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    std::cin >> n;

    int64_t moves = 0;
    int64_t previous = 0;
    std::cin >> previous;

    for (int i = 1; i < n; ++i) {
        int64_t value = 0;
        std::cin >> value;
        if (value < previous) {
            moves += previous - value;
        } else {
            previous = value;
        }
    }

    std::cout << moves << "\n";
    return 0;
}
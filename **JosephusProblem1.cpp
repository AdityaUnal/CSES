#include <cstdint>
#include <iostream>
#include <list>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint32_t n;
    std::cin >> n;

    std::list<uint32_t> children;
    for (uint32_t i = 1; i <= n; ++i) {
        children.push_back(i);
    }

    auto it = children.begin();
    while (!children.empty()) {
        ++it;
        if (it == children.end()) {
            it = children.begin();
        }

        std::cout << *it << ' ';

        auto next = it;
        ++next;
        if (next == children.end()) {
            next = children.begin();
        }

        children.erase(it);
        it = next;
    }
    std::cout << '\n';

    return 0;
}

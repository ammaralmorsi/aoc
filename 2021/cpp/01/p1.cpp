#include <iostream>
#include <unordered_set>


int main() {
    std::unordered_set<long long> um;
    long long current, target = 2020;
    while (std::cin >> current) {
        if (um.find(target - current) != um.end()) {
            std::cout << (long long)(current * (target - current)) << std::endl;
            break;
        }
        um.insert(current);
    }
    return 0;
}

#include <iostream>
#include <unordered_set>
#include <vector>


int main() {
    long long current;
    long long target = 2020;
    std::vector<long long> v;
    std::unordered_set<long long> um;

    while (std::cin >> current)
        v.push_back(current);

    for (int i = 0; i < v.size(); ++i) {
        um.clear();
        for (int j = i + 1; j < v.size(); ++j) {
            if (um.find(target - v[i] - v[j]) != um.end()) {
                std::cout << v[j] * (target - v[i] - v[j]) * v[i] << std::endl;
                goto finish;
            }
            um.insert(v[j]);
        }
    }
finish:
    return 0;
}

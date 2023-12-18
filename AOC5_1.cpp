#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <cstdint> 
#include <vector>

void seedToSoil(const std::string &s, std::map<uint64_t, uint64_t> &sts) {
    std::istringstream stream(s);
    std::vector<uint64_t> a(3);
    for (int i = 0; i < 3 && stream >> a[i]; ++i) {}

    for (uint64_t i = 0; i < a[2]; ++i) {
        sts.emplace(a[1] + i, a[0] + i);
    }
}

void findSeed(const std::string &s, std::list<uint64_t> &a1) {
    std::istringstream stream(s);
    uint64_t num;
    while (stream >> num) {
        a1.emplace_back(num);
    }
}

void replace(std::list<uint64_t> &a1, std::map<uint64_t, uint64_t> &sts) {
    for (auto &it : a1) {
        if (sts.find(it) == sts.end()) {
            sts.emplace(it, it);
        }
        it = sts[it];
    }
}

int main() {
    std::string seed, seed1;
    std::getline(std::cin, seed);

    seed = seed.substr(seed.find(" ") + 1);
    std::list<uint64_t> a1;
    findSeed(seed, a1);

    std::map<uint64_t, uint64_t> sts;

    std::getline(std::cin, seed1); // Skip line

    while (std::getline(std::cin, seed1)) {
        if (!seed1.empty()) {
            seedToSoil(seed1, sts);
        } else {
            replace(a1, sts);
            sts.clear();
            if (std::getline(std::cin, seed1) && seed1.empty()) {
                break;
            }
        }
    }

    a1.sort();
    std::cout << a1.front() << std::endl;
    return 0;
}

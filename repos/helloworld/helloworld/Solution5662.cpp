#include "Solution5662.h"
#include <unordered_map>
#include <set>

int Solution5662::minCharacters(string a, string b) {
    /*unordered_map<char, pair<int, int>>hash_map;
    set<char> set_all;
    for (auto& item : a) {
        if (hash_map.count(item)) {
            hash_map.at(item).first++;
        }
        else {
            hash_map.emplace(item, (1, 0));
        }
        set_all.insert(item);
    }
    for (auto& item : b) {
        if (hash_map.count(item)) {
            hash_map.at(item).second++;
        }
        else {
            hash_map.emplace(item, (0, 1));
        }
        set_all.insert(item);
    }*/
    return 1;

}
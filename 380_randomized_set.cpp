#include "common.h"

class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }

    bool insert(int val) {
        if (valueMap.find(val) != valueMap.end()) {
            return false;
        }
        values.push_back(val);
        valueMap[val] = values.size() - 1;  
        return true;
    }

    bool remove(int val) {
        auto it = valueMap.find(val);
        if (it == valueMap.end()) {
            return false;
        }
        int index = it->second;
        std::swap(values[index], values[values.size() - 1]);
        valueMap[values[index]] = index;
        valueMap.erase(val);
        values.pop_back();
        return true;
    }

    int getRandom() {
        return values[rand() % values.size()];
    }
private:
    std::unordered_map<int,int> valueMap;
    std::vector<int> values;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
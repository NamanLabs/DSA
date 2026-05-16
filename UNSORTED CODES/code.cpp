// first non repetitve element in an array

#include <unordered_map>
#include <vector>

int firstNonRepetitive(std::vector<int>& arr) {
    std::unordered_map<int, int> freqMap;
    for (int elem : arr) {
        if (freqMap.find(elem) == freqMap.end()) {
            freqMap[elem] = 1;
        } else {
            freqMap[elem]++;
        }
    }

    for (int elem : arr) {
        if (freqMap[elem] == 1) {
            return elem;
        }
    }

    return -1;  // if no non-repetitive element is found
}

int main() {
    std::vector<int> arr = {2, 4, 3, 5, 2, 4, 6};
    int result = firstNonRepetitive(arr);
    std::cout << "First non-repetitive element: " << result << std::endl;
    return 0;
}
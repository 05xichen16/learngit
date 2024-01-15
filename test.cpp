#include <algorithm>
#include <vector>
#include <string>
#include <iostream>


using namespace std;

class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        // next[0] = 0;
        int i = 0;
        while (i < s.size()) {
            if (j == 0 || s[j] == s[i]) {
                next[i] = j;
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while(j >= 1 && haystack[i] != needle[j]) {
                j = next[j] - 1;
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;

    // Test Case 1: Needle is present in Haystack
    std::string haystack1 = "hello";
    std::string needle1 = "ll";
    int result1 = solution.strStr(haystack1, needle1);
    std::cout << "Test Case 1: " << result1 << " (Expected: 2)" << std::endl;

    // Test Case 2: Needle is not present in Haystack
    std::string haystack2 = "aaaaa";
    std::string needle2 = "bba";
    int result2 = solution.strStr(haystack2, needle2);
    std::cout << "Test Case 2: " << result2 << " (Expected: -1)" << std::endl;

    // Test Case 3: Needle is an empty string
    std::string haystack3 = "hello";
    std::string needle3 = "aabaaf";
    int result3 = solution.strStr(haystack3, needle3);
    std::cout << "Test Case 3: " << result3 << " (Expected: 0)" << std::endl;

    return 0;
}
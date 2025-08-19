#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // If character is already in set, shrink window from left
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            
            // Add current character to set
            charSet.insert(s[right]);
            
            // Update maximum length
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            if (charIndex.find(s[right]) != charIndex.end()) {
                left = max(left, charIndex[s[right]] + 1);
            }
            
            charIndex[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};


int main() {
    
    return 0;
}
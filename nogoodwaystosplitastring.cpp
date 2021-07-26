#include <unordered_map>
/*
 *   https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
 */
using namespace std;

class Solution {
    
    unordered_map<char, size_t> character_count_right;
    unordered_map<char, size_t> character_count_left;
    int count = 0;
    
    public:
    
    int numSplits(string s) {
        
        for(size_t i = 0; i < s.size(); i++){
            character_count_right[s[i]]++;        
        }
        
        for(size_t i = 0; i < s.size() - 1; i++){

            character_count_left[s[i]]++;

            if(character_count_right[s[i]] == 1)
                character_count_right.erase(s[i]);
            else
                character_count_right[s[i]]--;

            if(character_count_left.size() == character_count_right.size())
                count++;
        }
    
        
        return count;
    }
};

class Solution {
public:
    int countOdds(int low, int high) {
        int diff = high - low + 1;
        
        if(diff & 1)
            return (diff - 1) / 2 + (low & 1);
        else
            return diff / 2;
    }
};

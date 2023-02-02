class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < words.size()-1; i++) {
            string first = words[i];
            string second = words[i+1];
            for (int j = 0; j < first.size(); j++) {
                if (j == second.size()) 
                    return false;
                if (j >= first.size()) 
                    return false;
                if (order.find(first[j]) > order.find(second[j]))
                    return false;
                if (order.find(first[j]) < order.find(second[j]))
                    break;
            }
        }
        return true;
    }
};
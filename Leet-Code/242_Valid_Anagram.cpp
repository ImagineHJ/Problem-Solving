class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int >map1, map2;

        if(s.size()!=t.size()) return false; // if the length is different
        // put all in hash map
        for(int i=0; i<s.size(); i++){
            map1[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            map2[t[i]]++;
        }
        for(auto a:map1){
            if(map2[a.first]!=a.second) return false; // num of alphabet is diff
        }
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int >map1, map2;

        if(s.size()!=t.size()) return false; // if the length is different
        // put all in hash map
        for(int i=0; i<s.size(); i++){
            map1[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            map2[t[i]]++;
        }
        for(auto a:map1){
            if(map2[a.first]!=a.second) return false; // num of alphabet is diff
        }
        return true;
    }
};

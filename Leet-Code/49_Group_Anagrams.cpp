class Solution {
public:
    int makeNum(string str){
        int ret = 0;
        for(int i=0; i<str.size(); i++){
            ret+= pow(2, str[i]-'a');
        }
        return ret;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, vector<int>> umap;
        string sorted_str;
        
        for(int i=0; i<strs.size(); i++)
        {
            umap[makeNum(strs[i])].push_back(i);
        }

        vector<vector<string>> answer(umap.size());
        int i=0;
        for(auto s:umap)
        {
            for(int j=0; j<s.second.size(); j++){
                answer[i].push_back(strs[s.second[j]]);
            }
            i++;
        }
        return answer;
    }
};

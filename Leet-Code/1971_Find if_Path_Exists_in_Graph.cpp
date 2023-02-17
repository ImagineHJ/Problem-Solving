class Solution {
public:
    bool visited[200001];
    bool found;
    int destination;
    vector<int> graph[200001];
  
    void dfs(int source){
        int a;
        visited[source]=true;
        for(int i=0; i<graph[source].size(); i++){
            a = graph[source][i];
            if(a==destination) found=true;
            if(found) return;
            if(!visited[a]) dfs(a);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        for(int i=0; i<n; i++) visited[i] = false;
        found = false;
        this-> destination = destination; // initialize
      
        for(auto a: edges){ // make adj lists
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
   
        dfs(source);
        return found;
    }
};

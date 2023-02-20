// Using Topology Sort

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> ans, in_edge(numCourses, 0);
        queue<int> q;
        int c;

        for(auto p : prerequisites){
            graph[p[1]].push_back(p[0]); // make graph
            in_edge[p[0]]++;
        }
        
        for(int i=0; i<numCourses; i++){
            if(in_edge[i]==0) q.push(i);
        }

        while(!q.empty()){
            c = q.front(); q.pop();
            ans.push_back(c);
            for(auto a : graph[c]){
                in_edge[a]--; // remove edges
                if(in_edge[a]==0) q.push(a); // if no more in-edge
            }
        }
        
        for(int i=0; i<numCourses; i++){
            if(in_edge[i]!=0) return vector<int>(); // impossible to finish all courses
        }
        return ans;
    }
};

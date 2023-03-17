class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(numCourses, 0);
        vector<bool> visited(numCourses, false);
        vector<int> order;
        vector<vector<int>> neighbour(numCourses);
        
        for (int i = 0; i < prerequisites.size(); i++) {
            int to = prerequisites[i][0];
            int from = prerequisites[i][1];
            inDeg[to]++;
            neighbour[from].push_back(to);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int curr = q.front();
            visited[curr] = true;
            order.push_back(curr);
            q.pop();
            for (int i = 0; i < neighbour[curr].size(); i++) {
                int to = neighbour[curr][i];
                inDeg[to]--;
                if (inDeg[to] == 0) {
                    q.push(to);
                }
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == false) {
                return vector<int>();
            }
        }
        return order;
    }
};
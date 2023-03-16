class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(numCourses, 0);
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < prerequisites.size(); i++) {
            int to = prerequisites[i][0];
            inDeg[to]++;
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
            q.pop();
            for (int i = 0; i < prerequisites.size(); i++) {
                if (prerequisites[i][1] == curr) {
                    int to = prerequisites[i][0];
                    inDeg[to]--;
                    if (inDeg[to] == 0) {
                        q.push(to);
                    }
                }
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == false) {
                return false;
            }
        }
        return true;
    }
};
#include "common.h"

class Solution {

public:

    void dfs(int u) {
        visited[u] = 1;
        for (int v : edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
        res.push_back(u);

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (auto& dependency : prerequisites) {
            edges[dependency[1]].push_back(dependency[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) {
                dfs(i);
            }
            if (!valid) {
                return {};
            }
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

private:
    //存储课程的依赖关系
    vector<vector<int>>edges;
    //存储是否访问过该节点，0表示未访问，1表示访问中，2表示访问过。
    vector<int>visited;
    bool valid = true;
    vector<int> res;
};
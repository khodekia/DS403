#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);
    vector<set<int>> ancestors(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            ancestors[neighbor].insert(node);
            for (int ancestor : ancestors[node]) {
                ancestors[neighbor].insert(ancestor);
            }

            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int ancestor : ancestors[i]) {
            cout << ancestor << " ";
        }
        cout << endl;
    }

    return 0;
}

//https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        size_t n = graph.size();
        vector<int> dist(n, n + 1);
        vector<int> visited(n, 0);
        queue<int> q;

        for (size_t i = 0; i < graph.size(); i++) {
            //if it is not a lone node and it hasn't been processed yet
            if ((graph[i].size() > 0) && (dist[i] == n + 1)) {
               
                dist[i] = 0;
                q.push(i);

                while (!q.empty()) {
                    //put all of its neighbours in a queue
                    for (size_t j = 0; j < graph[q.front()].size(); j++) {
                        //if the node is not yet processed
                        if (dist[graph[q.front()][j]] == n + 1) {

                            dist[graph[q.front()][j]] = dist[q.front()] + 1;
                            q.push(graph[q.front()][j]);

                        }
                        else { //if the node has already been processed

                            if ((dist[graph[q.front()][j]] - dist[q.front()]) % 2 == 0) {
                                while (!q.empty()) {
                                    q.pop();
                                }

                                return false;
                            }

                        }

                    }

                    q.pop();
                }

            }
        }

        return true;
    }
};

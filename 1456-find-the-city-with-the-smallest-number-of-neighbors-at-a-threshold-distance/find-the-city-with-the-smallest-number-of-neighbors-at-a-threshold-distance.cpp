class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for(const auto& edge : edges){
            int v1 = edge[0];
            int v2 = edge[1];
            int dist = edge[2];

            adj[v1].push_back({v2, dist});
            adj[v2].push_back({v1, dist});
        }

        std::function<int(int)> dijkstra = [&](int src){
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, 
            std::greater<std::pair<int, int>>> minHeap;
            minHeap.push({0, src});

            std::vector<bool> visited(n, false);
            while(!minHeap.empty()){
                auto [dist, node] = minHeap.top();
                minHeap.pop();
                if(visited[node]){
                    continue;
                }
                visited[node] = true;
                for(const auto& [nei, dist2] : adj[node]){
                    int neiDist = dist + dist2;
                    if(neiDist <= distanceThreshold){
                        minHeap.push({neiDist, nei});
                    }
                }

            }

            int reachable = std::count(visited.begin(), visited.end(), true);
            return reachable - 1;
        };

        int result = -1;
        int minCount = n;
        for(int i = 0; i < n; i++){
            int count = dijkstra(i);

            if(count <= minCount){
                result = i;
                minCount = count;
            }
        }

        return result;
    }
};
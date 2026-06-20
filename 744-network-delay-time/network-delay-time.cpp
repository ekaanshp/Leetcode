class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
        for(const auto& time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            graph[u].push_back({v, w});
        }

        std::priority_queue<std::pair<int, int>, 
                            std::vector<std::pair<int, int>>, 
                            std::greater<std::pair<int, int>>> minHeap;
        
        std::vector<bool> visited(n + 1, false);
        int visitCount = 0;
        int t = 0;

        minHeap.push({0, k});
        while(!minHeap.empty()){
            auto [w1, n1] = minHeap.top();
            minHeap.pop();

            if(visited[n1]){
                continue;
            }
            visited[n1] = true;
            visitCount++;
            t = std::max(t, w1);

            for(const auto& [n2, w2] : graph[n1]){
                if(!visited[n2]){
                    minHeap.push({w1 + w2, n2});
                }
            }
        }

        if(visitCount == n){
            return t;
        }
        return -1;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, int>> maxHeap;

        for(int i = 0; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int distance = (x * x) + (y * y);

            if(maxHeap.size() < k){
                maxHeap.push({distance, i});
            }
            else if(distance < maxHeap.top().first){
                maxHeap.pop();
                maxHeap.push({distance, i});
            }
        }

        std::vector<std::vector<int>> result;
        while(!maxHeap.empty()){
            result.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        return result;

    }
};
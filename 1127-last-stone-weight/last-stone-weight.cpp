class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> maxHeap(std::less<int>(), std::move(stones));

        while(maxHeap.size() > 1){
            int stone1 = maxHeap.top();
            maxHeap.pop();

            if(!maxHeap.empty()){
                int stone2 = maxHeap.top();
                maxHeap.pop();
                int difference = stone1 - stone2;
                if(difference != 0){
                    maxHeap.push(difference);
                }
            }
            else{
                return stone1;
            }
        }
        if(!maxHeap.empty()){
            return maxHeap.top();
        }
        else{
            return 0;
        }
    }
};
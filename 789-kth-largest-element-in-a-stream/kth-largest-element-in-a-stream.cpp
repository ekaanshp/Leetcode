class KthLargest {
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
public:
    KthLargest(int k, vector<int>& nums) : k(k){
        for(int value : nums){
            addToHeap(value);
        }
    }

    void addToHeap(int val){
        if(minHeap.size() < k){
            minHeap.push(val);
        }
        else if(val > minHeap.top()){
            minHeap.pop();
            minHeap.push(val);
        }
    }
    
    int add(int val) {
        addToHeap(val);
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
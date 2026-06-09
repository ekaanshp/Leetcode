class KthLargest {
    int kth;
    std::vector<int> input;
    
public:
    KthLargest(int k, vector<int>& nums) : kth(k), input(std::move(nums)){}
    
    int add(int val) {
        input.push_back(val);
        auto target = input.end() - kth;
        std::nth_element(input.begin(), target, input.end());
        return *target;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty() || intervals.size() == 1){
            return 0;
        }
        int nonOverlapCounter = 1;
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b){
            return a[1] < b[1];
        });

        int lastEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= lastEnd){
                nonOverlapCounter++;
                lastEnd = intervals[i][1];
            }
        }
        return intervals.size() - nonOverlapCounter;

    }
};
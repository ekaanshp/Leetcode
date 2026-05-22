class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1){
            return intervals;
        }

        std::sort(intervals.begin(), intervals.end());
        int start = 0;

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= intervals[start][1]){
                intervals[start][1] = std::max(intervals[i][1], intervals[start][1]);
            }
            else{
                start++;
                intervals[start] = intervals[i];
            }
        }
        intervals.erase(intervals.begin() + start + 1, intervals.end());
        return intervals;
    }
};
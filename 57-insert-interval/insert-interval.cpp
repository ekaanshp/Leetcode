class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> returnArray;

        for(int i = 0; i < intervals.size(); i++){
            if(newInterval[1] < intervals[i][0]){
                returnArray.push_back(newInterval);
                returnArray.insert(returnArray.end(), intervals.begin() + i, intervals.end());
                return returnArray;
            }
            else if(newInterval[0] > intervals[i][1]){
                returnArray.push_back(intervals[i]);
            }
            else{
                newInterval = {std::min(newInterval[0], intervals[i][0]), std::max(newInterval[1], intervals[i][1])};
            }
        }

        returnArray.push_back(newInterval);
        return returnArray;
    }
};
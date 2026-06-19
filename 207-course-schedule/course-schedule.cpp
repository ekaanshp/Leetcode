class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> preMap(numCourses);

        for(const auto& prereq : prerequisites){
            int course = prereq[0];
            int pre = prereq[1];
            preMap[course].push_back(pre);
        }

        std::vector<int> visitSet(numCourses, 0);

        std::function<bool(int)> dfs = [&](int course){
            if(visitSet[course] == 1){
                return false;
            }
            if(preMap[course].empty()){
                return true;
            }

            visitSet[course] = 1;
            for(auto pre : preMap[course]){
                if(!dfs(pre)){
                    return false;
                }
            }
            visitSet[course] = 0;
            preMap[course].clear();
            return true;
        };

        for(int crs = 0; crs < numCourses; crs++){
            if(!dfs(crs)){
                return false;
            }
        }
        return true;
    }
};
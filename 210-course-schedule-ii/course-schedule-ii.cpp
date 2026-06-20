class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graph(numCourses);
        std::vector<int> inDegree(numCourses, 0);
        std::deque<int> queue;

        for(const auto& prereq : prerequisites){
            int course = prereq[0];
            int pre = prereq[1];
            graph[pre].push_back(course);
            inDegree[course]++;
        }

        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] == 0){
                queue.push_back(i);
            }
        }

        std::vector<int> result;
        while(!queue.empty()){
            int course = queue.front();
            queue.pop_front();
            result.push_back(course);

            for(auto neighbor : graph[course]){
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0){
                    queue.push_back(neighbor);
                }
            }
        }

        if(result.size() == numCourses){
            return result;
        }

        return {};
    }
};
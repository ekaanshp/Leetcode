class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left = 0, right = cardPoints.size() - k;
        int total = std::accumulate(cardPoints.begin() + right, cardPoints.end(), 0);
        int result = total;

        while(right < cardPoints.size()){
            total += cardPoints[left] - cardPoints[right];
            result = std::max(result, total);
            left++;
            right++;
        }
        return result;
    }
};
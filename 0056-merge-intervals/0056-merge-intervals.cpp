#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort intervals based on the start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        // Start with the first interval
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            // Get the last interval added to our merged list
            vector<int>& lastMerged = merged.back();

            // Check if the current interval overlaps with the last merged one
            // Overlap happens if current_start <= last_merged_end
            if (intervals[i][0] <= lastMerged[1]) {
                // Merge them by updating the end time to the maximum seen so far
                lastMerged[1] = max(lastMerged[1], intervals[i][1]);
            } else {
                // No overlap, add the current interval as a new entry
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
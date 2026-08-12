# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* smallestSufficientTeam(char** req_skills, int req_skillsSize, char*** people, int peopleSize, int* peopleColSize, int* returnSize) {
    int m = req_skillsSize;
    int n = peopleSize;
    int target = 1 << m - 1;

    // Preprocessing for representing people skills into bit
    int skillBit[n];
    for (int i = 0; i < n; i++) {
        skillBit[i] = 0;

        for (int j = 0; j < m; j++) {
            for (int k = 0; k < peopleColSize[i]; k++) {
                if (strcmp(req_skills[j], people[i][k]) == 0) 
                    skillBit[i] |= (1 << j); 
            }
        }
    }

    // Initialize dp table
    int dp[1 << m];
    int parent_mask[1 << m];
    int parent_person[1 << m];
    for (int i = 0; i < 1 << m; i++)
        dp[i] = 100;
    dp[0] = 0;
    
    // Topological order : Bottom-Up
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            if (dp[mask] == 100)
                continue;

            int nmask = mask | skillBit[i];

            if (dp[nmask] > dp[mask] + 1) {
                dp[nmask] = dp[mask] + 1;
                parent_mask[nmask] = mask;
                parent_person[nmask] = i;
            }
        }
    }
   
    *returnSize = dp[target];
    int* ans = (int*)malloc((*returnSize) * sizeof(int));
    int cur = target;
    int idx = *returnSize - 1;
    
    while (cur > 0) {
        ans[idx--] = parent_person[cur];
        cur = parent_mask[cur];
    }

    return ans;
}
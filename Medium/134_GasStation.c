# include <stdio.h>
# include <stdlib.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int cur_gas = 0;
    int start = 0;
    int gasSum = 0;
    int costSum = 0;
    for (int i = 0; i < gasSize; i++) {
        cur_gas += gas[i] - cost[i];
        if (cur_gas < 0) {
            cur_gas = 0;
            start = i + 1;
        }

        gasSum += gas[i];
        costSum += cost[i];
    }

    if (gasSum < costSum)
        return -1;

    return start;
}
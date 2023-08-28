#include "common.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*
        * 通过不等式可以得出，设从x出发，能到的最远的加油站为y，则[x,y]中的任意一个加油站z，都无法到达y+1。
        */
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int count = 0;
            int sumOfGas = 0;
            int sumOfCost = 0;
            while (count < n) {
                int j = (i + count) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfGas < sumOfCost) {
                    break;
                }
                ++count;
            }
            if (count == n) {
                return i;
            }
            else {
                //如果i>n, 说明跑了一圈也没有找到合适的出发点，则返回-1;
                i = i + count + 1;
            }
        }
        return -1;

    }
    int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
        /*
        * 如果总和>0，说明一定能跑完，找到总和最小的点，就是出发点。
        */
        int n = gas.size();
        int sum = 0;
        int minSum = INT_MAX;
        int minIdx = -1;
        for (int i = 0; i < n; ++i) {
            sum += gas[i] - cost[i];
            if (sum < minSum) {
                minSum = sum;
                minIdx = i;
            }
        }
        return sum<0? -1:(minIdx+1)%n;

    }
};
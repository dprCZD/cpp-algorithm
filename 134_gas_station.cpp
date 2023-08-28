#include "common.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*
        * ͨ������ʽ���Եó������x�������ܵ�����Զ�ļ���վΪy����[x,y]�е�����һ������վz�����޷�����y+1��
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
                //���i>n, ˵������һȦҲû���ҵ����ʵĳ����㣬�򷵻�-1;
                i = i + count + 1;
            }
        }
        return -1;

    }
    int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
        /*
        * ����ܺ�>0��˵��һ�������꣬�ҵ��ܺ���С�ĵ㣬���ǳ����㡣
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
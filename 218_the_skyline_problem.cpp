#include "common.h"

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;

        vector<vector<int>> points;
        for (vector<int>& b : buildings) {
            int left = b[0];
            int right = b[1];
            int height = b[2];
            points.push_back({ left,-height });
            points.push_back({ right,height });
        }
        std::sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            // �Ȱ��պ������������
            // �����ͬ�ĺ����꣬���ո߶Ƚ�������
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
            });

        map<int, int8_t, std::greater<int>> highest;
        highest[0] = 1;
        int prevHeight = 0;

        for (vector<int>point : points) {
            // ��˵㣬���
            if (point[1] < 0) {
                ++highest[-point[1]];
            }
            //�Ҷ˵㣬����
            else {
                --highest[point[1]];
                if (highest[point[1]] == 0) {
                    highest.erase(point[1]);
                }
            }

            //�����ǰ��ߵĸ߶���֮ǰ�ĸ߶Ȳ�ͬ�������ӽ����
            int curHeight = highest.begin()->first;
            if (curHeight != prevHeight) {
                res.push_back({ point[0],curHeight});
                prevHeight = curHeight;
            }
        }

        return res;


    }
};

//int main() {
//	Solution su;
//    vector<vector<int>> v = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
//    su.getSkyline(v);
//
//}
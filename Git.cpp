#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> answer;

        for (int i = 0; i < l.size(); ++i) {
            int left = l[i];
            int right = r[i];

            // Извлекаем подмассив
            vector<int> subarray(nums.begin() + left, nums.begin() + right + 1);

            // Сортируем его
            sort(subarray.begin(), subarray.end());

            // Проверяем, является ли он арифметической последовательностью
            bool isArithmetic = true;
            int diff = subarray[1] - subarray[0];

            for (int j = 2; j < subarray.size(); ++j) {
                if (subarray[j] - subarray[j - 1] != diff) {
                    isArithmetic = false;
                    break;
                }
            }

            answer.push_back(isArithmetic);
        }

        return answer;
    }
};
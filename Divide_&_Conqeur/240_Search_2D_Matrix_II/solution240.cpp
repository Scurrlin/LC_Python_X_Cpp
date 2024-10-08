#include <vector>

using namespace std;

class Solution {
public:
    bool divide_and_conquer(vector<vector<int>>& mat, int min_i, int min_j, int max_i, int max_j, int tar) {
        if (min_i > max_i || min_j > max_j) {
            return false;
        }

        int med_i = (min_i + max_i) / 2;
        int med_j = (min_j + max_j) / 2;

        if (mat[med_i][med_j] == tar) {
            return true;
        }

        if (mat[med_i][med_j] > tar) {
            if (divide_and_conquer(mat, min_i, min_j, max_i, med_j - 1, tar)) {
                return true;
            }
            if (divide_and_conquer(mat, min_i, med_j, med_i - 1, max_j, tar)) {
                return true;
            }
        } else {
            if (divide_and_conquer(mat, med_i + 1, min_j, max_i, max_j, tar)) {
                return true;
            }
            if (divide_and_conquer(mat, min_i, med_j + 1, med_i, max_j, tar)) {
                return true;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        return divide_and_conquer(mat, 0, 0, mat.size() - 1, mat[0].size() - 1, tar);
    }
};

// Runtime1: 138ms, beats 11.94%
// Memory1: 17.69MB, beats 46.09%

// Runtime2: 134ms, beats 12.05%
// Memory2: 17.69MB, beats 46.09% 

// Runtime3: 134ms, beats 12.05%
// Memory3: 17.56MB, beats 79.11%
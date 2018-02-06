//
// Created by 王阳 on 2018/1/31.
//

/**
 * 返回最小的
 * @param arr
 * @param n
 * @return
 */
double MinDifference(double arr[], int n) {
    if (n < 2) {
        return 0;
    }

    double fMinDiff = fabs(arr[0] - arr[1]);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double tmp = fabs(arr[i] - arr[j]);
            if (fMinDiff > tmp) {
                fMinDiff = tmp;
            }
        }
    }

    return fMinDiff;
}
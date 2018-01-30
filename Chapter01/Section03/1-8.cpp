//
// Created by 王阳 on 2018/1/30.
//

// 烙饼排序实现

#include <cassert>
#include <cstdio>

class CPrefixSorting {
public:
    CPrefixSorting() {
        m_nCakeCnt = 0;
        m_nMaxSwap = 0;
    }

    ~CPrefixSorting() {
//        if ()
    }

    /**
     * 输出。
     */
    void Output() {
        for (int i = 0; i < m_nMaxSwap; i++) {
            printf("%d ", m_SwapArray[i]);
        }

        printf("\n |Search Times| :%d\n", m_nSearch);
        printf("Total Swap times = %d\n", m_nMaxSwap);
    }

    /**
     * 上界。
     * @param nCakeCnt
     * @return
     */
    int UpperBound(int nCakeCnt) {
        return nCakeCnt * 2;
    }

    /**
     * 判断是否排序。
     * @param pCakeArray
     * @param nCakeCnt
     * @return true:已经排好序，false:未排序。
     */
    bool IsSorted(int *pCakeArray, int nCakeCnt) {
        for (int i = 1; i < nCakeCnt; i++) {
            if (pCakeArray[i - 1] > pCakeArray[i]) {
                return false;
            }
        }
        return true;
    }

    /**
     * 翻转烙饼信息。
     * @param nBegin
     * @param nEnd
     */
    void Reverse(int nBegin, int nEnd) {
        assert(nEnd > nBegin);
        int i, j, t;

        for (i = nBegin, j = nEnd; i < j; i++, j--) {
            t = m_ReverseCakeArray[i];
            m_ReverseCakeArray[i] = m_ReverseCakeArray[j];
            m_ReverseCakeArray[j] = t;
        }

    }


private:
    int *m_CakeArray; // 烙饼信息数组。
    int m_nCakeCnt; // 烙饼个数。
    int m_nMaxSwap; // 最多交换次数，根据前面的推断，这里最多为m_nCakeCnt * 2；

    int *m_SwapArray;   //交换结果数组。

    int *m_ReverseCakeArray;    // 当前翻转烙饼的数组信息。
    int *m_ReverseCakeArraySwap;    //当前翻转烙饼交换结果数组。
    int m_nSearch;  // 当前搜索次数信息。
};
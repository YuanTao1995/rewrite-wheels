//
// Created by 采香行处 on 2021/9/15.
//
#include <iostream>
#include <vector>
using namespace std;

// 将两个有序区间[left, mid]和[mid+1, right]进行合并；
// 归并的核心就在于先进行组内排序，并且这种小范围的比较在后续中并没有被浪费；
// 而其他如插入、选择、冒泡等，都是在单兵作战，前面比较对后续的比较参考意义不大，并且难以降低规模。
void merge(vector<int> &v, int left, int mid, int right){
    vector<int> help(right-left+1); // 采用一个帮助数组
    int index_of_help = 0; // 帮助数组的下标
    int p1 = left, p2 = mid + 1;
    while(p1 <= mid && p2 <= right){// 谁小接谁
        help[index_of_help++] = v[p1] < v[p2]?v[p1++]:v[p2++];
    }
    // 多余的前半段
    while(p1 <= mid){
        help[index_of_help++] = v[p1++];
    }
    // 多余的后半段
    while(p2 <= right){
        help[index_of_help++] = v[p2++];
    }
    // 将help数组中的有序数组，搬回去
    for(int i = 0; i < help.size(); ++i){
        v[left+i] = help[i];
    }
}

// 递归
void mergesort(vector<int> &v, int left, int right){
    if (left >= right){
        return;
    }else{
        int mid = left + ((right-left) >> 1);
        mergesort(v, left, mid);
        mergesort(v, mid+1, right);
        merge(v, left, mid, right);
    }
}

// 非递归
void mergesort2(vector<int> &v, int left, int right){
    if (left >= right){
        return;
    }else{
        for(int sub_len = 1; sub_len <= v.size(); sub_len <<= 1){// 步长
            // 两个段一起往前，如果没有两段则跳出
            for(int index = left; index + sub_len <= right; index += 2*sub_len){
                int new_left = index, new_mid = index + sub_len -1, new_right = index + 2*sub_len - 1;
                if(new_right > right) {//第二段数量少于步长
                    new_right = right;
                }
                merge(v, new_left, new_mid, new_right);
            }
        }
    }
}

int main()
{
    vector<int> v{7,5,3,1,4,2,6}, v2(v) ;
    mergesort(v, 0, v.size()-1);
    cout << "递归实现：";
    for (const auto &i : v){
        cout << i << " ";
    }
    mergesort2(v2, 0, v.size()-1);
    cout<< endl << "非递归实现：";
    for (const auto &i : v2){
        cout << i << " ";
    }
    return 0;
}

//
// Created by 采香行处 on 2021/9/15.
//
#include <iostream>
#include <vector>
using namespace std;

// 求解有序区间[low, high)中是否存在值target
int binarysearch(vector<int> &v, int low, int high, int target){
    while( cout<< "["<<low <<","<< high<<"]:  " && 1 < high- low){
        int mid = low + ((high - low) >> 1);
        cout << "mid = " << mid << endl ;
        target < v[mid]? high = mid: low = mid;//[low, mid)或者[mid, high)
    }//迭代出口时high = low + 1，查找区间仅含一个元素v[low]
    return target == v[low] ? low:-1;
}

int main(){
    vector<int> v{1,2,4,6,8,10,11};
    int target = 3;
    cout << binarysearch(v, 0, v.size(), 3) << endl;
    return 0;
}

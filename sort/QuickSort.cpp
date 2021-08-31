//
// Created by 采香行处 on 2021/8/31.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int partition(vector<int> &v, int left, int right){
    int priot = v[left]; // 相当于priot取出来了
    while(left < right){
        // right往前找
        while(left < right && v[right] >= priot){
            --right;
        }
        v[left] = v[right];
        // left往后找
        while(left < right && v[left] <= priot){
            left++;
        }
        v[right] = v[left];
    }
    v[left] = priot;
    return left; // 此时left和right相同
}

void quicksort(vector<int> &v, int left, int right){
    if (left >= right){
        return;
    }
    else{
        int priot_index = partition(v, left, right);
        quicksort(v, left, priot_index-1);
        quicksort(v, priot_index+1, right);
    }
}

// 非递归方式
void quicksort2(vector<int> &v, int left,int right)
{
    if (left>=right)
        return;
    stack<int> stk;
    int i, j;
    //（注意保存顺序）先将初始状态的左右指针压栈，进出栈的顺序一定要注意
    stk.push(left);//先左指针
    stk.push(right);//再右指针

    while (!stk.empty())
    {
        //出栈顺序一定不能错
        j = stk.top();//弹出右指针
        stk.pop();
        i = stk.top();//弹出左指针
        stk.pop();
        if (i < j)
        {
            int priot_index = partition(v, i, j);
            stk.push(i);  //先左
            stk.push(priot_index - 1);//再右
            stk.push(priot_index + 1);//先左
            stk.push(j);//再右
        }

    }

}

int main()
{
    vector<int> v{3,1,4,2,6,5};
    quicksort(v, 0, v.size()-1);
    cout << "递归实现：";
    for (const auto &i : v){
        cout << i << " ";
    }
    quicksort2(v, 0, v.size()-1);
    cout<< endl << "非递归实现：";
    for (const auto &i : v){
        cout << i << " ";
    }
    return 0;
}

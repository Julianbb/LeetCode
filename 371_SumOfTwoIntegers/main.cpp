#include <iostream>
using namespace std;




// int Sum(int a, int b)
// {
//     if(b == 0) return a; // 结束条件是有一个数为０，直接返回另一个结果
//     return Sum(a^b, (a&b)<<1); // a^b 计算和，a&b << 1 ，计算的是进位，再利用递归进行两部分相加，
// }



// 上面解法在有的编译器(-1,1)不通过
// 考虑符号问题，一进来之后将其转化成 无符号类型
int getSum(int a, int b) {
    a = *(unsigned int* )&a;
    b = *(unsigned int* )&b;
    return b== 0 ? a  : getSum(a^b, (unsigned int)(a&b)<<1);
}



int main(void)
{
    int tmp = Sum(-1,1);
    cout << tmp << endl;
}

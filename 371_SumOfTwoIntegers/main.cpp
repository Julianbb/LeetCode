#include <iostream>
using namespace std;




int Sum(int a, int b)
{
    if(b == 0) return a; // 结束条件是有一个数为０，直接返回另一个结果
    return Sum(a^b, (a&b)<<1); // a^b 计算和，a&b << 1 ，计算的是进位，再利用递归进行两部分相加，
}






int main(void)
{
    int tmp = Sum(-1,1);
    cout << tmp << endl;
}

#include <iostream>
using namespace std;

class Solution {
public:
    
    inline int Min(int a, int b)
    {
        return a>b ? b : a;
    }
    


    int surfaceArea(vector<vector<int>>& grid) {
     int sum = 0;
     for(int i=0; i<grid.size(); i++)
     {
         for(int j=0; j<grid[0].size(); j++)
         {
             sum += grid[i][j];
         }
     }
        
     sum = sum*6; // 上面算出来的sum 是多少个cubes, *6代表总的表面积
        
     for(int i=0; i<grid.size(); i++)
     {
         for(int j=0; j<grid[0].size(); j++)
         {
             if(grid[i][j]>1) // 如果有堆积，-2*公共面
             sum -= 2*(grid[i][j]-1);
             
             if(j!=grid[0].size()-1)//从左到右，但是除了最右边一个 
             sum -= 2*Min(grid[i][j], grid[i][j+1]);//左边相交的面, 取当前[i][j] 与右边最小的cubes, 
             
             if(i!=grid.size()-1) // 从上到下，除了最下面一个
             sum -= 2*Min(grid[i][j], grid[i+1][j]);
         }
     }
      
     return sum;
    }
};





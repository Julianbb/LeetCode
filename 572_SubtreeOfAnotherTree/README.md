### 题目:<br>
给定两个非空的树，s和t, 判断t是否是s的子树，note:树的结点可以重复,而且子树意味着:当前结点(包括)以及它所有的子节点<br>

### solution:<br>
1. 先在s中找到和t的root值一样的结点,将所有结点保存到stack容器中(因为s中可能有重复的和t的root一样的结点)<br>
2. 从栈顶开始弹(从树下面)，判断当前树和t是否是一样的，只有有一个符和返回true,否则返回false<br>



解法很好，值得借鉴<br>
[leetcode上的解法](https://leetcode.com/articles/subtree-of-another-tree/#)


### notebook:<br>
1. 在函数内部定义指针或者变量的时候，一定给一个默认值，否则它有可能是随机值(不可控):48,49
2. 在取容器里面的值的时候，先判断size 是否为0, 否则出错:53-55

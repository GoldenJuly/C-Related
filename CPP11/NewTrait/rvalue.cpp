/**
 * 本文主要介绍：左值引用，右值引用，移动语义，完美转发
 * 关于左指右值的一些好的说明定义：
 * 1）https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c
 * 2）https://zhuanlan.zhihu.com/p/138210501
 * 
 * 1）左值引用：可以获取到地址的值，可以理解成一个容器
 * 2）右值引用：不可以获取地址的值，可以理解成一个容器内部具体的值
 * 3）移动语义：将左值转换成右值
 * 4）完美转发：参数是什么类型的值，就转发成什么类型的值，避免转发到的函数中不必要的拷贝
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    return 0;
}
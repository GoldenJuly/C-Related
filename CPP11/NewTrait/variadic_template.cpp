/**
 * 可变参数模版，c++11之前模板只支持确定数量的参数，c++11支持可变数量参数的模板
 * 
 * 额外说明：
 * 模板参数的声明中，可以用typename，也可以用class，这是因为在早期的c++中，使用的是class，但是这个容易让人误解参数必须要是一个类类型
 * 所以后来优化成typename了，但是历史上已经有很多是用class来写的了，所以也保留了下来
 */

#include <iostream>

using namespace std;

// Args：模板参数包，表示0个或多个模板参数类型
// args：函数参数包，表示0个活多个函数参数
// sizeof...运算符：获取参数包中有多少个参数：https://en.cppreference.com/w/cpp/language/sizeof...
template <class T, class... Args>
void myprint(T t, Args... args) {
  cout << "t:" << t << ", Args_num:" << sizeof...(Args) << endl;
  cout << "t:" << t << ", args_num:" << sizeof...(args) << endl;
}

/**
 * 如何获取可变模版参数中的每个参数？需要对参数包（parameter
 * pack）中的参数进行展开操作 一般有2种方式：
 * 1）通过递归函数来展开，优点：好理解，缺点：必须要有一个重载的递归终止函数
 * 2）通过逗号表达式来展开，
 */

// 1）通过递归进行函数展开
// 递归终止函数
template <class T>
void digui_print(T t) {
  cout << "last:" << t << endl;
}

// 递归展开函数
template <class T, class... Args>
void digui_print(T t, Args... args) {
  cout << "digui:" << t << endl;
  digui_print(args...);
}

// 2）通过逗号表达式展开
template <class T>
void douhao_print(T t) {
  cout << "douhao:" << t << endl;
}

template <class... Args>
void douhao_expand(Args... args) {
  // (douhao_print(args),
  // 0)表示是一个（逗号表达式），逗号表达式最终的结果是最后一个表达式的值
  // 代码中的...表示对参数包进行展开操作，如果args有3个参数，则下面的代码等价于：
  // int arr[] = {(douhao_print(args1), 0), (douhao_print(args2), 0),
  // (douhao_print(args3), 0)};
  int arr[] = {(douhao_print(args), 0)...};
  cout << "size:" << sizeof(arr) << endl;
  for (int i = 0; i < sizeof...(args); i++) {
    cout << "arr:" << arr[i] << endl;
  }
}

int main() {
  myprint(1);
  myprint(1, 2);
  myprint(1, "hello", 3.14);
  // result
  // t:1, Args_num:0
  // t:1, args_num:0
  // t:1, Args_num:1
  // t:1, args_num:1
  // t:1, Args_num:2
  // t:1, args_num:2
  cout << "digui_zhankai---" << endl;
  digui_print(1, 2, 3, 4);
  // digui_zhankai---
  // digui:1
  // digui:2
  // digui:3
  // last:4

  cout << "douhao_zhankai---" << endl;
  douhao_expand(1, 2, 3, 4);

  // douhao_zhankai---
  // douhao:1
  // douhao:2
  // douhao:3
  // douhao:4
  // size:16
  // arr:0
  // arr:0
  // arr:0
  // arr:0

  return 0;
}

// 编译：g++ -std=c++11 variadic_template.cpp -o variadic_template
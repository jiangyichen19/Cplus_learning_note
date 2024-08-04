#include <iostream>


using namespace std;





int main(){
    // 定义一个指针
    // 通过变量给指针存储一个内存
    int a = 10;
    int *p0 = &a;
    cout<<"*p0   "<<*p0<<endl;// 应该是空的？
    cout<<"p0    "<<p0<<endl; // 随机分配的一个内存，打出来应该是一个32位的二进制数

    cout<<"*(p0+1)   "<<*(p0+1)<<endl; // 地址向下移动四个字节，取出里面存储的值
    cout<<"p0+1    "<<(p0+1)<<endl; // 地址向下移动四个字节

    // 内存的回收与分配
    

    return 0;
}


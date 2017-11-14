#include <iostream>
//#include <memory>
#include <new>// 使用_set_new_mode和set_new_handler
void nomem_handler()
{
    std::cout<<"call nomem_handler"<<std::endl;
}
int main()
{
    set_new_mode(1);  //使new_handler有效
    set_new_handler(nomem_handler);//指定入口函数 函数原型void f();
    std::cout<<"try to alloc 2GB memory...."<<std::endl;
    char* a = (char*)malloc(2*1024*1024*1024);
    if(a)
        std::cout<<"ok...I got it"<<std::endl;
    free(a);
    system("pause");
}

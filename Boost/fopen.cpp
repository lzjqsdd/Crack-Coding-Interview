#include <stdio.h>
#include <stdlib.h> // 为了使用 exit()
int main()
{
    int ch;
    FILE* fp; 
    fp=fopen("a.iso","r+"); // 只供读取
    if(fp==NULL) // 如果失败了
    {
        printf("unable\n");
    }
    else
        printf("enable\n");
    fclose(fp); // 关闭文件
    return 0;
}



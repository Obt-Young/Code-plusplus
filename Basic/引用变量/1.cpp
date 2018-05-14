#include <stdio.h>

int xxx = 10;
int & r_xxx=xxx;



int main(int argc,char ** argv)
{

	printf("xxx=%d,r_xxx=%d\n",xxx,r_xxx);
	printf("address:xxx=%x,r_xxx=%x\n",&xxx,&r_xxx);
	
}

/*
运行结果：
xxx=10,r_xxx=10
address:xxx=601034,r_xxx=601034
可见，引用变量和原变量的虚拟内存地址都是一样的


读符号表：objdump -t 1|grep xxx
000000000060102c g O .data 0000000000000004 xxx
0000000000400660 g O .rodata 0000000000000008 r_xxx
可见，引用变量是只读的，和const修饰的变量一样


小结：1.使用起来和原变量一样
     2.虚拟内存地址一样，在符号表中是独立存在的，这一点看不懂？？？


注意：引用变量必须在定义时，就赋值，这一点和const变量是一样的，这也呼应了前面符号表中看到其存放在.rodata区域中
*/

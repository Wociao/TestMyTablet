耐心bai看看啊，运行通过啦，希望对你du有帮助啊！
#include<stdio.h>
unsigned int veax;
unsigned int vebx;
unsigned int vedx;
unsigned int vecx;
//执行CPUID指令
void cpuid(unsigned int veax1)
{
_asm{
mov eax,veax1
cpuid
mov veax,eax
mov vebx,ebx
mov vecx,ecx
mov vedx,edx
}
}
//做移位操作，zhi把寄存器中的daoASCII码，以字符形式输出
void LeftMove(unsigned int var)
{
printf("%c",var);
for(int i=0;i<3;i++)
{
var=(var>>;
printf("%c",var);
}
}
//做移位操作，把寄存器中的值以“%d”形式输出
void LM(unsigned int var)
{
printf("%d",var);
for(int i=0;i<3;i++)
{
var=(var>>;
printf("%d",var);
}
}
//得到CPU的生产厂商（当EAX值为0时），依次存放在EBX，EDX，ECX中
void getCpuName()
{
cpuid(0);
LeftMove(vebx);
LeftMove(vedx);
LeftMove(vecx);
printf("\
";
}
//得到CPU的商标，当EAX中的值为0x80000003和0x80000004时分别返回16个字符，组成商标
//依次存放在EAX，EBX，ECX，EDX中
void getCpuBrand()
{
for(int j=0;j<2;j++)
{
cpuid(0x80000003+j);
LeftMove(veax);
LeftMove(vebx);
LeftMove(vecx);
LeftMove(vedx);
}
printf("\
";
}
//获得CPU的特性，参数是eax = 1，返回值放在edx和ecx，通过验证edx或者ecx的某一个bit，
//可以获得CPU的一个特性是否被支持。比如说，edx的bit 32代表是否支持MMX，
//edx的bit 28代表是否支持Hyper-Threading，ecx的bit 7代表是否支持speed sted。
void getCpuFeature()
{//由于特性太多，无法一一编写，需要的时候再写，方法是一样的。
}
//获得CPU序列号，获得序列号需要两个步骤，首先用eax = 1做参数，返回的eax中存储序列号的高两个WORD。
//用eax = 3做参数，返回ecx和edx按从低位到高位的顺序存储前4个WORD。
void getCpuSeris()
{
cpuid(1);
LM(veax);
cpuid(3);
LM(vecx);
LM(vedx);
printf("\
";
}
void main()
{
getCpuName();
getCpuBrand();
getCpuSeris();
}

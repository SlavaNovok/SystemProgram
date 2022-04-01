#include <iostream>
#include <string>
#include <cstring>

using namespace std;

extern "C" {
 string text;
 int n;
 const int size = 10;
 int a=0;
 char b;
 char b1;
 char b2;
 char b3;
 char b4;
 int c=0;
 int r;
 int y;
 int k=0;
 int j=0;
 int arr[size];
 char char_array[size];
 int t=0;
};

int main()
{ 
  getline(cin,text);
  n = text.length();
  strcpy(char_array, text.c_str());
  b1=char_array[0];
  b2=char_array[n-1];
  b4=char_array[n-2];
  y=n-1;
  for (int i = 0; i < n; i++)
  {
  b3=char_array[i-1];
  b=char_array[i];
  r=i;
  __asm
 (
 R"(
 .intel_syntax noprefix
 mov esi,r
 mov ecx, 1
 mov al, b

 cmp esi, 0
 je lss
 cmp esi,y
 je lss

 cmpb al,' '
 jne lss

 mov al, b3
 cmpb al,' '
 je lss

 add a, ecx 
 lss:
 
 mov al, b
 cmpb al,' '
 je less

 mov eax,c
 cmp eax,0
 jne less

 mov eax,1
 mov c,eax

 less:

 .att_syntax
 )"
 );
 }

 __asm
 (
 R"(
 .intel_syntax noprefix
 mov esi,a
 mov al, b2
 mov ecx, 1

 cmp esi, 0
 je lsss
 cmpb al,' '
 je lsss

 add a, ecx

 lsss:

 cmp esi, 0
 je lssf
 cmpb al,' '
 jne lssf
 mov al, b4
 cmpb al,' '
 je lssf

 add a, ecx

 lssf:

 cmp esi, 0
 jne lssd

 mov al, b2
 cmpb al,' '
 je lssh
 mov al, b1
 cmpb al,' '
 je lssh

 add a, ecx
 jmp lssd

 lssh:

 mov al, b2
 cmpb al,' '
 jne lssc
 mov al, b1
 cmpb al,' '
 je lssc

 add a, ecx
 jmp lssd

 lssc:

 mov al, b2
 cmpb al,' '
 je lssx
 mov al, b1
 cmpb al,' '
 jne lssx

 add a, ecx
 jmp lssd

 lssx:

 mov al, b2
 cmpb al,' '
 jne lssd
 mov al, b1
 cmpb al,' '
 jne lssd
 mov esi,c
 cmp esi, 1
 jne lssd

 add a, ecx

 lssd:

 .att_syntax
 )"
 );
 
 cout << "Kolichestvo slov" << endl;
 cout << a << endl;

 c=2;
 for (int i = 0; i < n; i++)
 {
  b=char_array[i];
  r=i;
  __asm
 (
 R"(
 .intel_syntax noprefix
 mov esi,k
 mov ecx, 1
 mov al, b

 cmp esi, 0
 je lb
 mov esi,c
 cmp esi,2
 je lb

 cmpb al,' '
 je lbd
 mov esi,r
 cmp esi,y
 je lbd

 add k, ecx

 lbd:

 cmpb al,' '
 je lbdd
 mov esi,r
 cmp esi,y
 jne lbdd

 add k, ecx
 mov esi,k
 mov t,esi
 add j, ecx
 mov esi,0
 mov k,esi
 mov esi,2
 mov c,esi

 lbdd:

 cmpb al,' '
 jne lbdt
 mov esi,r
 cmp esi,y
 jne lbdt

 mov esi,k
 mov t,esi
 add j, ecx
 mov esi,0
 mov k,esi
 mov esi,2
 mov c,esi

 lbdt:

 cmpb al,' '
 jne lb
 mov esi,r
 cmp esi,y
 je lb

 mov esi,k
 mov t,esi
 add j, ecx
 mov esi,0
 mov k,esi
 mov esi,2
 mov c,esi

 lb:

 cmpb al,' '
 je lbb
 mov esi,k
 cmp esi,0
 jne lbb

 add k, ecx
 mov c, ecx

 lbb:

 .att_syntax
 )"
 );
 arr[(j-1)]=t;
 }

 cout << "Kolichestvo bukv v slovah" << endl;
 for (int i = 0; i < j; i++)
 {
    cout << arr[i] << endl;
 }

 return 0;
}

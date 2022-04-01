#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
 string text; 
 getline(cin,text);
 int n = text.length();
 int a=0;
 char b=' ';
 int c=0;
 int k=0;
 int j=0;
 int arr[n+1];
 char char_array[n + 1];
 strcpy(char_array, text.c_str());
 for (int i = 0; i < n; i++)
 {
   if ((i!=0)&&(i!=(n-1))) {
     if ((char_array[i]==b)&&(char_array[i-1]!=b)) {
        a=a+1;
     }
   }
   if ((char_array[i]!=b)&&(c==0))
   {
     c=1;
   }
 }
 if ((a!=0)&&(char_array[n-1]!=b)) {
   a=a+1;
 }
 if ((a!=0)&&(char_array[n-2]!=b)&&(char_array[n-1]==b)) {
   a=a+1;
 }

 if ((a==0)&&(((char_array[n-1]!=b)&&(char_array[0]!=b))||((char_array[n-1]==b)&&(char_array[0]!=b))||((char_array[n-1]!=b)&&(char_array[0]==b))||((char_array[n-1]==b)&&(char_array[0]==b)&&(c==1))))
 {
   a=a+1;
 }
 cout << "Kolichestvo slov" << endl;
 cout << a << endl;
 c=2;
 for (int i = 0; i < n; i++)
 {
    if ((k!=0)&&(c!=2)) {
      if ((char_array[i]!=b)&&(i!=(n-1))) {
        k=k+1;
      } else if ((char_array[i]!=b)&&(i==(n-1))) {
        k=k+1;
        arr[j]=k;
        j=j+1;
        k=0;
        c=2;
      }
         else if ((char_array[i]==b)&&(i==(n-1))) {
        arr[j]=k;
        j=j+1;
        k=0;
        c=2;
      } else if ((char_array[i]==b)&&(i!=(n-1))) {
        arr[j]=k;
        j=j+1;
        k=0;
        c=2;
      }

    }
    if ((char_array[i]!=b)&&(k==0)) {
        k=k+1;
        c=1;
    }

 }
 cout << "Kolichestvo bukv v slovah" << endl;
 for (int i = 0; i < j; i++)
 {
    cout << arr[i] << endl;
 }
 return 0;
}

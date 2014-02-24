#include <cstdio>
#include <cstring>
#define f(i,len) for(i=0;i<len;i++)
#define zi if(str[i]==
#define zo if(op==
#define zac a[i++]='C'
#define zax a[i++]='X'
#define zai a[i++]='I'
#define zal a[i++]='L'
#define zav a[i++]='V'
#define zad a[i++]='D'
int process(char * str)
{int ans,sum,prev,i;
int len=strlen(str);
sum=prev=0;
f(i,len) {
zi 'M') ans = 1000;
else zi 'D') ans = 500;
else zi 'C') ans = 100;
else zi 'L') ans = 50;
else zi 'X') ans = 10;
else zi 'V') ans = 5;
else zi 'I')ans = 1;

if(prev<ans) sum=sum+ans-prev-prev;
else sum=sum+ans;
prev=ans;
}return sum;}

int main ()
{
      char a[16], b[16];char op;
      int t,ans,a1,b1,tmp,i,len;
      t=5;
      while(t--) {
            scanf("%s %s %c",a,b,&op);
            a1=process(a);b1=process(b);
zo '+') ans = a1+b1;
else zo '-') ans=a1-b1;
else zo '*') ans=a1*b1;
else zo '/') ans=a1/b1;
else zo '%') ans=a1%b1;
//ans = ans%5000;
tmp = ans/1000; i=0;
while(tmp>0) {a[i++] = 'M'; tmp--;}
tmp = ans/100-(ans/1000)*10;
switch(tmp) {
case 1: zac;break;
case 2: zac;zac;break;
case 3: zac;zac;zac;break;
case 4: zac;zad;break;
case 5: zad;break;
case 6: zad;zac;break;
case 7: zad;zac;zac;break;
case 8: zad;zac;zac;zac;break;
case 9: zac;a[i++]='M';break;}
tmp=ans/10-(ans/100)*10;
switch(tmp) {
case 1: zax;break;
case 2: zax;zax;break;
case 3: zax;zax;zax;break;
case 4: zax;zal;break;
case 5: zal;break;
case 6: zal;zax;break;
case 7: zal;zax;zax;break;
case 8: zal;zax;zax;zax;break;
case 9: zax;zac;break;}
tmp=ans%10;
switch(tmp) {
case 1: zai;break;
case 2: zai;zai;break;
case 3: zai;zai;zai;break;
case 4: zai;zav;break;
case 5: zav;break;
case 6: zav;zai;break;
case 7: zav;zai;zai;break;
case 8: zav;zai;zai;zai;break;
case 9: zai;zax;break;}
len=i;
f(i,len) {printf("%c",a[i]);}
printf("\n");}
return 0;}

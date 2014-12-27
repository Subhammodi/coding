#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int x[15]; double area[16];

double get_area(int a,int b,int c)
{
 double p=(a+b+c)/2.0;
 p=sqrt(p*(p-a)*(p-b)*(p-c));
 return p;
}

int main()
{
 int t; scanf("%d",&t);
 while(t--)
 {
  int n; scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&x[i]);
  sort(x,x+n);
  area[n]=0.0;
  for(int i=n-1;i>=0;i--)
  {
   int j=i+1,k=j+1; area[i]=area[i+1];
   while(k<n)
   {
    if(x[i]+x[j]>x[k])
    {
     for(int m=j;m<k;m++)
      area[i]=max(area[i],get_area(x[i],x[m],x[k])+area[k+1]);
     k++;
    }
    else j++;
   }
  }
  printf("%.6f\n",area[0]);
 }
 return 0;
}
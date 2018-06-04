#include <bits/stdc++.h>
using namespace std;

#define MAX 60
void print(int *a,int n,int *y)
{
    for(int i=0;i<n;i++)
    	cout<<a[i]<<" ";
    cout<<"\n";
    (*y)++;
}

void countarr(int *a,int n,int pos,int *y)
{
	if(pos==n)
	{
	     return;
	}
	int count=0;
	for(int i=pos;i<n-1;i++)
	{
	      if(a[i]>0&&a[i+1]>0&&i<n-2)
	      {
	           a[i]--,a[i+1]--,a[i+2]++;
		   countarr(a,n,i,y);
	           print(a,n,y);
	           a[i]++,a[i+1]++,a[i+2]--;
	      }
	      else if(a[i]>0&&a[i+1]>0&&i==n-2)
	      {
                  a[i]--,a[i+1]--;
                  int *tem=new int[n+1];
                  int k;
                  for(k=0;k<n;k++)
                  {
            	     tem[k]=a[k];
                  }
                  tem[k]=1;
                  print(tem,n+1,y);
                  countarr(tem,n+1,i,y);
                  a[i]++,a[i+1]++;
	     }
	 }
	 return;
}

signed main()
{
	int *a,n;
	cout<<"n?"<<"\n";
	cin>>n;
	a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
  	int x=1;int *y=&x;
  	countarr(a,n,0,y);
  	cout<<*y<<"\n";
	return 0;
}

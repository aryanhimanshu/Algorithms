#include<iostream.h>
#include<conio.h>
class lsearch
{                 
int a[10],limit,item,n,flag;
public:
void read()
{
cout<<”\n\n\t Linear Search \n”;
cout<<”\t-------------------------\n”;
cout<<”\n\n\tINPUT\n”;
cout<<”\t----------------\n”;
cout<<”\n\nEnter the limit:”;
cin>>limit;
cout<<”\nEnter”<<limit<<”elements:\n\n”;
for(int i=0;i<limit;i++)
{
cin>>a[i];
}
cout<< “\n\nEnter the element to be searched:”;
cin>>item;
}
void search()
{
for(int i=0;i<limit;i++)
{
if(a[i]==item)
{
flag=1;
break;
}
else
flag=0;
}
if(flag==1)
cout<<”\n\nThe item found at index”<<i<<”.”;
else
cout<<”\n\nSorry!The element was not found.\n”;
}
void display()
{
cout<<”\n\tOUTPUT\n”;
cout<<”\n\nThe array is:\t”;
for(int i=0;i<limit;i++)
{
cout<<a[i]<<”\t”;
}
}
};
void main()
{
clrscr();
lsearch ls;
ls.read();
ls.display();
ls.search();
getch();
}

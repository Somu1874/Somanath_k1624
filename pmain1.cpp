#include<iostream>
#include<conio.h>
using namespace std;
struct process
{
	int pid;
	int priority;
	int btime;
	int atime;
};

int x,y,z;
int M[100],N[100],P[100];
int bt=0;

void Sorting_FCFS(process p[],int n)
{
	for(int j=0;j<n-1;j++)
	for(int i=0;i<n-1-j;i++)
	{
		if(p[i].atime>p[i+1].atime)
		{
			process q=p[i];
			p[i]=p[i+1];
			p[i+1]=q;
		}
	}
}

void Sorting_Priority(process p[],int n)
{
	for(int j=0;j<n-1;j++)
	for(int i=0;i<n-1;i++)
	{
		if(p[i].priority>p[i+1].priority)
		{
			process q=p[i];
			p[i]=p[i+1];
			p[i+1]=q;
		}
	}
}

void sorting_RR(process p[],int n)
{
	for(int j=0;j<n-1;j++)
	for(int i=0;i<n-1-j;i++)
	{
		if(p[i].atime>p[i+1].atime)
		{
			process q=p[i];
			p[i]=p[i+1];
			p[i+1]=q;
		}
	}
}


void execute_priority(process p[],int n)
{
	int m=0;                   
	for(int i=0;i<n;i++)
		m=m+p[i].btime;
	bt=bt+m;
	x=m;	
	int k=0;
	for(int i=0;i<n;i++)
	{
		
			for(int j=0;j<p[i].btime;j++)
			{
				
			M[k]=p[i].pid;
			k++;
		}
		
	}
}


void execute_RR(process p[],int n)
{
	cout<<"\n\n\n\n";
	int m=0;
	for(int i=0;i<n;i++)
		m=m+p[i].btime;
	bt=bt+m;	
	y=m;
	int k=0;
	while(m)
	{
		for(int i=0;i<n;i++)
		{
		int j=4;
		while(j)
		{
			if(p[i].btime!=0)
			{
				N[k]=p[i].pid;
				p[i].btime--;m--;k++;
			}
			j--;
		}
	}
			
	}
}

void execute_FCFS(process p[],int n)
{
	
	int m=0;
	for(int i=0;i<n;i++)
		m=m+p[i].btime;
	bt=bt+m;
	z=m;
	int k=0;
	for(int i=0;i<n;i++)
	{
		
			for(int j=0;j<p[i].btime;j++)
			{
			
			P[k]=p[i].pid;
			k++;}
		
	}
}


void display(process p[],int n)
{
	
	cout<<"\n*****************************************************";
	cout<<"\n* Process id  "<<"* Arrival time "<<"* Burst time "<<"* Priority ";
	cout<<"\n*****************************************************";
	for(int i=0;i<n;i++)
	{
		
	cout<<"\n"<<"*      "<<p[i].pid<<"      *     "<<p[i].atime<<"        *     "<<p[i].btime<<"      *    "<<p[i].priority;
	}
	cout<<"\n*****************************************************";
		
}

int m=0,n=0,r=0;
void EXECUTE()
{
	while(bt)
	{
	
	int i=10;
		cout<<"\n\n";
		while(i)
		{
			if(y!=0)
			{
				cout<<"p"<<N[n]<<"  ";
				n++;
				y--;
				bt--;
			
			}
			if(y==0)
				i=0;
			else	
				i--;
			
		}
		
		cout<<"\n\n";
		i=10;
		while(i)
		{
			if(x!=0)
			{
				cout<<"p"<<M[m]<<"  ";
				m++;
				x--;
				bt--;
				
			}
			if(x==0)
				i=0;
			else	
				i--;
			
		}
		
		cout<<"\n\n";
		i=10;
		while(i)
		{
			if(z!=0)
			{
				cout<<"p"<<P[r]<<"  ";
				r++;
				z--;
				bt--;
				
			}
			if(z==0)
				i=0;
			else	
				i--;
			
		}
				
    }
}



process a[10],b[10],c[10];

int d=0,e=0,f=0;
void INPUT(int n)
{
	process temp;
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter Process id :";
		cin>>temp.pid;
		cout<<"\nEnter arrival time :";
		cin>>temp.atime;
		cout<<"\nEnter burst time :";
		cin>>temp.btime;
		cout<<"\nEnter priority of process :";
		cin>>temp.priority;
		if(temp.priority>0&&temp.priority<=5)
		{
			a[d]=temp;
			d++;
		}
		else if(temp.priority>5&&temp.priority<=10)
		{
			b[e]=temp;
			e++;
		}
		else
		{
			c[f]=temp;
			f++;
		}	
	}
	
}


void SORTING()
{
	
	
	sorting_RR(a,d);
	Sorting_Priority(b,e);
	Sorting_FCFS(a,f);
}

void Execution()
{
	
	execute_RR(a,d);
	execute_priority(b,e);
	execute_FCFS(c,f);
	
}

void Display()
{
	cout<<"\n\n\n\n";
	cout<<"\nProcesses of queue 1 (with HIGH priority )";
	display(a,d);
	cout<<"\n\n\n\n";
	cout<<"\nProcesses of queue 2 (with MEDIUM priority )";
	display(b,e);
	cout<<"\n\n\n\n";
	cout<<"\nProcesses of queue 3 (with LOW priority )";
	display(c,f);
	
}
int main()
{
	int n;
	cout<<"\nEnter number of processes : ";
	cin>>n;
	/*priority from 1 to 5 will go to queue 1 (i.e a) 
	priority between 6 to 10 will go to queue 2 (i.e b)
	priority above 10 will  go to queue 3 (i.e c)   */
	
	INPUT(n);
	Display();
	SORTING();	
	Execution();
	cout<<"\n\nExecuting .............................\n\n\n";
	EXECUTE();
}

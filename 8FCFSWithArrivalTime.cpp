WITH TIME ARRIVAL
#include<iostream>
using namespace std;

int main(){
	int n,*arr,*b;
	arr=new int [n];
	b=new int [n];
	cout<<"enter the number of processes: ";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{cout<<"\nenter burst time of the "<<i+1<<" processes: ";
		cin>>arr[i];
		
	}cout<<endl<<"\n";
	
	for(int i=0;i<n;i++){
		cout<<"\nenter arrival time of "<<i+1<<" process : ";
		cin>>b[i];
	}
	
	
	
	cout<<" \n               GANTT CHART \n\n";
	cout<<" |";
	for(int i=0;i<n;i++){
		
		cout<<"  process   "<<i+1<<"   | ";
	}
	cout<<endl;
	int e=0;
	cout<<b[0]<<"                ";
	for(int i=0;i<n;i++){
		e+=arr[i];
		if(i==0){
			e+=b[0];
		}
		cout<<" "<<e<<"                ";
		
	}
	
	
	cout<<"\n\n";
	
	cout<<"\nprocess            burst time                  arival time                     waiting time                   turnaround time\n";
	float avg=0,t=0,tr=0,ta=0,d=0,dt=0; //t=gantt chart except last waala : avg=sum of waiting time 
	for(int i=0;i<n;i++){      //tr=gantt chart for turnaround  : ta = sum of turnaround time 
		
			tr+=arr[i];
			dt=tr-b[i]+b[0];
	    	ta+=tr;
			cout<<"  "<<i+1<<"                     "<<arr[i]<<"                         "<<b[i]<<"                               "<<d<<"                                 "<<dt<<endl;
		t+=arr[i];
		d=t-b[i]; 
		if(i!=n-1)
		avg+=t;
	
	}
	cout<<"\naverage waiting time is "<<avg/n<<endl;
	cout<<"\naverage turnaround time "<<ta/n;
	
}

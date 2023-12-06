WITHOUT ARRIVAL TIME
#include<iostream> 
using namespace std;

int main(){
	int n,**arr,**b;
	arr=new int *[n];
	b=new int*[n];
	

	

	cout<<"enter the number of processes: ";
	cin>>n;
	
		for(int i=0;i<n;i++){
	arr[i]=new int[2];
	}
	
		for(int i=0;i<n;i++){
	b[i]=new int[2];
	}
	
	
	for(int i=0;i<n;i++)
	{cout<<"\nenter burst time of the "<<i+1<<" processes: ";
		cin>>arr[i][2];
		arr[i][1]=i+1;
	}cout<<endl<<"\n";
	
	
	
	
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){		
			if(arr[i][2]>arr[j][2]){
				int temp=arr[i][2];
				int tem=arr[i][1];
				arr[i][2]=arr[j][2];
				arr[i][1]=arr[j][1];
				arr[j][2]=temp;	
				arr[j][1]=tem;	}
	}
}
	
	
		
	cout<<" \n               GANTT CHART \n\n";
	cout<<" |";
	for(int i=0;i<n;i++){
		
		cout<<"  process   "<<arr[i][1]<<"   | ";
	}
	cout<<endl;
	int e=0;
	for(int i=0;i<=n;i++){
		cout<<" "<<e<<"                ";
		e+=arr[i][2];
	}

	
	cout<<"\n\n\nprocess            burst time               waiting time                   turnaround time\n";
	float avg=0,t=0,tr=0,ta=0; 
	for(int i=0;i<n;i++){      
		
			tr+=arr[i][2];
		ta+=tr;
			cout<<"  "<<arr[i][1]<<"                     "<<arr[i][2]<<"                         "<<t<<"                                 "<<tr<<endl;
		t+=arr[i][2]; 
		if(i!=n-1)
		avg+=t;
		
		
	}
	cout<<"\naverage waiting time is "<<avg/n<<endl;
	cout<<"\naverage turnaround time "<<ta/n;
	
}

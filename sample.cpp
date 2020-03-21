#include<iostream>
#include<stdio.h>
#include<fstream>
#include<conio.h>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;

main()
{
	string line;
	string numline="";
	double arr[300],arr2[100],arr3[100],arr4[100];
	int j=0;
	
	ifstream transfer;
	transfer.open("timestat.txt");
	
	while(!transfer.eof())
	{
      getline(transfer,line);
	
	  for(int i=0;i<=line.length();i++)
	  {
	  	if(line[i]>=46 && line[i]<=57)
	  	{
	  	    numline=numline+line[i];
	    }
	  }
	     if(numline.length()==0)
	     continue;
		 stringstream time(numline);
	 	 double t;
	 	 time>>t;
		 arr[j]=t;
		 j++;
		 numline="";
	}
	
     double sum_r=0,sum_u=0,sum_s=0;
	 int r=0,u=1,s=2;
	 long double ssum_r=0,ssum_u=0,ssum_s=0;
	 int p=0,q=1,w=2;
	 int x=0,y=0,z=0;
	
	for(int k=1;k<=100;k++)
	{
	 sum_r = sum_r + arr[r];
	 r=r+3;
	 
	 sum_u = sum_u + arr[u];
	 u=u+3;
	 
	 sum_s = sum_s + arr[s];
	 s=s+3;
	 
	 cout<<"number of runs : "<<k<<endl;
	 cout<<"Average Time statistics"<<endl;
	 cout<<"real "<<sum_r/k<<", user "<<sum_u/k<<", sys "<<sum_s/k<<endl;
	 
	 for (int g=0;g<=k-1;g++ )
	 {
	  arr2[g]=arr[p]-sum_r/k;
	  ssum_r = ssum_r + arr2[g]*arr2[g];  //variance*number of terms for real time
	  p=p+3;
	  
	  arr3[g]=arr[q]-sum_u/k;
	  ssum_u = ssum_u + arr3[g]*arr3[g];
	  q=q+3;
	  
	  arr4[g]=arr[w]-sum_s/k;
	  ssum_s = ssum_s + arr4[g]*arr4[g];
	  w=w+3;
	 }
     cout<<"Standard deviation of Time statistics"<<endl;
	 cout<<"real "<<sqrt(ssum_r/k)<<" user "<<sqrt(ssum_u/k)<<" sys "<<sqrt(ssum_s/k)<<endl;
	  
	 p=0,q=1,w=2;
	 ssum_s=0,ssum_u=0,ssum_r=0;
	
	 for(int g=0;g<=k-1;g++)
	 {
	 if(arr[3*g]<=sum_r/k+sqrt(ssum_r/k) && arr[3*g]>=sum_r/k-sqrt(ssum_r/k))
	 x++;
	
	 if(arr[3*g+1]<=sum_u/k+sqrt(ssum_u/k) && arr[3*g+1]>=sum_u/k-sqrt(ssum_u/k))
	 y++;
	 
	 if(arr[3*g+2]<=sum_s/k+sqrt(ssum_s/k) && arr[3*g+2]>=sum_s/k-sqrt(ssum_s/k))
	 z++; 
     }
	 
	cout<<"Number of runs with (average-standard deviation) to (average + standard deviation)"<<endl;
    cout<<"real "<<x<<" user "<<y<<" sys "<<z<<endl;
    cout<<endl;
	x=0,y=0,z=0;
    }
    
	transfer.close();
}


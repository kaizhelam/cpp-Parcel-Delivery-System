#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <fstream>
#define RANGE 255;
using namespace std;

int trk_num[100];
string receiver[100];
string address[100];
int front = -1, rear = -1, n=100;
int value=0, index;
int del;

void append(int val, string name, string add) {
   if (front == -1) {
      front = 0;
      rear = 0;
   }
   else {
      if (rear == n - 1)
         rear = 0;
      else
         rear = rear + 1;
   }
   trk_num[rear] = val ;
   receiver[rear] = name;
   address[rear] = add;
}
void editCQ(int trk_num[], int m)
{
	int edit, data, cnt=0;
	int editdetails;
	string details;
	
	cout << "\n** Record **\n";
	for(int a=0; a<m; a++)
	{
		cout<<"Tracking number is "<< trk_num[a]<< ", Receiver name : " <<receiver[a] << ", Address : " << address[a] <<endl;
		cout<<"--------------------------------------------------------------------\n";
	}
	
	cout << "Enter the tracking number you want to edit :";
	cin >>  edit;
	cout<< "\n1. Tracking Number"<<endl;
	cout<< "2. Receiver name"<<endl;
	cout<< "3. Address"<<endl;
	cout << "Enter what you want to edit : "<<endl;
	cin>>editdetails;
	
	switch(editdetails)
	{
		case 1:
			for(int i=0; i<m; i++)
			{
				if(trk_num[i] == edit)
				{
					cout << "Enter the new Tracking number : ";
					cin >> data;
					cout << "\nTracking number "<< edit <<" found at "<<i+1<<" position\n";
					trk_num[i]=data;
					cnt++;
				}
			}
			break;
		case 2:
			for(int i=0; i<m; i++)
			{
				if(trk_num[i] == edit)
				{
					cin.ignore();
					cout << "Enter the new Username : ";
					getline(cin, details);
					cout << "\nReceiver name for tracking number "<< edit <<" found at "<<i+1<<" position\n";
					receiver[i]=details;
					cnt++;
				}
			}
			break;
		case 3:
			for(int i=0; i<m; i++)
			{
				if(trk_num[i] == edit)
				{
					cin.ignore();
					cout << "Enter the new Address : ";
					getline(cin, details);
					cout << "\nAddress for tracking number "<< edit <<" found at "<<i+1<<" position\n";
					address[i]=details;
					cnt++;
				}
			}
			break;
	}
	
	if(cnt==0)
		cout << "\nTracking number not Found!\n\n";
	else
	{
		cout <<	" Data edit successfully \n\n";
		cout << "* Record * \n";
		for(int i=0; i<m; i++)
		{
			cout<<"Tracking number is "<< trk_num[i]<< ", Receiver name : " <<receiver[i] << ", Address : " << address[i] <<endl;
         	cout<<"--------------------------------------------------------------------\n";
		}
		cout << "\n";
	}
}
void displayCQ() {
   int f = front, r = rear;
   if (front == -1) {
      cout<<"\nRecord is empty\n\n";
      return;
   }

   if (f <= r) {
   	  cout << "\n** Record ** \n";
      while (f <= r){
         cout<<"Tracking number is "<< trk_num[f]<< ", Receiver name : " <<receiver[f] << ", Address : " << address[f] <<endl;
         cout<<"--------------------------------------------------------------------\n";
         f++;
      }
   }
   cout<<endl;
}
void heapify(int arr[], string receiver[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        swap(arr[i], arr[largest]);
        swap(receiver[i], receiver[largest]);
 
        heapify(arr, receiver, n, largest);
    }
}
void heapSort(int arr[], string receiver[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, receiver, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        swap(receiver[0], receiver[i]);
 
        heapify(arr, receiver, i, 0);
    }
}
void printArray(int trk_num[], string receiver[], int n)
{
    for (int i = 0; i < n; ++i)
    {
    	cout<<"Tracking number is "<< trk_num[i]<< ", Receiver name : " <<receiver[i] << ", Address : " << address[i] <<endl;
    	cout<<"--------------------------------------------------------------------\n";
	}
    cout << "\n";
}
// Exponential Search
int jumpSearch(int arr[], int x, int n) 
{ 
    // Finding block size to be jumped 
    int step = sqrt(n); 
  
    // Finding the block where element is 
    // present (if it is present) 
    int prev = 0; 
    while (arr[min(step, n)-1] < x) 
    { 
        prev = step; 
        step += sqrt(n); 
        if (prev >= n) 
            return -1; 
    } 
  
    // Doing a linear search for x in block 
    // beginning with prev. 
    while (arr[prev] < x) 
    { 
        prev++; 
  
        // If we reached next block or end of 
        // array, element is not present. 
        if (prev == min(step, n)) 
            return -1; 
    } 
    // If element is found 
    if (arr[prev] == x) 
        return prev; 
  
    return -1; 
} 
void deleteCQ(int m)
{
	int del, count=0, z;
	int f = front, r = rear;
	cout << "\n** Record **\n";
	for(int a=0; a<m; a++)
	{
		cout<<"Tracking number is "<< trk_num[a]<< ", Receiver name : " <<receiver[a] << ", Address : " << address[a] <<endl;
		cout<<"--------------------------------------------------------------------\n";
	}
	
	cout << "Enter Tracking number to delete : ";
	cin >> del;
	
	for(int i=0; i<m; i++)
	{
		if(trk_num[i] == del)
		{
			for(int j=i; j<=(m-1); j++)
			{
				trk_num[j]=trk_num[j+1];
				receiver[j]=receiver[j+1];
				address[j]=address[j+1];
			}
			count++;
			m--;
			break;
		}
	}
	if(count == 0)
	{
		cout << "\nTracking number not found!\n\n";
	}
	else
	{
		cout << "Record " << del << " deleted successfully \n\n";
		cout<<"------------------------------"<<endl;
   	  	cout << "* Record * "<<endl;
   	  	cout<<"------------------------------"<<endl;
   	  	for(z=0; z<m; z++)
		{
			cout<<"Tracking number is "<< trk_num[z]<< ", Receiver name : " <<receiver[z] << ", Address : " << address[z] <<endl;
			cout<<"--------------------------------------------------------------------\n";
		}
		cout << "\n";
	}
}
void exitCQ()
{
	cout<<"\nTHANK YOU";
}

int main() {
	int ch, val, search;
	string name, add, line;
	short loop=0;
	int m=0;
	cout<<"-----------------------------------------"<<endl;
	cout<<"\t* Parcel Delivery System *\n";
	cout<<"-----------------------------------------\n"<<endl;
   	ifstream myfile("dsa.txt");
   	
   	if(myfile.is_open())
   	{
   		while (myfile >> val >> name >> add ){
            append(val, name, add);
            m++;
        }
	    myfile.close();
	}
   
   do {
   	   	cout<<"Choose what to do :"<<endl;
   		cout<<"==========================="<<endl;
   	  cout<<"\t1) Add Record\n";
   	  cout<<"\t2) Edit Record\n";
	  cout<<"\t3) Display Record\n";
	  cout<<"\t4) Sort Record\n";
	  cout<<"\t5) Search Record\n";
	  cout<<"\t6) Delete Record\n";
	  cout<<"\t7) Exit\n"<<endl;
      cout<<"Enter your choice : ";
      cin>>ch;
	      if(ch == 1){
	      	cout<<"\nEnter Parcel Tracking number: ";
	        cin>>val;
	        cout<<"Enter receiver name : ";
	        cin.ignore();
	        getline(cin, name);
	        cout<<"Enter address : ";
	        getline(cin, add);
	        append(val, name, add);
	        cout << "\nRecord added\n\n";
			m++;
		  }else if(ch == 2){
		  	editCQ(trk_num, m);
		  }else if(ch == 3){
		  	displayCQ();
		  }else if(ch == 4){
		  	heapSort(trk_num, receiver, m);
		  	cout << "\nRecord Sorted  \n";
    		printArray(trk_num, receiver, m);
		  }else if(ch == 5){
			 	displayCQ();
			 	//m++;
				if(m == 0){
					cout << endl;
					return 0;
				}else{
					cout << "Enter the Tracking number to find the index : ";
		         	cin >> search;
		         	int index = jumpSearch(trk_num, search, m);
		         	if(index == -1){
		         		cout << "Record not found!\n\n";
					 }else{
					 	cout << "\nNumber " << search << " is at index " << index <<endl<<endl;	
					 }
				}
		  }else if(ch == 6){
		  	deleteCQ(m);
		  	for(int i=0; i<m; i++)
			{
				if(trk_num[i] == del)
				{
			 		rear--;
		  			m--;
		  		}
			}
		  }else if(ch == 7){
		  	exitCQ();
		  	fstream myfile("dsa.txt");
		  	if(myfile.is_open()){
		  		for(int i=0; i<m; i++)
				{
				myfile << trk_num[i] << " " << receiver[i] << " " << address[i] << "\n";
				}	
			}
			myfile.close();
		  }else{
		  	cout<<"Invalid operation.\n\n";
		  }
   }while(ch != 7);
}

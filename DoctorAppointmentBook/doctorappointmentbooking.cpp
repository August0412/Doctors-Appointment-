#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int bookAppointment()
{
    system("cls");
	
    cout<<"\n ----- Check and Book Appointment as per available slots ---- \n";	
    cout<<"\n ----- The available slots are---- \n";	 


    ifstream read;
    read.open("appointment.dat");
    
    int hoursbook = 9;
    
    int arr[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int recordFound =0; 
     
    if(read)
    {     
	string line;
	char key = 'A';
	int i = 9;
	       
	while(getline(read, line)) {
	char temp = line[0];
	int index = (temp - 65);
	arr[index]=1;  
	recordFound = 1;
	}
	if(recordFound == 1)
	{
	cout<<"Timing: 9am to 10pm.";
    cout<<"\nTodays appointments.";
    
	cout<<"\nAppointment List as per available Hours:";
	char key = 'A';
	int hours = 9;
	for(int i = 0; i<=13; i++)
	{
	if(i == 0){
	if(arr[i] == 0) 
	cout<<"\n "<<key<<"-> 0"<<hours<<" - Available";
	else
	cout<<"\n "<<key<<"-> 0"<<hours<<" - Booked";
	}
	
	else
	{								           	
	if(arr[i] == 0) 
	cout<<"\n "<<key<<"->"<<hours<<" - Available";
	else
	cout<<"\n "<<key<<"->"<<hours<<" - Booked";
	}
	hours++; key++;
	}
            
	}
		
	read.close();
    }
	if(recordFound == 0){
	cout<<"\nAppointments are available for the following hours:";
	char key = 'A';
	for(int i = 9; i<=22; i++)
	{
		if(i==9)
		cout<<"\n "<<key<<" -> 0"<<i<<" - Available";
		else
		cout<<"\n "<<key<<" -> "<<i<<" - Available";
		key++;
	}
		
	}
   
   char choice;
   cout<<"\n\n Enter the initial of your slot according to available Hours: ";
   cin>>choice;
   
   if( !(choice >= 'A' && choice <='Z'))
   {
	cout<"\n Error : Invalid Selection";
	cout<<"\n Please select correct value from menu A- Z";
	cout<"\n Press any key to continue";
	getchar();
	getchar();
	system("cls");
	bookAppointment();
   }
   
   int index = (choice-65 );
   int isBooked = 1;
   if(arr[index] == 0) 
      isBooked = 0;
      
   if(isBooked ==1)
   {
   	cout<<"\n Error : This Appointment  slot is already booked.";
   	cout<<"\n Please select different time slot!!";
   	cout<<"\n Press any key to continue!!";
   	getchar();
	getchar();
   	system("cls");
   	bookAppointment();
   }
   
   string name;
   cout<<"\n Enter Patient's Name_Time :";
   cin>>name;  
   
   ofstream out;
   out.open("appointment.dat", ios::app);
	
   if(out){
	   out<<choice<<":"<<name.c_str()<<"\n";
	   out.close();
	   cout<<"\n Appointment is Successfully Noted(Booked) for Hour : "<< (choice-65) + 9 <<" !!";
    }
    else
    {
    	cout<<"\n Error while saving booking";
    }

    cout<<"\n Please any key to continue..";
	getchar();
	getchar();
	return 0;		
}

int existingAppointment()
{
    system("cls");
   cout<<"\nToday's Confirmed Appointments:'";	
   cout<<"\n ----- List of Available Appointments ---- \n";

    ifstream read;
    read.open("appointment.dat");
    
    int hoursbook = 8;
    
    int arr[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int recordFound =0; 
     
    if(read)
    {     
	string line;
	char key = 'A';
	int i = 9;
	       
	while(getline(read, line)) {
	char temp = line[0];
	int index = (temp - 65);
	arr[index]=1;  
	recordFound = 1;
	}
	if(recordFound == 1)
	{
	cout<<"\nAppointment List available as per hours:";
	char key = 'A';
	int hours = 9;
	for(int i = 0; i<=13; i++)
	{
	if(i == 0){
	if(arr[i] == 0) 
	cout<<"\n "<<key<<"-> 0"<<hours<<" - Available";
	else
	cout<<"\n "<<key<<"-> 0"<<hours<<" - Booked";
	}
	
	else
	{								           	
	if(arr[i] == 0) 
	cout<<"\n "<<key<<"->"<<hours<<" - Available";
	else
	cout<<"\n "<<key<<"->"<<hours<<" - Booked";
	}
	hours++; key++;
	}
            
	}
		
	read.close();
    }
	if(recordFound == 0){
	cout<<"\nAppointment Available for following hours :";
	char key = 'A';
	for(int i = 9; i<=22; i++)
	{
		if(i==9)
		cout<<"\n "<<key<<" -> 0"<<i<<" - Available";
		else
		cout<<"\n "<<key<<" -> "<<i<<" - Available";
		key++;
	}
		
	}
   

   ofstream out;
   out.open("appointment.dat", ios::app);
	

    cout<<"\n Press any key to continue..";
	getchar(); getchar();
	return 0;	 
}
 

int main(int argc, char** argv) {
	while(1)
	{
		system("cls");
		cout<<"\t\t|Doctor Appointment Booking System|\n";
		cout<<"\t--------------------------------------------------\n\n";
		cout<<"1. Book an Appointment now\n";
		cout<<"2. Check all the Existing Appointments\n";
		cout<<"0. Exit. \n";
		int choice;
		
		cout<<"\nEnter you choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: bookAppointment(); 
			break;
			case 2: existingAppointment(); 
			break;
			case 0: 
		        while(1)
		        {
				 system("cls");
					cout<<"\n Are you sure, you want to exit? y | n \n";
		        	char ex;
		        	cin>>ex;
		        	if(ex == 'y' || ex == 'Y')
		        		exit(0);
		        	else if(ex == 'n' || ex == 'N')
                     		{
                     		 break;
                    		}
                     else{
                     	cout<<"\n Invalid choice !!!";
                     	getchar();
                     }
             	 }	break;
                 	 
            default: cout<<"\n Invalid choice. Enter again ";
                     getchar();
                 	
		}   		        

	}
	return 0;
}   

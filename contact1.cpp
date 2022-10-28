#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

string name[50];
string phoneNo[50];
string email[50];

int counter = -1;
  
int validateContact(string Name){ 
	 for(int i=0; i<=counter; i++){
	 	if( name[i] == Name ){
	 		return 0;
	 	}
	 }
 	 return 1; 
}

void addContact(){
     string Name = "";
	 cout<<"Enter Name : ";
	 cin>>Name;
	 if( validateContact(Name) == 1 ){	
	     counter++;
	 	 name[counter] = Name;	 	
	 }else{
	 	cout<<endl<<"Contact Already Exist with this Name"<<endl;
	 	return;
	 } 
     cout<<"Enter Phone No : ";
     cin>>phoneNo[counter];
     cout<<"Enter Email No : ";
     cin>>email[counter];
}
void print(int tmpCounter){
	if( name[tmpCounter] == "" )
		return;
	if( counter > -1 ){
		cout<<"Name : "<<name[tmpCounter]<<endl;	
		cout<<"Phone No : "<<phoneNo[tmpCounter]<<endl;
		cout<<"Email : "<<email[tmpCounter]<<endl;
		cout<<"Press any key to view next / continue..."<<endl<<endl;
		getch();
	}
}
void printAll(){
	if( counter > -1 ){
		for(int i=0; i<=counter; i++){
		    print(i);
		}
	}
}

void updateContact( int tmpCounter ){	
     string Name = "";
	 cout<<"Enter Name : ";
	 cin>>Name;
	 if( validateContact(Name) ){
	 	 name[tmpCounter] = Name;	 	
	 }else{
	 	cout<<endl<<"Contact Already Exist with this Name"<<endl;
	 	return;
	 }
     cout<<"Enter Phone No : ";
     cin>>phoneNo[tmpCounter];
     cout<<"Enter Email No : ";
     cin>>email[tmpCounter];
}
void deleteContact(int tmpCounter){ 
	 name[tmpCounter] = ""; 
     phoneNo[tmpCounter] = ""; 
     email[tmpCounter] = ""; 
}
int findCounter(){ 
	 if( counter < 0 )
	 	 return -1;
	 	
	 string Name;
	 cout<<"Enter Name";
	 cin>>Name;
	 for(int i=0; i<=counter; i++){ 
	 	if( name[i] == Name ){
	 		return i;
	 	}
	 }
 	 return 1; 
}
	
int main(){
    char Entered_number;
    do{
        cout << "\n";
        cout << " ==============================================================="<<endl;
        cout << "                       RAVI CONTACT BOOK                          " << endl;
        cout << " ==============================================================="<<endl;
        cout << "\n";
        cout<<"1. Add or create new contact.."<<endl;
        cout<<"2. Udate contact.."<<endl;
        cout<<"3. Delete contact.."<<endl;
        cout<<"4. Search contact.."<<endl;
        cout<<"5. Show me all contact.."<<endl;
        cout<<"6. Exit.."<<endl;
        cout << " ==============================================================="<<endl;
        cout << "\n";
        cout<<"Enter input : ";
        cin>>Entered_number;
    switch(Entered_number){
        case '1':
			{
				 addContact();
				 cout<<"Contact added successfully..."<<endl;
				 cout<<"Press any key to continue";
				 getch();
		 		 break;
			}
            case '2':
			{
				 int tmpCounter = findCounter();
				 if( tmpCounter > -1 ){
				      updateContact(tmpCounter);				 	
				 }
		 		 break;
			}
            case '3':
			{
				 int tmpCounter = findCounter();
				 if( tmpCounter > -1 ){
				      deleteContact(tmpCounter);				 	
				 }
		 		 break;
			}
			case '4':
			{
				 int tmpCounter = findCounter();
				 if( tmpCounter > -1 ){
				      print(tmpCounter);				 	
				 }
		 		 break;
			}
            case '5':
			{
				 printAll(); 
		 		 break;
			}
			case '6':
			{
				 continue;
		 		 break; 
			}
		
    }
    }while(Entered_number!=6);	
	return 0;
}
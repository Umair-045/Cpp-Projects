#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;


class library{
	public:
	int id;
	string Bookname;
	string Authorname;
	string Studentname;
	int price;
	int pages;
};


int main(){
	
	
	library lib[20];       // Array used to store detail of 20 books
	int input=0;           // This stores the choice you make from the menu (1, 2, or 3)
	int count=0;           // Counter for how many books are stored
	while(input!=3){     // loop continues until user press digit 3
    cout<<"Enter 1 to input detail  id, Bookname, Authorname, Studentname, price, pages "<<endl;
    cout<<"Enter 2 to Display detail "<<endl;
    cout<<"Enter 3 to quit "<<endl;
    cin>>input;
    
    
    
    switch(input){
    	
    	
    	case 1:
    		start:
    		cout<<"Enter Book ID :"<<endl;
    		cin>>lib[count].id;
    		
    		cout<<"Enter Book name :"<<endl;
    		cin.ignore();     // clear input buffer before taking string input
    		getline(cin, lib[count].Bookname);
    		
    		
    		cout<<"Enter Author name :"<<endl;
    		getline(cin,lib[count].Authorname);
    		
    		
    		cout<<"Enter Student name :"<<endl;
    		getline(cin,lib[count].Studentname);
    		
    		
    		cout<<"Enter Price :"<<endl;
    		cin>>lib[count].price;
    		
    		
    		cout<<"Enter Pages :"<<endl;
    		cin>>lib[count].pages;
    		
    		
    		count++;      // increment book count after input
    		
    		break;
    		
    		case 2:
    			for(int i=0;i<count;i++){     // Display detail of all entered books
    				cout<<"Book ID  :"<<lib[i].id<<endl;
    				cout<<"Book Name  :"<<lib[i].Bookname<<endl;
    				cout<<"Author Name  :"<<lib[i].Authorname<<endl;
    				cout<<"Student Name  :"<<lib[i].Studentname<<endl;
    				cout<<"Book Price  :"<<lib[i].price<<endl;
    				cout<<"Book Pages  :"<<lib[i].pages<<endl;
				}
				
				break;
				
				
				
				case 3:
					
					exit(0);   // Exit the program
					
					break;
					
					default:
					
						cout<<"You have entered wrong value please try again "<<endl;
					
						goto start;    // Go back to input prompt in case of invalid option
	
	
	}
	
    
    
	}
         
	
	
	return 0;
}















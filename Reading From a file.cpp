#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
//struct that holds data from file.
struct PERSON{
    char first[20];
    char last[20];
    float Balance;
};
void Display(PERSON p[],int numberOfPeople){
    cout<<"Name                 Balance"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    for(int i=0; i<numberOfPeople;i++){
        cout<<p[i].first<<" "<<p[i].last<<" "<< p[i].Balance<<endl;
    }
}
void FindRichest(PERSON *p,int numberOfPeople){
    int max=0;
    for(int i=0; i<numberOfPeople; i++){
        if(p[max].Balance<p[i].Balance){
            max=i;
    }
        }
    cout<<"The customer with maximum balance is: "<< p[max].first<< " "<<p[max].last<<endl;
}

void Deposit(char CustName[],PERSON *p,int numberOfPeople){
    int index=0;
    for(int i=0; i<numberOfPeople; i++)
    {
        if(strcmp(CustName,p[i].first)==0)
        {
            index=i;
            break;
        }
    }
    float Deposit;
    cout<<endl;
    cout<< CustName<<", how much would you like to deposit? ";
    cin>>Deposit;
    p[index].Balance+=Deposit;
    cout<<"New balance is $"<<p[index].Balance<<endl;
    
}
/*
void NewCopy(string firstname,PERSON *p,int numberOfPeople){
    
    
}
*/
int main() {
    //make the array for PERSON struct
    PERSON p[100];
    string name;
    //open the file
    ifstream file("data.txt");
    
    //checks if the file is open
    if(!file)exit(1);
    //make temp person struct to store each line of data
    PERSON temporaryPerson;
    //have count for number of people
    int numberOfPeople =0;
    //read first thing on a given line into temp
    file >> temporaryPerson.first;
    //while loop
    while(!file.eof()){
        //read everything else on given line to struct
        file>> temporaryPerson.last >> temporaryPerson.Balance;
        // put temp into the array of Person
        p[numberOfPeople]=temporaryPerson;
        //increment count
        numberOfPeople++;
        //read first thing on a given line into temp
        file >> temporaryPerson.first;
    }
    //close file
    file.close();
    //output array to the screen
    Display(p,numberOfPeople);
    FindRichest(p,numberOfPeople);
    char CustName[20];
    cout<<"Enter your first name to deposit money: ";
    getline(cin,name);
    strcpy(CustName,name.c_str());
    Deposit(CustName,p,numberOfPeople);
    //NewCopy("data.txt",p,numberOfPeople);
    return 0;
}

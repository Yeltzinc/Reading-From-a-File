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
void FindRichest(PERSON p[],int numberOfPeople){
    
        float largest=p[0].Balance;
    float temp=0;
    int i;
        for(int x=1; x<=numberOfPeople;x++){
            temp=p[x].Balance;
            if(temp>largest)
                p[x].Balance=temp;
            i++;
        }
    cout<<p[i].Balance;
}

int main() {
    //make the array for PERSON struct
    PERSON p[100];
    
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
}

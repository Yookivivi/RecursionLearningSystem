#include<fstream>
#include<iostream>
#include<string>

using namespace std;

//Identify user input and reach the corresponding function
void go_to_function(string user_inpt){

    //to do
}

//This is the mode to showing some basic concepts of recursion.
void leaning_mode(){
    fstream myfile("ecursiveintroductrion.txt",ios::in|ios::out);
    string line;
    while(getline(myfile,line))
    cout<<line<<endl;
    
    //to do

}
void Primary(){

}

void Intermediate(){

}

void Advanced(){

}

//This is the mode to do some recursion related questions.
void testing_mode(){
    cout<<"For test mode, we can choose: "<<endl;
    cout<<"1: Primary: "<< endl;
    cout<<"2: Intermediate: "<<endl;
    cout<<"3: Advanced: "<<endl;
    int user_choose;

    if(user_choose==1){
        Primary();
    }
    else if (user_choose==0){
        Intermediate();
    }
    else{
        cout<<"Wrong choose! Please enter again!"<<endl;
        cout<<endl;
        Advanced();
    }
}






    



//Print the content in main_directory and ask the user to choose the function.
void main_directory(){
    int user_input;
    cout<<"We have the folowing mode:"<<endl;
    cout<<"1. Learning Mode"<<endl;
    cout<<"2. Testing Mode"<<endl;
    cout<<"Please select one(1 for Learning Mode and 2 for Testing Mode): ";
    cin>>user_input;
    
    if(user_input==1){
        leaning_mode();
    }
    else if (user_input==2){
        testing_mode();
    }
    else{
        cout<<"Wrong input! Please try it again!"<<endl;
        cout<<endl;
        main_directory();
    }
}

void welcome_message(){
    cout<<"Welcome to Introductory to Recursion System!"<<endl;
    cout<<endl;
}

//
int main(){
    welcome_message();
    main_directory();

}

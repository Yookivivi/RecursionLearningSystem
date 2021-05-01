#include <iostream>

using namespace std;

//Identify user input and reach the corresponding function
void go_to_function(string user_inpt){
    //to do
}

//This is the mode to showing some basic concepts of recursion.
void leaning_mode(){
    //to do

}

//This is the mode to do some recursion related questions.
void testing_mode(){
    //to do

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
    else if (user_input==0){
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
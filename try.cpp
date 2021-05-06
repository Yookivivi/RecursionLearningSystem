#include<fstream>
#include<iostream>
#include<string>
#include <stdlib.h>

using namespace std;

//Identify user input and reach the corresponding function
void go_to_function(string user_inpt){

    //to do
}

//This is the mode to showing some basic concepts of recursion.
void leaning_mode(){
    fstream myfile("recursion_introductrion.txt",ios::in|ios::out);
    string line;
    while(getline(myfile,line))
    cout<<line<<endl;
    
    //to do

}

//This is the mode to do some recursion related questions.
void testing_mode(){
    char level;
    cout<<"Please Select a level(p(primary1) or p2(primary2) or m(mediate) or s(senior)):";
    cin>>level;
    int ans1,ans2;
    int real_ans1=0,real_ans2=0,k=0,h=0;
    int a,b;
    int j=0;

    while(j==0){
        
    if(level=='p'){

        fstream file1("primary1.txt",ios::in|ios::out);
        string line1;
        while(getline(file1,line1))
        cout<<line1<<endl;
        cout<<"read and think about this question first,"<<endl;
        cout<<"Then please enter your answer here:";
        cin>>ans1;
        fstream infile1("primary1_answer.txt",ios::in|ios::out);
        string Line1;
        while(getline(infile1,Line1))
        real_ans1 =atoi(Line1.c_str());
        while(k==0){
        if(real_ans1 == ans1){
            cout<<"Your answer is right!"<<endl;
            cout<<"Now you can do other exercise!"<<endl;
            k=1;
        }
        else{
            cout<<"The answer is wrong, Please try again."<<endl;
            cout<<"Then please enter your answer here:";
            cin>>ans1;
            cout<<real_ans1;
        }
        }
        infile1.close();
        cout<<"If you want to leave the exercise, please enter 1.if don't, enter 0 :";
        cin>>j;
        if(j==0){
            cout<<"Please Select a level(p(primary1) or p2(primary2) or m(mediate) or s(senior)):";
            cin>>level;
        }
    }
    if(level=='P'){

        fstream file2("primary2.txt",ios::in|ios::out);
        string line2;
        while(getline(file2,line2))
        cout<<line2<<endl;
        cout<<"read and think about this question first,"<<endl;
        cout<<"Then please enter your answer here:";
        cin>>ans2;
        fstream infile2("primary1_answer.txt",ios::in|ios::out);
        string Line2;
        while(getline(infile2,Line2))
        real_ans1 =atoi(Line2.c_str());
        while(h==0){
        if(real_ans2 == ans2){
            cout<<"Your answer is right!"<<endl;
            cout<<"Now you can do other exercise!"<<endl;
            h=1;
        }
        else{
            cout<<"The answer is wrong, Please try again."<<endl;
            cout<<"Then please enter your answer here:";
            cin>>ans1;
    
        }
        }
        infile2.close();
        cout<<"If you want to leave the exercise, please enter 1.if don't, enter 0 :";
        cin>>j;
        if(j==0){
            cout<<"Please Select a level(p(primary1) or p2(primary2) or m(mediate) or s(senior)):";
        }
    }
    if(level=='m'){


        fstream file3("intermediate.txt",ios::in|ios::out);
        string line3;
        while(getline(file3,line3))
        cout<<line3<<endl;
        cout<<"read and think about this question first,"<<endl;
        cout<<"If you have written the answer,please enter '1' to get the answer:"<<endl;
        cin>>a;
        if(a==1){
            fstream infile3("intermediate_answer.txt",ios::in|ios::out);
            string Line3;
            while(getline(infile3,Line3))
            cout<<"The answer is:"<<endl;
            cout<<Line3<<endl;
            infile3.close();
        }
        cout<<"If you want to leave the exercise, please enter 1.if don't, enter 0 :";
        cin>>j;
        if(j==0){
            cout<<"Please Select a level(p(primary1) or p2(primary2) or m(mediate) or s(senior)):";
        }
    }
    if(level=='s'){


        fstream file4("senior.txt",ios::in|ios::out);
        string line4;
        while(getline(file4,line4))
        cout<<line4<<endl;
        cout<<"read and think about this question first,"<<endl;
        cout<<"If you have written the answer,please enter '1' to get the answer:"<<endl;
        cin>>b;
        if(b==1){
            fstream infile4("intermediate_answer.txt",ios::in|ios::out);
            string Line4;
            while(getline(infile4,Line4))
            cout<<"The answer is:"<<endl;
            cout<<Line4<<endl;
            infile4.close();
        }
        cout<<"You have finished all of the exercise,please enter 1 to leave:";
        cin>>j;
        if(j==0){
            cout<<"Please Select a level(p(primary1) or p2(primary2) or m(mediate) or s(senior)):";
        }
    }

 
    //to do
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

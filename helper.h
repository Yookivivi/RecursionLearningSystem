#include<fstream>
#include<iostream>
#include<string>
#include <stdlib.h>

using namespace std;

void print_txt_content(string fileName){
    fstream myfile(fileName,ios::in|ios::out);
    string line;
    while (getline (myfile, line)) { 
	    cout << line << endl;
	}
}

string get_txt_content(string fileName){
    fstream myfile(fileName,ios::in|ios::out);
    string line;
    while (getline (myfile, line)) { 
	    cout << line << endl;
	}
    return line;
}

void leaning_mode_table();
void main_directory();

void open_learning_file(int choice){
    //fstream myfile;
    //ifstream in;
    string line;
    switch(choice){
        case 1:{
            print_txt_content("learningMode\\learning1.txt");
            break;
        }
        case 2:{
            print_txt_content("learningMode\\learning2.txt");
            break;
        }
        case 3:{
            print_txt_content("learningMode\\learning3.txt");
            break;
        }
        case 4:{
            print_txt_content("learningMode\\learning4.txt");
            break;
        }
        case 5:{
            print_txt_content("learningMode\\learning5.txt");
            break;
        }
        case 6:{
            print_txt_content("learningMode\\learning6.txt");
            break;
        }
        case 7:{
            main_directory();
            break;
        }
    }

    if(choice==6){
        string anything;
        cout<<"This is the last part. Then we will go back to the learning mode table"<<endl;
        cout<<"Press anything to continue: ";
        cin>>anything;
        leaning_mode_table();
    }

    int next_choice;
    print_txt_content("learningMode\\next_choice.txt");
    cout<<"Your choice is: ";
    cin>>next_choice;
    while(next_choice!=1 && next_choice !=2){
        cout<<"Invalid choice! Please select it again: ";
        cin>>next_choice;
    }

    if(next_choice==1){
        leaning_mode_table();
    }

    else if(next_choice==2){
        open_learning_file(choice+1);
    }
    
}

//This is the mode to showing some basic concepts of recursion.
void leaning_mode_table(){
    print_txt_content("learningMode\\learningModeTable.txt");
    int choice;
    cout<<"Please choose the part you wanna go by inputting the corresponding number:";
    cin>>choice;
    while(choice<1 || choice>7){
        cout<<"Wrong input!"<<endl;
        cout<<"Please input the valid number agian:";
        cin>>choice;
    }
    open_learning_file(choice);
}

//This is the mode to do some recursion related questions.
void testing_mode_table(){
    char level;
    cout<<"Please Select a level(p(primary1) or p2(primary2) or m(mediate) or s(senior)):";
    cin>>level;
    int ans1,ans2;
    int real_ans1=0,real_ans2=0,k=0,h=0;
    int a,b;
    int j=0;

    while(j==0){
        
    if(level=='p'){
        print_txt_content("TestingMode\\primary1.txt");

        /*fstream file1("primary1.txt",ios::in|ios::out);
        string line1;
        while(getline(file1,line1))
        cout<<line1<<endl;*/
        cout<<"read and think about this question first,"<<endl;
        cout<<"Then please enter your answer here:";
        cin>>ans1;
        fstream infile1("TestingMode\\primary1_answer.txt",ios::in|ios::out);
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

        print_txt_content("TestingMode\\promary2.txt");
        /*fstream file2("primary2.txt",ios::in|ios::out);
        string line2;
        while(getline(file2,line2))*/
        cout<<line2<<endl;
        cout<<"read and think about this question first,"<<endl;
        cout<<"Then please enter your answer here:";
        cin>>ans2;
        fstream infile2("TestingMode\\primary2_answer.txt",ios::in|ios::out);
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
        print_txt_content("TestingMode\\intermediate.txt");
        
        cout<<"read and think about this question first,"<<endl;
        cout<<"If you have written the answer,please enter '1' to get the answer:"<<endl;
        cin>>a;
        if(a==1){
            fstream infile3("TestingMode\\intermediate_answer.txt",ios::in|ios::out);
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
        print_txt_content("TestingMode\\senior.txt");
        
        cout<<"read and think about this question first,"<<endl;
        cout<<"If you have written the answer,please enter '1' to get the answer:"<<endl;
        cin>>b;
        if(b==1){
            fstream infile4("TestingMode\\intermediate_answer.txt",ios::in|ios::out);
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
void welcome_message(){
    print_txt_content("welcome.txt");
}

//main directory
void main_directory(){
    int user_input;
    cout<<endl;
    print_txt_content("main_directory.txt");
    cout<<"Please select one mode by inputting the corresponding number: ";
    cin>>user_input;
    
    if(user_input==1){
        leaning_mode_table();
    }
    else if (user_input==2){
        testing_mode_table();
    }
    else if (user_input==3){
        exit(0);
    }
    else{
        cout<<"Wrong input! Please try it again!"<<endl;
        cout<<endl;
        main_directory();
    }
}
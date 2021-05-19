#include<fstream>
#include<iostream>
#include<string>
#include <stdlib.h>

using namespace std;

void main_directory();


/*
    Belows are common functions used in both Testing Mode and Learning mode
*/

void print_txt_content(string fileName){
    fstream myfile(fileName,ios::in|ios::out);
    string line;
    while(getline(myfile, line)){
        cout << line << endl;
    }
}

string get_txt_content(string fileName){
    fstream myfile(fileName,ios::in|ios::out);
    string line;
    getline (myfile, line);
    return line;
}



/*
    Belows are functions used in Learning mode
*/

void leaning_mode_table();

//This is the function to show the corresponding concepts according to the user's choice.
void open_learning_file(int choice){
    switch(choice){
        case 1:{
            print_txt_content("LearningMode\\learning1.txt");
            break;
        }
        case 2:{
            print_txt_content("LearningMode\\learning2.txt");
            break;
        }
        case 3:{
            print_txt_content("LearningMode\\learning3.txt");
            break;
        }
        case 4:{
            print_txt_content("LearningMode\\learning4.txt");
            break;
        }
        case 5:{
            print_txt_content("LearningMode\\learning5.txt");
            break;
        }
        case 6:{
            print_txt_content("LearningMode\\learning6.txt");
            break;
        }
        case 7:{
            main_directory();
            break;
        }
    }

    //The condition that it is the last concept, the user could only go back to the last slide.
    if(choice==6){
        string anything;
        cout<<"This is the last part. Then we will go back to the learning mode table"<<endl;
        cout<<"Press anything to continue: ";
        cin>>anything;
        leaning_mode_table();
    }

    //Ask the user to choose the next step, go to next question or go back to the last slide.
    int next_choice;
    print_txt_content("LearningMode\\next_choice.txt");
    cout<<"Your choice is: ";
    cin>>next_choice;

    //Check if the input is valid and ask the retype if it is invalid
    while(next_choice!=1 && next_choice !=2){
        cout<<"Invalid choice! Please select it again: ";
        cin>>next_choice;
    }
    
    if(next_choice==1){ leaning_mode_table(); }
    else{ open_learning_file(choice+1); }
}

//This is the function to showing the main table of learning mode
void leaning_mode_table(){
    print_txt_content("LearningMode\\learningModeTable.txt");

    int choice;
    cout<<"Please choose the part you wanna go by inputting the corresponding number: ";
    cin>>choice;

    //Check if the input is valid.
    while(choice<1 || choice>7){
        cout<<"Wrong input!"<<endl;
        cout<<"Please input the valid number agian: ";
        cin>>choice;
    }
    open_learning_file(choice);
}



/*
    Belows are functions used in Testing mode
*/

void testing_mode_table();
void open_testing_file(int, int);

//This is the function to get the file name of the answer file according to the question file.
string get_answer_file_name(string fileName){
    size_t pos = fileName.find(".");
    string answerFile = fileName.substr(0, pos);
    answerFile+="_ans.txt";
    return answerFile;
}

//This is the function to show the question and check user's answer
void do_the_test(string fileName, int choice_dir, int choice_file){
    print_txt_content(fileName);
    string user_answer, reference_answer;
    cin.ignore();
    cout<<"\nPlease input your answer here: ";
    getline(cin, user_answer);
    reference_answer = get_txt_content(get_answer_file_name(fileName));
    int next_choice;

    //Correct
    if(user_answer==reference_answer){

        if(choice_file==3){
            char anything;
            cout<<"#################\n#  CORRECT !!!  #\n#################\n\n";
            cout<<"We do not have more questions in this level\n";
            cout<<"Please enter anything to go back to the level selection slide: ";
            cin>>anything;
            testing_mode_table();
        }

        print_txt_content("TestingMode\\correct_table.txt");
        cout<<"Please enter your selection: ";
        cin>>next_choice;
        while(next_choice!=1 && next_choice!=2){
            cout<<endl<<"Invalid Input!"<<endl;
            cout<<"Please enter your selestion again!";
            cin>>next_choice;
        }
        if(next_choice==1){
            open_testing_file(choice_dir, choice_file+1);
        }
        else{
            testing_mode_table();
        }
    }

    //Wrong
    else{
        print_txt_content("TestingMode\\wrong_table.txt");
        cout<<"Please enter your selection: ";
        cin>>next_choice;
        while(next_choice!=1 && next_choice!=2){
            cout<<endl<<"Invalid Input!"<<endl;
            cout<<"Please enter your selestion again!";
            cin>>next_choice;
        }
        if(next_choice==1){
            do_the_test(fileName, choice_dir, choice_file);
        }
        else{
            cout<<endl<<"The answer of this question is: "<<reference_answer<<endl;
            cout<<endl;
            if(choice_file==3){
                char anything;
                cout<<"We do not have more questions in this level\n";
                cout<<"Please enter anything to go back to the level selection slide: ";
                cin>>anything;
                testing_mode_table();
            }
            print_txt_content("TestingMode\\wrong_next_choice.txt");
            cout<<"Please enter your selection: ";
            cin>>next_choice;
            while(next_choice!=1 && next_choice!=2){
                cout<<endl<<"Invalid Input!"<<endl;
                cout<<"Please enter your selestion again!";
                cin>>next_choice;
            }
            
            if(next_choice==1){
                open_testing_file(choice_dir, choice_file+1);
            }
            else{
                testing_mode_table();
            }
        }
    }
}

//This is the function to go to the corresponding question file according to the user's input.
void open_testing_file(int choice_dir, int choice_file){
    switch (choice_dir){

    //Beginner Level   
    case 1:
        switch (choice_file){
        case 1:
            do_the_test("TestingMode\\beginner\\1.txt", choice_dir, choice_file);
            break;
        case 2:
            do_the_test("TestingMode\\beginner\\2.txt", choice_dir, choice_file);
            break;
        case 3:
            do_the_test("TestingMode\\beginner\\3.txt", choice_dir, choice_file);
            break;
        }
        break;

    //Normal Level   
    case 2:
        switch (choice_file){
        case 1:
            do_the_test("TestingMode\\normal\\1.txt", choice_dir, choice_file);
            break;
        case 2:
            do_the_test("TestingMode\\normal\\2.txt", choice_dir, choice_file);
            break;
        case 3:
            do_the_test("TestingMode\\normal\\3.txt", choice_dir, choice_file);
            break;
        }
        break;

    //Advanced Level
    case 3:
        switch (choice_file){
        case 1:
            do_the_test("TestingMode\\advanced\\1.txt", choice_dir, choice_file);
            break;
        case 2:
            do_the_test("TestingMode\\advanced\\2.txt", choice_dir, choice_file);
            break;
        case 3:
            do_the_test("TestingMode\\advanced\\3.txt", choice_dir, choice_file);
            break;
        }
        break;
    }
}

void open_testing_directory(int choice){
    string line;
    int choice_file;
    switch(choice){
        case 1:{
            print_txt_content("TestingMode\\beginner\\table.txt");
            break;
        }
        case 2:{
            print_txt_content("TestingMode\\normal\\table.txt");
            break;
        }
        case 3:{
            print_txt_content("TestingMode\\advanced\\table.txt");
            break;
        }
        case 4:{
            main_directory();
            break;
        }
    }
    cout<<"Please input your selection: ";
    cin>>choice_file;
    while(choice_file>3 || choice_file<1){
        cout<<"Wrong input!"<<endl;
        cout<<"Please select again: ";
        cin>>choice_file;
    }
    if(choice_file==4){
        testing_mode_table();
    }
    else{
        open_testing_file(choice, choice_file);
    }
}


//This is the mode to do some recursion related questions.
void testing_mode_table(){
    print_txt_content("TestingMode\\testingModeTable.txt");
    int choice;
    cout<<"Please choose the part you wanna go by inputting the corresponding number:";
    cin>>choice;
    while(choice<1 || choice>4){
        cout<<"Wrong input!"<<endl;
        cout<<"Please input the valid number agian: ";
        cin>>choice;
    }
    open_testing_directory(choice);
}




/*
    Belows are functions to show welcome and ask the user to choose the using mode.
*/

//This function is used to show the welcome table for the users.
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
        cout<<endl<<"Thank you for using this system."<<endl;
        cout<<"Looking forward to see you next time."<<endl;
        cout<<"Bye!"<<endl;
        cout<<endl;
        exit(0);
    }
    else{
        cout<<"Wrong input! Please try it again!"<<endl;
        cout<<endl;
        main_directory();
    }
}

#include<iostream>                             //c++ input output library
#include<cstring>                              //c strings library for c++
using namespace std;
                                               //isUnique checks if a string has all different letters or not 
bool isUnique(char TestCase[100]){
    bool CharStatus[26];
    strupr(TestCase);                          /*converting the string to uppercase alphabet to make it easy to figure out
                                                 all alphabets irrespective of case*/

    for (int i = 0; i < 26; i++)               //initialising all elements in CharStatus to false as it didn't encounter any letters 
        CharStatus[i] = false;
    for (int i=0;TestCase[i] != '\0';i++){
                                               //checks the status of any previous occurances of any alphabets letter by letter
        if(CharStatus[TestCase[i]-'A']){
                                               /*enters this block if any previous occurances (character status) is encountered and 
                                                 hence returns false*/
           return false; 
        }
        else{
                                               /*enters this block if an alphabet is occured for first time and sets the status of 
                                               that character to true*/
            CharStatus[TestCase[i]-'A'] = true;
        }
    }
                                               /*if loop ends without entering if block (i.e not encountering same element atleast twice)
                                                string has all different alphabets*/
    return true;
}
main(){
    char input[100];
    while(1){
    cout<<"Give your string "<<endl;
    cin.getline(input,100);
    cout<<"your string is "<<input<<endl;
    if(isUnique(input)){
        cout<<"String is unique \n"<<endl;
    }
    else{
        cout<<"string is not unique \n"<<endl;
    }
    }
    return 0;
}

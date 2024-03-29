/*
Q8: There are two processes, A and B, that can access a common variable x. They can access it in
sequence, A first and then B, or B first then A. But in one day they access it only once. A logbook is
maintained by the OS showing which process accessed x when.
You got a series of entries of the log, but you want to make sure that this log has not been
altered by anyone. Your output is the answer to the question: Is the log valid or not?

Ex: Input: AB, output: Yes
Input: ABAABB, output: No
*/


#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the log of processers used:\n";
    cin>>n;
    char a[n];
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
       if(a[i]==a[i-1]) {
           printf("No"); 
           return 0;
           } 
    }
    cout<<"Yes";
    return 0;
}
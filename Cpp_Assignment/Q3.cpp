/**
Q3: You have a binary string with length N. You are allowed to do swap() operations of two elements
only if the index parity of both elements is the same. This means that: you can swap() an element at
index 2, with any element at index4, 6, 8 etc. (even parity), similarly the element at index 3 can be
swapped with the element at index1, 5,7,9 etc.

Ex: Given string 1110, you can swap 2nd and 4th char to get 1011. But, you can never get 1101 if you
follow the swap rules.
Now, the task is to find the number of times substring 01 can occur for all such possible swaps.

Ex: 1110 does not have any substring of 01. Now you can swap2nd and 4th to get 1011, this will have
‘one’ occurrence of 01. We can now perform more swaps but we will never get any more 01
substrings here.
Input: 00100 output should be 1, for: 01010-> 2, for 10001-> 2
**/



#include<iostream>
#include<string>
using namespace std;

void swap_(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}

int main(){
    int count=0;
    string str;
    cout<<"Enter a string:\n";
    cin>>str;
    int n= str.length();
    
    for(int i=0;i<n;i++)
    {
        if(str[i]=='0'||str[i]=='1') 
        cout<<str[i];
    }
    
    for(int i=0;i<n;i++) 
    { 
    if(str[i]=='0' && str[i+1]=='1') 
    count++;
    }
    
    if(n%2==0)
    {
        for(int i=0;i<n;i++)
        {
            string str1=str;
            if(i%2==0)
            {
                if(i==n-2 || i==n-1) {
                swap_(str1[0],str1[i]);
                }
                else {
                    swap_(str1[i+2],str1[i]);
                    cout<<"string after "<<i <<": "<<str<<endl;
                }
                if(str1[i]=='0' && str1[i+1]=='1') {
                count++;
                }
                else
                {
                    if(i==n-2 || i==n-1) { 
                    swap_(str1[1],str1[i]); 
                    } else {
                        swap_(str1[i+2],str1[i]);
                        cout<<"string after "<<i <<": "<<str<<endl;
                    }
                if(str1[i]=='0' && str1[i+1]=='1') count++;
                }
            }
        }
    }

    else{
        for(int i=0;i<n;i++){
            string str1=str;
            if(i%2!=0){
                if(i==n-2 || i==n-1) {
                    swap_(str1[1],str1[i]);
                }
                else {
                    swap_(str1[i+2],str1[i]);
                }
                
                if(str1[i]=='0' && str1[i+1]=='1') {
                count++;
                }
                else
                {
                    if(i==n-2 || i==n-1) 
                    { 
                    swap_(str1[1],str1[i]);
                    }
                    else 
                    {
                        swap_(str1[i+2],str1[i]);
                    }
                if(str1[i]=='0' && str1[i+1]=='1') count++;
                }
            }
        }
    }
    cout<<"\ncount: "<<count<<endl;
    return 0;
}
#include <string>
#include <iostream>
using namespace std;

void swap(string &input, int i, int j){
    char temp;
    temp=input[i];
    input[i]=input[j];
    input[j]=temp;
}

void reverseSort(string &input, int start, int end){
    if(start>end)
        return;
    for(int i=start;i<=(end+start)/2;i++)
        swap(input,i,start+end-i);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T = 1;
    //cin >> T;
    while(T--)
    {
        string input = "ayzaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        //cin >> input;
        int n=input.size();
        int index=n-1;
        while(index>0){
            if(input[index-1] < input[index])
                break;
            index--;
        }
        if(index==0){
            if(input[0] >= input[n-1])
                cout << "no answer" << endl;
            else
            {
                reverseSort(input,0,n-1);
                cout << input << endl;
            }
        }
        else{
            char val = input[index-1];
            int j = n-1;
            while(j >= index){
                if(input[j]>val)
                    break;
                j--;
            }
            swap(input,j,index-1);
            reverseSort(input,index,n-1);
            cout << input << endl;
        }
    }
    return 0;
}

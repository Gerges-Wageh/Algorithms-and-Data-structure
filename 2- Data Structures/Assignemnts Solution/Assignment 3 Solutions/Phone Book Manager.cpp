#include<bits/stdc++.h>
using namespace std;
#define BOOKSIZE 10000000
static string PhoneBook[BOOKSIZE];
int main(){
    int N, number;
    string query,name;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>query;
        if(query == "add"){
            cin>>number>>name;
            PhoneBook[number]=name;
        }
        else if(query == "find"){
            cin>>number;
            if(PhoneBook[number]!="")
                cout<<PhoneBook[number]<<endl;
            else
                cout<<"not found"<<endl;
        }
        else{
            cin>>number;
            PhoneBook[number]="";
        }
    }

    return 0;
}

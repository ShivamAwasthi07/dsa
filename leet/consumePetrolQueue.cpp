#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    vector<int> petrol, path;
    
    int n = 4;
    petrol.push_back(4);
    petrol.push_back(6);
    petrol.push_back(7);
    petrol.push_back(4);

    path.push_back(6);
    path.push_back(5);
    path.push_back(3);
    path.push_back(5);

    for(int i=0;i<n;i++){
        int bal = petrol[i];
        bool complete = true;
        for(int j=i;j<=i+n;j++){
            cout<<bal<<" "<<i<<" "<<j<<endl;
            bal-=path[j%n];
            if(bal < 0) {
                cout<<"true at"<<bal<<" "<<i<<" & "<<j<<endl;
                complete = false;
                break;
            }
            else{
                bal+=petrol[(j+1)%n];
            }
        }
        if(complete){
            cout<<endl<<"completed from "<<i<<"th petrol pump";
            break;
        }
        cout<<"not completed "<<endl;
    }
    return 0;
}
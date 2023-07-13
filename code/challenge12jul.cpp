#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	long long prod; 
	int a,b;
	while(t--){
	    int x,y,z;
	    cin>>x>>y>>z;
	    prod = x*y*z;
	    if(prod%x == 0 && (prod/x)%x==0){
            cout<<t<<" Enter x"<<endl;
            cout<<prod/x<<" "<<x<<endl;
	    }
	    else if(prod%y == 0 && (prod/y)%y==0){
            cout<<t<<" Enter y"<<endl;
	        cout<<prod/y<<" "<<y<<endl;
	    }
	    else if(prod%z == 0&& (prod/z)%z==0){
            cout<<t<<" Enter z"<<endl;
            cout<<prod/z<<" "<<z<<endl;
	    }
	    else{
            cout<<t<<" Enter else"<<endl;
	        cout<<"-1"<<endl;
	    }
	}
	return 0;
}
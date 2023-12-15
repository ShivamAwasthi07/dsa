#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(vector<int> &v, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(v[j] > v[j+1]) swap(v[j+1], v[j]);
        }
    }
}

void insertionSort(vector<int> &v, int n){
    for(int i=1;i<n;i++){
        int toSwap = v[i];
        int j = i-1;
        while(j >= 0){
            if(v[j] < toSwap){
                break;
            } else {
                v[j+1] = v[j];
                j--;
            }
        }
        v[j+1] = toSwap;
    }
}

int minIndex(vector<int> v, int start, int end){
    int mini = INT_MAX, index = -1;

    for(int i = start; i<= end;i++){
        if(v[i] < mini) {
            index = i;
            mini = v[i];
        }
    }
    return index;
}

void selectionSort(vector<int> &v, int n){
    for(int i=0;i<n;i++){
        int indexSwap = minIndex(v, i, n-1);
        
        swap(v[i], v[indexSwap]);
    }

}

int main(){
    vector<int> v;
    v.push_back(6);
    v.push_back(0);
    v.push_back(3);
    v.push_back(2);
    v.push_back(8);
    v.push_back(5);
    v.push_back(2);
    int n = v.size();

    selectionSort(v, n);
    printVector(v);
    
    return 0;
}
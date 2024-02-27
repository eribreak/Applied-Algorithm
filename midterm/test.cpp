#include <bits/stdc++.h>
using namespace std;

deque<int> n;

void printArray(){
    for (int i=0; i<n.size(); i++){
        cout << n[i] << " ";
    }
    cout << endl;
}

int main(){
    n.push_back(2);
    n.push_back(3);
    n.push_back(4);
    n.push_front(5);
    printArray();

    n.pop_back();
    printArray();

    n.pop_front();
    printArray();    
    return 0;
}
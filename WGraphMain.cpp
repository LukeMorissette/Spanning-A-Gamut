#include "WGraph.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    /*WGraph g = WGraph(4);
    g.addEdge(0,1,1);
    g.addEdge(0,3,7);
    g.AvoidLoop(1,3);
    return 0;*/


    string inputString;
    string line;
    int n;
    int row;
    int col;
    double val;
    int count;
    int i = 0;
    int z = 0;
    cout << "Please enter the name of your input file: " << endl;
    cin >> inputString;
    ifstream input_file(inputString);
    getline(input_file, line); 
        istringstream iss1(line);
        iss1 >> n;
    WGraph g = WGraph(n);
    count = 0;
    while (getline(input_file, line)) {
            if (count == n) {
                break;
            }
    istringstream iss2(line); 
    for (i = 0;i < n; i++){
        iss2 >> val;
        if (val != 0 && i >= z){
            g.addEdge(count,i,val);
        }
    }
    count++;
    z++;
    }
    g.createKruskal();
    g.printKruskal();
    return 0;
}

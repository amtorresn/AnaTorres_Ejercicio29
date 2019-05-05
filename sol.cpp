#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

using std::cout;
using std::endl;

void solve(string filename);

int main(){
    
    solve("datos.dat")
    return 0;
}

void solve(string filename){
    
    ofstream outfile;
    outfile.open(filename);
    
    
  
    outfile.close();
    
}
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
    
    solve("datos.dat");
    return 0;
}

void solve(string filename){
    
    ofstream outfile;
    outfile.open(filename);
    
    float dx = 0.01;
    float dt = 0.01;
    int Tmax = 6;
    float c = 0.5;
    float cc = dx/dt;
    float c1 = c*c/(cc*cc);
    float L = 1.0;
    
    float xi[100][3];
    float xii[100][3];
    
    for (int i = 0; i < 101; i++){
        xi[i][0] = sin(i*M_PI/100);
        xi[i][1] = 0; //not sure
        xii[i][0] = xi[i][0];
        xii[i][1] = xi[i][1];
    }
    
    float t = 0;
    while(t<=Tmax){
        
        for(int i = 1; i < 100; i++){
            xi[i][1] = xi[i][0] + 0.5*c1*(xi[i+1][0] + xi[i-1][0] - 2*xi[i][0] );
            xi[i][2] = 2*xi[i][1] - xi[i][0] + c1*(xi[i+1][1] + xi[i-1][1] - 2*xi[i][1] );
        }
        t = t+dt;
        for(int i = 0; i < 101; i++){
            xi[i][0] = xi[i][1];
            xi[i][1] = xi[i][2];
        }
    }
    for(int i = 0; i < 101; i++){
            outfile << xii[i][0] << " " << xii[i][1] << " " << xi[i][0] <<  " " <<  xi[i][1] << " " << xii[i][2] << endl;
     }
  
    outfile.close();
    
}
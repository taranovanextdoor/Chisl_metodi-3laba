#include <iostream>
#include <math.h>
#include "12var.h"
using namespace std;
struct Gap{
    double low_limit;//нижняя граница интервала
    double upper_limit;//верхняя граница
    double deg_acc;//нужная степень точности
};
istream& operator>>(istream& in,Gap& g){
    cout << "Enter low limit: " << endl;//0
    in >> g.low_limit;
    cout << "Enter upper limit: " << endl;
    in >> g.upper_limit;//2
    cout << "Enter degree of accuracy" << endl;
    in >> g.deg_acc; //0.001
    return in;
}
void FindX(Gap& g,double& x){
    double y1, y2;
    x = 0.5*( g.low_limit + g.upper_limit );
    y1 = findY( x );
    y2 = findY( g.low_limit );
    if( (y1*y2) < 0 ){
        g.upper_limit = x;
    }else{
        g.low_limit = x;
    }
}
int main(){
    Gap g;
    cin >> g;
    double x;
    while(abs( g.low_limit - g.upper_limit ) > g.deg_acc ){

        cout << "low_limit: " << g.low_limit << endl ;
        cout << "upper_limit: " << g.upper_limit << endl ;
        cout << "x is :" << x << endl;
        FindX(g,x);
        cout << endl;
    }
    cout << "X is " << x << endl;
    return 0;
};
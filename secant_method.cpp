#include<bits/stdc++.h>
using namespace std;
#define precision 0.0001
void coeffiecient(string str,double &a,double&b,double&c)
{
    int x_square_position=str.find("x^2");
    int x_position=str.find("x",x_square_position+3);
    int equal_position= str.find("=");
    string astr=str.substr(0,x_square_position);
    string bstr= str.substr(x_square_position+3,x_position);
    string cstr=str.substr(x_position+1,equal_position);
    istringstream(astr)>>a;
    istringstream(bstr)>>b;
    istringstream(cstr)>>c;
}
double F(double a,double b,double c, double x)
{
    return a*x*x+b*x+c;
}
double secant(double a,double b,double c,double x1,double x2)
{
    while(true)
    {
        double fx1=F(a,b,c,x1);
        double fx2=F(a,b,c,x2);
        double x3=(x1*fx2-x2*fx1)/(fx2-fx1);
        if(abs(x3-x2)<precision)
            return x3;
        x1=x2;
        x2=x3;
    }
}

int main()
{
    string str="1x^2-4x-10=0";
    double a,b,c,x1,x2;
    coeffiecient(str,a,b,c);
    cout<<"Enter initial values of  x1 and x2:\n";
    cin>>x1>>x2;   /// x1=5 x2=3
    double x=secant(a,b,c,x1,x2);
    cout<<"Solution: "<<x<<endl;

}

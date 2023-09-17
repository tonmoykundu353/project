#include<bits/stdc++.h>
using namespace std;
#define precision 0.00001

void coeffiecient(string str,double &a,double &b,double &c)
{
    int a_pos=str.find("x^2");
    int b_pos=str.find("x",a_pos+3);
    int equal_pos=str.find("=");
    string a_str,b_str,c_str;
    a_str=str.substr(0,a_pos);
    b_str=str.substr(a_pos+3,b_pos);
    c_str=str.substr(b_pos+1,equal_pos);
    istringstream(a_str)>>a;
    istringstream(b_str)>>b;
    istringstream(c_str)>>c;
}
double F(double a,double b,double c,double x)
{
    return  a*x*x+b*x+c;
}
double secant(double a,double b,double c,double x1,double x2)
{
    double fx1,fx2,x3;
    while(true)
    {
        fx1=F(a,b,c,x1) ;
        fx2=F(a,b,c,x2) ;
        x3=(x1*fx2-x2*fx1)/(fx2-fx1);
        if(abs(fx1-fx2)<precision)
            return x3;
        x1=x2;
        x2=x3;
    }
}
double derivative(double a, double b, double x)
{
    return 2*a*x + b;
}
double Newton_Raphson(double a,double b,double c,double x1)
{
    double fx,fx1,x2;
    while(true)
    {
        fx=F(a,b,c,x1);
        fx1=derivative(a,b,x1);
        x2 = x1 - fx/fx1;
        if(abs(x1-x2)<precision)
            return x2;
        x1=x2;
    }
}
int main()
{
    //cout<<"give the equation : ";
    string str2="1x^2-5x+4=0";
    string str1="1x^2-4x-10=0";
    //cin>>str;
    //cout<<"enter the initial values : ";
    double a,b,c,x1,x2,x3;
    //cin>>x1>>x2;
    x1=5.0;
    x2=3.0;
   coeffiecient(str1,a,b,c);
   x3=secant(a,b,c,x1,x2);
    cout<<" solution by secant : "<<x3<<endl;
   coeffiecient(str2,a,b,c);
    x1=0.0;
    x3=Newton_Raphson(a,b,c,x1);
   cout<<"solution by newton_raphson : "<<x3<<endl;

}

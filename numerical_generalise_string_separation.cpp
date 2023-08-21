#include<bits/stdc++.h>
using namespace std;

int main() {
    string str= "-1x-5y+3z=0";  /// ax+by+cz=d ei type er equation hobe ,and obossoi a,b,c,d thakte hobe,, sign doesnot matter
                                                    /// x+2y-3z=6 not acceptable cause x er samne sohog detect korte pabe naa

    // Find positions of coefficients and operators
    int xPos = str.find("x");
    int yPos = str.find("y");
    int zPos = str.find("z");
    int cPos = str.find("=");

    cout<<xPos<<endl;
    cout<<yPos<<endl;
    cout<<zPos<<endl;
    cout<<cPos<<endl;

    // Extract coefficient strings
    string xStr = str.substr(0, xPos);
    string yStr = str.substr(xPos+1,yPos );
    string zStr = str.substr(yPos+1, zPos);
    string cStr = str.substr(zPos+2);

    // Convert coefficient strings to numbers
    double x, y, z,c;
    istringstream(xStr) >> x;
    istringstream(yStr) >> y;
    istringstream(zStr) >> z;
    istringstream(cStr) >> c;

    // Output coefficients
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << "c = " << c<< endl;

        string quadraticEquation = "-1x^2-5x+3=0";

    // Find positions of coefficients and operators
   int    aPos = quadraticEquation.find("x^2");
    int bPos = quadraticEquation.find("x", aPos + 3); // Start searching after "x^2" cause x^2 teo x ache,,taile oikhanei atke jabe
    cPos = quadraticEquation.find("=");

    cout<<aPos<<endl;
     cout<<bPos<<endl;
      cout<<cPos<<endl;

    // Extract coefficient strings
    string aStr = quadraticEquation.substr(0, aPos);
    string bStr = quadraticEquation.substr(aPos + 3,bPos );
    cStr = quadraticEquation.substr(bPos + 1, cPos);

    // Convert coefficient strings to numbers
    double a, b;
    istringstream(aStr) >> a;
    istringstream(bStr) >> b;
    istringstream(cStr) >> c;

    // Output coefficients
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;


    return 0;
}

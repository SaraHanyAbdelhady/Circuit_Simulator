#include <iostream>
#include<string.h>
using namespace std;
int main()
{
    string description;
    double voltage;
    cout << "Please, enter the circuit description: "<<"\n";
    getline(cin,description);
    cout << "Enter the voltage applied: "<<"\n";
    cin >> voltage;
    string type = description.substr (0,1);
    string r1 = description.substr (2,1);
    float R1 = stof(r1);
    string r2 = description.substr (4,1);
    float R2 = stof(r2);
    string r3 = description.substr (6,1);
    float R3 = stof(r3);
    if (type == "S")
    {
        double Rt=R1+R2+R3;
        cout <<"the equivalent resistance = "<<Rt<<"\n";
        double It = voltage/Rt;
        cout <<"the total current passing = "<< It;
    }
    else if (type == "P")
    {
        double Rt=1/((1/R1)+(1/R2)+(1/R3));
        cout <<"the equivalent resistance = "<< Rt<<"\n";
        double It = voltage/Rt;
        cout <<"the total current passing = "<< It;
    }
    return 0;
}

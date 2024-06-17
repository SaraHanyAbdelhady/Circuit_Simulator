#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string description;
    double voltage;
    cout << "Please, enter the circuit description: "<<"\n";
    getline(cin,description);
    cout << "Enter the voltage applied: "<<"\n";
    cin >> voltage;
    char type = description [0];
    int x=2;
    int y=0;
    double z=0 ;
    double Rts=0;
    double Rtp =0;
    for (x ; x <  description. length ();x++)
    {

        char R= description[x];
        cout <<"R= " << R << endl;
        if ( R==' ' )
        {
            string Resistance = description.substr(x-y,y);
            float r =stof (Resistance);
            Rts = Rts +r ;
            cout << "RTs1 = " <<Rts << endl ;
            z = z +1/r ;
            Rtp = 1/z ;
            y=0;
            cout << "RTp1 = " <<Rtp << endl ;
        }
        y++;
        cout << "x= " << x <<" , y = " << y << endl ;
    }



    if (type == 'S')
    {
      cout <<"the equivalent resistance = "<<Rts<<"\n";
      double It = voltage/Rts;
      cout <<"the total current passing = "<< It;



    }
    else if (type == 'P')
    {

      cout <<"the equivalent resistance = "<<Rtp<<"\n";
      double It = voltage/Rtp;
      cout <<"the total current passing = "<< It;



    }
    else
    {
        cout <<"Invalid connection";
    }
    return 0;
}

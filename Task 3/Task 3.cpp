#include <iostream>
#include <string.h>
#include<vector>

using namespace std;
float Rseries (vector <float>&r)
{
    float Rt=0;
    int n = r.size();
    for (int i=0; i <n; i++) Rt+=r[i];
    return Rt;
}
float Rparallel (vector <float>&r)
{
    float x=0;
    int n = r.size();
    for (int i=0; i<n; i++)
    {
        if (x == 0) x = 1/r[i];
        else x += 1/r[i];
    }
    return (1/x);
}
int main()

{
    string description;
    float voltage, Rt=0;
    bool flag =1;
    cout << "Please, enter the circuit description: " << "\n";
    getline (cin, description);
    string arr[50];
    string x;
    int index = 0;
    for(int i =0; i < description.length(); i++)
    {
        if(description[i] == ' ')

        {
            arr[index] = x;
            index++;
            x = "";
        }
        else
        {
            x += description[i];
        }

    }
    cout << "Enter the voltage applied: " << "\n";
    cin >> voltage;
    vector <float> series;
    vector <float> parallel;
    if (arr[0]=="S")
    {
        for (int i=1; i< index; i++)
        {
        if (arr[i] == "P")
        {
            vector <float>sub_parallel;
            i++;
            if (stof(arr[i]) < 50&&stof(arr[i])>0)
            {
                while (arr[i]!="e")
                {
                    sub_parallel.push_back(stof(arr[i]));
                    i++;
                }
                float R= Rparallel (sub_parallel);
                series.push_back(R);
                sub_parallel.clear ();
            }

        }
        else if (stof (arr[i])<50&&stof(arr[i])>0)
        {
            series.push_back(stof(arr[i]));
        }
    }
    Rt= Rseries(series);
}
else if (arr[0] =="P")

{
    for (int i=1; i< index; i++)
    {
        if (arr[i] == "S")
        {
            vector <float>sub_series;
            i++;
            if (stof(arr[i]) < 50&&stof(arr[i])>0)
            {
                while (arr[i]!="e")
                {
                    sub_series.push_back(stof(arr[i]));
                    i++;
                }
                float R= Rseries (sub_series);
                parallel.push_back(R);
                sub_series.clear ();
            }

        }
        else if (stof (arr[i])<50&&stof(arr[i])>0)
        {
            parallel.push_back(stof(arr[i]));
        }
    }
    Rt= Rparallel(parallel);
}
else
{
    cout <<"Invalid connection";
    flag=0;
}

if(flag)
{
    cout <<"the equivalent resistance = "<<Rt<<"\n";
    double It = voltage/Rt;
    cout <<"the total current passing = "<< It;
}
return 0;
}

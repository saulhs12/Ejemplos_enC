#include <iostream>
#include <random>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
int main(){
    
    int n = 4;
    double x[n];
    double y[n];
    
    double x1,y1; 
    cout<<"Ingresa los puntos a graficar"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"Punto "<<i+1<<endl;
        cout<<"x: ";
        cin>>x1;
        x[i]=x1;
        cout<<"y: ";
        cin>>y1;
        y[i]=y1;
    }
    
    string command_filename;
    ofstream command_unit;
    string data_filename;
    ofstream data_unit;
    int i;
    string plot_filename;
    string name = "puntos_2";
    //  Write the data file.

    data_filename = name + "_data.dat";
    data_unit.open(data_filename.c_str());
    for (i = 0; i < n; i++)
    {
        data_unit << x[i] << "  "
            << y[i] << "\n";
    }
    data_unit.close();
    cout << "\n";
    cout << "  Plot data written to the file \"" << data_filename << "\"\n";
    
    //  Write the command file.
    
    system("gnuplot -p -e  \"plot 'puntos_2_data.dat'\"");
    plot_filename = name + ".png";
    return 0;
}
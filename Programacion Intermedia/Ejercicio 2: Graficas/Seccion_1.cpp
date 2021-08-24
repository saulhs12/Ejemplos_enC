#include <iostream>
#include <random>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
int main(){
    
    int n = 20;
    double x[n];
    double y[n];
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<>distr(-20,20);
       
    for (int i = 0; i < n; i++)
    {
        x[i]=distr(eng);
        y[i]=distr(eng);
    }
    
    string command_filename;
    ofstream command_unit;
    string data_filename;
    ofstream data_unit;
    int i;
    string plot_filename;
    string name = "puntos";
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
    cout << "  Plot data written to the file \"" << data_filename << "\".\n";
    
    //  Write the command file.
    
    system("gnuplot -p -e \"plot 'puntos_data.dat'\"");
    plot_filename = name + ".png";
    return 0;
}
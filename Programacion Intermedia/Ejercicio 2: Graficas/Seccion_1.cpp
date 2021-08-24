#include <iostream>
#include <random>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
//https://github.com/saulhs12/Ejemplos_enC
using namespace std;
int main(){
    //cantidad de  puntos
    int n = 20;
    //Arreglos que contienen las coordenadas de los puntos
    double x[n];
    double y[n];
    //declaracion de cosas para fabricar numeros aleatorios
    random_device rd;
    default_random_engine eng(rd());
    //rango de los numeros aleatorios
    uniform_real_distribution<>distr(-20,20);
    //ciclo que llena a los arreglos con numeros aleatorios
    for (int i = 0; i < n; i++)
    {
        x[i]=distr(eng);
        y[i]=distr(eng);
    }
    //cosas que necesito para construir el archivo
    //con los puntos asociados
    string command_filename;
    ofstream command_unit;
    string data_filename;
    ofstream data_unit;
    int i;
    string plot_filename;
    //nombre del archivo
    string name = "puntos";
    //  Write the data file.
    //se llena el archivo con los puntos del arreglo
    data_filename = name + "_data.dat";
    data_unit.open(data_filename.c_str());
    for (i = 0; i < n; i++)
    {
        data_unit << x[i] << "  "
            << y[i] << "\n";
    }
    data_unit.close();
    cout << "\n";
    cout << "  Graficar las coordenadas del archivo: \"" << data_filename << "\".\n";
    
    //  Write the command file.
    //se llama al programa de gnuplot  y lo grafica
    system("gnuplot -p -e \"plot 'puntos_data.dat'\"");
    plot_filename = name + ".png";
    return 0;
}
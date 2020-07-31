#include <iostream>
#include <random>
#include <iomanip>
#include <math.h>
using namespace std;
double leibniz(int,int);
int main()
{
    char resp = 's';

    while (resp == 's')
    {
        int opcion;
        cout << "1) Ejercicio 1" << endl
             << "2) Ejercicio 2" << endl
             << "3) Ejercicio 3" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            break;
        case 2:
        {
            int tamano = 0;
            cout << "Ingrese el tamaño de la matriz" << endl;
            cin >> tamano;
            int matriz[tamano][tamano];
            for (int i = 0; i < tamano; i++)
            {
                for (int j = 0; j < tamano; j++)
                {
                    int num_random = rand() % 89 + 10;
                    matriz[i][j] = num_random;
                }
            }
            for (int i = 0; i < tamano; i++)
            {
                for (int j = 0; j < tamano; j++)
                {
                    cout << setw(2) << matriz[i][j] << " ";
                }
                cout << endl;
            }
            int acum_valor = 0;
            double media;
            double desviacion, parte1_desv, part2_desv, parte3_desv;
            for (int i = 0; i < tamano; i++)
            {
                for (int j = 0; j < tamano; j++)
                {
                    acum_valor += matriz[i][j];
                }
            }
            media = acum_valor / (tamano * tamano);
            for (int i = 0; i < tamano; i++)
            {
                for (int j = 0; j < tamano; j++)
                {
                    parte1_desv = matriz[i][j] - media;
                    part2_desv = pow(parte1_desv, 2);
                    parte3_desv = part2_desv / (tamano * tamano);
                    desviacion += sqrt(parte3_desv);
                }
            }
            double matriz_estandar[tamano][tamano];
            for (int i = 0; i < tamano; i++)
            {
                for (int j = 0; j < tamano; j++)
                {
                    matriz_estandar[i][j] = (matriz[i][j] - media) / (desviacion);
                }
            }
            cout<<"Esta es la matriz estandar:"<<endl;
            for (int i = 0; i < tamano; i++)
            {
                for (int j = 0; j < tamano; j++)
                {
                    cout << setw(10) << matriz_estandar[i][j] << " ";
                }
                cout << endl;
            }
        }
        break;

        case 3:
            int max_sum;
            cout << "Ingrese el numero maximo de la sumatoria: " << endl;
            cin >> max_sum;
            cout<<"La respuesta es: "<<leibniz(max_sum,0)*4<<endl;
            break;
        }
    }
}
double leibniz(int max,int cont){
if(cont==max){
    return 0;
}else{
return (pow(-1,cont))/((2*cont)+1)+leibniz(max,cont+1);
}
return 0;
}

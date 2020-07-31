#include <iostream>
#include <random>
#include <iomanip>
#include <math.h>
using namespace std;
double leibniz(int, int);
double raphson(double, int,int,int,int);
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
            int num1, num2, num3;
            cout << "Ingrese los numeros de la ecuacion porfavor: " << endl;
            cin >> num1;
            if (num1 <= 0)
            {
                cout << "Ingrese un numero mayor a 0: " << endl;
                cin >> num1;
            }
            cout << endl;
            cin >> num2;
            cout << endl;
            cin >> num3;
            cout << endl;
            double vertice;
            vertice = -num2 / (2 * (num1));
            double ejecucion_1, ejecucion_2;
            ejecucion_1 = vertice + 200;
            ejecucion_2 = vertice - 200;
            cout << "Ejecucion 1 "<<raphson(ejecucion_1,num1,num2,num3,0)<<endl;
            cout << "Ejecucion 2 "<<raphson(ejecucion_2,num1,num2,num3,0)<<endl;
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
            cout << "Esta es la matriz estandar:" << endl;
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
            cout << "La respuesta es: " << leibniz(max_sum, 0) * 4 << endl;
            break;
        }
    }
}
double leibniz(int max, int cont)
{
    if (cont == max)
    {
        return 0;
    }
    else
    {
        return (pow(-1, cont)) / ((2 * cont) + 1) + leibniz(max, cont + 1);
    }
    return 0;
}

double raphson(double numero, int num1,int num2,int num3,int cont )
{
    if(cont==100){
return numero;
    }else{
        double x_subn=raphson(numero,num1,num2,num3,cont+1);
return x_subn-((num1*pow(x_subn,2))+(num2*x_subn)+num3)/((2*num1*x_subn)+num2);
    }
    return 0;
}


#include <Windows.h>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N=3;
    int M=13;
    int *array_M=new int[M];
    int *array_N = new int[N];
    int *sort_array = new int[M];
    map <int, bool> Dictonary_repeat;

    //инициализация словаря чтобы в дальнешем при создаании случайно перестановки числа в ней не повторялись
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        Dictonary_repeat[i] = true;
    }
    //инициализация массива случайно пестановки
    cout << "Массив случайных перестановок:" << endl;
    for (int i = 0; i < N; i++)
    {
        int m = 0 + rand() % N;
        if (Dictonary_repeat[m])
        {
            array_N[i] = m;
            cout << array_N[i] << " ";
            Dictonary_repeat[m] = false;
        }
        else
        {
            i--;
        }
    }
    cout <<"\nМассив длины М:"<< endl;
    //иницализация массива данных array_M
    for (int i = 0; i < M; i++)
    {
        array_M[i] = 0 + rand() % 100;
        cout << array_M[i] << " ";
    }
    cout << "\nОтсортированный массив:" << endl;
    if (N == M)
    {
        for (int i = 0; i < M; i++)
        {
            sort_array[i] = array_M[array_N[i]];
            cout << sort_array[i] << " ";
        }
    }
    if (N > M)
    {
        int j = 0;
        for (int i = 0; i < N; i++)
        {
            if (array_N[i] < M) 
            {
                sort_array[j] = array_M[array_N[i]];
                cout << sort_array[j] << " ";
                j++;
            }
        }
    }
    //не совсем понятно как переставлять значяения прри M>N
    //поэтому я это понял и реализорал это следующим образом
    //когда M>N, проверяется кратность М на N
    //если M кратно N то мы первые N элементов выстраиваем в порядке заданым перестановкой, затем следующую группу N элементов выстраиваем в порядке перестановки N и т.д.
    //если M не кратная то с кратными группами мы поступаем аналогично верхней строчке, а не кратный конец ставится в начало массива, так как они имеют значение порядка 0.
    //Нельзя только N=0, это глупо будет
    if (M > N)
    {
        int j = 0;
        if (M%N ==0)
        {
            for (int i = 0; i < M; i++)
            {

                    sort_array[i] = array_M[array_N[j]+(i/N)*N];
                    cout << sort_array[i] << " ";
                    j++;
                    if (N == j)
                        j = 0;
            }
        }
        else
        {
            int int_g = M % N;
            for (int i = 0; i < int_g; i++)
            {
                sort_array[j] = array_M[M-int_g+i];
                cout << sort_array[j]<< " ";
                j++;
            }
            j = 0;
            for (int i = 0; i + int_g < M; i++)
            {
                sort_array[i+int_g] = array_M[array_N[j] + (i / N) * N];
                cout << sort_array[i + int_g] << " ";
                j++;
                if (N == j)
                    j = 0;
            }
        }
    }
}


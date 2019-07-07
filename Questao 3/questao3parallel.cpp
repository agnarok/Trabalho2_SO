#include <omp.h>
#include <vector>
#include <chrono>
#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    int vet[2];
    omp_set_num_threads(10);
#pragma omp parallel
    {   
        cout << "Thread " << omp_get_thread_num() << " inizializando" << endl;

        cout << "Thread " << omp_get_thread_num() << " executando" << endl;
        vet[0] = omp_get_thread_num();
        cout << "Thread " << omp_get_thread_num() << " finalizada" << endl;
        
    }
    cout << vet[0] << endl;
}
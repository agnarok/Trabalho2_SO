#include <omp.h>
#include <vector>
#include <chrono>
#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    omp_lock_t lock;
    omp_init_lock(&lock);
    int vet[2];
    omp_set_num_threads(10);
#pragma omp parallel
    {   
        cout << "Thread " << omp_get_thread_num() << " inizializando" << endl;
        omp_set_lock(&lock);
        cout << "Thread " << omp_get_thread_num() << " executando" << endl;
        sleep(20);
        vet[0] = omp_get_thread_num();
        cout << "Thread " << omp_get_thread_num() << " finalizada" << endl;
        omp_unset_lock(&lock);
        
    }
    cout << vet[0] << endl;
}
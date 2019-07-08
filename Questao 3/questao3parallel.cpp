#include <omp.h>
#include <vector>
#include <chrono>
#include <iostream>
#include <unistd.h>
using namespace std;

#define tam 5

int main()
{
    int vet[tam];
    for(int i=0 ; i<tam;i++){
        vet[i]=0;
    }
    omp_set_num_threads(tam*2);
    int rand_numbers[tam*2];
    cout<< "Indexação: ";
    for(int i=0;i<tam*2;i++){
        rand_numbers[i] = rand() % tam;
        cout<< rand_numbers[i]<<" ";
    }
    cout << endl;
    int aux;
#pragma omp parallel
    {   
        cout << "Thread " << omp_get_thread_num() << " inizializando" << endl;
        cout << "Thread " << omp_get_thread_num() << " executando" << endl;
        aux = vet[rand_numbers[omp_get_thread_num()]]+1; 
        sleep(1);
        vet[rand_numbers[omp_get_thread_num()]] =aux;
        cout << "Thread " << omp_get_thread_num() << " finalizada" << endl;
        
    }
    cout<< "Vetor: ";
    for(int i=0;i<tam;i++){
        cout<< vet[i]<<" ";
    }
    cout << endl;
}
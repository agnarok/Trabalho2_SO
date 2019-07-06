#include <omp.h>
#include <vector>
#include <chrono>
#include <iostream>
using namespace std;

vector<int> merge(const vector<int> &left, const vector<int> &right)
{
    vector<int> result;
    unsigned left_it = 0, right_it = 0;

    while (left_it < left.size() && right_it < right.size())
    {
        if (left[left_it] < right[right_it])
        {
            result.push_back(left[left_it]);
            left_it++;
        }
        else
        {
            result.push_back(right[right_it]);
            right_it++;
        }
    }
    while (left_it < left.size())
    {
        result.push_back(left[left_it]);
        left_it++;
    }

    while (right_it < right.size())
    {
        result.push_back(right[right_it]);
        right_it++;
    }

    return result;
}

vector<int> mergesort(vector<int> &vec, int threads)
{
    if (vec.size() == 1)
    {
        return vec;
    }

    std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());
    if (threads > 1){
#pragma omp parallel sections
{
#pragma omp section
            {
                left = mergesort(left, threads / 2);
            }
#pragma omp section
            {
                right = mergesort(right, threads - threads / 2);
            }
        }
    }
    else{
        left = mergesort(left, 1);
        right = mergesort(right, 1);
    }

    return merge(left, right);
}

int main()
{
    int size = 100000; //Numero de elementos
    int threads = 0; //Se o numero de threads for menor que 1, sera realizado um MergeSort sem nenhum paralelismo
    vector<int> v(size);
    for (int i = 0; i < size; ++i)
    {
        v[i] = (i) % 10;
    }
    omp_set_num_threads(threads);
    auto start = chrono::steady_clock::now();
    v = mergesort(v, threads);
    auto end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
    // for (int i = 0; i < size; i++) //Imprime o vetor!
    // {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    
}
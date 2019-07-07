#include <iostream>
#include <fstream>
#include <complex>
#include <chrono>
# include <ctime>

using namespace std;

float width = 600;
float height = 600; 


int value (int x, int y)  {
    complex<float> point((float)x/width-1.5, (float)y/height-0.5);
    complex<float> z(0, 0);
    int nb_iter = 0;
    while (abs (z) < 2 && nb_iter <= 34) {
        z = z * z + point;
        nb_iter++;
    }
    if (nb_iter < 20)
       return (255*nb_iter)/20;
    else 
       return 0;
}

int main ()  {

    ofstream my_Image ("mandelbrotSERIAL.ppm");


    if (my_Image.is_open ()) {
        my_Image << "P3\n" << width << " " << height << " 255\n";
        auto start = chrono::steady_clock::now();
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++)  {
                int val = value(i, j);
                my_Image << val << ' ' << 0 << ' ' << 0 << "\n";
            }
        }
        auto end = chrono::steady_clock::now();
        cout << "Tempo de execução em ms: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
        my_Image.close();
    }
    else
      cout << "Could not open the file";
    
    return 0;
}
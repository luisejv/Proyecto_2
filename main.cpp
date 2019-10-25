#include <iostream>
#include <fstream>
#include "container.cpp"
#include <list>
#include <sstream>
#include <vector>
#include <string>

using std::ios, std::cout, std::list, std::stringstream, std::vector;

void merge(list<int> datos, int first, int middle, int size){
    int L[middle - first + 1];
    int R[size - middle];
    auto it = datos.begin();
    for (int i = 0; i < first+middle-1; i++){
        L[i] = *(it + i + 1);
    }
    for (int j = 0; j < size - middle; j++){

    }

}

void mergeSort(list<int> datos, int first, int size){
    if (size > first) {
        int middle = (first+size-1)/2;
        mergeSort(datos, first, middle);
        mergeSort(datos, middle + 1, size);
        merge(datos, first, middle, size);
    };
}

int main() {

    return 0;
}



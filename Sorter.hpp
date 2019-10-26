//
// Created by PEPE JÁUREGUI on 26/10/2019.
//

#ifndef PROYECTO_2_SORTER_HPP
#define PROYECTO_2_SORTER_HPP

#include <iostream>
#include "Merge.hpp"
#include "Quick.hpp"
#include "Heap.hpp"
#include "Shell.hpp"

template<typename T>
class Sorter : public T {
public:
    template <typename cont, typename ... Types>
    void operator()(cont *container, Types ... args){
        this -> sort(container, args...);
    }
};

#endif //PROYECTO_2_SORTER_HPP

//
// Created by PEPE JÁUREGUI on 26/10/2019.
//

#ifndef PROYECTO_2_MERGE_HPP
#define PROYECTO_2_MERGE_HPP
class Merge{
public:
    template<typename T>
    bool comparar(T& ct1, T& ct2){
        if ((*ct1)->getCountry_or_area() < (*ct2)->getCountry_or_area()){
            return true;
        } else if ((*ct1)->getCountry_or_area() == (*ct2)->getCountry_or_area()){
            if ((*ct1)->getYear() < (*ct2)->getYear()){
                return true;
            } else if ((*ct1)->getYear() == (*ct2)->getYear()){
                if ((*ct1)->getTrade_usd() < (*ct2)->getTrade_usd())
                    return true;
            }
        }
        return false;
    }
    template<typename T, typename iterador>
    void sort(T* container, iterador first, iterador end, string atr){
        if (first != end){
            auto middle = first + (end - first) / 2;
            sort(container, first, middle, atr);
            sort(container, middle+1, end, atr);
            mix(container, first, middle, end, atr);
        }
    }
    template<typename T, typename iterador>
    void sort(T* container, iterador first, iterador end, string atr, string atr2, string atr3){
        if (first != end){
            auto middle = first + (end - first) / 2;
            sort(container, first, middle, atr, atr2, atr3);
            sort(container, middle+1, end, atr, atr2, atr3);
            mix(container, first, middle, end, atr, atr2, atr3);
        }
    }
    template<typename T, typename iterador>
    void mix(T* container, iterador first, iterador mid, iterador end, string atr){
        auto izquierda = (mid - first) +1;
        auto derecha = (end - mid);
        T izq (izquierda);
        T der (derecha);
        auto inicio = first;
        auto inicioMid = mid + 1;
        auto inicioIzq = izq.begin();
        auto inicioDer = der.begin();

        for (auto &i : izq){
            i = *inicio;
            inicio++;
        }
        for (auto &i : der){
            i = *inicioMid;
            inicioMid++;
        }
        inicio = first;
        while((inicioIzq != izq.end()) && (inicioDer != der.end())){
            if ((*inicioIzq)->getTrade_usd() < (*inicioDer)->getTrade_usd()){
                *inicio = *inicioIzq;
                inicioIzq++;
            } else {
                *inicio = *inicioDer;
                inicioDer++;
            }
            inicio++;
        }
        while(inicioIzq != izq.end()){
            *inicio = *inicioIzq;
            inicioIzq++;
            inicio++;
        }
        while(inicioDer != der.end()){
            *inicio = *inicioDer;
            inicioDer++;
            inicio++;
        }
    }
    template<typename T, typename iterador>
    void mix(T* container, iterador first, iterador mid, iterador end, string atr, string atr2, string atr3){
        auto izquierda = (mid - first) +1;
        auto derecha = (end - mid);
        T izq (izquierda);
        T der (derecha);
        auto inicio = first;
        auto inicioMid = mid + 1;
        auto inicioIzq = izq.begin();
        auto inicioDer = der.begin();

        for (auto &i : izq){
            i = *inicio;
            inicio++;
        }
        for (auto &i : der){
            i = *inicioMid;
            inicioMid++;
        }
        inicio = first;
        while((inicioIzq != izq.end()) && (inicioDer != der.end())){
            if (comparar(inicioIzq, inicioDer)){
                *inicio = *inicioIzq;
                inicioIzq++;
            } else {
                *inicio = *inicioDer;
                inicioDer++;
            }
            inicio++;
        }
        while(inicioIzq != izq.end()){
            *inicio = *inicioIzq;
            inicioIzq++;
            inicio++;
        }
        while(inicioDer != der.end()){
            *inicio = *inicioDer;
            inicioDer++;
            inicio++;
        }
    }
};
#endif //PROYECTO_2_MERGE_HPP

#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <exception>
#include "Item.hpp"

class VectorException : public std::exception {
    // Excepcion especifica y exclusivamente para errores dentro del VectorTemplate.
    // Usar de la forma "throw VectorException();" cuando una precondicion no se cumpla.

    // Ejemplo:
    //     if (condicion_de_error()){
    //         throw VectorException();
    //     }
};
template <typename TipoGenerico >
class Vector {
private:
    TipoGenerico* datos;
    size_t cantidadDatos;
    size_t tamanioMaximo;

    //PRE: tamanio maximo debe ser diferente de 0.
    //POST: duplica el tamanio maximo, si tamanioMaximo es 0 solamente le suma 1.
    void duplicarTamanioMaximo();

    //PRE: tamanioMaximo debe ser el doble que cantidadDatos
    //POST: divide el tamanio maximo en 2, si tamanioMaximo es 1 solamente resta 1.
    void dividirTamanioMaximo();

    //PRE: --
    //POST: copia los datos que ya estaban escritos en el vector nuevo creado.
    void copiarDatosViejos();

public:
    // Constructor.
    Vector();

    // Pre: -
    // Post: Agrega el dato al final del vector.
    void alta(TipoGenerico dato);

    // Pre: El indice debe ser menor o igual que la cantidad de datos.
    // Post: Agrega el dato antes del dato en la posicion indicada, moviendo todos los elementos siguientes. Si el
    // indice es igual a la cantidad de datos, simplemente agrega al final.
    void alta(TipoGenerico dato, size_t indice);

    // Pre: El vector no puede estar vacio.
    // Post: Elimina el ultimo dato.
    TipoGenerico baja();

    // Pre: El vector no puede estar vacio. El indice debe ser menor que la cantidad de datos.
    // Post: Elimina el dato en la posicion indicada, moviendo todos los elementos siguientes. Si el indice es igual a
    // la cantidad de datos - 1, simplemente elimina el ultimo dato.
    TipoGenerico baja(size_t indice);

    // Pre: -
    // Post: Devuelve true si el vector esta vacio (es decir, si no hay datos).
    bool vacio();

    // Pre: -
    // Post: Devuelve la cantidad de datos del vector.
    size_t tamanio();

    // Pre: El vector no puede estar vacio. El indice debe ser menor que la cantidad de datos.
    // Post: Devuelve una referencia al dato deseado.
    TipoGenerico& operator[](size_t indice);

    // Destructor.
    ~Vector();
};
template<typename TipoGenerico>
Vector<TipoGenerico>::Vector() {
    cantidadDatos = 0;
    tamanioMaximo = 0;
    datos = nullptr;
}
template<typename TipoGenerico>
void Vector<TipoGenerico> ::duplicarTamanioMaximo() {
    if (tamanioMaximo == 0) {
        tamanioMaximo++;
    } else {
        tamanioMaximo *= 2;
    }
}
template<typename TipoGenerico>
void Vector<TipoGenerico>::dividirTamanioMaximo() {
    if (tamanioMaximo == 1) {
        tamanioMaximo--;
    }else {
        tamanioMaximo /= 2;
    }
}
template<typename TipoGenerico>
void Vector<TipoGenerico>::copiarDatosViejos() {
    TipoGenerico* nuevaLista = new TipoGenerico  [tamanioMaximo];
    for (size_t i = 0 ; i < cantidadDatos ; i++) {
        nuevaLista[i] = datos[i];
    }
    delete[] datos;
    datos = nuevaLista;
}
template<typename TipoGenerico>
void Vector<TipoGenerico>::alta(TipoGenerico dato) {
    if (cantidadDatos == tamanioMaximo) {
        duplicarTamanioMaximo();
        copiarDatosViejos();
    }
    datos[cantidadDatos] = dato;
    cantidadDatos++;
}
template<typename TipoGenerico>
void Vector<TipoGenerico>::alta(TipoGenerico dato, size_t indice) {
    if (indice > cantidadDatos) {
        throw VectorException();
    } else if (indice == cantidadDatos) {
        alta(dato);
    } else {
        for(size_t i = cantidadDatos ; i > indice ; i--) {
            datos[i] = datos[i-1];
        }
        datos[indice] = dato;
        cantidadDatos++;
    }
}
template<typename TipoGenerico>
TipoGenerico Vector<TipoGenerico>::baja() {
    if(vacio()) {
        throw VectorException();
    } else {
        TipoGenerico datoEliminado = datos[cantidadDatos - 1];
        cantidadDatos--;
        if (cantidadDatos <= (tamanioMaximo / 2)) {
            dividirTamanioMaximo();
            copiarDatosViejos();
        }
        return datoEliminado;
    }
}
template<typename TipoGenerico>
TipoGenerico Vector<TipoGenerico>::baja(size_t indice) {

    if (vacio() || indice >= cantidadDatos) {
        throw VectorException();
    } else {
        TipoGenerico  datoEliminado = datos[indice];
        for ( size_t i = indice ; i < cantidadDatos - 1; i++) {
            datos[i] = datos[i+1];
        }
        cantidadDatos--;
        if(cantidadDatos <= (tamanioMaximo/2)  ) {
            dividirTamanioMaximo();
            copiarDatosViejos();
        }
        return datoEliminado;
    }

}

template<typename TipoGenerico>
bool Vector<TipoGenerico>::vacio() {
    return cantidadDatos == 0;
}
template<typename TipoGenerico>
size_t Vector<TipoGenerico>::tamanio() {
    return cantidadDatos;
}
template<typename TipoGenerico>
TipoGenerico& Vector<TipoGenerico>::operator[](size_t indice) {
    if(indice >= cantidadDatos ) {
        throw VectorException();
    } else {
        return datos[indice];
    }
}
template<typename TipoGenerico>
Vector<TipoGenerico>::~Vector() {
    delete[] datos;
}

#endif

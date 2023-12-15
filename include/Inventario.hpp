#ifndef _INVENTARIO_HPP
#define _INVENTARIO_HPP
#include "Item.hpp"
#include "Vector.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

const std::string ruta = "inventario.csv";
const size_t LIMITE_ITEM = 15;
const char DELIMITADOR = ',';
class Inventario {
private:
    Vector<Item*> inventario;

    //PRE:--
    //POST: devuelve verdadero si el tipo de item es correcto.
    bool esTipoCorrecto(std::string tipo);

    //PRE:--
    //POST: devuelve verdadero si el nombre del item esta utitlizado
    bool nombreExistente(std::string nombre);

public:
    //Constructor
    Inventario();

    //PRE:--
    //POST: agrega el item recogido por el jugador al inventario
    void alta(std::string nombre,std::string tipo);

    //PRE:--
    //POST: elimina un item del inventario
    void baja(std::string itemAEliminar);

    //PRE:--
    //POST: Imprime por pantalla los items en el inventario.
    void consultar();

    //PRE:--
    //POST: carga la informacion del archivo .csv en el inventario.
    void cargar();

    //PRE:--
    //POST: guarda en el archivo .csv los datos del inventario.
    void guardar();

    //Destructor
    ~Inventario();
};
#endif


#ifndef AYP2_PLANTILLA_TP1_2C2023_MENU_HPP
#define AYP2_PLANTILLA_TP1_2C2023_MENU_HPP

#include "Inventario.hpp"
const int ALTA = 1;
const int BAJA = 2;
const int GUARDAR = 3;
const int CONSULTA = 4;
const int SALIR = 5;

class Menu {
private:
    Inventario inventario;
    //PRE:--
    //POST: verifica que el comando pertenezca al conjunto {ALTA,BAJA,CONSULTA,CARGAR,GUARDAR,SALIR}
    static bool esComandoValido(int comando);

    //PRE:--
    //POST:devuelve verdadero si el nombre ya esta utilizado
    bool nombreExistente(std::string nombre);

    //PRE:
    //POST: da de alta el arma en el inventario
    void menuAlta();
    //PRE:
    //POST: da de baja el arma del inventario
    void menuBaja();

public:
    Menu();
    //PRE:--
    //POST: se imprime por pantalla la ejecucion de los diferentes metodos del inventario.
    void opcionesInventario(int comando);

    //PRE:--
    //POST:imprime por pantalla un menu con los comandos del inventario
    static void opcionesMenu();

};

#endif

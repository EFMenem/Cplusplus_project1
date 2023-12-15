
#ifndef AYP2_PLANTILLA_TP1_2C2023_MENU_HPP
#define AYP2_PLANTILLA_TP1_2C2023_MENU_HPP

#include "Inventario.hpp"

class Menu {
private:
    //PRE:--
    //POST: verifica que el comando pertenezca al conjunto {ALTA,BAJA,CONSULTA,CARGAR,GUARDAR,SALIR}
    static bool esComandoValido(std::string comando);

    //PRE:--
    //POST:devuelve verdadero si el nombre ya esta utilizado
    bool nombreExistente(std::string nombre);

public:
    //PRE:--
    //POST: se imprime por pantalla la ejecucion de los diferentes metodos del inventario.
    static void opcionesInventario(std::string comando);

    //PRE:--
    //POST:imprime por pantalla un menu con los comandos del inventario
    static void opcionesMenu();

};

#endif

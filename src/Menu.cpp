#include "../include/Menu.hpp"


void Menu::opcionesInventario(std::string comando) {
    Inventario inventario;
    std::string item,nombre,tipo;
    inventario.cargar();
    while(comando != "SALIR") {
        if (!esComandoValido(comando)) {
            std::cout << "Ingreso un comando erroneo por favor ingrese de nuevo:" << std::endl;
        } else if (comando == "ALTA") {
            std::cout << "Ingrese un nombre : ";
            getline(std::cin, nombre);
            std::cout << "Ingrese un tipo (PUZZLE, MUNICION o CURATIVO) : ";
            getline(std::cin , tipo);
            inventario.alta(nombre,tipo);
        } else if (comando == "CONSULTA") {
            inventario.consultar();
        } else if (comando == "BAJA") {
            std::cout << "Indique el ítem a eliminar : ";
            getline(std::cin, item);
            inventario.baja(item);
        } else if (comando == "GUARDAR") {
            inventario.guardar();
        }
        opcionesMenu();
        getline(std::cin ,comando);
    }
    inventario.guardar();
    std::cout << "Cerrando el sistema" << std::endl;
}


bool Menu::esComandoValido(std::string comando) {
    return (comando == "ALTA") || (comando == "CONSULTA") || (comando == "GUARDAR") || (comando == "SALIR")  || (comando == "BAJA");
}

void Menu::opcionesMenu() {
    std::string comando;
    std::cout << "\nINVENTARIO\n--------------------------------------------------------------------\n";
    std::cout << "Opcion:\n1)'ALTA' carga de a un item en el inventario\n2)'BAJA' da de baja de a un item del inventario\n";
    std::cout << "3)'GUARDAR' guarda los items en un archivo.csv\n";
    std::cout << "4)'CONSULTA' consulta por pantalla los items del inventario\n5)'SALIR' para salir del inventario\n";
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Accion sobre el inventario : ";
}

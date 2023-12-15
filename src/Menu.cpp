#include "../include/Menu.hpp"

Menu::Menu() {}

void Menu::menuAlta() {
    std::string nombre,tipo;
    std::cout << "Ingrese un nombre : ";
    std::cin >> nombre;
    std::cout << "Ingrese un tipo (PUZZLE, MUNICION o CURATIVO) : ";
    std::cin >> tipo;
    inventario.alta(nombre, tipo);
    std::cout << "Se dio de alta el item con el nombre " << nombre << " y el tipo " << tipo << std::endl;
}

void Menu::menuBaja() {
    std::string item;
    std::cout << "Indique el ítem a eliminar : ";
    getline(std::cin, item);
    inventario.baja(item);
}

void Menu::opcionesInventario(int comando) {
    inventario.cargar();

    while (comando != SALIR) {
        switch (comando) {
            case ALTA:
                menuAlta();
                break;
            case BAJA:
                menuBaja();
                break;
            case CONSULTA:
                inventario.consultar();
                break;
            case GUARDAR:
                inventario.guardar();
                break;
            default:
                std::cout << "Por favor ingrese un comando valido\n";
                break;
        }

        opcionesMenu();
        std::cin >> comando;
    }
    inventario.guardar();
    std::cout << "Cerrando el sistema" << std::endl;
}


bool Menu::esComandoValido(int comando) {
    return (comando == ALTA) || (comando == CONSULTA) || (comando == GUARDAR)
    || (comando == SALIR)  || (comando == BAJA);
}

void Menu::opcionesMenu() {
    std::string comando;
    std::cout << "\nINVENTARIO\n--------------------------------------------------------------------\n";
    std::cout << "Opcion:\n1)ALTA: carga de a un item en el inventario\n2)BAJA: da de baja de a un item del inventario\n";
    std::cout << "3)GUARDAR: guarda los items en un archivo.csv\n";
    std::cout << "4)CONSULTA: consulta por pantalla los items del inventario\n5)SALIR: para salir del inventario\n";
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Accion sobre el inventario : ";
}

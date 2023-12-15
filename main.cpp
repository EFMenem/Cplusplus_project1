#include "include/Menu.hpp"
using namespace std;
int main() {
    int comando;
    Menu menu;
    menu.opcionesMenu();
    std::cin >> comando;
    menu.opcionesInventario(comando);
    return 0;
}
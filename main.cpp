#include "include/Menu.hpp"
using namespace std;
int main() {
    string comando;
    Menu::opcionesMenu();
    getline(cin,comando);
    Menu::opcionesInventario(comando);
    return 0;
}
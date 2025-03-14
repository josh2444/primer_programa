#include <iostream>
#include <windows.h>
using namespace std;
void mostrarMemoria() {
MEMORYSTATUSEX estado;
estado.dwLength = sizeof(estado);
GlobalMemoryStatusEx(&estado);
cout << "Memoria usada: " << (estado.ullTotalPhys - estado.ullAvailPhys) / (1024 * 1024) << " MB | ";
cout << "Memoria disponible: " << estado.ullAvailPhys / (1024 * 1024) << " MB" << endl;
}
int main() {
cout << "Antes de la asignación de memoria:" << endl;
mostrarMemoria();
int* arreglo = new int[10000000];
for (int i = 0; i < 10000000; i++) {
arreglo[i] = i;

}
cout << "\nDespués de la asignación de memoria:" << endl;
mostrarMemoria();
delete[] arreglo;
cout << "\nDespués de liberar memoria:" << endl;
mostrarMemoria();
return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Clase Proveedor
class Proveedor {
public:
    string nombre;

    Proveedor(string n) : nombre(n) {}
};

// Clase Equipo Electrónico
class EquipoElectronico {
public:
    string tipo;
    string marca;
    string estado;
    double costoUnitario;
    int añosGarantia;
    Proveedor proveedor;

    EquipoElectronico(string t, string m, string e, double c, int a, Proveedor p)
        : tipo(t), marca(m), estado(e), costoUnitario(c), añosGarantia(a), proveedor(p) {}
};

// Clase Mobiliario
class Mobiliario {
public:
    string tipo;
    string localizacion;
    double costoUnitario;
    int tiempoExplotacion;

    Mobiliario(string t, string l, double c, int te)
        : tipo(t), localizacion(l), costoUnitario(c), tiempoExplotacion(te) {}
};

// Función para mostrar menú
void mostrarMenu() {
    cout << "\n--- Sistema de Gestión de Equipos Electrónicos y Mobiliario ---\n";
    cout << "1. Agregar equipo electrónico\n";
    cout << "2. Agregar mobiliario\n";
    cout << "3. Mostrar equipos electrónicos por tipo y marca\n";
    cout << "4. Mostrar mobiliario\n";
    cout << "5. Calcular costos\n";
    cout << "6. Salir\n";
    cout << "Seleccione una opción: ";
}

// Función para calcular el costo total de equipos
double calcularCostoEquipos(const vector<EquipoElectronico>& equipos) {
    double total = 0;
    for (const auto& equipo : equipos) {
        total += equipo.costoUnitario * equipo.añosGarantia;
    }
    return total;
}

// Función para calcular el costo total de mobiliario
double calcularCostoMobiliario(const vector<Mobiliario>& muebles) {
    double total = 0;
    for (const auto& mueble : muebles) {
        double plus = 0;
        if (mueble.localizacion == "aula") plus = 250;
        else if (mueble.localizacion == "laboratorio") plus = 320;
        else if (mueble.localizacion == "departamento") plus = 450;
        else if (mueble.localizacion == "oficina") plus = 500;
        total += (mueble.costoUnitario * mueble.tiempoExplotacion) + plus;
    }
    return total;
}

int main() {
    vector<EquipoElectronico> equipos;
    vector<Mobiliario> muebles;

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1: {
            // Agregar equipo electrónico
            string tipo, marca, estado, proveedor;
            double costo;
            int garantia;
            cout << "Ingrese tipo de equipo (TV, PC, etc.): ";
            cin >> tipo;
            cout << "Ingrese marca: ";
            cin >> marca;
            cout << "Ingrese estado (Funcionando, Defectuoso, Roto): ";
            cin >> estado;
            cout << "Ingrese costo unitario: ";
            cin >> costo;
            cout << "Ingrese años de garantía: ";
            cin >> garantia;
            cout << "Ingrese nombre del proveedor: ";
            cin >> proveedor;

            equipos.emplace_back(tipo, marca, estado, costo, garantia, Proveedor(proveedor));
            cout << "Equipo agregado correctamente.\n";
            break;
        }
        case 2: {
            // Agregar mobiliario
            string tipo, localizacion;
            double costo;
            int tiempo;
            cout << "Ingrese tipo de mobiliario (silla, mesa, etc.): ";
            cin >> tipo;
            cout << "Ingrese localización (aula, laboratorio, etc.): ";
            cin >> localizacion;
            cout << "Ingrese costo unitario: ";
            cin >> costo;
            cout << "Ingrese tiempo estimado de explotación: ";
            cin >> tiempo;

            muebles.emplace_back(tipo, localizacion, costo, tiempo);
            cout << "Mobiliario agregado correctamente.\n";
            break;
        }
        case 3: {
            // Mostrar equipos electrónicos
            cout << "\n--- Equipos Electrónicos ---\n";
            for (const auto& equipo : equipos) {
                cout << "Tipo: " << equipo.tipo
                     << ", Marca: " << equipo.marca
                     << ", Estado: " << equipo.estado
                     << ", Costo Unitario: " << equipo.costoUnitario
                     << ", Años de Garantía: " << equipo.añosGarantia
                     << ", Proveedor: " << equipo.proveedor.nombre << endl;
            }
            break;
        }
        case 4: {
            // Mostrar mobiliario
            cout << "\n--- Mobiliario ---\n";
            for (const auto& mueble : muebles) {
                cout << "Tipo: " << mueble.tipo
                     << ", Localización: " << mueble.localizacion
                     << ", Costo Unitario: " << mueble.costoUnitario
                     << ", Tiempo Estimado de Explotación: " << mueble.tiempoExplotacion << endl;
            }
            break;
        }
        case 5: {
            // Calcular costos
            double costoEquipos = calcularCostoEquipos(equipos);
            double costoMuebles = calcularCostoMobiliario(muebles);
            cout << "\n--- Costos Totales ---\n";
            cout << "Costo total de equipos electrónicos: " << costoEquipos << endl;
            cout << "Costo total de mobiliario: " << costoMuebles << endl;
            break;
        }
        case 6:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while (opcion != 6);

    return 0;
}
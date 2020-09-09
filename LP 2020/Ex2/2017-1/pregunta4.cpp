#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
using namespace std;

class Infraccion {
public:
    Infraccion(int id, string descripcion, string gravedad, double multa): id(id), descripcion(descripcion), gravedad(gravedad), multa(multa) {
    }

    friend bool operator< (const Infraccion& lhs, const Infraccion& rhs);
    friend ostream& operator<<(ostream& os, const Infraccion& vehiculo);

    int getId() const {
        return id;
    }

    double getMulta() const {
        return multa;
    }

private:
    int id;
    string descripcion;
    string gravedad;
    double multa;
};

bool operator< (const Infraccion & lhs, const Infraccion & rhs) {
    return lhs.id < rhs.id;
}

ostream& operator<<(ostream& os, const Infraccion& infraccion) {
    os << infraccion.id << "       " << infraccion.descripcion << "         " << infraccion.gravedad << "          " << infraccion.multa << "\n--------------------------\n";
    return os;
}

template<typename T>
class ListaDoble {
public:
    // 0: inicio a fin
    // 1: fin a inicio
    void imprimir(int sentido) {
        if (sentido == 0) {
            for (auto& item : lista) {
                cout << item << " ";
            }
        }
        else {
            for (auto it = lista.rbegin(); it != lista.rend(); ++it) {
                cout << *it << " ";
            }
        }
        cout << "\n";
    }

    void insertarOrdenado(T item) {
        lista.insert(std::lower_bound(lista.begin(), lista.end(), item), item);
    }

    // NO HACER ESTO EN GENERAL!!!
    list<T>& getLista() {
        return lista;
    }
    
private:
    list<T> lista;
};

class ListaInfracciones {
public:
    double buscarInfraccion(int id) {
        for (const auto& infraccion : infracciones.getLista()) {
            if (infraccion.getId() == id) {
                return infraccion.getMulta();
            }
        }
        return -1.0;
    }

    void agregarInfraccion(const Infraccion& infraccion) {
        infracciones.insertarOrdenado(infraccion);
    }

    void imprimir(int sentido) {
        infracciones.imprimir(sentido);
    }

    // NO HACER ESTO EN GENERAL!!!
    list<Infraccion>& getInfracciones() {
        return infracciones.getLista();
    }

private:
    ListaDoble<Infraccion> infracciones;
};

class Vehiculo {
public:
    Vehiculo() {}

    Vehiculo(string placa): placa(placa) {
    }
    friend bool operator< (const Vehiculo& lhs, const Vehiculo& rhs);
    friend ostream& operator<<(ostream& os, const Vehiculo& vehiculo);
    void agregarInfraccion(int idInfraccion) {
        infracciones.push_back(idInfraccion);
    }

    string getPlaca() {
        return placa;
    }

    list<int> getInfracciones() {
        return infracciones;
    }
private:
    string placa;
    list<int> infracciones; // códigos de las infracciones cometidas (ids)
};

bool operator< (const Vehiculo & lhs, const Vehiculo & rhs) {
    return lhs.placa < rhs.placa;
}

ostream& operator<<(ostream& os, const Vehiculo& vehiculo) {
    os << "Placa: " << vehiculo.placa << "\n";
    if (!vehiculo.infracciones.empty()) {
        os << "Infracciones: ";
        for (auto idInfraccion: vehiculo.infracciones) {
            os << " " << idInfraccion;
        }
    }
    else {
        os << "El vehículo no tiene infracciones.";
    }
    os << "\n";
    return os;
}

class NodoV {
private:
    Vehiculo vehiculo;
    NodoV* prev;
    NodoV* next;
};

class ListaVehiculos {
public:

    void insertarOrdenado(const Vehiculo& vehiculo) {
        vehiculos.insert(std::lower_bound(vehiculos.begin(), vehiculos.end(), vehiculo), vehiculo);
    }

    Vehiculo* buscarVehiculo(string placa) {
        for (auto& vehiculo: vehiculos) {
            if (vehiculo.getPlaca() == placa) {
                return &vehiculo;
            }
        }
        return nullptr;
        // return Vehiculo();
    }

    void imprimir(ostream& file) {
        for (Vehiculo& vehiculo : vehiculos) {
            file << vehiculo << "\n";
        }
    }

    const list<Vehiculo>& getVehiculos() {
        return vehiculos;
    }

private:
    // string placa;
    // list<int> infracciones; // códigos de las infracciones cometidas
    list<Vehiculo> vehiculos;
    // NodoV* inicio;
    // NodoV* fin;
};

class Conductor {
public:
    Conductor(int dni, string nombre, int telefono): dni(dni), nombre(nombre), telefono(telefono) {
    }

    Conductor(const Conductor& other) {
        this->dni = other.dni;
        this->nombre = other.nombre;
        this->telefono = other.telefono;
        this->vehiculos = other.vehiculos;
    }

    int getDni() const {
        return dni;
    }

    friend bool operator< (const Conductor& lhs, const Conductor& rhs);
    friend ostream& operator<<(ostream& os, Conductor& conductor);

    void agregarVehiculo(string placa) {
        Vehiculo vehiculo(placa);
        vehiculos.insertarOrdenado(vehiculo);
    }

    void agregarInfraccion(string placa, int idInfraccion) {
        Vehiculo* vehiculo = vehiculos.buscarVehiculo(placa);
        if (vehiculo == nullptr) {
            // cout << "El vehículo de placa " << placa << " no fue encontrado.\n";
            return;
        }
        // cout << vehiculo << "\n";
        vehiculo->agregarInfraccion(idInfraccion);
    }

    const list<Vehiculo>& getVehiculos() {
        return vehiculos.getVehiculos();
    }
    
    void setMontoMultas(double monto) {
        // cout << "seteando la multa a " << monto << "\n";
        montoMultas = monto;
    }

private:
    int dni = 0;
    string nombre;
    int telefono = 0;
    ListaVehiculos vehiculos;
    double montoMultas = 0.0;
};

bool operator< (const Conductor & lhs, const Conductor & rhs) {
    return lhs.dni < rhs.dni;
}

ostream& operator<<(ostream& os, Conductor& conductor) {
    os << conductor.dni << "        " << conductor.nombre << "        " << conductor.telefono << "                   " << conductor.montoMultas << "\n";
    os << "Vehículos de este conductor:\n";
    conductor.vehiculos.imprimir(os);
    os << "---------------------\n";
    return os;
}

class ListaConductores {
public:
    void insertarOrdenado(const Conductor& conductor) {
        conductores.insert(std::lower_bound(conductores.begin(), conductores.end(), conductor), conductor);
    }

    void imprimir(ostream& file) {
        for (Conductor& conductor : conductores) {
            file << conductor << "\n";
        }
    }

    Conductor& buscarConductor(int dni) {
        for (auto& cond : conductores) {
            if (cond.getDni() == dni) {
                return cond;
            }
        }
        // return Conductor();
    }

    // NO HACER ESTO EN GENERAL!!!
    list<Conductor>& getConductores() {
        return conductores;
    }

private:
    list<Conductor> conductores;
};

class NodoC {
    Conductor conductor;
    NodoC* prev;
    NodoC* next;
};

class EntidadReguladora {
public:
    EntidadReguladora() {
        leerConductores();
        leerInfracciones();
        calcularMultas();
    }

    void leerConductores() {
        ifstream conductoresFile("Conductores.csv");
        string line;
        while (getline(conductoresFile, line)) {
            // 63736112,ZAMORA/ZAVALETA/RONAL MANUEL,989320773,K0D-676,T9A-930
            istringstream iss(line);
            string token;
            getline(iss, token, ',');
            int dni = stoi(token);
            getline(iss, token, ',');
            string nombre = token;
            getline(iss, token, ',');
            int telefono = stoi(token);

            Conductor conductor(dni, nombre, telefono);
            string placa;
            while (getline(iss, placa, ',')) {
                conductor.agregarVehiculo(placa);
            }
            conductores.insertarOrdenado(conductor);
        }

        // ofstream reporte("pregunta1.txt");
        // reporte << "Conductores\n";
        // reporte << "DNI                      Nombre            Telefono\n";
        // conductores.imprimir(reporte);

        // Imprimir todos los conductores de nuevo, esta vez con sus infracciones
        ifstream faltasFile("Registro_de_Faltas.csv");
        while (getline(faltasFile, line)) {
            istringstream iss(line);
            string token;
            getline(iss, token, ',');
            int dni = stoi(token);
            getline(iss, token, ',');
            string placa = token;
            getline(iss, token, ',');
            int idInfraccion = stoi(token);
            // Buscar al conductor
            Conductor& conductor = conductores.buscarConductor(dni);
            conductor.agregarInfraccion(placa, idInfraccion);
        }
    }

    void leerInfracciones() {
        ifstream infraccionesFile("Infracciones.csv");
        string line;
        while (getline(infraccionesFile, line)) {
            istringstream iss(line);
            string token;
            getline(iss, token, ',');
            int id = stoi(token);
            getline(iss, token, ',');
            string descripcion = token;
            getline(iss, token, ',');
            string gravedad = token;
            getline(iss, token, ',');
            double multa = stoi(token);
            Infraccion infraccion(id, descripcion, gravedad, multa);
            infracciones.agregarInfraccion(infraccion);
        }
    }

    void calcularMultas() {
        // necesitamos:
        // - lista de infracciones
        // - lista de conductores
        // para cada conductor en la lista de conductores
        //  para cada vehiculo en la lista de vehiculos
        //   obtenemos los ids de infracciones asociados a cada vehiculo
        //   para cada id de infracción:
        //    lo buscamos en ListaInfracciones
        //    si lo encontramos, obtenemos su monto
        //    acumular el monto
        // retornar el monto acumulado
        ofstream reporte("pregunta4.txt");
        for (auto& conductor : conductores.getConductores()) {
            double montoTotal = 0;
            for (auto vehiculo : conductor.getVehiculos()) {
                list<int> idsInfracciones = vehiculo.getInfracciones();
                for (auto id : idsInfracciones) {
                    double multa = infracciones.buscarInfraccion(id);
                    if (multa != -1.0) {
                        montoTotal += multa;
                    }
                }
            }
            conductor.setMontoMultas(montoTotal);
        }
    }

    void imprimirReporte() {
        ofstream reporte("pregunta4.txt");
        conductores.imprimir(reporte);
    }

private:
    ListaConductores conductores;
    ListaInfracciones infracciones;
};

int main() {
    EntidadReguladora entidad;
    entidad.imprimirReporte();
}
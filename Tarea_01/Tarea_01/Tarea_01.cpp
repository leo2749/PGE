#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Pasajero {
public:
    Pasajero();
    ~Pasajero();
    string get_nombre(), get_apellido(), get_mail(), get_direccion();
    void set_nombre(string nom), set_apellido(string ap), set_mail(string em), set_direccion(string dire);
    int get_DNI(), get_telefono(), get_numero_asiento();
    void set_DNI(int dni), set_telefono(int tel), set_numero_asiento(int na);
    char get_sexo();
    void set_sexo(char sex);

private:
    int DNI, telefono, numero_asiento;
    char sexo;
    string nombre, apellido, mail, direccion;
};

Pasajero::Pasajero() {}
Pasajero::~Pasajero() {}

string Pasajero::get_nombre() { return nombre; }
void Pasajero::set_nombre(string nom) { nombre = nom; }

string Pasajero::get_apellido() { return apellido; }
void Pasajero::set_apellido(string ap) { apellido = ap; }

char Pasajero::get_sexo() { return sexo; }
void Pasajero::set_sexo(char sex) { sexo = sex; }

int Pasajero::get_DNI() { return DNI; }
void Pasajero::set_DNI(int dni) { DNI = dni; }

int Pasajero::get_telefono() { return telefono; }
void Pasajero::set_telefono(int tel) { telefono = tel; }

int Pasajero::get_numero_asiento() { return numero_asiento; }
void Pasajero::set_numero_asiento(int na) { numero_asiento = na; }

string Pasajero::get_direccion() { return direccion; }
void Pasajero::set_direccion(string dire) { direccion = dire; }

string Pasajero::get_mail() { return mail; }
void Pasajero::set_mail(string em) { mail = em; }

class Reserva {
public:
    Reserva();
    ~Reserva();
    void set_cant_pasajeros(int c);
    int get_cant_pasajeros();
    string get_numero_vuelo();
    int get_nro_reserva();
    bool get_estado_pago();
    void set_numero_vuelo(string n);
    void Cargar_pasajero(Pasajero p);

private:
    int cant_pasajeros;
    vector<Pasajero> pasajeros;
    int Nro_reserva = 1111 + std::rand() % (9999 - 1111 + 1);
    bool Estado_Pago = false;
    string nro_vuelo;
};

Reserva::Reserva() {}
Reserva::~Reserva() {}

void Reserva::set_cant_pasajeros(int c) { cant_pasajeros = c; }
int Reserva::get_cant_pasajeros() { return cant_pasajeros; }

void Reserva::Cargar_pasajero(Pasajero p) { pasajeros.push_back(p); }

string Reserva::get_numero_vuelo() { return nro_vuelo; }
void Reserva::set_numero_vuelo(string n) { nro_vuelo = n; }

int Reserva::get_nro_reserva() { return Nro_reserva; }
bool Reserva::get_estado_pago() { return Estado_Pago; }

class Vuelo {
public:
    Vuelo();
    ~Vuelo();
    string get_numero_vuelo();
    string get_origen();
    string get_destino();
    string get_fecha();
    void set_numero_vuelo(string n);
    void set_origen(string o);
    void set_destino(string d);
    void set_fecha(string f);
    void set_time(int t);
    int get_time();
    int asientos_disponibles();
    void Cargar_Reservar();
    void Ver_Reservas();
    void Detalle_Vuelo();
    void Generar_Detalles_Vuelo(string origen, string destino);

private:
    string numero_vuelo;
    string origen;
    string destino;
    string fecha;
    int time;
    Pasajero Asientos[300];
    vector<Reserva> Reservas;
    int ocupados = 0;
};

Vuelo::Vuelo() {}
Vuelo::~Vuelo() {}

string Vuelo::get_numero_vuelo() { return numero_vuelo; }
string Vuelo::get_origen() { return origen; }
string Vuelo::get_destino() { return destino; }
string Vuelo::get_fecha() { return fecha; }

void Vuelo::set_numero_vuelo(string n) { numero_vuelo = n; }
void Vuelo::set_origen(string o) { origen = o; }
void Vuelo::set_destino(string d) { destino = d; }
void Vuelo::set_fecha(string f) { fecha = f; }
void Vuelo::set_time(int t) { time = t; }

int Vuelo::get_time() { return time; }
int Vuelo::asientos_disponibles() { return 300 - ocupados; }

void Vuelo::Cargar_Reservar() {
    Reserva r;
    int o;
    int cant;
    string n;
    char s;
    cout << "Cuantos Pasajeros son: ";
    cin >> cant;
    r.set_cant_pasajeros(cant);
    for (int i = 0; i < cant; i++) {
        cout << "Pasajero " << i + 1 << "\n";
        cout << "-------------------------\n";
        Pasajero p;
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, n);
        p.set_nombre(n);
        cout << "Apellido: ";
        getline(cin, n);
        p.set_apellido(n);
        cout << "Sexo(M/F): ";
        cin >> s;
        p.set_sexo(s);
        cout << "DNI: ";
        cin >> o;
        p.set_DNI(o);
        cout << "Direccion de la vivienda: ";
        cin.ignore();
        getline(cin, n);
        p.set_direccion(n);
        cout << "Email: ";
        getline(cin, n);
        p.set_mail(n);
        cout << "Telefono: ";
        cin >> o;
        p.set_telefono(o);
        p.set_numero_asiento(300 - ocupados);
        ocupados += 1;
        r.Cargar_pasajero(p);
        cout << "Pasajero Cargado correctamente.\n";
    }
    r.set_numero_vuelo(numero_vuelo);
    Reservas.push_back(r);
    cout << "Reserva cargada correctamente.\n";
}

void Vuelo::Detalle_Vuelo() {
    cout << "Numero Vuelo: " << numero_vuelo << endl;
    cout << "Origen del vuelo: " << origen << endl;
    cout << "Destino del vuelo: " << destino << endl;
    cout << "Tiempo de salida: " << time << endl;
    cout << "Fecha del vuelo: " << fecha << endl;
    cout << "Asientos disponibles: " << asientos_disponibles() << endl;
}

void Vuelo::Ver_Reservas() {
    for (int i = 0; i < Reservas.size(); i++) {
        cout << "---------------------------\n";
        cout << "Numero de reserva: " << Reservas[i].get_nro_reserva() << endl;
        cout << "Cantidad de pasajeros: " << Reservas[i].get_cant_pasajeros() << "\n";
        cout << "Estado de la reserva: ";
        if (Reservas[i].get_estado_pago()) {
            cout << "Pagado.\n";
        }
        else {
            cout << "Pago pendiente.\n";
        }
    }
}

void Vuelo::Generar_Detalles_Vuelo(string origen, string destino) {
    this->origen = origen;
    this->destino = destino;

    //genero numero de vuelo y tiempo(formato 24h) aleatorio
    numero_vuelo = "V" + to_string(1000 + rand() % 9000);
    time = 1000 + rand() % 900;

    // Generar fecha aleatoria (formato d/m/y)
    int dia = 1 + rand() % 28;
    int mes = 1 + rand() % 12;
    int anio = 2024;
    fecha = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);

    cout << "Detalles del vuelo: \n";
    cout << "Numero Vuelo: " << numero_vuelo << endl;
    cout << "Origen: " << origen << endl;
    cout << "Destino: " << destino << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Tiempo de salida: " << time << " hrs" << endl;
}

void mostrar_menu() {
    cout << "Bienvenido al sistema de reservas de vuelo\n";
    cout << "1. Ingresar Origen y Destino del Vuelo\n";
    cout << "2. Cargar Reserva\n";
    cout << "3. Ver Reservas\n";
    cout << "4. Detalle del Vuelo\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    std::srand(std::time(nullptr));
    Vuelo v;

    bool salir = false;
    int opcion;
    while (!salir) {
        mostrar_menu();
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string origen, destino;
            cout << "Ingrese el Origen del Vuelo: ";
            cin >> origen;
            cout << "Ingrese el Destino del Vuelo: ";
            cin >> destino;
            v.Generar_Detalles_Vuelo(origen, destino);
            break;
        }
        case 2:
            v.Cargar_Reservar();
            break;
        case 3:
            v.Ver_Reservas();
            break;
        case 4:
            v.Detalle_Vuelo();
            break;
        case 5:
            salir = true;
            break;
        default:
            cout << "Opcion no valida, por favor intente nuevamente.\n";
        }
        cout << endl;
    }

    cout << "Gracias por usar el sistema de reservas de vuelo.\n";
    return 0;
}

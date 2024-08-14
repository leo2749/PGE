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
    void Mostrar_pasajeros();

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

void Reserva::Mostrar_pasajeros() {
    for (int i = 0; i < pasajeros.size(); i++) {
        cout << "Pasajero " << i + 1 << ":\n";
        cout << "Nombre: " << pasajeros[i].get_nombre() << " " << pasajeros[i].get_apellido() << endl;
        cout << "DNI: " << pasajeros[i].get_DNI() << endl;
        cout << "Sexo: " << pasajeros[i].get_sexo() << endl;
        cout << "Email: " << pasajeros[i].get_mail() << endl;
        cout << "Telefono: " << pasajeros[i].get_telefono() << endl;
        cout << "Direccion: " << pasajeros[i].get_direccion() << endl;
        cout << "Numero de asiento: " << pasajeros[i].get_numero_asiento() << endl;
        cout << "---------------------------\n";
    }
}

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
    void Cargar_Reservar(Reserva r, void(*callback)(Reserva));
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

    friend class SistemaReservas; // Para que SistemaReservas pueda acceder a los miembros privados
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

void Vuelo::Cargar_Reservar(Reserva u, void(*callback)(Reserva)) {
    Reserva r;
    int o;
    int cant;
    string n;
    char s;
    cout << "Cuantos Pasajeros son: ";
    cin >> cant;
    if (cant > asientos_disponibles()) {
        cout << "No hay suficientes asientos disponibles en este vuelo.\n";
        return;
    }
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
        p.set_numero_asiento(ocupados + 1);
        ocupados += 1;
        r.Cargar_pasajero(p);
        cout << "Pasajero Cargado correctamente.\n";
    }
    r.set_numero_vuelo(numero_vuelo);
    Reservas.push_back(r);
    callback(r);
}

void Vuelo::Detalle_Vuelo() {
    cout << "Numero Vuelo: " << numero_vuelo << endl;
    cout << "Origen del vuelo: " << origen << endl;
    cout << "Destino del vuelo: " << destino << endl;
    cout << "Tiempo de salida: " << time << endl;
    cout << "Fecha del vuelo: " << fecha << endl;
    cout << "Asientos disponibles: " << asientos_disponibles() << endl;

    Ver_Reservas(); // Llama a la funcion para mostrar las reservas y los detalles de los pasajeros
}

void Vuelo::Ver_Reservas() {
    if (Reservas.empty()) {
        cout << "No hay reservas para este vuelo.\n";
        return;
    }

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
        cout << "Detalles de los pasajeros:\n";
        Reservas[i].Mostrar_pasajeros();
        cout << "---------------------------\n";
    }
}

void Vuelo::Generar_Detalles_Vuelo(string origen, string destino) {
    this->origen = origen;
    this->destino = destino;

    // Generar numero de vuelo aleatorio
    numero_vuelo = "V" + to_string(1000 + rand() % 9000);

    // Generar tiempo de salida aleatorio (formato 24h)
    time = 1000 + rand() % 900;

    // Generar fecha aleatoria (formato dd/mm/yyyy)
    int day = 1 + rand() % 28;
    int month = 1 + rand() % 12;
    int year = 2024;
    fecha = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

    cout << "Detalles del vuelo generados automaticamente:\n";
    cout << "Numero Vuelo: " << numero_vuelo << endl;
    cout << "Origen: " << origen << endl;
    cout << "Destino: " << destino << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Tiempo de salida: " << time << " hrs" << endl;
}

void Detalle(Reserva r){
    cout << "Reserva creada con exito :)\n";
    cout << "-----------------------------------------------\n";
    cout << "Detalle de la reseva.\n";
    cout << "Numero de reserva: " << r.get_nro_reserva() << endl; 
    cout << "Numero Vuelo: " << r.get_numero_vuelo() << endl;
    cout << "Cantidad de pasajeros: " << r.get_cant_pasajeros() << endl;
    cout << "Estado del pago: " << r.get_estado_pago() << endl;
    cout << "------------------------------------------------\n";
    
}

class SistemaReservas {
public:
    void agregar_vuelo(Vuelo v);
    void mostrar_vuelos();
    void seleccionar_vuelo_para_reserva();
    void crear_nuevo_vuelo();
    void ver_detalles_vuelo();
    void ver_reservas();
    void cargar_reserva();
    vector <Vuelo> vuelos;
};

void SistemaReservas::agregar_vuelo(Vuelo v) {
    vuelos.push_back(v);
    cout << "Vuelo agregado al sistema.\n";
}

void SistemaReservas::mostrar_vuelos() {
    for (int i = 0; i < vuelos.size(); i++) {
        cout << i + 1 << ". Vuelo " << vuelos[i].get_numero_vuelo()
            << " (" << vuelos[i].get_origen() << " -> " << vuelos[i].get_destino() << ")\n";
    }
}

void SistemaReservas::seleccionar_vuelo_para_reserva() {
    if (vuelos.empty()) {
        cout << "No hay vuelos disponibles. Por favor, cree un nuevo vuelo.\n";
        crear_nuevo_vuelo();
        return;
    }

    mostrar_vuelos();

    int opcion;
    Reserva r;
    cout << "Seleccione un vuelo para hacer la reserva: ";
    cin >> opcion;

    if (opcion < 1 || opcion > vuelos.size()) {
        cout << "Opcion no valida. Por favor intente nuevamente.\n";
        return;
    }

    Vuelo& vuelo_seleccionado = vuelos[opcion - 1];

    if (vuelo_seleccionado.asientos_disponibles() > 0) {
        vuelo_seleccionado.Cargar_Reservar(r,Detalle);
    }
    else {
        cout << "El vuelo seleccionado está lleno. \n";
        cout << "1. Seleccionar otro vuelo\n2. Crear nuevo vuelo\nOpcion: ";
        cin >> opcion;

        if (opcion == 1) {
            seleccionar_vuelo_para_reserva();
        }
        else if (opcion == 2) {
            crear_nuevo_vuelo();
        }
    }
}

void SistemaReservas::crear_nuevo_vuelo() {
    string origen, destino;
    cout << "Ingrese el Origen del Vuelo: ";
    cin >> origen;
    cout << "Ingrese el Destino del Vuelo: ";
    cin >> destino;

    Vuelo v;
    v.Generar_Detalles_Vuelo(origen, destino);
    agregar_vuelo(v);
}

void SistemaReservas::ver_detalles_vuelo() {
    if (vuelos.empty()) {
        cout << "No hay vuelos disponibles.\n";
        return;
    }

    mostrar_vuelos();

    int opcion;
    cout << "Seleccione un vuelo para ver los detalles: ";
    cin >> opcion;

    if (opcion < 1 || opcion > vuelos.size()) {
        cout << "Opcion no valida. Por favor intente nuevamente.\n";
        return;
    }

    vuelos[opcion - 1].Detalle_Vuelo();
}

void SistemaReservas::ver_reservas() {
    if (vuelos.empty()) {
        cout << "No hay vuelos disponibles.\n";
        return;
    }

    mostrar_vuelos();

    int opcion;
    cout << "Seleccione un vuelo para ver las reservas: ";
    cin >> opcion;

    if (opcion < 1 || opcion > vuelos.size()) {
        cout << "Opcion no valida. Por favor intente nuevamente.\n";
        return;
    }

    vuelos[opcion - 1].Ver_Reservas();
}

void SistemaReservas::cargar_reserva() {
    if (vuelos.empty()) {
        cout << "No hay vuelos disponibles. Por favor, cree un nuevo vuelo.\n";
        crear_nuevo_vuelo();
        return;
    }

    mostrar_vuelos();
    Reserva r;
    int opcion;
    cout << "Seleccione un vuelo para cargar una reserva: ";
    cin >> opcion;

    if (opcion < 1 || opcion > vuelos.size()) {
        cout << "Opcion no valida. Por favor intente nuevamente.\n";
        return;
    }

    vuelos[opcion - 1].Cargar_Reservar(r,Detalle);
}

void mostrar_menu() {
    cout << "1. Crear nuevo vuelo\n";
    cout << "2. Hacer reserva en vuelo existente\n";
    cout << "3. Ver detalles de un vuelo\n";
    cout << "4. Ver todas las reservas\n";
    cout << "5. Cargar una nueva reserva\n";
    cout << "6. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    std::srand(std::time(nullptr)); // Inicializar el generador de numeros aleatorios

    SistemaReservas sistema;
    bool salir = false;

    while (!salir) {
        mostrar_menu();
        int opcion;
        cin >> opcion;

        switch (opcion) {
        case 1:
            sistema.crear_nuevo_vuelo();
            break;
        case 2:
            sistema.seleccionar_vuelo_para_reserva();
            break;
        case 3:
            sistema.ver_detalles_vuelo();
            break;
        case 4:
            sistema.ver_reservas();
            break;
        case 5:
            sistema.cargar_reserva();
            break;
        case 6:
            salir = true;
            break;
        default:
            cout << "Opcion no valida. Por favor intente nuevamente.\n";
        }
        cout << endl;
    }

    cout << "Gracias por usar el sistema de reservas de vuelo.\n";
    return 0;
}
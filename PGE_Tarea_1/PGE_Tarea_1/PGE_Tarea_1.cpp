#include <iostream>
#include <Vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


class Pasajero
{
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

string Pasajero::get_nombre() {
	return nombre;
}

void Pasajero::set_nombre(string nom) {
	nom = nombre;
}

string Pasajero::get_apellido() {
	return apellido;
}

void Pasajero::set_apellido(string ap) {
	ap = apellido;
}

char Pasajero::get_sexo() {
	return sexo;
}

void Pasajero::set_sexo(char sex) {
	sex = sexo;
}

int Pasajero::get_DNI() {
	return DNI;
}

void Pasajero::set_DNI(int dni) {
	dni = DNI;
}

int Pasajero::get_telefono() {
	return telefono;
}

void Pasajero::set_telefono(int tel) {
	tel = telefono;
}

int Pasajero::get_numero_asiento() {
	return numero_asiento;
}

void Pasajero::set_numero_asiento(int na) {
	na = numero_asiento;
}

string Pasajero::get_direccion() {
	return direccion;
}

void Pasajero::set_direccion(string dire) {
	dire = direccion;
}

string Pasajero::get_mail() {
	return mail;
}

void Pasajero::set_mail(string em) {
	em = mail;
}


class Reserva
{
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
	vector <Pasajero> pasajeros;
	int Nro_reserva = 1111 + std::rand() % (9999 - 1111 + 1);
	bool Estado_Pago = false;
	string nro_vuelo;
	


};

Reserva::Reserva()
{

}

Reserva::~Reserva()
{

}

void Reserva::set_cant_pasajeros(int c)
{
	cant_pasajeros = c;
}

int Reserva::get_cant_pasajeros()
{
	return cant_pasajeros;
}


void Reserva::Cargar_pasajero(Pasajero p)
{
	pasajeros.push_back(p);
}

string Reserva::get_numero_vuelo()
{
	return nro_vuelo;
}

void Reserva::set_numero_vuelo(string n)
{
	nro_vuelo = n;
}

int Reserva::get_nro_reserva()
{
	return Nro_reserva;
}

bool Reserva::get_estado_pago()
{
	return Estado_Pago;
}





class Vuelo
{
public:
	Vuelo();
	~Vuelo();
	string get_numero_vuelo();
	string get_origen();
	string get_destino();
	string get_fecha();
	void set_origen(string o);
	void set_destino(string d);
	void set_fecha(string f);
	int get_time();
	int asientos_disponibles();
	void Cargar_Reservar();
	void Ver_Reservas();

private:
	string numero_vuelo;
	string origen;
	string destino;
	string fecha;
	int time;
	Pasajero Asientos[300];
	vector <Reserva> Reservas;
	int ocupados = 0;

};

Vuelo::Vuelo() {}

Vuelo::~Vuelo() {}



string Vuelo::get_numero_vuelo() {
	return numero_vuelo;
}

string Vuelo::get_origen() {
	return origen;
}

string Vuelo::get_destino() {
	return destino;
}

string Vuelo::get_fecha()
{
	return string();
}

void Vuelo::set_origen(string o)
{
	origen = o;
}

void Vuelo::set_destino(string d)
{
	destino = d;
}

void Vuelo::set_fecha(string f)
{
	fecha = f;
}

int Vuelo::get_time()
{
	return time;
}

int Vuelo::asientos_disponibles()
{
	return 300 - ocupados;
}

void Vuelo::Cargar_Reservar() {
	Reserva r;
	int o;
	int cant;
	string n;
	char s;
	cout << "Cuantos Pasajeros son: ";
	cin >> cant;
	r.set_cant_pasajeros(cant);
	for (int i = 0; i < cant;i++) {
		cout << "Pasajero " << i + 1 << endl;
		cout << "-------------------------" << endl;
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
		getline(cin,n);
		p.set_direccion(n);
		cout << "Email: ";
		getline(cin,n);
		p.set_mail(n);
		cout << "Telefono: ";
		cin >> o;
		p.set_telefono(o);
		p.set_numero_asiento(300 - ocupados);
		ocupados += 1;
		r.Cargar_pasajero(p);
		cout << "Pasajero Cargado correctamente." << endl;
	}
	r.set_numero_vuelo(numero_vuelo);
	Reservas.push_back(r);
	cout << "reserva cargada corectamente." << endl;
}

void Vuelo::Ver_Reservas() {
	for (int i = 0; i < Reservas.size();i++) {
		cout << "---------------------------" << endl;
		cout << "Numero de reserva: " << Reservas[i].get_nro_reserva() << endl;
		cout << "Cantidad de pasajeros: " << Reservas[i].get_cant_pasajeros() << endl;
		cout << "Estado de la reserva: ";
		if (Reservas[i].get_estado_pago()) {
			cout << "Pagado." << endl;
		}
		else {
			cout << "Pago pendiente." << endl;
		}
	}
}





int main()
{
	std::srand(std::time(nullptr));
	Vuelo v;
	v.Cargar_Reservar();
	cout << endl;
	v.Ver_Reservas();

}


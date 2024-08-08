#include <iostream>
#include <Vector>

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

private:
	int cant_pasajeros;
	vector <Pasajero> pasajeros;
	int Nro_reserva;
	bool Estado_Pago;
	int nro_vuelo;
	string Fecha_reserva;

};

Reserva::Reserva()
{

}

Reserva::~Reserva()
{

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





int main()
{
	std::cout << "Hello World!\n";
}


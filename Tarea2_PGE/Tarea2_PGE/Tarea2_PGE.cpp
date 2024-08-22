#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
using namespace std;

class Domicilio {
public:
	Domicilio();
	~Domicilio();
	string getCalle() const, getCiudad() const, getProvincia() const;
	int getAltura() const, getCodigoPostal() const;
	void setCalle(string ca), setCiudad(string ci), setProvincia(string pr), setAltura(int al), setCodigoPostal(int cp);
	void MostrarDomicilio() const {
		cout << getCalle() << " " << getAltura() << ", " << getCiudad() << ", " << getProvincia() << ", " << getCodigoPostal() << endl;
	}
private:
	string calle, ciudad, provincia;
	int altura, codigoPostal;
};

Domicilio::Domicilio() {}
Domicilio::~Domicilio() {}

string Domicilio::getCalle() const {
	return calle;
}

void Domicilio::setCalle(string ca) {
	calle = ca;
}

string Domicilio::getCiudad() const {
	return ciudad;
}

void Domicilio::setCiudad(string ci) {
	ciudad = ci;
}

string Domicilio::getProvincia() const {
	return provincia;
}

void Domicilio::setProvincia(string pr) {
	provincia = pr;
}

int Domicilio::getAltura() const {
	return altura;
}

void Domicilio::setAltura(int al) {
	altura = al;
}

int Domicilio::getCodigoPostal() const {
	return codigoPostal;
}

void Domicilio::setCodigoPostal(int cp) {
	codigoPostal = cp;
}

class Persona {
public:
	Persona();
	~Persona();
	string getNombre(), getApellido();
	char getSexo();
	int getFechaNacimiento();
	void setNombre(string nom), setApellido(string ap), setSexo(char sex), setFechaNacimiento(int fn);
	void setDomicilio(const string& calle, const string& ciudad, const string& provincia, const int& altura, const int& codigoPostal) {
		d.setCalle(calle);
		d.setCiudad(ciudad);
		d.setProvincia(provincia);
		d.setAltura(altura);
		d.setCodigoPostal(codigoPostal);
	}
	void getDomicilio() {
		cout << d.getCalle() << " " << d.getAltura() << ", " << d.getCiudad() << ", " << d.getProvincia() << ", " << d.getCodigoPostal();
	};
private:
	string nombre, apellido;
	char sexo;
	int fechaNacimiento;
	Domicilio d;

};

Persona::Persona() {}
Persona::~Persona() {}

string Persona::getNombre() {
	return nombre;
}

void Persona::setNombre(string nom) {
	nombre = nom;
}

string Persona::getApellido() {
	return apellido;
}

void Persona::setApellido(string ap) {
	apellido = ap;
}

char Persona::getSexo() {
	return sexo;
}

void Persona::setSexo(char sex) {
	sexo = sex;
}

int Persona::getFechaNacimiento() {
	return fechaNacimiento;
}

void Persona::setFechaNacimiento(int fn) {
	fechaNacimiento = fn;
}

class Academia {
private:
	class Animal {
	public:
		Animal();
		~Animal();
		string getNombre(), getApellido();
		char getGenero();
		int getEdad();
		void setNombre(string nom), setApellido(string ap), setGenero(char ge), setEdad(int ed);
		void setDatosAnimal(string nombre, string apellido, char genero, int edad) {
			setNombre(nombre);
			setApellido(apellido);
			setGenero(genero);
			setEdad(edad);
		}
	private:
		char genero;
		int edad;
		string nombre, apellido;
	};
	class Vehiculo {
	public:
		Vehiculo();
		~Vehiculo();
		string getMarca(), getModelo();
		int getAno();
		void setMarca(string ma), setModelo(string mo), setAno(int a);
		void setDatosVehiculo(string marca, string modelo, int ano) {
			setMarca(marca);
			setModelo(modelo);
			setAno(ano);
		}
	private:
		string marca, modelo;
		int ano;
	};
	class Estudiante : public Persona {
	public:
		Estudiante();
		~Estudiante();
		int getLegajo(), getFechaAlta(), getFechaBaja();
		void setLegajo(int le), setFechaAlta(int fa), setFechaBaja(int fb);
		void setDatosPersona(string nombre, string apellido, char sexo, int fn) {
			setNombre(nombre);
			setApellido(apellido);
			setSexo(sexo);
			setFechaNacimiento(fn);
		}
		void setDatosEstudiante(int legajo, int fa, int fb) {
			setLegajo(legajo);
			setFechaAlta(fa);
			setFechaBaja(fb);
		}
		void setDatosDomicilio(string calle, int altura, string ciudad, string provincia, int cp) {
			setDomicilio(calle, ciudad, provincia, altura, cp);
		}
		void asignarAnimal(const Animal& animal) {
			animalAsignado.push_back(animal);
		}
		void mostrarAnimalesAsignados() {
			if (animalAsignado.empty()) {
				cout << "No hay animales asignados a este estudiante." << endl;
			}
			else {
				cout << "Animales asignados:" << endl;
				for (int i = 0; i < animalAsignado.size(); i++) {
					cout << "Animal " << i + 1 << ": " << animalAsignado[i].getNombre() << " " << animalAsignado[i].getApellido() << endl;
				}
			}
		}
		void asignarVehiculo(const Vehiculo& vehiculo) {
			vehiculoAsignado.push_back(vehiculo);
		}
		void mostrarvehiculoAsignado() {
			if (vehiculoAsignado.empty()) {
				cout << "No hay vehiculos asignados a este estudiante." << endl;
			}
			else {
				cout << "Vehiculos asignados:" << endl;
				for (int i = 0; i < vehiculoAsignado.size(); i++) {
					cout << "Vehiculo " << i + 1 << ": " << vehiculoAsignado[i].getMarca() << " " << vehiculoAsignado[i].getModelo() << " " << vehiculoAsignado[i].getAno() << endl;
				}
			}
		}
	private:
		int legajo, fechaAlta, fechaBaja;
		vector<Animal> animalAsignado;
		vector<Vehiculo> vehiculoAsignado;
	};
	class Instructor : public Persona {
	public:
		Instructor();
		~Instructor();
		int getID(), getFechaIngreso();
		string getEspecialidad();
		void setID(int i), setEspecialidad(string e), setFechaIngreso(int fi);
		void setDatosPersona(string nombre, string apellido, char sexo, int fn) {
			setNombre(nombre);
			setApellido(apellido);
			setSexo(sexo);
			setFechaNacimiento(fn);
		}
		void setDatosDomicilio(string calle, int altura, string ciudad, string provincia, int cp) {
			setDomicilio(calle, ciudad, provincia, altura, cp);
		}
		void setDatosInstructor(int id, string especialidad, int fi) {
			setID(id);
			setEspecialidad(especialidad);
			setFechaIngreso(fi);
		}
		void asignarVehiculo(const Vehiculo& vehiculo) {
			vehiculoAsignado.push_back(vehiculo);
		}
		void mostrarvehiculoAsignado() {
			if (vehiculoAsignado.empty()) {
				cout << "No hay vehiculos asignados a este estudiante." << endl;
			}
			else {
				cout << "Vehiculos asignados:" << endl;
				for (int i = 0; i < vehiculoAsignado.size(); i++) {
					cout << "Vehiculo " << i + 1 << ": " << vehiculoAsignado[i].getMarca() << " " << vehiculoAsignado[i].getModelo() << " " << vehiculoAsignado[i].getAno() << endl;
				}
			}
		}
	private:
		int ID;
		string especialidad;
		int fechaIngreso;
		vector<Vehiculo> vehiculoAsignado;
	};
	class Entrenamiento {
	public:
		Entrenamiento() {}
		~Entrenamiento() {}

		void setFecha(int f) { fecha = f; }
		void setHora(int h) { hora = h; }

		int getFecha() const { return fecha; }
		int getHora() const { return hora; }

	private:
		int fecha, hora;
	};

	vector<Estudiante> estudiantes;
	vector<Instructor> instructores;
	vector<Animal> animales;
	vector<Vehiculo> vehiculos;
	vector<Entrenamiento> entrenamientos;

public:
	void RegistrarEstudiante();
	void RegistrarInstructor();
	void DetallesPersona();
	void RegistrarAnimal();
	void AsignarAnimal();
	void ListarAnimal();
	void ProgramarEntrenamiento();
	//void ListarEstudiante();
	void RegistrarVehiculo();
	void AsignarVehiculo();
	void ListarVehiculo();
	//void RegistrarProgreso();
	//void CalificarExamen();
	void Menu();
};

Academia::Estudiante::Estudiante() {}
Academia::Estudiante::~Estudiante() {}

int Academia::Estudiante::getLegajo() {
	return legajo;
}

void Academia::Estudiante::setLegajo(int le) {
	legajo = le;
}

int Academia::Estudiante::getFechaAlta() {
	return fechaAlta;
}

void Academia::Estudiante::setFechaAlta(int fa) {
	fechaAlta = fa;
}

int Academia::Estudiante::getFechaBaja() {
	return fechaBaja;
}

void Academia::Estudiante::setFechaBaja(int fb) {
	fechaBaja = fb;
}

void Academia::RegistrarEstudiante() {
	Estudiante e;
	string nombre = "", apellido = ""; char sexo = 0; int fn = 0;
	string calle = "", ciudad = "", provincia = ""; int altura = 0, codigoPostal = 0;
	int legajo = 0, fechaAlta = 0, fechaBaja = 0;

	cout << "Nombre: ";
	cin >> nombre;
	cout << "Apellido: ";
	cin >> apellido;
	cout << "Sexo (M/F): ";
	cin >> sexo;
	cout << "Fecha de Nacimiento (DDMMAAAA): ";
	cin >> fn;

	e.setDatosPersona(nombre, apellido, sexo, fn);

	cout << "Calle: ";
	cin.ignore();
	getline(cin, calle);
	cout << "Altura: ";
	cin >> altura;
	cout << "Ciudad: ";
	cin.ignore();
	getline(cin, ciudad);
	cout << "Provincia: ";
	cin.ignore();
	getline(cin, provincia);
	cout << "Codigo Postal: ";
	cin >> codigoPostal;

	e.setDatosDomicilio(calle, altura, ciudad, provincia, codigoPostal);

	cout << "Legajo: ";
	cin >> legajo;
	cout << "Fecha de Alta(DDMMAAAA): ";
	cin >> fechaAlta;
	cout << "Fecha de Baja(DDMMAAAA): ";
	cin >> fechaBaja;

	e.setDatosEstudiante(legajo, fechaAlta, fechaBaja);

	estudiantes.push_back(e);

	cout << "Estudiante registrado con exito." << endl;
}

void Academia::RegistrarInstructor() {
	Instructor i;
	string nombre = "", apellido = ""; char sexo = 0; int fn = 0;
	string calle = "", ciudad = "", provincia = ""; int altura = 0, codigoPostal = 0;
	int ID = 0; string especialidad = ""; int fechaIngreso = 0;

	cout << "Nombre: ";
	cin >> nombre;
	cout << "Apellido: ";
	cin >> apellido;
	cout << "Sexo (M/F): ";
	cin >> sexo;
	cout << "Fecha de Nacimiento (DDMMAAAA): ";
	cin >> fn;

	i.setDatosPersona(nombre, apellido, sexo, fn);

	cout << "Calle: ";
	cin.ignore();
	getline(cin, calle);
	cout << "Altura: ";
	cin >> altura;
	cout << "Ciudad: ";
	cin.ignore();
	getline(cin, ciudad);
	cout << "Provincia: ";
	cin.ignore();
	getline(cin, provincia);
	cout << "Codigo Postal: ";
	cin >> codigoPostal;

	i.setDatosDomicilio(calle, altura, ciudad, provincia, codigoPostal);

	cout << "ID: ";
	cin >> ID;
	cout << "Especialidad: ";
	cin.ignore();
	getline(cin, especialidad);
	cout << "Fecha de Ingreso(DDMMAAAA): ";
	cin >> fechaIngreso;

	i.setDatosInstructor(ID, especialidad, fechaIngreso);

	instructores.push_back(i);

	cout << "Instructor registrado con éxito." << endl;
}

Academia::Instructor::Instructor() {}
Academia::Instructor::~Instructor() {}

int Academia::Instructor::getID() {
	return ID;
}

void Academia::Instructor::setID(int i) {
	ID = i;
}

int Academia::Instructor::getFechaIngreso() {
	return fechaIngreso;
}

void Academia::Instructor::setFechaIngreso(int fi) {
	fechaIngreso = fi;
}

string Academia::Instructor::getEspecialidad() {
	return especialidad;
}

void Academia::Instructor::setEspecialidad(string e) {
	especialidad = e;
}

Academia::Animal::Animal() {}
Academia::Animal::~Animal() {}

string Academia::Animal::getNombre() {
	return nombre;
}

void Academia::Animal::setNombre(string nom) {
	nombre = nom;
}

string Academia::Animal::getApellido() {
	return apellido;
}

void Academia::Animal::setApellido(string ap) {
	apellido = ap;
}

char Academia::Animal::getGenero() {
	return genero;
}

void Academia::Animal::setGenero(char ge) {
	genero = ge;
}

int Academia::Animal::getEdad() {
	return edad;
}

void Academia::Animal::setEdad(int ed) {
	edad = ed;
}

Academia::Vehiculo::Vehiculo() {}
Academia::Vehiculo::~Vehiculo() {}

string Academia::Vehiculo::getMarca() {
	return marca;
}

void Academia::Vehiculo::setMarca(string ma) {
	marca = ma;
}

string Academia::Vehiculo::getModelo() {
	return modelo;
}

void Academia::Vehiculo::setModelo(string mo) {
	modelo = mo;
}

int Academia::Vehiculo::getAno() {
	return ano;
}

void Academia::Vehiculo::setAno(int a) {
	ano = a;
}

void Academia::DetallesPersona() {

	cout << "Lista de instructores:\n";
	for (int i = 0; i < instructores.size(); i++) {
		cout << "----------------------------------------\n";
		cout << "Nombre: " << instructores[i].getNombre() << " " << instructores[i].getApellido() << endl;
		cout << "Sexo: " << instructores[i].getSexo() << endl;
		cout << "Fecha de Nacimiento: " << instructores[i].getFechaNacimiento() << endl;
		cout << "Domicilio: ";
		instructores[i].getDomicilio();
		cout << endl;
		cout << "ID: " << instructores[i].getID() << endl;
		cout << "Fecha Ingreso: " << instructores[i].getFechaIngreso() << endl;
		cout << "Especialidad: " << instructores[i].getEspecialidad() << endl;
		cout << "----------------------------------------\n";
	}
	cout << "Lista de estudiantes:\n";
	for (int i = 0; i < estudiantes.size(); i++) {
		cout << "----------------------------------------\n";
		cout << "Nombre: " << estudiantes[i].getNombre() << " " << estudiantes[i].getApellido() << endl;
		cout << "Sexo: " << estudiantes[i].getSexo() << endl;
		cout << "Fecha de Nacimiento: " << estudiantes[i].getFechaNacimiento() << endl;
		cout << "Domicilio: ";
		estudiantes[i].getDomicilio();
		cout << endl;
		cout << "Legajo: " << estudiantes[i].getLegajo() << endl;
		cout << "Fecha Ingreso: " << estudiantes[i].getFechaAlta() << endl;
		cout << "Fecha Egreso: " << estudiantes[i].getFechaBaja() << endl;
		cout << "----------------------------------------\n";
	}
}

void Academia::RegistrarAnimal() {
	Animal a;
	char genero = 0; int edad = 0; string nombre = "", apellido = "";

	cout << "Nombre: ";
	cin >> nombre;
	cout << "Apellido: ";
	cin >> apellido;
	cout << "Genero: ";
	cin >> genero;
	cout << "Edad: ";
	cin >> edad;

	a.setDatosAnimal(nombre, apellido, genero, edad);
	animales.push_back(a);

	cout << "Animal registrado con éxito." << endl;
}

void Academia::AsignarAnimal() {
	if (estudiantes.empty()) {
		cout << "No se encontraron estudiantes disponibles.\n";
		return;
	}

	if (animales.empty()) {
		cout << "No se encontraron animales disponibles.\n";
		return;
	}

	// Inicializar la semilla para la generación aleatoria
	srand(static_cast<unsigned>(time(0)));

	// Seleccionar un estudiante aleatoriamente
	int indiceEstudiante = rand() % estudiantes.size();

	// Seleccionar un animal aleatoriamente
	int indiceAnimal = rand() % animales.size();

	// Asignar el animal al estudiante
	cout << "----------------------------------------\n";
	estudiantes[indiceEstudiante].asignarAnimal(animales[indiceAnimal]);
	cout << "Animal asignado al estudiante: " << estudiantes[indiceEstudiante].getNombre() << " " << estudiantes[indiceEstudiante].getApellido() << endl;
	cout << "----------------------------------------\n";
}

void Academia::ListarAnimal() {

	int indiceEstudiante = rand() % estudiantes.size();

	estudiantes[indiceEstudiante].mostrarAnimalesAsignados();
	cout << "Estudiante: " << estudiantes[indiceEstudiante].getNombre() << estudiantes[indiceEstudiante].getApellido() << endl;
}

void Academia::ProgramarEntrenamiento() {
	if (estudiantes.empty()) {
		cout << "No se encontraron estudiantes disponibles.\n";
		return;
	}

	if (instructores.empty()) {
		cout << "No se encontraron instructores disponibles.\n";
		return;
	}

	if (animales.empty()) {
		cout << "No se encontraron animales disponibles.\n";
		return;
	}


	// Elegir un estudiante aleatorio
	srand(static_cast<unsigned>(time(0)));
	int indiceEstudiante = rand() % estudiantes.size();
	Estudiante& estudiante = estudiantes[indiceEstudiante];

	// Elegir un instructor aleatorio
	int indiceInstructor = rand() % instructores.size();
	Instructor& instructor = instructores[indiceInstructor];

	// Elegir un animal aleatorio
	int indiceAnimal = rand() % animales.size();
	Animal& animal = animales[indiceAnimal];

	int fecha, hora;
	cout << "Ingrese la fecha del entrenamiento (DDMMAAAA): ";
	cin >> fecha;
	cout << "Ingrese la hora del entrenamiento (HHMM): ";
	cin >> hora;

	Entrenamiento e;

	e.setFecha(fecha);
	e.setHora(hora);

	entrenamientos.push_back(e);

	cout << "----------------------------------------\n";
	cout << "Entrenamiento programado:\n";
	cout << "----------------------------------------\n";
	cout << "Fecha: " << fecha << "\n";
	cout << "Hora: " << hora << "\n";
	cout << "Estudiante: " << estudiante.getNombre() << " " << estudiante.getApellido() << "\n";
	cout << "Instructor: " << instructor.getNombre() << " " << instructor.getApellido() << "\n";
	cout << "Animal: " << animal.getNombre() << " " << animal.getApellido() << "\n";
	cout << "----------------------------------------\n";
}

void Academia::RegistrarVehiculo() {
	Vehiculo v;
	string marca = "", modelo = ""; int ano = 0;

	cout << "Marca: ";
	cin.ignore();
	getline(cin, marca);
	cout << "Modelo: ";
	cin >> modelo;
	cout << "Ano: ";
	cin >> ano;

	v.setDatosVehiculo(marca, modelo, ano);
	vehiculos.push_back(v);
}

void Academia::AsignarVehiculo() {
	if (estudiantes.empty()) {
		cout << "No se encontraron estudiantes disponibles.\n";
		return;
	}

	if (instructores.empty()) {
		cout << "No se encontraron animales disponibles.\n";
		return;
	}

	if (vehiculos.empty()) {
		cout << "No se encontraron vehiculos disponibles.\n";
		return;
	}

	while (!estudiantes.empty() && !instructores.empty() && !vehiculos.empty()) {
		// Inicializar la semilla para la generación aleatoria
		srand(static_cast<unsigned>(time(0)));

		// Seleccionar un estudiante o instructor aleatoriamente
		int indiceEstudiante = rand() % estudiantes.size();
		int indiceInstructor = rand() % instructores.size();

		// Seleccionar un vehiculo aleatoriamente
		int indiceVehiculo = rand() % vehiculos.size();

		int asignarA = rand() % 2;

		// Asignar el vehiculo al estudiante o instructor
		if (asignarA == 0) {
			cout << "----------------------------------------\n";
			estudiantes[indiceEstudiante].asignarVehiculo(vehiculos[indiceVehiculo]);
			cout << "Vehículo asignado al estudiante: " << estudiantes[indiceEstudiante].getNombre() << endl;
			cout << "----------------------------------------\n";
		}
		else {
			cout << "----------------------------------------\n";
			instructores[indiceInstructor].asignarVehiculo(vehiculos[indiceVehiculo]);
			cout << "Vehículo asignado al instructor: " << instructores[indiceInstructor].getNombre() << endl;
			cout << "----------------------------------------\n";
		}
	}
}

void Academia::ListarVehiculo() {
	if (vehiculos.empty()) {
		cout << "No se encontraron vehiculos disponibles.\n";
		return;
	}

	int indiceEstudiante = rand() % estudiantes.size();
	int indiceInstructor = rand() % instructores.size();

	estudiantes[indiceEstudiante].mostrarvehiculoAsignado();
	instructores[indiceInstructor].mostrarvehiculoAsignado();
}

void Academia::Menu()
{
	int op = 0;
	do {
		cout << "------------------------------------------\n";
		cout << "Sistema de gestion Academia Patitas Suaves\n";
		cout << "------------------------------------------\n";
		cout << "[1] Registrar Persona.\n";
		cout << "[2] Detalles Persona.\n";
		cout << "[3] Registrar Animal.\n";
		cout << "[4] Asignar Animal a Estudiante.\n";
		cout << "[5] Listar Animales Asignados a un Estudiante.\n";
		cout << "[6] Programar Sesion de Entrenamiento.\n";
		cout << "[7] Registrar Vehiculo.\n";
		cout << "[8] Asignar Vehiculo a Persona.\n";
		//cout << "[10] Registrar Progreso de Entrenamiento." << endl;
		//cout << "[11] Calificar Examen de Adiestramiento." << endl;
		cout << "[9] Listar Vehiculos Disponibles.\n";
		cout << "[10] Salir del programa.\n";
		cout << "-------------------------------------\n";
		cin >> op;
		switch (op)
		{
		case 1:
			char o;
			cout << "Ingrese una S para salir al menu\n";
			cout << "Desea registrar un estudiante o un instructor?\n";
			cout << "[I] Instructor | [E] Estudiante\n";
			cin >> o;
			if (o == 'I' || o == 'i') {
				RegistrarInstructor();
			}
			else if (o == 'E' || o == 'e') {
				RegistrarEstudiante();
			}
			else {
				cout << "Opcion no valida. Ingrese nuevamente.";
			}
			break;
		case 2:
			DetallesPersona();
			break;
		case 3:
			RegistrarAnimal();
			break;
		case 4:
			AsignarAnimal();
			break;
		case 5:
			ListarAnimal();
			break;
		case 6:
			ProgramarEntrenamiento();
			break;
		case 7:
			RegistrarVehiculo();
			break;
		case 8:
			AsignarVehiculo();
			break;
		case 9:
			ListarVehiculo();
			break;
		case 10:
			break;
		default:
			cout << "Opcion no valida. Ingrese nuevamente." << endl;
			break;
		}
	} while (op != 10);
}

int main()
{
	Academia a;
	a.Menu();
	return 0;
}
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
/*Debe tener los siguientes métodos:
	- Constructor
	- Iniciar el temporizador
	- Detener el temporizador
	- Regresar la cantidad de tiempo transcurrido. Esto puede mostrarse
	en diversos formatos: cantidad de milisegundos, formato minutos y
	segundos por ejemplo hh:mm:ss.
	- Resetear el temporizador (volverlo a cero).
	- Tres métodos más que Ud. elija agregar referidos al uso del tiempo
	o fechas con la librería ctime*/

class Temporizador {
public:
	Temporizador() {
		resetear();
	}
	
	void iniciar() {
		if (!iniciado) {
			iniciado = true;
			tiempo_inicio = std::clock();
		}
	}
	
	void detener() {
		if (iniciado) {
			iniciado = false;
			tiempo_transcurrido += std::clock() - tiempo_inicio;
		}
	}
	
	void resetear() {
		iniciado = false;
		tiempo_inicio = 0;
		tiempo_transcurrido = 0;
	}
	
	double obtener_tiempo_transcurrido_milisegundos() const {
		return static_cast<double>(tiempo_transcurrido);
	}
	
	std::string obtener_tiempo_transcurrido_hh_mm_ss() const {
		int segundos_totales = static_cast<int>(tiempo_transcurrido);
		int horas = segundos_totales / 3600;
		int minutos = (segundos_totales % 3600) / 60;
		int segundos = segundos_totales % 60;
		
		return std::to_string(horas) + ":" + std::to_string(minutos) + ":" + std::to_string(segundos);
	}
	
private:
		bool iniciado;
		std::clock_t tiempo_inicio;
		std::clock_t tiempo_transcurrido;
};

void mostrar_menu() {
	std::cout << "1. Iniciar temporizador\n";
	std::cout << "2. Detener temporizador\n";
	std::cout << "3. Mostrar tiempo transcurrido en milisegundos\n";
	std::cout << "4. Mostrar tiempo transcurrido en formato hh:mm:ss\n";
	std::cout << "5. Resetear temporizador\n";
	std::cout << "6.Salir\n";
}

int main() {
	Temporizador temporizador;
	time_t tiempo;
	
	tiempo = time(NULL);
	int opcion;
	
	while (true) {
		mostrar_menu();
		
		std::cin >> opcion;
		
		switch (opcion) {
		case 1:
			temporizador.iniciar();
			break;
			
		case 2:
			temporizador.detener();
			break;
			
		case 3:
			std::cout << "Tiempo transcurrido en milisegundos: " << temporizador.obtener_tiempo_transcurrido_milisegundos() << "\n";
			break;
			
		case 4:
			std::cout << "Tiempo transcurrido en formato hh:mm:ss: " << temporizador.obtener_tiempo_transcurrido_hh_mm_ss() << "\n";
			break;
			
		case 5:
			temporizador.resetear();
			break;
		
	    case 6:
			opcion=true;
			break;
			
		default:
			std::cout << "Opción inválida.\n";
			break;
			
		}
	}
	
	return 0;
}


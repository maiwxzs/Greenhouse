#ifndef GREENHOUSE_CORE_HPP
#define GREENHOUSE_CORE_HPP

#include 
#include 
#include 

using namespace std;

// Lectura de datos de sensores
class LecturaDato {
public:
    int idLectura;
    long timestamp;
    float valor;
    string unidad;

    LecturaDato(int id, float val, string uni) 
        : idLectura(id), timestamp(0), valor(val), unidad(uni) {}

    bool esValida() {
        return valor >= 0.0f;
    }

    string formatearSalida() {
        return "Lectura #" + to_string(idLectura) + ": " + to_string(valor) + " " + unidad;
    }
};

// Evaluación de umbrales y reglas
class ReglaControl {
public:
    float umbralTempMax;
    float umbralHumedadSueloMin;
    string estadoAlerta;

    ReglaControl(float tempMax, float humMin) 
        : umbralTempMax(tempMax), umbralHumedadSueloMin(humMin), estadoAlerta("NORMAL") {}

    void evaluarTemperatura(float t) {
        if (t > umbralTempMax) {
            estadoAlerta = "ALERTA_TEMPERATURA_ALTA";
        }
    }

    void evaluarHumedad(float h) {
        if (h < umbralHumedadSueloMin) {
            estadoAlerta = "ALERTA_SUELO_SECO";
        }
    }

    string obtenerEstado() {
        return estadoAlerta;
    }
};

// Clase base abstracta para sensores
class Sensor {
public:
    int idPin;
    string nombre;
    bool activo;

    Sensor(int pin, string nom) : idPin(pin), nombre(nom), activo(true) {}
    virtual ~Sensor() {}

    virtual void inicializar() = 0;
    virtual void obtenerLectura() = 0;
};

// Clase base abstracta para actuadores
class Actuador {
public:
    int idPin;
    bool estado;

    Actuador(int pin) : idPin(pin), estado(false) {}
    virtual ~Actuador() {}

    virtual void encender() = 0;
    virtual void apagar() = 0;
};

// Sensor de humedad de suelo (YL-69 / FC-28)
class SensorHumedad : public Sensor {
public:
    float humedad;

    SensorHumedad(int pin) : Sensor(pin, "YL-69 Humedad Suelo"), humedad(0.0f) {}

    void inicializar() override {
        // Inicialización de pin analógico
    }

    void obtenerLectura() override {
        leerHumedadSuelo();
    }

    void leerHumedadSuelo() {
        // Lectura de entrada analógica
    }

    float porcentajeHumedad() {
        return humedad;
    }
};

// Sensor ambiental (DHT11)
class SensorDHT11 : public Sensor {
public:
    float temperatura;
    float humedadAire;

    SensorDHT11(int pin) : Sensor(pin, "DHT11 Ambiental"), temperatura(0.0f), humedadAire(0.0f) {}

    void inicializar() override {
        // Inicialización bus digital DHT
    }

    void obtenerLectura() override {
        leerTemperatura();
        leerHumedadAire();
    }

    void leerTemperatura() {
        // Lectura de grados Celsius
    }

    void leerHumedadAire() {
        // Lectura de porcentaje humedad aire
    }
};

// Indicador visual LED
class IndicadorLED : public Actuador {
public:
    string color;
    string parpadeo;

    IndicadorLED(int pin, string col) 
        : Actuador(pin), color(col), parpadeo("DESACTIVADO") {}

    void encender() override {
        estado = true;
    }

    void apagar() override {
        estado = false;
    }

    void cambiarEstado() {
        estado = !estado;
    }

    void cambiarColor(string nuevoColor) {
        color = nuevoColor;
    }
};

// Servomotor para escotilla de ventilación
class ServomotorEscotilla : public Actuador {
public:
    int anguloActual;
    int anguloAbierto;
    int anguloCerrado;

    ServomotorEscotilla(int pin, int abierto = 90, int cerrado = 0) 
        : Actuador(pin), anguloActual(cerrado), anguloAbierto(abierto), anguloCerrado(cerrado) {}

    void encender() override {
        abrirEscotilla();
    }

    void apagar() override {
        cerrarEscotilla();
    }

    void abrirEscotilla() {
        fijarAngulo(anguloAbierto);
    }

    void cerrarEscotilla() {
        fijarAngulo(anguloCerrado);
    }

    void fijarAngulo(int angulo) {
        anguloActual = angulo;
    }
};

// Controlador principal
class ControladorArduino {
public:
    int puertoSerie;
    int frecuenciaMuestreo;
    string estadoActual;

    vector sensores;
    vector actuadores;
    vector reglas;

    ControladorArduino(int puerto = 9600, int freq = 2000) 
        : puertoSerie(puerto), frecuenciaMuestreo(freq), estadoActual("INICIANDO") {}

    void leerSensores() {
        for (Sensor* s : sensores) {
            if (s->activo) {
                s->obtenerLectura();
            }
        }
    }

    void ejecutarLogica() {
        // Evaluación de reglas de control
    }

    void enviarTelemetria() {
        // Envío de datos por serie o WiFi
    }
};

// Entidad principal del sistema
class Invernadero {
public:
    string idInvernadero;
    string nombre;
    bool sistemaActivo;

    ControladorArduino* controlador;

    Invernadero(string id, string nom) 
        : idInvernadero(id), nombre(nom), sistemaActivo(false), controlador(nullptr) {}

    void iniciarSistema() {
        sistemaActivo = true;
    }

    void monitorear() {
        if (sistemaActivo && controlador != nullptr) {
            controlador->leerSensores();
            controlador->ejecutarLogica();
            controlador->enviarTelemetria();
        }
    }
};

#endif // GREENHOUSE_CORE_HPP
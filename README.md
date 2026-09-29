# Smart Greenhouse IoT — Sistema de Monitoreo y Ventilación Automatizada
 
## Descripción General
 
Sistema embebido de control y monitoreo en tiempo real diseñado para prevenir pérdidas de cultivos por variaciones térmicas e hídricas. La solución integra adquisición de datos mediante sensores ambientales, control de actuadores mecatrónicos y una arquitectura orientada a objetos en C++ bajo principios de ingeniería de sistemas.
 
**Tecnologías:** C++ | Arduino | Embedded Systems | IoT | UML/POO
 
---
 
## Arquitectura del Sistema
 
El modelo de software implementa principios de programación orientada a objetos en C++, abstrayendo componentes físicos en clases especializadas para control, sensores y actuadores.
 
```
Sensores (DHT11, YL-69)
         ↓
  Microcontrolador
    (Arduino/ESP32)
         ↓
  Lógica de Control (C++ POO)
         ↓
Actuadores (Servomotor, LEDs)
```
 
Para consultar diagramas de bloques, flujo de sistema y mapeo UML-OOP, véase la carpeta `docs/assets/`.
 
---
 
## Componentes de Hardware
 
| Componente | Tipo | Función |
|------------|------|---------|
| Arduino UNO / ESP32 | Microcontrolador | Procesamiento local y ejecución de reglas de control |
| DHT11 | Sensor Ambiental | Lectura de temperatura (°C) y humedad relativa (%) |
| YL-69 / FC-28 | Sensor Higrómetro | Lectura de humedad en sustrato/suelo |
| Servomotor SG90 | Actuador | Apertura/cierre mecánico de escotilla de ventilación |
| LEDs Indicadores | Actuador | Señalización visual de estado y alertas |
 
---
 
## Estructura del Repositorio
 
```
smart-greenhouse-iot/
├── docs/                              # Documentación técnica
│   ├── technical-system-specification.pdf
│   ├── uml-to-oop-mapping-analysis.pdf
│   └── assets/                        # Esquemas y diagramas
├── firmware/                          # Código embebido C++
│   ├── include/
│   │   └── GreenhouseCore.hpp        # Clases POO (Sensores, Actuadores, Control)
│   └── src/
│       └── main.cpp                   # Punto de entrada (setup/loop)
├── hardware/                          # Esquemas, modelos 3D y BOM
│   ├── circuits/
│   ├── 3d-models/
│   └── bom/
├── .gitignore
└── README.md
```
 
---
 
 
 
---
 
## Documentación
 
### Archivos de Referencia
 
- **technical-system-specification.pdf** — Especificación técnica del sistema
- **uml-to-oop-mapping-analysis.pdf** — Análisis de mapeo UML a OOP
- **diagrams/** — Esquemas circuitales y diagramas de flujo
### Convenciones de Código
 
- Lenguaje: C++ (estándar C++11 o superior)
- Estilo: Nomenclatura camelCase para métodos, UPPER_CASE para constantes
- Documentación: Comentarios en línea explicando lógica de control
---
 
## Autores
 
- **maiwxzs**
- **pautthh**
- **lopezand2701**
- **jdavidortiz2004-tech**
 
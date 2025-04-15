# Auto Modular Estandarizado de Base (AMEB)

Es una plataforma base sobre la que las diferentes escuderías podrán desarrollar sus propias soluciones al problema planteado.
La modularidad es la filosofía central del diseño ya que queremos que los equipos tengan una amplia capacidad de modificación de la plataforma, sin embargo hay que encontrar un balance entre modularidad, rigidez y facilidad de producción.

## Requerimientos:
- Modularidad
- Facilidad de producción y reparación
- Rigidez estructural
- Capacidad de expansión
- Desempeño decente en la pista con mucho potencial disponible
- Diseño robusto 
- Minimizando posibles puntos de falla durante la carrera
- Sistema de giro tradicional (rotando las ruedas delanteras)

### Nice-to-have
- Comunicación con centro de control mediante más de un canal
- Acelerómetro, giroscopio y magnetómetro para mejorar estimación de posición 
- Feedback del estado del sistema de giro(closed loop)
- Medición de velocidad de rueda
- Sistema de propulsión independiente para cada rueda trasera
- Algún tipo de suspensión
- Capacidad alta de procesamiento (raspberry pi possibly)
- Sistema de posicionamiento mediante cámaras y marcadores infrarrojos

## Sistema de dirección frontal
El sistema de giro es una de las partes más complicadas de todo el diseño ya que son las responsables de hacer que el auto gire y van a ser el principal punto de control que van a tener los equipos sobre cómo se comporta el auto, también es una de las partes que más fuerzas y abuso van a ver en todo el auto, por lo que tienen que ser extremadamente robustas para durar toda una carrera en la que podrían ocurrir choques, roces y fuerzas imprevistas en el tren delantero. 

A continuación vamos a deliberar algunas importantes decisiones sobre la geometría del sistema de giro.
### Ackerman vs Anti-ackerman vs Estandard
Primero y principal vamos a definir que tipo de configuración de giro vamos a usar, realmente solo tenemos 3 opciones prácticas: Estándar(0 ackerman), ackerman positivo y anti-ackerman, cada una con sus pros y sus contras.

- Estándar: Es la más simple de todas, con ambas ruedas manteniéndose paralelas entre sí en todo ángulo de giro, es simple y funcional pero puede ser mejorable.

- Ackerman: Este sistema hace que las ruedas externas a la dirección de giro giren menos que las internas, manteniendo mejor el arco de giro en ambas ruedas, evitando que una deslice más que la otra, otorgando un gorro más suave y controlado con menos desgaste de cubiertas a cuestas de capacidad de giro máxima, ideal para plataformas utilitarias o urbanas.

- Anti-ackerman: Es el completo opuesto de la configuración Ackerman, va a girar las ruedas externas al giro más que las internas, esto se hace con el propósito de generar un mayor ángulo de delize en las ruedas exteriores que también son las ruedas que van a tener mayor carga durante un giro por lo que van a poder soportar dicho ángulo, maximizando toda la capacidad de giro que ofrezca el auto, este sistema se usa principalmente en autos en donde la prioridad es sacar el desempeño máximo de la plataforma, como por ejemplo en los autos de carreras, esto viene a costa únicamente de un mucho mayor desgaste de las cubiertas y de giros ligeramente más bruscos.

Tras definir los pros y contras de cada configuración es bastante claro que la mejor configuración sería “Anti-Ackerman” ya que estamos tratando de desarrollar un auto de alto desempeño y esta configuración nos trae múltiples beneficios que se alinean bien con nuestros objetivos.

## Sistema de propulsion



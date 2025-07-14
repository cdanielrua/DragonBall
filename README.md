# Be Yayirobe 🎮

Un videojuego 2D de acción y aventura con vista cenital, inspirado en el capítulo 105 del manga de Dragon Ball. Desarrollado en C++ con el framework Qt, el juego desafía a los jugadores a navegar niveles llenos de obstáculos y enemigos con comportamientos basados en diferentes modelos físicos.

![Gameplay GIF](https://raw.githubusercontent.com/cdanielrua/DragonBall/main/gameplay.gif) 

---

## ✨ Características Principales

* **Múltiples Niveles:** Viaja a través de 3 niveles únicos con un aumento progresivo de la dificultad.
* **Enemigos Diversos:** Enfréntate a enemigos con diferentes patrones de ataque y movimiento.
* **Jugabilidad Basada en Físicas:** Las mecánicas del juego están impulsadas por simulaciones físicas realistas:
    * ☄️ **Movimiento Parabólico:** Esquiva los proyectiles de cañón que siguen una trayectoria curva y realista.
    * Swinging Pendulum **Movimiento Pendular:** Evita trampas de péndulos que se balancean con un movimiento oscilatorio preciso.
    * 🌀 **Movimiento Circular:** Enfréntate a un jefe final protegido por un escudo de orbes que giran a su alrededor.
* **Sistema de Guardado:** Tu progreso se guarda automáticamente, permitiéndote continuar tu partida más tarde.

---

## 🛠️ Tecnología Utilizada

* **Lenguaje:** C++
* **Framework:** Qt 5 para la interfaz gráfica, la gestión de la escena (`QGraphicsScene`) y el manejo de eventos.
* **IDE:** Desarrollado principalmente en Qt Creator.

---

## 🚀 Cómo Empezar

Para compilar y ejecutar el proyecto desde el código fuente, necesitarás tener instalado Qt y un compilador de C++.

### Prerrequisitos
* Qt Framework (versión 5.15 o superior recomendada)
* Qt Creator o un IDE compatible con C++ y Qt
* Un compilador de C++ (MinGW, MSVC en Windows, GCC en Linux, Clang en macOS)

### Pasos para la Compilación
1.  **Clona el repositorio:**
    ```sh
    git clone [https://github.com/cdanielrua/DragonBall.git](https://github.com/cdanielrua/DragonBall.git)
    ```
2.  **Abre el proyecto:**
    Abre el archivo `DragonBall.pro` con Qt Creator.
3.  **Configura el Kit:**
    Asegúrate de que el proyecto esté configurado con un Kit de compilación válido que incluya tu instalación de Qt.
4.  **Compila y Ejecuta:**
    * Presiona `Ctrl+B` (o `Cmd+B`) para compilar el proyecto.
    * Presiona `Ctrl+R` (o `Cmd+R`) para ejecutarlo.

### Ejecutable
También puedes encontrar un **ejecutable precompilado** en la sección de `Releases` del repositorio de GitHub para jugar directamente sin necesidad de compilar.

---

## 🕹️ Cómo Jugar

Los controles del juego son sencillos:

* **Movimiento:** `W` (Arriba), `A` (Izquierda), `S` (Abajo), `D` (Derecha)
* **Disparar:**
    * `I`: Disparar hacia arriba
    * `K`: Disparar hacia abajo
    * `J`: Disparar hacia la izquierda
    * `L`: Disparar hacia la derecha
* **Objetivo:** Sobrevive a los obstáculos, derrota a todos los enemigos y vence al jefe final en el Nivel 3.

---

## 🧑‍💻 Autores

Este proyecto fue desarrollado por:

* **Carlos Daniel Rua Gutierrez**
* **Tomás Mesa Sánchez**

Como proyecto final para el curso de **Informática II** de la **Universidad de Antioquia**.

---

## 📄 Licencia

Este proyecto se distribuye bajo la Licencia MIT. Consulta el archivo `LICENSE` para más detalles.

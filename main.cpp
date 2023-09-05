/*Autor: Natalia Polo Peña
 * En el siguiente proyecto se ejecutan los problemas establecidos en la guia Lab1
 * Se implementan un menú y funciones para optimizar un poco más la entrega
*/


#include <iostream>
#include <cmath>
using namespace std;

void determinarTipoCaracter(char caracter) {
    // Convertir el carácter ingresado a minúscula para simplificar la comparación
    caracter = tolower(caracter);

    if ((caracter >= 'a' && caracter <= 'z') && (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u')) {
        cout << caracter << " es una vocal." << endl;
    } else if (caracter >= 'a' && caracter <= 'z') {
        cout << caracter << " es una consonante." << endl;
    } else {
        cout << "No es una letra." << endl;
    }
}

// Función para determinar la combinación de billetes y monedas
void calcularCombinacion(int cantidad) {
    int billetes[] = {50000, 20000, 10000, 5000, 2000, 1000};
    int monedas[] = {500, 200, 100, 50};
    int cantidadActual = cantidad;

    for (int i = 0; i < 6; i++) {
        int cantidadBillete = cantidadActual / billetes[i];
        cantidadActual %= billetes[i];
        cout << billetes[i] << " : " << cantidadBillete << endl;
    }

    for (int i = 0; i < 4; i++) {
        int cantidadMoneda = cantidadActual / monedas[i];
        cantidadActual %= monedas[i];
        cout << monedas[i] << " : " << cantidadMoneda << endl;
    }

    if (cantidadActual > 0) {
        cout << "Faltante: " << cantidadActual << endl;
    }
}
//funcion para determinar si un año es bisiesto o no
bool esBisiesto(int año) {
    // Un año es bisiesto si es divisible por 4 pero no es divisible por 100, o si es divisible por 400.
    return (año % 4 == 0 && año % 100 != 0) || (año % 400 == 0);
}

bool esFechaValida(int mes, int dia) {
    // Verificar si el mes está dentro del rango válido (1-12).
      if (mes<1 || mes>12) {
        return false;
    }

    // Arreglo que contiene la cantidad de días en cada mes, considerando un año no bisiesto.
    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Verificar si el día está dentro del rango válido para el mes.
    if (dia < 1 || dia > diasPorMes[mes]) {
        return false;
    }

    // Si el mes es febrero (mes 2) y el día es 29, verificar si es un año bisiesto.
    if (mes == 2 && dia == 29) {
        // Solicitar al usuario el año para verificar si es bisiesto.
        int año;
        std::cout << "Ingrese un año: ";
        std::cin >> año;
        return esBisiesto(año);
    }

    return true;
}
//funcion para leer dos  numeros enteros y representarlos en reloj

bool esTiempoValido(int tiempo) {
    int horas = tiempo / 100; // Extraer las horas del tiempo
    int minutos = tiempo % 100; // Extraer los minutos del tiempo

    return (horas >= 0 && horas <= 23) && (minutos >= 0 && minutos <= 59);
}

int sumarDuracion(int tiempo, int duracion) {
    int horasTiempo = tiempo / 100;
    int minutosTiempo = tiempo % 100;

    int horasDuracion = duracion / 100;
    int minutosDuracion = duracion % 100;

    int horasResultado = horasTiempo + horasDuracion;
    int minutosResultado = minutosTiempo + minutosDuracion;

    // Manejar el desbordamiento de minutos
    if (minutosResultado >= 60) {
        horasResultado += minutosResultado / 60;
        minutosResultado %= 60;
    }

    // Manejar el desbordamiento de horas
    horasResultado %= 24;

    return (horasResultado * 100) + minutosResultado;
}
//funcion para imprimir patron problema 6
void mostrarPatron(int n) {
    // Imprimir la parte superior del patrón (triángulo invertido)
    for (int i = 1; i <= n; i++) {
        // Imprimir espacios en blanco antes de los asteriscos
        for (int j = 1; j <= n - i; j++) {
            std::cout << " ";
        }

        // Imprimir asteriscos
        for (int k = 1; k <= 2 * i - 1; k++) {
            std::cout << "*";
        }

        // Cambiar de línea después de cada fila
        std::cout << std::endl;
    }

    // Imprimir la parte inferior del patrón (triángulo normal)
    for (int i = n - 1; i >= 1; i--) {
        // Imprimir espacios en blanco antes de los asteriscos
        for (int j = 1; j <= n - i; j++) {
            std::cout << " ";
        }

        // Imprimir asteriscos
        for (int k = 1; k <= 2 * i - 1; k++) {
            std::cout << "*";
        }

        // Cambiar de línea después de cada fila
        std::cout << std::endl;
    }
}
//funcion para calcular euler aproximado
double calcularEulerAproximado(int n) {
    double eulerAproximado = 1.0; // Inicializar con el primer término (1/0!)
    double termino = 1.0; // Inicializar con el primer término (1/0!)

    for (int i = 1; i <= n; i++) {
        termino /= i; // Calcular el siguiente término (1/n!)
        eulerAproximado += termino; // Sumar el término actual a la aproximación de e
    }

    return eulerAproximado;
}

// Función para calcular la suma de los números pares en la serie de Fibonacci menores a n
int sumaFibonacciPares(int n) {
    int a = 1;  // Primer número de la serie de Fibonacci
    int b = 1;  // Segundo número de la serie de Fibonacci
    int suma = 0;  // Inicializamos la suma en cero

    while (a + b < n) {
        int c = a + b;  // Calculamos el siguiente número de Fibonacci
        if (c % 2 == 0) {
            suma += c;  // Si es par, lo sumamos a la suma
        }
        a = b;  // Actualizamos a y b para el siguiente cálculo
        b = c;
    }

    return suma;
}
// Función para calcular la suma de los múltiplos de a y b menores que c
int sumaMultiplos(int a, int b, int c) {
    int suma = 0;

    // Iteramos desde a hasta c, sumando múltiplos de a
    for (int i = a; i < c; i += a) {
        suma += i;
    }

    // Iteramos desde b hasta c, sumando múltiplos de b que no sean múltiplos de a
    for (int i = b; i < c; i += b) {
        if (i % a != 0) {
            suma += i;
        }
    }

    return suma;
}
// Función para calcular la suma de los dígitos elevados a sí mismos
int sumaDigitosElevados(int n) {
    int suma = 0;

    while (n > 0) {
        int digito = n % 10; // Obtenemos el último dígito
        suma += pow(digito, digito); // Elevamos el dígito a sí mismo y lo sumamos a la suma
        n /= 10; // Eliminamos el último dígito
    }

    return suma;
}

int main() {
    int opcion = 0;

    while (opcion != 3) {
        cout << "Menu:" << endl;
        cout << "1. Determinar tipo de caracter" << endl;
        cout << "2. Calcular combinacion de billetes y monedas" << endl;
        cout << "3. Determinar si un year es bisiesto o no" << endl;
        cout << "4. Leer dos numeros enteros y representarlos en reloj" << endl;
        cout << "5. Imprimir patrón en pantalla" << endl;
        cout << "6. Aproximar a euler" << endl;
        cout << "7. Suma de numeros pares en la serie Fibonacci" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                char caracter;

                cout << "Ingrese un caracter: ";
                cin >> caracter;

                determinarTipoCaracter(caracter);
                break;
            }
            case 2: {
                int cantidad;

                cout << "Ingrese la cantidad de dinero: ";
                cin >> cantidad;

                calcularCombinacion(cantidad);
                break;
            }
            case 3:{
                int mes, dia;

                std::cout << "Ingrese el mes (1-12): ";
                std::cin >> mes;

                std::cout << "Ingrese el dia: ";
                std::cin >> dia;

                if (esFechaValida(mes, dia)) {
                    if (mes == 2 && dia == 29) {
                        std::cout << "29/2 es valida en bisiesto." << std::endl;
                    } else {
                        std::cout << mes << "/" << dia << " es una fecha valida." << std::endl;
                    }
                } else {
                    std::cout << mes << "/" << dia << " es una fecha invalida." << std::endl;
                    break;
                }
            }
                break;
            case 4:{
                int tiempo, duracion;

                std::cout << "Ingrese un tiempo en formato de 24 horas: ";
                std::cin >> tiempo;

                if (!esTiempoValido(tiempo)) {
                    std::cout << tiempo << " es un tiempo inválido." << std::endl;
                        return 1; // Salir con código de error
                }

                std::cout << "Ingrese una duración en formato de 24 horas: ";
                        std::cin >> duracion;

                if (!esTiempoValido(duracion)) {
                    std::cout << duracion << " es un tiempo inválido." << std::endl;
                        return 1; // Salir con código de error
                }

                int resultado = sumarDuracion(tiempo, duracion);

                std::cout << "La hora es " << resultado << "." << std::endl;
            }
            break;
            case 5:{
                int n = 4; // Número de filas en la parte superior del patrón (ajusta este valor según lo necesites)

                mostrarPatron(n);
            break;

            }
            case 6: {
                 int n; // Número de términos para la aproximación (ajusta este valor según lo necesites)
                 cout<<"Ingrese el numero de terminos para la aproximacion"<<endl;
                 cin>>n;

                 double eulerAproximado = calcularEulerAproximado(n);

                 cout << "El valor aproximado de Euler (e) con " << n << " términos es: " << eulerAproximado << std::endl;
            }
            break;
            case 7: {
                 int n;
                 cout << "Ingrese un número n: ";
                 cin >> n;

                 int resultado = sumaFibonacciPares(n);

                 cout << "El resultado de la suma es: " << resultado << std::endl;
            }
            break;
            case 8: {
                 int a, b, c;
                 cout << "Ingrese el valor de a: ";
                 cin >> a;
                 cout << "Ingrese el valor de b: ";
                 cin >> b;
                 cout << "Ingrese el valor de c: ";
                 cin >> c;

                 int resultado = sumaMultiplos(a, b, c);

                cout << "Resultado: ";

                 // Imprimir los múltiplos de a
                 for (int i = a; i < c; i += a) {
                        cout << "m" << i/a << a;
                        if (i + a < c) {
                        cout << " + ";
                        }
                 }

                 // Imprimir los múltiplos de b que no sean múltiplos de a
                 for (int i = b; i < c; i += b) {
                        if (i % a != 0) {
                        cout << "m" << i/b << b;
                        if (i + b < c) {
                            cout << " + ";
                        }
                        }
                 }

                cout << " = " << resultado << endl;
            }
            break;
            case 9: {
                int n;
                cout << "Ingrese un número entero N: ";
                cin >> n;

                int resultado = sumaDigitosElevados(n);

                std::cout << "El resultado de la suma es: " << resultado << endl;
            }

            }
    }

    return 0;
}





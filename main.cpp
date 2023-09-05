/*Autor: Natalia Polo Peña
 * En el siguiente proyecto se ejecutan los problemas establecidos en la guia Lab1
 * Se implementan un menú y funciones para optimizar un poco más la entrega
*/


#include <iostream>
#include <cmath>
#include <vector>
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
// Función para verificar si un año es bisiesto
bool esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

// Función para verificar si una fecha es válida
bool esFechaValida(int mes, int dia) {
    if (mes < 1 || mes > 12) {
        return false;
    }

    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && dia == 29) {
        // Si es el 29 de febrero, verifica si el año es bisiesto

        return esBisiesto(true);
    }

    if (dia < 1 || dia > diasPorMes[mes]) {
        return false;
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
            cout << " ";
        }

        // Imprimir asteriscos
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";
        }

        // Cambiar de línea después de cada fila
        cout << endl;
    }

    // Imprimir la parte inferior del patrón (triángulo normal)
    for (int i = n - 1; i >= 1; i--) {
        // Imprimir espacios en blanco antes de los asteriscos
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // Imprimir asteriscos
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";
        }

        // Cambiar de línea después de cada fila
        cout << endl;
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
// Función para verificar si un número es primo
bool esPrimo(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
// Función para encontrar el enésimo número primo
int encontrarPrimo(int n) {
    int contador = 0;
    int num = 2; // Empezamos desde el primer número primo

    while (contador < n) {
        if (esPrimo(num)) {
            contador++;
        }
        if (contador < n) {
            num++;
        }
    }

    return num;
}

// Función para calcular el máximo común divisor (GCD) usando el algoritmo de Euclides
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Función para calcular el mínimo común múltiplo (LCM) de dos números
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Función para calcular el LCM de todos los números enteros entre 1 y n
int lcmDe1aN(int n) {
    int resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado = lcm(resultado, i);
    }
    return resultado;
}
// Función para calcular el máximo factor primo de un número
int maxFactorPrimo(int numero) {
    int maxFactor = -1; // Inicializamos el máximo factor primo como -1

    while (numero % 2 == 0) {
        maxFactor = 2;
        numero /= 2;
    }

    for (int i = 3; i * i <= numero; i += 2) {
        while (numero % i == 0) {
            maxFactor = i;
            numero /= i;
        }
    }

    if (numero > 1) {
        maxFactor = numero;
    }

    return maxFactor;
}



// Función para calcular la suma de todos los primos menores que n
int sumaPrimosMenores(int n) {
    int suma = 0;
    for (int i = 2; i < n; i++) {
        if (esPrimo(i)) {
            suma += i;
        }
    }
    return suma;
}
// Función para verificar si un número es palíndromo
bool esPalindromo(int numero) {
    int original = numero;
    int reverso = 0;

    while (numero > 0) {
        int digito = numero % 10;
        reverso = reverso * 10 + digito;
        numero /= 10;
    }

    return original == reverso;
}

// Función para encontrar el número palíndromo más grande como producto de números de 3 dígitos
int encontrarPalindromoMasGrande() {
    int palindromoMaximo = 0;

    for (int i = 100; i <= 999; i++) {
        for (int j = 100; j <= 999; j++) {
            int producto = i * j;
            if (producto < 100000) {
                continue;  // Ignorar productos menores a 100,000
            }
            if (producto > palindromoMaximo && esPalindromo(producto)) {
                palindromoMaximo = producto;
            }
        }
    }

    return palindromoMaximo;
}

//Función para calcular la suma de los números en la diagonal de una espiral de nxn
    int sumaDiagonalEspiral(int n, bool imprimir) {
    if (n % 2 == 0) {
        cout << "El número ingresado debe ser impar." << endl;
            return 0;
    }

    std::vector<std::vector<int>> espiral(n, std::vector<int>(n));

    int valor = 1;
    int x = n / 2;
    int y = n / 2;
    int sumaDiagonal = 0;

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < 2 * i + 1; j++) {
            espiral[y][x] = valor++;
            x++;
        }
        x--;
        y--;

        for (int j = 0; j < 2 * i + 2; j++) {
            espiral[y][x] = valor++;
            y--;
        }
        y++;
        x--;

        for (int j = 0; j < 2 * i + 2; j++) {
            espiral[y][x] = valor++;
            x--;
        }
        x++;
        y++;

        for (int j = 0; j < 2 * i + 3; j++) {
            espiral[y][x] = valor++;
            y++;
        }
        y--;
        x++;
    }

    // Llenar el centro de la espiral
    espiral[y][x] = valor;

    // Calcular suma de la diagonal
    for (int i = 0; i < n; i++) {
        sumaDiagonal += espiral[i][i];
        sumaDiagonal += espiral[i][n - 1 - i];
    }
    sumaDiagonal -= espiral[n / 2][n / 2]; // Restar el valor central si n es impar

    // Imprimir espiral
    if (imprimir) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << espiral[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    return sumaDiagonal;
}
// Función para calcular la longitud de la serie de Collatz para una semilla dada
int longitudCollatz(long long semilla) {
    int longitud = 1;
    while (semilla != 1) {
        if (semilla % 2 == 0) {
            semilla /= 2;
        } else {
            semilla = 3 * semilla + 1;
        }
        longitud++;
    }
    return longitud;
}

// Función para encontrar la semilla que produce la serie más larga menor que k
long long encontrarSemillaMasLarga(long long k, int& maxLongitud) {
    long long semillaMasLarga = 0;
    maxLongitud = 0;

    for (long long i = 2; i < k; i++) {
        int longitud = longitudCollatz(i);
        if (longitud > maxLongitud) {
            maxLongitud = longitud;
            semillaMasLarga = i;
        }
    }

    return semillaMasLarga;
}

// Función para imprimir la serie de Collatz para una semilla dada
void imprimirCollatz(long long semilla) {
     cout << semilla;
    while (semilla != 1) {
        if (semilla % 2 == 0) {
            semilla /= 2;
        } else {
            semilla = 3 * semilla + 1;
        }
         cout << ", " << semilla;
    }
     cout << endl;
}

// Función para contar la cantidad de divisores de un número
int contarDivisores(int numero) {
     int contador = 0;
     for (int i = 1; i <= numero; i++) {
         if (numero % i == 0) {
            contador++;
         }
     }
     return contador;
}

// Función para encontrar el primer número triangular con más de k divisores
int encontrarPrimerTriangularConDivisores(int k) {
     int n = 1; // Iniciar con el primer número triangular
     int numeroTriangular = 0;

     while (true) {
         numeroTriangular = n * (n + 1) / 2;
         int divisores = contarDivisores(numeroTriangular);

         if (divisores > k) {
            return numeroTriangular;
         }

         n++;
     }
}

int main() {
    int opcion = 0;

    while (opcion != 3) {
        cout << "*******************Menu***************:" << endl;
        cout << "1. Determinar tipo de caracter" << endl;
        cout << "2. Calcular combinacion de billetes y monedas" << endl;
        cout << "3. Determinar si un year es bisiesto o no" << endl;
        cout << "4. Leer dos numeros enteros y representarlos en reloj" << endl;
        cout << "5. Imprimir patrón en pantalla" << endl;
        cout << "6. Aproximar a euler" << endl;
        cout << "7. Suma de numeros pares en la serie Fibonacci" << endl;
        cout << "8. Imprimir los multiplos de a, b y c" << endl;
        cout << "9. Suma de los digitos elevados a si mismos" << endl;
        cout << "10.Encontrar el numero primo de n" << endl;
        cout << "11.Minimo comun multiplo" << endl;
        cout << "12.Maximo factor primo" << endl;
        cout << "13.Suma de los primos menores que el numero ingresado" << endl;
        cout << "14.Palindromo" << endl;
        cout << "15.Suma diagonal matriz" << endl;
        cout << "16.Encontrar la semilla mas larga" << endl;
        cout << "17.Primer tirangular con divisores" << endl;
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

                cout << "Ingrese el mes (1-12): ";
                cin >> mes;

                cout << "Ingrese el dia: ";
                cin >> dia;

                if (esFechaValida(mes, dia)) {
                if (mes == 2 && dia == 29) {
                      cout << "29/2 es válida en año bisiesto." << endl;
                } else {
                      cout << mes << "/" << dia << " es una fecha válida." << endl;
                }
                } else {
                     cout << mes << "/" << dia << " es una fecha inválida." << endl;
                }
            }
            break;
            case 4:{
                int tiempo, duracion;

                cout << "Ingrese un tiempo en formato de 24 horas: ";
                cin >> tiempo;

                if (!esTiempoValido(tiempo)) {
                    cout << tiempo << " es un tiempo inválido." << endl;
                        return 1; // Salir con código de error
                }

                cout << "Ingrese una duración en formato de 24 horas: ";
                        cin >> duracion;

                if (!esTiempoValido(duracion)) {
                    cout << duracion << " es un tiempo inválido." << endl;
                        return 1; // Salir con código de error
                }

                int resultado = sumarDuracion(tiempo, duracion);

                cout << "La hora es " << resultado << "." << endl;
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

                 cout << "El valor aproximado de Euler (e) con " << n << " términos es: " << eulerAproximado <<endl;
            }
            break;
            case 7: {
                 int n;
                 cout << "Ingrese un número n: ";
                 cin >> n;

                 int resultado = sumaFibonacciPares(n);

                 cout << "El resultado de la suma es: " << resultado <<endl;
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

                cout << "El resultado de la suma es: " << resultado << endl;
            }
            break;
            case 10: {
                int n;
                cout << "Ingrese un numero n: ";
                cin >> n;

                int primo = encontrarPrimo(n);

                cout << "El primo numero " << n << " es: " << primo << endl;
            }
            break;
            case 11: {
                int numero;
                cout << "Ingrese un numero: ";
                cin >> numero;

                int resultado = lcmDe1aN(numero);

                cout << "El minimo comun multiplo es: " << resultado << endl;
            }
            break;
            case 12: {
                int numero;
                cout << "Ingrese un numero: ";
                cin >> numero;

                int maxFactor = maxFactorPrimo(numero);

                cout << "El mayor factor primo de " << numero << " es: " << maxFactor << endl;
            }
            break;
            case 13: {
                int numero;
                cout << "Ingrese un numero: ";
                cin >> numero;

                int resultado = sumaPrimosMenores(numero);

                cout << "El resultado de la suma es: " << resultado << endl;
            }
            break;
            case 14: {
                int resultado = encontrarPalindromoMasGrande();

                cout << "El número palíndromo más grande como producto de números de 3 dígitos es: " << resultado <<endl;
            }
            break;
            case 15: {
                int n;
                cout << "Ingrese un numero impar n para la espiral: ";
                cin >> n;

                int suma = sumaDiagonalEspiral(n, true);

                cout << "En una espiral de " << n << "x" << n << ", la suma es: " << suma <<endl;
            }
            break;
            case 16: {
                long long k;
                cout << "Ingrese un numero k: ";
                cin >> k;

                int maxLongitud;
                long long semilla = encontrarSemillaMasLarga(k, maxLongitud);

                cout << "La serie más larga es con la semilla: " << semilla << ", teniendo " << maxLongitud << " terminos." <<endl;

                           cout << "La serie es: ";
                imprimirCollatz(semilla);
            }
            break;
            case 17: {
                int k;
                cout << "Ingrese un número k: ";
                cin >> k;

                int resultado = encontrarPrimerTriangularConDivisores(k);

                cout << "El primer número triangular con más de " << k << " divisores es: " << resultado <<endl;
            }


            }
    }

    return 0;
}





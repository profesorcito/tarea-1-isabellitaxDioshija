#include <iostream>

using namespace std;

// Función para calcular la suma de los dígitos de un número
int sumaDigitos(int n) {
    int sumarDig = 0;
    while (n > 0) {
        sumarDig += n % 10;
        n /= 10;
    }
    return sumarDig;
}

// Función para calcular la tarifa
double calcularTarifa(int horas, int dia) {
    const double TARIFA_PRIMERA_HORA = 6.00;
    const double TARIFA_1_A_3 = 4.00;
    const double TARIFA_3_A_5 = 3.00;
    const double TARIFA_FIJA = 22.00;
    const int LIMITE_HORAS = 24;
    const double INCREMENTO_FIN_SEMANA = 1.15;
    const double DESCUENTO_DIGITOS = 0.95;

    // Validar límite de horas
    if (horas > LIMITE_HORAS) {
        return -1;
    }

    double totalPagar = 0.0;

    // Cálculo de la tarifa base
    if (horas == 1) {
        totalPagar = TARIFA_PRIMERA_HORA;
    } else if (horas > 1 && horas <= 3) {
        totalPagar = TARIFA_PRIMERA_HORA + (horas - 1) * TARIFA_1_A_3;
    } else if (horas > 3 && horas <= 5) {
        totalPagar = TARIFA_PRIMERA_HORA + 2 * TARIFA_1_A_3 + (horas - 3) * TARIFA_3_A_5;
    } else {
        totalPagar = TARIFA_FIJA;
    }

    // Aplicar incremento si es fin de semana (sábado = 6, domingo = 7)
    if (dia == 6 || dia == 7) {
        totalPagar *= INCREMENTO_FIN_SEMANA;
    }

    // Aplicar descuento si la suma de los dígitos de las horas es múltiplo de 3
    if (sumaDigitos(horas) % 3 == 0) {
        totalPagar *= DESCUENTO_DIGITOS;
    }

    return totalPagar;
}

int main() {
    int horas, dia;

    // Leer los valores de entrada
    cin >> horas >> dia;

    double resultado = calcularTarifa(horas, dia);
    if (resultado == -1) {
        cout << "ERROR" << endl;
    } else {
        printf("%.2f\n", resultado);
    }

    return 0;
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
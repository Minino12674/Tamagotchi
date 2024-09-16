#include <ncurses.h>

// Función para inicializar colores
void inicializarColores()
{
    start_color(); // Inicializar colores

    // Definir colores personalizados
    init_color(1, 1000, 500, 0);  // Naranja (RGB: 255, 128, 0)
    init_color(2, 1000, 0, 1000); // Rosa (RGB: 255, 0, 255)
    init_color(3, 0, 0, 0);       // Negro (RGB: 0, 0, 0)

    // Definir pares de colores
    init_pair(1, 1, 3); // Naranja con fondo negro
    init_pair(2, 2, 3); // Rosa con fondo negro
    init_pair(3, 3, 3); // Negro con fondo negro
    init_pair(4, COLOR_WHITE, COLOR_WHITE);
}

void dibujarMatriz(char matriz[5][5])
{
    clear(); // Limpiar la pantalla
    char cuadro = '#';

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            switch (matriz[i][j])
            {
            case '2':
                attron(COLOR_PAIR(1)); // Naranja
                break;
            case '1':
                attron(COLOR_PAIR(2)); // Rosa
                break;
            case '#':
                attron(COLOR_PAIR(3)); // Negro
                break;
            default:
                attron(COLOR_PAIR(3)); // Por defecto, negro
                break;
            }
            mvprintw(i, j * 2, "%c", cuadro); // Imprimir el carácter
            attroff(COLOR_PAIR(1));           // Apagar color de Naranja
            attroff(COLOR_PAIR(2));           // Apagar color de Rosa
            attroff(COLOR_PAIR(3));           // Apagar color de Negro
        }
    }

    refresh(); // Actualizar la pantalla
}

int main()
{
    initscr();            // Inicializar la pantalla
    curs_set(FALSE);      // Ocultar el cursor
    keypad(stdscr, TRUE); // Habilitar el manejo de teclas especiales
    noecho();             // No mostrar caracteres ingresados

    inicializarColores(); // Inicializar colores

    // Definir una matriz de ejemplo
    char matriz[5][5] = {
        {'1', '2', '1', '#', '2'},
        {'2', '1', '#', '1', '2'},
        {'#', '2', '1', '2', '1'},
        {'1', '#', '2', '1', '#'},
        {'2', '1', '#', '2', '1'}};

    dibujarMatriz(matriz); // Dibujar la matriz

    getch();  // Esperar a que se presione una tecla
    endwin(); // Terminar NCurses

    return 0;
}

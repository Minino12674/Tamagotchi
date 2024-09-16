#include <ncurses.h>
#include <unistd.h>  // Para usleep()

void dibujarTamagotchi(int frame) {
    clear();  // Limpiar la pantalla

    // Usar combinación de colores 1 para la cara
    attron(COLOR_PAIR(1));
    mvprintw(5, 10, "(");
    attroff(COLOR_PAIR(1));  // Desactivar el color para la cara

    // Usar combinación de colores 4 para los ojos (naranja claro)
    attron(COLOR_PAIR(4));
    if (frame == 0) {
        mvprintw(5, 11, "> #");  // Ojos abiertos
    } else {
        mvprintw(5, 11, "0 0");  // Ojos diferentes
    }
    attroff(COLOR_PAIR(4));  // Desactivar el color de los ojos

    // Volver al color de la cara
    attron(COLOR_PAIR(1));
    mvprintw(5, 14, ")");
    attroff(COLOR_PAIR(1));  // Desactivar el color de la cara

    refresh();
}

int main() {
    initscr();
    start_color();  // Inicializar soporte de colores
    curs_set(FALSE);  // Ocultar cursor
    nodelay(stdscr, TRUE);  // No esperar entrada del usuario

    if (has_colors() && can_change_color()) {
        // Definir un color personalizado: naranja claro (RGB: 1000, 500, 0)
        init_color(5, 1000, 500, 0);  // El color 10 es naranja claro
        init_color(6, 121, 121, 188);

        // Definir combinaciones de colores
        init_pair(1, COLOR_WHITE, 6);  // Color de la cara (blanco sobre fondo azul)
        init_pair(2, COLOR_WHITE, 6);  // Fondo azul
        init_pair(4, 5, 6);  // Ojos en naranja claro (color 10 sobre azul)
    } else {
        printw("Tu terminal no soporta colores personalizados.\n");
        getch();
        endwin();
        return 1;
    }

    // Cambiar el fondo de la pantalla a azul
    bkgd(COLOR_PAIR(2));  

    int frame = 0;
    while (true) {
        if (getch() == 'q') {  // Presionar 'q' para salir
            break;
        }

        dibujarTamagotchi(frame);  // Dibujar Tamagotchi

        frame = (frame + 1) % 2;

        usleep(500000);  // Esperar 0.5 segundos
    }

    endwin();  // Terminar ncurses
    return 0;
}

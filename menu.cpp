#include <ncurses.h>
#include <unistd.h>

using namespace std;

int main()
{
    initscr();
    start_color();         // Inicializar soporte de colores
    curs_set(FALSE);       // Ocultar cursor
    keypad(stdscr, TRUE);
    noecho();

    while (true)
    {
        
    }

    return 0;
}
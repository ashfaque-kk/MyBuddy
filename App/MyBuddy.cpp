#include <ncurses.h>
#include <string>
#include <vector>

void draw_menu_bar(WINDOW* menu_win, const std::vector<std::string>& menus, int highlight) {
    werase(menu_win);
    box(menu_win, 0, 0);
    int x = 2;
    for (size_t i = 0; i < menus.size(); ++i) {
        if ((int)i == highlight)
            wattron(menu_win, A_REVERSE);
        mvwprintw(menu_win, 1, x, "%s", menus[i].c_str());
        wattroff(menu_win, A_REVERSE);
        x += menus[i].size() + 6;
    }
    wrefresh(menu_win);
}

void draw_task_window(WINDOW* task_win, const std::vector<std::string>& tasks) {
    werase(task_win);
    box(task_win, 0, 0);
    mvwprintw(task_win, 0, 2, " Tasks ");
    for (size_t i = 0; i < tasks.size(); ++i) {
        mvwprintw(task_win, i + 1, 2, "[%zu] %s", i + 1, tasks[i].c_str());
    }
    wrefresh(task_win);
}

void draw_status_bar(WINDOW* status_win, const std::string& msg) {
    werase(status_win);
    wattron(status_win, A_REVERSE);
    mvwprintw(status_win, 0, 1, "%s", msg.c_str());
    wattroff(status_win, A_REVERSE);
    wrefresh(status_win);
}

// Helper function to find menu item clicked by mouse
int get_menu_index_at(int mouse_x, const std::vector<std::string>& menus) {
    int x = 2;
    for (size_t i = 0; i < menus.size(); ++i) {
        int start_x = x;
        int end_x = x + (int)menus[i].size() - 1;
        if (mouse_x >= start_x && mouse_x <= end_x) {
            return i;
        }
        x += menus[i].size() + 6;
    }
    return -1;  // no menu clicked
}

int main() {
    initscr();              // Initialize ncurses
    cbreak();               // Disable line buffering
    noecho();               // Don't echo keys
    keypad(stdscr, TRUE);   // Enable function/arrow keys
    curs_set(0);            // Hide cursor
    start_color();          // Enable colors
    use_default_colors();

    // Enable mouse events
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    int height, width;
    getmaxyx(stdscr, height, width);

    // Define window sizes
    WINDOW* menu_win   = newwin(3, width, 0, 0);
    WINDOW* task_win   = newwin(height - 5, width, 3, 0);
    WINDOW* status_win = newwin(1, width, height - 1, 0);

    // Menu items
    std::vector<std::string> menus = {"File", "Edit", "Help"};
    int highlight = 0;

    // Example tasks
    std::vector<std::string> tasks = {
        "Finish project report (Due: 2025-11-10)",
        "Pay electricity bill (Due: 2025-11-08)",
        "Schedule dentist appointment"
    };

    draw_menu_bar(menu_win, menus, highlight);
    draw_task_window(task_win, tasks);
    draw_status_bar(status_win, "Use ← → to navigate, Click menu | q to quit");

    MEVENT event;
    int ch;
    while ((ch = getch()) != 'q') {
        switch (ch) {
            case KEY_LEFT:
                highlight = (highlight == 0) ? menus.size() - 1 : highlight - 1;
                break;
            case KEY_RIGHT:
                highlight = (highlight + 1) % menus.size();
                break;
            case KEY_MOUSE:
                if (getmouse(&event) == OK) {
                    // Only react to mouse left click
                    if (event.bstate & BUTTON1_CLICKED) {
                        // Check if click is in menu window's height (y=0,1,2)
                        if (event.y >= 1 && event.y <= 1) {
                            int clicked_index = get_menu_index_at(event.x, menus);
                            if (clicked_index != -1) {
                                highlight = clicked_index;
                                if (menus[highlight] == "Help")
                                    draw_status_bar(status_win, "Help: q=Quit, ←/→=Move, Click=Select");
                                else
                                    draw_status_bar(status_win, "Selected: " + menus[highlight]);
                            }
                        }
                    }
                }
                break;
            case 10: // Enter key
                if (menus[highlight] == "Help")
                    draw_status_bar(status_win, "Help: q=Quit, ←/→=Move, Enter=Select");
                else
                    draw_status_bar(status_win, "Selected: " + menus[highlight]);
                break;
        }

        draw_menu_bar(menu_win, menus, highlight);
        draw_task_window(task_win, tasks);
    }

    endwin();  // Restore normal terminal
    return 0;
}

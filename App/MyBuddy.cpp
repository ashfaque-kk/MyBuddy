#include <ncurses.h>
#include <fstream>
#include <string>
#include <vector>

struct Task {
    std::string description;
    bool done;
};

std::vector<Task> tasks;
const std::string FILENAME = "tasks.txt";

void loadTasks() {
    std::ifstream file(FILENAME);
    tasks.clear();
    if (!file.is_open()) return;

    std::string line;
    while (getline(file, line)) {
        if (line.size() > 2) {
            bool done = (line[0] == '1');
            std::string desc = line.substr(2);
            tasks.push_back({desc, done});
        }
    }
    file.close();
}

void saveTasks() {
    std::ofstream file(FILENAME);
    for (auto &t : tasks) {
        file << (t.done ? '1' : '0') << " " << t.description << "\n";
    }
    file.close();
}

void displayTasks(int highlight) {
    clear();
    for (int i = 0; i < tasks.size(); i++) {
        if (i == highlight)
            attron(A_REVERSE);
        mvprintw(i, 0, "[%c] %s", tasks[i].done ? 'x' : ' ', tasks[i].description.c_str());
        if (i == highlight)
            attroff(A_REVERSE);
    }
    mvprintw(tasks.size() + 1, 0, "Press 'a' to add, 'd' to delete, 't' to toggle, 'q' to quit");
    refresh();
}

int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    loadTasks();

    int highlight = 0;
    int ch;

    while (true) {
        displayTasks(highlight);
        ch = getch();

        if (ch == 'q') {
            saveTasks();
            break;
        } else if (ch == KEY_UP) {
            if (highlight > 0) highlight--;
        } else if (ch == KEY_DOWN) {
            if (highlight < tasks.size() - 1) highlight++;
        } else if (ch == 'a') {
            echo();
            char buf[256];
            mvprintw(tasks.size() + 2, 0, "Enter new task: ");
            getnstr(buf, 255);
            noecho();
            tasks.push_back({std::string(buf), false});
        } else if (ch == 'd' && !tasks.empty()) {
            tasks.erase(tasks.begin() + highlight);
            if (highlight >= tasks.size() && highlight > 0) highlight--;
        } else if (ch == 't' && !tasks.empty()) {
            tasks[highlight].done = !tasks[highlight].done;
        }
    }

    endwin();
    return 0;
}

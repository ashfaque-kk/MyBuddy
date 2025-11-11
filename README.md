# MyBuddy

A simple terminal-based task manager with a GUI-like interface. This app is created to demonstrate how  our tui library works as well.

## Screenshot

![App Screenshot](Assets/Screenshot/Screenshot.png)


## Features

-  Note Down Important task [WIP]
## Requirements

- Linux or Unix-like OS terminal
- `ncurses` library installed
- C++17 compatible compiler (e.g., `g++`, `clang++`)

## Building

1. Clone the repository
2. Build:
```
mkdir Build && cd Build
cmake ..
make clean all
```

## Running

Run the executable:
1. Go to Build/bin directory
2. Execute:
```
./MyBuddy
```

## Usage

- Use **left/right arrow keys** to highlight different menu options.
- Press **Enter** to select a menu.
- Click on menu items with the **left mouse button** to select them.
- Press **`q`** to exit the application.

## Notes

- Mouse support requires a terminal that supports mouse events (e.g., `xterm`, `gnome-terminal`).
- The program currently only supports mouse clicks on the menu bar.


## Future Enhancements

- Add task creation, deletion, and editing via menus
- Support mouse interaction within task list window
- Save and load tasks to/from disk
- Add reminders and due dates UI
- Implement dropdown menus

## License

- Take it, break it, improve it… just don’t blame me if it explodes!"_ 💥 
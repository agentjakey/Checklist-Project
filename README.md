# Vice Vault

> A 3D-printed physical lockbox controlled by a motor-driven locking mechanism that releases only when every task on your checklist is complete.

---

## What Is It?

Vice Vault is a hardware + software accountability system. You place your phone, or any other distraction you want to "lock away", inside a 3D-printed box. The box stays physically locked until every item on your task list is marked complete. Once the checklist clears, the motor disengages and the lid releases.

The software side is a C++ console application (`Checklist Project.cpp`) that manages the todo list state and communicates completion status to the hardware controller.

---

## How It Works

```
┌──────────────────────────────────────────────────────────┐
│                       USER FLOW                          │
│                                                          │
│  1. Add tasks to the checklist                           │
│  2. Place item inside the Vice Vault, close lid          │
│  3. Hardware motor locks the box                         │
│  4. Complete all tasks → mark each [c]omplete in CLI     │
│  5. All tasks done → motor unlocks → lid releases        │
└──────────────────────────────────────────────────────────┘
```

### Software (C++ Console App)

The CLI app runs a continuous loop with three operations:

| Command | Action |
|---------|--------|
| `a` | Add a new todo item (auto-assigned random ID) |
| `c` | Mark a todo item as complete by ID |
| `q` | Quit the program |

Each `TodoItem` holds:
- A randomly generated integer ID (1–100)
- A text description
- A boolean completion flag

When all items are marked complete, the lock signal fires.

### Hardware

- **Enclosure**: Custom 3D-printed PLA box designed to hold a phone or similar object, with a hidden compartment to hold circuit and motors
- **Actuator**: Servo or DC motor controlling a physical locking bar or latch
- **Controller**: Microcontroller (Arduino-compatible) reading serial/GPIO signals from the host machine
- **Power**: USB or dedicated 5V supply

---

## Project Structure

```
Checklist-Project/
├── Checklist Project/
│   └── Checklist Project.cpp      # Main application logic
├── Checklist Project.slnx         # Visual Studio solution file
├── .gitignore
└── .gitattributes
```

---

## Getting Started

### Prerequisites

- Windows (uses `system("cls")` for terminal clearing)
- Visual Studio 2022 or later
- A C++17-compatible compiler

### Build & Run

1. Clone the repository
   ```bash
   git clone https://github.com/agentjakey/Checklist-Project.git
   ```

2. Open `Checklist Project.slnx` in Visual Studio

3. Build with `Ctrl + F5` (Run without Debugging) or press **F5** for Debug mode

4. The console app will launch. Use `a`, `c`, and `q` to interact.

---

## Roadmap

- [ ] Persistent task storage (save/load from file)
- [ ] Serial communication to hardware controller on task completion
- [ ] Unique deterministic IDs (replace `rand()` with UUID or sequential counter)
- [ ] Multi-session support: tasks survive program restart
- [ ] Web UI / companion app for task management
- [ ] Bluetooth or alternative unlock as an emergency override
- [ ] Timer mode: lock for a fixed duration regardless of task state

---

## Known Limitations

- IDs are generated with `rand() % 100 + 1` so collisions are possible with more than ~10 items
- Task list resets on every program exit (no persistence yet)
- `system("cls")` is Windows-only; Linux/macOS builds need `system("clear")`

---

## Contributing

Pull requests are welcome. For major changes, open an issue first to discuss what you'd like to change.

---

## Authors

- **Jacob O.** ([@agentjakey](https://github.com/agentjakey)) - software + UI
- **Jacob P.** ([@j7powell1](https://github.com/j7powell1)) - original fork / hardware + C++
- **Kai** - hardware + design

---

## License

MIT

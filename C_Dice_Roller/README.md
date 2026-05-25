# 🎲 C Dice Roller

A lightweight, robust, and interactive CLI dice roller written in modern C (C23). Designed for tabletop gamers and developers who need a quick, reliable way to generate random dice rolls with flexible configurations.

## ✨ Features

- **Customizable Dice:** Roll dice with any number of sides (D8, D10, D12, D20, ...).
- **Batch Rolling:** Roll multiple dice at once and see individual results.
- **Interactive CLI:** Smart input handling with sensible defaults (6-sided die, 1 roll).
- **Result Summaries:** Automatically calculates the total sum of all rolls.
- **Safety First:** Robust input validation and memory management.
- **Modern Standards:** Built using the **C23** standard with strict compiler flags for reliability.

## 🛠️ Prerequisites

To build and run this project, you'll need:
- A C compiler (e.g., `gcc` or `clang`) with C23 support.
- `make` build utility.

## 🚀 Getting Started

### 1. Installation
Clone the repository to your local machine:
```bash
git clone https://github.com/keuwey/C_Projects.git
cd C_Projects/C_Dice_Roller
```

### 2. Building the Project
The project uses a `Makefile` to simplify the build process.

**Development Build (with Debug Symbols & Sanitizers):**
```bash
make dev
```

**Release Build (Optimized for performance):**
```bash
make release
```

### 3. Running the Application
You can run the application directly using `make` commands:

**Run Development Version:**
```bash
make run
```

**Run Release Version:**
```bash
make run-release
```

## 📖 Usage

Upon running the program, follow the interactive prompts:
1. **Sides:** Enter the number of sides for the die (e.g., `20` for a d20). Press `Enter` to use the default (6).
2. **Count:** Enter how many times you want to roll the die. Press `Enter` to use the default (1).

**Example Output:**
```text
--- C Dice Roller ---
How many sides does the die have? (default 6): 20
How many times to roll? (default 1): 4

Rolling 4d20...
Results: [18, 4, 12, 9]
Total: 43
```

## 📂 Project Structure

- `src/`: Contains the source code (`main.c`).
- `bin/`: Compiled executables (`app` for release, `app_dev` for development).
- `build/`: Temporary object files generated during compilation.
- `Makefile`: Build configuration and utility scripts.

## 🔧 Development

The development environment is configured with strict safety checks:
- `-std=c23`: Uses the latest C standard.
- `-fsanitize=address,undefined`: Detects memory leaks and undefined behavior at runtime.
- `-Wall -Wextra -Werror`: Ensures high code quality by treating all warnings as errors.

To clean up build artifacts:
```bash
make clean
```

---
*Created with ❤️ by Keuwey*

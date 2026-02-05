# Chess Game in C

A fully-featured command-line chess implementation written in C, developed as part of a Programming 1 course project.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Game Rules](#game-rules)
- [Technical Details](#technical-details)
- [Documentation](#documentation)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Overview

This project implements a complete chess game in C with standard chess rules including piece movement validation, check detection, checkmate, stalemate, and draw conditions. The game is played through a command-line interface and demonstrates fundamental programming concepts including data structures, algorithms, and game logic implementation.

## ✨ Features

- **Complete Chess Rules Implementation**
  - All standard piece movements (King, Queen, Rook, Bishop, Knight, Pawn)
  - Special moves: Castling, En Passant, Pawn Promotion
  - Check and Checkmate detection
  - Stalemate detection
  - Draw conditions (50-move rule, threefold repetition, insufficient material)

- **Game Management**
  - Two-player local gameplay
  - Move validation
  - Turn-based system
  - Game state tracking
  - Move history

- **User Interface**
  - ASCII-based chessboard display
  - Coordinate-based move input (e.g., e2 e4)
  - Clear move feedback and error messages
  - Current game status display

## 📁 Project Structure

```
Chess/
├── include/           # Header files (.h)
│   └── ...           # Game logic, board representation, move validation headers
├── src/              # Source files (.c)
│   └── ...           # Implementation of game logic and main program
├── Makefile          # Build configuration
├── .gitignore        # Git ignore rules
├── README.md         # This file
├── Programming_1_Project.pdf      # Original project specification
├── Stalmate_and_draw.pdf         # Stalemate and draw rules documentation
└── chess_project.pdf             # Additional project documentation
```

## 🔧 Prerequisites

To build and run this project, you need:

- GCC (GNU Compiler Collection) or any C compiler
- Make utility
- Linux/Unix environment (or WSL on Windows)

## 🚀 Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/youssefelganini/Chess.git
   cd Chess
   ```

2. **Build the project**
   ```bash
   make
   ```

3. **Run the game**
   ```bash
   ./chess
   ```

## 🎮 Usage

### Starting a Game

Run the compiled executable:
```bash
./chess
```

### Making Moves

Moves are entered using algebraic notation with coordinates:
```
Enter move: e2 e4
```

Format: `[source] [destination]`
- Source: Starting square (e.g., e2)
- Destination: Target square (e.g., e4)

### Example Game Session

```
  a b c d e f g h
8 ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜
7 ♟ ♟ ♟ ♟ ♟ ♟ ♟ ♟
6 . . . . . . . .
5 . . . . . . . .
4 . . . . . . . .
3 . . . . . . . .
2 ♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙
1 ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖

White's turn
Enter move: e2 e4
```

### Special Commands

- Type your move in the format shown above
- Follow on-screen prompts for pawn promotion
- The game automatically detects check, checkmate, and stalemate

## 📖 Game Rules

This implementation follows standard FIDE chess rules:

### Piece Movements
- **King**: One square in any direction
- **Queen**: Any number of squares in any direction
- **Rook**: Any number of squares horizontally or vertically
- **Bishop**: Any number of squares diagonally
- **Knight**: L-shape (2 squares in one direction, 1 square perpendicular)
- **Pawn**: Forward one square (two on first move), captures diagonally

### Special Rules
- **Castling**: King moves two squares toward a rook
- **En Passant**: Pawn captures pawn that moved two squares
- **Pawn Promotion**: Pawn reaching the opposite end promotes to Queen, Rook, Bishop, or Knight

### Game End Conditions
- **Checkmate**: King is in check with no legal moves
- **Stalemate**: No legal moves but not in check
- **Draw**: By agreement, insufficient material, 50-move rule, or threefold repetition

## 🔬 Technical Details

### Data Structures
- **Board Representation**: 8x8 array structure
- **Piece Storage**: Character or enum-based piece identification
- **Move Validation**: Function-based validation for each piece type
- **Game State**: Struct containing board state, turn information, and move history

### Key Algorithms
- Legal move generation for each piece type
- Check detection algorithm
- Checkmate and stalemate detection
- Move validation pipeline

### Memory Management
- Static allocation for board structure
- Proper cleanup of dynamic memory (if used)
- Efficient move validation without excessive copying

## 📚 Documentation

Additional documentation is available in the repository:
- `Programming_1_Project.pdf` - Original project requirements and specifications
- `Stalmate_and_draw.pdf` - Detailed explanation of stalemate and draw conditions
- `chess_project.pdf` - Additional project documentation

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

### Areas for Improvement
- Add AI opponent with minimax algorithm
- Implement PGN (Portable Game Notation) file support
- Add save/load game functionality
- Improve UI with colored pieces or graphical display
- Add move hints and board evaluation
- Implement time controls
- Add undo/redo functionality

## 📝 License

This project is available for educational purposes. Please check with the repository owner for specific licensing terms.

## 👥 Authors

- **Youssef Elganini** - [GitHub Profile](https://github.com/youssefelganini)
- **Adham Hamada** - [GitHub Profile](https://github.com/adham-hamada)

## 🙏 Acknowledgments

- Programming 1 course instructors and teaching assistants
- Chess rules reference from FIDE (World Chess Federation)
- C programming community for best practices and guidance

## 📧 Contact

For questions or feedback, please open an issue on the GitHub repository or contact the repository owner.

---

**Note**: This is an educational project created as part of a Programming 1 course. It demonstrates fundamental programming concepts including data structures, algorithms, input validation, and game logic implementation in C.

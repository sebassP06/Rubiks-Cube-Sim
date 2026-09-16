# Rubiks-Cube-Sim
A 2D 3x3 Rubiks Cube simulator on the CLI

## Supported Platforms:
- Linux
- MacOS

# Installation

### Dependencies
- GCC
- ncurses-devel

## Building

```sh
git clone https://github.com/sebassP06/Rubiks-Cube-Sim.git
cd Rubiks-Cube-Sim
make
```

## Run
```sh
./cube
```

### Opening Files

```sh
./cube path/to/file.rbk
```

# Help

### Clockwise Rotations
- l  | Left
- r  | Right
- u  | Up
- d  | Down
- b  | Back

### Counterclockwise Rotations
- l' | Left
- r' | Right
- u' | Up
- d' | Down
- b' | Back

### Saving/Quiting
- q  | Exit Program
- w  | Save to new/existing file
- wq | Save to new/existing file and exit program

### Other
- mv    | Move cube with arrow keys or [wasd] | q or esc key to exit
- undo  | undos the previous rotation
- solve | resets the cube

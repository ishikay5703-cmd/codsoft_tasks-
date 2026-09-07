# CodSoft C++ Programming Internship — Task Submissions

This folder contains **5 separate, independently-compilable `.cpp` files**,
one per task, exactly as required by CodSoft's C++ Programming internship
task list.

| File | Task | Description |
|---|---|---|
| `Task1_NumberGuessingGame.cpp` | Task 1 | Random number guessing game with limited attempts and hints |
| `Task2_SimpleCalculator.cpp` | Task 2 | Basic arithmetic calculator (+, -, *, /) |
| `Task3_TicTacToeGame.cpp` | Task 3 | Console-based 2-player Tic-Tac-Toe with win/draw detection |
| `Task4_ToDoList.cpp` | Task 4 | Add / view / complete / remove tasks (menu-driven) |
| `Task5_ImageProcessingTool.cpp` | Task 5 | Load/display/filter/crop/resize/save 24-bit BMP images |

## How to compile & run each task

Each file is fully self-contained — no external libraries needed (Task 5
uses only the standard C++ library and reads/writes 24-bit BMP files
directly, so it needs no OpenCV or image SDKs).

```bash
g++ -std=c++17 -o Task1_NumberGuessingGame Task1_NumberGuessingGame.cpp
./Task1_NumberGuessingGame

g++ -std=c++17 -o Task2_SimpleCalculator Task2_SimpleCalculator.cpp
./Task2_SimpleCalculator

g++ -std=c++17 -o Task3_TicTacToeGame Task3_TicTacToeGame.cpp
./Task3_TicTacToeGame

g++ -std=c++17 -o Task4_ToDoList Task4_ToDoList.cpp
./Task4_ToDoList

g++ -std=c++17 -o Task5_ImageProcessingTool Task5_ImageProcessingTool.cpp
./Task5_ImageProcessingTool
```

All five were compiled with `-Wall -Wextra` and produced **zero warnings**,
and each was manually run through its main use cases to confirm correct
behavior before this submission.

## Task 5 note

Task 5 needs a **24-bit uncompressed BMP** as input (not JPG/PNG). To get
one quickly:
- Windows: open any image in Paint → "Save As" → "24-bit Bitmap (.bmp)"
- Or use an online PNG-to-BMP converter and choose 24-bit, uncompressed.

## Suggested submission steps (per CodSoft's usual process)

1. Push this folder (all 5 `.cpp` files) to a GitHub repository named
   `CODSOFT` (or similar), with one commit/README per task.
2. Record a short screen-recording demo of each program running.
3. Post the demo video on LinkedIn tagging **#codsoft** and mention the
   task/domain, then link your GitHub repo in the post.
4. Double-check the exact instructions in your offer-letter/task email —
   CodSoft sometimes asks for a minimum number of completed tasks (often
   3 of the 5) for the certificate, so confirm your batch's requirement.

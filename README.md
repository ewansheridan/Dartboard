# Dartboard

A command-line application for scoring a darts match between two players. This is a personal project, all code was written without the use of AI

## How to run
[]()
#### Compile the program

- Download the C source file to your computer, then compile it
- Any mainstream C compiler would work, I used gcc version 6.3.0 (MinGW.org GCC-6.3.0-1)

   ```bash
   gcc darts.c -o darts.exe
   ```

#### Using the application
- Enter the two player names, and a goal score

   ```plaintext
    Enter name for Player 1:
    >> John
    
    Enter name for Player 2:
    >> Paul
    
    Enter a goal score (We recommend 501)
    >> 501
   ```

- Enter scores for each player

   ```plaintext
  Now, John's turn:   (You require 501)
  
  Dart 1:
  >> T20
  That dart scored: 60
  
  Dart 2:
  >> T20
  That dart scored: 60
  
  Dart 3:
  >> T20
  That dart scored: 60
  
  In 3 darts, John scored 180
  John's score was 501, now it's 321
  ------------------------------------
  Now, Paul's turn:   (You require 501)
  
  Dart 1:
  >> S1
  That dart scored: 1
  
  Dart 2:
  >> S19
  That dart scored: 19
  
  Dart 3:
  >> D15
  That dart scored: 30
  
  In 3 darts, Paul scored 50
  Paul's score was 501, now it's 451
  ------------------------------------
  CURRENT SCORE: > John: 321
                  > Paul: 451
   ```

- You must finish on an exact score, and on a double...

   ```plaintext
  Now, John's turn:   (You require 41)
  
  Dart 1:
  >> s11
  That dart scored: 11
  
  Dart 2:
  >> s20
  That dart scored: 20
  
  Dart 3:
  >> s20
  That dart scored: 20
  John busted their score! No points scored.
  
  In 3 darts, John scored 0
  John's score was 41, now it's 41
  ------------------------------------
  Now, Paul's turn:   (You require 82)
  
  Dart 1:
  >> t20
  That dart scored: 60
  
  Dart 2:
  >> s11
  That dart scored: 11
  
  Dart 3:
  >> s11
  That dart scored: 11
  Paul busted their score! (must finish on a double) No points scored.
  
  In 3 darts, Paul scored 0
  Paul's score was 82, now it's 82
  ------------------------------------
  CURRENT SCORE:  > John: 41
                   > Paul: 82
   ```

- Until you find yourself a winner...

   ```plaintext
  Now, John's turn:   (You require 41)
  
  Dart 1:
  >> s1
  That dart scored: 1
  
  Dart 2:
  >> d20
  That dart scored: 40
  John wins!
   ```

## Features
- Error handling for badly formatted inputs
- Rules are enforced (finish on exact score, finish on double, etc.)
- Custom game length i.e. scores other than 501 allowed


## Scope and implementation notes

- A `Dart` struct is used to hold the dart's value and whether it's a double
- The three darts a user throws are stored in an array and are passed-by-reference to a function to enforce their score
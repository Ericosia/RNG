#include <iostream>
#include <random>
#include <chrono>



using std::cout, std::cin, std::endl, std::string;
using namespace std::chrono;

bool isEven_Odd(int rng) {
    if (rng % 2 == 0) {
        cout << "The number is even\n";
    } else if (rng % 2 == 1) {
        cout << "The number is odd\n";
    }
    return true;
}



bool isPrime(int rng) {
    if (rng <= 1) return false;
    for (int i = 2; i * i <= rng; ++i) {
        if (rng % i == 0) return false;
    }
    return true;
}

int main() {
    srand(time(0));
    int guesses, RNG, guess, chances, score, rand_hint, New_score;
    int highScoreEasy = INT_MAX;
    int highScoreMedium = INT_MAX;
    int highScoreHard = INT_MAX;
    char y = 'y', No_400;
    double guesses_percent;

    cout << "-----------------------------------\nWelcome to the RNG game.\nI'm thinking of a number between 1 and 100.\n";
        
        
        while (y == 'y' || y == 'Y') {
            RNG = rand() % 100 + 1;
                cout << "\nPlease select the difficulty level: ";
                cout << "\n1. Easy (10 chances)";
                cout << "\n2. Medium (5 chances)";
                cout << "\n3. Hard (3 chances)\n";
                cout << "\nEnter your choice: ";
                cin >> chances;
                
                if (chances == 1) {
                    cout << "\nGreat! You have selected the Easy difficulty level.\n" << "You have 10 chances to guess the correct number.\nLet's start the game!\n";
                    chances = 10;
                    
                } else if (chances == 2) {
                    cout << "\nGreat! You have selected the Medium difficulty level.\n" << "You have 5 chances to guess the correct number.\nLet's start the game!\n";
                    chances = 5;
                    
                } else if (chances == 3) {
                    cout << "\nGreat! You have selected the Hard difficulty level.\n" << "You have 3 chances to guess the correct number.\nLet's start the game!\n";
                    chances = 3;
                } else {
                    cout << "Invalid choice\n";
                    continue;
                }
            

            cout << "---------------------------------------------------\n";

            auto start_time = high_resolution_clock::now();
            int currentGuesses = 0;

            for (guesses = 1; guesses <= chances; guesses++) {
                rand_hint = rand() % 3;
                guesses_percent = (guesses * 100 )/ chances;
                cout << "Enter your guess: ";
                cin >> guess;
                
                currentGuesses++;
            
                if (guess > RNG) {
                        cout << "\nIncorrect! The number is less than " << guess << "\n";
                    } else if (guess < RNG) {
                        cout << "\nIncorrect! The number is more than " << guess << "\n";
                    } else if (guess == RNG) {
                        cout << "\nCongratulations! You guessed the correct number in " << guesses << " attempts.\n"; 
                        break;
                        
                    } 

                if (guesses_percent >= 50 && guesses < chances){
                        cout << "Do you want a hint (Y|N): ";
                        cin >> No_400;
                        if (No_400 == 'y' | No_400 == 'Y') {
                            if (rand_hint == 0) {
                                isEven_Odd(RNG);
                            }else if (rand_hint == 1){
                                isEven_Odd(RNG) && isPrime(RNG);
                            } else {
                                printf("NO hint for you\n");
                                continue;
                            }
                        }
                    }

                
                
            }
            score = guesses;
            if (chances == 10 && guess == RNG) {  // Easy difficulty
            if (currentGuesses < highScoreEasy) {
                highScoreEasy = currentGuesses;
                cout << "New High Score for Easy difficulty: " << highScoreEasy << " attempts!\n";
            } else {
                cout << "Your High Score for Easy difficulty is: " << highScoreEasy << " attempts.\n";
            }
        } else if (chances == 5 && guess == RNG) {  // Medium difficulty
            if (currentGuesses < highScoreMedium) {
                highScoreMedium = currentGuesses;
                cout << "New High Score for Medium difficulty: " << highScoreMedium << " attempts!\n";
            } else {
                cout << "Your High Score for Medium difficulty is: " << highScoreMedium << " attempts.\n";
            }
        } else if (chances == 3 && guess == RNG) {  // Hard difficulty
            if (currentGuesses < highScoreHard) {
                highScoreHard = currentGuesses;
                cout << "New High Score for Hard difficulty: " << highScoreHard << " attempts!\n";
            } else {
                cout << "Your High Score for Hard difficulty is: " << highScoreHard << " attempts.\n";
            }
        }            
            

            

            if (guesses > chances){
                cout << "You've ran out of attempts!\n" << "Try again(Y|N): ";
                cin >> y ;
            }
            if (guess == RNG) {
                cout << "Play again (Y|N): ";
                cin >> y;
            }
            
            
            auto end_time = high_resolution_clock::now();
            auto elapsed_time = duration_cast<seconds>(end_time - start_time).count();
            cout << "It took you " << elapsed_time << " seconds to complete the game.\n";

        } 
        if (score < New_score){
            New_score = score;
        }

        cout << "Your highest score was: " << score << "\n";
        cout << "see you next time";
    return 0;
}
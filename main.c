#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>  // For Sleep()

int score = 0;

// Function to create a delay
void delay(unsigned int secs) {
    Sleep(secs * 1000);
}

// Function to show loading screen
void loading() {
    system("cls");
    printf("\n\n\t\t\t\t\tWORD BY WORD is loading....\n\n");
    for(int i = 0; i < 50; i++) {
        Sleep(30);
        printf("%c", 219);
    }
    printf("\n\n\t\t\t\t\t\t\tWelcome!");
    delay(2);
    system("cls");
}

// Function to display the menu and handle the options
void Menu() {
    char press;
    while (1) {
        system("cls");
        printf("\n\t\t\t\t\t--------------------------------------------");
        printf("\n\t\t\t\t\t\t       WORD BY WORD");
        printf("\n\t\t\t\t\t--------------------------------------------");
        printf("\n\t\t\t\t\t> Press s to START");
        printf("\n\t\t\t\t\t> Press e to EXIT");
        printf("\n\t\t\t\t\t--------------------------------------------");
        printf("\n\n\t\t\t\t\t\tEnter here: ");
        scanf(" %c", &press);  // added space before %c to handle newline issues

        if (press == 's') {
            break;
        } else if (press == 'e') {
            exit(0);
        }
    }
}

// Function to handle each level's display, input, and validation
void playLevel(const char *sentence, const char *correctAnswer) {
    char answer[100];
    system("cls");
    printf("\n\n\t\t\t\t\tBe ready to memorize the following words\n");
    delay(2);

    // Display the sentence word by word
    char temp[100];
    strcpy(temp, sentence);
    char *word = strtok(temp, " ");
    while (word != NULL) {
        printf("\n\n\n\t\t\t\t\t\t\t%s", word);
        delay(2);
        system("cls");
        word = strtok(NULL, " ");
    }

    printf("\n\n\t\t\tNote: Please use an underline instead of spaces. Example: Time_is_gold");
    printf("\n\n\t\t\tNow write the whole sentence: ");
    scanf("%s", answer);

    if (strcmp(answer, correctAnswer) == 0) {
        score += 10;
        printf("\n\n\t\t\t\t\tCORRECT! Well done!\n");
    } else {
        printf("\n\n\t\t\t\t\tGAME OVER! The correct answer was: %s\n", correctAnswer);
        exit(0);
    }
    printf("\n\n\t\t\t\t\tScore: %d", score);
    delay(2);
}

// Main game loop
void startGame() {
    const char *levelSentences[] = {
        "Practice makes perfect",
        "The tall man has just written a letter",
        "The dog owner gives a bone to his dog everyday",
        "The customer is paying the shopkeeper two hundred dollars",
        "Her constant complaining about the job would adumbrate her intent to leave"
    };

    const char *correctAnswers[] = {
        "Practice_makes_perfect",
        "The_tall_man_has_just_written_a_letter",
        "The_dog_owner_gives_a_bone_to_his_dog_everyday",
        "The_customer_is_paying_the_shopkeeper_two_hundred_dollars",
        "Her_constant_complaining_about_the_job_would_adumbrate_her_intent_to_leave"
    };

    for (int i = 0; i < 5; i++) {
        printf("\n\n\t\t\t\t\t\tLEVEL %d\n", i + 1);
        delay(1);
        playLevel(levelSentences[i], correctAnswers[i]);
    }
    printf("\n\n\t\t\t\t\tCongratulations! You've completed all levels!\n");
}

// Main function
int main() {
    loading();
    Menu();
    startGame();
    return 0;
}

#include <stdio.h>

    strcpy(questions[1].question, "What is the largest planet in our Solar System?");
    strcpy(questions[1].options[0], "A. Earth");
    strcpy(questions[1].options[1], "B. Mars");
    strcpy(questions[1].options[2], "C. Jupiter");
    strcpy(questions[1].options[3], "D. Saturn");
    questions[1].correct_option = 'C';

    strcpy(questions[2].question, "Who wrote 'To Kill a Mockingbird'?");
    strcpy(questions[2].options[0], "A. Harper Lee");
    strcpy(questions[2].options[1], "B. J.K. Rowling");
    strcpy(questions[2].options[2], "C. Ernest Hemingway");
    strcpy(questions[2].options[3], "D. Mark Twain");
    questions[2].correct_option = 'A';
}

int askQuestion(QuizQuestion question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", question.options[i]);
    }

    time_t start_time = time(NULL);
    char answer;
    int valid_answer = 0;

    while (time(NULL) - start_time < TIME_LIMIT && !valid_answer) {
        printf("Enter your answer (A, B, C, or D): ");
        if (scanf(" %c", &answer) == 1) {
            if (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D') {
                valid_answer = 1;
            } else {
                printf("Invalid answer. Please enter A, B, C, or D.\n");
            }
        }
    }

    if (time(NULL) - start_time >= TIME_LIMIT) {
        printf("Time's up!\n");
        return 0;
    }

    if (answer == question.correct_option) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Wrong! The correct answer is %c.\n", question.correct_option);
        return 0;
    }
}

int main() {
    QuizQuestion questions[NUM_QUESTIONS];
    initializeQuestions(questions);

    int score = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("\nQuestion %d:\n", i + 1);
        score += askQuestion(questions[i]);
    }

    printf("\nYour final score is %d out of %d.\n", score, NUM_QUESTIONS);
    return 0;
}

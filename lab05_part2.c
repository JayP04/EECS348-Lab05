#include <stdio.h>

// Function to calculate and print all scoring combinations for a given score
void calc_scoring_comb(int score) {
    const int scr_tdplus2 = 8; // Touchdown with 2-point conversion
    const int scr_tdplus1 = 7; // Touchdown with 1-point conversion
    const int scr_td = 6;      // Touchdown without extra points
    const int scr_fg = 3;      // Field Goal
    const int scr_safety = 2;  // Safety

    printf("Possible combinations of scoring plays:\n\n");

    // Iterate through all scoring methods combinations
    for (int tdPlus2 = 0; tdPlus2 <= score / scr_tdplus2; ++tdPlus2) {
        for (int tdPlus1 = 0; tdPlus1 <= score / scr_tdplus1; ++tdPlus1) {
            for (int td = 0; td <= score / scr_td; ++td) {
                for (int fg = 0; fg <= score / scr_fg; ++fg) {
                    for (int safety = 0; safety <= score / scr_safety; ++safety) {
                        if (tdPlus2 * scr_tdplus2 + tdPlus1 * scr_tdplus1 + td * scr_td +
                            fg * scr_fg + safety * scr_safety == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   tdPlus2, tdPlus1, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

// Main function to interact with the user and process scores
int main() {
    int score;
    printf("Enter a score to find combinations or enter 0 or 1 to STOP.\n\n");
    while (1) {
        printf("\nEnter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            printf("Program ended :( .\n");
            break;
        } else {
            calc_scoring_comb(score);
        }
    }

    return 0;
}

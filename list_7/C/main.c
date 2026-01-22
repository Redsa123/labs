#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define min(a,b) \
({__typeof__ (a) _a = (a);\
  __typeof__ (b) _b = (b);\
  _a < _b ? _a : _b;\
})

uint32_t coins_range_d;
uint32_t amount;

void change(uint32_t* coins);

int main(int argc, char* argv[]) {

    if(argc < 3) {
        printf("Wrong number of arguments!");
        return 0;
    }

    FILE *in_file;
    in_file = fopen(argv[1], "r");
    char coins_range[20];

    if(in_file != NULL) {
        fgets(coins_range, 20, in_file);
        sscanf(coins_range, "%d", &coins_range_d);
    } else {
        printf("Wrong input file!");
        return 0;
    }

    uint32_t* coins = malloc(coins_range_d * sizeof(uint32_t));
    for(int i = 0; i < coins_range_d; i++) {
        char coin[20];
        fgets(coin, 20, in_file);
        coins[i] = atoi(coin);
    }
    fclose(in_file);

    for(int i = 2; i < argc; i++) {
        amount = atoi(argv[i]);
        change(coins);
    }

    free(coins);

    return 0;
}

void change(uint32_t* coins) {
    if(amount == 0) {
        printf("0 ==> 0\n");
        return;
    }

    // Tablica dp przechowuje minimalna liczbe monet dla kazdej kwoty
    uint32_t* dp = malloc((amount + 1) * sizeof(uint32_t));

    // Ustawienie domyslnych wartosci
    dp[0] = 0;
    for(int i = 1; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    // 
    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < coins_range_d; j++) {
            if(coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[amount] > amount) {
        printf("%d ==> No solution!\n", amount);
    } else {
        printf("%d ==> %d\n", amount, dp[amount]);
        
        uint32_t* coin_counts = calloc(coins_range_d, sizeof(uint32_t));
        uint32_t temp_amount = amount;
        
        while(temp_amount > 0) {
            for(int j = 0; j < coins_range_d; j++) {
                if(temp_amount >= coins[j] && dp[temp_amount] == dp[temp_amount - coins[j]] + 1) {
                    coin_counts[j]++;
                    temp_amount -= coins[j];
                    break;
                }
            }
        }

        for(int i = 0; i < coins_range_d; i++) {
            if(coin_counts[i] > 0) {
                printf("    %d x %d\n", coin_counts[i], coins[i]);
            }
        }
        free(coin_counts);
    }

    free(dp);
}
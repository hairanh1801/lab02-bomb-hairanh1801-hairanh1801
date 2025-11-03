/***************************************************************************
 * Dr. Evil's Insidious Bomb, Version 1.1
 * Copyright 2011, Dr. Evil Incorporated. All rights reserved.
 *
 * LICENSE:
 *
 * Dr. Evil Incorporated (the PERPETRATOR) hereby grants you (the
 * VICTIM) explicit permission to use this bomb (the BOMB).  This is a
 * time limited license, which expires on the death of the VICTIM.
 * The PERPETRATOR takes no responsibility for damage, frustration,
 * insanity, bug-eyes, carpal-tunnel syndrome, loss of sleep, or other
 * harm to the VICTIM.  Unless the PERPETRATOR wants to take credit,
 * that is.  The VICTIM may not distribute this bomb source code to
 * any enemies of the PERPETRATOR.  No VICTIM may debug,
 * reverse-engineer, run "strings" on, decompile, decrypt, or use any
 * other technique to gain knowledge of and defuse the BOMB.  BOMB
 * proof clothing may not be worn when handling this program.  The
 * PERPETRATOR will not apologize for the PERPETRATOR's poor sense of
 * humor.  This license is null and void where the BOMB is prohibited
 * by law.
 ***************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *infile;

/* Prototypes */
void initialize_bomb(void);
char *read_line(void);
void phase_1(char *input);
void phase_2(char *input);
void phase_3(char *input);
void phase_4(char *input);
void phase_5(char *input);
void phase_6(char *input);
void phase_defused(void);
void explode_bomb(const char *msg);

/* ---------------- Implementation ---------------- */

void initialize_bomb(void) {
    /* keep minimal; real lab may do more */
    return;
}

char *read_line(void) {
    static char linebuf[1024];

    while (1) {
        if (fgets(linebuf, sizeof(linebuf), infile) == NULL) {
            if (infile != stdin) {
                /* switch to standard input */
                fclose(infile);
                infile = stdin;
                fprintf(stderr, "Switching to standard input. Enter input:\n");
                continue;
            } else {
                fprintf(stderr, "No more input. Exiting.\n");
                exit(0);
            }
        }
        /* remove trailing newline/carriage return */
        linebuf[strcspn(linebuf, "\r\n")] = '\0';
        return linebuf;
    }
}

void explode_bomb(const char *msg) {
    if (msg) fprintf(stderr, "BOOM! %s\n", msg);
    else fprintf(stderr, "BOOM! The bomb exploded.\n");
    exit(8);
}

/* ---------- Simple deterministic checks for testing ---------- */

/* Phase 1: exact string "CSAPP" */
void phase_1(char *input) {
    if (!input || strcmp(input, "CSAPP") != 0) {
        explode_bomb("Phase 1 failed: expected \"CSAPP\"");
    }
    printf("[Phase 1 OK] Got: \"%s\"\n", input);
}

/* Phase 2: five integers that double each step (e.g., 1 2 4 8 16) */
void phase_2(char *input) {
    if (!input) explode_bomb("Phase 2 failed: empty input");

    int vals[5];
    int n = sscanf(input, "%d %d %d %d %d",
                   &vals[0], &vals[1], &vals[2], &vals[3], &vals[4]);
    if (n != 5) explode_bomb("Phase 2 failed: expected 5 integers");

    for (int i = 1; i < 5; ++i) {
        if (vals[i] != vals[i-1] * 2) explode_bomb("Phase 2 failed: sequence not doubling");
    }
    printf("[Phase 2 OK] Sequence: %d %d %d %d %d\n",
           vals[0], vals[1], vals[2], vals[3], vals[4]);
}

/* Phase 3: exact string "phase3-defused" */
void phase_3(char *input) {
    if (!input || strcmp(input, "phase3-defused") != 0) {
        explode_bomb("Phase 3 failed: expected \"phase3-defused\"");
    }
    printf("[Phase 3 OK] Got: \"%s\"\n", input);
}

/* Phase 4: two integers a b where a + b == 100 and a > b */
void phase_4(char *input) {
    if (!input) explode_bomb("Phase 4 failed: empty input");
    int a, b;
    if (sscanf(input, "%d %d", &a, &b) != 2) explode_bomb("Phase 4 failed: expected two integers");
    if (a + b != 100) explode_bomb("Phase 4 failed: a + b must equal 100");
    if (!(a > b)) explode_bomb("Phase 4 failed: a must be greater than b");
    printf("[Phase 4 OK] a=%d b=%d\n", a, b);
}

/* Phase 5: input must be a palindrome (e.g., \"level\") */
void phase_5(char *input) {
    if (!input || input[0] == '\0') explode_bomb("Phase 5 failed: empty input");
    size_t L = strlen(input);
    for (size_t i = 0; i < L/2; ++i) {
        if (input[i] != input[L-1-i]) explode_bomb("Phase 5 failed: not a palindrome");
    }
    printf("[Phase 5 OK] \"%s\" is a palindrome\n", input);
}

/* Phase 6: exact string "open sesame" */
void phase_6(char *input) {
    if (!input || strcmp(input, "open sesame") != 0) {
        explode_bomb("Phase 6 failed: expected \"open sesame\"");
    }
    printf("[Phase 6 OK] Got: \"%s\"\n", input);
}

void phase_defused(void) {
    /* placeholder for logging in real lab */
    return;
}

/* ---------------- main (keeps original behavior) ---------------- */

int main(int argc, char *argv[])
{
    char *input;

    if (argc == 1) {
        infile = stdin;
    } else if (argc == 2) {
        if (!(infile = fopen(argv[1], "r"))) {
            printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
            exit(8);
        }
    } else {
        printf("Usage: %s [<input_file>]\n", argv[0]);
        exit(8);
    }

    initialize_bomb();

    printf("Welcome to my fiendish little bomb. You have 6 phases with\n");
    printf("which to blow yourself up. Have a nice day!\n");

    input = read_line();
    phase_1(input);
    phase_defused();
    printf("Phase 1 defused. How about the next one?\n");

    input = read_line();
    phase_2(input);
    phase_defused();
    printf("That's number 2.  Keep going!\n");

    input = read_line();
    phase_3(input);
    phase_defused();
    printf("Halfway there!\n");

    input = read_line();
    phase_4(input);
    phase_defused();
    printf("So you got that one.  Try this one.\n");

    input = read_line();
    phase_5(input);
    phase_defused();
    printf("Good work!  On to the next...\n");

    input = read_line();
    phase_6(input);
    phase_defused();

    printf("Congratulations — all phases defused!\n");
    return 0;
}

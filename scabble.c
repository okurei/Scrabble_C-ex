#include <stdio.h>
#include <string.h>
#include <ctype.h>

void getString(char *q, char *a);
int pointScore(char *a);
void scoreCompare(int i1, int i2);

int main(){
    char pi1[50];
    char pi2[50];
    getString("Player 1: ", pi1);
    getString("Player 2: ", pi2);
    int s1 = pointScore(pi1);
    int s2 = pointScore(pi2);
    scoreCompare(s1, s2);
    return 0;
}

// get string from input and convert to lover case.
void getString(char *q, char *a){
    printf("%s", q);
    fgets(a, 50, stdin);
    a [strcspn(a, "\n")] = '\0';
     for (int i = 0; a[i] != '\0'; i++){
        a[i] = tolower((unsigned char)a[i]);
    }
}

// calculate score by iterating the string and with an if else adding point to the variable point depending on the "rules"
int pointScore(char *a){
    int point = 0;
    for (int i = 0; i < strlen(a); i++){
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'l' || a[i] == 'n' || a[i] == 'o' || a[i] == 'r' || a[i] == 's' || a[i] == 't' || a[i] == 'u'){
            point += 1;
        }
        else if (a[i] == 'd' || a[i] == 'g'){
            point += 2;
        }
        else if (a[i] == 'b' || a[i] == 'c' || a[i] == 'm' || a[i] == 'p'){
            point += 3;
        }
        else if (a[i] == 'f' || a[i] == 'h' || a[i] == 'v' || a[i] == 'w' || a[i] == 'y'){
            point += 4;
        }
        else if (a[i] == 'k'){
            point += 5;
        }
        else if (a[i] == 'j' || a[i] == 'x'){
            point += 8;
        }
        else if (a[i] == 'q' || a[i] == 'z'){
            point += 10;
        }
        else{
            point += 0;
        }
    }
    return point;
}

//compare the score of player 1 and player 2 printing it.
void scoreCompare(int i1, int i2){
    if (i1 > i2){
        printf("Player 1 win");
    }
    else if (i1 < i2){
        printf("Player 2 win");
    }
    else {
        printf("Tie");
    }
}

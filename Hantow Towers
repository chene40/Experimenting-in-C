#include <stdio.h>
#include <unistd.h>
#include <string.h>

// initialize the pegs
// pego is origin peg, pegd is destination peg, pegh is helper peg
int pego[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int pegd[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int pegh[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};


void display_pegs(){
        int i, j, k, l;
     int *towers[3] = {pego, pegd, pegh};
     
     for (i = 0; i < 9; i++){                         // to print each row of hantoi tower
          int num[3] = {pego[8-i], pegd[8-i], pegh[8-i]};          // num of disks in a row for each tower
          for (j = 0; j < 3; j++){                    // goes through each tower (S, D, H)
               for (k = 10; k > 0; k--){               // prints left end of '|'
                    if (k > num[j])     printf(" ");
                    else {printf("+");}
               }                    
               printf("|");
               for (l = 0; l < 10; l++){               // prints right end of '|'
                    if (l < num[j])     printf("+");
                    else {printf(" ");}
               }
          printf("\t");
          }
          printf("\n");
     }
     printf("XXXXXXXXXXXXXXXXXXXXX\tXXXXXXXXXXXXXXXXXXXXX\tXXXXXXXXXXXXXXXXXXXXX\n");
     printf("\n");
}

void init(nod){
     int i;
        for (i = 0; i < nod; i++){
                pego[i] = nod - i;
        }
}

// move a peg from source to destination
void move(int pegA[9], int pegB[9]){          // pegS is source peg, pegD is destination peg
     int i, top_peg;
     
     // access the element at the top of the source peg (top_peg)
     for (i = 0; i < 9; i++){
          if (pegA[i] == 0){
               top_peg = pegA[i-1];
               pegA[i-1] = 0;
               break;
          }
          else if (i == 8 && pegA[i] == 1){     // accounts for top disk being == 1
               top_peg = pegA[i];
               pegA[i] = 0;
          }     
     }

     int j;
     for (j = 0; j < 9; j++){
          if (pegB[j] == 0){          // move top element of source peg to destination peg
               pegB[j] = top_peg;
               break;
          }
     }

     // display the pegs after moving the top element from source peg to destination peg
          
     display_pegs();     
     sleep(1);          
}


void hantow(int nod, int pego[9], int pegd[9], int pegh[9]){
     if (nod > 1){                    // recursively perform the movement until we only have 1 disk left
          hantow(nod-1, pego, pegh, pegd);
     }

     move(pego, pegd);

     if (nod > 1){
          hantow(nod-1, pegh, pegd, pego);
     }
}

int main(int argc, char* argv[]){
     if (argc > 2){     // if more than one command line argument
          printf("Too many command line arguments!\n");
          printf("Terminating program...\n");
          return;
     }
     else if (argc < 2){
          printf("Missing command line argument!\n");
          printf("Usage: hantow <numofdisks>\n");
          printf("\twhere <numofdisks> is an integer number between 1 and 9 (1..9)\n");
          return;
      }
     
     // by this time, we are certain that argc = 2
     // if the second command line argument is not a number between 1 and 9, terminate the program
     if (strlen(argv[1]) != 1){
          printf("Incorrect command line argument!\n");
          printf("Command line argument should be an integer between 1 and 9.\n");
          printf("Terminating program...\n");
          return;
     }

     // obtain the number of disks     
     int nod = 0;

     if ((argv[1][0] >= '1') && (argv[1][0] <= '9')){
          nod = argv[1][0] - '0';
     }
     else{
          printf("invalid input\n");
          printf("command line argument should be between 1 and 9\n");
          return;
     }
     
     init(nod);
     display_pegs();
     sleep(1);
     hantow(nod, pego, pegd, pegh);
     printf("done\n");
}

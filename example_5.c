#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char alphabet[29] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', ' ', ',', '.'};
const char ch = ' ';
const int length = 29;

int **getLettersCode(char *str, int matrix_row, int matrix_column) {  
  int i, j, l, key = 0;
 
  int letters[strlen(str)];
   
  for(key = 0; key < strlen(str); key++){
    for(l=0; l < length; l++) {
      if(tolower(str[key]) == alphabet[l]) {
        letters[key] = l;
      }
    }
  }

 int** startMatrix = (int**)malloc(matrix_row * sizeof(int*));
    
  for (i = 0, key = 0; i < matrix_row; i++){
    startMatrix[i] = (int*)malloc(matrix_column * sizeof(int));

    for (j = 0; j < matrix_column; j++){
      startMatrix[i][j] = letters[key++];
    }
  }

  return startMatrix;

  free(startMatrix);
  
}

char *getTextFromFile( char *fileName) {
FILE *fp;
char fileStr[256];
int textSize, s;
 
 fp = fopen(fileName , "r");
 if(fp == NULL) {
    perror("Error opening file");
    exit(1);
 }

fgets (fileStr, 256, fp);
fseek(fp, 0L, SEEK_END);
  
textSize = ftell(fp);

fclose(fp);

char *str = malloc(textSize);
  
 for(s = 0; s < textSize; s++) {
   str[s] = ' ';
   str[s] = fileStr[s]; 
 }
    
  return str;

  free(str);
}

void getCryptedText(int **codeMatrix, int matrix_row, int matrix_column) {
  int i, j, l;
  int encryptMatrix[matrix_row][matrix_column];
  int keyMatrix[2][2] = {5, 17, 4, 15};
  
  FILE *fc = fopen("crypted.txt", "w");
  
  printf("\nEncrypted text=\n\n");
    for (i = 0; i < matrix_row; i++){
      for (j = 0; j < matrix_column; j++){
        
        encryptMatrix[i][j] = 0;
       
        for (l = 0; l < matrix_row; l++){
         
          encryptMatrix[i][j] += keyMatrix[i][l] * codeMatrix[l][j];
        }
        printf("%c", alphabet[encryptMatrix[i][j] % length]);
        fputc(alphabet[encryptMatrix[i][j] % length], fc);
        
      }
    }
    printf("\n\n");

  fclose(fc);
}

void getDecryptedText(int **codeMatrix, int matrix_row, int matrix_column){
  int i, j, l;
  int decryptMatrix[matrix_row][matrix_column];
  int reverseMatrix[2][2] = {27, 10, 16, 9};
  
  printf("\nDecrypted text=\n\n");
    for (i = 0; i < matrix_row; i++){
      for (j = 0; j < matrix_column; j++){
        decryptMatrix[i][j] = 0;
        for (l = 0; l < matrix_row; l++){
          decryptMatrix[i][j] += reverseMatrix[i][l] * codeMatrix[l][j];
        }
     
        printf("%c", alphabet[decryptMatrix[i][j]% length]);  
        
      }
    }
    printf("\n\n");
}

int main() {  
  int i, j, d;
  
  int matrix_row = 2;
  int matrix_column = 0;
  
  printf("Hello! This code crypt and decrypt text (only latin) from file. What you need to do:\n press 1 - encrypt the text from file; \n press 2 - decrypt the text from file\n\n");    
scanf("%d",&d);

  if(d == 1){
    char *str = getTextFromFile("origin.txt");
    
    if(strlen(str) == 0) {
      printf("There is no text in file. Please add text for crypting");
    }

    if(strlen(str) % 2 == 0){
      matrix_column = strlen(str)/matrix_row;
    }else {
      matrix_column = strlen(str)/matrix_row + 1;
      strncat(str, &ch, 1);
    }

    int **startMatrix = getLettersCode(str, matrix_row, matrix_column);

    printf("\nOrigin text=\n\n");  
    for (i = 0; i < matrix_row; i++){
      for (j = 0; j < matrix_column; j++){
        printf("%c", alphabet[startMatrix[i][j] % length]);
      }
    }

    printf("\n\n");
    
    getCryptedText(startMatrix, matrix_row, matrix_column);

    printf("\n\n");

    }else if(d == 2){
      char *cryptedStr = getTextFromFile("crypted.txt");
    
      if(strlen(cryptedStr) == 0) {
        printf("There is no text in file. Please add text for decrypting");
      }

    if(strlen(cryptedStr) % 2 == 0){
      matrix_column = strlen(cryptedStr)/matrix_row;
    }else {
      matrix_column = strlen(cryptedStr)/matrix_row + 1;
      strncat(cryptedStr, &ch, 1);
    }

      int **cryptedMatrix = getLettersCode(cryptedStr, matrix_row, matrix_column);

      getDecryptedText(cryptedMatrix, matrix_row, matrix_column);
    }

  return 0;
}  

#include <stdio.h>
#include <stdlib.h> 

#define N 3     //size for matrix array
#define S 20    //size for sorting array

void getArrayFromUser();
void printArray(int arr[N][N]);
void getRearrangementArray(int arr[N][N]);
void print_simple_array(int num[], int size_num);
void getArrayForSorting();

int main(void) {
  //get array from console and print array
  getArrayFromUser();

  //get array for sorting and print sorted array
  getArrayForSorting();

  return 0;
}

void getArrayFromUser() {
  int initialArray[N][N];
  int i, j, k;

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("Enter [%i][%i] element of an array[%i][%i] \n", i, j, N, N);
      scanf("%i", &initialArray[i][j]);
    }
  }

  printf("Initial array \n");
  printArray(initialArray);
  putchar('\n');

  printf("Rearrangement of array in additional diagonals[N][N] \n");
  getRearrangementArray(initialArray);
  putchar('\n');

}

void printArray(int arr[N][N]){
  int i, j;

  for (i = 0; i < N; i++){
    for (j = 0; j < N; j++) {
      printf(" %-d \t", arr[i][j]);
      if(j == N - 1) putchar('\n');
    }   
  }
}

void getRearrangementArray(int arr[N][N]){
  //AdditionalDiagonal[i][j] = Initial[N - 1 - j][N - 1 - i];
  int i, j;
  int additionalDiagonal[N][N];

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      additionalDiagonal[i][j] = arr[N - 1 - j][N - 1 - i];
    }
  }

  printArray(additionalDiagonal);

}

void getArrayForSorting() {
  int initialArray[S];
  int i, j, k, temp;
  int size = sizeof(initialArray)/sizeof(initialArray[0]);

  for (i = 0; i < S; i++) {
    initialArray[i] = i + 1; 
  }

  printf("\nInitial array: \n"); 
  print_simple_array(initialArray, size);

  for (k = 0; k < size - 1; k++) {
    for (j = 0; j < size - k - 1; j++) {
      if (initialArray[j] < initialArray[j + 2]){
        temp = initialArray[j]; 
        initialArray[j] = initialArray[j+2]; 
        initialArray[j+2] = temp;
      } 
    }
  }
  
  putchar('\n');
  printf("Array after bubble sort: \n"); 
  print_simple_array(initialArray, size);

}

void print_simple_array(int num[], int size_num){
  int i;

  for (i = 0; i < size_num; i++) {
    printf("%d ", num[i]); 
  }
  printf("\n"); 
}

#include <stdio.h>

int main () {
  int i, j, c;
  float start[4][4];
    
  FILE *fp;
  
  fp = fopen("start","r");
  
  while(1) {
    c = fgetc(fp);
    if( feof(fp) ) {
      break ;
    }
    printf("%c", c);
  }
  
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
    printf("Enter [%i][%i] element of an array[%i][%i] \n", i, j, 4,4);
    scanf("%f", &start[i][j]);
    }
  }
  
  if((fp=fopen("start", "wb"))==NULL) {
    printf("Cannot open file.");
  }
  
  fwrite(start, sizeof start, 1, fp) ;
  fclose(fp);
  
  if((fp=fopen("start","rb")) == NULL) {
    printf("Cannot open file");
  }
  
  fread(start, sizeof start, 1, fp);
  
  for(i=0; i<4; i++) {
    for(j=0; j <4; j++) {
      printf("%f  ", start[i][j]);
      if(j == 3) putchar('\n');
    }
  }
    
  fclose(fp);
    
  return 0;
  
}

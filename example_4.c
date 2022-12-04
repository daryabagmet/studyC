#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUM 8 
#define MAXMOD 15
#define MAXNAME 10

struct service { 
  char car_registration_number[MAXNUM];
  char car_model[MAXMOD];
  float car_mileage;
  char repairman_name[MAXNAME];
  float repair_amount; 
};

int main () {
  
struct service car_service; 
  
printf("Enter car registrantion number...\n");
scanf("%s", car_service.car_registration_number);
  
printf("Enter car model...\n");
scanf("%s", car_service.car_model);

printf("Enter car mileage...\n");
scanf("%f", &car_service.car_mileage);

printf("Enter repairman name...\n");
scanf("%s", car_service.repairman_name);
  
printf("Enter total repair amount...\n");
scanf("%f", &car_service.repair_amount);

FILE *fp;
fp = fopen ("car_service.txt", "w");

if (fp == NULL) {
  fprintf(stderr, "\nError to open the file\n");
}
 
fwrite (&car_service, sizeof(struct service), 1, fp);

fclose (fp);

fp = fopen ("car_service.txt", "r");

while(fread(&car_service, sizeof(struct service), 1, fp)){
  printf ("Car number = %s\nCar model = %s\nCar mileage = %.2f km\nRepairman = %s\nTotal = %.2f $", 
  car_service. car_registration_number, 
  car_service.car_model, 
  car_service.car_mileage, 
  car_service.repairman_name, 
  car_service.repair_amount);
}

fclose (fp);

return 0;
  
}

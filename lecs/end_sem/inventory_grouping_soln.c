#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Group {
  Diary,
  Vegetables,
  Fruits
} Group;

char group_names[3][100] = {
    "diary",
    "vegetable",
    "fruit"
  };

typedef struct InventoryItem {
  char name[100];
  int quantity;
  int price;
  Group group;
} InventoryItem;

int main(int argc, char* argv[]) {

  InventoryItem inventory[100];

/* Problem 2.1: Suppose the first argument of a.out
contains the csv file of inventories, write code 
here, which reads that file and stores the data in 
the `inventory` array declared above.
*/
  FILE* f_inventory = fopen(argv[1],"r");
  char item[100];
  fscanf(f_inventory,"%s\n", item);
  int q,p;
  int i = 0;
  while (fscanf(f_inventory,"%s ,%d,%d\n", item, &q, &p) == 3)
  {
    printf("%s %d %d\n",item, q, p);
    strcpy(inventory[i].name, item);
    inventory[i].quantity = q;
    inventory[i].price = p;
    i++;
  }
  fclose(f_inventory);


  FILE* f_group = fopen(argv[2],"r");
  fscanf(f_group,"%s\n", item);
  char group[100];
  while(fscanf(f_group,"%s ,%s\n",item,group)==2)
  {
/* Problem 2.2: Suppose the second argument of a.out
contains the csv file which has the group name
corresponding to each inventory item, write code here,
which updates the `group` field
in each InventoryItem of the `inventory` array.
*/
    printf("%s %s\n",item, group);
    for (int j = 0; j < i; j++) {
      if (strcmp(inventory[j].name, item) == 0) {
        if (strcmp(group, group_names[Diary]) == 0) {
          inventory[j].group = Diary;
        } else if (strcmp(group, group_names[Vegetables]) == 0) {
          inventory[j].group = Vegetables;
        } else if (strcmp(group, group_names[Fruits]) == 0) {
          inventory[j].group = Fruits;
        } 
         
      }
    }
  }
  fclose(f_group);



  int grouped_value[3];
/* Problem 2.3: Compute the total value of all
items in a group and store it in the correpsonding
entry of the array `grouped_value`. That is
grouped_value[0] has the total value of all
Diary items. Similarly Vegetables for 1 and Fruits for 2.
*/

  for (int j = 0; j < i; j++) {
    printf("%s,%d,%d\n", inventory[j].name, inventory[j].price, inventory[j].group);
    grouped_value[inventory[j].group] += inventory[j].price*inventory[j].quantity;
  }

/* Problem 2.4: Write down the grouped inventory values
into a file given by the third argument to a.out, in the format
specificed for `grouped_inventory.csv`.
*/
  FILE* f_grouped_inventory = fopen(argv[3], "w");
  fprintf(f_grouped_inventory, "group,value\n");
  for (int k = 0; k <3; k++) {
    fprintf(f_grouped_inventory, "%s,%d\n", group_names[k], grouped_value[k]);
  }
  fclose(f_grouped_inventory);
}
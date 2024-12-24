#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "user.txt"

struct User
{
  int id;
  char name[50];
  int age;
};

void createUser();
void readUser();
void updateUser();
void deleteUser();
void createFile();
void clearFile();

int main()
{
  createFile();
  int operation;
  int islooping = 1;
  while (islooping)
  {

    printf("Hey, please select one option\n");
    printf("1. Create User\n");
    printf("2. Read User\n");
    printf("3. Update User\n");
    printf("4. Delete User\n");
    printf("5. Clear File\n");
    printf("6. Exit Program\n");
    printf("Enter your Choice: ");
    scanf("%d", &operation);

    switch (operation)
    {
    case 1:
      createUser();
      break;

    case 2:
      readUser();
      break;

    case 3:
      updateUser();
      break;

    case 4:
      deleteUser();
      break;

    case 5:
      clearFile();
      break;

    case 6:
      islooping = -1;
      break;

    default:
      printf("Invalid operation\n");
    }
  }
}

void createFile()
{
  FILE *file = fopen(FILE_NAME, "a");
  if (file == NULL)
  {
    printf("Error in creating file\n");
  }
  fclose(file);
}

void clearFile()
{

  FILE *file = fopen(FILE_NAME, "w");

  if (file == NULL)
  {
    printf("File Not Found\n");
  }
  else
  {
    printf("File cleared successfully\n");
  }
  fclose(file);
}

int isUserIdUnique(int id)
{

  FILE *file = fopen(FILE_NAME, "r");
  if (file == NULL)
  {
    return -2;
  }

  struct User user;

  while (fscanf(file, "%d,%49[^,],%d", &user.id, user.name, &user.age) == 3)
  {

    if (user.id == id)
    {
      fclose(file);
      return 1;
    }
  }
  fclose(file);
  return -1;
}

void createUser()
{
  printf("\nEnter User Details: \n");
  struct User user;

  printf("Enter User ID: ");
  scanf("%d", &user.id);
  printf("Enter User Name: ");
  scanf(" %49[^\n]", user.name);
  printf("Enter User Age: ");
  scanf("%d", &user.age);

  int is_ID_present = isUserIdUnique(user.id);

  if (is_ID_present == 1)
  {
    printf("User ID already present\n");
  }
  else if (is_ID_present == -2)
  {
    printf("Error in Creating User\n");
  }
  else
  {

    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL)
    {
      printf("Error in Creating User\n");
      return;
    }
    fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
    printf("User Created Successfully\n");
    fclose(file);
  }
}

void readUser()
{

  printf("\nFile Entries: \n");

  FILE *file = fopen(FILE_NAME, "r");
  if (!file)
  {
    printf("Error opening file");
    return;
  }

  struct User user;

  printf("\nID\tName\t\tAge\n");
  while (fscanf(file, "%d,%49[^,],%d", &user.id, user.name, &user.age) == 3)
  {
    printf("%d\t%s\t%d\n", user.id, user.name, user.age);
  }

  fclose(file);
}

void updateUser()
{

  printf("\nUpdate User\n");

  FILE *file = fopen(FILE_NAME, "r");
  if (file == NULL)
  {
    printf("File Not Found\n");
    return;
  }

  int id, found = 0;
  printf("Enter ID to update: ");
  scanf("%d", &id);

  FILE *temp = fopen("temp.txt", "w");
  if (!temp)
  {
    printf("Something went wrong\n");
    fclose(file);
    return;
  }

  struct User user;

  while (fscanf(file, "%d,%49[^,],%d", &user.id, user.name, &user.age) == 3)
  {
    if (user.id == id)
    {
      found = 1;
      printf("Enter new Name: ");
      scanf(" %[^\n]", user.name);
      printf("Enter new Age: ");
      scanf("%d", &user.age);
    }
    fprintf(temp, "%d,%s,%d\n", user.id, user.name, user.age);
  }

  fclose(file);
  fclose(temp);

  remove(FILE_NAME);
  rename("temp.txt", FILE_NAME);

  if (found)
  {
    printf("User updated successfully.\n");
  }
  else
  {
    printf("User with ID %d not found.\n", id);
  }
}

void deleteUser()
{

  printf("\nDelete User\n");

  FILE *file = fopen(FILE_NAME, "r");
  if (file == NULL)
  {
    printf("File Not Found\n");
    return;
  }

  int id, found = 0;
  printf("Enter ID to update: ");
  scanf("%d", &id);

  FILE *temp = fopen("temp.txt", "w");
  if (!temp)
  {
    printf("Something went wrong\n");
    fclose(file);
    return;
  }

  struct User user;

  while (fscanf(file, "%d,%49[^,],%d", &user.id, user.name, &user.age) == 3)
  {
    if (user.id == id)
    {
      found = 1;
    }
    else
      fprintf(temp, "%d,%s,%d\n", user.id, user.name, user.age);
  }

  fclose(file);
  fclose(temp);

  remove(FILE_NAME);
  rename("temp.txt", FILE_NAME);

  if (found)
  {
    printf("User Deleted successfully.\n");
  }
  else
  {
    printf("User with ID %d not found.\n", id);
  }
}
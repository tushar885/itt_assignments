#include <stdio.h>
#include <stdlib.h>

void createUser();
void readUser();
void updateUser();
void deleteUser();

int main(){

    int operation;
    while(1){

        printf("Hey, please select one option\n");
        printf("1. Create User\n");
        printf("2. Read User\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &operation);

        switch (operation){
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
                exit(0);
                break;
            
            default:
                printf("Invalid operation\n");
        }
    }

}

void createUser(){
    printf("Create User\n");
}

void readUser(){
    printf("Read User\n");
}  

void updateUser(){
    printf("Update User\n");
}   

void deleteUser(){
    printf("Delete User\n");
}
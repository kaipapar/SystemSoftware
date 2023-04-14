#include <stdio.h>
#include <stdlib.h>

struct my_struct {
    int id;
    char name[50];
    float score;
};

int main() {
    FILE *fp = fopen("filename.bin", "rb");
    int num_structs = 1;
    
    // read the number of structs from file
    fread(&num_structs, sizeof(int), 1, fp);
    
    // allocate memory for the array of structs
    struct my_struct *arr = malloc(num_structs * sizeof(struct my_struct));
    
    // read the array of structs from file
    fread(arr, sizeof(struct my_struct), num_structs, fp);
    
    // print the array of structs
    for(int i = 0; i < num_structs; i++) {
        printf("Struct %d: id = %d, name = %s, score = %.2f\n", i+1, arr[i].id, arr[i].name, arr[i].score);
    }
    
    

    // close the file
    fclose(fp);
    
    // free the memory allocated for the array
    free(arr);
    
    return 0;
}

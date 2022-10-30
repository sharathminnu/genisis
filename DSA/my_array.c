
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE (10)

typedef enum status_t 
{
    SUCESS, 
    NULL_POINTER, 
    FAILURE
}status_t;

typedef struct employee_t
{
    int ps_number;
    char name[20];
    char email_id[40];
}employee_t;

employee_t* ptr_arr = NULL;

employee_t* create_employees(int size)
{
    return malloc(size * sizeof(employee_t));
}

status_t add_employee(employee_t* array, int array_size, employee_t* new_employee)
{
    int index = 0;// your logic to find the empty index
    memcpy(&array[index], new_employee, sizeof(employee_t));
    return SUCESS;
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage: ./executable <filename>\n");
        exit(-1);
    }
    
    int fd = open(argv[1], O_RDONLY);
    if(fd<0)
	{
		perror("open");
		exit(-5);
	}
    printf("File open Success\n");

    char arr[1024] = "";
    int n_bytes = 0;
    
    ptr_arr = create_employees(ARRAY_SIZE);
    int bytes_scanned = 0;

    
    do{
        n_bytes = read(fd, &arr[bytes_scanned], 1024-bytes_scanned);
        
        printf("Bytes read = %d\n", n_bytes);
        if(n_bytes < 0)
        {
            perror("read");
            exit(-1);
        }
        else if(0 == n_bytes)
        {
            break;
        }
        else
        {
#if 0
            printf("Before conversion\n");
            employee_t employee;
            employee.ps_number = atoi(strtok(arr, ","));
            strcpy(employee.name,strtok(NULL, ","));
            strcpy(employee.email_id,strtok(NULL, "\n"));
            printf("After conversion\n");
            add_employee(ptr_arr,ARRAY_SIZE, &employee);
#else
        
        for(int i = 0; i< n_bytes; i++)
        {
            if('\n' == arr[i])
            {
                char* row = malloc((i-bytes_scanned) * sizeof(char) + 1);
                memcpy(row, &arr[bytes_scanned], i-bytes_scanned);
                printf("%s\n", row);

                employee_t employee;
                employee.ps_number = atoi(strtok(row, ","));
                strcpy(employee.name,strtok(NULL, ","));
                strcpy(employee.email_id,strtok(NULL, ","));
                
                printf("%d, %s, %s\n", employee.ps_number, employee.name, employee.email_id);

                add_employee(ptr_arr,ARRAY_SIZE, &employee);
                free(row);
                bytes_scanned = i +1;
            }
        }
        if(bytes_scanned != n_bytes)
        {
            memmove(arr, &arr[bytes_scanned], n_bytes-bytes_scanned);
            //to copy the remaining characters back to the array start
        }
        else
        {
            bytes_scanned = 0;
        }
#endif
            // Fix code to add all the employees
        }
    }
    while(0 != n_bytes);
    
    

    employee_t empl1 = {40010753, "Bharath", "bharath.g@ltts.com"};
    
    return 0;
}
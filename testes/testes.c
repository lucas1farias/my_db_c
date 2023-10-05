

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
    int ident;
    char *name;
    struct student *next;
} Student;

Student *left;
Student *right;

Student *newStudent(int ident, char name[]) {
    Student *student = (Student *)malloc(sizeof(Student));
    if (student == NULL) {
        printf("\nErro ao alocar memória!");
        exit(1);
    }
    student->ident = ident;
    student->name = strdup(name);
    student->next = NULL;
    return student;
}

// Outside to inside perspective (from parameter to pointer)
void appendLeft(Student *student) {
    if (left == NULL) {
        left = student;
        right = student;
    } else {
        
        /*
            if the parameter is telling that its attribute
            "next" points to where the pointer is, this means
            it comes first than something, in this case,
            it is in front of what the pointer points to, but 
            the parameter is not yet the first element, because 
            the pointer needs to offset from its current 
            position to the position of the parameter, which is 
            what happens in the second line
        */
        student->next = left;
        left = student;
    }
}

// Inside from outside perspective (from pointer to parameter)
void appendRight(Student *student) {
    if (left == NULL) {
        left = student;
        right = student;
    } else {
        /*
            the chained list has the pointer "right" pointing
            to the last object of this list. In order to make
            the parameter the last index of this chained list,
            it is needed to reference the parameter as value 
            of the attribute "next" that the pointer is pointing 
            to, then the pointer is moved to the parameter and it
            becomes the last index 
        */
        right->next = student;
        right = student;
    }
}

void exhibit(char type[]) {
    printf("\n[\n");
    if (strcmp(type, "for") == 0) {
        for (Student *eachStudent = left; eachStudent != NULL; eachStudent = eachStudent->next) {
            printf("    Matricula: %d, Nome: %s,\n", eachStudent->ident, eachStudent->name);
        }
    } else {
        Student *eachStudent = left;
        while (eachStudent) {
            printf("    Matricula: %d, Nome: %s,\n", eachStudent->ident, eachStudent->name);
            eachStudent = eachStudent->next;
        }
    }
    printf("\n]");
}

int main() {
    Student *ptrNewStudent = newStudent(1, "Ena");
    appendLeft(ptrNewStudent);
    ptrNewStudent = newStudent(2, "Ina");
    appendLeft(ptrNewStudent);
    ptrNewStudent = newStudent(3, "Ana");
    appendRight(ptrNewStudent);
    exhibit("for");
    
    return 0;
}

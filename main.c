// Estudiantes: Semisterra Ibadango Jhosue Benjamin
//              Heredia Valdivieso Carlos Mauricio 

#include <stdio.h>
#include <string.h>

int main(){

    char name[5][20];
    char subject[3][20];
    float results[5][3] = {0};
    int opt, len, opt1, beststudent = 0, worststudent = 0, bestsubject = 0, worstsubject = 0, approved = 0, reproved = 0;
    float grade, averageStudents = 0, averageSubjects = 0, bestgrade = 0, worstgrade = 0;
    char nameAux[20], subjectAux[20];


   do {
    printf("Choose one option\n 1.Enter the name\n 2.Enter the subjects\n 3.Enter the grade\n 4.Grades of the Students\n 5.EXIT THE PROGRAM\n");
    printf("<<");
    scanf("%i", &opt);

    switch (opt){

        case 1:
            for (int i = 0; i < 5; i++) {
                if (i < 5) {
                    printf("Writting the name #%i\n", i+1);
                    
                    fflush(stdin);
                    fgets(name[i], 20, stdin);
                    len = strlen(name[i]) -1;
                    name[i][len] = '\0';     
                }
            }
        break;

        case 2:
            for (int i = 0; i < 3; i++) {
                printf("Enter the names of subjects\n");

                fflush(stdin);
                fgets(subject[i], 20, stdin);

                len= strlen(subject[i]) -1;
                subject[i][len] = '\0';
            }
            printf("The subjects are\n --%s\n --%s\n --%s\n",subject[0], subject[1], subject[2]);

        break;
        
        case 3:
            for (int i = 0; i < 5; i++) {
                printf("Enter grades for studen %s\n", name[i]);
                for (int j = 0; j < 3; j++) {
                    printf("Enter grade for %s in %s\n", name[i], subject[j]);
                    printf("<<");
                    scanf("%f", &grade);
                    if (grade <= 10 && grade >= 0) {
                        results[i][j] = grade;
                        printf("%s has a %.2f in %s\n",name[i], grade, subject[j]);
                    } else {
                        printf("Invalid Grade try again please\n");
                        j--;
                    }
                }
            }
        break;   

        case 4:
            printf("Choose the option \n 1.Enter for see the grades standar\n 2.Enter for see approved students\n 3.Enter for see the best average in each Student and Subject\n 4.Number of Students Passed\n");
            printf("<<");
            scanf("%i", &opt1);
            switch (opt1){
                case 1:
                    printf("\n#\t\t\tStudent\t\t\t%s\t\t\t%s\t\t\t%s\t\tAverage Students\n",subject[0],subject[1],subject[2]);
                    for (int i = 0; i < 5; i++) {
                        averageStudents = 0;
                        printf("%i\t\t\t%s",i+1, name[i]);
                        for (int j = 0; j < 3; j++) {
                            printf("\t\t\t%.2f", results[i][j]);

                            averageStudents += results[i][j];
                        }
                        averageStudents = averageStudents/3;
                        printf("\t\t%.2f\n", averageStudents);
                    }
                    printf("\t\t---\t\t\n");
                    printf("Average Subjects");
                    for (int j = 0; j < 3; j++){
                        averageSubjects = 0;
                        for (int i = 0; i < 5; i++){
                            averageSubjects += results[i][j];
                        }
                        averageSubjects = averageSubjects / 5;
                        printf("\t\t\t\t%.2f", averageSubjects);
                    }
                    printf("\n");
                    
                break;   
                
                case 2:
                    printf("The students approved or not approved in each subject\n");
                    for (int i = 0; i < 5; i++) {
                        printf("%i\t\t\t%s\n",i+1, name[i]);
                        for (int j = 0; j < 3; j++) {
                            printf("\t%s %.2f\t",subject[j], results[i][j]);
                            if (results[i][j] >= 6) {
                                printf("Approved %s\n", name[i]);
                            } else {
                                printf("-----\n"); 
                            }
                        } 
                    }
                    printf("\n");

                break;

                case 3:
                    printf("The Best Grade of each Subject\n");
                    for (int j = 0; j < 3; j++) {
                        bestgrade = 0;
                        beststudent = 0;
                        for (int i = 0; i < 5; i++) {
                            if (results[i][j] > bestgrade) {
                                bestgrade= results[i][j];
                                beststudent = i;
                            }
                        } 
                        if (bestsubject != -1) {
                            printf("Student's name: %s\n", name[beststudent]);
                            printf("The best subject is %s with %.2f\n\n\n", subject[j], bestgrade);
                        }
                    }
                    printf("The Worst Grade of each subject\n");
                    for (int j = 0; j < 3; j++) {
                        worstgrade = 10;
                        worstsubject = 0;
                        for (int i = 0; i < 5; i++) {
                            if (results[i][j] < worstgrade) {
                                worstgrade= results[i][j];
                                worstsubject = i;
                            }
                        } 
                        if (worstsubject != -1) {
                            printf("Student's name: %s\n", name[worststudent]);
                            printf("The worst subject is %s with %.2f\n\n\n", subject[worstsubject], worstgrade);
                        }
                    }

                    printf("The Best Grade of each Student\n");
                    for (int i = 0; i < 5; i++) {
                        bestgrade = 0;
                        bestsubject = 0;
                        for (int j = 0; j < 3; j++) {
                            if (results[i][j] > bestgrade) {
                                bestgrade= results[i][j];
                                bestsubject = j;
                            }
                        } 
                        if (bestsubject != -1) {
                            printf("Student's name: %s\n", name[i]);
                            printf("The best subject is %s with %.2f\n\n\n", subject[bestsubject], bestgrade);
                        }
                    }
                    printf("The Worst Grade of each Student\n");
                    for (int i = 0; i < 5; i++) {
                        worstgrade = 10;
                        worstsubject = 0;
                        for (int j = 0; j < 3; j++) {
                            if (results[i][j] < worstgrade) {
                                worstgrade= results[i][j];
                                worstsubject = j;
                            }
                        } 
                        if (worstsubject != -1) {
                            printf("Student's name: %s\n", name[i]);
                            printf("The worst subject is %s with %.2f\n\n\n", subject[worstsubject], worstgrade);
                        }
                    }

                break;

                case 4:
                    for (int i = 0; i < 5; i++) {
                        approved = 0;
                        reproved = 0;
                        printf("%s\n", name[i]);
                        for (int j = 0; j < 3; j++) {
                            if (results[i][j] >= 6) {
                                approved++;
                                printf("\t%s Approved\t\t%.2f", subject[j], results[i][j]);
                            } else {
                                reproved++; 
                                printf("\t%s Reproved\t\t%.2f", subject[j], results[i][j]);
                            }
                        }
                        printf("%s Approved: %d Reproved: %d\n\n", name[i], approved, reproved);
                    }
                break;
            }
        break;
    } 
   } while(opt != 5);
}
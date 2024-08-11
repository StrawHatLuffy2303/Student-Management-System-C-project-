#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct Student_data
{
  int roll;
  char name[20];
  char remark[10];
  float paper_1;
  float paper_2;
  float paper_3;
  float result;
};

int main()
{
  int ch, n = 0, k = 1, v = 0, z = 1, j, i = 0, x = 0, p1, p2, p3, temp, count = 0;
  int total, found = 0, roll_no;
  char search[10], out, newname[20];

  struct Student_data stu[100];

  FILE *data, *data1;

  data = fopen("Student_Datbase.txt", "r");

  if (data != NULL)
  {
    printf("File Found");
    while (!feof(data))
    {
      fscanf(data, "%d\t%s\t%f\t%f\t%f\t%f\t%s\n", &stu[i].roll, &stu[i].name, &stu[i].paper_1, &stu[i].paper_2, &stu[i].paper_3, &stu[i].result, &stu[i].remark);
      i++;
    }
    n = i;
  }
  else if (data == NULL)
  {
    printf("File not found\n");
    printf("Creating New File For You");
    data = fopen("Student_Datbase.txt", "w");
    fclose(data);
  }

  printf("\n---------------------------------------\n");
  printf("  Welcome Student Management System\n");
  printf("---------------------------------------");

  while (k)
  {
    printf("\n\n1. Add Student\n");
    printf("2. Show Student\n");
    printf("3. Delete Student\n");
    printf("4. Update Student\n");
    printf("5. Search Student\n");
    printf("0. Exit\n");

    printf("\nEnter the Choice:");
    scanf("%d", &ch);

    switch (ch)
    {
      /*------------------------------------------------------------ADD STUDENT----------------------------------------------------------------------*/
    case 1:

      printf("Number of Student:");
      scanf("%d", &v);

      for (j = 0; j < v; j++)
      {
        printf("\nStudent %d\n", n + 1);
        while (z)
        {
          printf("Roll no.-");
          scanf("%d", &temp);

          for (i = 0; i < n; i++)
          {

            if (stu[i].roll == temp)
            {
              printf("Please use new roll,its already in use\n");
            }
            else
            {

              count++;
            }
          }

          if (count == n)
          {

            stu[n].roll = temp;
            printf("Name-");
            scanf("%s", &stu[n].name);
            printf("Marks-\n");
            printf("Paper 1-");
            scanf("%f", &stu[n].paper_1);
            printf("Paper 2-");
            scanf("%f", &stu[n].paper_2);
            printf("Paper 3-");
            scanf("%f", &stu[n].paper_3);

            stu[n].result = stu[n].paper_1 + stu[n].paper_2 + stu[n].paper_3;

            printf("Record Save...!");
            data = fopen("Student_Datbase.txt", "a");

            if (stu[n].result > 150)
            {
              strcpy(stu[n].remark, "Pass");
            }
            else
            {
              strcpy(stu[n].remark, "Fail");
            }
            fprintf(data, "%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n", stu[n].roll, stu[n].name, stu[n].paper_1, stu[n].paper_2, stu[n].paper_3, stu[n].result, stu[n].remark);

            fclose(data);
            z = 0;
            n++;
          }
          count = 0;
        }
        z = 1;
      }

      break;
      /*-----------------------------------------------------------SHOW STUDENTS-----------------------------------------------------------------------------*/
    case 2:

      printf("----------------------------------------------------------------------------------------\n");
      printf("|   Roll   |   Name   |   Paper1   |   Paper2   |   Paper3   |   Result   |   Remark   |\n");
      printf("----------------------------------------------------------------------------------------\n");
      for (i = 0; i < n + v; i++)
      {
        if (stu[i].roll != 0)
        {
          printf("%6d \t%11s \t%8.2f \t%5.2f \t%10.2f \t%8.2f \t%s\n", stu[i].roll, stu[i].name, stu[i].paper_1, stu[i].paper_2, stu[i].paper_3, stu[i].result, stu[i].remark);
        }
      }

      printf("All Record Show...!\n\n");

      break;
      /*-------------------------------------------------------------DELETE STUDENTS------------------------------------------------------------------------*/
    case 3:
      printf("Delete Record:\n");
      printf("Enter Student Roll:");
      scanf("%d", &roll_no);

      for (i = 0; i < n; i++)
      {
        if (roll_no == stu[i].roll)
        {
          printf("----------------------------------------------------------------------------------------\n");
          printf("|   Roll   |   Name   |   Paper1   |   Paper2   |   Paper3   |   Result   |   Remark   |\n");
          printf("----------------------------------------------------------------------------------------\n");
          printf("%6d \t%11s \t%8.2f \t%5.2f \t%10.2f \t%8.2f \t%s\n", stu[i].roll, stu[i].name, stu[i].paper_1, stu[i].paper_2, stu[i].paper_3, stu[i].result, stu[i].remark);

          printf("Do you really want to Delete(Y/N)");
          scanf(" %c", &out);

          if (out == 'Y' || out == 'y')
          {
            stu[i].roll = 0;
            strcpy(stu[i].name, " ");
            stu[i].paper_1 = 0;
            stu[i].paper_2 = 0;
            stu[i].paper_3 = 0;
            stu[i].result = 0;
            strcpy(stu[i].remark, " ");
            printf("OK RECORD DELETED....\n");
          }
          else
          {
            printf("OK NO RECORD DELETED.....\n");
          }
        }
        else
        {
          count++;
        }
        if (count == n)
        {
          printf("NO RECORD FOUND....");
        }
      }

      data = fopen("Student_Datbase.txt", "w");
      for (i = 0; i < n; i++)
      {
        if (stu[i].roll != 0)
        {
          fprintf(data, "%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n", stu[i].roll, stu[i].name, stu[i].paper_1, stu[i].paper_2, stu[i].paper_3, stu[i].result, stu[i].remark);
        }
      }
      fclose(data);

      break;
       /*-----------------------------------------------------------------UPDATE RECORDS------------------------------------------------------------------------*/
    case 4:

      data = fopen("Student_Datbase.txt", "r");

      printf("Update Record:\n");
      printf("Enter Student Roll:");
      scanf("%d", &roll_no);

      printf("Update\n");
      printf("1. Name\n");
      printf("2. Paper1\n");
      printf("3. Paper2\n");
      printf("4. Paper3\n");

      printf("Choice:");
      scanf("%d", &ch);

      switch (ch)
      {
      case 1:
        for (i = 0; i < n; i++)
        {

          if (stu[i].roll == roll_no)
          {
            printf("-----------------------------\n");
            printf("|   Roll   |  Current Name  |\n");
            printf("-----------------------------\n");
            printf("%6d \t%11s", stu[i].roll, stu[i].name);
            printf("\nEnter new  name:");
            scanf("%s", &newname);

            printf("Do you really want to change name %s to %s ", stu[i].name, newname);
            out = getche();

            if (out == 'Y' || out == 'y')
            {
              strcpy(stu[i].name, newname);
              printf("...OK NAME UPDATED\n");
            }
            else
            {
              printf("...OK NO RECORD UPDATED\n");
            }
          }
          x++;
        }

        data = fopen("Student_Datbase.txt", "w");
        for (i = 0; i < x; i++)
        {
          fprintf(data, "%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n", stu[i].roll, stu[i].name, stu[i].paper_1, stu[i].paper_2, stu[i].paper_3, stu[i].result, stu[i].remark);
        }
        fclose(data);
        break;

      case 2:
        for (i = 0; i < n; i++)
        {

          if (stu[i].roll == roll_no)
          {
            printf("------------------------------------\n");
            printf("|   Roll   |   Name   |   Paper1   |\n");
            printf("------------------------------------\n");
            printf("%6d \t%11s \t%8.2f", stu[i].roll, stu[i].name, stu[i].paper_1);
            printf("\nEnter new  paper number:");
            scanf("%d", &p1);

            stu[i].paper_1 = p1;
            printf("...OK PAPER1 UPDATED\n");
          }
          x++;
        }

        data = fopen("Student_Datbase.txt", "w");
        for (i = 0; i < x; i++)
        {
          fprintf(data, "%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n", stu[i].roll, stu[i].name, stu[i].paper_1, stu[i].paper_2, stu[i].paper_3, stu[i].result, stu[i].remark);
        }
        fclose(data);
        break;

      case 3:
        for (i = 0; i < n; i++)
        {

          if (stu[i].roll == roll_no)
          {
            printf("------------------------------------\n");
            printf("|   Roll   |   Name   |   Paper2   |\n");
            printf("------------------------------------\n");
            printf("%6d \t%11s \t%8.2f", stu[i].roll, stu[i].name, stu[i].paper_2);
            printf("\nEnter new  paper number:");
            scanf("%d", &p2);

            stu[i].paper_1 = p2;
            printf("...OK PAPER2 UPDATED\n");
          }
          x++;
        }

        data = fopen("Student_Datbase.txt", "w");
        for (i = 0; i < x; i++)
        {
          fprintf(data, "%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n", stu[i].roll, stu[i].name, stu[i].paper_1, stu[i].paper_2, stu[i].paper_3, stu[i].result, stu[i].remark);
        }
        fclose(data);
        break;

      case 4:
        for (i = 0; i < n; i++)
        {

          if (stu[i].roll == roll_no)
          {
            printf("------------------------------------\n");
            printf("|   Roll   |   Name   |   Paper3   |\n");
            printf("------------------------------------\n");
            printf("%6d \t%11s \t%8.2f", stu[i].roll, stu[i].name, stu[i].paper_3);
            printf("\nEnter new  paper number:");
            scanf("%d", &p3);

            stu[i].paper_1 = p3;
            printf("...OK PAPER3 UPDATED\n");
          }
          x++;
        }

        data = fopen("Student_Datbase.txt", "w");
        for (i = 0; i < x; i++)
        {
          fprintf(data, "%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n", stu[i].roll, stu[i].name, stu[i].paper_1, stu[i].paper_2, stu[i].paper_3, stu[i].result, stu[i].remark);
        }
        fclose(data);
        break;
      }

      break;
        /*-------------------------------------------------------------SEARCH STUDENTS---------------------------------------------------------------------------*/
    case 5:

      printf("Search:\n");
      printf("1. Search by name\n");
      printf("2. Serach by Roll no.\n");
      printf("Enter Chhoice:");
      scanf("%d", &ch);

      if (ch == 1)
      {
        printf("Enter Student Name:");
        scanf("%s", &search);

        data = fopen("Student_Datbase.txt", "r");

        while (!feof(data))
        {
          fscanf(data, "%d\t%s\t%f\t%f\t%f\t%f\t%s\n", &stu[i].roll, &stu[i].name, &stu[i].paper_1, &stu[i].paper_2, &stu[i].paper_3, &stu[i].result, &stu[i].remark);
          if (strcmp(search, stu[i].name) == 0)
          {
            printf("----------------------------------------------------------------------------------------\n");
            printf("|   Roll   |   Name   |   Paper1   |   Paper2   |   Paper3   |   Result   |   Remark   |\n");
            printf("----------------------------------------------------------------------------------------\n");
            printf("%6d \t%11s \t%8.2f \t%5.2f \t%10.2f \t%8.2f \t%s\n", stu[i].roll, stu[i].name, stu[i].paper_1, stu[i].paper_2, stu[i].paper_3, stu[i].result, stu[i].remark);
            printf("SEARCH DONE...\n");
          }
        }

        fclose(data);
      }

      else if (ch == 2)
      {
        printf("Enter Roll no:");
        scanf("%d", &roll_no);

        data = fopen("Student_Datbase.txt", "r");

        while (!feof(data))
        {
          fscanf(data, "%d\t%s\t%f\t%f\t%f\t%f\t%s\n", &stu[i].roll, &stu[i].name, &stu[i].paper_1, &stu[i].paper_2, &stu[i].paper_3, &stu[i].result, &stu[i].remark);
          if (stu[i].roll = roll_no)
          {
            printf("----------------------------------------------------------------------------------------\n");
            printf("|   Roll   |   Name   |   Paper1   |   Paper2   |   Paper3   |   Result   |   Remark   |\n");
            printf("----------------------------------------------------------------------------------------\n");
            printf("%6d \t%11s \t%8.2f \t%5.2f \t%10.2f \t%8.2f \t%s\n", stu[i].roll, stu[i].name, stu[i].paper_1, stu[i].paper_2, stu[i].paper_3, stu[i].result, stu[i].remark);
            printf("SEARCH DONE...\n");
          }
        }

        fclose(data);
      }
      break;
       /*--------------------------------------------------------------------------EXIT---------------------------------------------------------------------------*/
    case 0:

      printf("NOTE: AFTER EXITING SYSTEM ALL RECORD IS DELETE AUTOMATICALLY....");
      printf("DO YOU WANT TO EXIT?(y/n)");
      scanf(" %c", &out);
      if (out == 'Y' || out == 'y')
      {
        k = 0;
      }

      break;

    default:
       printf("Entered Wrong Choice.....\n");
       printf("Please Enter Correct Choice----");
      break;
    }
  }

  fclose(data);

  return 0;
}
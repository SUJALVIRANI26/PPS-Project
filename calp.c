#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <stdbool.h>


#define M_PI 3.14159265358979323846

typedef struct
{
    double a;
    char c;
    double b;
    double ans;
} Basic;

typedef struct
{
    int r1;
    int r2;
    int c1;
    int c2;
    int **ptr1;
    int **ptr2;
} Matrix;

typedef struct
{
    double var;
} Log;

typedef struct
{
    double var;
    int m;
} Trigonometry;

bool Quit()
{
    char s[100];
    fgets(s, sizeof(s), stdin);
    if (strncmp(s, "wq", 2) == 0)
        return true;
    else
        return false;
    fflush(stdin);
    return false;
}

bool Quit_int(int n)
{
    char s[100];
    while (1)
    {
        printf("Enter 'wq' for <-back : ");
        fgets(s, 100, stdin);
        if (strncmp(s, "wq",2) == 0)
            return true;
        else
            printf("Wrong input\n");
    }
}

void setcolor()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
}

void print_instruction()
{
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  printf("Enter 'wq' for <- back \n\n");
}



double fact(int n)
{
    if(n <= 0 || n == 1 )
    return 1;
    else
    return n * fact(n-1);
}

void factorial_calculation()
{
    print_instruction();
    setcolor();

    int var;
    while (1)
    {
        printf("Enter number for which you want to find factorial: ");
        if (scanf("%d", &var) != 1)
        {
            if (Quit())
                return;
            else
            {
                printf("Please enter valid number\n");
            }
        }
        else
        {
            printf("%d! = %lf\n\n", var, fact(var));
            fflush(stdin);
        }
    }
}

 double power(double a ,  int n)
 {
    long double sum=1;

    for(int i=0 ; i < n ; i++)
      sum*=a;

    return sum;
 }
double exponential(double a)
{
    long double result=0;
    for(int i=0; i < 20 ; i++ )
    {
        result+=power(a,i)/fact(i);
    }
    return result;
}

void exponential_calculation()
{
   print_instruction();
   setcolor();

    double var;
    while (1)
    {
        printf("Enter number for which you wnat to find exponential: ");
        if (scanf("%lf", &var) != 1)
        {
            if (Quit())
                return;
            else
            {
                printf("Not a number\n");
                fflush(stdin);
            }
        }
        else
        {
            printf("Ans = %lf\n", exponential(var));
            fflush(stdin);
        }
    }
}

void log_base_e()
{
    print_instruction();
    setcolor();

    Log loge;
    while (1)
    {
        printf("Enter number for which you want to find logerithem: ");
        while (scanf("%lf", &loge.var) != 1)
        {
            if (Quit())
                return;
            else
            {
                printf("Please enter valid number\n");
                fflush(stdin);
            }
        }
        printf("ln(%lf) = %lf\n", loge.var, log(loge.var));
        fflush(stdin);
    }
}

void log_base_10()
{
    print_instruction();
    setcolor();
    Log log;
    while (1)
    {
        printf("Enter number for which you want to find logerithem: ");
        while (scanf("%lf", &log.var) != 1)
        {
            if (Quit())
                return;
            else
            {
                printf("Please enter valid number\n");
            }
        }
        printf("log(%lf): %lf\n", log.var, log10(log.var));
        fflush(stdin);
    }
}

void logarithm_calculation()
{
    while (1)
    {
        system("cls");
       setcolor();

        printf("1: log value base 10\n");
        printf("2: log value base e\n");
        printf("3: back\n");
        int n;
        printf("Enter your choice: ");

        while (scanf("%d", &n) != 1 || !(n > 0 && n < 4))
        {
            if (Quit())
                return;
            else
            {
                printf("Please enter valid number: ");
                fflush(stdin);
            }
        }

        system("cls");
        switch (n)
        {
        case 1:
            log_base_10();
            break;
        case 2:
            log_base_e();
            break;
        case 3:
            return;
        }
    }
}

void trigonometry_function(bool is_inverse, int n, Trigonometry *trig)
{
    print_instruction();
    setcolor();

    while (1)
    {
        while (scanf("%lf", &trig->var) != 1)
        {
            if (Quit())
                return;
            else
            {
                printf("Please enter valid number\n");
                fflush(stdin);
            }
        }

        double x;
        x=trig->var;
        if(!is_inverse)
        {
         if (trig->m == 2)
            trig->var = (trig->var * M_PI) / 180.0;
        }
        if (is_inverse)
        {
            if (trig->m == 2)
            {
                switch (n)
                {
                case 1:
                    printf("Inverse of sin %lf: %lf\n", x, (asin(trig->var) * 180.0) / M_PI);
                    break;
                case 2:
                    printf("Inverse of cos %lf: %lf\n", x, (acos(trig->var) * 180.0) / M_PI);
                    break;
                case 3:
                    printf("Inverse of tan %lf: %lf\n", x, (atan(trig->var) * 180.0) / M_PI);
                    break;
                case 4:
                    printf("Inverse of cosec %lf: %lf\n", x, (asin(1 / trig->var) * 180.0) / M_PI);
                    break;
                case 5:
                    printf("Inverse of sec %lf: %lf\n", x, (acos(1 / trig->var) * 180.0) / M_PI);
                    break;
                case 6:
                    printf("Inverse of cot %lf: %lf\n", x, (atan(1 / trig->var) * 180.0) / M_PI);
                    break;
                }

            }
            else
            {
                switch (n)
                {
                case 1:
                    printf("Inverse of sin %lf: %lf\n", x, asin(trig->var));
                    break;
                case 2:
                    printf("Inverse of cos %lf: %lf\n", x, acos(trig->var));
                    break;
                case 3:
                    printf("Inverse of tan %lf: %lf\n", x, atan(trig->var));
                    break;
                case 4:
                    printf("Inverse of cosec %lf: %lf\n", x, asin(1 / trig->var));
                    break;
                case 5:
                    printf("Inverse of sec %lf: %lf\n", x, acos(1 / trig->var));
                    break;
                case 6:
                    printf("Inverse of cot %lf: %lf\n", x, atan(1 / trig->var));
                    break;
                }
            }
        }
        else
        {
            switch (n)
            {
            case 1:
                printf("sin(%lf) = %lf\n", x, sin(trig->var));
                break;
            case 2:
                printf("cos(%lf) = %lf\n", x, cos(trig->var));
                break;
            case 3:
                printf("tan(%lf) = %lf\n", x, tan(trig->var));
                break;
            case 4:
                printf("cosec(%lf) = %lf\n", x, (1 / sin(trig->var)));
                break;
            case 5:
                printf("sec(%lf) = %lf\n", x, (1 / cos(trig->var)));
                break;
            case 6:
                printf("cot(%lf) = %lf\n", x, (1 / tan(trig->var)));
                break;
            }
        }
        fflush(stdin);
    }
}

int trigo(bool is_inverse)
{
    system("cls");

    if (is_inverse)
    {
        printf("1: for Inverse of sin\n");
        printf("2: for Inverse of cos\n");
        printf("3: for Inverse of tan\n");
        printf("4: for Inverse of cosec\n");
        printf("5: for Inverse of sec\n");
        printf("6: for Inverse of cot\n");
    }
    else
    {
        printf("1: sin0\n");
        printf("2: cos0\n");
        printf("3: tan0\n");
        printf("4: cosec0\n");
        printf("5: sec0\n");
        printf("6: cot0\n");
    }
    printf("7: back\n");
    printf("Enter your choice: ");

    int n;
    while (scanf("%d", &n) != 1 || (n > 7 || n <= 0))
    {
        if (Quit())
            return 7;
        else
        {
            printf("Please enter valid number\n");
            fflush(stdin);
        }
    }
    return n;
}

bool trig_fun(Trigonometry *trig)
{
    system("cls");

    printf("1: for angle in radian\n");
    printf("2: for angle in degree\n");
    printf("3: back\n");
    printf("Enter your choice: ");

    while (scanf("%d", &trig->m) != 1 || (trig->m > 3 || trig->m <= 0))
    {
        if (Quit())
            return true;
        else
        {
            printf("Please enter valid number\n");
            fflush(stdin);
        }
    }
    return (trig->m == 3);
}

void trigonometry_calculation(bool is_inverse)
{
    Trigonometry trig;
    int k;

    while (!trig_fun(&trig))
    {
        while ((k = trigo(is_inverse)) != 7)
            trigonometry_function(is_inverse, k, &trig);
    }
}

void free_matrix(Matrix *m)
{
    for (int i = 0; i < m->r1; i++)
        free(m->ptr1[i]);

    for (int i = 0; i < m->r2; i++)
        free(m->ptr2[i]);

    free(m->ptr1);
    free(m->ptr2);
    free(m);
}


void matrix_add(Matrix *m)
{
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("Enter 'wq' for <- back\n\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);

    for (int i = 0 ; i < m->r1 ; i++)
    {
        for (int j = 0; j < m->c1; j++)
            printf("%d ", m->ptr1[i][j] + m->ptr2[i][j]);
        printf("\n");
    }

    Quit_int(1);
}

void matrix_subtract(Matrix *m)
{
 print_instruction();
 setcolor();

    for (int i = 0; i < m->r1; i++)
    {
        for (int j = 0 ; j < m->c1 ; j++)
            printf("%d ", m->ptr1[i][j] - m->ptr2[i][j]);
        printf("\n");
    }

    Quit_int(1);
}

void matrix_multiply(Matrix *m)
{
  print_instruction();
  setcolor();
    for (int i = 0; i < m->r1; i++)
    {
        for (int j = 0; j < m->c2; j++)
        {
            double temp = 0;
            for (int k = 0 ; k < m->c1 ; k++)
                temp += (m->ptr1[i][k]) * (m->ptr2[k][j]);
            printf("%.0lf ", temp);
        }
        printf("\n");
    }
    Quit_int(1);
}

void matrix_operations(Matrix *m)
{
    while (1)
    {
        system("cls");

        printf("1: add\n");
        printf("2: subtract\n");
        printf("3: multiplication\n");
        printf("4: back\n");
        printf("Enter your choice:");

        int k;
        
            while (scanf("%d", &k) != 1 || !(k > 0 && k <= 4))
            {
                if (Quit())
                    return;
                else
                    printf("Please enter number between 1 to 4: ");
            }

        switch (k)
        {
        case 1:
            if (m->r1 == m->r2 && m->c1 == m->c2)
                matrix_add(m);
            else
            {
                printf("addition is not possible\n");
                getchar();
                printf("Enter any key to continue.....\n");
                getchar();
            }
            break;
        case 2:
            if (m->r1 == m->r2 && m->c1 == m->c2)
                matrix_subtract(m);
            else
            {
                printf("subtraction is not possible\n");
                getchar();
                printf("Enter any key to continue.....\n");
                getchar();
            }
            break;
        case 3:
            if (m->c1 == m->r2)
                matrix_multiply(m);
            else
            {
                printf("multiplication is not possible\n");
                 getchar();
                printf("Enter any key to continue.....\n");
                getchar();
            }
            break;
        case 4:
            return;
        }
    }
}

bool read_matrix(Matrix *m)
{
    printf("Enter first matrix\n");
    for (int i = 0 ; i < m->r1 ; i++)
    {
        for (int j = 0; j < m->c1; j++)
        {
            while (scanf("%d", &m->ptr1[i][j]) != 1)
            {
                if (Quit())
                    return false;
                else
                {
                    printf("Please enter number:\n");
                    fflush(stdin);
                }
            }
        }
    }
    fflush(stdin);
    printf("\nEnter second matrix\n");
    for (int i = 0 ; i < m->r2 ; i++)
    {
        for (int j = 0 ; j < m->c2 ; j++)
        {
            while (scanf("%d", &m->ptr2[i][j]) != 1)
            {
                if (Quit())
                    return false;
                else
                {
                    printf("Please enter number:\n");
                    fflush(stdin);
                }
            }
        }
        printf("\n");
    }
    fflush(stdin);
    return true;
}

Matrix *create_matrix(int r1, int c1, int r2, int c2)
{
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    m->r1 = r1;
    m->c1 = c1;
    m->r2 = r2;
    m->c2 = c2;

    m->ptr1 = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++)
        m->ptr1[i] = (int *)malloc(c1 * sizeof(int));

    m->ptr2 = (int **)malloc(r2 * sizeof(int *));
    for (int i = 0; i < r2; i++)
        m->ptr2[i] = (int *)malloc(c2 * sizeof(int));

    return m;
}

void matrix_calculation()
{
    print_instruction();
    setcolor();

    int r1, r2, c1, c2;
    printf("Enter First matrix's number of rows: ");
    while (scanf("%d", &r1) != 1)
    {
        if (Quit())
            return;
        else
            printf("Please Enter number: ");
    }
    fflush(stdin);
    printf("Enter First matrix's number of colums: ");
    while (scanf("%d", &c1) != 1)
    {
        if (Quit())
            return;
        else
        {
            printf("Please Enter number: ");
        }
    }
    fflush(stdin);

    printf("\nEnter Second matrix's number of rows: ");
    while (scanf("%d", &r2) != 1)
    {
        if (Quit())
            return;
        else
        {
            printf("Please Enter number: ");
        }
    }
    fflush(stdin);

    printf("Enter Second matrix's number of colums: ");
    while (scanf("%d", &c2) != 1)
    {
        if (Quit())
            return;
        else
        {
            printf("Please Enter number: ");
        }
    }
    fflush(stdin);
    printf("\n");

    Matrix *matrix1 = create_matrix(r1, c1, r2, c2);
    if (read_matrix(matrix1))
        matrix_operations(matrix1);
    free_matrix(matrix1);
}

void basic_calculation()
{
    print_instruction();
    setcolor();

    Basic basic_cal;
    while (1)
    {
        while (scanf("%lf %c %lf", &basic_cal.a, &basic_cal.c, &basic_cal.b) != 3)
        {
            if (Quit())
                return;
            else
            {
                printf("Not a number\n");
            }
        }
        switch (basic_cal.c)
        {
        case '+':
            printf("Ans = %lf\n", basic_cal.a + basic_cal.b);
            break;
        case '-':
            printf("Ans = %lf\n", basic_cal.a - basic_cal.b);
            break;
        case '*':
            printf("Ans = %lf\n", basic_cal.a * basic_cal.b);
            break;
        case '/':
            printf("Ans = %lf\n", basic_cal.a / basic_cal.b);
            break;
        case '^':
            printf("Ans = %lf\n", pow(basic_cal.a, basic_cal.b));
            break;
        default:
            printf("Please Enter valid operator\n");
            break;
        }
        fflush(stdin);
    }
}

int main()
{
    setcolor();
    int n;
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("                                           __        __   _                            _ \n");
    printf("                                           \\ \\      / /__| | ___ ___  _ __ ___   ___  | |\n");
    printf("                                            \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | |\n");
    printf("                                             \\ V  V /  __/ | (_| (_) | | | | | |  __/ |_|\n");
    printf("                                              \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___| (_)\n");

    printf("Enter any key to continue ........  ");
    getchar();

    while (1)
    {
        system("cls");
        printf("\n");
        printf("1: Basic calculation\n");
        printf("2: For matrix calculation\n");
        printf("3: For triginomatric calculation\n");
        printf("4: For inverse trigonomtric calculation\n");
        printf("5: For logerithem\n");
        printf("6: For exponential function base e\n");
        printf("7: For factorial of any number\n");
        printf("8: Quit from calculator\n");
        printf("Enter your choice: ");

        while (scanf("%d", &n) != 1 || !(n > 0 && n <= 8))
        {
            if (Quit())
                return 0;
            else
            {
                printf("Please enter valid number: ");
                fflush(stdin);
            }
        }

        switch (n)
        {
        case 1:
            basic_calculation();
            break;
        case 2:
            matrix_calculation();
            break;
        case 3:
            trigonometry_calculation(false);
            break;
        case 4:
            trigonometry_calculation(true);
            break;
        case 5:
            logarithm_calculation();
            break;
        case 6:
            exponential_calculation();
            break;
        case 7:
            factorial_calculation();
            break;
        case 8:
            return 0;
        }
    }
}
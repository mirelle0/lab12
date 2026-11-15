#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

int task1()
{
    setlocale(LC_ALL, "RUS");
    char fname[20] = "number.txt"; 
    FILE* out; 
    puts("Создание файла");
    if ((out = fopen(fname, "a")) == NULL)
    {
        printf("Ошибка открытия файла для записи");
        return 0;
    }
    fprintf(out, "%d\n", 5); 
    fprintf(out, "%.2f\n", 12.56);
    fclose(out); 
    return 1;
}

int task2()
{
    setlocale(LC_ALL, "RUS");
    FILE* out;
    char fname[] = "temp.txt";
    int choice;
    double start, end, step, x, y;
    double c;

    printf("=== Табулирование функции y = x - 3*cos^2(1.04x) ===\n");
    printf("Введите начало интервала:");
    scanf("%lf", &start);
    printf("Введите конец интервала:");
    scanf("%lf", &end);
    printf("Введите шаг:");
    scanf("%lf", &step);

    printf("\nВыберите действие:\n");
    printf("  1) Записать в новый файл\n");
    printf("  2) Дописать в существующий файл\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    if (choice == 1) {
        out = fopen(fname, "wt");
    }
    else {
        out = fopen(fname, "at");
    }

    fprintf(out, "--- y = x - 3*cos^2(1.04x), x = [%.2f; %.2f], шаг = %.2f ---\n", start, end, step);
    fprintf(out, "%10s %15s\n", "x", "y");

    for (x = start; x <= end + step / 1000.0; x += step) {
        c = cos(1.04 * x);
        y = x - 3.0 * c * c;
        fprintf(out, "%10.3f %15.4f\n", x, y);
    }
    fprintf(out, "\n");

    fclose(out);
    printf("\nРезультат записан в %s\n", fname);
    return 0;
}

int main()
{
    task2();
}

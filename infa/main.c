#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <windows.h>

int main() {
    // Настройка кодировки консоли Windows на UTF-8 для корректного вывода кириллицы
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    printf("=================================================================\n");
    printf("ЛАБОРАТОРНАЯ РАБОТА №1. БАЗОВЫЕ ТИПЫ ДАННЫХ ЯЗЫКА СИ\n");
    printf("Студент: Чнаваян Адриан | Группа: М03-104БВ-26 | Вариант: 29\n");
    printf("=================================================================\n\n");

    // =========================================================================
    // ЗАДАНИЕ 1: Ввод/вывод, форматирование, системы счисления, sizeof()
    // =========================================================================
    printf("--- ЗАДАНИЕ 1 ---\n");
    char c_val;
    int i_val;
    float f_val;
    double d_val;

    // 1.1 Отдельный ввод каждого типа и мгновенная эхопечать
    printf("Введите символ (char): ");
    scanf(" %c", &c_val); // пробел перед %c обязателен, чтобы пропустить остаточный Enter
    printf("Эхопечать char: %c\n\n", c_val);

    printf("Введите целое число (int): ");
    scanf("%d", &i_val);
    printf("Эхопечать int: %d\n\n", i_val);

    printf("Введите вещественное число (float): ");
    scanf("%f", &f_val);
    printf("Эхопечать float: %f\n\n", f_val);

    printf("Введите вещественное число двойной точности (double): ");
    scanf("%lf", &d_val);
    printf("Эхопечать double: %lf\n\n", d_val);

    // 1.2 Второй вариант вывода ОДНИМ оператором printf с шириной поля и точностью
    printf("1.2 Вывод одним printf (ширина и точность):\n");
    printf("char=[%4c] | int=[%8d] | float=[%10.2f] | double=[%12.4lf]\n\n",
           c_val, i_val, f_val, d_val);

    // 1.3 Третий вариант печати: разные системы счисления и экспоненциальный вид
    printf("1.3 Разные системы счисления и экспоненциальный вид:\n");
    printf("char:   символ='%c', dec=%d, oct=%o, hex=%X\n",
           c_val, (unsigned char)c_val, (unsigned char)c_val, (unsigned char)c_val);
    printf("int:    dec=%d, oct=%o, hex=%X\n", i_val, i_val, i_val);
    printf("float:  exp=%e\n", f_val);
    printf("double: exp=%e\n\n", d_val);

    // 1.4 Размер каждого типа данных в байтах через sizeof()
    printf("1.4 Размеры типов данных в памяти (sizeof):\n");
    printf("sizeof(char)   = %zu байт\n", sizeof(char)); // %zu используется для вывода значения типа size_t
    printf("sizeof(int)    = %zu байт\n", sizeof(int));
    printf("sizeof(float)  = %zu байт\n", sizeof(float));
    printf("sizeof(double) = %zu байт\n\n", sizeof(double));

    // =========================================================================
    // ЗАДАНИЕ 2: Предельные значения из limits.h и float.h
    // =========================================================================
    printf("--- ЗАДАНИЕ 2 (Границы типов из limits.h и float.h) ---\n");
    printf("CHAR_MIN   = %d \t\t CHAR_MAX   = %d\n", CHAR_MIN, CHAR_MAX);
    printf("UCHAR_MAX  = %u\n", UCHAR_MAX);
    printf("INT_MIN    = %d \t INT_MAX    = %d\n", INT_MIN, INT_MAX);
    printf("UINT_MAX   = %u\n", UINT_MAX);
    printf("FLT_MIN    = %e \t FLT_MAX    = %e\n", FLT_MIN, FLT_MAX);
    printf("DBL_MIN    = %e \t DBL_MAX    = %e\n\n", DBL_MIN, DBL_MAX);

    // =========================================================================
    // ЗАДАНИЕ 3: Цепочки преобразования типов (расширение и усечение)
    // =========================================================================
    printf("--- ЗАДАНИЕ 3 (Цепочки преобразований типов) ---\n");
    char c3;
    short int s3;
    int i3;
    unsigned char uc3;
    unsigned short int us3;
    unsigned int ui3;

    // ЭТАП 1: Максимальные значения из limits.h
    printf("\n[Этап 1: Максимальные значения]\n");
    c3 = CHAR_MAX;
    s3 = c3;
    i3 = s3;
    printf("char -> short -> int:                %d -> %d -> %d\n", c3, s3, i3);

    uc3 = UCHAR_MAX;
    us3 = uc3;
    ui3 = us3;
    printf("uchar -> ushort -> uint:             %u -> %u -> %u\n", uc3, us3, ui3);

    i3 = INT_MAX;
    s3 = i3;
    c3 = s3;
    printf("int -> short -> char:                %d -> %d -> %d\n", i3, s3, c3);

    ui3 = UINT_MAX;
    us3 = ui3;
    uc3 = us3;
    printf("uint -> ushort -> uchar:             %u -> %u -> %u\n", ui3, us3, uc3);

    // ЭТАП 2: Минимальные значения из limits.h
    printf("\n[Этап 2: Минимальные значения]\n");
    c3 = CHAR_MIN;
    s3 = c3;
    i3 = s3;
    printf("char -> short -> int:                %d -> %d -> %d\n", c3, s3, i3);

    i3 = INT_MIN;
    s3 = i3;
    c3 = s3;
    printf("int -> short -> char:                %d -> %d -> %d\n", i3, s3, c3);

    // ЭТАП 3: Произвольные значения (включая отрицательный int)
    printf("\n[Этап 3: Произвольные значения]\n");
    c3 = 100;
    s3 = c3;
    i3 = s3;
    printf("char -> short -> int:                %d -> %d -> %d\n", c3, s3, i3);

    uc3 = 200;
    us3 = uc3;
    ui3 = us3;
    printf("uchar -> ushort -> uint:             %u -> %u -> %u\n", uc3, us3, ui3);

    // Пример усечения положительного int (483 как в примере из методички)
    i3 = 483;
    s3 = i3;
    c3 = s3;
    printf("int(483) -> short -> char:           %d -> %d -> %d\n", i3, s3, c3);

    // Пример усечения отрицательного int (-300)
    i3 = -300;
    s3 = i3;
    c3 = s3;
    printf("int(-300) -> short -> char:          %d -> %d -> %d\n", i3, s3, c3);

    ui3 = 70000;
    us3 = ui3;
    uc3 = us3;
    printf("uint(70000) -> ushort -> uchar:      %u -> %u -> %u\n\n", ui3, us3, uc3);

    // =========================================================================
    // ЗАДАНИЕ 4: Переполнение границ типов (+1 и -1)
    // =========================================================================
    printf("--- ЗАДАНИЕ 4 (Переполнение границ типов) ---\n");
    int s_max = INT_MAX;
    printf("signed int MAX:   %d  ->  MAX + 1: ", s_max);
    s_max = s_max + 1;
    printf("%d\n", s_max);

    unsigned int u_max = UINT_MAX;
    printf("unsigned int MAX: %u  ->  MAX + 1: ", u_max);
    u_max = u_max + 1;
    printf("%u\n", u_max);

    int s_min = INT_MIN;
    printf("signed int MIN:   %d ->  MIN - 1: ", s_min);
    s_min = s_min - 1;
    printf("%d\n", s_min);

    unsigned int u_min = 0;
    printf("unsigned int MIN: %u           ->  MIN - 1: ", u_min);
    u_min = u_min - 1;
    printf("%u\n", u_min);

    return 0;
}
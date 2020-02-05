/*
** EPITECH PROJECT, 2019
** CPool_Tree_2019
** File description:
** tree.c
*/

#include <unistd.h>

void check_error(int size)
{
    if (size <= 0 || size >= 100) {
        write(1, "Number is less 0 or more 100.\n", 15);
        return (1);
    }
    return (0);
}

int get_max_row(int nb)
{
    int line = 4;
    int max_row = 0;

    for (int i = 0; i != nb; i++, line++) {
        max_row += line;
    }
    return (max_row);
}

int get_max_col(int nb)
{
    int max_col = 1;
    int line = 4;
    int red = 1;
    
    for (int i = 0; i != nb; i++, line++) {
        max_col += (2 * (line - red));
        if (i % 2 == 0)
            red++;
    }
    return (max_col);
}

void tronc(int nb, int max_col)
{
    int size = nb;
    int ep = nb;

    if (nb % 2 == 0)
        ep++;
    for (int i = 0; i != size; i++) {
        for (int spc = 0; spc != (max_col / 2 - ep / 2); spc++)
            my_putchar(' ');
        for (int p = 0; p != ep; p++)
            my_putchar('|');
        my_putchar('\n');
    }
}

int tree(int size)
{
    int max_row = get_max_row(size);
    int max_col = get_max_col(size);
    int max_star = 1;
    int haut = size;
    int block = 1;
    int block_limit = get_max_row(block);
    int red = 0;
    int id_spc = 0;

    if (check_error == 1)
        return (84);
    for (int i = 0; i != max_row; i++) {
        if (i == block_limit) {
            block += 1;
            block_limit = get_max_row(block);
            red += (block % 2 == 0) ? 1 : 0;
            id_spc -= (red + 1);
        }
        for (int spc = 0; spc != max_col / 2 - id_spc; spc++)
            my_putchar(' ');
        for (int star = 0; star != 1 + (id_spc * 2); star++)
            my_putchar('*');
        my_putchar('\n');
        id_spc += 1;
    }
    tronc(size, max_col);
    return (1);
}

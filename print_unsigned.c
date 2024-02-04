#include "main.h"
/**
 * print_unt - prints an unsigned int
 * @arguments: number to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int print_unt(va_list arguments, char *buf, unsigned int ibuf)
{
        unsigned int int_in, int_temp, i, div;

        int_in = va_arg(arguments, unsigned int);
        int_temp = int_in;
        div = 1;
        while (int_temp > 9)
        {
                div *= 10;
                int_temp /= 10;
        }
        for (i = 0; div > 0; div /= 10, i++)
        {
                ibuf = handl_buf(buf, ((int_in / div) % 10) + '0', ibuf);
        }
        return (i);
}

#include "main.h"

/**
 * print_upx - prints a decimal in hexadecimal
 * @arguments: The character to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int print_upx(va_list arguments, char *buf, unsigned int ibuf)
{
        int int_input, i, isnegative, count, first_digit;
        char *hexadecimal, *binary;

        int_input = va_arg(arguments, int);
        isnegative = 0;
        if (int_input == 0)
        {
                ibuf = handl_buf(buf, '0', ibuf);
                return (1);
        }
        if (int_input < 0)
        {
                int_input = (int_input * -1) - 1;
                isnegative = 1;
        }
        binary = malloc(sizeof(char) * (32 + 1));
        binary = fill_binary_array(binary, int_input, isnegative, 32);
        hexadecimal = malloc(sizeof(char) * (8 + 1));
        hexadecimal = fill_hex_array(binary, hexadecimal, 1, 8);
        for (first_digit = i = count = 0; hexadecimal[i]; i++)
        {
                if (hexadecimal[i] != '0' && first_digit == 0)
                        first_digit = 1;
                if (first_digit)
                {
                        ibuf = handl_buf(buf, hexadecimal[i], ibuf);
                        count++;
                }
        }
        free(binary);
        free(hexadecimal);
        return (count);
}

#include "main.h"

/**
 * print_usr - prints a string and values of
 * non-printed chars
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int print_usr(va_list arguments, char *buf, unsigned int ibuf)
{
        unsigned char *str;
        char *hexadecimal, *binary;
        unsigned int i, sum, op;

        str = va_arg(arguments, unsigned char *);
        binary = malloc(sizeof(char) * (32 + 1));
        hexadecimal = malloc(sizeof(char) * (8 + 1));
        for (sum = i = 0; str[i]; i++)
        {
                if (str[i] < 32 || str[i] >= 127)
                {
                        ibuf = handl_buf(buf, '\\', ibuf);
                        ibuf = handl_buf(buf, 'x', ibuf);
                        op = str[i];
                        binary = fill_binary_array(binary, op, 0, 32);
                        hexadecimal = fill_hex_array(binary, hexadecimal, 1, 8);
                        ibuf = handl_buf(buf, hexadecimal[6], ibuf);
                        ibuf = handl_buf(buf, hexadecimal[7], ibuf);
                        sum += 3;
                }
                else
                        ibuf = handl_buf(buf, str[i], ibuf);
        }
        free(binary);
        free(hexadecimal);
        return (i + sum);
}

#include "main.h"
/********************************NO. 1.****************************************/
/******************************************************************************/

/**
 * prinhhex - prints a short decimal in hexadecimal
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 *
 * Return: number of chars printed
 */
int prinhhex(va_list arguments, char *buf, unsigned int ibuf)
{
        short int int_input, i, isnegative, count, first_digit;
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

        binary = malloc(sizeof(char) * (16 + 1));
        binary = fill_binary_array(binary, int_input, isnegative, 16);
        hexadecimal = malloc(sizeof(char) * (4 + 1));
        hexadecimal = fill_hex_array(binary, hexadecimal, 0, 4);
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
/********************************NO. 2.****************************************/
/******************************************************************************/

/**
 * prinhint - prints a short integer
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 *
 * Return: number of chars printed.
 */
int prinhint(va_list arguments, char *buf, unsigned int ibuf)
{
        short int int_input;
        unsigned short int int_in, int_temp, i, div, isneg;

        int_input = va_arg(arguments, int);
        isneg = 0;
        if (int_input < 0)
        {
                int_in = int_input * -1;
                ibuf = handl_buf(buf, '-', ibuf);
                isneg = 1;
        }
        else
        {
                int_in = int_input;
        }
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
        return (i + isneg);
}
/********************************NO. 3.****************************************/
/******************************************************************************/

/**
 * prinhoct - prints long decimal number in octal
 * @arguments: input number
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 *
 * Return: number of chars printed.
 */
int prinhoct(va_list arguments, char *buf, unsigned int ibuf)
{
        short int int_input, i, isnegative, count, first_digit;
        char *octal, *binary;

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

        binary = malloc(sizeof(char) * (16 + 1));
        binary = fill_binary_array(binary, int_input, isnegative, 16);
        octal = malloc(sizeof(char) * (6 + 1));
        octal = fill_short_oct_array(binary, octal);
        for (first_digit = i = count = 0; octal[i]; i++)
        {
                if (octal[i] != '0' && first_digit == 0)
                        first_digit = 1;
                if (first_digit)
                {
                        ibuf = handl_buf(buf, octal[i], ibuf);
                        count++;
                }
        }
        free(binary);
        free(octal);
        return (count);
}
/********************************NO. 4.****************************************/
/******************************************************************************/

/**
 * prinhunt - prints a short unsigned integer
 * @arguments: number to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 *
 * Return: number of chars printed.
 */
int prinhunt(va_list arguments, char *buf, unsigned int ibuf)
{
        unsigned short int int_in, int_temp, i, div;

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


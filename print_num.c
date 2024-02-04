#include "main.h"
/********************************NO. 1.****************************************/
/******************************************************************************/

/**
 * prinnhex - print number in hex begining with zero
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 *
 * Return: number of chars printed
 */
int prinnhex(va_list arguments, char *buf, unsigned int ibuf)
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
        ibuf = handl_buf(buf, '0', ibuf);
        ibuf = handl_buf(buf, 'x', ibuf);
        binary = malloc(sizeof(char) * (32 + 1));
        binary = fill_binary_array(binary, int_input, isnegative, 32);
        hexadecimal = malloc(sizeof(char) * (8 + 1));
        hexadecimal = fill_hex_array(binary, hexadecimal, 0, 8);
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
        return (count + 2);
}
/********************************NO. 2.****************************************/
/******************************************************************************/

/**
 * prinnoct - print the number in octal begining with zero
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 *
 * Return: number of chars printed
 */
int prinnoct(va_list arguments, char *buf, unsigned int ibuf)
{
        int int_input, i, isnegative, count, first_digit;
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
        ibuf = handl_buf(buf, '0', ibuf);
        binary = malloc(sizeof(char) * (32 + 1));
        binary = fill_binary_array(binary, int_input, isnegative, 32);
        octal = malloc(sizeof(char) * (11 + 1));
        octal = fill_oct_array(binary, octal);
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
        return (count + 1);
}
/********************************NO. 3.****************************************/
/******************************************************************************/

/**
 * prinnupx - prints number in uppercase hex
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 *
 * Return: number of chars printed
 */
int prinnupx(va_list arguments, char *buf, unsigned int ibuf)
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
        ibuf = handl_buf(buf, '0', ibuf);
        ibuf = handl_buf(buf, 'X', ibuf);
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
        return (count + 2);
}

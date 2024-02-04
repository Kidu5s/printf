#include "main.h"

/********************************NO. 1.****************************************/
/******************************************************************************/
/**
 * fill_binary_array - prints decimal in binary
 * @binary: pointer to binary
 * @int_in: input number
 * @isneg: if input number is negative
 * @limit: size of the binary
 * Return: number of chars printed.
 */
char *fill_binary_array(char *binary, long int int_in, int isneg, int limit)
{
        int i;

        for (i = 0; i < limit; i++)
                binary[i] = '0';
        binary[limit] = '\0';
        for (i = limit - 1; int_in > 1; i--)
        {
                if (int_in == 2)
                        binary[i] = '0';
                else
                        binary[i] = (int_in % 2) + '0';
                int_in /= 2;
        }
        if (int_in != 0)
                binary[i] = '1';
        if (isneg)
        {
                for (i = 0; binary[i]; i++)
                        if (binary[i] == '0')
                                binary[i] = '1';
                        else
                                binary[i] = '0';
        }
        return (binary);
}
/********************************NO. 2.****************************************/
/******************************************************************************/

/**
 * fill_hex_array - writes the character c to stdout
 *
 * @bnr: array where is stored the binary.
 * @hex: array where is stored the hexadecimal.
 * @isupp: integer that determines if the hexadecimal array is
 * in uppercase or lowercase letter.
 * @limit: size of hex
 * Return: binary array.
 */
char *fill_hex_array(char *bnr, char *hex, int isupp, int limit)
{
        int op, i, j, toletter;

        hex[limit] = '\0';
        if (isupp)
                toletter = 55;
        else
                toletter = 87;
        for (i = (limit * 4) - 1; i >= 0; i--)
        {
                for (op = 0, j = 1; j <= 8; j *= 2, i--)
                        op = ((bnr[i] - '0') * j) + op;
                i++;
                if (op < 10)
                        hex[i / 4] = op + 48;
                else
                        hex[i / 4] = op + toletter;
        }
        return (hex);
}
/********************************NO. 3.****************************************/
/******************************************************************************/

/**
 * fill_long_oct_array - calculates a long octal number
 *
 * @bnr: array where is stored the binary.
 * @oct: array where is stored the octal.
 *
 * Return: binary array.
 */
char *fill_long_oct_array(char *bnr, char *oct)
{
        int op, i, j, ioct, limit;

        oct[22] = '\0';
        for (i = 63, ioct = 21; i >= 0; i--, ioct--)
        {
                if (i > 0)
                        limit = 4;
                else
                        limit = 1;
                for (op = 0, j = 1; j <= limit; j *= 2, i--)
                        op = ((bnr[i] - '0') * j) + op;
                i++;
                oct[ioct] = op + '0';
        }
        return (oct);
}
/********************************NO. 4.****************************************/
/******************************************************************************/

/**
 * fill_oct_array - writes the character c to stdout
 * @bnr: array where is stored the binary.
 * @oct: array where is stored the octal.
 *
 * Return: binary array.
 */
char *fill_oct_array(char *bnr, char *oct)
{
        int op, i, j, ioct, limit;

        oct[11] = '\0';
        for (i = 31, ioct = 10; i >= 0; i--, ioct--)
        {
                if (i > 1)
                        limit = 4;
                else
                        limit = 2;
                for (op = 0, j = 1; j <= limit; j *= 2, i--)
                        op = ((bnr[i] - '0') * j) + op;
                i++;
                oct[ioct] = op + '0';
        }
        return (oct);
}


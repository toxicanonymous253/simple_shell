#include "shellme.h"

/**
* space_validation - validation of the space
* @iinput: input
* Return: 1 on spaces
*/
int space_validation(char *iinput)
{
int i = 0;
int j = 1;
int space_count = 0;

space_count = strlen(iinput);

while (iinput[i] == ' ' || iinput[i] == '\n' || iinput[i] == '\t')
i++;

if (i != space_count)
j = 0;

return (j);
}

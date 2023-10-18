#include "shellme.h"

/**
* _en - Printing the environment
* @av: array
* @input:input
* @exiti:exit
*
* Return:  1 true
*/
int _en(char **av, char *input, int *exiti)
{
int  i;

i = 0;

(void)av;
(void)input;
(void)exiti;

if (environ[i] == NULL)
{
printf("%s", "The current built environment has nothing");
return (1);
}

do {
printf("%s\n", environ[i]);
i++;
} while (environ[i]);

return (1);
}

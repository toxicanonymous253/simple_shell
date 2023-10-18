#include "shellme.h"

/**
* h_unsetenv - eliminate aa variable
* @av: array
* @input:input
* @exiti:exit
* Return:  1 tru 0 false
*/
int h_unsetenv(char **av, char *input, int *exiti)
{
int number_tokens;

number_tokens = 0;

(void)input;
(void)exiti;

while (av[number_tokens] != NULL)
{
number_tokens++;
}

if (number_tokens == 2)
unsetenv(av[1]);
else
fprintf(stderr, "Try 'setenviroment' key value\n");
return (1);

}
/**
* h_setenv - Sets and overwrite aa variable
* @av: array
* @input:input
* @exiti:exit
* Return:  1 tru 0 false
*/


int h_setenv(char **av, char *input, int *exiti)
{
int number_tokens;

number_tokens = 0;

(void)input;
(void)exiti;

while (av[number_tokens] != NULL)
{
number_tokens++;
}

if (number_tokens == 3)
setenv(av[1], av[2], 1);
else if (number_tokens < 3)
fprintf(stderr, "Try 'setenviroment' key value\n");
else

fprintf(stderr, "Try  'setenviroment' key value\n");

return (1);

}

#include "shellme.h"

/**
* signal_handler - handle CTRL + C
* @sigint: Signal
* Return: Void character
*/
void signal_handler(int sigint)
{
if (sigint == SIGINT)
write(2, "\n#shell_CL$ ", 11);
}

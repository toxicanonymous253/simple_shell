#include "shellme.h"
/**
* input_validation - Space validator
* @agu: agu
* @arg: arg
* Return: n_agu
*/
char *input_validation(char **agu, char **arg)
{
char *n_agu, *start, *s_agu = "/", **t_path, hold_en[1024];
int i = 0;
if (agu[0][0] == '/' || agu[0][0] == '.')
{
n_agu = agu[0];
if ((access(n_agu, F_OK) == -1))
{
fprintf(stderr, "%s: No such file or directory\n", arg[0]);
return ("Fail to acess");
}
}
else
{
strcpy(hold_en, getenv("PATH"));
t_path = _tonken(hold_en);
while (t_path[i])
{
start = append_str(s_agu, agu[0]);
n_agu = append_str(t_path[i], start);
if ((access(n_agu, F_OK) == -1))
{
free(n_agu);
free(start);
}
else
{
free(t_path);
free(start);
return (n_agu);
}
i++;
}
free(t_path);
fprintf(stderr, "%s: No such file or directory\n", arg[0]);
return ("Fail to acess");
}
return (n_agu);
}


#include "minishell.h"

static const char *redir_type_str(int type)
{
    if (type == REDIR_IN)
        return "<";
    if (type == REDIR_OUT)
        return ">";
    if (type == REDIR_APPEND)
        return ">>";
    if (type == HEREDOC)
        return "<<";
    return "UNKNOWN";
}

static void print_redirs(t_redir *r)
{
    while (r)
    {
        printf("    redir: %s %s\n", redir_type_str(r->type), r->filename);
        if (r->type == HEREDOC)
        {
            if (r->filename_quote)
                printf("  (no expand inside, quote='%c')", r->filename_quote);
            else
                printf("  (expand inside)");
        }
        r = r->next;
    }
}

void print_cmds(t_cmd *cmds)
{
    int cmd_i = 0;
    int arg_i;

    while (cmds)
    {
        printf("CMD %d\n", cmd_i);
        // argv
        if (!cmds->argv)
            printf("  argv: (null)\n");
        else
        {
            printf("  argv:\n");
            arg_i = 0;
            while (cmds->argv[arg_i])
            {
                printf("    [%d] %s\n", arg_i, cmds->argv[arg_i]);
                arg_i++;
            }
        }

        // redirections
        if (!cmds->redirs)
            printf("  redirs: (none)\n");
        else
            print_redirs(cmds->redirs);
        printf("\n");
        cmds = cmds->next;
        cmd_i++;
    }
}


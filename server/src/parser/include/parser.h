/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** parser
*/

#ifndef PARSER_H_
#define PARSER_H_

typedef struct cli_command_s {
    char *name;
    char **arguments;
    void *(*function)(void *);
} cli_command_t;

void *help_command(void *);
void *info_command(void *);
void *list_command(void *);
void *create_command(void *);
void *use_command(void *);
void *unsubscribe_command(void *);
void *subscribe_command(void *);
void *subscribed_command(void *);
void *messages_command(void *);
void *send_command(void *);
void *user_command(void *);
void *users_command(void *);
void *logout_command(void *);
void *login_command(void *);

#endif /* !PARSER_H_ */

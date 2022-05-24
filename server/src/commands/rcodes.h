/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** rcodes
*/

#ifndef RCODES_H_
    #define RCODES_H_

    #include <stdlib.h>

typedef struct retcodes_s {
    char *repr;
    int code;
    char **params;
} retcodes_t;

const retcodes_t retcode[] = {
    {.repr = "200 Success\n", .code = 200, .params = 0},
    {.repr = "201 Successfully connected to existing used: %s\n", .code = 201, .params = 0},
    {.repr = "202 Successfully connected, new user created with username: %s\n", .code = 202, .params = 0},
    {.repr = "203 Successfully disconnected as user: %s\n", .code = 203, .params = 0},
    {.repr = "310 No requested data found, empty relation\n", .code = 310, .params = 0},
    {.repr = "311 Reqested UUID: %s not found\n", .code = 311, .params = 0},
    {.repr = "312 Requested username: %s not found\n", .code = 312, .params = 0},
    {.repr = "320 Invalid action: Data already exist\n", .code = 320, .params = 0},
    {.repr = "321 Invalid action: Already subscribed to %s\n", .code = 321, .params = 0},
    {.repr = "322 Invalid action: Not subscribed to %s\n", .code = 322, .params = 0},
    {.repr = "401 Invalid requested action, please login\n", .code = 400, .params = 0},
    {.repr = "500 Syntax error\n", .code = 500, .params = 0},
    {.repr = "501 Format error: Invalid UUID\n", .code = 501, .params = 0},
    {.repr = "502 Format error: body too long\n", .code = 502, .params = 0},
    {.repr = "503 Format error: name too long\n", .code = 503, .params = 0},
    {.repr = "504 Format error: description too long\n", .code = 504, .params = 0},
    {.repr = "510 Syntax error: Wrong number of arguments\n", .code = 510, .params = 0},
    {.repr = "520 Syntax error: Invalid format\n", .code = 520, .params = 0},
    {.repr = "530 Syntax error: Command not found\n", .code = 530, .params = 0},
    {.repr = "540 Syntax error: Not implemented\n", .code = 540, .params = 0},
    {0, 0, 0}
};

static inline retcodes_t *get_copy_repcodes_by_code(int code) {
    retcodes_t *retcode = (retcodes_t *) malloc(sizeof(retcodes_t));

    if (!retcode)
        return NULL;
    for (int i = 0; retcode[i].repr; i++) {
        if (retcode[i].code == code)
            return retcode;
    }
    free(retcode);
    return NULL;
}

#endif /* !RCODES_H_ */

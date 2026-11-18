#ifndef MINISHELL_H
#define MINISHELL_H

typedef struct{
    char *command; // 명령어
    char **argv; // 인자 배열
    int argc; // 인자 개수
} CMD;

int parser(char *parsed_cmd[], char cmd[]);

#endif
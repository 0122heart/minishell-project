#include <stdio.h>
#include "minishell.h"

// 한 번에 입력할 수 있는 명령어의 최대 size를 1024byte로 설정
#define CMD_BUFFER_SIZE 1024

// token 하나를 최소 1byte라고 생각하면 최대 토큰이 512 나올 수 있음
#define PARSED_CMD_BUFFER_SIZE 512

int main(void){
    // cmd 선언.
    char cmd[CMD_BUFFER_SIZE + 1];
    char* parsed_cmd[PARSED_CMD_BUFFER_SIZE + 1];

    // 종료될 때 까지 루프
    while(1){
        // 명령어 입력 받기
        printf("minishell> ");
        fgets(cmd, CMD_BUFFER_SIZE, stdin);

        // 종료 조건
        if("exit" == cmd) return 0;

        // 명령어 파싱
        parser(parsed_cmd, cmd);

        // 명령어가 built-in인지 아닌지 구분


        // 실행시키기

    }
}
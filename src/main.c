#include <stdio.h>
#include <string.h>
#include "minishell.h"

// 한 번에 입력할 수 있는 명령어의 최대 size를 1024byte로 설정
#define CMD_BUFFER_SIZE 1024

// token 하나를 최소 1byte라고 생각하면 최대 토큰이 512 나올 수 있음
#define PARSED_CMD_BUFFER_SIZE 512

int main(void){
    // cmd 선언.
    char input[CMD_BUFFER_SIZE + 2] = {0}; // 개행문자와 널 문자 생각해서 +2, null 문자로 초기화
    CMD parsed_input[PARSED_CMD_BUFFER_SIZE] = {0};

    // 종료될 때 까지 루프
    while(1){
        // 명령어 입력 받기
        printf("minishell> ");
        fgets(input, sizeof(input), stdin);

        /*
        입력 크기 1024 이하일 시
        크기 + 1(개행문자) + 1(null문자)로 배열에 저장됨
        그럼 strlen 연산 실행 결과 크기 + 1 나오고, 이 때 idx = 크기로 설정해서 개행문자가 나오는지 확인하면 됨
        입력 크기가 1024 초과 시 1025 + 1(null문자)만 저장되므로, 이 때 idx = 1025로 설정해도 개행문자가 나오지 않음
        */ 
        size_t input_len = strlen(input);
        if(input_len <= 0 || input[input_len - 1] != '\n'){
            printf("최대 1024byte까지 입력 가능합니다.\n");
            char garbage;
            while((garbage = getchar()) != '\n'){};
            continue;
        }

        // 종료 조건
        if("exit" == input) return 0;

        // 명령어 파싱

        parser(input, parsed_input);

        // 명령어가 built-in인지 아닌지 구분


        // 실행시키기

    }
}
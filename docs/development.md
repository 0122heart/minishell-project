# data strucure
- command는 문자열로 입력받되 1024byte를 최대 길이로 한다
  - \0을 포함하여 1025를 배열의 크기로 한다
- command를 토큰화/파싱하여 (명령어 + 옵션 배열) 구조로 구조체에 저장된다.
  - command는 파싱된 구조체 인스턴스들의 배열로 변환된다.
- Operator
  - redirection : 파싱된 하나의 명령어 안에서의 연산자 
  - pipe : 파싱된 두 개의 명령어 사이의 연산자(inter process)
  - 

# algorithm

- while(1)을 통해 계속 실행되도록 하자
- cmd 문자열 입력은 char 배열로 받자 
  - 한 번에 입력할 수 있는 최대 길이를 1024byte로 설정(char * 1024)
    - 버퍼의 크기는 1024 + 1로 해야함
    - buffer overflow가 일어나지 않게 하려면 어떻게 입력을 받아야하지?
  - 공백을 포함해서 입력받으려면 scanf가 아닌 gets로 입력받아야겠다
- 명령의 실행은 fork()로 하되, waitpid를 통해 명령어 수행이 종료된 후에 다음 작업을 할 수 있도록 하자
- 종료는 ctrl + c or "exit"으로 하자
- 한 줄로 들어온 cmd는 parser.c의 parser 함수를 호출하여 파싱
  - 명령어를 최대 몇 개의 token으로 분리할 것인가
  - 하나의 token의 최대 size를 어떻게 할 것인가
  - 
- 파싱된 문자열을 내장함수와 외장함수로 구분
- 각각의 함수 호출
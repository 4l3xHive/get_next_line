# get_next_line 설계 및 오류 수정도
## 발생 가능한 이슈들
1. Memory issues
	1. malloc
	2. leak
	### 해결책 : 메모리 할당 및 해제는 하는 곳을 한정하고, 그 부분에서만 할당 및 해제한다.
2. '\n'이 들어왔을 경우와 안들어왔을 경우
	1. 들어왔을 경우
		- 남은 부분을 저장할 공간이 필요하고, 어디에 저장할지
	2. 안들어왔을 경우
		- 어디에 저장할건지 그전에 저장한 것은 있는지?
	* 두개의 차이점은 read()함수를 얼마나 사용했는가 이다.
### read() function
4. Utils & core part function design

## 합수를 여러번 지우고 다시 썻을 때 고려해야하는 사항들
1. tmp & nextline 두개의 변수만 이용해서 저장 및 출력
2. 자주 사용하지 않는 함수들 정리하기(ft_strdup, ft_strsub) <- leak segement fault 발생
3. 문제 사항 발생 지점 -> 1개일 때 와 여러 개 일때 경우의 수 생각하기.

### 23.11.09(목)
1. read_error 사항 빼고 오류 전체 수정 - 기본 paco 기준
2. paco -s 의 경우, strdup에서 Memory leaks 발생
3. 대부분 문제점 Edge Point에서 발생 (주로 1byte)
4. 귀가 후, 기본 paco 오류 해결하기.

### 23.11.13(월)
1. paco 모든 테스트 통과 - Mandantory
2. paco -s Null check -> Multiline nl 부분 확인하기 (윈도우 환경에서 오류 확인 불가)
3. 예외처리 (Null- check) 모두 해줬는데 오류가 발생하는 원인이 무엇일까..

# CodingProblems_CPP
This project is for warming up before brain storming

## Environment
- Docker (There is dockerfile)
- GCC (G++, 9.3.0)

## 기억해둘만한 문제번호
- 1152
- 1002 : float 형에서의 == 비교는 반드시 부등호로 비교해야함. ex) if(abs(a - b) < __DBL_EPSILON__)
- 11729 : std::string의 operator**+** 는 느림. 그러므로, 미리 std::string something; something.reserve(10000000) 해두고 append해서 쓰는게 매우 빠름. ~~그냥 출력하는게 더 빠른거같다.~~
- 11053
  * size_t 를 사용할 때, ```for(size_t i = 5; i >= 0; i--)``` 같은 코드는 사용하지 말 것. ```i = 0``` 이후로 -- 되어 **Underflow**가 발생하기 때문.

## Compile and Run
- Press ```Ctrl + Shift + B``` in Visual Studio Code
- This will compile current .cpp code to binary, run it, and delete it automatically.
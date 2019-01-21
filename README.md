# practice
작성한 코드 기록

## MyDoubleVector
* STL vector<double>과 비슷한 class 만들기
* 새로운 연산자로 double포인터 변수화 동적 메모리 할당 사용.
* 구현 목록
  * Default constructor
    * MyDoubleVector();
  * Copy constructor for deep copy
    * MyDoubleVector(const MyDoubleVector& v);
  * Destructor
    * ~MyDoubleVector();
  * Operator
    * = : deep copy로 Chaining assignment가 가능하도록 합니다.
    * += : 왼쪽 object에 오른쪽 object를 추가합니다.
    * [] :  vector안에 요청된 위치에 있는 요소에 대한 참조를 반환합니다.
            요청 된 위치가 범위를 벗어나면 메세지를 출력하고 프로그램을 종료해야 합니다.
    * (binary)+ : 두 object의 vector 합인 object를 반환합니다.
    * (binary)- : 두 object의 vecotr 차친 object를 반환합니다.
    * (binary)* : 두 object의 스칼라 곱( 또는 내적)인 object를 반환합니다.
    * (binary)== : 두 vector가 같은지 아닌지를 반환합니다.
                  ( size가 같은지 확인합니다. capacities는 확인하지 않습니다.)
    * (Unary)- : 피연산자 object에서 각 요소의 단일 부정인 object를 반환합니다.
    * (Unary)() : object의 모든 요소를 실수(double typed)으로 설정합니다.
  * void
    * pop_back() : vector의 마지막 요소와 그에 대한 참조를 제거하고, size를 줄입니다.
    * push_back(double x) : vector의 마지막에 새로운 요소를 추가합니다.
                            새로운 요소 x는 복사복으로 초기화됩니다.
    * reserve(size_t n) : vector가 n개 요소를 수용할 수 있도록 capacity를 할당을 요청합니다.
    * clear() : vector의 모든 요소를 버립니다.
                destructor 호출 후, vector에서 제거되고 size는 0으로 유지합니다.
  * size_t
    * capacity() const : vector 요소에 할당된 저장 공간의 크기를 반환합니다.
    * size() const : vector안의 요소 개수를 반환합니다.
  * bool
    * empty() const : vector가 비어있는지, size가 0인지 반환합니다.

#include<iostream>
#include<string>

using namespace std;

const int maxStackSize = 1000;
typedef int ItemType;

class StackType
{
public:
	StackType()  // 생성자
	{
		top = -1;
	}

	bool IsFull() const  // 스텍이 꽉 차있는지
	{
		return (top == maxStackSize - 1);
	}

	bool IsEmpty() const  // 스텍이 비었는지
	{
		return (top == -1);
	}

	void Push(ItemType newItem)  // 스텍에 원소를 추가
	{
		if( IsFull() )
			cout << "Error: the stack is full." << endl;
		else
		{
			top++;
			items[top] = newItem;
		}
	}

	void Pop()  // 스텍에 있는 원소를 제거
	{
		if( IsEmpty() )
			cout << "Error: the stack is full." << endl;
		else
			top--;
	}

	ItemType Top()  // 맨 마지막 원소 반환
	{
		if( IsEmpty() )
			cout << "Error: the stack is full." << endl;
		else
			return items[top];
	}


private:
	int top;
	ItemType items[maxStackSize];
};

//--------------------------------------------------------------------------------------------

int main(){

	StackType S1, S2;  // S1, S2: 연산하기 위한 두 스텍(Stack)
	StackType S3;  // S3: 연산 결과를 담는 스텍(Stack)
	string num1, num2;  // num1, num2: 덧셈할 두 수를 입력받기 위한 변수
	int n;  // n: 숫자 한 자리를 저장함 (다용도로 사용됨)

	cout << "Input two numbers: ";
	cin >> num1 >> num2;  // 덧셈할 두 숫자를 입력받음

	for(int i=0; i<=num1.length()-1; i++){  // 아스키 코드를 이용해 숫자 한자리씩 스텍에 저장함(num1)
		n = num1.at(i) - 48;
		S1.Push(n);
	}

	for(int i=0; i<=num2.length()-1; i++){  // 아스키 코드를 이용해 숫자 한자리씩 스텍에 저장함(num2)
		n = num2.at(i) - 48;
		S2.Push(n);
	}

	int result = 0;  // result: 자리 올림을 저장하는 변수

	while( ! S1.IsEmpty() || ! S2.IsEmpty() )  // 두 스텍 중 적어도 하나가 원소가 남아있으면
	{
		if( S1.IsEmpty() )  // 첫 번째 스텍이 비어있을 경우
		{
			result += S2.Top();  // 스택의 가장 위에 있는 수를 자리 올림이랑 더함
			S2.Pop();  // 스텍의 원소를 하나씩 제거함
		}
		else if( S2.IsEmpty() )  // 두 번째 스텍이 비어있을 경우
		{
			result += S1.Top();
			S1.Pop();
		}
		else  // 두 스텍 모두 원소가 남아있을 경우
		{
			result += S1.Top() + S2.Top();  // 두 스택의 가장 위에 있는 수를 자리 올림이랑 더함
			S1.Pop();
			S2.Pop();  // 두 스텍의 원소를 하나씩 제거함
		}

		n = result % 10;  // 덧셈한 결과에서 자릿수를 저장함
		S3.Push(n);  // 자릿수를 스텍에 넣어줌

		result /= 10;  // 값이 10 이상일 경우 십의 자리만 남김
	}

	if(result != 0) S3.Push(result);  // 자리 올림이 남아 있을 경우 스텍에 넣어줌

	cout << "Output: " << num1 << " + " << num2 << " = ";  // 선 출력문

	while( ! S3.IsEmpty() )  // 덧셈 결과를 출력함
	{
		n = S3.Top();
		cout << n;  // 스텍으로부터 한자리씩 저장한 후 출력
		S3.Pop();  // 원소를 하나씩 제거함
	}

	cout << endl;

	return 0;
}
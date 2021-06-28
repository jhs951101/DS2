#include<iostream>
#include<string>

using namespace std;

const int maxStackSize = 1000;
typedef int ItemType;

class StackType
{
public:
	StackType()  // ������
	{
		top = -1;
	}

	bool IsFull() const  // ������ �� ���ִ���
	{
		return (top == maxStackSize - 1);
	}

	bool IsEmpty() const  // ������ �������
	{
		return (top == -1);
	}

	void Push(ItemType newItem)  // ���ؿ� ���Ҹ� �߰�
	{
		if( IsFull() )
			cout << "Error: the stack is full." << endl;
		else
		{
			top++;
			items[top] = newItem;
		}
	}

	void Pop()  // ���ؿ� �ִ� ���Ҹ� ����
	{
		if( IsEmpty() )
			cout << "Error: the stack is full." << endl;
		else
			top--;
	}

	ItemType Top()  // �� ������ ���� ��ȯ
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

	StackType S1, S2;  // S1, S2: �����ϱ� ���� �� ����(Stack)
	StackType S3;  // S3: ���� ����� ��� ����(Stack)
	string num1, num2;  // num1, num2: ������ �� ���� �Է¹ޱ� ���� ����
	int n;  // n: ���� �� �ڸ��� ������ (�ٿ뵵�� ����)

	cout << "Input two numbers: ";
	cin >> num1 >> num2;  // ������ �� ���ڸ� �Է¹���

	for(int i=0; i<=num1.length()-1; i++){  // �ƽ�Ű �ڵ带 �̿��� ���� ���ڸ��� ���ؿ� ������(num1)
		n = num1.at(i) - 48;
		S1.Push(n);
	}

	for(int i=0; i<=num2.length()-1; i++){  // �ƽ�Ű �ڵ带 �̿��� ���� ���ڸ��� ���ؿ� ������(num2)
		n = num2.at(i) - 48;
		S2.Push(n);
	}

	int result = 0;  // result: �ڸ� �ø��� �����ϴ� ����

	while( ! S1.IsEmpty() || ! S2.IsEmpty() )  // �� ���� �� ��� �ϳ��� ���Ұ� ����������
	{
		if( S1.IsEmpty() )  // ù ��° ������ ������� ���
		{
			result += S2.Top();  // ������ ���� ���� �ִ� ���� �ڸ� �ø��̶� ����
			S2.Pop();  // ������ ���Ҹ� �ϳ��� ������
		}
		else if( S2.IsEmpty() )  // �� ��° ������ ������� ���
		{
			result += S1.Top();
			S1.Pop();
		}
		else  // �� ���� ��� ���Ұ� �������� ���
		{
			result += S1.Top() + S2.Top();  // �� ������ ���� ���� �ִ� ���� �ڸ� �ø��̶� ����
			S1.Pop();
			S2.Pop();  // �� ������ ���Ҹ� �ϳ��� ������
		}

		n = result % 10;  // ������ ������� �ڸ����� ������
		S3.Push(n);  // �ڸ����� ���ؿ� �־���

		result /= 10;  // ���� 10 �̻��� ��� ���� �ڸ��� ����
	}

	if(result != 0) S3.Push(result);  // �ڸ� �ø��� ���� ���� ��� ���ؿ� �־���

	cout << "Output: " << num1 << " + " << num2 << " = ";  // �� ��¹�

	while( ! S3.IsEmpty() )  // ���� ����� �����
	{
		n = S3.Top();
		cout << n;  // �������κ��� ���ڸ��� ������ �� ���
		S3.Pop();  // ���Ҹ� �ϳ��� ������
	}

	cout << endl;

	return 0;
}
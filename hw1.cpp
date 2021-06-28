#include<iostream>

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

	StackType S;  // S: r������ ��ȯ�� ���� �����ϴ� ����
	int n;  // n: �Է¹��� 10������ ����
	int r;  // r: 10������ �� ������ ��ȯ�� ������ ����
	
	cout << "Input n and r: ";
	cin >> n >> r;  // n�� r�� �Է¹���

	int out_n = n;  // out_n: �Է¹��� 10������ �ٽ� ��¸� �ϱ� ���� ����

	if( !(n > 0 && r > 0) )  // n,r �� �ϳ��� ����� �ƴ� ��� Error
	{
		cout << "Error: not valid number." << endl;
		return 1;
	}

	if( !( (r <= 9) || (r>=11 && r<=16) ) )  // �߸��� ���� r�� ���� ��� Error
	{
		cout << "Error: not valid number." << endl;
		return 1;
	}

	while(n != 0)  // 10������ r������ ��ȯ�ϴ� ����
	{
		int rem;  // rem: n�� r�� ���� �������� ����
		rem = n % r;
		S.Push(rem);  // �������� ���ؿ� �ϳ��� �־���
		n = n/r;
	}

	cout << "Output - " << out_n << "�� " << r << "���� ǥ��: ";  // �� ��¹�

	while( ! S.IsEmpty() )  // r������ ��ȯ�� ���� �ϳ��� ����ϴ� ����
	{
		int x;  // x: ���ؿ� ����� �� ���Ҹ� ����
		x = S.Top();  // �� ������ ���Ҹ� ��ȯ�� ������

		if(x > 9){  // ���Ұ� 10�̻��� ��� �빮�� ���ĺ����� ��ȯ
			char c = x + 55;  // c: �빮�� ���ĺ��� ���� �� ���
			cout << c;
		}
		else{
			cout << x;
		}

		S.Pop();  // ���Ҹ� �ϳ��� ������
	}

	cout << endl;

	return 0;
}
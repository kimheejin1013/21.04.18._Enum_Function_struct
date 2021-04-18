#include <iostream>
#include <time.h>


struct NumberData {
	int number;
	bool isCheck;
};

enum CHARACTER_MOTION // 열거형, 가독성
{
	IDLE = 0,
	MOVE,
	JUMP,
	ATTACK,
	HIT,
	DEATH

	// 2배수 씩 찍는 법

	//IDLE = 2,
	//MOVE = IDLE + 2,
	//JUMP = MOVE + 2
};

int GetRandomNumber(NumberData[], int);
void PrintBingo(NumberData values[]);

int main()
{
	
	////	삼항 연산자
	//bool isResult;
	//If (100 > 0) isResult = true;
	//else isResult = false;

	////	왼쪽이 조건부 true
	//bool isResult = (100 > 0) ? true : false;

	//CHARACTER_MOTION type = IDLE;
	//
	//int code = 0;
	//std::cin >> code;
	//
	//type = (CHARACTER_MOTION)code; // 명시적 형변환 (개발자가 직접)

	//float data = code; //묵시적 형변환 (컴파일러가 추정해 변경)

	//switch (type)
	//{
	//case IDLE:
	//	break;
	//case MOVE:
	//	break;
	//case JUMP:
	//	break;
	//case ATTACK:
	//	break;

	//default:
	//	break;
	//}

	srand(time(NULL));

	NumberData values[25] = { 0, };

	for (int i = 0; i < 25; ++i)
	{
		
		values[i].number = GetRandomNumber(values, i);
		printf("%d\t", values[i].number);
		
		if (i % 5 == 4 ) std::cout << std::endl;
	}
	
	int number = 0;
	while (number != -1)
	{
		system("cls");
		PrintBingo(values);

		std::cin >> number;

		for (int i = 0; i < 25; ++i)
		{
			if (values[i].number == number)
				values[i].isCheck = true;

			
		}
	}
	
	return 0;

}


int GetRandomNumber(NumberData containValues[], int index)
{
	int value = rand() % 25 + 1;
	for (int i = 0; i < index; ++i)
	{
		if (value == containValues[i].number)
		{
			value = rand() % 25 + 1;
			i = -1;
		}

	}
	
	return value;

}

void PrintBingo(NumberData values[])
{
	for (int i = 1; i < 26; ++i)
	{
		std::cout << values[i - 1].number << "\t";

		if (i % 5 == 0) std::cout << std::endl;
	}

	/*for (int x = 0; x < 5; ++x)
	{
		for (int y = 0; y < 5; ++y)
		{
			std::cout << values[y * 5 + x].number << "\t";
		}
		std::cout << std::endl;
	}*/

}
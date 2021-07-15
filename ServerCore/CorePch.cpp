#include "pch.h"
#include "CorePch.h"

void HelloWorld()
{
	int O_Map[4][4] = {}; //원래 게임판
	int G_Map[4][4] = {}; //게임이 진행될 게임판
	int G_Num[8];

	void NumArray(int i, int j);
	void Num_Num();
	void Suffle_Num(int i, int j);
	int Empty(int x, int y);
	int Pos_X(int x);
	int Pos_Y(int y);
	void Show_Map(int i, int j);
	void Show_Num(int i, int j);
	int Found_All(int i, int j);

	int i, j = 0;
	int x, y = 0;
	//=====================================================
	int main()
	{
		//짝 맞추기 게임
		//4X4 사이즈(8쌍)
		//1~16 사이의 숫자를 입력하면 입력한 숫자에 해당하는 카드 오픈
		//짝을 찾으면 오픈된 상태로 유지
		//아닌 경우 다시 뒤집음
		//시도한 횟수 표시

		srand(size_t(time(NULL)));


		NumArray(i, j);
		Num_Num();

		Suffle_Num(i, j);

		int G_Count = 0;

		while (1)
		{
			system("cls");

			cout << "총 시도 횟수: " << G_Count << endl;
			int Select1 = 0;
			int Select2 = 0;

			Show_Map(i, j);
			Show_Num(i, j);
			cout << "1번째로 뒤집을 카드를 선택하세요(0~15): ";
			cin >> Select1;
			cout << endl;

			cout << "2번째로 뒤집을 카드를 선택하세요(0~15): ";
			cin >> Select2;
			cout << endl;

			if (Select1 == Select2)
			{
				continue;
			}
			else if (Select1 < 0 || Select1>15 || Select2 < 0 || Select1>15)
			{
				cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
				Sleep(1000);
				continue;
			}

			int F_Select_X = Pos_X(Select1);
			int F_Select_Y = Pos_Y(Select1);

			int S_Select_X = Pos_X(Select2);
			int S_Select_Y = Pos_Y(Select2);


			if (G_Map[F_Select_X][F_Select_Y] == 0 && G_Map[S_Select_X][S_Select_Y] == 0
				&& (O_Map[F_Select_X][F_Select_Y] == O_Map[S_Select_X][S_Select_Y]))
			{
				cout << "짝을 찾았습니다." << endl;
				cout << endl;
				G_Map[F_Select_X][F_Select_Y] = 1;
				G_Map[S_Select_X][S_Select_Y] = 1;
				G_Count++;
			}

			else
			{
				cout << "짝이 아닙니다." << endl;
				cout << "첫번째 선택: " << G_Num[O_Map[F_Select_X][F_Select_Y]];
				cout << endl;
				cout << "두번째 선택: " << G_Num[O_Map[S_Select_X][S_Select_Y]];
				cout << endl;
				G_Count++;
			}

			if (Found_All(i, j) == 1)
			{
				cout << "======YOU WIN ! !======" << endl;
				break;
			}
			system("pause");
		}
		return 0;
	}

	void NumArray(int i, int j)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				O_Map[i][j] = 1;
			}
		}
	}

	void Num_Num()
	{
		G_Num[0] = 1;
		G_Num[1] = 2;
		G_Num[2] = 3;
		G_Num[3] = 4;
		G_Num[4] = 5;
		G_Num[5] = 6;
		G_Num[6] = 7;
		G_Num[7] = 8;
	}

	void Suffle_Num(int i, int j)
	{

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int pos = Empty(x, y);
				int x = Pos_X(pos);
				int y = Pos_Y(pos);

				O_Map[x][y] = i;
			}
		}

	}

	int Empty(int x, int y)
	{
		while (1)
		{
			int RandPos = rand() % 16;
			int x = Pos_X(RandPos);
			int y = Pos_Y(RandPos);

			if (O_Map[x][y] == 1)
			{
				return RandPos;
			}
		}
		return 0;
	}

	int Pos_X(int x)
	{
		return x / 4;
	}

	int Pos_Y(int y)
	{
		return y % 4;
	}

	void Show_Map(int i, int j)
	{
		cout << "=============테스트용================" << endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << G_Num[O_Map[i][j]] << "\t";
			}
			cout << endl;
			cout << endl;
		}
		cout << "====================================" << endl;
		cout << endl;
	}

	void Show_Num(int i, int j)
	{

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (G_Map[i][j] != 0)
				{
					cout << "  " << G_Num[O_Map[i][j]] << " ";
				}
				else
				{
					cout << "  [?] ";
				}
			}
			cout << endl;
			cout << endl;
		}
	}

	int Found_All(int i, int y)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (G_Map[i][j] == 0)
				{
					return 0;
				}
			}

		}
		return 1;
	}
}
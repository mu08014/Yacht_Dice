#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

int InfoNum;

//�޴�â
void MenuInfo() {
	cout << "---------------------------------------\n";
	cout << setfill(' ') << '|'<< left << setw(38) <<" 1. Game Information" << "|\n";
	cout << setfill(' ') << '|' << left << setw(38) << " 2. The Method of Score Calculation" << "|\n";
	cout << setfill(' ') << '|' << left << setw(38) << " 3. Start Game" << "|\n";
	cout << setfill(' ') << '|' << left << setw(38) << " 4. Quit Game" << "|\n";
	cout << "---------------------------------------\n";
	cout << "���ϴ� ���� ��ȣ�� �Է��ϼ��� --> ";
	cin >> InfoNum;
	cout << "\n";
}

//1. Game Information
void Menu1() {
	cout << "��Ʈ ���̽��� �ֻ����� ����� ��Ŀó�� ������ ���ߴ� �����Դϴ�. 5���� �ֻ����� �ִ� 3������ ���� ��\n";
	cout << "���ϴ� �ֻ����� ������ ������ ����ϴ�. ���� ������ �����ǿ� ����Ͽ� ������ ����ϴ�. �� ���� ������ ��� Player�� �¸��մϴ�. \n";
	cout << "�������� ���α׷��� �Ƿ� �Ѱ�� �ֻ����� �����ϴ� ����� �������� ���� 5���� �ֻ����� �ִ� 5�� ������ ������� �����մϴ�.\n";
	cout << "���� ������ ������ ��� �����ôٸ� 2���� �����ּ���. \n\n";
}

//2. The Method of Score Calculation
void Menu2() {
	cout << "-----------------------------------------------------------------------------------------\n";
	cout << "Aces : 1�� ���� �ֻ��� ���� ����. �ִ� 5�� (1)\n";
	cout << "Deuces : 2�� ���� �ֻ��� ���� ����. �ִ� 10�� (2)\n";
	cout << "Threes : 3�� ���� �ֻ��� ���� ����. �ִ� 15�� (3)\n";
	cout << "Fours : 4�� ���� �ֻ��� ���� ����. �ִ� 20�� (4)\n";
	cout << "Fives : 5�� ���� �ֻ��� ���� ����. �ִ� 25�� (5)\n";
	cout << "Sixes : 6�� ���� �ֻ��� ���� ����. �ִ� 30�� (6)\n";
	cout << "�� 6�� �׸��� ������ 63�� �̻��� ��, 35���� ���ʽ��� ����ϴ�!\n";
	cout << "-----------------------------------------------------------------------------------------\n";
	cout << "Choice : �ֻ����� �� 5���� ����. �ִ� 30�� (7)\n";
	cout << "-----------------------------------------------------------------------------------------\n";
	cout << "4 of a Kind : ������ �ֻ����� ���� 4�� �̻��� ��, �ֻ��� �� 5���� ����. �ִ� 30�� (8)\n";
	cout << "Full House : ������ �ֻ����� ���� ���� 3��, 2���� ��, �ֻ��� �� 5���� ����. �ִ� 30�� (9)\n";
	cout << "Little Straight : �ֻ��� ���� ���� 1, 2, 3, 4, 5�� ��, ���� 30�� (10)\n";
	cout << "Big Straight : �ֻ��� ���� ���� 2, 3, 4, 5, 6�� ��, ���� 30�� (11)\n";
	cout << "Yacht : ������ ������ ���� 5���� ��, ���� 50�� (12)\n";
	cout << "-----------------------------------------------------------------------------------------\n\n";
}

//�ֻ��� �߻�
void RunDice(int& dice1, int& dice2, int& dice3, int& dice4, int& dice5) {
	srand(time(NULL));
	dice1 = (rand() % 6) + 1;
	dice2 = (rand() % 6) + 1;
	dice3 = (rand() % 6) + 1;
	dice4 = (rand() % 6) + 1;
	dice5 = (rand() % 6) + 1;
}

//Aces
void Aces(int dice1, int dice2, int dice3, int dice4, int dice5, int& point, int& bonus) {
	int a;
	int dice[] = { dice1,dice2,dice3,dice4,dice5 };
	a = count(dice, dice + 5, 1);
	bonus = bonus + a;
	point = point + a;
}

//Deuces
void Deuces(int dice1, int dice2, int dice3, int dice4, int dice5, int& point, int& bonus) {
	int a;
	int dice[] = { dice1,dice2,dice3,dice4,dice5 };
	a = count(dice, dice + 5, 2);
	bonus = bonus + (a * 2);
	point = point + (a * 2);
}

//Threes
void Threes(int dice1, int dice2, int dice3, int dice4, int dice5, int& point, int& bonus) {
	int a;
	int dice[] = { dice1,dice2,dice3,dice4,dice5 };
	a = count(dice, dice + 5, 3);
	bonus = bonus + (a * 3);
	point = point + (a * 3);
}

//Fours
void Fours(int dice1, int dice2, int dice3, int dice4, int dice5, int& point, int& bonus) {
	int a;
	int dice[] = { dice1,dice2,dice3,dice4,dice5 };
	a = count(dice, dice + 5, 4);
	bonus = bonus + (a * 4);
	point = point + (a * 4);
}

//Fives
void Fives(int dice1, int dice2, int dice3, int dice4, int dice5, int& point, int& bonus) {
	int a;
	int dice[] = { dice1,dice2,dice3,dice4,dice5 };
	a = count(dice, dice + 5, 5);
	bonus = bonus + (a * 5);
	point = point + (a * 5);
}

//Sixes
void Sixes(int dice1, int dice2, int dice3, int dice4, int dice5, int& point, int& bonus) {
	int a;
	int dice[] = { dice1,dice2,dice3,dice4,dice5 };
	a = count(dice, dice + 5, 6);
	bonus = bonus + (a * 6);
	point = point + (a * 6);
}

//Choice
void Choice(int dice1, int dice2, int dice3, int dice4, int dice5, int& point) {
	int a;
	a = dice1 + dice2 + dice3 + dice4 + dice5;
	point = point + a;
}

//4 of a Kind
void Kin(int dice1, int dice2, int dice3, int dice4, int dice5, int& point) {
	int a = 0,b;
	int dice[] = { dice1,dice2,dice3,dice4,dice5 };
	for (int i = 1; i <= 6; i++) {
		if (count(dice, dice + 5, i) >= 4) {
			a = a + 1;
		}
	}
	if (a != 0) {
		b = dice1 + dice2 + dice3 + dice4 + dice5;
	}
	else {
		b = 0;
	}
	point = point + b;
}

//Full House
void Full(int dice1, int dice2, int dice3, int dice4, int dice5, int& point) {
	int dice[] = { dice1,dice2,dice3,dice4,dice5 };
	int a = 0, b = 0, c;
	for (int i = 1; i <= 6; i++) {
		if (count(dice, dice + 5, i) == 3) {
			a = a + 1;
		}
	}
	for (int i = 1; i <= 6; i++) {
		if (count(dice, dice + 5, i) == 2) {
			b = b + 1;
		}
	}
	if (a != 0 && b != 0) {
		c = dice1 + dice2 + dice3 + dice4 + dice5;
	}
	else {
		c = 0;
	}
	point = point + c;
}

//Little Straight
void LS(int dice1, int dice2, int dice3, int dice4, int dice5, int& point) {
	int a;
	int dice[] = {dice1,dice2,dice3,dice4,dice5 };
	if (count(dice, dice + 5, 1) == 1 && count(dice, dice + 5, 2) == 1 && count(dice, dice + 5, 3) == 1 && count(dice, dice + 5, 4) == 1 && count(dice, dice + 5, 5) == 1) {
		point = point + 30;
	}
}

//Big Straight
void BS(int dice1, int dice2, int dice3, int dice4, int dice5, int& point) {
	int a;
	int dice[] = { dice1,dice2,dice3,dice4,dice5 };
	if (count(dice, dice + 5, 2) == 1 && count(dice, dice + 5, 3) == 1 && count(dice, dice + 5, 4) == 1 && count(dice, dice + 5, 5) == 1 && count(dice, dice + 5, 6) == 1) {
		point = point + 30;
	}
}

//Yacht
void Yacht(int dice1, int dice2, int dice3, int dice4, int dice5, int& point) {
	int a;
	int dice[] = { dice1,dice2,dice3,dice4,dice5 };
	for (int i = 1; i <= 6; i++) {
		if (count(dice, dice + 5, i) == 5) {
			point = point + 50;
		}
	}
}

//���� �����ϱ�
void Score(int dice1, int dice2, int dice3, int dice4, int dice5, int& point, int& A, int& B, int& C, int& D, int& E, int& F, int& G, int& H, int& I, int& J, int& K, int& L, string player, int& bonus)  {
	int score;
	while (1) {
		cout << "< ���� ǥ > ��� ���� ���� 0, ��� �Ұ��� ���� 1\n";
		cout << "Aces : " << A << "\n";
		cout << "Deuces : " << B << "\n";
		cout << "Threes : " << C << "\n";
		cout << "Fours : " << D << "\n";
		cout << "Fives : " << E << "\n";
		cout << "sixes : " << F << "\n";
		cout << "choice : " << G << "\n";
		cout << "4 of a Kind : " << H << "\n";
		cout << "Full House : " << I << "\n";
		cout << "Little Straight : " << J << "\n";
		cout << "Big Straight : " << K << "\n";
		cout << "Yacht : " << L << "\n\n";
		cout << "������ ���� ������ �����ϼ���. (������ ���� ������ �������� 0�� �Է��ϼ���. ��ȣ ���� ���� �Է�) -> ";
		cin >> score;
		if (score == 0) {
			Menu2();
		}
		else {
			if (score == 1) {
				if (A == 1) {
					cout << "\n�̹� ����� ����\n\n";
				}
				else {
					Aces(dice1, dice2, dice3, dice4, dice5, point, bonus);
					A = 1;
					break;
				}
			}
			else if (score == 2) {
				if (B == 1) {
					cout << "\n�̹� ����� ����\n\n";
				}
				else {
					Deuces(dice1, dice2, dice3, dice4, dice5, point, bonus);
					B = 1;
					break;
				}
			}
			else if (score == 3) {
				if (C == 1) {
					cout << "\n�̹� ����� ����\n\n";
				}
				else {
					Threes(dice1, dice2, dice3, dice4, dice5, point, bonus);
					C = 1;
					break;
				}
			}
			else if (score == 4) {
				if (D == 1) {
					cout << "\n�̹� ����� ����\n\n";
				}
				else {
					Fours(dice1, dice2, dice3, dice4, dice5, point, bonus);
					D = 1;
					break;
				}
			}
			else if (score == 5) {
				if (E == 1) {
					cout << "\n�̹� ����� ����\n\n";
				}
				else {
					Fives(dice1, dice2, dice3, dice4, dice5, point, bonus);
					E = 1;
					break;
				}
			}
			else if (score == 6) {
				if (F == 1) {
					cout << "\n�̹� ����� ����\n\n";
				}
				else {
					Sixes(dice1, dice2, dice3, dice4, dice5, point, bonus);
					F = 1;
					break;
				}
			}
			else if (score == 7) {
				if (G == 1) {
					cout << "\n�̹� ����� ����\n\n";
				}
				else {
					Choice(dice1, dice2, dice3, dice4, dice5, point);
					G = 1;
					break;
				}
			}
			else if (score == 8) {
				if (H == 1) {
					cout << "\n�̹� ����� ����\n\n";
				}
				else {
					Kin(dice1, dice2, dice3, dice4, dice5, point);
					H = 1;
					break;
				}
			}
			else if (score == 9) {
				if (I == 1) {
					cout << "\n�̹� ����� ����\n\n";
				}
				else {
					Full(dice1, dice2, dice3, dice4, dice5, point);
					I = 1;
					break;
				}
			}
			else if (score == 10) {
				if (J == 1) {
					cout << "\n�̹� ����� ����\n\n";
				}
				else {
					LS(dice1, dice2, dice3, dice4, dice5, point);
					J = 1;
					break;
				}
			}
			else if (score == 11) {
				if (K == 1) {
					cout << "\n�̹� ����� ����\n\n";
				}
				else {
					BS(dice1, dice2, dice3, dice4, dice5, point);
					K = 1;
					break;
				}
			}
			else if (score == 12) {
				if (L == 1) {
					cout << "\n�̹� ����� ����\n\n";
				}
				else {
					L = 1;
					break;
				}
			}
			else {
				cout << "\n��ȿ�� ���� �Է����ּ���.\n\n";
			}
		}
	}
	cout <<player<< "���� ���� ������ " << point << "�Դϴ�.\n\n";
}

//�ֻ��� ���� ��� ǥ��
void Repeat(string player) {
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	int E = 0;
	int F = 0;
	int G = 0;
	int H = 0;
	int I = 0;
	int J = 0;
	int K = 0;
	int L = 0;
	int point = 0;
	int bonus = 0;
	int turn = 1;
	int Dice1, Dice2, Dice3, Dice4, Dice5;
	int play;
	while (1) {
		if (turn >= 13) {
			break;
		}
		else {
			int n = 1;
			while (1) {
				char decision;
				cout << player << "�� �غ� �Ǽ����� 1�� �Է��� �ּ���!-> ";
				cin >> play;
				if (play == 1) {
					cout << player << "���� �ֻ����� �����ϴ�. (" << turn << "��° ��, " << n << "��° �ֻ���)\n";
					RunDice(Dice1, Dice2, Dice3, Dice4, Dice5);
					cout << "��� : " << Dice1 << " " << Dice2 << " " << Dice3 << " " << Dice4 << " " << Dice5 << "\n\n";
					if (n >= 5) {
						break;
					}
					else {
						cout << "�����Ͻðڽ��ϱ�? (Y or N) -> ";
						cin >> decision;
						cout << "\n";
						if (decision == 'Y') {
							break;
						}
						else {
							n = n + 1;
						}
					}
				}
				else {
					cout << "1�� �Է����ּ���!\n";
				}
			}
			Score(Dice1, Dice2, Dice3, Dice4, Dice5, point, A, B, C, D, E, F, G, H, I, J, K, L, player, bonus);
			turn = turn + 1;
		}
	}
	if (bonus >= 63) {
		point = point + 35;
		cout << "Aces ~ Sixes�� �� ���� 63���� �Ѿ����Ƿ� ���ʽ� 35��!\n";
	}
	cout << "��������! " <<player<< "���� ���� ������ " << point << "�� �Դϴ�.\n";
}

//3. Start Game
void Menu3() {
	string player;
	cout << "���� ����!\n";
	cout << "�÷��̾��� �̸��� �������ּ��� --> ";
	cin >> player;
	Repeat(player);	
}

//�޴�
void Menu() {
	while (1) {
		MenuInfo();
		if (InfoNum == 1) {
			Menu1();
		}
		else if (InfoNum == 2) {
			Menu2();
		}
		else if (InfoNum == 3) {
			Menu3();
			break;
		}
		else if (InfoNum == 4) {
			break;
		}
		else {
			cout << "���� : 1���� 4 ������ �������� �Է����ּ���!\n";
		}
	}	
}

int main() 
{
	Menu();
}
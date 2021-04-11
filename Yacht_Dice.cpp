#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

int InfoNum;

//메뉴창
void MenuInfo() {
	cout << "---------------------------------------\n";
	cout << setfill(' ') << '|'<< left << setw(38) <<" 1. Game Information" << "|\n";
	cout << setfill(' ') << '|' << left << setw(38) << " 2. The Method of Score Calculation" << "|\n";
	cout << setfill(' ') << '|' << left << setw(38) << " 3. Start Game" << "|\n";
	cout << setfill(' ') << '|' << left << setw(38) << " 4. Quit Game" << "|\n";
	cout << "---------------------------------------\n";
	cout << "원하는 실행 번호를 입력하세요 --> ";
	cin >> InfoNum;
	cout << "\n";
}

//1. Game Information
void Menu1() {
	cout << "요트 다이스는 주사위를 사용해 포커처럼 족보를 맞추는 게임입니다. 5개의 주사위를 최대 3번까지 던진 후\n";
	cout << "원하는 주사위를 선택해 족보를 만듭니다. 만든 족보를 점수판에 기록하여 점수를 얻습니다. 더 많은 점수를 얻는 Player가 승리합니다. \n";
	cout << "제작자의 프로그래밍 실력 한계로 주사위를 선택하는 기능을 구현하지 못해 5개의 주사위를 최대 5번 던지는 방식으로 진행합니다.\n";
	cout << "점수 계산법에 정보를 얻고 싶으시다면 2번을 눌러주세요. \n\n";
}

//2. The Method of Score Calculation
void Menu2() {
	cout << "-----------------------------------------------------------------------------------------\n";
	cout << "Aces : 1이 나온 주사위 눈의 총합. 최대 5점 (1)\n";
	cout << "Deuces : 2가 나온 주사위 눈의 총합. 최대 10점 (2)\n";
	cout << "Threes : 3가 나온 주사위 눈의 총합. 최대 15점 (3)\n";
	cout << "Fours : 4가 나온 주사위 눈의 총합. 최대 20점 (4)\n";
	cout << "Fives : 5가 나온 주사위 눈의 총합. 최대 25점 (5)\n";
	cout << "Sixes : 6가 나온 주사위 눈의 총합. 최대 30점 (6)\n";
	cout << "위 6개 항목의 점수가 63점 이상일 때, 35점을 보너스로 얻습니다!\n";
	cout << "-----------------------------------------------------------------------------------------\n";
	cout << "Choice : 주사위의 눈 5개의 총합. 최대 30점 (7)\n";
	cout << "-----------------------------------------------------------------------------------------\n";
	cout << "4 of a Kind : 동일한 주사위의 눈이 4개 이상일 때, 주사위 눈 5개의 총합. 최대 30점 (8)\n";
	cout << "Full House : 동일한 주사위의 눈이 각각 3개, 2개일 때, 주사위 눈 5개의 총합. 최대 30점 (9)\n";
	cout << "Little Straight : 주사위 눈이 각각 1, 2, 3, 4, 5일 때, 고정 30점 (10)\n";
	cout << "Big Straight : 주사위 눈이 각각 2, 3, 4, 5, 6일 때, 고정 30점 (11)\n";
	cout << "Yacht : 동일한 숫자의 눈이 5개일 때, 고정 50점 (12)\n";
	cout << "-----------------------------------------------------------------------------------------\n\n";
}

//주사위 발생
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

//족보 선택하기
void Score(int dice1, int dice2, int dice3, int dice4, int dice5, int& point, int& A, int& B, int& C, int& D, int& E, int& F, int& G, int& H, int& I, int& J, int& K, int& L, string player, int& bonus)  {
	int score;
	while (1) {
		cout << "< 족보 표 > 사용 가능 족보 0, 사용 불가능 족보 1\n";
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
		cout << "점수를 얻을 족보를 선택하세요. (족보에 대한 정보를 얻으려면 0을 입력하세요. 괄호 안의 숫자 입력) -> ";
		cin >> score;
		if (score == 0) {
			Menu2();
		}
		else {
			if (score == 1) {
				if (A == 1) {
					cout << "\n이미 사용한 족보\n\n";
				}
				else {
					Aces(dice1, dice2, dice3, dice4, dice5, point, bonus);
					A = 1;
					break;
				}
			}
			else if (score == 2) {
				if (B == 1) {
					cout << "\n이미 사용한 족보\n\n";
				}
				else {
					Deuces(dice1, dice2, dice3, dice4, dice5, point, bonus);
					B = 1;
					break;
				}
			}
			else if (score == 3) {
				if (C == 1) {
					cout << "\n이미 사용한 족보\n\n";
				}
				else {
					Threes(dice1, dice2, dice3, dice4, dice5, point, bonus);
					C = 1;
					break;
				}
			}
			else if (score == 4) {
				if (D == 1) {
					cout << "\n이미 사용한 족보\n\n";
				}
				else {
					Fours(dice1, dice2, dice3, dice4, dice5, point, bonus);
					D = 1;
					break;
				}
			}
			else if (score == 5) {
				if (E == 1) {
					cout << "\n이미 사용한 족보\n\n";
				}
				else {
					Fives(dice1, dice2, dice3, dice4, dice5, point, bonus);
					E = 1;
					break;
				}
			}
			else if (score == 6) {
				if (F == 1) {
					cout << "\n이미 사용한 족보\n\n";
				}
				else {
					Sixes(dice1, dice2, dice3, dice4, dice5, point, bonus);
					F = 1;
					break;
				}
			}
			else if (score == 7) {
				if (G == 1) {
					cout << "\n이미 사용한 족보\n\n";
				}
				else {
					Choice(dice1, dice2, dice3, dice4, dice5, point);
					G = 1;
					break;
				}
			}
			else if (score == 8) {
				if (H == 1) {
					cout << "\n이미 사용한 족보\n\n";
				}
				else {
					Kin(dice1, dice2, dice3, dice4, dice5, point);
					H = 1;
					break;
				}
			}
			else if (score == 9) {
				if (I == 1) {
					cout << "\n이미 사용한 족보\n\n";
				}
				else {
					Full(dice1, dice2, dice3, dice4, dice5, point);
					I = 1;
					break;
				}
			}
			else if (score == 10) {
				if (J == 1) {
					cout << "\n이미 사용한 족보\n\n";
				}
				else {
					LS(dice1, dice2, dice3, dice4, dice5, point);
					J = 1;
					break;
				}
			}
			else if (score == 11) {
				if (K == 1) {
					cout << "\n이미 사용한 족보\n\n";
				}
				else {
					BS(dice1, dice2, dice3, dice4, dice5, point);
					K = 1;
					break;
				}
			}
			else if (score == 12) {
				if (L == 1) {
					cout << "\n이미 사용한 족보\n\n";
				}
				else {
					L = 1;
					break;
				}
			}
			else {
				cout << "\n유효한 값을 입력해주세요.\n\n";
			}
		}
	}
	cout <<player<< "님의 현재 점수는 " << point << "입니다.\n\n";
}

//주사위 던진 결과 표시
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
				cout << player << "님 준비 되셨으면 1을 입력해 주세요!-> ";
				cin >> play;
				if (play == 1) {
					cout << player << "님이 주사위를 던집니다. (" << turn << "번째 턴, " << n << "번째 주사위)\n";
					RunDice(Dice1, Dice2, Dice3, Dice4, Dice5);
					cout << "결과 : " << Dice1 << " " << Dice2 << " " << Dice3 << " " << Dice4 << " " << Dice5 << "\n\n";
					if (n >= 5) {
						break;
					}
					else {
						cout << "결정하시겠습니까? (Y or N) -> ";
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
					cout << "1을 입력해주세요!\n";
				}
			}
			Score(Dice1, Dice2, Dice3, Dice4, Dice5, point, A, B, C, D, E, F, G, H, I, J, K, L, player, bonus);
			turn = turn + 1;
		}
	}
	if (bonus >= 63) {
		point = point + 35;
		cout << "Aces ~ Sixes의 총 합이 63점이 넘었으므로 보너스 35점!\n";
	}
	cout << "게임종료! " <<player<< "님의 최종 점수는 " << point << "점 입니다.\n";
}

//3. Start Game
void Menu3() {
	string player;
	cout << "게임 시작!\n";
	cout << "플레이어의 이름을 지정해주세요 --> ";
	cin >> player;
	Repeat(player);	
}

//메뉴
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
			cout << "오류 : 1에서 4 사이의 정수값을 입력해주세요!\n";
		}
	}	
}

int main() 
{
	Menu();
}
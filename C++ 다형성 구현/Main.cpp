#include <iostream>
#include <print>
#include "ShapeManager.h"
#include "Vertex.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "Menu.h"
using namespace std;

int main()
{
	ShapeManager sm(100);
	int command{};

	sm.insert(new Triangle());
	sm.insert(new Triangle(Vertex(0, 0), Vertex(1, 1), Vertex(2, 2)));
	sm.insert(new Circle(Vertex(1.23, 4.56), 7.89));

	for (int i{}; i < 10; ++i) {
		sm.insert(new Rectangle(Vertex(static_cast<double>(i), static_cast<double>(i + 1)),
			Vertex(static_cast<double>(i * 2), static_cast<double>(i * 3))));
	}

	sm.insert(new Triangle(Vertex(3, 3), Vertex(4, 4), Vertex(5, 5)));
	sm.insert(new Circle(Vertex(3.14, 3.14), 5.6));

	while (true) {
		if (100 == sm.current_capacity()) {
			int pofcapa_command;
			cout << "현재 수용 가능한 용량이 꽉 찼습니다." << '\n';
			cout << "								v command number" << '\n';
			cout << "프로그램 종료 :					0";
			cout << "제일 첫번째 도형을 삭제한다 :		1";
			cout << "수용 가능 용량을 늘린다 :			2";

			cin >> pofcapa_command;

			if (0 == pofcapa_command) {
				return 0;
			}

			else if (1 == pofcapa_command) {
				sm.removeShapes(1);
			}

			else if (2 == pofcapa_command) {

			}
		}

		// 1. 메뉴판을 부르기
		// 2. 메뉴에 추가할 기능 : 도형 추가(삼각형, 사각형, 원), 그리기, 프로그램 끝내기
		Menu();

		// 3. 수행할 입력을 받아 수행하기
		cout << "어떤 명령을 수행할까요? : ";
		cin >> command;

		if (0 == command) {
			break;
		}

		else if (1 == command) {
			sm.draw();
		}

		else if (2 == command) {
			char YNcommand;
			double p1_x, p1_y, p2_x, p2_y, p3_x, p3_y;
			cout << "삼각형을 디폴트로 생성할까요? (Y/N) : ";
			cin >> YNcommand;
			if ('y' == YNcommand || 'Y' == YNcommand)
				sm.insert(new Triangle());
			else if ('n' == YNcommand || 'N' == YNcommand) {
				cout << "세부사항을 입력해주세요. : ";
				cin >> p1_x >> p1_y >> p2_x >> p2_y >> p3_x >> p3_y;
				sm.insert(new Triangle(Vertex(p1_x, p1_y), Vertex(p2_x, p2_y), Vertex(p3_x, p3_y)));
			}

			else {
				cout << "다시 입력하세요.";
				continue;
			}
		}

		else if (3 == command) {
			char YNcommand;
			double p1_x, p1_y, p2_x, p2_y;
			cout << "사각형을 디폴트로 생성할까요? (Y/N) : ";
			cin >> YNcommand;
			if ('y' == YNcommand || 'Y' == YNcommand)
				sm.insert(new Rectangle());
			else if ('n' == YNcommand || 'N' == YNcommand) {
				cout << "세부사항을 입력해주세요. : ";
				cin >> p1_x >> p1_y >> p2_x >> p2_y;
				sm.insert(new Rectangle(Vertex(p1_x, p1_y), Vertex(p2_x, p2_y)));
			}

			else {
				cout << "다시 입력하세요.";
				continue;
			}
		}

		else if (4 == command) {
			char YNcommand;
			double p1_x, p1_y, rad;
			cout << "원을 디폴트로 생성할까요? (Y/N) : ";
			cin >> YNcommand;
			if ('y' == YNcommand || 'Y' == YNcommand)
				sm.insert(new Circle());

			else if ('n' == YNcommand || 'N' == YNcommand) {
				cout << "세부사항을 입력해주세요. : ";
				cin >> p1_x >> p1_y >> rad;
				sm.insert(new Circle(Vertex(p1_x, p1_y), rad));
			}

			else {
				cout << "다시 입력하세요.";
				continue;
			}
		}

		else if (5 == command) {
			char YNcommand;
			double p1_x, p1_y, p2_x, p2_y;
			cout << "선을 디폴트로 생성할까요? (Y/N) : ";
			cin >> YNcommand;
			if ('y' == YNcommand || 'Y' == YNcommand)
				sm.insert(new Line());

			else if ('n' == YNcommand || 'N' == YNcommand) {
				cout << "세부사항을 입력해주세요. : ";
				cin >> p1_x >> p1_y >> p2_x >> p2_y;
				sm.insert(new Line(Vertex(p1_x, p1_y), Vertex(p2_x, p2_y)));
			}

			else {
				cout << "다시 입력하세요.";
				continue;
			}
		}
		// 4. 추가할 다른 기능 : 원하는 도형 삭제, 선택한 클래스의 모든 도형 삭제
		else if (6 == command) {
			int remove_command;
			cout << "몇번 도형을 삭제할까요?";
			cin >> remove_command;
			sm.removeShapes(remove_command);
		}

		else if (7 == command) {
			sm.removeSpecificShapes(typeid(Triangle));
		}

		else if (8 == command) {
			sm.removeSpecificShapes(typeid(Rectangle));
		}

		else if (9 == command) {
			sm.removeSpecificShapes(typeid(Circle));
		}

		else if (5 == command) {
			sm.removeSpecificShapes(typeid(Line));
		}

		else
			cout << "잘못된 입력입니다.";
	}
		// 5. 도형관리자가 관리할 수 있는 도형 갯수가 꽉 찼다고 가정하자.
		//    이 경우 새로운 도형을 추가할 수 있도록 프로그램을 변형하라
		// 
		// (선택) 6. 도형관리자가 관리하는 도형을 파일로 저장하고 읽어 오는 메뉴를 추가
		// (선택) 7. 새로운 도형 Line을 추가하라.



	// 이 프로그램에서 잘못된 점을 찾을 수 있는가?
	// -> for 루프에서 i 선언을 int로 하여 Vertex의 인자로써 사용하기 때문에 문제가 발생함
	// 
	// 잘못된 점을 어떻게 찾을 수 있는가?
	// Circle.h 와 Circle.cpp에 생성자 Circle::Circle(const Vertex& c, int r)을
	// Circle::Circle(const Vertex& c, double r)로 고쳐야 한다.


}
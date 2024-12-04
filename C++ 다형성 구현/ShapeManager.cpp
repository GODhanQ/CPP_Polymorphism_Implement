#include <iostream>
#include <print>
#include "ShapeManager.h"
using namespace std;

ShapeManager::ShapeManager(int n)
{
	nShape = 0;
	capacity = n;
	shapes = new Shape * [capacity];
}

ShapeManager::~ShapeManager()
{
	delete[] shapes;
}

// 복사생성자
ShapeManager::ShapeManager(const ShapeManager& other)	// 질문으로 나둬야지
	: nShape(other.nShape), capacity(other.capacity), shapes(new Shape* [other.capacity])
{
	for (int i = 0; i < other.nShape; ++i) {
		shapes[i] = other.shapes[i]->clone();
	}
}

ShapeManager& ShapeManager::operator=(const ShapeManager& other) {		// 이것도
	if (this == &other)
		return *this;

	// 기존 메모리 해제
	for (int i = 0; i < nShape; ++i) {
		delete shapes[i];
	}
	delete[] shapes;

	// 새로운 용량과 크기 설정
	nShape = other.nShape;
	capacity = other.capacity;

	// 새로운 메모리 할당
	shapes = new Shape * [capacity];

	// 깊은 복사 (각 Shape 객체의 복사본 생성)
	for (int i = 0; i < nShape; ++i) {
		shapes[i] = other.shapes[i]->clone();
	}

	return *this;
}

int ShapeManager::current_capacity() const
{
	return nShape;
}

void ShapeManager::insert(Shape* a)
{
	shapes[nShape] = a;
	nShape++;
}

void ShapeManager::draw() const
{
	cout << "-----------------------------------" << '\n';
	cout << "관리하는 모든 도형을 그립니다." << '\n';
	cout << "최대 " << capacity << "개의 도형을 담을 수 있습니다." << '\n';
	cout << "모두 " << nShape << "개의 도형이 있습니다." << '\n';
	cout << "-----------------------------------" << '\n';

	for (int i{}; i < nShape; ++i) {
		//cout << "[" << i << "] ";
		print("[{:3}]", i + 1);
		shapes[i]->draw();
	}
	cout << '\n';

	cout << "-----------------------------------" << '\n';
	cout << "그리기를 마칩니다." << '\n';
	cout << "-----------------------------------" << '\n';
}

// 지정 도형 삭제를 취급할 함수
void ShapeManager::removeShapes(int idx)
{
	if (idx <= 0 || idx >= nShape) {
		cout << "Invalid index" << endl;
		return;
	}

	// 1. 메모리 해제
	delete shapes[idx];

	// 2. 배열 재구성
	for (int i = idx; i < nShape; ++i) {
		shapes[i] = shapes[i + 1];
	}

	// 3. 마지막 포인터를 nullptr로 설정
	shapes[nShape - 1] = nullptr;

	// 4. 크기 감소
	--nShape;
}

// 지정 클래스 삭제를 취급할 함수
void ShapeManager::removeSpecificShapes(const type_info& type)
{
	for (int i = 0; i < nShape; ++i) {
		if (typeid(*shapes[i]) == type) {
			ShapeManager::removeShapes(i);
			--i;
		}
	}
}
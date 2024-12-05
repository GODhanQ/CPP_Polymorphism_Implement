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
	cout << "Draw all of managing shapes" << '\n';
	cout << "Maxinum " << capacity << "piece of shpae can put in capacity" << '\n';
	cout << "All of " << nShape << "shapes in here" << '\n';
	cout << "-----------------------------------" << '\n';

	for (int i{}; i < nShape; ++i) {
		//cout << "[" << i << "] ";
		print("[{:3}]", i + 1);
		shapes[i]->draw();
	}
	cout << '\n';

	cout << "-----------------------------------" << '\n';
	cout << "Finish all of drawing" << '\n';
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

void ShapeManager::ExpandCapacity(int morecapacity)
{
	if (capacity >= morecapacity) {
		cout << "Failed expand capacity.\n";
		cout << "It can be more than current capacity.\n";
		return;
	}
	Shape** temp = {shapes};
	shapes = new Shape * [morecapacity];

	for (int i{}; i < nShape; ++i) {
		shapes[i] = temp[i];
	}
	capacity = morecapacity;

	delete temp;
}
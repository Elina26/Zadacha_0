#include "Container.h"
using namespace namespaceContainer;

// ���������� ������� � ����������
int Container::numOfBoxes()
{
	return vector.size();
}


// ��������� ��� ����������� ����������
double Container::sumWeight()
{
	double res = 0.0;
	int size = vector.size();
	for (int i = 0; i < size; i++) {
		res += vector[i].getWeight();
	}
	return res;
}


// ��������� ��������� �����������
int Container::sumVlaue()
{
	int res = 0; int size = vector.size();
	for (int i = 0; i < size; i++) {
		res += vector[i].getValue();
	}
	return res;
}


// ��������� ������� �� �������
namespaceBox::Box Container::getBox(int index)
{
	return vector[index];
}


/*���������� ������� � ���������. ����� �������� �� ���� ������� � ���������, ���
��������� ��� ������� ������ ��������� �������� ������ (������� ������� ��
���������). ���� ����������� �� ���� ���������, �� ������� �����������, �����
���������� �� ������. � ��������� ������ ������������� ���������� (�������� ��� ���
����)*/
int Container::setBox(namespaceBox::Box& box) {
	if ((sumWeight() + box.getWeight()) <= maxWeight) {
		vector.push_back(box);
		return vector.size() - 1;
	}
	else {
		throw "box's weight bigger then maxWeight!";
		//return -1;
	}
}


// �������� ������� �� �������
void Container::deleteBox(int index) {
	std::vector <namespaceBox::Box> copy(0);

    //std::vector <namespaceBox::Box> copy(0);

    // ��������� copy
    for (int i = index + 1; i < vector.size(); i++) {
        copy.push_back(vector[i]);
    }

    int size = vector.size();
    // ������� ����� �� �������
    for (int i = index; i < size; i++) {
		vector.pop_back();
    }


    for (int i = 0; i < copy.size(); i++) {
		vector.push_back(copy[i]);
    }
}

namespaceBox::Box& Container::operator[](int index)
{
	return vector[index];
}
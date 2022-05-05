#include "Box.h"
using  namespace namespaceBox;

Box::Box(int length, int width, int height, double weight, int value)
{
    this->length = length;
    this->width = width;
    this->height = height;
    this->weight = weight;
    this->value = value;
}


Box::Box()
{
    length = width = height = value = 0;
    weight = 0;
}


/* 2.�������� �������, ������� ��� ������� ������� ��������� ��������� ���������
����������� ���� �������.*/
int Box::maxValue(Box* box, int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res += box[i].getValue();
    }
    return res;
}


/* 3.�������� �������, ������� ���������, ��� ����� �����, ������ � ������ ���� �������
�� ����������� ��������� ��������.*/
bool Box::lessThen(Box* box, int size, int max) {
    int count = 0; bool res;
    for (int i = 0; i < size; i++) {
        if ((box[i].getLength() + box[i].getWidth() + box[i].getHeight()) <= max) {
            count++;
        }
    }
    if (count == size) {
        res = true;
    }
    else {
        res = false;
    }
    return res;
}


/* 4.�������� �������, ������� ���������� ������������ ��� �������, ����� ������� ��
������ ��������� maxV.*/
double Box::maxWeight(Box* box, int size, double maxV) {
    double res = 0; long int max;
    for (int i = 0; i < size; i++) {
        max = box[i].getHeight() * box[i].getLength() * box[i].getWidth();
        if ((max <= maxV) and (box[i].getWeight() > res)) {
            res = box[i].getWeight();
        }
    }
    return res;
}


/* 5.� �������������, ��� ��� ������� ������, �������� �������, ������� ���������, ��� ���
������� ������� ����� ������� ���� � ����� �� ����� ����� (�.�. ����� ���������
������� ������ ����������� � ������� ��������, ��� ���� ������� � � ��� �������
� �.�.). �������, ��� ���� ������� ����� ��������� ������, ���� �����, ������ � ������
������ ������� ������ ����������� �������� ������.*/
bool Box::oneInOne(Box* box, int size) {
    /*����� ������������� ������� � ������� �����������, ��������, ������, � �����
    ��������� ��������� �� � ������� ����������� ������ � �����*/

    bool res = false;
    Box temp; // ��������� ���������� ��� ������ ��������� �������

    // ���������� ������� ��������� � ������� ����������� ������
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (box[j].getHeight() > box[j + 1].getHeight()) {
                temp = box[j];
                box[j] = box[j + 1];
                box[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size - 1; i++) {    //���������, ��� ����� ���� ������� ���� � ������� �����������
        if (box[i].getLength() < box[i + 1].getLength()) {
            res = true;
        }
        else {
            res = false;
            break;
        }
    }

    if (res) {    //������ ���������, ��� �� ������ ������� ���� ��������� � ������� �����������
        for (int i = 0; i < size - 1; i++) {
            if (box[i].getWidth() >= box[i + 1].getWidth()) {
                res = false;
                break;
            }
            else {
                res = true;
            }
        }
        return res;
    }
    else {
        return res;
    }
}


// 6.�������� ==
bool Box::operator==(const Box& box) {
    return (this->length == box.length &&
        this->width == box.width &&
        this->height == box.height &&
        this->weight == box.weight &&
        this->value == box.value);
}




#pragma once
#include <iostream>
#include <ostream>

namespace namespaceBox {
	class Box
	{
	private:
		int length, width, height;
		double weight;
		int value;

	public:
		Box(int length, int width, int height, double weight, int value);
		Box();

		int maxValue(Box* box, int size);
		bool lessThen(Box* box, int size, int max);
		double maxWeight(Box* box, int size, double maxV);
		bool oneInOne(Box* box, int size);
		bool operator==(const Box& rhs);
		friend std::istream& operator>> (std::istream& in, Box &box) {
			int i = 0; double d = 0;
			in >> i;
			box.setLength(i);
			in >> i;
			box.setWidth(i);
			in >> i;
			box.setHeight(i);
			in >> d;
			box.setWeight(d);
			in >> i;
			box.setValue(i);
			return in;
		}

		friend std::ostream& operator<< (std::ostream& out, Box& box) {
			std::cout << "{length = " << box.getLength() << ", ";
			std::cout << "width = " << box.getWidth() << ", ";
			std::cout << "height = " << box.getHeight() << ", ";
			std::cout << "weight = " << box.getWeight() << ", ";
			std::cout << "value = " << box.getValue() << "}";
			return out;
		}


		int getLength() { return length; }
		int getWidth() { return width; }
		int getHeight() { return height; }
		double getWeight() { return weight; }
		int getValue() { return value; }

		void setLength(int length) { this->length = length; }
		void setWidth(int width) { this->width = width; }
		void setHeight(int height) { this->height = height; }
		void setWeight(double weight) { this->weight = weight; }
		void setValue(int value) { this->value = value; }
	};
}
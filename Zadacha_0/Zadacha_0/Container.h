#pragma once
#include "Box.h"
#include <vector> 
#include <iostream>
#include <ostream>

namespace namespaceContainer {
	class Container {
	private:
		int length, width, height;
		double maxWeight;
		std::vector <namespaceBox::Box> vector;

	public:
		Container(int length, int width, int height, double maxWeight) {
			this->length = length;
			this->width = width;
			this->height = height;
			this->maxWeight = maxWeight;
		}

		int numOfBoxes();
		double sumWeight();
		int sumValue();
		namespaceBox::Box getBox(int index);
		int setBox(namespaceBox::Box& box);
		void deleteBox(int index);

		friend std::istream& operator>> (std::istream& in, Container& container) {
			int Int; double Double;
			in >> Int;
			container.setLength(Int);
			in >> Int;
			container.setWidth(Int);
			in >> Int;
			container.setHeight(Int);
			in >> Double;
			container.setMaxWeight(Double);
			return in;
		}
		friend std::ostream& operator<< (std::ostream& out, Container& container) {
			std::cout << "length = " << container.getLength() << ", ";
			std::cout << "width = " << container.getWidth() << ", ";
			std::cout << "height = " << container.getHeight() << ", ";
			std::cout << "maxWeight = " << container.getMaxWeight() << std::endl << std::endl;
			for (int i = 0; i < container.numOfBoxes(); i++) {
				std::cout << "box[" << i << "] = " << container.vector[i] << std::endl;
			}
			return out;
		}
		namespaceBox::Box& operator[] (int index);

		int getLength() { return length; }
		int getWidth() { return width; }
		int getHeight() { return height; }
		double getMaxWeight() { return maxWeight; }

		void setLength(int length) { this->length = length; }
		void setWidth(int width) { this->width = width; }
		void setHeight(int height) { this->height = height; }
		void setMaxWeight(double maxWeight) { this->maxWeight = maxWeight; }
	};
}
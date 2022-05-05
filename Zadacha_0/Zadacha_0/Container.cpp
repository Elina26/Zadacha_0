#include "Container.h"
using namespace namespaceContainer;

// количество коробок в контейнере
int Container::numOfBoxes()
{
	return vector.size();
}


// суммарный вес содержимого контейнера
double Container::sumWeight()
{
	double res = 0.0;
	int size = vector.size();
	for (int i = 0; i < size; i++) {
		res += vector[i].getWeight();
	}
	return res;
}


// суммарная стоимость содержимого
int Container::sumVlaue()
{
	int res = 0; int size = vector.size();
	for (int i = 0; i < size; i++) {
		res += vector[i].getValue();
	}
	return res;
}


// получение коробки по индексу
namespaceBox::Box Container::getBox(int index)
{
	return vector[index];
}


/*добавление коробки в контейнер. Метод получает на вход коробку и проверяет, что
суммарный вес коробок внутри позволяет добавить данную (размеры коробки не
проверяем). Если ограничение по весу выполнено, то коробка добавляется, метод
возвращает ее индекс. В противном случае выбрасывается исключение (создайте тип для
него)*/
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


// удаление коробки по индексу
void Container::deleteBox(int index) {
	std::vector <namespaceBox::Box> copy(0);

    //std::vector <namespaceBox::Box> copy(0);

    // заполняем copy
    for (int i = index + 1; i < vector.size(); i++) {
        copy.push_back(vector[i]);
    }

    int size = vector.size();
    // удаляем хвост из вектора
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
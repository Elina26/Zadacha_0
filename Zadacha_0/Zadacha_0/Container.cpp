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


// суммарна€ стоимость содержимого
int Container::sumValue()
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


/*добавление коробки в контейнер. ћетод получает на вход коробку и провер€ет, что
суммарный вес коробок внутри позвол€ет добавить данную (размеры коробки не
провер€ем). ≈сли ограничение по весу выполнено, то коробка добавл€етс€, метод
возвращает ее индекс. ¬ противном случае выбрасываетс€ исключение (создайте тип дл€
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

    // заполн€ем copy всем, что идет после index в контейнере
    for (int i = index + 1; i < vector.size(); i++) {
        copy.push_back(vector[i]);
    }

    int size = vector.size();
    // удал€ем из контейнера с index вкл и до конца
    for (int i = index; i < size; i++) {
		vector.pop_back();
    }

	// добавл€ем все из копии в контейнер
    for (int i = 0; i < copy.size(); i++) {
	    vector.push_back(copy[i]);
    }

	// удал€ем копию
	copy.clear();
	copy.shrink_to_fit();
}

namespaceBox::Box& Container::operator[](int index)
{
	return vector[index];
}
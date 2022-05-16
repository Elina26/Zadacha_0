#include "Main.h"
#include "Box.h"
#include "Container.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

    namespaceContainer::Container container(1, 2, 3, 100);
    namespaceBox::Box first(1, 3, 5, 20.0, 200);
    namespaceBox::Box second(2, 4, 7, 10.0, 500);
    namespaceBox::Box third(3, 5, 3, 50.0, 400);

    namespaceBox::Box boxes[3] = { first , second , third };
    cout << "2) maxValue = " << first.maxValue(boxes, 3) << endl << endl;

    if (first.lessThen(boxes, 3, 17)) cout << "3) true" << endl << endl;
    else cout << "3) false" << endl << endl;

    cout << "4) maxWeight = " << first.maxWeight(boxes, 3, 130) << endl << endl;

    if (first.oneInOne(boxes, 3)) cout << "5) true(oneInOne)" << endl << endl;
    else cout << "5) false(oneInOne)" << endl << endl;

    //добавляем коробки в контейнер
    try { container.setBox(first); }
    catch (const char* msg) { std::cout << msg << std::endl; }

    try { container.setBox(second); }
    catch (const char* msg) { std::cout << msg << std::endl; }

    try { container.setBox(third); }
    catch (const char* msg) { std::cout << msg << std::endl; }

    std::cout << "\nOur container:\n" << container << std::endl << std::endl;

    std::cout << "\nNumber of boxes in container: " << container.numOfBoxes() << std::endl << std::endl;

    std::cout << "\nTotal content weight: " << container.sumWeight() << std::endl << std::endl;

    std::cout << "\nTotal content value: " << container.sumValue() << std::endl << std::endl;

    std::cout << "\nbox[" << 1 << "]: " << container[1] << std::endl << std::endl;

    container.deleteBox(1);

    std::cout << "\nWe has deleted box[" << 1 << "], our container now:\n" << container << std::endl << std::endl;

    return 0;
}
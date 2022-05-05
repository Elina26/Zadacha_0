#include "Main.h"
#include "Box.h"
#include "Container.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

    namespaceContainer::Container container(1, 2, 3, 100);
    namespaceBox::Box first(1, 3, 5, 60.0, 200);
    namespaceBox::Box second(2, 4, 7, 10.0, 500);
    namespaceBox::Box third(3, 5, 3, 50.0, 400);

    namespaceBox::Box boxes[3] = { first , second , third };
    cout << "maxValue = " << first.maxValue(boxes, 3) << endl << endl;

    if (first.lessThen(boxes, 3, 17)) cout << "true" << endl << endl;
    else cout << "false" << endl << endl;

    cout << "maxWeight = " << first.maxWeight(boxes, 3, 130) << endl << endl;

    if (first.oneInOne(boxes, 3)) cout << "true(oneInOne)" << endl << endl;
    else cout << "false(oneInOne)" << endl << endl;


    try { container.setBox(first); }
    catch (const char* msg) { std::cout << msg << std::endl; }

    try { container.setBox(second); }
    catch (const char* msg) { std::cout << msg << std::endl; }

    try { container.setBox(third); }
    catch (const char* msg) { std::cout << msg << std::endl; }

    std::cout << container << std::endl << std::endl;

    container.deleteBox(0);

    std::cout << container << std::endl << std::endl;

    return 0;
}
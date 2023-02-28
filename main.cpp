#include <iostream>
#include "ObjectTree.h"


int main()
{
    CObjectTree tree("ObjectRoot");
    tree.AddHeirToObjectByName("ObjectRoot", "Object1");
    tree.AddHeirToObjectByName("ObjectRoot", "Object2");
    tree.AddHeirToObjectByName("ObjectRoot", "Object3");

    tree.AddHeirToObjectByName("Object3", "Object4");
    tree.AddHeirToObjectByName("Object3", "Object5");
    tree.Print();
}

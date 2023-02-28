//
// Created by Vlad on 28.02.2023.
//

#pragma once
#include "Object/CObject.h"


class CObjectTree
{
public:
    CObjectTree(const std::string& sRootObjectName);
    CObject* GetObjectByName(const std::string& sObjectName);
    void AddHeirToObjectByName(const std::string& sParentName, const std::string& sHeirName);
    void Print();
private:
    CObject* GetObjectByNameRecursive(CObject *pObj, const std::string& sObjectName);
    void PrintRecursive(const CObject* pObj);
    CObject* m_pRootObject;
};

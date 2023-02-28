//
// Created by Vlad on 28.02.2023.
//

#include "ObjectTree.h"


CObjectTree::CObjectTree(const std::string &sRootObjectName)
{
    m_pRootObject = new CObject(nullptr, sRootObjectName);
}

CObject *CObjectTree::GetObjectByName(const std::string &sObjectName)
{
    return GetObjectByNameRecursive(m_pRootObject, sObjectName);
}

CObject *CObjectTree::GetObjectByNameRecursive(CObject *pObj, const std::string &sObjectName)
{
    if (pObj->m_sName == sObjectName)
        return pObj;

    for (const auto pParent : pObj->m_vecHeirs)
    {
        auto res = GetObjectByNameRecursive(pParent,sObjectName);
        if (res)
            return res;
    }

    return nullptr;
}

void CObjectTree::AddHeirToObjectByName(const std::string &sParentName, const std::string &sHeirName)
{
    auto pParent = GetObjectByName(sParentName);

    if (GetObjectByName(sHeirName) or !pParent)
        return;

    pParent->m_vecHeirs.push_back(new CObject(pParent, sHeirName));
}

void CObjectTree::PrintRecursive(const CObject *pObj)
{
    if (pObj->m_vecHeirs.empty())
        return;

    printf("%s ", pObj->m_sName.c_str());


    for (const auto pHeir : pObj->m_vecHeirs)
        printf((pHeir != pObj->m_vecHeirs.back()) ? "%s " : "%s\n", pHeir->m_sName.c_str());

    for (const auto pHeir : pObj->m_vecHeirs)
        PrintRecursive(pHeir);
}

void CObjectTree::Print()
{
    PrintRecursive(m_pRootObject);
}

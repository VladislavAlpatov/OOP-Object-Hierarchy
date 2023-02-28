//
// Created by Vlad on 28.02.2023.
//

#pragma once
#include <string>
#include <vector>

class CObject
{
    friend class CObjectTree;
public:
    CObject(const CObject* pParent, const std::string& sName);
    std::string GetName() {return m_sName;}
private:
    std::string m_sName;
    const CObject* m_pParent = nullptr;
    std::vector<CObject*> m_vecHeirs;
};

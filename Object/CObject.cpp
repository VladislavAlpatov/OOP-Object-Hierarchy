//
// Created by Vlad on 28.02.2023.
//

#include "CObject.h"

CObject::CObject(const CObject *pParent, const std::string &sName)
{
    m_sName = sName;
    m_pParent = pParent;
}

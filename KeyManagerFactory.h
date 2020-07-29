//
// Created by Karl Moad on 7/29/20.
//
#ifndef QTKEYCHAIN_KEYMANAGERFACTORY_H
#define QTKEYCHAIN_KEYMANAGERFACTORY_H

#include "KeyManager.h"
#include "MacKeyManager.h"

class KeyManagerFactory
{
public:
    static KeyManager* getDefault(const QString& ApplicationId)
    {
        return new MacKeyManager(ApplicationId);
    }
};
#endif //QTKEYCHAIN_KEYMANAGERFACTORY_H

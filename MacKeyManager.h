//
// Created by Karl Moad on 7/29/20.
//

#ifndef QTKEYCHAIN_MACKEYMANAGER_H
#define QTKEYCHAIN_MACKEYMANAGER_H

#include <QString>
#include "KeyManager.h"

class MacKeyManager;

class MacKeyManager: public KeyManager
{
public:
    explicit MacKeyManager(const QString& AppId);
    virtual ~MacKeyManager()=default;
    const QString getPassword(const QString &account) override;
    bool setPassword(const QString &account, const QString &password) override;
};


#endif //QTKEYCHAIN_MACKEYMANAGER_H

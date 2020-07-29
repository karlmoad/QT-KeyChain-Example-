//
// Created by Karl Moad on 7/29/20.
//

#ifndef QTKEYCHAIN_KEYMANAGER_H
#define QTKEYCHAIN_KEYMANAGER_H

#include <QString>

class KeyManager
{
public:
    explicit KeyManager(const QString& AppId): _appId(AppId){};
    virtual ~KeyManager()=default;

    KeyManager(const KeyManager&) = delete;
    KeyManager& operator=(const KeyManager&) = delete;

    virtual const QString getPassword(const QString& account) = 0;
    virtual bool setPassword(const QString& account, const QString& password) = 0;

protected:
    QString _appId;
};


#endif //QTKEYCHAIN_KEYMANAGER_H

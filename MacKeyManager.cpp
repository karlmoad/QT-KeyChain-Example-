//
// Created by Karl Moad on 7/29/20.
//

#include "MacKeyManager.h"
#include <Security/Security.h>

const QString MacKeyManager::getPassword(const QString &account)
{
    UInt32 password_length;
    char* password;
    OSStatus ret = SecKeychainFindGenericPassword(
            NULL,
            _appId.length(),
            _appId.toStdString().c_str(),
            account.length(),
            account.toStdString().c_str(),
            &password_length,
            (void**)&password,
            NULL);

    if (ret == 0) {
        QString pass = QString::fromLatin1(password, password_length);
        SecKeychainItemFreeContent(NULL, password);
        return pass;
    }

    return QString();
}

bool MacKeyManager::setPassword(const QString &account, const QString &password)
{
    SecKeychainItemRef item;
    OSStatus ret = SecKeychainFindGenericPassword(
            NULL,
            _appId.length(),
            _appId.toStdString().c_str(),
            account.length(),
            account.toStdString().c_str(),
            NULL,
            NULL,
            &item);

    if (ret == 0) {
        ret = SecKeychainItemModifyAttributesAndData(
                item,
                NULL,
                password.length(),
                password.toStdString().c_str());

        return ret == 0;
    } else {
        ret = SecKeychainAddGenericPassword(
                NULL,
                _appId.length(),
                _appId.toStdString().c_str(),
                account.length(),
                account.toStdString().c_str(),
                password.length(),
                password.toStdString().c_str(),
                NULL);

        return ret == 0;
    }
}

MacKeyManager::MacKeyManager(const QString &AppId) : KeyManager(AppId)
{}

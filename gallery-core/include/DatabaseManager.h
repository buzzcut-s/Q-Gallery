#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>

#include "AlbumDao.h"

class QSqlDatabase;
class QSqlQuery;
const QString DATABASE_FILENAME = "gallery.db";

class DatabaseManager
{
public:
        static DatabaseManager& instance();

        virtual ~DatabaseManager();
        DatabaseManager(const DatabaseManager&) = delete;
        DatabaseManager(DatabaseManager&&)      = delete;
        DatabaseManager& operator=(DatabaseManager&&) = delete;

        static void debugQuery(const QSqlQuery& query);

protected:
        explicit DatabaseManager(const QString& path = DATABASE_FILENAME);
        DatabaseManager& operator=(const DatabaseManager& rhs);

private:
        QSqlDatabase* m_dataBase;

public:
        const AlbumDao albumDao;
};

#endif  // DATABASEMANAGER_H

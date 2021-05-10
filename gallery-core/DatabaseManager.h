#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>

class QSqlDatabase;
const QString DATABASE_FILENAME = "gallery.db";

class DatabaseManager
{
public:
        static DatabaseManager& instance();

        virtual ~DatabaseManager();
        DatabaseManager(const DatabaseManager&) = delete;
        DatabaseManager(DatabaseManager&&)      = delete;
        DatabaseManager& operator=(DatabaseManager&&) = delete;

protected:
        explicit DatabaseManager(const QString& path = DATABASE_FILENAME);
        DatabaseManager& operator=(const DatabaseManager& rhs);

private:
        QSqlDatabase* m_dataBase;
};

#endif  // DATABASEMANAGER_H

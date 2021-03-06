#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>

#include "AlbumDao.h"
#include "PictureDao.h"
#include "qstringliteral.h"

class QSqlDatabase;
class QSqlQuery;

const QString DATABASE_FILENAME = QStringLiteral("gallery.db");

class DatabaseManager
{
public:
        static DatabaseManager& instance();

        virtual ~DatabaseManager();
        DatabaseManager(const DatabaseManager&) = delete;
        DatabaseManager(DatabaseManager&&)      = delete;
        DatabaseManager& operator=(DatabaseManager&&) = delete;

        [[nodiscard]] auto albumDao() const -> const AlbumDao&;
        [[nodiscard]] auto pictureDao() const -> const PictureDao&;

        static void debugQuery(const QSqlQuery& query);

protected:
        explicit DatabaseManager(const QString& path = DATABASE_FILENAME);
        DatabaseManager& operator=(const DatabaseManager& rhs);

private:
        QSqlDatabase*    m_dataBase;
        const AlbumDao   m_albumDao;
        const PictureDao m_pictureDao;
};

#endif  // DATABASEMANAGER_H

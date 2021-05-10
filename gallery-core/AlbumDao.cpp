#include "AlbumDao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>

#include "DatabaseManager.h"

AlbumDao::AlbumDao(QSqlDatabase& database) :
    m_database(database)
{
}

void AlbumDao::init() const
{
        if (not m_database.tables().contains("album"))
        {
                QSqlQuery query(m_database);
                query.exec(
                    "CREATE TABLE albums "
                    "(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
        }
}

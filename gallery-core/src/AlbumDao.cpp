#include "include/AlbumDao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
#include <QVariant>

#include "include/Album.h"
#include "include/DatabaseManager.h"

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
                DatabaseManager::debugQuery(query);
        }
}

void AlbumDao::addAlbum(Album& album) const
{
        QSqlQuery query(m_database);

        query.prepare("INSERT INTO albums (name) VALUE (:name)");
        query.bindValue(":name", album.name());
        query.exec();
        album.setId(query.lastInsertId().toInt());

        DatabaseManager::debugQuery(query);
}

void AlbumDao::updateAlbum(const Album& album) const
{
        QSqlQuery query(m_database);

        query.prepare("UPDATE albums SET name = (:name) WHERE id = (:id)");
        query.bindValue(":name", album.name());
        query.bindValue(":id", album.id());
        query.exec();

        DatabaseManager::debugQuery(query);
}

void AlbumDao::removeAlbum(int id) const
{
        QSqlQuery query(m_database);

        query.prepare("DELETE FROM albums WHERE id = (:id)");
        query.bindValue(":id", id);
        query.exec();

        DatabaseManager::debugQuery(query);
}

auto AlbumDao::albums() const -> std::unique_ptr<std::vector<std::unique_ptr<Album>>>
{
        QSqlQuery query("SELECT * FROM albums", m_database);

        query.exec();
        DatabaseManager::debugQuery(query);

        auto list = std::make_unique<std::vector<std::unique_ptr<Album>>>();
        while (query.next())
        {
                auto album = std::make_unique<Album>();
                album->setId(query.value("id").toInt());
                album->setName(query.value("name").toString());
                list->push_back(std::move(album));
        }

        return list;
}

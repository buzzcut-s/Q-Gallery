#include "AlbumDao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
#include <QVariant>

#include "Album.h"

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

void AlbumDao::addAlbum(Album& album) const
{
        QSqlQuery query(m_database);

        query.prepare("INSERT INTO albums (name) VALUE (:name)");
        query.bindValue(":name", album.name());
        query.exec();
        album.setId(query.lastInsertId().toInt());
}

void AlbumDao::updateAlbum(const Album& album) const
{
        QSqlQuery query(m_database);

        query.prepare("UPDATE albums SET name = (:name) WHERE id = (:id)");
        query.bindValue(":name", album.name());
        query.bindValue(":id", album.id());
        query.exec();
}

void AlbumDao::removeAlbum(int id) const
{
        QSqlQuery query(m_database);

        query.prepare("DELETE FROM albums WHERE id = (:id)");
        query.bindValue(":id", id);
        query.exec();
}

auto AlbumDao::albums() const -> QVector<Album*>
{
        QSqlQuery query("SELECT * FROM albums", m_database);

        query.exec();
        QVector<Album*> list;
        while (query.next())
        {
                auto* album = new Album();
                album->setId(query.value("id").toInt());
                album->setName(query.value("name").toString());
                list.append(album);
        }

        return list;
}

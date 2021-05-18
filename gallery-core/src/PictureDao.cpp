#include "include/PictureDao.h"

#include <memory>
#include <vector>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "include/DatabaseManager.h"
#include "include/Picture.h"

PictureDao::PictureDao(QSqlDatabase& database) :
    m_database(database)
{
}

void PictureDao::init() const
{
        if (not m_database.tables().contains("pictures"))
        {
                QSqlQuery query(m_database);

                query.exec(QString("CREATE TABLE pictures ")
                           + "(id INTEGER PRIMARY KEY AUTOINCREMENT, "
                           + "album_id INTEGER, "
                           + "url TEXT)");
                DatabaseManager::debugQuery(query);
        }
}

void PictureDao::addPictureInAlbum(int albumId, Picture& picture) const
{
        QSqlQuery query(m_database);

        query.prepare(QString("INSERT INTO pictures")
                      + " (album_id, url)"
                      + " VALUES ("
                      + ":album_id, "
                      + ":url"
                      + ")");
        query.bindValue(":album_id", albumId);
        query.bindValue(":url", picture.fileUrl());
        query.exec();

        DatabaseManager::debugQuery(query);

        picture.setId(query.lastInsertId().toInt());
        picture.setAlbumId(albumId);
}

void PictureDao::removePicture(int id) const
{
        QSqlQuery query(m_database);

        query.prepare("DELETE FROM pictures WHERE id = (:id)");
        query.bindValue(":id", id);
        query.exec();

        DatabaseManager::debugQuery(query);
}

void PictureDao::removePicturesForAlbum(int albumId) const
{
        QSqlQuery query(m_database);

        query.prepare("DELETE FROM pictures WHERE album_id = (:album_id)");
        query.bindValue(":album_id", albumId);
        query.exec();

        DatabaseManager::debugQuery(query);
}

auto PictureDao::picturesForAlbum(int albumId) const -> std::unique_ptr<std::vector<std::unique_ptr<Picture>>>
{
        QSqlQuery query(m_database);

        query.prepare("SELECT * FROM pictures WHERE album_id = (:album_id)");
        query.bindValue(":album_id", albumId);
        query.exec();

        DatabaseManager::debugQuery(query);

        auto list = std::make_unique<std::vector<std::unique_ptr<Picture>>>();
        while (query.next())
        {
                auto picture = std::make_unique<Picture>();
                picture->setId(query.value("id").toInt());
                picture->setAlbumId(query.value("album_id").toInt());
                picture->setFileUrl(query.value("url").toString());
                list->push_back(std::move(picture));
        }
        return list;
}

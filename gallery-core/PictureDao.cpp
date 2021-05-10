#include "PictureDao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "Picture.h"

PictureDao::PictureDao(QSqlDatabase& database) :
    m_database(database)
{
}

void PictureDao::init() const
{
        if (!m_database.tables().contains("pictures"))
        {
                QSqlQuery query(m_database);

                query.exec(QString("CREATE TABLE pictures ")
                           + "(id INTEGER PRIMARY KEY AUTOINCREMENT, "
                           + "album_id INTEGER, "
                           + "url TEXT)");
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

        picture.setId(query.lastInsertId().toInt());
        picture.setAlbumId(albumId);
}

void PictureDao::removePicture(int id) const
{
        QSqlQuery query(m_database);

        query.prepare("DELETE FROM pictures WHERE id = (:id)");
        query.bindValue(":id", id);
        query.exec();
}

void PictureDao::removePicturesForAlbum(int albumId) const
{
        QSqlQuery query(m_database);

        query.prepare("DELETE FROM pictures WHERE album_id = (:album_id)");
        query.bindValue(":album_id", albumId);
        query.exec();
}

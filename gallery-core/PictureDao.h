#ifndef PICTUREDAO_H
#define PICTUREDAO_H

#include <QVector>

class QSqlDatabase;
class Picture;

class PictureDao
{
public:
        explicit PictureDao(QSqlDatabase& database);
        void init() const;

        void addPictureInAlbum(int albumId, Picture& picture) const;
        void removePicture(int id) const;
        void removePicturesForAlbum(int albumId) const;
        auto picturesForAlbum(int albumId) const -> QVector<Picture*>;

private:
        QSqlDatabase& m_database;
};

#endif  // PICTUREDAO_H

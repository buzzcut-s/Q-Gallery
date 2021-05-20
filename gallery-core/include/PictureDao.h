#ifndef PICTUREDAO_H
#define PICTUREDAO_H

#include <memory>
#include <vector>

class QSqlDatabase;
class Picture;

class PictureDao
{
public:
        explicit PictureDao(QSqlDatabase& database);
        void init() const;

        void               addPictureInAlbum(int albumId, Picture& picture) const;
        void               removePicture(int id) const;
        void               removePicturesForAlbum(int albumId) const;
        [[nodiscard]] auto picturesForAlbum(int albumId) const -> std::unique_ptr<std::vector<std::unique_ptr<Picture>>>;

private:
        QSqlDatabase& m_database;
};

#endif  // PICTUREDAO_H

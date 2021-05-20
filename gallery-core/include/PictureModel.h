#ifndef PICTUREMODEL_H
#define PICTUREMODEL_H

#include <memory>
#include <vector>

#include <QAbstractListModel>

#include "AlbumModel.h"
#include "DatabaseManager.h"
#include "Picture.h"
#include "gallery-core_global.h"

class GALLERYCORE_EXPORT PictureModel : public QAbstractItemModel
{
        Q_OBJECT
public:
        explicit PictureModel(const AlbumModel& albumModel, QObject* parent = nullptr);

        enum Roles
        {
                urlRole = Qt::UserRole + 1,
                filePathRole
        };

        auto addPicture(const Picture& picture) -> QModelIndex;

        [[nodiscard]] int  rowCount(const QModelIndex& parent = QModelIndex()) const override;
        [[nodiscard]] auto data(const QModelIndex& index, int role) const -> QVariant override;
        [[nodiscard]] auto roleNames() const -> QHash<int, QByteArray> override;

        bool removeRows(int row, int count, const QModelIndex& parent) override;

        void setAlbumId(int albumId);
        void clearAlbum();

public slots:
        void deletePicturesForAlbum();

private:
        DatabaseManager&                                       m_db;
        int                                                    m_albumId;
        std::unique_ptr<std::vector<std::unique_ptr<Picture>>> m_pictures;

        void               loadPictures(int albumId);
        [[nodiscard]] bool isIndexValid(const QModelIndex& index) const;
};

#endif  // PICTUREMODEL_H

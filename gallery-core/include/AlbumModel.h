#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H

#include <memory>
#include <vector>

#include <QAbstractListModel>
#include <QHash>

#include "Album.h"
#include "DatabaseManager.h"
#include "gallery-core_global.h"

class GALLERYCORE_EXPORT AlbumModel : public QAbstractItemModel
{
        Q_OBJECT;

public:
        explicit AlbumModel(QObject* parent = nullptr);

        int  rowCount(const QModelIndex& parent = QModelIndex()) const override;
        auto data(const QModelIndex& index, int role = Qt::DisplayRole) const -> QVariant override;
        auto roleNames() const -> QHash<int, QByteArray> override;

        bool setData(const QModelIndex& index, const QVariant& value, int role) override;
        bool removeRows(int row, int count, const QModelIndex& parent) override;

        QModelIndex addAlbum(const Album& album);

private:
        bool isIndexValid(QModelIndex& index) const;

private:
        DatabaseManager&                                     m_db;
        std::unique_ptr<std::vector<std::unique_ptr<Album>>> m_albums;
};
#endif  // ALBUMMODEL_H

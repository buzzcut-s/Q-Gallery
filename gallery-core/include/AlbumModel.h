#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H

#include <QAbstractListModel>
#include <QHash>

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
};
#endif  // ALBUMMODEL_H

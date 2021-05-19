#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H

#include <QAbstractListModel>

#include "gallery-core_global.h"

class GALLERYCORE_EXPORT AlbumModel : public QAbstractItemModel
{
        Q_OBJECT;

public:
        explicit AlbumModel(QObject* parent = nullptr);
};
#endif  // ALBUMMODEL_H

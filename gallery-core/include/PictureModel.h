#ifndef PICTUREMODEL_H
#define PICTUREMODEL_H

#include <QAbstractListModel>

#include "gallery-core_global.h"

class GALLERYCORE_EXPORT PictureModel : public QAbstractItemModel
{
        Q_OBJECT
public:
        explicit PictureModel(QObject* parent = nullptr);
};

#endif  // PICTUREMODEL_H

#ifndef PICTURE_H
#define PICTURE_H

#include <QString>
#include <QUrl>

#include "gallery-core_global.h"

class GALLERYCORE_EXPORT Picture
{
public:
        Picture(const QString& filePath = "");
        Picture(const QUrl& fileUrl);

        int  id() const;
        void setId(int id);

        int  albumId() const;
        void setAlbumId(int albumId);

        QUrl fileUrl() const;
        void setFileUrl(const QUrl& fileUrl);

private:
        int  m_id;
        int  m_albumId;
        QUrl m_fileUrl;
};

#endif  // PICTURE_H

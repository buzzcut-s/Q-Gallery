#ifndef PICTURE_H
#define PICTURE_H

#include <QString>
#include <QUrl>

#include "gallery-core_global.h"

class GALLERYCORE_EXPORT Picture
{
public:
        explicit Picture(const QString& filePath = "");
        explicit Picture(QUrl fileUrl);

        [[nodiscard]] int id() const;
        void              setId(int id);

        [[nodiscard]] int albumId() const;
        void              setAlbumId(int albumId);

        [[nodiscard]] auto fileUrl() const -> QUrl;
        void               setFileUrl(const QUrl& fileUrl);

private:
        int  m_id;
        int  m_albumId;
        QUrl m_fileUrl;
};

#endif  // PICTURE_H

#ifndef ALBUM_H
#define ALBUM_H

#include <QString>

#include "gallery-core_global.h"

class GALLERYCORE_EXPORT Album
{
public:
        explicit Album(QString name = "");

        [[nodiscard]] int  id() const;
        void               setId(int id);
        [[nodiscard]] auto name() const -> QString;
        void               setName(const QString& name);

private:
        int     m_id;
        QString m_name;
};

#endif  // ALBUM_H

#include "include/Album.h"

#include <utility>

Album::Album(QString name) :
    m_id{-1},
    m_name{std::move(name)}
{
}

int Album::id() const
{
        return m_id;
}

void Album::setId(int id)
{
        m_id = id;
}

auto Album::name() const -> QString
{
        return m_name;
}

void Album::setName(const QString& name)
{
        m_name = name;
}

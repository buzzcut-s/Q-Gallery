#include "include/AlbumListWidget.h"

#include "ui_AlbumListWidget.h"

AlbumListWidget::AlbumListWidget(QWidget* parent) :
    QWidget{parent},
    m_ui{new Ui::AlbumListWidget}
{
        m_ui->setupUi(this);
}

AlbumListWidget::~AlbumListWidget()
{
        delete m_ui;
}

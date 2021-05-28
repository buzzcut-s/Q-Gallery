#include "AlbumListWidget.h"
#include "ui_AlbumListWidget.h"

AlbumListWidget::AlbumListWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::AlbumListWidget)
{
        ui->setupUi(this);
}

AlbumListWidget::~AlbumListWidget()
{
        delete ui;
}
